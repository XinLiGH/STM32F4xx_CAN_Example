/****************************************************************
 * Copyright (C) 2016, XinLi, all right reserved.
 * File name:    main.c
 * Date:         2016.11.30
 * Description:  CAN Example.
*****************************************************************/

/****************************************************************
 *                        Header include
*****************************************************************/
#include "main.h"
#include "CAN.h"

/****************************************************************
 *                       Global variables
*****************************************************************/
CanTxMsg TxMessage;
CanRxMsg RxMessage;

/****************************************************************
 *                     Function declaration
*****************************************************************/
static void System_Init(void);
static void NVIC_Configuration(void);

/****************************************************************
 *                     Function definition
*****************************************************************/

/****************************************************************
 * Function:    main
 * Description: Program entry.
 * Input:
 * Output:
 * Return:
*****************************************************************/
int main(void)
{
  System_Init();
  
  for(;;)
  {
    TxMessage.StdId = 0x02;
    TxMessage.ExtId = 0x03;
    TxMessage.IDE = CAN_ID_EXT;
    TxMessage.RTR = CAN_RTR_DATA;
    TxMessage.DLC = 8;
    TxMessage.Data[0] += 1;
    TxMessage.Data[1] = 1;
    TxMessage.Data[2] = 2;
    TxMessage.Data[3] = 3;
    TxMessage.Data[4] = 4;
    TxMessage.Data[5] = 5;
    TxMessage.Data[6] = 8;
    TxMessage.Data[7] = 9;
    
    CAN_TxMsg(CAN1, &TxMessage);
  }
}

/****************************************************************
 * Function:    System_Init
 * Description: Initialization System.
 * Input:
 * Output:
 * Return:
*****************************************************************/
static void System_Init(void)
{
  CAN_Configuration(CAN1, BAUD_RATE_1000K, 0x01|0x02, 0x02|0x03, CAN_Mode_LoopBack, CAN_IT_FMP0);
  NVIC_Configuration();
}

/****************************************************************
 * Function:    NVIC_Configuration
 * Description: Interrupt Vector Table Configuration.
 * Input:
 * Output:
 * Return:
*****************************************************************/
static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

  NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
