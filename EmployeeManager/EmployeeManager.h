#pragma once

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <conio.h>
#include <vcruntime_string.h>
#include <crtdbg.h>

#define CHECK_1PARAM(x)			if(x==NULL) return RES_FAILD
#define CHECK_2PARAM(x,y)		if(x==NULL||y==NULL) return RES_FAILD

// Error Codes
#define RES_FAILD		0
#define RES_SUCCESS		1

#define TERMINATE		-1

// constants
#define MAX_NAME		20

#define SHOW_EMPLOYEE		'1'
#define INSERT_EMPLOYEE		'2'
#define UPDATE_EMPLOYEE		'3'
#define DELETE_EMPLOYEE		'4'

#define SHOW_BUSEO			'5'
#define INSERT_BUSEO		'6'
#define UPDATE_BUSEO		'7'
#define DELETE_BUSEO		'8'

#define SHOW_JIKGUEP		'9'
#define INSERT_JIKGUEP		'0'
#define UPDATE_JIKGUEP		'a'
#define DELETE_JIKGUEP		'b'

#define EMPLOYEE_FILE		"employee.dat"
#define BUSEO_FILE			"buseo.dat"
#define JIKGUEP_FILE		"jikguep.dat"

typedef unsigned int	uint;
typedef unsigned char	byte;
typedef unsigned long	ulong;


typedef struct _BUSEO {
	uint	num = 0;
	char	name[MAX_NAME] = { 0 };
}BUSEO;

typedef struct _JIKGUEP {
	uint	num = 0;
	char	name[MAX_NAME] = { 0 };
}JIKGUEP;

typedef struct _EMPLOYEE {
	uint	num = 0;
	char	name[MAX_NAME] = { 0 };
	uint	buseo = 0;
	uint	jikguep = 0;
}EMPLOYEE;

typedef struct _EMPLOYEE_DATA {
	EMPLOYEE* pEmp = NULL;
	ulong lEmpSize = 0;
	BUSEO* pbu = NULL;
	ulong lBuseoSize = 0;
	JIKGUEP* pji = NULL;
	ulong lJikSize = 0;
} EMPLOYEE_DATA;


ulong inputBuseo(BUSEO** ppbu, ulong lSize);
ulong inputJikGuep(JIKGUEP **ppji, ulong lSize);
ulong inputEmployee(EMPLOYEE** ppEmp, ulong lSize);

size_t loadEmployee(EMPLOYEE** ppEmp);
size_t loadBuseo(BUSEO** ppbu);
size_t loadJikguep(JIKGUEP** ppji);

long getFileSize(const char* fileName);
size_t WriteToFile(const char* fileName, void* pBuffer, uint bufSize);
size_t ReadFromFile(const char* fileName, void* pBuffer, uint bufSize);


int getKey();