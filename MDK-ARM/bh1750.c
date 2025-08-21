#include "bh1750.h"

void BH1750_Init(void)
{
    uint8_t power_on = 0x01;  // Power On
    uint8_t mode = 0x10;      // Continuous H-Resolution Mode

    HAL_I2C_Master_Transmit(&hi2c2, BH1750_ADDRESS, &power_on, 1, 100);
    HAL_Delay(10);
    HAL_I2C_Master_Transmit(&hi2c2, BH1750_ADDRESS, &mode, 1, 100);
    HAL_Delay(180); // ??????
}

float BH1750_ReadLight(void)
{
    uint8_t buf[2];
    HAL_I2C_Master_Receive(&hi2c2, BH1750_ADDRESS, buf, 2, 100);

    uint16_t raw = (buf[0] << 8) | buf[1];
    return raw / 1.2f; // ??? Lux
}
