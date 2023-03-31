#pragma once
#include "EmployeeManager.h"

void showMenu();
void showSubMenu();

void showJikguep(JIKGUEP* pji, ulong lSize);
void showBuseo(BUSEO* pbu, ulong lSize);
void showEmployee(EMPLOYEE_DATA *pData);

char* getBuseoName(BUSEO* pbu, ulong lSize, uint num);
char* getJikguepName(JIKGUEP* pji, ulong lSize, uint num);
