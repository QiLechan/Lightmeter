#ifndef __BH1750_H__
#define __BH1750_H__

#include "stm32f1xx_hal.h"

#define BH1750_ADDRESS 0x23 << 1  // ????,HAL I2C ??8???

extern I2C_HandleTypeDef hi2c2;

void BH1750_Init(void);
float BH1750_ReadLight(void);

#endif
