#include "mbed.h"
#include "arm_book_lib.h"

#include "button.h"

#include "alcohol_system.h"

//=====[Declaration of private defines]========================================

#define DEBOUNCE_BUTTON_TIME_MS                 40

//=====[Declaration of private data types]=====================================

typedef enum {
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_FALLING,
    BUTTON_RISING
} buttonState_t;

//=====[Declaration and initialization of public global objects]===============
                           
DigitalIn send_stop_button(BUTTON1);

buttonState_t send_stopButtonState;

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============


static int newStateButtonSendStop = 0;
static int accumulatedTimeInputSendStop = 0;
static int accumulatedDebounceButtonTimeSendStop = 0;

//=====[Declarations (prototypes) of private functions]========================

static void debounceButtonInit();
static void debounceButtonUpdate();

//=====[Implementations of public functions]===================================

void initButton()
{
    debounceButtonInit();
}

void inputUpdate()
{
    debounceButtonUpdate();
}

void debounceButtonInit()
{
    if( send_stop_button ) {
        send_stopButtonState = BUTTON_DOWN;
    } else {
        send_stopButtonState = BUTTON_UP;
    }
}

void debounceButtonUpdate()
{
    bool send_stopButtonReleasedEvent = false;

    switch( send_stopButtonState ) {

    case BUTTON_UP:
        if( send_stop_button ) {
            send_stopButtonState = BUTTON_FALLING;
            accumulatedDebounceButtonTimeSendStop = 0;
        }
        break;

    case BUTTON_FALLING:
        if( accumulatedDebounceButtonTimeSendStop >= DEBOUNCE_BUTTON_TIME_MS ) {
            if( send_stop_button) {
                send_stopButtonState = BUTTON_DOWN;
                newStateButtonSendStop=1;
            } else {
                send_stopButtonState = BUTTON_UP;
                newStateButtonSendStop=0;
            }
           
        }
        accumulatedDebounceButtonTimeSendStop += SYSTEM_TIME_INCREMENT_MS;
        break;

    case BUTTON_DOWN:
        if( !send_stop_button) {
            send_stopButtonState = BUTTON_RISING;
            accumulatedDebounceButtonTimeSendStop = 0;
        }
        break;

    case BUTTON_RISING:
        if( accumulatedDebounceButtonTimeSendStop >= DEBOUNCE_BUTTON_TIME_MS ) {
            if( !send_stop_button ) {
                send_stopButtonState = BUTTON_UP;
                send_stopButtonReleasedEvent = true;
                newStateButtonSendStop=0;
            } else {
                send_stopButtonState = BUTTON_DOWN;
                newStateButtonSendStop=1;
            }
            
        }
        accumulatedDebounceButtonTimeSendStop += SYSTEM_TIME_INCREMENT_MS;
        break;

    default:
        debounceButtonInit();
        break;
    }
}


int readStateButtonSendOff()
{
    return newStateButtonSendStop;
}


//=====[Implementations of private functions]==================================