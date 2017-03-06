#include <motor_control.h>
#include<reg52.h>

sbit M00 = P0^0;
sbit M01 = P0^1;
sbit M10 = P0^2;
sbit M11 = P0^3;

sbit M20 = P0^4;
sbit M21 = P0^5;
sbit M30 = P0^6;
sbit M31 = P0^7;
 
 void bot_Init(void)
 {
	M00 = 0;
	M01 = 0;
	M10 = 0;
	M11 = 0;

	M20 = 0;
	M21 = 0;
	M30 = 0;
	M31 = 0;
 }
 void bot_Start(void)
 {

 }

  void bot_Stop(void)
 {
  	M00 = 0;
	M01 = 0;
	M10 = 0;
	M11 = 0;
 }

 void bot_MoveForward(void)
 {
 	M00 = 1;
	M01 = 0;
	M10 = 1;
	M11 = 0;
 }

 void bot_MoveBackward(void)
 {
  	M00 = 0;
	M01 = 1;
	M10 = 0;
	M11 = 1;
 }
 void bot_MoveForwardRight(void)
 {
	M00 = 0;
	M01 = 0;
	M10 = 1;
	M11 = 0;
 }
 void bot_MoveForwardLeft(void)
{
	  	M00 = 0;
		M01 = 0;
		M10 = 1;
		M11 = 0;
}


void bot_MoveBackwardRight(void)
 {
  	M00 = 0;
	M01 = 1;
	M10 = 0;
	M11 = 1;
 }

 void bot_MoveBackwardLeft(void)
 {
  	M00 = 0;
	M01 = 1;
	M10 = 0;
	M11 = 1;
 }


 void bot_ArmUp(void)
 {
  	M20 = 0;
	M21 = 1;
 }
 void bot_ArmDown(void)
 {
  	M20 = 1;
	M21 = 0;
 }
 void bot_ArmStop(void)
 {
  	M20 = 0;
	M21 = 0;
 }
 void bot_PickOpen(void)
 {
  	M30 = 0;
	M31 = 1;
 }
 void bot_PickClose(void)
 {
  	M30 = 1;
	M31 = 0;
 }
 void bot_PickStop(void)
 {
  	M30 = 0;
	M31 = 0;
 }