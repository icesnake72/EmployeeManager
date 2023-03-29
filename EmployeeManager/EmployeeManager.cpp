#include "EmployeeManager.h"

// 인사관리
// 기본적인 C.R.U.D 구현
// Create : Input Data & Write To File
// Read : Read From File
// Update : Update Data To File
// Delete : Delete Data In File

int main()
{
	// 파일로부터 부서, 직급, 사원정보를 읽어보고..
	// 만약 파일이 없으면 첫번째 데이터를 입력받도록 한다.
	/*if (!ReadFromFile())
		inputBuseo();*/


	// Read, Write, Append

	FILE* fp = NULL;
	//fp = fopen("myfile.dat", "w+t");
	errno_t err_code = fopen_s(&fp, "myfile.txt", "w+t");
	if (fp && !err_code)
	{
		// fwrite의 파라미터들:
		// 첫번째 : Write할 데이터가 들어있는 버퍼
		// 두번째 : element Size, 
		// const char *myData[] = { "Hello", "How are you", "This is C Language" };
		const char myData[] = "Hello\nThis is C Language";
		size_t ret = fwrite(myData, sizeof(char), sizeof(myData), fp);
		if (ret < sizeof(myData))
		{
			printf("파일에 쓰는도 중 오류 발생!!!");
		}

		fclose(fp);
		fp = NULL;
	}


	err_code = fopen_s(&fp, "myfile.txt", "r+t");
	if (fp && !err_code)
	{
		char myData[50] = { 0 };		
		size_t ret = fread(myData, sizeof(char), sizeof(myData), fp);
		if (!ret)
		{
			printf("fread()에서 오류가 발생했습니다.");
		}
		else
		{
			printf("%s", myData);
		}


		fclose(fp);
		fp = NULL;
	}

	

	SIHUM_JUMSU	myJumsu;
	strcpy_s(myJumsu.name, "유재석");
	myJumsu.hakbun = 1;
	myJumsu.subs[0] = 90;
	myJumsu.subs[1] = 90;
	myJumsu.subs[2] = 90;
	myJumsu.subs[3] = 90;
	for (int i = 0; i < 4; i++)
	{
		myJumsu.tot += myJumsu.subs[i];
	}

	myJumsu.avg = myJumsu.tot / 4.0;

	err_code = fopen_s(&fp, "sihumjumsu.dat", "w+b");
	if (fp && !err_code)
	{
		size_t ret = fwrite(&myJumsu, sizeof(SIHUM_JUMSU), 1, fp);
		if (ret < 1)
		{
			printf("fread()에서 오류가 발생했습니다.");
		}

		fclose(fp);
		fp = NULL;
	}

	memset(&myJumsu, 0, sizeof(SIHUM_JUMSU));
	err_code = fopen_s(&fp, "sihumjumsu.dat", "r+b");
	if (fp && !err_code)
	{
		size_t ret = fread(&myJumsu, sizeof(SIHUM_JUMSU), 1, fp);
		if (ret < 1)
		{
			printf("fread()에서 오류가 발생했습니다.");
		}

		printf("학번 : %d\n", myJumsu.hakbun);
		printf("이름 : %s\n", myJumsu.name);
		printf("국어 : %d\n", myJumsu.subs[0]);
		printf("수학 : %d\n", myJumsu.subs[1]);
		printf("과학 : %d\n", myJumsu.subs[2]);
		printf("영어 : %d\n", myJumsu.subs[3]);
		printf("총점 : %d\n", myJumsu.tot);
		printf("평균 : %.3f\n", myJumsu.avg);

		fclose(fp);
		fp = NULL;
	}


	SIHUM_JUMSU arrJumsu[3];

	// arrJumsu 구조체의 데이터를 입력받는 함수를 만들어주세요. (두가지 방법다 옳습니다.)
	myJumsu = inputSihumJumsu();
	printf("학번 : %d\n", myJumsu.hakbun);
	printf("이름 : %s\n", myJumsu.name);
	printf("국어 : %d\n", myJumsu.subs[0]);
	printf("수학 : %d\n", myJumsu.subs[1]);
	printf("과학 : %d\n", myJumsu.subs[2]);
	printf("영어 : %d\n", myJumsu.subs[3]);
	printf("총점 : %d\n", myJumsu.tot);
	printf("평균 : %.3f\n", myJumsu.avg);

	//
	inputSihumJumsu(&myJumsu);
	printf("학번 : %d\n", myJumsu.hakbun);
	printf("이름 : %s\n", myJumsu.name);
	printf("국어 : %d\n", myJumsu.subs[0]);
	printf("수학 : %d\n", myJumsu.subs[1]);
	printf("과학 : %d\n", myJumsu.subs[2]);
	printf("영어 : %d\n", myJumsu.subs[3]);
	printf("총점 : %d\n", myJumsu.tot);
	printf("평균 : %.3f\n", myJumsu.avg);


	// 총 3명의 시험점수 데이터를 입력받아 1차원 배열에 저장해주세요.


	return 0;
}