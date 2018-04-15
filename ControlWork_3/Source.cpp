#include "Header.h"


// итак, короткое описание того что НЕ получилось:

// иногда, не знаю по какой причине выдает ошибку при system("cls")
// иногда просто пропускает функцию ввода символов в связи с этим может закрыться))
// не доделал историю покупок и при регистрации как админ выходит только надпись режим бога ))
//во всём остальном работает на ура....=)


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
			printf("Режим бога включен\n");
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
	printf("Заходите ещё\n");
	system("pause");
}