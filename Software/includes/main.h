/**
 * @file main.h
 * @author Jesutofunmi Kupoluyi (jimsufficency@gmail.com)
 * @brief This is the header file for the main.c/.cpp source file.
 * @version 0.1
 * @date 2023-09-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __MAIN_H__
#define __MAIN_H__

/* Defines */
#define F_CPU 8000000UL

/* Including required libraries */
#include <avr/io.h>
/* #include <avr/iom328p.h> */ /* For atmega328p */
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>


/** List of components
 * LEDs [3] -> Moist, Pumping and Dry
 * LCD  [1] -> 1602A (4-bit mode)
 * Pump [1] (via Optocoupler)
 * Soil Moisture sensor [1] (via ADC)
 * UART debug output [1]
*/

/* LCD pin definitions */
#define LCD_D4      PC4
#define LCD_D5      PC5
#define LCD_D6      PC6
#define LCD_D7      PC7
#define LCD_RS      PC3
#define LCD_E       PC2
#define LCD_PORT    PORTC
#define LCD_DDR     DDRC

/* LED pin definitions */
#define PUMPING_LED     PD2
#define DRY_LED         PD3
#define MOIST_LED       PD4
#define LED_PORT        PORTD
#define LED_DDR         DDRD

/* Pump pin definitions */
#define PUMP_PIN        PD5
#define PUMP_PORT       PORTD
#define PUMP_DDR        DDRD

/* Soil moisture sensor pin definitions */
#define MOIST_SENSE_PIN     PA0
#define MOIST_SENSE_PORT    PORTA
#define MOIST_SENSE_DDR     DDRA

/* Soil moisture sensor calibration values */
#define SOIL_WET 450
#define SOIL_DRY 750


#endif/*__MAIN_H__*/