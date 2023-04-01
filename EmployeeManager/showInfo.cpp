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
        

    printf("사번\t이름\t\t부서\t\t직급\n");
    printf("=========================================================\n");
    if (pData->pEmp == NULL)
    {
        printf("직원정보가 없습니다.\n");
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
        printf("부서정보가 없습니다.\n");        
    }
    else
    {
        printf("부서코드\t부서명\n");
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
        printf("직급정보가 없습니다.\n");
    }
    else
    {        
        printf("직급코드\t직급명\n");
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
    printf("수정할 사원번호를 입력하세요 : ");
    scanf_s("%u", &num);

    EMPLOYEE* pEmp = findEmployee(pData, num);
    if (pEmp == NULL)
        return 0;

    printf("이름을 입력하세요 : ");
    scanf_s("%s", pEmp->name, MAX_NAME);

    printf("부서코드를 입력하세요 : ");
    scanf_s("%u", &pEmp->buseo);

    printf("직급코드를 입력하세요 : ");
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
    printf("삭제할 사원번호를 입력하세요 : ");
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