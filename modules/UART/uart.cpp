#include "mbed.h"
#include "arm_book_lib.h"

#include "uart.h"

#include "alcohol_system.h"
#include "adc.h"
#include "button.h"



//=====[Declaration of private defines]========================================

#define NUMBER_TIME_UART            500

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

static UnbufferedSerial serial_port(USBTX, USBRX);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static int accumulatedTimeUART = 0;
static int lastStateButtonSendStop=0;
static char receivedChar;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void on_rx_interrupt()
{
    
    if (serial_port.read(&receivedChar, 1)) {
        if ( receivedChar == '0' ) {
            //LD1=1;
        }
    }
    
}

void initUART()
{
    serial_port.baud(9600);
    serial_port.format(
        /* bits */ 8,
        /* parity */ SerialBase::None,
        /* stop bit */ 1
    );
    serial_port.attach(&on_rx_interrupt, SerialBase::RxIrq);

}

void UARTUpdate()
{
    char str[17];
    int stringLength;
  
    accumulatedTimeUART = accumulatedTimeUART + SYSTEM_TIME_INCREMENT_MS;       //send data over 500ms and button1 is pressed
    
    if (accumulatedTimeUART >= NUMBER_TIME_UART && lastStateButtonSendStop !=readStateButtonSendOff())
    {
        accumulatedTimeUART=0;
        sprintf ( str, "mq3_level: %.3f \r\n", float(readADC_1()));
        stringLength = strlen(str);
        serial_port.write( str, stringLength );
    }
} 

//=====[Implementations of private functions]==================================
