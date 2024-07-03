/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "spi.h"
#include <stdio.h>
#include "stm32util-debug.h"
#include "stm32util-hcms.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
osThreadId_t secondTaskHandle;
const osThreadAttr_t secondTask_attributes = {
	.name = "secondTask",
	.stack_size = 256 * 4,
	.priority = (osPriority_t) osPriorityNormal,
};
void secondDefaultTask(void *argument);

osThreadId_t hcmsTaskHandle;
const osThreadAttr_t hcmsTask_attributes = {
	.name = "hcmsTask",
	.stack_size = 256 * 4,
	.priority = (osPriority_t) osPriorityNormal,
};
void hcmsDefaultTask(void *argument);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	secondTaskHandle = osThreadNew(secondDefaultTask, NULL, &secondTask_attributes);
	hcmsTaskHandle = osThreadNew(hcmsDefaultTask, NULL, &hcmsTask_attributes);
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
	/* Infinite loop */
	int count = 0;
	for(;;) {
		TRACE("%d: 1: This is test.\r\n", count++);
		osDelay(1);
	}
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void secondDefaultTask(void *argument)
{
	int count = 0;
	for(;;) {
		WARNING("%d: 2: This is test.\r\n", count++);
		osDelay(250);
		//ASSERT(count == 12345, "test");
	}
}

void hcmsDefaultTask(void *argument)
{
	/*
	                NVCI	NUCLEO	CN9
	        DATA	PE6	-	20
	        RS	PE5	-	18
	        CLK	PE2	-	14
	        CE	PE4	-	16
	        BL	PE3	-	22
	        RESET	PC13	PF8	24
	        VDD
	        GND
	 */
	int count = 32;

	stm32util_hcms_init();

	static char buffer[256];
	for (int i = 0; i < 256; ++i) {
		buffer[i] = i;
	}

	while (1) {
		stm32util_hcms_puts(buffer + count % (256-4));
		printf("3: %lu %d hcms\r\n", osKernelGetTickCount(), count);
		osDelay(250);
		HAL_GPIO_TogglePin(MX_GPIO(LD1));
		++count;
	}
}

/* USER CODE END Application */

