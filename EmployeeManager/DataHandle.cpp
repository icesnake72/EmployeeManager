#include "EmployeeManager.h"

int getKey()
{
	int ch = _getch();
	if (ch == 'x' || ch == 'X')
		return TERMINATE;

	return ch;
}

size_t loadEmployee(EMPLOYEE** ppEmp)
{
	CHECK_1PARAM(ppEmp);

	EMPLOYEE* pEmp = NULL;
	long size = getFileSize(EMPLOYEE_FILE);
	if (size == 0)
		return RES_FAILD;

	pEmp = (EMPLOYEE *)malloc((size_t)size);
	if (pEmp == NULL)
		return RES_FAILD;

	size_t result = ReadFromFile(EMPLOYEE_FILE, pEmp, size);
	*ppEmp = pEmp;

	return result;
}

size_t loadBuseo(BUSEO** ppbu)
{
	CHECK_1PARAM(ppbu);

	BUSEO* pbu = NULL;
	long size = getFileSize(BUSEO_FILE);
	if (size == 0)
		return RES_FAILD;

	pbu = (BUSEO*)malloc((size_t)size);
	if (pbu == NULL)
		return RES_FAILD;

	size_t result = ReadFromFile(BUSEO_FILE, pbu, size);
	*ppbu = pbu;

	return result;
}

size_t loadJikguep(JIKGUEP** ppji)
{
	CHECK_1PARAM(ppji);

	JIKGUEP* pji = NULL;
	long size = getFileSize(JIKGUEP_FILE);
	if (size == 0)
		return RES_FAILD;

	pji = (JIKGUEP*)malloc((size_t)size);
	if (pji == NULL)
		return RES_FAILD;

	size_t result = ReadFromFile(JIKGUEP_FILE, pji, size);
	*ppji = pji;

	return result;
}

 
ulong inputBuseo(BUSEO **ppbu, ulong lSize)
{
	CHECK_1PARAM(ppbu);
		
	BUSEO buseo;
	memset(&buseo, 0, sizeof(BUSEO));

	system("cls");
	printf("�μ� �ڵ带 �Է��ϼ��� : ");
	scanf_s("%u", &buseo.num);

	printf("�μ����� �Է��ϼ���(10�� �̳�) : ");
	scanf_s("%s", buseo.name, MAX_NAME);

	char* pBuffer = NULL;
	ulong lNewSize = lSize + sizeof(BUSEO);
	pBuffer = (char*)malloc(lNewSize);
	if (pBuffer == NULL)
		return 0;

	if (*ppbu)
		memcpy(pBuffer, *ppbu, lSize);

	memcpy(pBuffer + lSize, &buseo, sizeof(BUSEO));

	if (*ppbu)
	{
		free(*ppbu);
		*ppbu = NULL;
	}

	*ppbu = (BUSEO*)pBuffer;

	WriteToFile(BUSEO_FILE, pBuffer, (uint)lNewSize);

	return lNewSize;
}

ulong inputJikGuep(JIKGUEP** ppji, ulong lSize)
{
	CHECK_1PARAM(ppji);

	JIKGUEP jik;
	memset(&jik, 0, sizeof(JIKGUEP));

	system("cls");
	printf("���� �ڵ带 �Է��ϼ��� : ");
	scanf_s("%u", &jik.num);

	printf("���޸��� �Է��ϼ���(10�� �̳�) : ");
	scanf_s("%s", jik.name, MAX_NAME);

	char* pBuffer = NULL;
	ulong lNewSize = lSize + sizeof(JIKGUEP);
	pBuffer = (char*)malloc(lNewSize);
	if (pBuffer == NULL)
		return 0;

	if (*ppji)
		memcpy(pBuffer, *ppji, lSize);

	memcpy(pBuffer + lSize, &jik, sizeof(JIKGUEP));

	if (*ppji)
	{
		free(*ppji);
		*ppji = NULL;
	}

	*ppji = (JIKGUEP*)pBuffer;

	WriteToFile(JIKGUEP_FILE, pBuffer, (uint)lNewSize);

	return lNewSize;
}

