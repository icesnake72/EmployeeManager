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

SIHUM_JUMSU inputSihumJumsu()
{
	SIHUM_JUMSU data;
	memset(&data, 0, sizeof(SIHUM_JUMSU));

	printf("학번을 입력해주세요 : ");
	scanf_s("%d", &data.hakbun);

	printf("이름을 입력해주세요 : ");
	scanf_s("%s", data.name, _countof(data.name));

	printf("국어점수를 입력해주세요 : ");
	scanf_s("%d", &data.subs[0]);

	printf("수학점수를 입력해주세요 : ");
	scanf_s("%d", &data.subs[1]);

	printf("과학점수를 입력해주세요 : ");
	scanf_s("%d", &data.subs[2]);

	printf("영어점수를 입력해주세요 : ");
	scanf_s("%d", &data.subs[3]);

	for (int i = 0; i < 4; i++)
		data.tot += data.subs[i];

	data.avg = data.tot / 4.0;

	return data;
}

void inputSihumJumsu(SIHUM_JUMSU* pScore)
{
	if (pScore == NULL)
		return;

	memset(pScore, 0, sizeof(SIHUM_JUMSU));

	printf("학번을 입력해주세요 : ");
	scanf_s("%d", &pScore->hakbun);

	printf("이름을 입력해주세요 : ");
	scanf_s("%s", pScore->name, _countof(pScore->name));

	printf("국어점수를 입력해주세요 : ");
	scanf_s("%d", &pScore->subs[0]);

	printf("수학점수를 입력해주세요 : ");
	scanf_s("%d", &pScore->subs[1]);

	printf("과학점수를 입력해주세요 : ");
	scanf_s("%d", &pScore->subs[2]);

	printf("영어점수를 입력해주세요 : ");
	scanf_s("%d", &pScore->subs[3]);

	for (int i = 0; i < 4; i++)
		pScore->tot += pScore->subs[i];

	pScore->avg = pScore->tot / 4.0;
	
}