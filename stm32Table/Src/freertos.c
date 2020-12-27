/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stdio.h"
#include "usart.h"
#include "string.h"
#include "blue.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

//人体
int IsPeople = 0;
//led
int led = 1;
//beep
int beep = 0;
//blue
char txbuf[100];
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
osThreadId defaultTaskHandle;
osThreadId PeopleTaskHandle;
osThreadId BlueTaskHandle;
osThreadId LEDTaskHandle;
osThreadId BEEPTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void PeopleTaskFunc(void const * argument);
void BlueTaskFunc(void const * argument);
void LEDTask04(void const * argument);
void BEEPTask05(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
  
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}                   
/* USER CODE END GET_IDLE_TASK_MEMORY */

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
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityLow, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of PeopleTask */
  osThreadDef(PeopleTask, PeopleTaskFunc, osPriorityAboveNormal, 0, 128);
  PeopleTaskHandle = osThreadCreate(osThread(PeopleTask), NULL);

  /* definition and creation of BlueTask */
  osThreadDef(BlueTask, BlueTaskFunc, osPriorityNormal, 0, 128);
  BlueTaskHandle = osThreadCreate(osThread(BlueTask), NULL);

  /* definition and creation of LEDTask */
  osThreadDef(LEDTask, LEDTask04, osPriorityNormal, 0, 128);
  LEDTaskHandle = osThreadCreate(osThread(LEDTask), NULL);

  /* definition and creation of BEEPTask */
  osThreadDef(BEEPTask, BEEPTask05, osPriorityNormal, 0, 128);
  BEEPTaskHandle = osThreadCreate(osThread(BEEPTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
		printf("默认任务执行中\r\n");
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_PeopleTaskFunc */
/**
* @brief Function implementing the PeopleTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_PeopleTaskFunc */
void PeopleTaskFunc(void const * argument)
{
  /* USER CODE BEGIN PeopleTaskFunc */
  /* Infinite loop */
  for(;;)
  {
		printf("人体任务执行中\r\n");
		if(HAL_GPIO_ReadPin(People_GPIO_Port,People_Pin)==1)
		{
			IsPeople = 1;
		}
		else
		{
			IsPeople = 0;
		}
		printf("people:=%d\r\n",IsPeople);
    osDelay(1000);
  }
  /* USER CODE END PeopleTaskFunc */
}

/* USER CODE BEGIN Header_BlueTaskFunc */
/**
* @brief Function implementing the BlueTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_BlueTaskFunc */
void BlueTaskFunc(void const * argument)
{
  /* USER CODE BEGIN BlueTaskFunc */
  /* Infinite loop */
  for(;;)
  {
		printf("蓝牙任务执行中led=%d,beep=%d\r\n",led,beep);
		sprintf(txbuf,"people=%d,led=%d,beep=%d\r\n",IsPeople,led,beep);
		blue_send(txbuf);
    osDelay(1000);
  }
  /* USER CODE END BlueTaskFunc */
}

/* USER CODE BEGIN Header_LEDTask04 */
/**
* @brief Function implementing the LEDTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LEDTask04 */
void LEDTask04(void const * argument)
{
  /* USER CODE BEGIN LEDTask04 */
  /* Infinite loop */
  for(;;)
  {
		printf("LED任务执行中\r\n");
		if(led) led = 0;
		else led = 1;
		HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin);
		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
		HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
    osDelay(1000);
  }
  /* USER CODE END LEDTask04 */
}

/* USER CODE BEGIN Header_BEEPTask05 */
/**
* @brief Function implementing the BEEPTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_BEEPTask05 */
void BEEPTask05(void const * argument)
{
  /* USER CODE BEGIN BEEPTask05 */
  /* Infinite loop */
  for(;;)
  {
		if(beep) beep=0;
		else beep=1;
		//HAL_GPIO_TogglePin(BEEP_GPIO_Port,BEEP_Pin);
    osDelay(1000);
  }
  /* USER CODE END BEEPTask05 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
