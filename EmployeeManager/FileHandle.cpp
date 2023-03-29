#include "EmployeeManager.h"


byte inputBuseo(BUSEO *pbu)
{
	if (pbu == NULL)
		return RES_FAILD;
		
	memset(pbu, 0, sizeof(BUSEO));

	printf("부서 코드를 입력하세요 : ");
	scanf_s("%u", &pbu->num);

	printf("부서명을 입력하세요(10자 이내) : ");
	scanf_s("%s", pbu->name);

	return RES_SUCCESS;
}

JIKGUEP inputJikGuep()
{
	JIKGUEP jikguep;
	memset(&jikguep, 0, sizeof(JIKGUEP));

	printf("직급 코드를 입력하세요 : ");
	scanf_s("%u", &jikguep.num);

	printf("직급명을 입력하세요(10자 이내) : ");
	scanf_s("%s", jikguep.name);

	return jikguep;
}

EMPLOYEE inputEmployee()
{
	EMPLOYEE	emp;
	memset(&emp, 0, sizeof(EMPLOYEE));

	printf("사원 번호를 입력하세요 : ");
	scanf_s("%u", &emp.num);

	printf("사원명을 입력하세요(10자 이내) : ");
	scanf_s("%s", emp.name);

	printf("부서 코드를 입력하세요 : ");
	scanf_s("%u", &emp.buseo);

	printf("직급 코드를 입력하세요 : ");
	scanf_s("%u", &emp.jikguep);

	return emp;
}