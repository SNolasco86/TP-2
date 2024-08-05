//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "alcohol_system.h"

#include "uart.h"
#include "button.h"
#include "adc.h"
#include "display.h"


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================


void alcoholSystemInit()
{
    displayInit(DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER);
    initADC();
    initUART();
    initButton();
}

void alcoholSystemUpdate()
{
    
    inputUpdate();
    alcoholUpdate();
    displayUpdate();
    UARTUpdate() ;
    delay(SYSTEM_TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================