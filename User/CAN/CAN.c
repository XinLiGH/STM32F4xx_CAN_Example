/****************************************************************
 * Copyright (C) 2016, XinLi, all right reserved.
 * File name:    CAN.c
 * Date:         2016.11.30
 * Description:  CAN Driver
*****************************************************************/

/****************************************************************
 *                        Header include
*****************************************************************/
#include "CAN.h"

/****************************************************************
 *                       Global variables
*****************************************************************/
static uint8_t gpioFlag = 0x00; /* Used to record the GPIO initialization flag. */
static uint8_t canFlag  = 0x00; /* Used to record the CAN initialization flag. */

/****************************************************************
 *                     Function declaration
*****************************************************************/


/****************************************************************
 *                     Function definition
*****************************************************************/

/****************************************************************
 * Function:    CAN_Configuration
 * Description: CAN Configuration.
 * Input:       CANx
 *              BaudRate
 *              StdId
 *              ExtId
 *              CAN_Mode
 *              CAN_IT
 * Output:
 * Return:
*****************************************************************/
void CAN_Configuration(CAN_TypeDef* CANx, uint16_t BaudRate, uint32_t StdId, uint32_t ExtId, uint8_t CAN_Mode, uint32_t CAN_IT)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  CAN_InitTypeDef CAN_InitStructure;
  CAN_FilterInitTypeDef CAN_FilterInitStructure;
  
  if(CANx == CAN1)
  {
    if((canFlag & 0x01) != 0x01)
    {
      canFlag |= 0x01;
      
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);     /* Enable CAN1 clock */
    }
    
    if((gpioFlag & 0x01) != 0x01)
    {
      gpioFlag |= 0x01;
      
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CAN1_Tx, ENABLE);  /* Enable CAN1_Tx GPIO clock */
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CAN1_Rx, ENABLE);  /* Enable CAN1_Rx GPIO clock */

      GPIO_PinAFConfig(GPIO_CAN1_Tx, GPIO_PinSource_CAN1_Tx, GPIO_AF_CAN1); /* Connect GPIOxn to CAN1_Tx */
      GPIO_PinAFConfig(GPIO_CAN1_Rx, GPIO_PinSource_CAN1_Rx, GPIO_AF_CAN1); /* Connect GPIOxn to CAN1_Rx */

      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_CAN1_Tx;     /* Specifies the GPIO pins to be configured. */
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        /* Specifies the operating mode for the selected pins. */
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  /* Specifies the speed for the selected pins. */
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      /* Specifies the operating output type for the selected pins. */
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        /* Specifies the operating Pull-up/Pull down for the selected pins. */
      GPIO_Init(GPIO_CAN1_Tx, &GPIO_InitStructure);       /* Initializes the GPIOx peripheral according to the specified parameters in the GPIO_InitStruct. */
      
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_CAN1_Rx;     /* Specifies the GPIO pins to be configured. */
      GPIO_Init(GPIO_CAN1_Rx, &GPIO_InitStructure);       /* Initializes the GPIOx peripheral according to the specified parameters in the GPIO_InitStruct. */
    }
  }
  else if(CANx == CAN2)
  {
    if((canFlag & 0x02) != 0x02)
    {
      canFlag |= 0x02;
      
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);     /* Enable CAN1 clock */
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);     /* Enable CAN2 clock */
    }
    
    if((gpioFlag & 0x02) != 0x02)
    {
      gpioFlag |= 0x02;
      
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CAN2_Tx, ENABLE);  /* Enable CAN2_Tx GPIO clock */
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CAN2_Rx, ENABLE);  /* Enable CAN2_Rx GPIO clock */

      GPIO_PinAFConfig(GPIO_CAN2_Tx, GPIO_PinSource_CAN2_Tx, GPIO_AF_CAN2); /* Connect GPIOxn to CAN2_Tx */
      GPIO_PinAFConfig(GPIO_CAN2_Rx, GPIO_PinSource_CAN2_Rx, GPIO_AF_CAN2); /* Connect GPIOxn to CAN2_Rx */

      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_CAN2_Tx;     /* Specifies the GPIO pins to be configured. */
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        /* Specifies the operating mode for the selected pins. */
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  /* Specifies the speed for the selected pins. */
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      /* Specifies the operating output type for the selected pins. */
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        /* Specifies the operating Pull-up/Pull down for the selected pins. */
      GPIO_Init(GPIO_CAN2_Tx, &GPIO_InitStructure);       /* Initializes the GPIOx peripheral according to the specified parameters in the GPIO_InitStruct. */
      
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_CAN2_Rx;     /* Specifies the GPIO pins to be configured. */
      GPIO_Init(GPIO_CAN2_Rx, &GPIO_InitStructure);       /* Initializes the GPIOx peripheral according to the specified parameters in the GPIO_InitStruct. */
    }
  }
