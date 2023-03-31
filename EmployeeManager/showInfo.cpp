#include "showInfo.h"

void showMenu()
{
    system("cls");  // msc에서만 가능, 화면 클리어 해주는 함수입니다.

    printf("1. 직원 정보 보기\n");
    printf("2. 직원 정보 입력\n");
    printf("3. 직원 정보 수정\n");
    printf("4. 직원 정보 삭제\n");
    printf("============================\n");
    printf("5. 부서 정보 보기\n");
    printf("6. 부서 정보 입력\n");
    printf("7. 부서 정보 수정\n");
    printf("8. 부서 정보 삭제\n");
    printf("============================\n");
    printf("9  직급 정보 보기\n");
    printf("0. 직급 정보 입력\n");
    printf("a. 직급 정보 수정\n");
    printf("b. 직급 정보 삭제\n");
    printf("============================\n");
    printf("x. 종료\n");
    printf("============================\n");
    printf("원하시는 메뉴를 선택하세요\n");
}

void showSubMenu()
{
    printf("\n");
    printf("메뉴보기(m)\n");
}


void showEmployee(EMPLOYEE_DATA *pData)
{
    system("cls");

    EMPLOYEE* pEmp = pData->pEmp;
    BUSEO* pbu = pData->pbu;
    JIKGUEP* pji = pData->pji;

    printf("사번\t이름\t\t부서\t\t직급\n");
    printf("==============================================================================\n");
    if (pEmp == NULL)
    {
        printf("직원정보가 없습니다.\n");
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