/**
  ******************************************************************************
  * File Name          : STM32DMA.hpp
  ******************************************************************************
  * This file is generated by TouchGFX Generator 4.22.0. Please, do not edit!
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef STM32DMA_HPP
#define STM32DMA_HPP

#include <touchgfx/Bitmap.hpp>
#include <touchgfx/hal/DMA.hpp>

#include "cmsis_os.h"
#if defined(osCMSIS) && (osCMSIS < 0x20000)
#define MUTEX_CREATE() osMutexCreate(0)
#define MUTEX_LOCK(m) osMutexWait(m, osWaitForever)
#define MUTEX_TYPE osMutexId
#define MUTEX_UNLOCK(m) osMutexRelease(m)
#define SEM_CREATE() osSemaphoreCreate(0, 1)
#define SEM_POST(s) osSemaphoreRelease(s)
#define SEM_TYPE osSemaphoreId
#define SEM_WAIT(s) osSemaphoreWait(s, osWaitForever)
#else
#define MUTEX_CREATE() osMutexNew(0)
#define MUTEX_LOCK(m) osMutexAcquire(m, osWaitForever)
#define MUTEX_TYPE osMutexId_t
#define MUTEX_UNLOCK(m) osMutexRelease(m)
#define SEM_CREATE() osSemaphoreNew(1, 0, 0)
#define SEM_POST(s) osSemaphoreRelease(s)
#define SEM_TYPE osSemaphoreId_t
#define SEM_WAIT(s) osSemaphoreAcquire(s, osWaitForever)
#endif

#define JPEG_BUFFER_EMPTY 0
#define JPEG_BUFFER_FULL  1
#define NB_OUTPUT_DATA_BUFFERS 2

extern volatile uint32_t JPEG_OUT_Read_BufferIndex;
extern volatile uint32_t DMA2D_CopyBufferEnd;

typedef struct
{
    uint8_t State;
    uint8_t *DataBuffer;
    uint32_t DataBufferSize;
    uint32_t MCU_index;
} JPEG_Data_BufferTypeDef;

extern JPEG_Data_BufferTypeDef Jpeg_OUT_BufferTab[NB_OUTPUT_DATA_BUFFERS];

extern "C" void DMA2D_CopyBuffer(JPEG_Data_BufferTypeDef& job);
extern "C" void DMA2D_ExternalJobCompleted(JPEG_Data_BufferTypeDef& job);

/**
 * @class STM32DMA
 *
 * @brief This class specializes DMA_Interface for the STM32 processors.
 *
 * @sa touchgfx::DMA_Interface
 */
class STM32DMA : public touchgfx::DMA_Interface
{
    /**
     * @typedef touchgfx::DMA_Interface Base
     *
     * @brief Defines an alias representing the base.
     *
     Defines an alias representing the base.
     */
    typedef touchgfx::DMA_Interface Base;

public:
    /**
     * @fn STM32DMA::STM32DMA();
     *
     * @brief Default constructor.
     *
     *        Default constructor.
     */
    STM32DMA();

    /**
     * @fn STM32DMA::~STM32DMA();
     *
     * @brief Destructor.
     *
     *        Destructor.
     */
    virtual ~STM32DMA();

    /**
     * @fn DMAType touchgfx::STM32DMA::getDMAType()
     *
     * @brief Function for obtaining the DMA type of the concrete DMA_Interface implementation.
     *
     *        Function for obtaining the DMA type of the concrete DMA_Interface implementation.
     *        As default, will return DMA_TYPE_CHROMART type value.
     *
     * @return a DMAType value of the concrete DMA_Interface implementation.
     */
    virtual touchgfx::DMAType getDMAType(void)
    {
        return touchgfx::DMA_TYPE_CHROMART;
    }

    /**
     * @fn touchgfx::BlitOperations STM32DMA::getBlitCaps();
     *
     * @brief Gets the blit capabilities.
     *
     *        Gets the blit capabilities.
     *
     *        This DMA supports a range of blit caps: BLIT_OP_COPY, BLIT_OP_COPY_ARGB8888,
     *        BLIT_OP_COPY_ARGB8888_WITH_ALPHA, BLIT_OP_COPY_A4, BLIT_OP_COPY_A8.
     *
     *
     * @return Currently supported blitcaps.
     */
    virtual touchgfx::BlitOperations getBlitCaps();

