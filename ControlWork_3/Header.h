#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <locale.h>
#include "Struct.h"
#include <iostream>
using namespace std;
const int WIDTH = 20, HEIGHT = 20;


void CountOfString(FILE * file, int * count);
void CodesToStruct(char * buffer, Goods * item, long * length);
int LogIn(char * login);
int CheckLogin(FILE * file, char * login);
int CheckPassword(FILE * file, char * login);
int Password(FILE * file, char * login);
int PasswordResult(FILE * file, char * login);
void NewClientLogin(FILE * file, char * login);
int GoodsMenu(char * login);
int GoodsNumbReturn(char * login);
void CountOfChar(FILE * file, long * countOfChar);
void FromFileToArr(char * arr, FILE * file, long* length);
void NameToStruct(char * arr, Goods * goods, long * countofChar);
void RetailtPriceToStruct(char * arr, Goods * goods, long * countofChar);
void WholeSalePriceToStruct(char * arr, Goods * goods, long * countofChar);
int CodeSearching(Goods * goods, int *code, int * countofStrings, int * index);
int GoodsChoosing(Goods * goods, int * code, int * countofStrings, int * index, int * triesCount);
void StructPrint(Goods *goods, int * countofStrings);
void FromArrToBasket(Basket * basket, int *globalIndex, Goods * goods, int * countOfGoodsInBasket, int * countofStrings);
int MenuMain(char * login, int *AllBusketCount, AllBasket * allbasket);
int OrderForm(Basket * basket, int * countOfGoodsInBasket, long * sum);
void FromOneBusketToAnother(AllBasket * allbasket, Basket * basket, int * countofGoodsinBasket, int * countInAllBasket);
void copy_board(int board1[HEIGHT + 2][WIDTH + 2], int board2[HEIGHT + 2][WIDTH + 2]);
void new_generation(int board[HEIGHT + 2][WIDTH + 2]);
void display_board(int board[HEIGHT + 2][WIDTH + 2]);
int OrderForm(AllBasket * basket, int * countOfGoodsInBasket, long * sum);
