#include <string>
#include "Station.h"
#include <iostream>



void Station::setName(std::string name) {
	this->name = name;
}
void Station::setCountWorkshop(int countWorkshop) {
	if (countWorkshop >= 0) {
		this->countWorkshop = countWorkshop;
	}
}
void Station::setCountActiveWorkshop(int countActiveWorkshop) {
	if (countActiveWorkshop >= 0) {
		this->countActiveWorkshop = countActiveWorkshop;
	}
}
void Station::setEfficiency(int efficiency) {
	if (efficiency >= 0) {
		this->efficiency = efficiency;
	}
}
std::string Station::getName() {
	return this->name;
}
int Station::getCountWorkshop() {
	return this->countWorkshop;
}
int Station::getCountActiveWorkshop() {
	return this->countActiveWorkshop;
}
int Station::getEfficiency() {
	return this->efficiency;
}
void Station::inputForEnterName()
{
	std::string name;
	std::cout << "Введите название станции: ";
	std::cin >> name;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(12321313, '\n');
		inputForEnterName();
	}
	setName(name);
}

void Station::inputForEnterCountWorkshop()
{
	int countWorkshop;
	std::cout << "Введите количество цехов: ";
	std::cin >> countWorkshop;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(12321313, '\n');
		inputForEnterCountWorkshop();
	}
	setCountWorkshop(countWorkshop);
}

void Station::inputForEntertCountActiveWorkshop()
{
	int countActiveWorkshop;
	std::cout << "Введите количество активных цехов: ";
	std::cin >> countActiveWorkshop;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(12321313, '\n');
		inputForEntertCountActiveWorkshop();
	}
	setCountActiveWorkshop(countActiveWorkshop);
}

void Station::inputForEnterEfficiency()
{
	int efficiency;
	std::cout << "Введите показатель эффективности: ";
	std::cin >> efficiency;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(12321313, '\n');
		inputForEnterEfficiency();
	}
	setEfficiency(efficiency);
}
void Station::print() {
	if (getName() == "") {
		std::cout << "Ошибка, станция не найдена" << std::endl;
		return;
	}
	std::cout << "Станция" << std::endl;
	std::cout << " Название: " << getName() << std::endl;
	std::cout << " Количество цехов: " << getCountWorkshop() << std::endl;
	std::cout << " Количество рабочих цехов: " << getCountActiveWorkshop() << std::endl;
	std::cout << " Эффективность: " << getEfficiency() << std::endl;
}