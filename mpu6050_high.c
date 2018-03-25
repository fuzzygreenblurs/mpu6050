/* Name: main.c
 * Author: Zhyhariev Mikhail
 * License: MIT
 */

#include "mpu6050.h"

/**
 * [MPU6050_countTemp computing the temperature in degrees Celsius]
 * @param mpu6050 - structure that containing all measured variables
 */
void MPU6050_countTemp(mpu6050 *mpu6050) {
    // getting the values of temp_high and temp_l registers
    MPU6050_getTemp(mpu6050);

    // computing the temperature in degrees
    mpu6050->temp = (mpu6050->temp_h << 8) + mpu6050->temp_l;
    mpu6050->temp /= 340;
    mpu6050->temp += 36.53;
}
