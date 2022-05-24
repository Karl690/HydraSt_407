#ifdef STM32F4XX
/**
  ******************************************************************************
  * @file    stm32f4xx_flash.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    30-September-2011
  * @brief   This file contains all the functions prototypes for the FLASH 
  *          firmware library.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_FLASH_H
#define __STM32F4xx_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F4xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/
/** 
  * @brief FLASH Status  
  */ 
typedef enum
{ 
  FLASH_BUSY = 1,
  HYREL_FLASH_ERROR_PGS,
  HYREL_FLASH_ERROR_PGP,
  HYREL_FLASH_ERROR_PGA,
  HYREL_FLASH_ERROR_WRP,
  HYREL_FLASH_ERROR_PROGRAM,
  HYREL_FLASH_ERROR_OPERATION,
  HYREL_FLASH_COMPLETE
}HYREL_FLASH_Status;

/* Exported constants --------------------------------------------------------*/

/** @defgroup FLASH_Exported_Constants
  * @{
  */  

/** @defgroup Flash_Latency 
  * @{
  */ 
#define HYREL_FLASH_Latency_0                ((uint8_t)0x0000)  /*!< FLASH Zero Latency cycle */
#define HYREL_FLASH_Latency_1                ((uint8_t)0x0001)  /*!< FLASH One Latency cycle */
#define HYREL_FLASH_Latency_2                ((uint8_t)0x0002)  /*!< FLASH Two Latency cycles */
#define HYREL_FLASH_Latency_3                ((uint8_t)0x0003)  /*!< FLASH Three Latency cycles */
#define HYREL_FLASH_Latency_4                ((uint8_t)0x0004)  /*!< FLASH Four Latency cycles */
#define HYREL_FLASH_Latency_5                ((uint8_t)0x0005)  /*!< FLASH Five Latency cycles */
#define HYREL_FLASH_Latency_6                ((uint8_t)0x0006)  /*!< FLASH Six Latency cycles */
#define HYREL_FLASH_Latency_7                ((uint8_t)0x0007)  /*!< FLASH Seven Latency cycles */

#define HYREL_IS_FLASH_LATENCY(LATENCY) (((LATENCY) == FLASH_Latency_0) || \
                                   ((LATENCY) == HYREL_FLASH_Latency_1) || \
                                   ((LATENCY) == HYREL_FLASH_Latency_2) || \
                                   ((LATENCY) == HYREL_FLASH_Latency_3) || \
                                   ((LATENCY) == HYREL_FLASH_Latency_4) || \
                                   ((LATENCY) == HYREL_FLASH_Latency_5) || \
                                   ((LATENCY) == HYREL_FLASH_Latency_6) || \
                                   ((LATENCY) == HYREL_FLASH_Latency_7))
/**
  * @}
  */ 

/** @defgroup FLASH_Voltage_Range 
  * @{
  */ 
#define HYREL_VoltageRange_1        ((uint8_t)0x00)  /*!< Device operating range: 1.8V to 2.1V */
#define HYREL_VoltageRange_2        ((uint8_t)0x01)  /*!<Device operating range: 2.1V to 2.7V */
#define HYREL_VoltageRange_3        ((uint8_t)0x02)  /*!<Device operating range: 2.7V to 3.6V */
#define HYREL_VoltageRange_4        ((uint8_t)0x03)  /*!<Device operating range: 2.7V to 3.6V + External Vpp */

#define HYREL_IS_VOLTAGERANGE(RANGE)(((RANGE) == HYREL_VoltageRange_1) || \
                               ((RANGE) == HYREL_VoltageRange_2) || \
                               ((RANGE) == HYREL_VoltageRange_3) || \
                               ((RANGE) == HYREL_VoltageRange_4))
/**
  * @}
  */ 

/** @defgroup FLASH_Sectors
  * @{
  */ 
