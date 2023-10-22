/* startup_cortxM3
Eng. Abdelrahman*/

.section .vectors
.word 0x20001000			
.word _reset				/*1  reset  */
.word Vector_handler		/*2  NMI  */
.word Vector_handler		/*3  Hard fault  */
.word Vector_handler		/*4  Mem manage  */
.word Vector_handler		/*5  Bus fault */
.word Vector_handler		/*6  Usage fault */	
.word Vector_handler		/*7  Reserved  */
.word Vector_handler		/*8  Reserved  */
.word Vector_handler		/*9  System service call  */
.word Vector_handler		/*10 Debug menitor  */
.word Vector_handler		/*11 Reserved  */
.word Vector_handler		/*12 System service request  */
.word Vector_handler		/*13 Tick timer  */	
.word Vector_handler		/*14 Watchdog interrupt  */
.word Vector_handler		/*15 Line interrupt  */
.word Vector_handler		/*16 Tamper interrupt  */
.word Vector_handler		/*17 RTC interrupt  */
.word Vector_handler		/*18 Flash interrupt  */
.word Vector_handler		/*19 RCC interrupt  */

.section .text
_reset:
	bl main
	b .
.thumb_func

Vector_handler:
	b _reset
 