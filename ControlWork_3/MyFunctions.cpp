#include "Header.h"
using namespace std;

int MenuMain(char * login, int *AllBusketCount, AllBasket * allbasket)
{
	FILE * file;
	errno_t err;
	Goods * goods;
	long sum = 0;
	
	/*int loginResult = LogIn(login);
	switch (loginResult)
	{
	case 0:
	{
		system("cls");
		printf("Режим бога включен\n");
	} break;
	case 1:
	{*/
		err = fopen_s(&file, "login.txt", "r");
		if (err != 0)
		{
			perror("Error");
			system("pause");
			exit(1);
		}
		PasswordResult(file, login); // возвращает 1 если вход выполнен
		fclose(file);


		int res = GoodsMenu(login);
		int countOfStrings = 0;
		long countOfChar = 0;
		char *arrGoods;
		switch (res)
		{
		case Laptops:
		{
			countOfStrings = 0;
			countOfChar = 0;
			err = fopen_s(&file, "laptops.txt", "r");
			if (err != 0)
			{
				perror("Error");
				system("pause");
				exit(1);
			}
			CountOfString(file, &countOfStrings);
			CountOfChar(file, &countOfChar);
			arrGoods = (char*)calloc(countOfChar, sizeof(char));
			if (arrGoods == NULL)
			{
				perror("Error");
				system("pause");
				exit(1);
			}
			FromFileToArr(arrGoods, file, &countOfChar);
			fclose(file);

			goods = (Goods*)calloc(countOfStrings, sizeof(Goods));
			if (goods == NULL)
			{
				perror("Error");
				system("pause");
				exit(1);
			}
			countOfStrings -= 2;

			CodesToStruct(arrGoods, goods, &countOfChar);
			NameToStruct(arrGoods, goods, &countOfChar);
			RetailtPriceToStruct(arrGoods, goods, &countOfChar);
			WholeSalePriceToStruct(arrGoods, goods, &countOfChar); // всё работает
			int code = 0;
			int countOfGoodsInBasket = 0;
			int localIndex = 0;
			int *globalIndex;
			globalIndex = (int*)calloc(1, sizeof(int));
			if (globalIndex == NULL)
			{
				perror("Error");
				system("pause");
				free(goods);
				exit(1);
			}

			int TriesCount = 0;
			int z = 0;
			StructPrint(goods, &countOfStrings);
			while (GoodsChoosing(goods, &code, &countOfStrings, &localIndex, &TriesCount) != 0)
			{
				countOfGoodsInBasket++;
				globalIndex = (int*)realloc(globalIndex, (countOfGoodsInBasket + 1) * sizeof(int));
				globalIndex[z] = localIndex;
				z++;
			}
			// после того как функция выше равна нулю мы идем к баскету
			Basket *basket;
			basket = (Basket*)calloc(countOfGoodsInBasket, sizeof(Basket));
			if (basket == NULL)
			{
				printf("Ошибка при вызове функции calloc для basket\n");
				system("pause");
				exit(1);
			}
			FromArrToBasket(basket, globalIndex, goods, &countOfGoodsInBasket, &countOfStrings);

			free(arrGoods);
			if (countOfGoodsInBasket == 0)
			{
				printf("Товар не был добавлен\nДля выхода введите 0\nДля возврата в меню выбора товара введите 1\n----> ");
				scanf_s("%d", &z);
				switch (z)
				{
				case 1:
				{
					system("cls");
					return 1;
				} break;
				case 0:
				{
					system("cls");
					printf("До скоро встречи\n");
					free(basket);
					return 0;
					//free(goods);
				} break;
				}
			}
			long sumLocal = 0;

			allbasket = (AllBasket*)realloc(allbasket, (countOfGoodsInBasket + 1) * sizeof(AllBasket));
			FromOneBusketToAnother(allbasket, basket, &countOfGoodsInBasket, AllBusketCount);

			printf("Хотите ещё добавить товар в корзину? (1 - для подтверждения)\n");
			printf("Хотите оформить заказ? (2 - для подтверждения)\n");
			printf("Хотите отменить заказ и выйти? (3 - для подтверждения)\n ---->");
			int decision;
			scanf_s("%d", &decision);
			switch (decision)
			{
				case 1:
				{
					
					if (allbasket == NULL)
					{
						printf("Ошибка при создании allbasket\n");
						free(basket);
						free(goods);
						system("pause");
						exit(1);
					}
					
					MenuMain(login, AllBusketCount, allbasket);
				} break;
				case 2:
				{
					// написать функцию для оформления заказа
					//OrderForm(basket, &countOfGoodsInBasket, &sum);
					int ReTurn = OrderForm(allbasket, AllBusketCount, &sum);
					if (ReTurn == 1)
						return 0;
					else
						return 0;
				} break;
				case 3:
				{
					system("cls");
					free(basket);
					//free(goods);
					return 0;
				} break;
			}
			free(basket);
			free(goods);
		}
		break;
		case Cooler:
		{
			countOfStrings = 0;
			countOfChar = 0;
			err = fopen_s(&file, "cooler.txt", "r");
			if (err != 0)
			{
				perror("Error");
				system("pause");
				exit(1);
			}
			CountOfString(file, &countOfStrings);
			CountOfChar(file, &countOfChar);
			arrGoods = (char*)calloc(countOfChar, sizeof(char));
			if (arrGoods == NULL)
			{
				perror("Error");
				system("pause");
				exit(1);
			}
			FromFileToArr(arrGoods, file, &countOfChar);
			fclose(file);

			goods = (Goods*)calloc(countOfStrings, sizeof(Goods));
			if (goods == NULL)
			{
				perror("Error");
				system("pause");
				exit(1);
			}
			countOfStrings -= 2;

			CodesToStruct(arrGoods, goods, &countOfChar);
			NameToStruct(arrGoods, goods, &countOfChar);
			RetailtPriceToStruct(arrGoods, goods, &countOfChar);
			WholeSalePriceToStruct(arrGoods, goods, &countOfChar); // всё работает
			int code = 0;
			int countOfGoodsInBasket = 0;
			int localIndex = 0;
			int *globalIndex;
			globalIndex = (int*)calloc(1, sizeof(int));
			if (globalIndex == NULL)
			{
				perror("Error");
				system("pause");
				free(goods);
				exit(1);
			}

			int TriesCount = 0;
			int z = 0;
			StructPrint(goods, &countOfStrings);
			while (GoodsChoosing(goods, &code, &countOfStrings, &localIndex, &TriesCount) != 0)
			{
				countOfGoodsInBasket++;
				globalIndex = (int*)realloc(globalIndex, (countOfGoodsInBasket + 1) * sizeof(int));
				globalIndex[z] = localIndex;
				z++;
			}
			// после того как функция выше равна нулю мы идем к баскету
			Basket *basket;
			basket = (Basket*)calloc(countOfGoodsInBasket, sizeof(Basket));
			if (basket == NULL)
			{
				printf("Ошибка при вызове функции calloc для basket\n");
				system("pause");
				exit(1);
			}
			FromArrToBasket(basket, globalIndex, goods, &countOfGoodsInBasket, &countOfStrings);

			free(arrGoods);
			if (countOfGoodsInBasket == 0)
			{
				printf("Товар не был добавлен\nДля выхода введите 0\nДля возврата в меню выбора товара введите 1\n----> ");
				scanf_s("%d", &z);
				switch (z)
				{
				case 1:
				{
					system("cls");
					return 1;
				} break;
				case 0:
				{
					system("cls");
					printf("До скоро встречи\n");
					free(basket);
					return 0;
					//free(goods);
				} break;
				}
			}
			long sumLocal = 0;

			allbasket = (AllBasket*)realloc(allbasket, (countOfGoodsInBasket + 1) * sizeof(AllBasket));
			FromOneBusketToAnother(allbasket, basket, &countOfGoodsInBasket, AllBusketCount);

			printf("Хотите ещё добавить товар в корзину? (1 - для подтверждения)\n");
			printf("Хотите оформить заказ? (2 - для подтверждения)\n");
			printf("Хотите отменить заказ и выйти? (3 - для подтверждения)\n ---->");
			int decision;
			scanf_s("%d", &decision);
			switch (decision)
			{
			case 1:
			{

				if (allbasket == NULL)
				{
					printf("Ошибка при создании allbasket\n");
					free(basket);
					free(goods);
					system("pause");
					exit(1);
				}

				MenuMain(login, AllBusketCount, allbasket);
			} break;
			case 2:
			{
				// написать функцию для оформления заказа
				//OrderForm(basket, &countOfGoodsInBasket, &sum);
				int ReTurn = OrderForm(allbasket, AllBusketCount, &sum);
				if (ReTurn == 1)
					return 0;
				else
					return 0;
			} break;
			case 3:
			{
				system("cls");
				free(basket);
				//free(goods);
				return 0;
			} break;
			}
			free(basket);
			free(goods);
		}break;
		case Cpu:
			break;
		case AllinOnePC:
			break;
		case Ram:
			break;
		case Ssd:
			break;
		case Videocard:
			break;
		default:
			break;
		}

		// теперь мне необходимо составить меню где покупатель выбирает товар
		// добавляет его в корзину
		//режим прайс листа

	//} break;
	//}
}

