#pragma once
#include "Computer.h"

class computerList
{
private:
	computer** computers; // массив компьютеров
	int count; // количество записей
	int capacity; // вместимость
public:
	computerList(int n);
	~computerList();

	void readComputers(); // Считать компьютеры
	void showComputers(); // Показать компьютеры
	void addComputer(); //добавить пк
	void deleteComputer(); //удалить пк
	void saveIntoFile(); //сохранить в файл
	

	//Задания: 
	void Price20To30();
	void TotalCost();
	void RedOrBlue();
	void SearchByType();
};