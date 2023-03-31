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
}


void showEmployee(EMPLOYEE_DATA *pData)
{
    system("cls");

    EMPLOYEE* pEmp = pData->pEmp;
    BUSEO* pbu = pData->pbu;
    JIKGUEP* pji = pData->pji;

    printf("���\t�̸�\t\t�μ�\t\t����\n");
    printf("==============================================================================\n");
    if (pEmp == NULL)
    {
        printf("���������� �����ϴ�.\n");
    }
    else
    {
        uint count = pData->lEmpSize / sizeof(EMPLOYEE);
        for (int i = 0; i < count; i++)
        {
            printf("%d\t", pData->pEmp->num);
            printf("%s\t", pData->pEmp->name);
            printf("%d\t", pData->pEmp->buseo);
            printf("%d\n", pData->pEmp->jikguep);
        }
    }
    
    showSubMenu();

    int ch = _getch();
    switch (ch)
    {
    case 'p':
    case 'P':
    case 'n':
    case 'N':
    case 'm':
    case 'M':
        return;
    }
}