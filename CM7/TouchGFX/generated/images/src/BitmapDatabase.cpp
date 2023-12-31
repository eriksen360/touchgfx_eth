// 4.22.1 0x9708a6c8
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_alternate_theme_images_backgrounds_1024x600_poly[]; // BITMAP_ALTERNATE_THEME_IMAGES_BACKGROUNDS_1024X600_POLY_ID = 0, Size: 1024x600 pixels
extern const unsigned char image_alternate_theme_images_widgets_boxprogress_normal_medium[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BOXPROGRESS_NORMAL_MEDIUM_ID = 1, Size: 300x10 pixels
extern const unsigned char image_alternate_theme_images_widgets_slider_horizontal_thick_filler_medium[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_FILLER_MEDIUM_ID = 2, Size: 300x10 pixels
extern const unsigned char image_alternate_theme_images_widgets_slider_horizontal_thick_rounded_dark[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_ROUNDED_DARK_ID = 3, Size: 32x32 pixels
extern const unsigned char image_alternate_theme_images_widgets_slider_horizontal_thick_track_medium[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_TRACK_MEDIUM_ID = 4, Size: 300x10 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_alternate_theme_images_backgrounds_1024x600_poly, 0, 1024, 600, 0, 0, 1024, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 600, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_alternate_theme_images_widgets_boxprogress_normal_medium, 0, 300, 10, 0, 0, 300, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 10, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_alternate_theme_images_widgets_slider_horizontal_thick_filler_medium, 0, 300, 10, 5, 0, 290, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 10, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_slider_horizontal_thick_rounded_dark, 0, 32, 32, 2, 2, 28, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 28, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_slider_horizontal_thick_track_medium, 0, 300, 10, 5, 0, 290, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 10, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