int OrderForm(Basket * basket, int * countOfGoodsInBasket, long * sum)
{
	for (int i = 0; i < *countOfGoodsInBasket; i++)
	{	
		printf("Наименование товара:\n %s\n", basket[i].name);
		printf("Сумма товара = %d\n", basket[i].cost);
		sum += basket[i].cost;
	}
	printf("Общая сумма = %d\n", sum);
	printf("Для подтверждения оплаты введите 1, Для отмены - 0\n----> ");
	int res;
	scanf_s("%d", &res);
	if (res == 1)
	{
		printf("Спасибо за покупук!!!\n");
		//system("pause");
		return 1;
	}
	else
		return 0;
}


int OrderForm(AllBasket * basket, int * countOfGoodsInBasket, long * sum)
{
	system("cls");

	for (int i = 0; i < *countOfGoodsInBasket; i++)
	{
		printf("Наименование товара:\n %s\n", basket[i].name);
		printf("Сумма товара = %d\n", basket[i].cost);
		*sum += basket[i].cost;
	}
	printf("Общая сумма = %d\n", *sum);
	printf("Для подтверждения оплаты введите 1, Для отмены - 0\n----> ");
	int res;
	scanf_s("%d", &res);
	if (res == 1)
	{
		printf("Спасибо за покупук!!!\n");
		system("pause");
		return 1;
	}
	else
		return 0;
}