#define HYREL_FLASH_Sector_0     ((uint16_t)0x0000) /*!< Sector Number 0 */
#define HYREL_FLASH_Sector_1     ((uint16_t)0x0008) /*!< Sector Number 1 */
#define HYREL_FLASH_Sector_2     ((uint16_t)0x0010) /*!< Sector Number 2 */
#define HYREL_FLASH_Sector_3     ((uint16_t)0x0018) /*!< Sector Number 3 */
#define HYREL_FLASH_Sector_4     ((uint16_t)0x0020) /*!< Sector Number 4 */
#define HYREL_FLASH_Sector_5     ((uint16_t)0x0028) /*!< Sector Number 5 */
#define HYREL_FLASH_Sector_6     ((uint16_t)0x0030) /*!< Sector Number 6 */
#define HYREL_FLASH_Sector_7     ((uint16_t)0x0038) /*!< Sector Number 7 */
#define HYREL_FLASH_Sector_8     ((uint16_t)0x0040) /*!< Sector Number 8 */
#define HYREL_FLASH_Sector_9     ((uint16_t)0x0048) /*!< Sector Number 9 */
#define HYREL_FLASH_Sector_10    ((uint16_t)0x0050) /*!< Sector Number 10 */
#define HYREL_FLASH_Sector_11    ((uint16_t)0x0058) /*!< Sector Number 11 */
//GB XXX added to cover 429
#define HYREL_FLASH_Sector_22    ((uint16_t)0x00B0) /*!< Sector Number 22 */
#define HYREL_FLASH_Sector_23    ((uint16_t)0x00B8) /*!< Sector Number 23 */
#define HYREL_IS_FLASH_SECTOR(SECTOR) (((SECTOR) == FLASH_Sector_0) || ((SECTOR) == HYREL_FLASH_Sector_1) ||\
                                 ((SECTOR) == HYREL_FLASH_Sector_2) || ((SECTOR) == HYREL_FLASH_Sector_3) ||\
                                 ((SECTOR) == HYREL_FLASH_Sector_4) || ((SECTOR) == HYREL_FLASH_Sector_5) ||\
                                 ((SECTOR) == HYREL_FLASH_Sector_6) || ((SECTOR) == HYREL_FLASH_Sector_7) ||\
                                 ((SECTOR) == HYREL_FLASH_Sector_8) || ((SECTOR) == HYREL_FLASH_Sector_9) ||\
                                 ((SECTOR) == HYREL_FLASH_Sector_10) || ((SECTOR) == HYREL_FLASH_Sector_11))
#define HYREL_IS_FLASH_ADDRESS(ADDRESS) ((((ADDRESS) >= 0x08000000) && ((ADDRESS) < 0x080FFFFF)) ||\
                                   (((ADDRESS) >= 0x1FFF7800) && ((ADDRESS) < 0x1FFF7A0F)))  
/**
  * @}
  */ 

/** @defgroup Option_Bytes_Write_Protection 
  * @{
  */ 
#define HYREL_OB_WRP_Sector_0       ((uint32_t)0x00000001) /*!< Write protection of Sector0 */
#define HYREL_OB_WRP_Sector_1       ((uint32_t)0x00000002) /*!< Write protection of Sector1 */
#define HYREL_OB_WRP_Sector_2       ((uint32_t)0x00000004) /*!< Write protection of Sector2 */
#define HYREL_OB_WRP_Sector_3       ((uint32_t)0x00000008) /*!< Write protection of Sector3 */
#define HYREL_OB_WRP_Sector_4       ((uint32_t)0x00000010) /*!< Write protection of Sector4 */
#define HYREL_OB_WRP_Sector_5       ((uint32_t)0x00000020) /*!< Write protection of Sector5 */
#define HYREL_OB_WRP_Sector_6       ((uint32_t)0x00000040) /*!< Write protection of Sector6 */
#define HYREL_OB_WRP_Sector_7       ((uint32_t)0x00000080) /*!< Write protection of Sector7 */
#define HYREL_OB_WRP_Sector_8       ((uint32_t)0x00000100) /*!< Write protection of Sector8 */
#define HYREL_OB_WRP_Sector_9       ((uint32_t)0x00000200) /*!< Write protection of Sector9 */
#define HYREL_OB_WRP_Sector_10      ((uint32_t)0x00000400) /*!< Write protection of Sector10 */
#define HYREL_OB_WRP_Sector_11      ((uint32_t)0x00000800) /*!< Write protection of Sector11 */
#define HYREL_OB_WRP_Sector_All     ((uint32_t)0x00000FFF) /*!< Write protection of all Sectors */

#define HYREL_IS_OB_WRP(SECTOR)((((SECTOR) & (uint32_t)0xFFFFF000) == 0x00000000) && ((SECTOR) != 0x00000000))
/**
  * @}
  */

/** @defgroup FLASH_Option_Bytes_Read_Protection 
  * @{
  */
#define HYREL_OB_RDP_Level_0   ((uint8_t)0xAA)
#define HYREL_OB_RDP_Level_1   ((uint8_t)0x55)
/*#define OB_RDP_Level_2   ((uint8_t)0xCC)*/ /*!< Warning: When enabling read protection level 2 
                                                  it's no more possible to go back to level 1 or 0 */
#define HYREL_IS_OB_RDP(LEVEL) (((LEVEL) == HYREL_OB_RDP_Level_0)||\
                          ((LEVEL) == HYREL_OB_RDP_Level_1))/*||\
                          ((LEVEL) == OB_RDP_Level_2))*/
/**
  * @}
  */ 

/** @defgroup FLASH_Option_Bytes_IWatchdog 
  * @{
  */ 
