#ifndef __SSD1306_H__
#define __SSD1306_H__

#include "stm32f1xx_hal.h"

// I2C??(????7??? << 1)
#define SSD1306_I2C_ADDR 0x78

extern I2C_HandleTypeDef hi2c1;

void SSD1306_Init(void);
void SSD1306_Clear(void);
void SSD1306_ShowChar(uint8_t x, uint8_t y, char chr);
void SSD1306_ShowString(uint8_t x, uint8_t y, char *chr);

#endif
