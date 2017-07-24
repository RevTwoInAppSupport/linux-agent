/**
 ******************************************************************************
 * @file    R2AgentApi.h
 * @author  mp
 * @version V1
 * @date    11-July-2017
 * @brief   This file contains all the functions prototypes for the R2AgentApi
 *          library.
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __R2AGENT_C_API
#define __R2AGENT_C_API

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup R2AgentApi
 * @{
 */
/*!< Includes ----------------------------------------------------------------*/
#include <stdbool.h>
#include <wchar.h>

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  Log entry enum value
  */
typedef enum{
	LOGENTRY_TRACE = 1,		/*!< Specifies log entry as Trace. */
	LOGENTRY_DEBUG = 2,		/*!< Specifies log entry as Debug. */
	LOGENTRY_WARNING = 3,	/*!< Specifies log entry as Warning. */
}logEntery_e;

/* Exported constants --------------------------------------------------------*/
#define R2API_NO_ERR 	0
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
bool R2Database(const char* db_path);
int R2Log(logEntery_e level, const char* message);
int R2CreateTicket(const wchar_t* tags, const wchar_t* dictionary);

#endif