#if defined(STM32F413_423xx)
  else if(CANx == CAN3)
  {
    if((canFlag & 0x04) != 0x04)
    {
      canFlag |= 0x04;
      
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN3, ENABLE);     /* Enable CAN3 clock */
    }
    
    if((gpioFlag & 0x04) != 0x04)
    {
      gpioFlag |= 0x04;
      
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CAN3_Tx, ENABLE);  /* Enable CAN3_Tx GPIO clock */
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CAN3_Rx, ENABLE);  /* Enable CAN3_Rx GPIO clock */

      GPIO_PinAFConfig(GPIO_CAN3_Tx, GPIO_PinSource_CAN3_Tx, GPIO_AF11_CAN3); /* Connect GPIOxn to CAN3_Tx */
      GPIO_PinAFConfig(GPIO_CAN3_Rx, GPIO_PinSource_CAN3_Rx, GPIO_AF11_CAN3); /* Connect GPIOxn to CAN3_Rx */

      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_CAN3_Tx;     /* Specifies the GPIO pins to be configured. */
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        /* Specifies the operating mode for the selected pins. */
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  /* Specifies the speed for the selected pins. */
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      /* Specifies the operating output type for the selected pins. */
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        /* Specifies the operating Pull-up/Pull down for the selected pins. */
      GPIO_Init(GPIO_CAN3_Tx, &GPIO_InitStructure);       /* Initializes the GPIOx peripheral according to the specified parameters in the GPIO_InitStruct. */
      
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_CAN3_Rx;     /* Specifies the GPIO pins to be configured. */
      GPIO_Init(GPIO_CAN3_Rx, &GPIO_InitStructure);       /* Initializes the GPIOx peripheral according to the specified parameters in the GPIO_InitStruct. */
    }
  }
#endif /* STM32F413_423xx */
  
  CAN_InitStructure.CAN_Prescaler = BaudRate;     /* Specifies the length of a time quantum. It ranges from 1 to 1024. */
  CAN_InitStructure.CAN_Mode = CAN_Mode;          /* Specifies the CAN operating mode. */
  CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;        /* Specifies the maximum number of time quanta the CAN hardware is allowed to lengthen or shorten a bit to perform resynchronization. */

#if defined(STM32F40_41xxx)
  CAN_InitStructure.CAN_BS1 = CAN_BS1_16tq;       /* Specifies the number of time quanta in Bit Segment 1. */
  CAN_InitStructure.CAN_BS2 = CAN_BS2_4tq;        /* Specifies the number of time quanta in Bit Segment 2. */
#endif /* STM32F40_41xxx */
  
#if defined(STM32F427_437xx) || defined(STM32F429_439xx) || defined(STM32F446xx) || defined(STM32F469_479xx)
  CAN_InitStructure.CAN_BS1 = CAN_BS1_11tq;       /* Specifies the number of time quanta in Bit Segment 1. */
  CAN_InitStructure.CAN_BS2 = CAN_BS2_3tq;        /* Specifies the number of time quanta in Bit Segment 2. */
#endif /* STM32F427_437x || STM32F429_439xx || STM32F446xx || STM32F469_479xx */
  
#if defined(STM32F413_423xx)
  CAN_InitStructure.CAN_BS1 = CAN_BS1_3tq;        /* Specifies the number of time quanta in Bit Segment 1. */
  CAN_InitStructure.CAN_BS2 = CAN_BS2_1tq;        /* Specifies the number of time quanta in Bit Segment 2. */
