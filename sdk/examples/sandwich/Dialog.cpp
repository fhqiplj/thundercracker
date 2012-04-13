#include "Dialog.h"
#include "Game.h"

static const uint8_t font_data[] = {
    0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x02,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x01,0x00,0x00,
    0x04,0x00,0x00,0x05,0x05,0x05,0x00,0x00,0x00,0x00,0x00,0x00,
    0x06,0x00,0x00,0x0a,0x1f,0x0a,0x1f,0x0a,0x00,0x00,0x00,0x00,
    0x06,0x00,0x04,0x0e,0x15,0x05,0x0e,0x14,0x15,0x0e,0x04,0x00,
    0x06,0x00,0x00,0x12,0x15,0x0a,0x04,0x0a,0x15,0x09,0x00,0x00,
    0x06,0x00,0x00,0x06,0x09,0x05,0x02,0x15,0x09,0x16,0x00,0x00,
    0x02,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0x00,0x04,0x02,0x02,0x01,0x01,0x01,0x02,0x02,0x04,0x00,
    0x04,0x00,0x01,0x02,0x02,0x04,0x04,0x04,0x02,0x02,0x01,0x00,
    0x06,0x00,0x00,0x04,0x15,0x0e,0x15,0x04,0x00,0x00,0x00,0x00,
    0x06,0x00,0x00,0x00,0x04,0x04,0x1f,0x04,0x04,0x00,0x00,0x00,
    0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x02,0x01,
    0x05,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x00,0x00,
    0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x00,0x00,
    0x06,0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,0x01,0x01,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x19,0x15,0x13,0x11,0x0e,0x00,0x00,
    0x03,0x00,0x00,0x02,0x03,0x02,0x02,0x02,0x02,0x02,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x10,0x08,0x04,0x02,0x1f,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x10,0x0c,0x10,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x08,0x0c,0x0a,0x09,0x1f,0x08,0x08,0x00,0x00,
    0x06,0x00,0x00,0x1f,0x01,0x0f,0x10,0x10,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x01,0x0f,0x11,0x11,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x1f,0x10,0x10,0x08,0x04,0x04,0x04,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x11,0x0e,0x11,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x11,0x11,0x1e,0x10,0x0e,0x00,0x00,
    0x03,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x03,0x03,0x00,0x00,
    0x03,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x03,0x03,0x02,0x01,
    0x05,0x00,0x00,0x08,0x04,0x02,0x01,0x02,0x04,0x08,0x00,0x00,
    0x05,0x00,0x00,0x00,0x00,0x0f,0x00,0x0f,0x00,0x00,0x00,0x00,
    0x05,0x00,0x00,0x01,0x02,0x04,0x08,0x04,0x02,0x01,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x10,0x08,0x04,0x00,0x04,0x00,0x00,
    0x06,0x00,0x0e,0x11,0x11,0x15,0x17,0x0d,0x01,0x11,0x0e,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x11,0x1f,0x11,0x11,0x11,0x00,0x00,
    0x06,0x00,0x00,0x0f,0x11,0x11,0x0f,0x11,0x11,0x0f,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x01,0x01,0x01,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x0f,0x11,0x11,0x11,0x11,0x11,0x0f,0x00,0x00,
    0x06,0x00,0x00,0x1f,0x01,0x01,0x0f,0x01,0x01,0x1f,0x00,0x00,
    0x06,0x00,0x00,0x1f,0x01,0x01,0x0f,0x01,0x01,0x01,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x01,0x19,0x11,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x11,0x11,0x11,0x1f,0x11,0x11,0x11,0x00,0x00,
    0x02,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,
    0x06,0x00,0x00,0x10,0x10,0x10,0x10,0x11,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x11,0x09,0x05,0x03,0x05,0x09,0x11,0x00,0x00,
    0x06,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x1f,0x00,0x00,
    0x06,0x00,0x00,0x11,0x1b,0x15,0x11,0x11,0x11,0x11,0x00,0x00,
    0x06,0x00,0x00,0x11,0x13,0x15,0x19,0x11,0x11,0x11,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x11,0x11,0x11,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x0f,0x11,0x11,0x0f,0x01,0x01,0x01,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x11,0x11,0x11,0x11,0x0e,0x10,0x00,
    0x06,0x00,0x00,0x0f,0x11,0x11,0x0f,0x11,0x11,0x11,0x00,0x00,
    0x06,0x00,0x00,0x0e,0x11,0x01,0x0e,0x10,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x1f,0x04,0x04,0x04,0x04,0x04,0x04,0x00,0x00,
    0x06,0x00,0x00,0x11,0x11,0x11,0x11,0x11,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x11,0x11,0x11,0x0a,0x0a,0x04,0x04,0x00,0x00,
    0x06,0x00,0x00,0x11,0x11,0x11,0x11,0x15,0x1b,0x11,0x00,0x00,
    0x06,0x00,0x00,0x11,0x0a,0x04,0x04,0x04,0x0a,0x11,0x00,0x00,
    0x06,0x00,0x00,0x11,0x11,0x11,0x0a,0x04,0x04,0x04,0x00,0x00,
    0x06,0x00,0x00,0x1f,0x10,0x08,0x04,0x02,0x01,0x1f,0x00,0x00,
    0x03,0x00,0x03,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x03,0x00,
    0x06,0x01,0x01,0x02,0x02,0x04,0x04,0x08,0x08,0x10,0x10,0x00,
    0x03,0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,
    0x06,0x00,0x04,0x0a,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0x00,
    0x04,0x00,0x01,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x1e,0x11,0x11,0x19,0x16,0x00,0x00,
    0x06,0x00,0x00,0x01,0x01,0x0f,0x11,0x11,0x11,0x0f,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x0e,0x11,0x01,0x01,0x1e,0x00,0x00,
    0x06,0x00,0x00,0x10,0x10,0x1e,0x11,0x11,0x11,0x1e,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x0e,0x11,0x1f,0x01,0x1e,0x00,0x00,
    0x05,0x00,0x00,0x0c,0x02,0x07,0x02,0x02,0x02,0x02,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x1e,0x11,0x11,0x11,0x1e,0x10,0x0e,
    0x06,0x00,0x00,0x01,0x01,0x0f,0x11,0x11,0x11,0x11,0x00,0x00,
    0x02,0x00,0x00,0x01,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,
    0x04,0x00,0x00,0x04,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x03,
    0x06,0x00,0x00,0x01,0x01,0x09,0x05,0x07,0x09,0x11,0x00,0x00,
    0x03,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x03,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x0f,0x15,0x15,0x15,0x15,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x0d,0x13,0x11,0x11,0x11,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x0e,0x11,0x11,0x11,0x0e,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x0f,0x11,0x11,0x11,0x0f,0x01,0x01,
    0x06,0x00,0x00,0x00,0x00,0x1e,0x11,0x11,0x11,0x1e,0x10,0x10,
    0x06,0x00,0x00,0x00,0x00,0x0d,0x13,0x01,0x01,0x01,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x1e,0x01,0x0e,0x10,0x0f,0x00,0x00,
    0x05,0x00,0x00,0x02,0x02,0x0f,0x02,0x02,0x02,0x0c,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x11,0x11,0x11,0x19,0x16,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x11,0x11,0x0a,0x0a,0x04,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x15,0x15,0x15,0x15,0x0a,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x11,0x0a,0x04,0x0a,0x11,0x00,0x00,
    0x06,0x00,0x00,0x00,0x00,0x11,0x11,0x11,0x11,0x1e,0x10,0x0e,
    0x06,0x00,0x00,0x00,0x00,0x1f,0x08,0x04,0x02,0x1f,0x00,0x00,
};

