#include "main.h"
#include "gpio.h"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifdef USE_HYREL_IO

void pinInitAll(void)
{
	pinInit(W_EN);
	pinInit(W_DIR);
	pinInit(W_STEP);
	pinInit(W_HSS1);
	pinInit(W_HSS2);
	pinInit(W_HOME);
	pinInit(W_STALL);

	pinInit(X_EN);
	pinInit(X_DIR);
	pinInit(X_STEP);
	pinInit(X_HSS1);
	pinInit(X_HSS2);
	pinInit(X_HOME);
	pinInit(X_STALL);

	pinInit(Y_EN);
	pinInit(Y_DIR);
	pinInit(Y_STEP);
	pinInit(Y_HSS1);
	pinInit(Y_HSS2);
	pinInit(Y_STALL);
	pinInit(Y_HOME);

	pinInit(Z_STEP);
	pinInit(Z_DIR);
	pinInit(Z_EN);
	pinInit(Z_HSS1);
	pinInit(Z_HSS2);
	pinInit(Z_STALL);
	pinInit(Z_HOME);
//	pinInit(Z_HOME1);
//	pinInit(Z_HOME2);
//	pinInit(Z_HOME3);
//	pinInit(Z_HOME4);
//	pinInit(Z_HOME5);

	HEARTBEAT_PIN = HEARTBEAT;
	pinInit(HEARTBEAT_PIN);
	pinInit(CAN_TX_LED);
//	pinInit(DRAWBAR);
//	pinInit(HIGHLOWSPEED);
//	pinInit(SPINDLECOOLANT);
//	pinInit(RELAY7);
//	pinInit(RELAY8);

	pinInit(CAN1_RX);
	pinInit(CAN1_TX);
	pinInit(CAN2_RX);
	pinInit(CAN2_TX);

	pinInit(UART3_RX);
	pinInit(UART3_TX);

	pinInit(UART4_RX);
	pinInit(UART4_TX);

	pinInit(UART6_RX);
	pinInit(UART6_TX);

	pinInit(W_RTD1);
	pinInit(W_RTD2);

//	pinInit(ERROR);

//	pinInit(J13_P8); // TEMP RTD CALIB PINS
//	pinInit(J13_P7); // TEMP RTD CALIB PINS
//	pinInit(J13_P6); // TEMP RTD CALIB PINS

	pinInit(OTG_FS_DM);
	pinInit(OTG_FS_DP);

}
#endif //USE_HYREL_IO

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifdef USE_HYDRA_IO
extern boolean isSpecialBuildMachine(void);
void pinInitAll(void)
{
	if (isSpecialBuildMachine())
	{
		HEARTBEAT_PIN = (OUTPUT_PP_2MHZ | PIN_PORT_A | PIN_NUM_01);
		pinInit(HEARTBEAT_PIN);
		pinInit(OTG_FS_DM);
		pinInit(OTG_FS_DP);
		pinInit(PIN_AF_CAN1 | PIN_PORT_D | PIN_NUM_00 | PIN_PUPPD_PULLUP);
		pinInit(PIN_AF_CAN1 | PIN_PORT_D | PIN_NUM_01);
		pinInit(PIN_AF_CAN2 | PIN_PORT_B | PIN_NUM_12 | PIN_PUPPD_PULLUP);
		pinInit(PIN_AF_CAN2 | PIN_PORT_B | PIN_NUM_13);
	}
	else
	{
		pinInit(GB_DEBUG_PIN1);
		pinInit(GB_DEBUG_PIN2);
		pinInit(GB_DEBUG_PIN3);
		pinInit(GB_DEBUG_PIN4);
		pinInit(GB_DEBUG_PIN5);
		pinInit(GB_DEBUG_PIN6);
		pinInit(GB_DEBUG_PIN7);
		pinInit(GB_DEBUG_PIN8);
		pinInit(GB_DEBUG_PIN9);

#if defined(USE_AB_ENCODER)
		pinInit(CO2_LASER_PWM);
		pinInit(PANEL_ENC_A);
		pinInit(PANEL_ENC_B);
		pinInit(PANEL_ENC_SEL);;
#else   // original def (!USE_AB_ENCODER)
		pinInit(AIN3);
		pinInit(J19_10);   // undefined
		pinInit(CO2_LASER_PWM);
		pinInit(DAC1_OUT);
#endif  // !USE_AB_ENCODER

#if defined(USE_6_TO_ONE_SELECT)
		pinInit(PANEL_SEL_0);
		pinInit(PANEL_SEL_2);
		pinInit(PANEL_SEL_1);
		pinInit(PANEL_SEL_3);
		pinInit(PANEL_SEL_4);
		pinInit(PANEL_SEL_5);
#else   // original def (!USE_6_TO_ONE_SELECT)
		pinInit(AIN5);
		pinInit(AIN6);
		pinInit(J17_13);   // undefined
		pinInit(J17_14);   // undefined
		pinInit(J17_15);   // undefined
		pinInit(J17_16);   // undefined
#endif  // !USE_6_TO_ONE_SELECT

#ifdef ADD_ON_SPI_DISPLAY
		pinInit(PIN_LCD_D_CB);
		pinInit(PIN_LCD_MISO);
		pinInit(PIN_LCD_MOSI);
		pinInit(PIN_LCD_CS);
		pinInit(PIN_LCD_SCK);
		pinInit(PIN_LCD_BKL);
#else // original defs (!ADD_ON_SPI_DISPLAY)
		pinInit(SPI2_CS);
		pinInit(SPI2_MISO);
		pinInit(SPI2_MOSI);
		pinInit(SPI2_NSS);
		pinInit(SPI2_SCK);
		pinInit(SPI2_SPARE);
#endif // !ADD_ON_SPI_DISPLAY

		pinInit(A_DIR);
		pinInit(A_FAULT);
		pinInit(A_HOME);
		pinInit(A_L1);
		pinInit(A_L2);
		pinInit(A_STEP);

		pinInit(AIN6_RTD);
		pinInit(AIN7);
		pinInit(AIN8);
		pinInit(B_DIR);
		pinInit(B_FAULT);
		pinInit(B_HOME);
		pinInit(B_L1);
		pinInit(B_L2);
		pinInit(B_STEP);
		pinInit(BOOT1);   // undefined
		pinInit(C_DIR);
		pinInit(C_FAULT);
		pinInit(C_HOME);
		pinInit(C_L1);
		pinInit(C_L2);
		pinInit(C_STEP);
		pinInit(CAN1_RX);
		pinInit(CAN1_TX);
		pinInit(CAN2_RX);
		pinInit(CAN2_TX);

		pinInit(DAC2_OUT);
		pinInit(DRAIN1);
		pinInit(DRAIN2);
		pinInit(DRAIN3);
		pinInit(DRAIN4);
		pinInit(CAN_TX_LED);
		HEARTBEAT_PIN = HEARTBEAT;
		pinInit(HEARTBEAT_PIN);
		pinInit(HSS_AUX_PWR1);
		pinInit(HSS_AUX_PWR2);
		pinInit(HSS_AUX_PWR4);
		pinInit(HSS_AUX_PWR5);
		pinInit(HSS_AUX_PWR6);
		pinInit(HSS_AUX_PWR7);
		pinInit(HSS_AUX_PWR8);
		pinInit(HSS_AUX_PWR9);

		pinInit(J18_13);   // undefined
		pinInit(J18_14);   // undefined
		pinInit(J18_15);   // undefined

		pinInit(J19_9);   // undefined
		pinInit(JTCK_SWCLK);
		pinInit(JTDI);
		pinInit(JTDO_SWO);
		pinInit(JTMS_SWDIO);
		pinInit(JTRST);
		pinInit(MOTOR_EN);
		pinInit(NC_SPARE);   // undefined
		pinInit(OSC_IN);   // undefined
		pinInit(OSC_OUT);   // undefined
		pinInit(OSC32_IN);
		pinInit(OSC32_OUT);
		pinInit(OTG_FS_DM);
		pinInit(OTG_FS_DP);
		pinInit(OTG_FS_ID);
		pinInit(RX6);
		pinInit(SDRAM_A0);
		pinInit(SDRAM_A1);
		pinInit(SDRAM_A10);
		pinInit(SDRAM_A11);
		pinInit(SDRAM_A2);
		pinInit(SDRAM_A3);
		pinInit(SDRAM_A4);
		pinInit(SDRAM_A5);
		pinInit(SDRAM_A6);
		pinInit(SDRAM_A7);
		pinInit(SDRAM_A8);
		pinInit(SDRAM_A9);
		pinInit(SDRAM_BA0);
		pinInit(SDRAM_BA1);
		pinInit(SDRAM_CLK);
		pinInit(SDRAM_D0);
		pinInit(SDRAM_D1);
		pinInit(SDRAM_D10);
		pinInit(SDRAM_D11);
		pinInit(SDRAM_D12);
		pinInit(SDRAM_D13);
		pinInit(SDRAM_D14);
		pinInit(SDRAM_D15);
		pinInit(SDRAM_D2);
		pinInit(SDRAM_D3);
		pinInit(SDRAM_D4);
		pinInit(SDRAM_D5);
		pinInit(SDRAM_D6);
		pinInit(SDRAM_D7);
		pinInit(SDRAM_D8);
		pinInit(SDRAM_D9);
		pinInit(SDRAM_NBL0);
		pinInit(SDRAM_NBL1);
		pinInit(SDRAM_SDCKE1);
		pinInit(SDRAM_SDNCAS);
		pinInit(SDRAM_SDNE1);
		pinInit(SDRAM_SDNRAS);
		pinInit(SDRAM_SDNWE);
		pinInit(SPI3_CS);
		pinInit(SPI3_MISO);
		pinInit(SPI3_MOSI);
		pinInit(SPI3_NSS_NOT);
		pinInit(SPI3_SCK);
		pinInit(SPI3_SPARE);
		pinInit(START);
		pinInit(TX6);
		pinInit(X_DIR);
		pinInit(X_FAULT);
		pinInit(X_HOME);
		pinInit(X_L1);
		pinInit(X_L2);
		pinInit(X_STEP);
		pinInit(Y_DIR);
		pinInit(Y_FAULT);
		pinInit(Y_HOME);
		pinInit(Y_L1);
		pinInit(Y_L2);
		pinInit(Y_STEP);
		pinInit(Z_DIR);
		pinInit(Z_FAULT);
		pinInit(Z_HOME);
		pinInit(Z_L1);
		pinInit(Z_L2);
		pinInit(Z_STEP);
	}
}
#endif  // USE_HYDRA_IO

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifdef MEGASONIC_HYDRA
void pinInitAll(void)
{
	HEARTBEAT_PIN = HEARTBEAT;
	pinInit(HEARTBEAT_PIN);
	pinInit(CAN_RX_LED);
	pinInit(CAN_TX_LED);

	pinInit(CAN1_RX);
	pinInit(CAN1_TX);

	pinInit(CAN2_RX);
	pinInit(CAN2_TX);

	pinInit(OTG_FS_DM);
	pinInit(OTG_FS_DP);
}
#endif //MEGASONIC_HYDRA

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifdef MEGASONIC_HYREL
void pinInitAll(void)
{
	HEARTBEAT_PIN = HEARTBEAT;
	pinInit(HEARTBEAT_PIN);
	pinInit(CAN_RX_LED);
	pinInit(CAN_TX_LED);

	pinInit(CAN1_RX);
	pinInit(CAN1_TX);

//  pinInit(OTG_FS_DM);
//  pinInit(OTG_FS_DP);
}
#endif //MEGASONIC_HYREL
