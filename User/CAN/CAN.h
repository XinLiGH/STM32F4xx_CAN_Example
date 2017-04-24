/****************************************************************
 * Copyright (C) 2016, XinLi, all right reserved.
 * File name:    CAN.h
 * Date:         2016.11.30
 * Description:  CAN Driver
*****************************************************************/

#ifndef __CAN_H
#define __CAN_H

/****************************************************************
 *                        Header include
*****************************************************************/
#include "stm32f4xx.h"

/****************************************************************
 *                       Macro definition
*****************************************************************/
#define CAN1_FILTER_FIFO    CAN_Filter_FIFO0
#define CAN2_FILTER_FIFO    CAN_Filter_FIFO0
#if defined(STM32F413_423xx)
#define CAN3_FILTER_FIFO    CAN_Filter_FIFO1
#endif /* STM32F413_423xx */

#define CAN1_FIFO   CAN_FIFO0
#define CAN2_FIFO   CAN_FIFO0
#if defined(STM32F413_423xx)
#define CAN3_FIFO   CAN_FIFO1
#endif /* STM32F413_423xx */

/********************** CAN1 Configuration **********************/

#define RCC_AHB1Periph_CAN1_Tx    RCC_AHB1Periph_GPIOA
#define RCC_AHB1Periph_CAN1_Rx    RCC_AHB1Periph_GPIOA

#define GPIO_CAN1_Tx              GPIOA
#define GPIO_CAN1_Rx              GPIOA

#define GPIO_Pin_CAN1_Tx          GPIO_Pin_12
#define GPIO_Pin_CAN1_Rx          GPIO_Pin_11

#define GPIO_PinSource_CAN1_Tx    GPIO_PinSource12
#define GPIO_PinSource_CAN1_Rx    GPIO_PinSource11

/****************************************************************/

/********************** CAN2 Configuration **********************/

#define RCC_AHB1Periph_CAN2_Tx    RCC_AHB1Periph_GPIOB
#define RCC_AHB1Periph_CAN2_Rx    RCC_AHB1Periph_GPIOB

#define GPIO_CAN2_Tx              GPIOB
#define GPIO_CAN2_Rx              GPIOB

#define GPIO_Pin_CAN2_Tx          GPIO_Pin_13
#define GPIO_Pin_CAN2_Rx          GPIO_Pin_12

#define GPIO_PinSource_CAN2_Tx    GPIO_PinSource13
#define GPIO_PinSource_CAN2_Rx    GPIO_PinSource12

/****************************************************************/

/********************** CAN3 Configuration **********************/

#if defined(STM32F413_423xx)
#define RCC_AHB1Periph_CAN3_Tx    RCC_AHB1Periph_GPIOB
#define RCC_AHB1Periph_CAN3_Rx    RCC_AHB1Periph_GPIOB

#define GPIO_CAN3_Tx              GPIOB
#define GPIO_CAN3_Rx              GPIOB

#define GPIO_Pin_CAN3_Tx          GPIO_Pin_4
#define GPIO_Pin_CAN3_Rx          GPIO_Pin_3

#define GPIO_PinSource_CAN3_Tx    GPIO_PinSource4
#define GPIO_PinSource_CAN3_Rx    GPIO_PinSource3
#endif /* STM32F413_423xx */

/****************************************************************/

#if defined(STM32F40_41xxx)
#define BAUD_RATE_1000K    ((uint16_t)2)
#define BAUD_RATE_500K     ((uint16_t)4)
#define BAUD_RATE_250K     ((uint16_t)8)
#define BAUD_RATE_125K     ((uint16_t)16)
#define BAUD_RATE_100K     ((uint16_t)20)
#define BAUD_RATE_50K      ((uint16_t)40)
#define BAUD_RATE_20K      ((uint16_t)100)
#define BAUD_RATE_10K      ((uint16_t)200)
#endif /* STM32F40_41xxx */

#if defined(STM32F427_437xx) || defined(STM32F429_439xx) || defined(STM32F446xx) || defined(STM32F469_479xx)
#define BAUD_RATE_1000K    ((uint16_t)3)
#define BAUD_RATE_500K     ((uint16_t)6)
#define BAUD_RATE_250K     ((uint16_t)12)
#define BAUD_RATE_125K     ((uint16_t)24)
#define BAUD_RATE_100K     ((uint16_t)30)
#define BAUD_RATE_50K      ((uint16_t)60)
#define BAUD_RATE_20K      ((uint16_t)150)
#define BAUD_RATE_10K      ((uint16_t)300)
#endif /* STM32F427_437x || STM32F429_439xx || STM32F446xx || STM32F469_479xx */

#if defined(STM32F413_423xx)
#define BAUD_RATE_1000K    ((uint16_t)10)
#define BAUD_RATE_500K     ((uint16_t)20)
#define BAUD_RATE_250K     ((uint16_t)40)
#define BAUD_RATE_125K     ((uint16_t)80)
#define BAUD_RATE_100K     ((uint16_t)100)
#define BAUD_RATE_50K      ((uint16_t)200)
#define BAUD_RATE_20K      ((uint16_t)500)
#define BAUD_RATE_10K      ((uint16_t)1000)
#endif /* STM32F413_423xx */

#if defined(STM32F412xG)
#define BAUD_RATE_1000K    ((uint16_t)5)
#define BAUD_RATE_500K     ((uint16_t)10)
#define BAUD_RATE_250K     ((uint16_t)20)
#define BAUD_RATE_125K     ((uint16_t)40)
#define BAUD_RATE_100K     ((uint16_t)50)
#define BAUD_RATE_50K      ((uint16_t)100)
#define BAUD_RATE_20K      ((uint16_t)250)
#define BAUD_RATE_10K      ((uint16_t)500)
#endif /* STM32F412xG */

/****************************************************************
 *                       Type definition
*****************************************************************/


/****************************************************************
 *                     Structure definition
*****************************************************************/



#ifdef __cplusplus
 extern "C" {
#endif  /* __cplusplus */

/****************************************************************
 *                     Variable declaration
*****************************************************************/


/****************************************************************
 *                     Function declaration
*****************************************************************/
void CAN_Configuration(CAN_TypeDef* CANx, uint16_t BaudRate, uint32_t StdId, uint32_t ExtId, uint8_t CAN_Mode, uint32_t CAN_IT);
void CAN_Unconfigure(CAN_TypeDef* CANx);
uint8_t CAN_TxMsg(CAN_TypeDef* CANx, CanTxMsg* TxMessage);
uint8_t CAN_RxMsg(CAN_TypeDef* CANx, CanRxMsg* RxMessage);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __CAN_H */