void FromOneBusketToAnother(AllBasket * allbasket, Basket * basket, int * countofGoodsinBasket, int * countInAllBasket)
{
	for (int i = 0; i < *countofGoodsinBasket; i++)
	{
		allbasket[*countInAllBasket].cost = basket[i].cost;
		strcpy_s(allbasket[*countInAllBasket].name, 250, basket[i].name);
		*countInAllBasket = *countInAllBasket + 1;
	}
}

void CountOfString(FILE * file, int * count) // кол-во строк
{
	// должен прийти файл с rewind(file)
	rewind(file);
	char arr[1024];
	while (!feof(file))
	{
		fgets(arr, 1024, file);
		*count = *count + 1;
	}
}

void FromFileToArr(char * arr, FILE * file, long* length)
{
	rewind(file);
	for (long i = 0; i < *length; i++)
	{
		fscanf_s(file, "%c", &arr[i]); // заполняет как надо первый символ - \n в конце файла \n нет
	}
}


void CodesToStruct(char * buffer, Goods * item, long * countOfChar)
{
	int j = 0;
	int b = 0;
	int z = 0;
	char arr[10];
	for (long i = 0; i < *countOfChar-10; i++)
	{
		if (buffer[i] == '\n')
		{
			j = i + 1;
			b = 0;
			while (buffer[j] != '\t')
			{
				arr[b] = buffer[j];
				b++;
				j++;
			}
			item[z].code = atoi(arr);
			z++;
			j++;
			i = j;
		}
	}
}

void NameToStruct(char * arr, Goods * goods, long * countofChar)
{	
	int z = 0;
	int j = 0;
	for (long i = 0; i < *countofChar-5; i++)
	{
		if (arr[i] == '\n')
		{
			while (arr[i] != '\t')
				i++;
			i += 1;
			j = 0;
			while (arr[i] != '\t')
			{
				goods[z].name[j] = arr[i];
				j++;
				i++;
 			}
			z++;
		}
	}
}

