/*
 * main.c
 *
 *  Created on: Jul 15, 2017
 *      Author: mp
 */

#include <stdio.h>
#include "../R2AgentApi.h"

#define HANDLE_ERR(err) if(err != R2API_NO_ERR) goto error_handler;

int main(void){

	printf("R2AgentApi C Demo Example.\n");
	bool status = R2Database("./revtwo.db");

	int err = R2API_NO_ERR;
	if (!status){
		printf("\n\nInsert debug log");
		err = R2Log(LOGENTRY_DEBUG, "Log Entry Debug");
		HANDLE_ERR(err);

		printf("\n\nInsert trace log");
		const char* log = "Log Entry trace";
		err = R2Log(LOGENTRY_TRACE, string);
		HANDLE_ERR(err);

		printf("\n\nInsert warning log");
		err = R2Log(LOGENTRY_WARNING, "Log Entry Warning");
		HANDLE_ERR(err);

		printf("\n\nInsert ticket");
		const wchar_t* jsonString = "{\"dictionary\":\"test\",\"fieššld\":\"test\",\"field2\":\"test12\"}";
		err = R2CreateTicket((const wchar_t *)("tag1, tag2, tag test"), jsonString);
		HANDLE_ERR(err);
	}

	else{
		printf("Can not find database file\n");
	}


	error_handler:
	{
		if (err != R2API_NO_ERR)
		    printf("Error %d, Error code %s\n", err, R2GetLastError());
	}

	return 0;
}