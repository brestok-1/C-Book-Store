#include <bits/stdc++.h>
#include "struct.h"
#include "funcs.h"
#include "funcs.cpp"



using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	ifstream istore;
	char storeFileName[20];
	cout << "Введите название файла, содержащего данные о магазине в формате FileName.dat: ";
	cin >> storeFileName;
	istore.open(storeFileName);
	char storeName[20], storeNumber[20], storeAddress[20], booksFileName[20];
	if (istore.is_open())
	{
		istore.read(storeName, 20);
		istore.read(storeNumber, 20);
		istore.read(storeAddress, 20);
		istore.read(booksFileName, 20);
	}
	else
	{
		cout << "Файл с таким именем не был найден, он будет создан\n";
		cout << "Введите название магазина: ";
		cin >> storeName;
		cout << "Введите номер магазина: ";
		cin >> storeNumber;
		cout << "Введите адрес магазина: ";
		cin >> storeAddress;
		cout << "Введите имя файла, в котором хранится информация об имеющихся книгах в формате FileName.dat: ";
		cin >> booksFileName;
	}
	istore.close();

	int amount = 0;
	book books[100];

	ifstream ibooks;
	ibooks.open(booksFileName);
	if (ibooks.is_open())
	{
		ibooks.read((char*)&amount, sizeof(int));
		for (int i = 0; i < amount; ++i)
			ibooks.read((char*)&books[i], sizeof(book));
	}
	else
		cout << "Файл с этим именем не был найден, он будет создан";
	ibooks.close();

	while (true)
	{
		bool isEnd = 0;

		cout << "\nВыберите пункт меню:\n";
		cout << "1. Редактирование данных магазина\n";
		cout << "2. Выдача справки\n";
		cout << "3. Продажа книги\n";
		cout << "4. Поступление новых книг\n";
		cout << "5. Поиск требуемой книги\n";
		cout << "6. Сортировка\n";
        cout << "7. Выход из программы\n";

		int key;
		cin >> key;
		switch (key)
		{
		case 1:
			changeStoreData(storeName, storeNumber, storeAddress, booksFileName);
			break;
		case 2:
			printAll(books, amount);
			break;
		case 3:
			SellBook(books, &amount);
			break;
		case 4:
			addBook(books, &amount);
			break;
		case 5:
			searchForBook(books, amount);
			break;
        case 6:
			sortbook(books, amount);
			break;
		case 7:
			isEnd = 1;
			break;
		default:
			cout << "Введено неверное значение\n";
			break;
		}

		if (isEnd)
			break;
	}

	ofstream ostore;
	ostore.open(storeFileName);
	ostore.write(storeName, 20);
	ostore.write(storeNumber, 20);
	ostore.write(storeAddress, 20);
	ostore.write(booksFileName, 20);
	ostore.close();

	ofstream obooks;
	obooks.open(booksFileName);
	obooks.write((char*)&amount, sizeof(int));
	for (int i = 0; i < amount; ++i)
		obooks.write((char*)&books[i], sizeof(book));
	obooks.close();
	return 0;
}