#endif /* STM32F413_423xx */
  
#if defined(STM32F412xG)
  CAN_InitStructure.CAN_BS1 = CAN_BS1_3tq;        /* Specifies the number of time quanta in Bit Segment 1. */
  CAN_InitStructure.CAN_BS2 = CAN_BS2_1tq;        /* Specifies the number of time quanta in Bit Segment 2. */
#endif /* STM32F412xG */
  
  CAN_InitStructure.CAN_TTCM = DISABLE;           /* Enable or disable the time triggered communication mode. */
  CAN_InitStructure.CAN_ABOM = DISABLE;           /* Enable or disable the automatic bus-off management. */
  CAN_InitStructure.CAN_AWUM = DISABLE;           /* Enable or disable the automatic wake-up mode. */
  CAN_InitStructure.CAN_NART = DISABLE;           /* Enable or disable the non-automatic retransmission mode. */
  CAN_InitStructure.CAN_RFLM = DISABLE;           /* Enable or disable the Receive FIFO Locked mode. */
  CAN_InitStructure.CAN_TXFP = DISABLE;           /* Enable or disable the transmit FIFO priority. */
  
  CAN_DeInit(CANx);                   /* Deinitializes the CAN peripheral registers to their default reset values. */
  CAN_Init(CANx, &CAN_InitStructure); /* Initializes the CAN peripheral according to the specified parameters in the CAN_InitStruct. */
  
  CAN_FilterInitStructure.CAN_FilterIdHigh = (uint16_t)((((StdId<<18)|ExtId)<<3)>>16);                  /* Specifies the filter identification number. */
  CAN_FilterInitStructure.CAN_FilterIdLow = (uint16_t)(((StdId<<18)|ExtId)<<3);                         /* Specifies the filter identification number. */
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = (~((uint16_t)((((StdId<<18)|ExtId)<<3)>>16)))&0xFFFF;  /* Specifies the filter mask number or identification number,according to the mode. */
  CAN_FilterInitStructure.CAN_FilterMaskIdLow = (~((uint16_t)(((StdId<<18)|ExtId)<<3)))&0xFFF8;         /* Specifies the filter mask number or identification number,according to the mode. */
  
  if(CANx == CAN1)
  {
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN1_FILTER_FIFO;  /* Specifies the FIFO (0 or 1) which will be assigned to the filter. */
    CAN_FilterInitStructure.CAN_FilterNumber = 0;                         /* Specifies the filter which will be initialized. */
  }
  else if(CANx == CAN2)
  {
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN2_FILTER_FIFO;  /* Specifies the FIFO (0 or 1) which will be assigned to the filter. */
    CAN_FilterInitStructure.CAN_FilterNumber = 14;                        /* Specifies the filter which will be initialized. */
  }
#if defined(STM32F413_423xx)
  else if(CANx == CAN3)
  {
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN3_FILTER_FIFO;  /* Specifies the FIFO (0 or 1) which will be assigned to the filter. */
    CAN_FilterInitStructure.CAN_FilterNumber = 0;                         /* Specifies the filter which will be initialized. */
  }
#endif /* STM32F413_423xx */
  
  CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;   /* Specifies the filter mode to be initialized. */
  CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;  /* Specifies the filter scale. */
  CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;            /* Enable or disable the filter. */
  
#if defined(STM32F413_423xx)
  CAN_FilterInit(CANx, &CAN_FilterInitStructure); /* Configures the CAN reception filter according to the specified parameters in the CAN_FilterInitStruct. */
#else
  CAN_FilterInit(&CAN_FilterInitStructure);       /* Configures the CAN reception filter according to the specified parameters in the CAN_FilterInitStruct. */
#endif /* STM32F413_423xx */
  
  CAN_ITConfig(CANx, CAN_IT_TME|CAN_IT_FMP0|CAN_IT_FF0|CAN_IT_FOV0|CAN_IT_FMP1|CAN_IT_FF1|CAN_IT_FOV1|
                     CAN_IT_WKU|CAN_IT_SLK|CAN_IT_EWG|CAN_IT_EPV|CAN_IT_BOF|CAN_IT_LEC|CAN_IT_ERR, DISABLE);  /* Disables the specified CAN interrupts. */
  CAN_ITConfig(CANx, CAN_IT, ENABLE);                                                                         /* Enables the specified CAN interrupts. */
}

