/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "misc_4xx.h"
#include "mailbox.h"
#include "HardwareInit.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
extern void initKey(boolean, char *, char *);

#ifdef HYDRA_DIAGS
#include "diags.h"
#endif

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern systemInfoStruct *_sysInfoPtr;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
#ifdef GB_DEBUGGING
	setupDBGMCU();    // set controls for debugger to keep peripherals from continuing to operate when paused.
#endif //GB_DEBUGGING
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  masterCommPort = BOOTUP;
  ExecutionPtr = &cmdQue[0];
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, NVIC_VECTOR_OFFSET); // Set interrupt jump table location
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);              //4 bits for preemp priority 0 bit for sub priority
  InitGPIO();                 //configure direction and purpose of the I/O pin
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  //MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */
#ifdef GB_HIDDEN_WARNINGS
	int doWeWantToReinstateClockInitCheck;
	//  if (ClocksFailedToInitialize)
	//  {
	//      setupIWDG(25.0f);  // enable SLOW IWDG timer (needs interrupts for LSI calib)
	//      pinSet(ERROR_LED);
	//  }
	//  else
	//  {
	//      setupIWDG(5.0f);  // enable IWDG timer (needs interrupts for LSI calib)
	//      pinClear(ERROR_LED);
	//  }
#endif //GB_HIDDEN_WARNINGS

	wiggleDebugIO(1);

	initAllHss();
	InitGlobals();              //initialize/clear CAN and MCODE globals
	DeInitLaser();
	InitializeMotorParameters();
	initMailbox();
	initKey(FALSE, _sysInfoPtr->lastKeyUsed, &GCodeArgComment[1]);     // must be after initMailbox; 	// tell the key checker where to put and find data
	InitTimer7();
	InitTimer3ForDelays();  // for delayMsec; delayuSec; delaySec   delayMs(

	//if (ClocksFailedToInitialize)
	{
		_heartbeatRateControl = HEARTBEAT_MODE_ABORT;
	}
	__disable_irq();            //prevent any interrupts until everything is initialized

	wiggleDebugIO(0);

	InitAllUARTS(SYSTEM_BAUD_RATE);

	CAN_Config(CAN1);
#ifdef USE_CAN2
	CAN_Config(CAN2);
#endif
	InitializeFixtureOffsets();

	ResetProcess(0);
	processSoapstringCommands=TRUE; // get ready to self initialize

	RCC_ClearFlag(); // clear flags indicating boot reason

	executeAnySpecialDebugStartCode();	//this call must remain here


	_heartbeatRateControl = HEARTBEAT_MODE_NORMAL;
	SysTick_Config(SystemCoreClock / SYSTICKS_PER_SECOND);//slice timer has lowest interrupt priority
	__enable_irq();  // now everything is ready, so let interrupts occur

#ifdef ADD_ON_SPI_DISPLAY
	display_Init();                     // do after SysTick started
#endif //ADD_ON_SPI_DISPLAY

#ifdef USE_AB_ENCODER
	timerInitEncoderAB(FALSE);  		// setup for GUI use
#endif //USE_AB_ENCODER
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

#ifdef ADD_ON_SPI_DISPLAY
#if 0 //NUKE
		if (GUI_GetCurrPage() != GUI_GetNextPage())
		{   // request to change page
			GUI_DrawPage(GUI_GetNextPage());
		}
		else if (_gs._display.updateIntervalCountMs >= _gs._display.updateIntervalMs)
		{
			_gs._display.updateIntervalCountMs = 0;
			GUI_RefreshPage(GUI_GetCurrPage());
		}
#else //!0
		if (_gs._displayIsAlive)
		{
			//			if (_gs._initializationComplete)
			//			{       // do want to overwrite the bootup display info
			GUI_ProcessCommandsFromQueue(10);       // process up to 10 gui cmds from the canbus

			if (GUI_GetCurrPage() != GUI_GetNextPage())
			{       // keep page change in the foreground
				_gs._displayForceRedraw = FALSE;
				GUI_DrawPage(GUI_GetNextPage());

			}
			else if (_gs._displayForceRedraw)
			{
				_gs._displayForceRedraw = FALSE;
				GUI_RedrawCurrentPage();
			}
			else if (GUI_RefreshIntervalReached())
			{
				GUI_DrawJustDynamicValues();
			}
			else
			{
				GUI_DrawFakeLeds(FALSE);
			}
			//			}
			//			else
			//			{
			//				displayBootSequence();
			//			}
		}
#endif //!0
#endif //ADD_ON_SPI_DISPLAY
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, 0x00000000U) != HAL_OK) //FLASH_LATENCY_0
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
