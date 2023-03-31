#include "showInfo.h"

// 인사관리
// 기본적인 C.R.U.D 구현
// Create : Input Data & Write To File
// Read : Read From File
// Update : Update Data To File
// Delete : Delete Data In File

int main()
{
	//char* buf = NULL;
	//buf = (char *)_malloc_dbg(1024, _NORMAL_BLOCK, NULL, NULL);
	//// buf = (char*)malloc(1024);
	//if (buf == NULL)
	//{
	//	printf("메모리 할당 실패.");
	//	return 0;
	//}
	//	
	//printf("메모리할당!!!");

	//_freea_dbg(buf, _NORMAL_BLOCK);
	////free(buf);
	
	// initialize... 
	EMPLOYEE_DATA	data;
	
	data.lJikSize = (ulong)loadJikguep(&data.pji);
	data.lBuseoSize = (ulong)loadBuseo(&data.pbu);
	data.lEmpSize = (ulong)loadEmployee(&data.pEmp);
	
	showMenu();

	int selectedMenu = TERMINATE;
	do
	{
		switch (selectedMenu)
		{
		case SHOW_EMPLOYEE:
			showEmployee(&data);
			break;

		case INSERT_EMPLOYEE:
			data.lEmpSize = inputEmployee(&data.pEmp, data.lEmpSize);
			showEmployee(&data);
			break;

		case UPDATE_EMPLOYEE:
		case DELETE_EMPLOYEE:
			break;

		case SHOW_BUSEO:
			showBuseo(data.pbu, data.lBuseoSize);
			break;

		case INSERT_BUSEO:
			data.lBuseoSize = inputBuseo(&data.pbu, data.lBuseoSize);
			showBuseo(data.pbu, data.lBuseoSize);
			break;

		case UPDATE_BUSEO:
		case DELETE_BUSEO:
			break;

		case SHOW_JIKGUEP:
			showJikguep(data.pji, data.lJikSize);
			break;

		case INSERT_JIKGUEP:
			data.lJikSize = inputJikGuep(&data.pji, data.lJikSize);
			showJikguep(data.pji, data.lJikSize);
			break;

		case UPDATE_JIKGUEP:
		case DELETE_JIKGUEP:
			break;

		default:			
			break;
		}

		showMenu();

	} while ((selectedMenu = getKey()) != TERMINATE);

	if (data.pEmp)
	{
		free(data.pEmp);
		data.pEmp = NULL;
	}

	if (data.pbu)
	{
		free(data.pbu);
		data.pbu = NULL;
	}

	if (data.pji)
	{
		free(data.pji);
		data.pji = NULL;
	}
		
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

	return 0;
}