/****************************************************************
 * Function:    CAN_Unconfigure
 * Description: CAN Unconfigure.
 * Input:       CANx
 * Output:
 * Return:
*****************************************************************/
void CAN_Unconfigure(CAN_TypeDef* CANx)
{
  if(CANx == CAN1)
  {
    if((canFlag & 0x01) == 0x01)
    {
      canFlag &= 0xFE;
      
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, DISABLE);     /* Disable CAN1 clock */
      
      CAN_DeInit(CAN1); /* Deinitializes the CAN1 peripheral registers to their default reset values. */
    }
  }
  else if(CANx == CAN2)
  {
    if((canFlag & 0x02) == 0x02)
    {
      canFlag &= 0xFD;
      
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, DISABLE);     /* Disable CAN2 clock */
      
      if((canFlag & 0x01) != 0x01)
      {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, DISABLE);   /* Disable CAN1 clock */
      }
      
      CAN_DeInit(CAN2); /* Deinitializes the CAN2 peripheral registers to their default reset values. */
    }
  }
#if defined(STM32F413_423xx)
  else if(CANx == CAN3)
  {
    if((canFlag & 0x04) == 0x04)
    {
      canFlag &= 0xFB;
      
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN3, DISABLE);     /* Disable CAN3 clock */
      
      CAN_DeInit(CAN3); /* Deinitializes the CAN3 peripheral registers to their default reset values. */
    }
  }
#endif /* STM32F413_423xx */
}

/****************************************************************
 * Function:    CAN_TxMsg
 * Description: CAN TxMsg.
 * Input:       CAN_x
 *              TxMessage
 * Output:
 * Return:      0:Failure
 *              1:Success
*****************************************************************/
uint8_t CAN_TxMsg(CAN_TypeDef* CANx, CanTxMsg* TxMessage)
{
  uint8_t status = 0;
  
  if(CANx == CAN1)
  {
    if((canFlag & 0x01) == 0x01)
    {
      status = 1;
      
      while(CAN_Transmit(CAN1, TxMessage) == CAN_TxStatus_NoMailBox);
    }
  }
  else if(CANx == CAN2)
  {
    if((canFlag & 0x02) == 0x02)
    {
      status = 1;
      
      while(CAN_Transmit(CAN2, TxMessage) == CAN_TxStatus_NoMailBox);
    }
  }
#if defined(STM32F413_423xx)
  else if(CANx == CAN3)
  {
    if((canFlag & 0x04) == 0x04)
    {
      status = 1;
      
      while(CAN_Transmit(CAN3, TxMessage) == CAN_TxStatus_NoMailBox);
    }
  }
#endif /* STM32F413_423xx */
  
  return status;
}

/****************************************************************
 * Function:    CAN_RxMsg
 * Description: CAN RxMsg.
 * Input:       CAN_x
 *              RxMessage
 * Output:
 * Return:      0:Failure
 *              1:Success
*****************************************************************/
uint8_t CAN_RxMsg(CAN_TypeDef* CANx, CanRxMsg* RxMessage)
{
  uint8_t status = 0;
  
  if(CANx == CAN1)
  {
    if((canFlag & 0x01) == 0x01)
    {
      status = 1;
      
      CAN_Receive(CAN1, CAN1_FIFO, RxMessage);
    }
  }
  else if(CANx == CAN2)
  {
    if((canFlag & 0x02) == 0x02)
    {
      status = 1;
      
      CAN_Receive(CAN2, CAN2_FIFO, RxMessage);
    }
  }
#if defined(STM32F413_423xx)
  else if(CANx == CAN3)
  {
    if((canFlag & 0x04) == 0x04)
    {
      status = 1;
      
      CAN_Receive(CAN3, CAN3_FIFO, RxMessage);
    }
  }
#endif /* STM32F413_423xx */
  
  return status;
}
