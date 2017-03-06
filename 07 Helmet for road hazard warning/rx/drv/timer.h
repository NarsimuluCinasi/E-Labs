

/* 

	* Timer Registers TL and TH for count update 
	* TMOD timer mode 8bit register to set various timer operation mode
	  lower 4bits for Timer0 and upper 4bits for Timer1.

	* GATE Gating control when set. ther timer/counter is enabled only while Intx pin is high 
	and the Trx control pin is set. when cleared, wtimer is enabled when ever the Trx control bit is set.

	* C/T Timer or counter selected cleared for timer operation

	* M0, M1-- Mode 0(13 bit timer mode), Mode1(16-bit timer/counter), Mode2(8-bit autoreload), Mode3(split timer mode)

*/