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