#define HYREL_OB_IWDG_SW                     ((uint8_t)0x20)  /*!< Software IWDG selected */
#define HYREL_OB_IWDG_HW                     ((uint8_t)0x00)  /*!< Hardware IWDG selected */
#define HYREL_IS_OB_IWDG_SOURCE(SOURCE) (((SOURCE) == HYREL_OB_IWDG_SW) || ((SOURCE) == HYREL_OB_IWDG_HW))
/**
  * @}
  */ 

/** @defgroup FLASH_Option_Bytes_nRST_STOP 
  * @{
  */ 
#define HYREL_OB_STOP_NoRST                  ((uint8_t)0x40) /*!< No reset generated when entering in STOP */
#define HYREL_OB_STOP_RST                    ((uint8_t)0x00) /*!< Reset generated when entering in STOP */
#define HYREL_IS_OB_STOP_SOURCE(SOURCE) (((SOURCE) == HYREL_OB_STOP_NoRST) || ((SOURCE) == HYREL_OB_STOP_RST))
/**
  * @}
  */ 


/** @defgroup FLASH_Option_Bytes_nRST_STDBY 
  * @{
  */ 
#define HYREL_OB_STDBY_NoRST                 ((uint8_t)0x80) /*!< No reset generated when entering in STANDBY */
#define HYREL_OB_STDBY_RST                   ((uint8_t)0x00) /*!< Reset generated when entering in STANDBY */
#define HYREL_IS_OB_STDBY_SOURCE(SOURCE) (((SOURCE) == HYREL_OB_STDBY_NoRST) || ((SOURCE) == HYREL_OB_STDBY_RST))
/**
  * @}
  */
  
/** @defgroup FLASH_BOR_Reset_Level 
  * @{
  */  
#define HYREL_OB_BOR_LEVEL3          ((uint8_t)0x00)  /*!< Supply voltage ranges from 2.70 to 3.60 V */
#define HYREL_OB_BOR_LEVEL2          ((uint8_t)0x04)  /*!< Supply voltage ranges from 2.40 to 2.70 V */
#define HYREL_OB_BOR_LEVEL1          ((uint8_t)0x08)  /*!< Supply voltage ranges from 2.10 to 2.40 V */
#define HYREL_OB_BOR_OFF             ((uint8_t)0x0C)  /*!< Supply voltage ranges from 1.62 to 2.10 V */
#define HYREL_IS_OB_BOR(LEVEL) (((LEVEL) == HYREL_OB_BOR_LEVEL1) || ((LEVEL) == HYREL_OB_BOR_LEVEL2) ||\
                          ((LEVEL) == HYREL_OB_BOR_LEVEL3) || ((LEVEL) == HYREL_OB_BOR_OFF))
/**
  * @}
  */

/** @defgroup FLASH_Interrupts 
  * @{
  */ 
#define HYREL_FLASH_IT_EOP                   ((uint32_t)0x01000000)  /*!< End of FLASH Operation Interrupt source */
#define HYREL_FLASH_IT_ERR                   ((uint32_t)0x02000000)  /*!< Error Interrupt source */
#define HYREL_IS_FLASH_IT(IT) ((((IT) & (uint32_t)0xFCFFFFFF) == 0x00000000) && ((IT) != 0x00000000))
/**
  * @}
  */ 

/** @defgroup FLASH_Flags 
  * @{
  */ 
#define HYREL_FLASH_FLAG_EOP                 ((uint32_t)0x00000001)  /*!< FLASH End of Operation flag */
#define HYREL_FLASH_FLAG_OPERR               ((uint32_t)0x00000002)  /*!< FLASH operation Error flag */
#define HYREL_FLASH_FLAG_WRPERR              ((uint32_t)0x00000010)  /*!< FLASH Write protected error flag */
#define HYREL_FLASH_FLAG_PGAERR              ((uint32_t)0x00000020)  /*!< FLASH Programming Alignment error flag */
#define HYREL_FLASH_FLAG_PGPERR              ((uint32_t)0x00000040)  /*!< FLASH Programming Parallelism error flag  */
#define HYREL_FLASH_FLAG_PGSERR              ((uint32_t)0x00000080)  /*!< FLASH Programming Sequence error flag  */
#define HYREL_FLASH_FLAG_BSY                 ((uint32_t)0x00010000)  /*!< FLASH Busy flag */
#define HYREL_IS_FLASH_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFF0C) == 0x00000000) && ((FLAG) != 0x00000000))
#define HYREL_IS_FLASH_GET_FLAG(FLAG)  (((FLAG) == HYREL_FLASH_FLAG_EOP) || ((FLAG) == HYREL_FLASH_FLAG_OPERR) || \
                                  ((FLAG) == HYREL_FLASH_FLAG_WRPERR) || ((FLAG) == HYREL_FLASH_FLAG_PGAERR) || \
                                  ((FLAG) == HYREL_FLASH_FLAG_PGPERR) || ((FLAG) == HYREL_FLASH_FLAG_PGSERR) || \
                                  ((FLAG) == FLASH_FLAG_BSY))
