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
#include <string.h>
#include <stdlib.h>
//n текущее значение АЦП
//k номер канала (фазы)
#define SHIFT (3)
#define CH_NUM (1<<SHIFT)
uint8 buffer_out[128];
  int filter(int a);
    int16 Nk[8];//Прендыдущий периуд данных
    int16 NeWk[8];//данные после удаления постоянной
    int BIX_X[8];//входной сигнал, который нужно отфильтровать
    int BIX_Y[8];//выходной (отфильтрованный) сигнал
void USAR_();
    static int16 NSin[8]={1000,707,0,-707,-1000,-707,0,707};
    static int16 NCos[8]={0,707,1000,707,0,-707,-1000,-707};

void Sk (int16 NewValue, uint8 k);//Удаление постоянной составляющей

int8 Server_Function(const char* buf, uint16 Len);
void R_D_F (const char* buf, uint8 ofset);//Расчет для генератора
