#include "EmployeeManager.h"

// �λ����
// �⺻���� C.R.U.D ����
// Create : Input Data & Write To File
// Read : Read From File
// Update : Update Data To File
// Delete : Delete Data In File

int main()
{
	// ���Ϸκ��� �μ�, ����, ��������� �о��..
	// ���� ������ ������ ù��° �����͸� �Է¹޵��� �Ѵ�.
	/*if (!ReadFromFile())
		inputBuseo();*/


	// Read, Write, Append

	FILE* fp = NULL;
	//fp = fopen("myfile.dat", "w+t");
	errno_t err_code = fopen_s(&fp, "myfile.txt", "w+t");
	if (fp && !err_code)
	{
		// fwrite�� �Ķ���͵�:
		// ù��° : Write�� �����Ͱ� ����ִ� ����
		// �ι�° : element Size, 
		// const char *myData[] = { "Hello", "How are you", "This is C Language" };
		const char myData[] = "Hello\nThis is C Language";
		size_t ret = fwrite(myData, sizeof(char), sizeof(myData), fp);
		if (ret < sizeof(myData))
		{
			printf("���Ͽ� ���µ� �� ���� �߻�!!!");
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
			printf("fread()���� ������ �߻��߽��ϴ�.");
		}
		else
		{
			printf("%s", myData);
		}


		fclose(fp);
		fp = NULL;
	}

	

	SIHUM_JUMSU	myJumsu;
	strcpy_s(myJumsu.name, "���缮");
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
			printf("fread()���� ������ �߻��߽��ϴ�.");
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
			printf("fread()���� ������ �߻��߽��ϴ�.");
		}

		printf("�й� : %d\n", myJumsu.hakbun);
		printf("�̸� : %s\n", myJumsu.name);
		printf("���� : %d\n", myJumsu.subs[0]);
		printf("���� : %d\n", myJumsu.subs[1]);
		printf("���� : %d\n", myJumsu.subs[2]);
		printf("���� : %d\n", myJumsu.subs[3]);
		printf("���� : %d\n", myJumsu.tot);
		printf("��� : %.3f\n", myJumsu.avg);

		fclose(fp);
		fp = NULL;
	}


	SIHUM_JUMSU arrJumsu[3];

	// arrJumsu ����ü�� �����͸� �Է¹޴� �Լ��� ������ּ���. (�ΰ��� ����� �ǽ��ϴ�.)
	myJumsu = inputSihumJumsu();
	printf("�й� : %d\n", myJumsu.hakbun);
	printf("�̸� : %s\n", myJumsu.name);
	printf("���� : %d\n", myJumsu.subs[0]);
	printf("���� : %d\n", myJumsu.subs[1]);
	printf("���� : %d\n", myJumsu.subs[2]);
	printf("���� : %d\n", myJumsu.subs[3]);
	printf("���� : %d\n", myJumsu.tot);
	printf("��� : %.3f\n", myJumsu.avg);

	//
	inputSihumJumsu(&myJumsu);
	printf("�й� : %d\n", myJumsu.hakbun);
	printf("�̸� : %s\n", myJumsu.name);
	printf("���� : %d\n", myJumsu.subs[0]);
	printf("���� : %d\n", myJumsu.subs[1]);
	printf("���� : %d\n", myJumsu.subs[2]);
	printf("���� : %d\n", myJumsu.subs[3]);
	printf("���� : %d\n", myJumsu.tot);
	printf("��� : %.3f\n", myJumsu.avg);


	// �� 3���� �������� �����͸� �Է¹޾� 1���� �迭�� �������ּ���.


	return 0;
}