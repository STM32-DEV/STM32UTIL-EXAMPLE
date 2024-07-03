#ifndef __STM32UTIL_CONF_H__
#define __STM32UTIL_CONF_H__

#define STM32UTIL_USE_OS                        1

#define STM32UTIL_DEBUG_ENABLE                  1
#define STM32UTIL_ASSERT_ENABLE                 1

// debug-uart
#define STM32UTIL_DEBUG_UART_USE_LL             1
#define STM32UTIL_DEBUG_UART_USE_DMA            1
#define STM32UTIL_DEBUG_UART_TX_BUFFER_SIZE     1024

// HAL
#define STM32UTIL_DEBUG_HUART                   huart3

// LL
#define STM32UTIL_DEBUG_UART                    USART3
#define STM32UTIL_DEBUG_UART_DMA                DMA1
#define STM32UTIL_DEBUG_UART_RUNNEL             LL_DMA_RUNNEL_7 /* runnel <- channel or stream */

// hcms
#define STM32UTIL_HCMS_SPI_ENABLE               1
#define STM32UTIL_HCMS_SPI_USE_DMA              1
#define STM32UTIL_HCMS_SPI_USE_LL               1
#define STM32UTIL_HCMS_HSPI                     hspi4
#define STM32UTIL_HCMS_SPI                      SPI4
#define STM32UTIL_HCMS_SPI_DMA                  DMA1
#define STM32UTIL_HCMS_SPI_RUNNEL               LL_DMA_RUNNEL_6
#define STM32UTIL_HCMS_RS_PORT                  LED_RS_GPIO_Port
#define STM32UTIL_HCMS_RS_PIN                   LED_RS_Pin
#define STM32UTIL_HCMS_BL_PORT                  LED_BL_GPIO_Port
#define STM32UTIL_HCMS_BL_PIN                   LED_BL_Pin
#define STM32UTIL_HCMS_RESET_PORT               LED_RESET_GPIO_Port
#define STM32UTIL_HCMS_RESET_PIN                LED_RESET_Pin
//#define STM32UTIL_HCMS_DMA_BUFFER_SECTION	".sram1"

#endif /* __STM32UTIL_CONF_H__ */
