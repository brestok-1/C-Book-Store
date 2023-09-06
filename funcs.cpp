#include "struct.h"
#include "funcs.h"
#include <cstring>
#include <iostream>


void changeStoreData(std::string storeName, std::string storeNumber, std::string storeAddress, std::string booksFileName)
{
	std::cout << "Введите новые данные магазина\nИмя: ";
	std::cin >> storeName;
	std::cout << "Номер: ";
	std::cin >> storeNumber;
	std::cout << "Адрес: ";
	std::cin >> storeAddress;
	std::cout << "Имя файла, в котором хранится информация об имеющихся в нем книгах (книги не перенесутся из старого файла): ";
	std::cin >> booksFileName;
}

void printAll(book books[], int amount)
{
	for (int i = 0; i < amount; ++i)
	{
		
		std::cout << "Название: " << books[i].name << std::endl;
		std::cout << "Количество: " << books[i].amount << std::endl;
		std::cout << "Цена: " << books[i].price << std::endl;
        std::cout << "Индекс: " << i + 1 << std::endl;
		std::cout << "Издательство: " << books[i].publishingHouse << std::endl << std::endl;
	}
}



void SellBook(book books[], int* amount)
{
	int toSell;
	std::cout << "Введите номер книги, которую хотите продать: ";
	std::cin >> toSell;
	--toSell;
	std::cout << "Книга продана за " << books[toSell].price;
	if (books[toSell].amount < 2)
	{
		for (int i = toSell + 1; i < *amount; ++i)
			books[i - 1] = books[i];
		--(*amount);
	}
	else
		--books[toSell].amount;
}

void addBook(book books[], int* amount)
{
	bool key;
	std::cout << "Такие книги уже имеются в коллекции магазина? (1 - да, 0 - нет): ";
	std::cin >> key;
	if (key)
	{
		std::cout << "Введите номер этой книги:";
		int toAdd;
		std::cin >> toAdd;
		--toAdd;
		++books[toAdd].amount;
	}
	else
	{
		std::cout << "Введите данные новой книги\nНазвание: ";
		std::cin >> books[*amount].name;
		std::cout << "Количество: ";
		std::cin >> books[*amount].amount;
		std::cout << "Цена: ";
		std::cin >> books[*amount].price;
		std::cout << "Издательство: ";
		std::cin >> books[*amount].publishingHouse;
		++(*amount);
        books[*amount].index = (*amount)+1;
	}
}

void searchForBook(book books[], int amount)
{
	char searchFor[20];
	std::cout << "Введите имя книги, которую хотите найти: ";
	std::cin >> searchFor;

	for (int i = 0; i < amount; ++i)
	{
		if (strcmp(books[i].name, searchFor) == 0)
		{
			std::cout << "Книга номер " << i + 1 << ":\n";
			std::cout << "Название: " << books[i].name << std::endl;
			std::cout << "Количество: " << books[i].amount << std::endl;
			std::cout << "Цена: " << books[i].price << std::endl;
            std::cout << "Цена: " << books[i].index << std::endl;
			std::cout << "Издательство: " << books[i].publishingHouse << std::endl << std::endl;
		}
	}
}

void sortbook(book books[], int amount){
    int i_sort;
    std::cout<<"Выберите поле для сортировки (0 - цена, 1 - количество)"<<std::endl; std::cin >> i_sort;
    if (i_sort == 0){
    for (int i = amount - 1; i >= 0; i--)
	{
        for(int j = 0; j< i; j++){
            if(books[j].price > books[j + 1].price){
                book tmp = books[j];
                books[j] = books[j+1];
                books[j+1] = tmp; 
            }
        }
	}}
    else{
        for (int i = amount - 1; i >= 0; i--)
	{
        for(int j = 0; j< i; j++){
            if(books[j].amount > books[j + 1].amount){
                book tmp = books[j];
                books[j] = books[j+1];
                books[j+1] = tmp; 
            }
        }
	}
    }
}