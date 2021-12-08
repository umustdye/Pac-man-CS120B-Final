// Permission to copy is granted provided that this header remains intact. 
// This software is provided with no warranties.

////////////////////////////////////////////////////////////////////////////////

#ifndef USART_H
#define USART_H

// USART Setup Values
#define F_CPU 8000000UL // Assume uC operates at 8MHz
#define BAUD_RATE 9600
#define BAUD_PRESCALE (((F_CPU / (BAUD_RATE * 16UL))) - 1)

////////////////////////////////////////////////////////////////////////////////
//Functionality - Initializes TX0 and RX0 on PORT D
//Parameter: None
//Returns: None
void initUSART_1()
{
	// Turn on the reception circuitry
	// Use 8-bit character sizes - URSEL bit set to select the UCRSC register
	// Turn on receiver and transmitter
	UCSR1B |= (1 << RXEN1)  | (1 << TXEN1);
	//UCSR0C |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	/* Set frame format: 8data, 2stop bit */
	UCSR1C = (1<<USBS1)|(3<<UCSZ01); // from datasheet pg. 243
	// Load lower 8-bits of the baud rate value into the low byte of the UBRR register
	UBRR1L = BAUD_PRESCALE;
	// Load upper 8-bits of the baud rate value into the high byte of the UBRR register
	UBRR1H = (BAUD_PRESCALE >> 8);
}



////////////////////////////////////////////////////////////////////////////////
//Functionality - checks if USART is ready to send
//Parameter: None
//Returns: 1 if true else 0
unsigned char USART_IsSendReady_1()
{
	return (UCSR1A & (1 << UDRE1));
}
////////////////////////////////////////////////////////////////////////////////
//Functionality - checks if USART has recieved data
//Parameter: None
//Returns: 1 if true else 0
unsigned char USART_HasTransmitted_1()
{
	return (UCSR1A & (1 << TXC1));
}
////////////////////////////////////////////////////////////////////////////////
// **** WARNING: THIS FUNCTION BLOCKS MULTI-TASKING; USE WITH CAUTION!!! ****
//Functionality - checks if USART has recieved data
//Parameter: None
//Returns: 1 if true else 0
unsigned char USART_HasReceived_1()
{
	return (UCSR1A & (1 << RXC1));
}
////////////////////////////////////////////////////////////////////////////////
//Functionality - Flushes the data register
//Parameter: None
//Returns: None
void USART_Flush_1()
{
	static unsigned char dummy;
	while ( UCSR1A & (1 << RXC1) ) { dummy = UDR1; }
}
////////////////////////////////////////////////////////////////////////////////
// **** WARNING: THIS FUNCTION BLOCKS MULTI-TASKING; USE WITH CAUTION!!! ****
//Functionality - Sends an 8-bit char value
//Parameter: Takes a single unsigned char value
//Returns: None
void USART_Send_1(unsigned char sendMe)
{
	while( !(UCSR1A & (1 << UDRE1)) );
	UDR1 = sendMe;
}
////////////////////////////////////////////////////////////////////////////////
// **** WARNING: THIS FUNCTION BLOCKS MULTI-TASKING; USE WITH CAUTION!!! ****
//Functionality - receives an 8-bit char value
//Parameter: None
//Returns: Unsigned char data from the receive buffer
unsigned char USART_Receive_1()
{
	while ( !(UCSR1A & (1 << RXC1)) ); // Wait for data to be received
	return UDR1; // Get and return received data from buffer
}


#endif //USART_H
