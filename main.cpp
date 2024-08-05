/* mbed Microcontroller implementation
 * Tp Nro2
 * Modularization, functions private and public,machine state finite
 */

#include "alcohol_system.h"

int main()
{
    alcoholSystemInit();
    while (true) {
        alcoholSystemUpdate();
    }
}