void RetailtPriceToStruct(char * arr, Goods * goods, long * countofChar)
{
	int z = 0;
	int j = 0;
	int countTab = 0;
	char numb[10];
	for (long i = 0; i < *countofChar - 3; i++)
	{
		if (arr[i] == '\n')
		{	
			countTab = 0;
			while (countTab < 2)
			{
				if (arr[i] == '\t')
					countTab++;
				i++;
			}
			j = 0;
			while (arr[i] != '\t')
			{
				numb[j] = arr[i];
				j++;
				i++;
			}
			goods[z].retailPrice = atoi(numb);
			z++;
		}
	}
}

void WholeSalePriceToStruct(char * arr, Goods * goods, long * countofChar)
{
	int j = 0;
	int z = 0;
	int countTab = 0;
	char numb[10];
	for (long i = 0; i < *countofChar - 1; i++)
	{
		if (arr[i] == '\n')
		{
			countTab = 0;
			while (countTab < 3)
			{
				if (arr[i] == '\t')
					countTab++;
				i++;
			}
			j = 0;
			while (arr[i] != '\n')
			{
				numb[j] = arr[i];
				j++;
				i++;
			}
			goods[z].wholesalePrice = atoi(numb);
			z++;
			i -= 1;
		}
	}
}

void CountOfChar(FILE * file, long * countOfChar)
{
	rewind(file);
	while (fgetc(file) != EOF)
	{
		*countOfChar = *countOfChar + 1;
	}
}



int LogIn(char * login)
{	
	
	char admin[] = "admin\n";
	char NewClient[] = "newclient\n";
	printf("Добро пожаловать к нам в магазин\nВведите NewClient если Вы новый пользователь и хотите зарегестрироваться\n");
	printf("Или введите свой логин, если уже зарегестрированны\n ---> ");
	fgets(login, 20, stdin);
	int length = strlen(login);
	for (int j = 0; j < length; j++)
	{
		login[j] = tolower(login[j]);
	}
	if(strcmp(login, admin) == 0)
		return 0;
	if (strcmp(login, NewClient) == 0)
	{	
		FILE * file;
		errno_t err;
		printf("Спасибо чтоб выбрали нас\n");
		err = fopen_s(&file, "login.txt", "a+");
		NewClientLogin(file, login);
		printf("Поздравляю, Вы зарегестрированы!!!\nТеперь Вам необходимо ввойти в свой логин\n");
		system("pause");
		fclose(file);
		system("cls");
		return 1;
	}
	else
		return 1;
}

//регистрация нового пользователя
void NewClientLogin(FILE * file, char * login)
{
	printf("Введите имя пользователя: ");
	char name[20];
	int check = 1;
	do
	{
		fgets(name, 20, stdin);
		check = CheckLogin(file, name);
		if (check == 1)
			printf("Данное имя уже занято.\nВведите ещё раз\n");
	} while (check != 0);
	int length = strlen(name);
	for (int i = 0; i < length; i++)
	{
		name[i] = tolower(name[i]);
		fprintf(file, "%c", name[i]);
	}
	for (int i = 0; i <= strlen(name); i++)
	{
		login[i] = name[i];
	}
	printf("Введите пароль: ");
	fgets(name, 20, stdin);
	fprintf(file, "%s", name);
	system("Pause");
}

int CheckLogin(FILE * file, char * login) // проверяет есть ли такой логин
{	
	char name[20];
	rewind(file);
	while (!feof(file))
	{
		fgets(name, 20, file);
		
		if (strcmp(name, login) == 0)
			return 1;
	}
	return 0;
}

int CheckPassword(FILE * file, char * login) // проверяет пароль пользователя
{
	char password[20];
	fgets(password, 20, stdin);
	rewind(file);
	char name[20];
	while (!feof(file))
	{
		fgets(name, 20, file);

		if (strcmp(name, login) == 0)
		{
			while (!feof(file))
			{
				fgets(name, 20, file);
				if (strcmp(name, password) == 0)
					return 1;
				else
					return 0;
			}
		}
	}
}

int Password(FILE * file, char * login)
{	
	int count = 3;
	int CheckLoginRes = CheckLogin(file, login);
	int CheckPasswordRes = 0;
	if (CheckLoginRes == 1)
	{
		while (count != 0)
		{
			printf("Введите пароль (кол-во попыток осталось - %d\n---> ", count);
			CheckPasswordRes = CheckPassword(file, login);
			if (CheckPasswordRes == 1)
				return 1;
			count--;
		}
		if (count == 0)
		{
			return 0;
		}
	}
	else if (CheckLoginRes == 0)
		return 0;

	printf("%d\n", CheckPasswordRes);
}

