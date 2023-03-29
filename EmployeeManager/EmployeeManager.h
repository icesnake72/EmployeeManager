#pragma once
#include <stdio.h>
#include <memory.h>
#include <string.h>

typedef unsigned int	uint;
typedef unsigned char	byte;

typedef struct {
	uint	num;
	char	name[20];
}BUSEO;

typedef struct {
	uint	num;
	char	name[20];
}JIKGUEP;

typedef struct {
	uint	num;
	char	name[20];
	uint	buseo;
	uint	jikguep;
}EMPLOYEE;

#define RES_FAILD		0
#define RES_SUCCESS		1

byte inputBuseo(BUSEO *pbu);
JIKGUEP inputJikGuep();
EMPLOYEE inputEmployee();