    /**
     * @fn void STM32DMA::initialize();
     *
     * @brief Perform hardware specific initialization.
     *
     *        Perform hardware specific initialization.
     */
    virtual void initialize();

    /**
     * @fn void STM32DMA::signalDMAInterrupt()
     *
     * @brief Raises a DMA interrupt signal.
     *
     *        Raises a DMA interrupt signal.
     */
    virtual void signalDMAInterrupt()
    {
        if(!started_by_external_job)
        {
            executeCompleted();

            /* Start new external job if next buffer is full */
            if (Jpeg_OUT_BufferTab[JPEG_OUT_Read_BufferIndex].State == JPEG_BUFFER_FULL && !DMA2D_CopyBufferEnd && !isReserved && !isRunning)
            {
                started_by_external_job = true;
                externalJobExecute();
            }
        }
        else
        {
            externalJobCompleted();

            /* Prioritize BlitOps if there are any pending */
            if (!queue.isEmpty() && isAllowed)
            {
                started_by_external_job = false;
                execute();
            }
        }
    }

    virtual void start()
    {
        MUTEX_LOCK(mutexIsRunning);
        if (!queue.isEmpty() && isAllowed && !isRunning)
        {
            started_by_external_job = false;
            execute();
        }
        else if ((Jpeg_OUT_BufferTab[JPEG_OUT_Read_BufferIndex].State == JPEG_BUFFER_FULL) && !isReserved && !isRunning)
        {
            started_by_external_job = true;
            externalJobExecute();
        }
        MUTEX_UNLOCK(mutexIsRunning);
    }

protected:
    /**
     * @fn virtual void STM32DMA::setupDataCopy(const touchgfx::BlitOp& blitOp);
     *
     * @brief Configures the DMA for copying data to the frame buffer.
     *
     *        Configures the DMA for copying data to the frame buffer.
     *
     * @param blitOp Details on the copy to perform.
     */
    virtual void setupDataCopy(const touchgfx::BlitOp& blitOp);

    /**
     * @fn virtual void STM32DMA::setupDataFill(const touchgfx::BlitOp& blitOp);
     *
     * @brief Configures the DMA for "filling" the frame-buffer with a single color.
     *
     *        Configures the DMA for "filling" the frame-buffer with a single color.
     *
     * @param blitOp Details on the "fill" to perform.
     */
    virtual void setupDataFill(const touchgfx::BlitOp& blitOp);

    /**
     * @fn void STM32DMA::externalJobCompleted();
     *
     * @brief Handle DMA2D when an external job has been executed
     *
     * @param None
     */
    void externalJobCompleted()
    {
        if (isRunning)
        {
            isRunning = false;
            DMA2D_ExternalJobCompleted(Jpeg_OUT_BufferTab[JPEG_OUT_Read_BufferIndex]);
        }
    }

    /**
     * @fn void STM32DMA::externalJobExecute();
     *
     * @brief Executes an external DMA2D job
     *
     * @param None
     */
    void externalJobExecute()
    {
        isRunning = true;
        DMA2D_CopyBuffer(Jpeg_OUT_BufferTab[JPEG_OUT_Read_BufferIndex]);
    }

private:
    touchgfx::LockFreeDMA_Queue dma_queue;
    touchgfx::BlitOp queue_storage[96];
    bool started_by_external_job;
    MUTEX_TYPE mutexIsRunning;

    /**
     * @fn void STM32DMA::getChromARTInputFormat()
     *
     * @brief Convert Bitmap format to ChromART Input format.
     *
     * @param format Bitmap format.
     *
     * @return ChromART Input format.
     */

    inline uint32_t getChromARTInputFormat(touchgfx::Bitmap::BitmapFormat format);

    /**
     * @fn void STM32DMA::getChromARTOutputFormat()
     *
     * @brief Convert Bitmap format to ChromART Output format.
     *
     * @param format Bitmap format.
     *
     * @return ChromART Output format.
     */
    inline uint32_t getChromARTOutputFormat(touchgfx::Bitmap::BitmapFormat format);
};

#endif // STM32DMA_HPP
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
