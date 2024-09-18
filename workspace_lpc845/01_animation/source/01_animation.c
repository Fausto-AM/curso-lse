#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "fsl_debug_console.h"

// Etiqueta para todos los pines a usar
#define A	11
#define B   10
#define C   6
#define D   14
#define E   0
#define F   13
#define USER_BUTTON 4
#define ANODE1 8
#define ANODE2 9
/*
 * @brief   Application entry point.
*/
int main(void) {
	// Inicializacion
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    // Estructura de configuracion para salida
    gpio_pin_config_t out_config = { kGPIO_DigitalOutput, 1 };
    // Estructura de configuración para entrada
    gpio_pin_config_t in_config = { kGPIO_DigitalInput };
    // Habilito el clock del GPIO 0
    GPIO_PortInit(GPIO, 0);
    // Configuro el pin 11 del GPIO 0 como salida
    GPIO_PinInit(GPIO, 0, A, &out_config);
    // Configuro el pin 10 del GPIO 0 como salida
    GPIO_PinInit(GPIO, 0, B, &out_config);
    // Configuro el pin 6 del GPIO 0 como salida
    GPIO_PinInit(GPIO, 0, C, &out_config);
    // Configuro el pin 14 del GPIO 0 como salida
    GPIO_PinInit(GPIO, 0, D, &out_config);
    // Configuro el pin 0 del GPIO 0 como salida
    GPIO_PinInit(GPIO, 0, E, &out_config);
    // Configuro el pin 13 del GPIO 0 como salida
    GPIO_PinInit(GPIO, 0, F, &out_config);
    // Configuro el pin 4 del GPIO 0 como entrada
    GPIO_PinInit(GPIO, 0, USER_BUTTON, &in_config);
    // Configuro el pin 8 del GPIO 0 como entrada
    GPIO_PinInit(GPIO, 0, ANODE1, &out_config);
    // Configuro el pin 9 del GPIO 0 como entrada
        GPIO_PinInit(GPIO, 0, ANODE2, &out_config);

    while(1) {
   		GPIO_PinWrite(GPIO, 0, ANODE1, 0);
   		GPIO_PinWrite(GPIO, 0, ANODE2, 0);
       	// Verifico el estado del pulsador (Posee una Pull-Up)
       	if(!GPIO_PinRead(GPIO, 0, USER_BUTTON)) {
       		// Prendo los LEDs
       			GPIO_PinWrite(GPIO, 0, F, 1);
       			GPIO_PinWrite(GPIO, 0, A, 0);
       			for(uint32_t i = 0; i < 1000000; i++);
       			GPIO_PinWrite(GPIO, 0, A, 1);
       			GPIO_PinWrite(GPIO, 0, B, 0);
       			for(uint32_t i = 0; i < 1000000; i++);
       			GPIO_PinWrite(GPIO, 0, B, 1);
       			GPIO_PinWrite(GPIO, 0, C, 0);
       			for(uint32_t i = 0; i < 1000000; i++);
       			GPIO_PinWrite(GPIO, 0, C, 1);
       			GPIO_PinWrite(GPIO, 0, D, 0);
       			for(uint32_t i = 0; i < 1000000; i++);
       			GPIO_PinWrite(GPIO, 0, D, 1);
       			GPIO_PinWrite(GPIO, 0, E, 0);
       			for(uint32_t i = 0; i < 1000000; i++);
       			GPIO_PinWrite(GPIO, 0, E, 1);
       			GPIO_PinWrite(GPIO, 0, F, 0);
       			for(uint32_t i = 0; i < 1000000; i++);
       		}
       }
    return 0;
}
