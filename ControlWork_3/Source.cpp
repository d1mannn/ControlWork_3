#include "Header.h"


// ����, �������� �������� ���� ��� �� ����������:

// ������, �� ���� �� ����� ������� ������ ������ ��� system("cls")
// ������ ������ ���������� ������� ����� �������� � ����� � ���� ����� ���������))
// �� ������� ������� ������� � ��� ����������� ��� ����� ������� ������ ������� ����� ���� ))
//�� ��� ��������� �������� �� ���....=)


void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char login[20];
	FILE * file;
	errno_t err;
	Goods * goods;
	int AllBusketCount = 0;
	AllBasket * allbasket = (AllBasket*)calloc(1, sizeof(AllBasket));

	int loginResult = LogIn(login);
	switch (loginResult)
	{
		case 0:
		{
			system("cls");
			printf("����� ���� �������\n");
		} break;
		case 1:
		{
			int res;
			do
			{
				res = MenuMain(login, &AllBusketCount, allbasket);
			} while (res != 0);
		} break;
	}
	printf("�������� ���\n");
	system("pause");
}