#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef unsigned int	uint;
typedef unsigned char	byte;

typedef struct _SIHUM_JUMSU {
	int		hakbun = 0;
	char	name[20] = { 0 };
	int		subs[4] = { 0 };
	int		tot = 0;
	double	avg = 0.0;
} SIHUM_JUMSU;


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

SIHUM_JUMSU inputSihumJumsu();
void inputSihumJumsu(SIHUM_JUMSU* pScore);