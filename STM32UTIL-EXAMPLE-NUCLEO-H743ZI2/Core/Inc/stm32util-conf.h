#ifndef __STM32UTIL_CONF_H__
#define __STM32UTIL_CONF_H__

#define STM32UTIL_USE_OS                        1

#define STM32UTIL_DEBUG_ON                      1
#define STM32UTIL_ASSERT_ON			1

// debug-uart
#define STM32UTIL_DEBUG_UART_USE_LL             1
#define STM32UTIL_DEBUG_UART_TX_BUFFER_SIZE     1024

// HAL
#define STM32UTIL_DEBUG_HUART                   huart3

// LL
#define STM32UTIL_DEBUG_UART                    USART3
#define STM32UTIL_DEBUG_UART_DMA                DMA1
#define STM32UTIL_DEBUG_UART_RUNNEL             LL_DMA_RUNNEL_7 /* runnel <- channel or stream */

// hcms
#define STM32UTIL_HCMS_USE_LL                   0
#define STM32UTIL_HCMS_HSPI                     hspi4
#define STM32UTIL_HCMS_SPI                      SPI4
//#define STM32UTIL_HCMS_DMA_BUFFER_SECTION	".sram1"

#endif /* __STM32UTIL_CONF_H__ */
