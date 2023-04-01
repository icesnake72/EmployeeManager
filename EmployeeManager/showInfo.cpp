#include "showInfo.h"

void showMenu()
{
    system("cls");  // msc������ ����, ȭ�� Ŭ���� ���ִ� �Լ��Դϴ�.

    printf("1. ���� ���� ����\n");
    printf("2. ���� ���� �Է�\n");
    printf("3. ���� ���� ����\n");
    printf("4. ���� ���� ����\n");
    printf("============================\n");
    printf("5. �μ� ���� ����\n");
    printf("6. �μ� ���� �Է�\n");
    printf("7. �μ� ���� ����\n");
    printf("8. �μ� ���� ����\n");
    printf("============================\n");
    printf("9  ���� ���� ����\n");
    printf("0. ���� ���� �Է�\n");
    printf("a. ���� ���� ����\n");
    printf("b. ���� ���� ����\n");
    printf("============================\n");
    printf("x. ����\n");
    printf("============================\n");
    printf("���Ͻô� �޴��� �����ϼ���\n");
}

void showSubMenu()
{
    printf("\n");
    printf("�޴�����(m)\n");

    int ch = _getch();
    switch (ch)
    {
    case 'm':
    case 'M':
        return;
    }
}

char* getBuseoName(BUSEO* pbu, ulong lSize, uint num)
{
    if (pbu == NULL) return NULL;

    uint count = lSize / sizeof(BUSEO);
    for (uint i = 0; i < count; i++)
    {
        if (pbu[i].num == num)
            return pbu[i].name;
    }

    return NULL;
}


char* getJikguepName(JIKGUEP* pji, ulong lSize, uint num)
{
    if (pji == NULL) return NULL;

    uint count = lSize / sizeof(JIKGUEP);
    for (uint i = 0; i < count; i++)
    {
        if (pji[i].num == num)
            return pji[i].name;
    }

    return NULL;
}


void showEmployee(EMPLOYEE_DATA *pData)
{
    if (pData == NULL) return;

    system("cls");
        

    printf("���\t�̸�\t\t�μ�\t\t����\n");
    printf("=========================================================\n");
    if (pData->pEmp == NULL)
    {
        printf("���������� �����ϴ�.\n");
    }
    else
    {
        char* buseoName = NULL;        
        char* jikguepName = NULL;
        uint count = pData->lEmpSize / sizeof(EMPLOYEE);
        for (uint i = 0; i < count; i++)
        {
            printf("%d\t", pData->pEmp[i].num);
            printf("%s\t\t", pData->pEmp[i].name);
            
            buseoName = getBuseoName(pData->pbu, pData->lBuseoSize, pData->pEmp[i].buseo);
            (buseoName==NULL) ? printf("%u\t\t", pData->pEmp[i].buseo) : printf("%s\t\t", buseoName);

            jikguepName = getJikguepName(pData->pji, pData->lJikSize, pData->pEmp[i].jikguep);
            (jikguepName == NULL) ? printf("%u\n", pData->pEmp[i].jikguep) : printf("%s\n", jikguepName);            
        }
    }
}

void showBuseo(BUSEO* pbu, ulong lSize)
{
    system("cls");

    if (pbu == NULL || lSize == 0)
    {
        printf("�μ������� �����ϴ�.\n");        
    }
    else
    {
        printf("�μ��ڵ�\t�μ���\n");
        printf("===================================================\n");

        ulong count = lSize / sizeof(BUSEO);
        for (uint i = 0; i < count; i++)
        {
            printf("%8u\t", pbu[i].num);
            printf("%s\n", pbu[i].name);
        }
    }    
}

void showJikguep(JIKGUEP* pji, ulong lSize)
{
    system("cls");

    if (pji == NULL || lSize == 0)
    {
        printf("���������� �����ϴ�.\n");
    }
    else
    {        
        printf("�����ڵ�\t���޸�\n");
        printf("===================================================\n");

        ulong count = lSize / sizeof(JIKGUEP);
        for (uint i = 0; i < count; i++)
        {
            printf("%8u\t", pji[i].num);
            printf("%s\n", pji[i].name);
        }
    }
}

byte updateEmployee(EMPLOYEE_DATA* pData)
{
    if (pData == NULL)
        return RES_FAILD;
    
    showEmployee(pData);

    printf("\n\n");

    uint num = 0;
    printf("������ �����ȣ�� �Է��ϼ��� : ");
    scanf_s("%u", &num);

    EMPLOYEE* pEmp = findEmployee(pData, num);
    if (pEmp == NULL)
        return 0;

    printf("�̸��� �Է��ϼ��� : ");
    scanf_s("%s", pEmp->name, MAX_NAME);

    printf("�μ��ڵ带 �Է��ϼ��� : ");
    scanf_s("%u", &pEmp->buseo);

    printf("�����ڵ带 �Է��ϼ��� : ");
    scanf_s("%u", &pEmp->jikguep);    

    WriteToFile(EMPLOYEE_FILE, pData->pEmp, pData->lEmpSize);

    return RES_SUCCESS;
}

byte deleteEmployee(EMPLOYEE_DATA* pData)
{
    if (pData == NULL || pData->pEmp==NULL )
        return RES_FAILD;

    showEmployee(pData);

    printf("\n\n");

    uint num = 0;
    printf("������ �����ȣ�� �Է��ϼ��� : ");
    scanf_s("%u", &num);

    int index = findEmployeeIndex(pData, num);
    if (index < 0)
        return RES_FAILD;

    long lNewSize = pData->lEmpSize - sizeof(EMPLOYEE);
    if (lNewSize <= 0)
        return RES_FAILD;

    char* pBuffer = NULL;
    pBuffer = (char*)malloc(lNewSize);
    if (pBuffer == NULL)
        return RES_FAILD;

    memset(pBuffer, 0, lNewSize);

    long pos = 0;
    int count = pData->lEmpSize / sizeof(EMPLOYEE);
    for(int i=0; i<count; i++)
    {
        if (i == index)
            continue;

        memcpy(pBuffer + pos, &pData->pEmp[i], sizeof(EMPLOYEE));
        pos += sizeof(EMPLOYEE);
    }

    if (pData->pEmp)
    {
        free(pData->pEmp);
        pData->pEmp = NULL;
    }

    pData->pEmp = (EMPLOYEE*)pBuffer;
    pData->lEmpSize = lNewSize;

    WriteToFile(EMPLOYEE_FILE, pData->pEmp, pData->lEmpSize);

    return RES_SUCCESS;
}