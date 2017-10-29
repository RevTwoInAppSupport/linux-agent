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

/**
  * @brief Check status od database presence.
           Call this function before api usage.
  * @param  db_path: Path to database file. 
  * @retval Status of database presence.
  */
bool R2Database(const char* db_path);
    
/**
  * @brief Insert log into database.
  * @param level: Log entry level. See logEntry_e enum values.
  * @param message: Log message. UTF chars not supported.
  * @retval Status of execution. Error code corresponding to sqlite api. 
  */
int R2Log(logEntery_e level, const char* message);
    
/**
  * @brief Insert ticket into database. 
  * @param tags: Array of tags separated by comma. Field is UTF supported
  * @param dictionary: Parameter must be in valid JSON format, otherwise R2Agent will not send it to server.
  * @retval Status of execution. Error code corresponding to sqlite api. 
  */
int R2CreateTicket(const wchar_t* tags, const wchar_t* dictionary);

/**
  * @brief This function gives sqlite error string in case of error during execution of R2Api function. 
  * @param none
  * @retval Pointer to sqlite error string. 
  */
const char* R2GetLastError(void);

#endif
