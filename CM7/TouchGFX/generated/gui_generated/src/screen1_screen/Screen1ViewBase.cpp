/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Screen1ViewBase::Screen1ViewBase()
{
    __background.setPosition(0, 0, 1280, 800);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    digitalClock1.setPosition(0, 0, 100, 25);
    digitalClock1.setColor(touchgfx::Color::getColorFromRGB(153, 21, 21));
    digitalClock1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ABAJ));
    digitalClock1.displayLeadingZeroForHourIndicator(true);
    digitalClock1.setDisplayMode(touchgfx::DigitalClock::DISPLAY_12_HOUR);
    digitalClock1.setTime12Hour(10, 10, 0, true);
    add(digitalClock1);

    slider1.setXY(0, 0);
    slider1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_TRACK_MEDIUM_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_FILLER_MEDIUM_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_ROUNDED_DARK_ID));
    slider1.setupHorizontalSlider(16, 11, 0, 0, 300);
    slider1.setValueRange(0, 100);
    slider1.setValue(0);
    add(slider1);

    boxProgress1.setXY(0, 0);
    boxProgress1.setProgressIndicatorPosition(0, 0, 300, 10);
    boxProgress1.setRange(0, 100);
    boxProgress1.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    boxProgress1.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BOXPROGRESS_NORMAL_MEDIUM_ID));
    boxProgress1.setColor(touchgfx::Color::getColorFromRGB(0, 240, 255));
    boxProgress1.setValue(60);
    add(boxProgress1);

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_BACKGROUNDS_1024X600_POLY_ID));
    add(image1);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}