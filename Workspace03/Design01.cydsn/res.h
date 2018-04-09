/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
// Фильтр Баттерворта 4 порядка 1000 -> 100; 200  = -30 дб
//
// 1 звено y0 = 0,061885*(x0+x2) + 0,123770*x1 + 1,048600*y1 - 0,296140*y2
// Коэффициенты a0,a1,b1,b2,c1 = 2028, 4056, 1593, -9704, 1 
// 2 звено y0 = 0,077956*(x0+x2) + 0,155913*x1 + 1,320910*y1 - 0,632739*y2
// Коэффициенты a0,a1,b1,b2,c1 = 2554, 5109, 10516, -20734, 1
//
int16_t            fltr_c1[5] = {2028, 4056, 1593, -9704, 1},
                fltr_c2[5] = {2554, 5109, 10516, -20734, 1};
uint8 cnt_line=0;
                
#             
struct    data_s
{
  int16_t        x[3],y[3];                                // Данные фильтра
};

struct    coef_s
{
  int16_t        a0, a1, b1, b2, c1;                        // Коэффициенты фильтра
};
struct    data_ADC
{
  int16_t        x[3],y[3],z[3];                            // Данные фильтра
};


void fir2_16(uint8_t * data, uint8_t * coef);
struct data_ADC lin[12]; // Объявляем массив данных.   

/* [] END OF FILE */
