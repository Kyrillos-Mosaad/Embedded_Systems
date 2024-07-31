#include "uart.h"
char string_buffer[100] = "Kyrillos Mosaad" ;
const char string_buffer2[100] = "Kyrillos Mosaad" ;
 void main(void)
 {
 	Uart_Send_String(string_buffer);
 }