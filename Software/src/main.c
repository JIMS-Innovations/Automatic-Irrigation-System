/**
 * @file main.c
 * @author Jesutofunmi Kupoluyi (jimsufficiency@gmail.com)
 * @brief Skeleton code for Automatic Irrigation System in C.
 * @version 0.1
 * @date 2023-05-24
 *
 * @copyright Copyright (c) 2023
 *
 */

/* Include header files */
#include "main.h"
#include "modules.h"

/* Create indicator instances */
indicator pumping_ind = {
	.pin = PUMPING_LED,
	.port = &LED_PORT,
	.ddr = &LED_DDR
};

indicator dry_ind = {
	.pin = DRY_LED,
	.port = &LED_PORT,
	.ddr = &LED_DDR
};

indicator moist_ind = {
	.pin = MOIST_LED,
	.port = &LED_PORT,
	.ddr = &LED_DDR
};

/* Create an LCD instance */
lcd screen = {
	.d4 = LCD_D4,
	.d5 = LCD_D5,
	.d6 = LCD_D6,
	.d7 = LCD_D7, 
	.rs = LCD_RS,
	.e  = LCD_E, 
	.port = &LCD_PORT,
	.ddr = &LCD_DDR
};

pump water_pump = {
	.pin  = PUMP_PIN,
	.port = &PUMP_PORT,
	.ddr  = &PUMP_DDR
};

adc sensor = {
	.pin  = MOIST_SENSE_PIN,
	.port = &MOIST_SENSE_PORT,
	.ddr  = &MOIST_SENSE_DDR
};

int main()
{
	char sensor_value[16];

	indicator_init(&pumping_ind);
	indicator_init(&dry_ind);
	indicator_init(&moist_ind);

	LCD_Init(&screen);

	pump_init(&water_pump);

	ADC_Init(&sensor);

	_delay_us(100);

	/* LCD intro sequence */
	char *intro[] = {
		"   Automatic   ",
		"  Irrigation   ",
		"    System     "
	};

	for(uint8_t i = 0; i < 2; i++)
	{
		indicator_blink(&pumping_ind, 250);
		indicator_blink(&dry_ind, 250);
		indicator_blink(&moist_ind, 250);
	}

	LCD_Write_String_XY(&screen, 0, 0, intro[0]);
	LCD_Write_String_XY(&screen, 1, 0, "****************");
	_delay_ms(500);
	LCD_Clear(&screen);
	_delay_ms(100);
	LCD_Write_String_XY(&screen, 0, 0, intro[1]);
	LCD_Write_String_XY(&screen, 1, 0, intro[2]);
	_delay_ms(500);
	LCD_Clear(&screen);
	_delay_ms(100);


	char label[] = "Pump State: OFF";

	LCD_Write_String(&screen, label);
	float moist_cont = 0.0f;

	while(1)
	{
		ADC_Read(&sensor);

		moist_cont = (1 + ((sensor.data - SOIL_WET) / (float)(SOIL_WET - SOIL_DRY))) * 100;
		
		if (sensor.data < SOIL_WET)
		{
			indicator_on(&moist_ind);
			indicator_off(&pumping_ind);
			indicator_off(&dry_ind);
			LCD_Write_String_XY(&screen, 0, 0, "Pump State: OFF");
			LCD_Write_String_XY(&screen, 1, 0, " SOIl TOO WET! ");
			pump_off(&water_pump);
		}
		else if (sensor.data > SOIL_DRY)
		{
			indicator_off(&moist_ind);
			indicator_on(&pumping_ind);
			indicator_on(&dry_ind);
			LCD_Write_String_XY(&screen, 0, 0, "Pump State: ON ");
			LCD_Write_String_XY(&screen, 1, 0, " SOIl TOO DRY! ");
			pump_on(&water_pump);
		}
		else
		{
			snprintf(sensor_value, sizeof(sensor_value), "Moist.%% = %.1f%%", moist_cont);
			LCD_Write_String_XY(&screen, 1, 0, sensor_value);
			indicator_blink(&moist_ind, 250);
		}

	}
}

