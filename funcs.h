#include "struct.h"
#include <iostream>

#ifndef __funcs_H__
#define __funcs_H__

void changeStoreData(std::string storeName, std::string storeNumber, std::string storeAddress, std::string booksFileName);
void printAll(book books[], int amount);
void SellBook(book books[], int* amount);
void addBook(book books[], int* amount);
void searchForBook(book books[], int amount);
void sortbook(book books[], int amount);

#endif