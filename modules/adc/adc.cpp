#include "mbed.h"
#include "arm_book_lib.h"

#include "adc.h"

//=====[Declaration of private defines]========================================

#define NUMBER_OF_AVG_SAMPLES                   20

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn mq3_1(A1);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static float ReadingsAverage_1  = 0.0;
static float Reading_1 = 0.0;
static float ReadingsSum_1      = 0.0;
static float ReadingsArray_1[NUMBER_OF_AVG_SAMPLES];

//=====[Declarations (prototypes) of private functions]========================

static void ReadingsArrayInit();

//=====[Implementations of public functions]===================================

void initADC(){
    ReadingsArrayInit();
}

void alcoholUpdate()
{
    static int SampleIndex = 0;
    int i = 0;
    
    ReadingsArray_1[SampleIndex] = mq3_1.read();
    SampleIndex++;
    if ( SampleIndex >= NUMBER_OF_AVG_SAMPLES) {
         SampleIndex = 0;
    
    }
    
    ReadingsSum_1 = 0.0;
    for (i = 0; i < NUMBER_OF_AVG_SAMPLES; i++) {
        ReadingsSum_1 = ReadingsSum_1 + ReadingsArray_1[i];
    }
    ReadingsAverage_1 = ReadingsSum_1 / NUMBER_OF_AVG_SAMPLES;
    
    
 }


float readADC_1(){
    return ReadingsAverage_1;
}

//=====[Implementations of private functions]==================================

static void ReadingsArrayInit() 
{
    int i;
    for( i=0; i<NUMBER_OF_AVG_SAMPLES ; i++ ) {
        ReadingsArray_1[i] = 0;
    }
}