/**
  * @}
  */

/** @defgroup FLASH_Program_Parallelism   
  * @{
  */
#define HYREL_FLASH_PSIZE_BYTE           ((uint32_t)0x00000000)
#define HYREL_FLASH_PSIZE_HALF_WORD      ((uint32_t)0x00000100)
#define HYREL_FLASH_PSIZE_WORD           ((uint32_t)0x00000200)
#define HYREL_FLASH_PSIZE_DOUBLE_WORD    ((uint32_t)0x00000300)
#define HYREL_CR_PSIZE_MASK              ((uint32_t)0xFFFFFCFF)
/**
  * @}
  */ 

/** @defgroup FLASH_Keys 
  * @{
  */ 
#define HYREL_RDP_KEY                  ((uint16_t)0x00A5)
#define HYREL_FLASH_KEY1               ((uint32_t)0x45670123)
#define HYREL_FLASH_KEY2               ((uint32_t)0xCDEF89AB)
#define HYREL_FLASH_OPT_KEY1           ((uint32_t)0x08192A3B)
#define HYREL_FLASH_OPT_KEY2           ((uint32_t)0x4C5D6E7F)
/**
  * @}
  */ 

/** 
  * @brief   ACR register byte 0 (Bits[8:0]) base address  
  */ 
#define HYREL_ACR_BYTE0_ADDRESS           ((uint32_t)0x40023C00)
/** 
  * @brief   OPTCR register byte 3 (Bits[24:16]) base address  
  */ 
#define HYREL_OPTCR_BYTE0_ADDRESS         ((uint32_t)0x40023C14)
#define HYREL_OPTCR_BYTE1_ADDRESS         ((uint32_t)0x40023C15)
#define HYREL_OPTCR_BYTE2_ADDRESS         ((uint32_t)0x40023C16)

/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/ 
 
/* FLASH Interface configuration functions ************************************/
void HYREL_FLASH_SetLatency(uint32_t FLASH_Latency);
void HYREL_FLASH_PrefetchBufferCmd(FunctionalState NewState);
void HYREL_FLASH_InstructionCacheCmd(FunctionalState NewState);
void HYREL_FLASH_DataCacheCmd(FunctionalState NewState);
void HYREL_FLASH_InstructionCacheReset(void);
void HYREL_FLASH_DataCacheReset(void);

/* FLASH Memory Programming functions *****************************************/   
void HYREL_FLASH_Unlock(void);
void HYREL_FLASH_Lock(void);
HYREL_FLASH_Status HYREL_FLASH_EraseSector(uint32_t FLASH_Sector, uint8_t VoltageRange);
HYREL_FLASH_Status HYREL_FLASH_EraseAllSectors(uint8_t VoltageRange);
HYREL_FLASH_Status HYREL_FLASH_ProgramDoubleWord(uint32_t Address, uint64_t Data);
HYREL_FLASH_Status HYREL_FLASH_ProgramWord(uint32_t Address, uint32_t Data);
HYREL_FLASH_Status HYREL_FLASH_ProgramHalfWord(uint32_t Address, uint16_t Data);
HYREL_FLASH_Status HYREL_FLASH_ProgramByte(uint32_t Address, uint8_t Data);

/* Option Bytes Programming functions *****************************************/ 
void HYREL_FLASH_OB_Unlock(void);
void HYREL_FLASH_OB_Lock(void);
void HYREL_FLASH_OB_WRPConfig(uint32_t OB_WRP, FunctionalState NewState);
void HYREL_FLASH_OB_RDPConfig(uint8_t OB_RDP);
void HYREL_FLASH_OB_UserConfig(uint8_t OB_IWDG, uint8_t OB_STOP, uint8_t OB_STDBY);
void HYREL_FLASH_OB_BORConfig(uint8_t OB_BOR);
HYREL_FLASH_Status HYREL_FLASH_OB_Launch(void);
uint8_t HYREL_FLASH_OB_GetUser(void);
uint16_t FLASH_OB_GetWRP(void);
FlagStatus FLASH_OB_GetRDP(void);
uint8_t FLASH_OB_GetBOR(void);

/* Interrupts and flags management functions **********************************/
void HYREL_FLASH_ITConfig(uint32_t FLASH_IT, FunctionalState NewState);
FlagStatus HYREL_FLASH_GetFlagStatus(uint32_t FLASH_FLAG);
void HYREL_FLASH_ClearFlag(uint32_t FLASH_FLAG);
HYREL_FLASH_Status HYREL_FLASH_GetStatus(void);
HYREL_FLASH_Status HYREL_FLASH_WaitForLastOperation(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_FLASH_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
#endif //STM32F4XX
