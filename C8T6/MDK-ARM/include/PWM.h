#ifndef _PWM_H
#define _PWM_H

#include "type.h"

void PWM_Setting_Car(THE_CAR Car, unsigned char Num);
void Car_Move(unsigned char Move_MOD, unsigned char Num);
void Car_Left();
void Car_Right();
void Car_Left_Move();
void Car_Right_Move();
void Car_Up();
void Car_Down();
void Car_Stop();
void Car_Move_Version(unsigned char Num);

#endif