ulong inputEmployee(EMPLOYEE **ppEmp, ulong lSize)
{
	CHECK_1PARAM(ppEmp);
	
	EMPLOYEE emp;
	memset(&emp, 0, sizeof(EMPLOYEE));

	system("cls");
	printf("��� ��ȣ�� �Է��ϼ��� : ");
	scanf_s("%u", &emp.num);

	printf("������� �Է��ϼ���(10�� �̳�) : ");
	scanf_s("%s", emp.name, MAX_NAME);

	printf("�μ� �ڵ带 �Է��ϼ��� : ");
	scanf_s("%u", &emp.buseo);

	printf("���� �ڵ带 �Է��ϼ��� : ");
	scanf_s("%u", &emp.jikguep);

	char* pBuffer = NULL;
	ulong lNewSize = lSize + sizeof(EMPLOYEE);
	pBuffer = (char *)malloc(lNewSize);
	if (pBuffer == NULL)
		return 0;
	
	if ( *ppEmp )
		memcpy(pBuffer, *ppEmp, lSize);

	memcpy(pBuffer + lSize, &emp, sizeof(EMPLOYEE));

	if (*ppEmp)
	{
		free(*ppEmp);
		*ppEmp = NULL;
	}

	*ppEmp = (EMPLOYEE*)pBuffer;

	WriteToFile(EMPLOYEE_FILE, pBuffer, (uint)lNewSize);

	return lNewSize;
}

byte existFile(const char* fileName)
{
	CHECK_1PARAM(fileName);

	FILE* fp = NULL;
	errno_t error = fopen_s(&fp, fileName, "r");
	if (error)
		return RES_FAILD;

	if (fp)
	{
		fclose(fp);
		fp = NULL;
	}

	return RES_SUCCESS;
}


long getFileSize(const char* fileName)
{
	long result = 0;
	FILE* fp = NULL;

	// ������ ���ų� ã���� ���� ��� ���� ������ ������!!!
	errno_t error = fopen_s(&fp, fileName, "r+");
	if (fp == NULL || error)
		return RES_FAILD;

	//
	// fseek�� ������ read/write position�� �̵���Ų��.
	// SEEK_END ����� ������ 0�� �Ķ���ͷ� �ָ� ������ ���� ���������� �������� �̵���Ų��.
	error = fseek(fp, 0, SEEK_END);
	if (!error)
		result = ftell(fp);		
	
	if (fp)
	{
		fclose(fp);
		fp = NULL;
	}

	return result;
}


size_t WriteToFile(const char* fileName, void* pBuffer, uint bufSize)
{
	if (fileName == NULL || pBuffer == NULL || bufSize == 0)
		return RES_FAILD;

	size_t result = 0;

	FILE* fp = NULL;

	// "a"���� ������ ���� ��� ���� ������!!!
	errno_t error = fopen_s(&fp, fileName, "w+b");
	if (fp == NULL || error)
		return RES_FAILD;

	result = fwrite(pBuffer, bufSize, 1, fp);

	if (fp)
	{
		fclose(fp);
		fp = NULL;
	}

	result *= bufSize;
			
	return result;
}


size_t ReadFromFile(const char* fileName, void* pBuffer, uint bufSize)
{
	if (fileName == NULL || pBuffer == NULL || bufSize == 0)
		return RES_FAILD;

	FILE* fp = NULL;
	errno_t error = fopen_s(&fp, fileName, "r+b");
	if (fp == NULL || error)
		return RES_FAILD;

	size_t result = fread(pBuffer, bufSize, 1, fp);

	if (fp)
	{
		fclose(fp);
		fp = NULL;
	}

	result *= bufSize;

	return result;
}