#define kFontHeight 11


static uint16_t rgb565(uint8_t r, uint8_t g, uint8_t b) {
    // Round to the nearest 5/6 bit color. Note that simple
    // bit truncation does NOT produce the best result!
    uint16_t r5 = ((uint16_t)r * 31 + 128) / 255;
    uint16_t g6 = ((uint16_t)g * 63 + 128) / 255;
    uint16_t b5 = ((uint16_t)b * 31 + 128) / 255;
    return (r5 << 11) | (g6 << 5) | b5;
}

static RGB565 color_lerp(uint8_t alpha) {
    return RGB565::fromRGB(0xddedc1).lerp(RGB565::fromRGB(0x000000), alpha);
}

void Dialog::Init(VideoBuffer *cube) {
    mCube = cube;
    mCube->initMode(FB128);
    mCube->colormap.setMono(color_lerp(0), color_lerp(0));    
}

const char* Dialog::Show(const char* str) {
    unsigned count, length;
    MeasureText(str, &count, &length);
	mPosition.x = (128 - length) >> 1;
    DrawText(str);
    mPosition.y += kFontHeight+1;
    return str + count;
}

void Dialog::DrawGlyph(char ch) {
    uint8_t index = ch - ' ';
    const uint8_t *data = font_data + (index * kFontHeight) + index;
    uint8_t escapement = *(data++);
    const Int2 size = {8, kFontHeight};
    mCube->fb128.bitmap(mPosition, size, data, 1);
    mPosition.x += escapement;
}

unsigned Dialog::MeasureGlyph(char ch) {
    uint8_t index = ch - ' ';
    const uint8_t *data = font_data + (index * (kFontHeight + 1));
    return data[0];
}

void Dialog::DrawText(const char *str) {
    char c;
    while ((c = *str) && c != '\n') {
        str++;
        DrawGlyph(c);
    }
}

void Dialog::MeasureText(const char *str, unsigned *outCount, unsigned *outPx) {
    *outPx = 0;
    *outCount = 0;
    char c;
    while ((c = *str) && c != '\n') {
        str++;
        (*outCount)++;
        *outPx += MeasureGlyph(c);
    }
    if (c) { (*outCount)++; }
}

void Dialog::Erase() {
    mPosition.y = 5;
    mCube->fb128.fill(0);
}

void Dialog::SetAlpha(uint8_t i) {
    mCube->colormap[0] = color_lerp(i);
}

void Dialog::ShowAll(const char* lines) {
    while(*lines) {
        lines = Show(lines);
    }
}
