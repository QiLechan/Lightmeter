#include "ssd1306.h"
#include "fonts.h"   // ??,??6x8, 8x16,??????

// ????
static void SSD1306_WriteCmd(uint8_t cmd)
{
    uint8_t d[2] = {0x00, cmd};
    HAL_I2C_Master_Transmit(&hi2c1, SSD1306_I2C_ADDR, d, 2, 10);
}

// ????
static void SSD1306_WriteData(uint8_t data)
{
    uint8_t d[2] = {0x40, data};
    HAL_I2C_Master_Transmit(&hi2c1, SSD1306_I2C_ADDR, d, 2, 10);
}

// 显示一个字符 (6x8 字符)
void SSD1306_ShowChar(uint8_t x, uint8_t y, char chr)
{
    uint8_t c = chr - 32;   // ASCII 从空格(32)开始
    if(c > 95) c = 0;       // 超出范围显示空格

    // 设置光标位置
    SSD1306_WriteCmd(0xB0 + y);                // 设置页地址 (0~7)
    SSD1306_WriteCmd(0x00 + (x & 0x0F));       // 设置列低地址
    SSD1306_WriteCmd(0x10 + (x >> 4));         // 设置列高地址

    // 写入字模数据
    for(uint8_t i = 0; i < 6; i++) {
        SSD1306_WriteData(Font6x8[c][i]);
    }
}

// ???
void SSD1306_Init(void)
{
    HAL_Delay(100);
    SSD1306_WriteCmd(0xAE); // ????
    SSD1306_WriteCmd(0x20); // ????????
    SSD1306_WriteCmd(0x10); // Page addressing mode
    SSD1306_WriteCmd(0xB0);
    SSD1306_WriteCmd(0xC8);
    SSD1306_WriteCmd(0x00);
    SSD1306_WriteCmd(0x10);
    SSD1306_WriteCmd(0x40);
    SSD1306_WriteCmd(0x81);
    SSD1306_WriteCmd(0x7F);
    SSD1306_WriteCmd(0xA1);
    SSD1306_WriteCmd(0xA6);
    SSD1306_WriteCmd(0xA8);
    SSD1306_WriteCmd(0x3F);
    SSD1306_WriteCmd(0xA4);
    SSD1306_WriteCmd(0xD3);
    SSD1306_WriteCmd(0x00);
    SSD1306_WriteCmd(0xD5);
    SSD1306_WriteCmd(0xF0);
    SSD1306_WriteCmd(0xD9);
    SSD1306_WriteCmd(0x22);
    SSD1306_WriteCmd(0xDA);
    SSD1306_WriteCmd(0x12);
    SSD1306_WriteCmd(0xDB);
    SSD1306_WriteCmd(0x20);
    SSD1306_WriteCmd(0x8D);
    SSD1306_WriteCmd(0x14);
    SSD1306_WriteCmd(0xAF); // ????
    SSD1306_Clear();
}

// ??
void SSD1306_Clear(void)
{
    for(uint8_t page=0; page<8; page++) {
        SSD1306_WriteCmd(0xB0 + page);
        SSD1306_WriteCmd(0x00);
        SSD1306_WriteCmd(0x10);
        for(uint8_t x=0; x<128; x++) {
            SSD1306_WriteData(0x00);
        }
    }
}

// ?????(???)
void SSD1306_ShowString(uint8_t x, uint8_t y, char *chr)
{
    while(*chr) {
        SSD1306_ShowChar(x, y, *chr);
        x += 6;
        chr++;
    }
}