int PasswordResult(FILE * file, char * login)
{
	int passRes = Password(file, login);
	if (passRes == 1)
	{
		system("cls");
		printf("Пароль введен успешно\n");
		system("pause");
		return 1;
	}
	else
	{
		printf("Вы превысили кол-во попыток\nЗавершение программы\n");
		system("pause");
		fclose(file);
		exit(1);
	}
}

int GoodsNumbReturn(char * login)
{
	printf("Введите номер, соответствующий номеру последовательности товара\n ---> ");
	int numb;
	scanf_s("%d", &numb);
	switch (numb)
	{
	case Laptops: return 1;
		break;
	case Cooler: return 2;
		break;
	case Cpu: return 3;
		break;
	case AllinOnePC: return 4;
		break;
	case Ram: return 5;
		break;
	case Ssd: return 6;
		break;
	case Videocard: return 7;
		break;
	default: return 0;
		break;
	}
}

int GoodsMenu(char * login)
{	
	system("cls");
	printf("Добро пожаловать к нам в магазин\n");
	printf("Мы можем предложить Вам следующий ассортимент товара:\n");
	FILE * file;
	errno_t err = fopen_s(&file, "Goods.txt", "r");
	if (err != 0)
	{
		perror("Error");
		exit(1);
	}
	fseek(file, 0, SEEK_END);
	long lSize = ftell(file);
	rewind(file);
	char * arr = (char*)calloc(lSize, sizeof(char));
	int i = 0;
	while (!feof(file))
	{
		fscanf_s(file, "%c", &arr[i]);
		printf("%c", arr[i]);
		i++;
	}
	fclose(file);
	free(arr);

	printf("Введите номер, соответствующий номеру последовательности товара\n ---> ");
	int numb;
	scanf_s("%d", &numb);
	switch (numb)
	{
	case Laptops: return 1;
		break;
	case Cooler: return 2;
		break;
	case Cpu: return 3;
		break;
	case AllinOnePC: return 4;
		break;
	case Ram: return 5;
		break;
	case Ssd: return 6;
		break;
	case Videocard: return 7;
		break;
	default: return 0;
		break;
	}

	system("pause");
}

void StructPrint(Goods *goods, int * countofStrings)
{	
	printf("Код товара:\tНаименование:\t\t\t\t\t\tСтоимость:\n");
	for (int i = 0; i < *countofStrings; i++)
	{
		printf("%d\t%s\t%d\n", goods[i].code, goods[i].name, goods[i].retailPrice);
	}
}

int GoodsChoosing(Goods * goods, int * code, int * countofStrings, int * index, int * triesCount)
{
	
	printf("Введите код товара для добавления его в корзину\nИли введите 0 для выхода\n---> ");
	scanf_s("%d", code);
	if (*code == 0)
		return 0;
	int res = CodeSearching(goods, code, countofStrings, index);
	if (res == 0)
	{	
		*triesCount = *triesCount + 1;;
		if (*triesCount == 3)
			return 0;
		printf("Вы ввели неверный код\nПопробуйте ещё раз\n");
		system("pause");
		GoodsChoosing(goods, code, countofStrings, index, triesCount);
	}
	else
	{	
		return 1;
	}
}

int CodeSearching(Goods * goods, int *code, int * countofStrings, int * index)
{
	for (int i = 0; i < *countofStrings; i++)
	{
		if (goods[i].code == *code)
		{
			*index = i;
			return 1;
		}
			
	}
	return 0;
}

void FromArrToBasket(Basket * basket, int *globalIndex, Goods * goods, int * countOfGoodsInBasket, int * countofStrings)
{	
	int j = 0;
	int z = 0;
	int copyCountGoodsinBasket = *countOfGoodsInBasket;
	while (copyCountGoodsinBasket != 0)
	{
		for (int i = 0; i < *countofStrings; i++)
		{
			if (i == globalIndex[j])
			{
				basket[z].cost = goods[i].retailPrice;
				strcpy_s(basket[z].name, 250, goods[i].name);
			//	strcpy(basket[z].name, goods[i].name);
				copyCountGoodsinBasket--;
				z++;
				j++;
			}
		}
	}
	
}

