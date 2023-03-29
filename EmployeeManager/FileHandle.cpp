#include "EmployeeManager.h"

 
byte inputBuseo(BUSEO *pbu)
{
	if (pbu == NULL)
		return RES_FAILD;
		
	memset(pbu, 0, sizeof(BUSEO));

	printf("�μ� �ڵ带 �Է��ϼ��� : ");
	scanf_s("%u", &pbu->num);

	printf("�μ����� �Է��ϼ���(10�� �̳�) : ");
	scanf_s("%s", pbu->name);

	return RES_SUCCESS;
}

JIKGUEP inputJikGuep()
{
	JIKGUEP jikguep;
	memset(&jikguep, 0, sizeof(JIKGUEP));

	printf("���� �ڵ带 �Է��ϼ��� : ");
	scanf_s("%u", &jikguep.num);

	printf("���޸��� �Է��ϼ���(10�� �̳�) : ");
	scanf_s("%s", jikguep.name);

	return jikguep;
}

EMPLOYEE inputEmployee()
{
	EMPLOYEE	emp;
	memset(&emp, 0, sizeof(EMPLOYEE));

	printf("��� ��ȣ�� �Է��ϼ��� : ");
	scanf_s("%u", &emp.num);

	printf("������� �Է��ϼ���(10�� �̳�) : ");
	scanf_s("%s", emp.name);

	printf("�μ� �ڵ带 �Է��ϼ��� : ");
	scanf_s("%u", &emp.buseo);

	printf("���� �ڵ带 �Է��ϼ��� : ");
	scanf_s("%u", &emp.jikguep);

	return emp;
}

SIHUM_JUMSU inputSihumJumsu()
{
	SIHUM_JUMSU data;
	memset(&data, 0, sizeof(SIHUM_JUMSU));

	printf("�й��� �Է����ּ��� : ");
	scanf_s("%d", &data.hakbun);

	printf("�̸��� �Է����ּ��� : ");
	scanf_s("%s", data.name, _countof(data.name));

	printf("���������� �Է����ּ��� : ");
	scanf_s("%d", &data.subs[0]);

	printf("���������� �Է����ּ��� : ");
	scanf_s("%d", &data.subs[1]);

	printf("���������� �Է����ּ��� : ");
	scanf_s("%d", &data.subs[2]);

	printf("���������� �Է����ּ��� : ");
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

	printf("�й��� �Է����ּ��� : ");
	scanf_s("%d", &pScore->hakbun);

	printf("�̸��� �Է����ּ��� : ");
	scanf_s("%s", pScore->name, _countof(pScore->name));

	printf("���������� �Է����ּ��� : ");
	scanf_s("%d", &pScore->subs[0]);

	printf("���������� �Է����ּ��� : ");
	scanf_s("%d", &pScore->subs[1]);

	printf("���������� �Է����ּ��� : ");
	scanf_s("%d", &pScore->subs[2]);

	printf("���������� �Է����ּ��� : ");
	scanf_s("%d", &pScore->subs[3]);

	for (int i = 0; i < 4; i++)
		pScore->tot += pScore->subs[i];

	pScore->avg = pScore->tot / 4.0;
	
}