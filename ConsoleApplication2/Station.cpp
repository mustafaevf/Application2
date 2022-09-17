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
	std::cout << "������� �������� �������: ";
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
	std::cout << "������� ���������� �����: ";
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
	std::cout << "������� ���������� �������� �����: ";
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
	std::cout << "������� ���������� �������������: ";
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
		std::cout << "������, ������� �� �������" << std::endl;
		return;
	}
	std::cout << "�������" << std::endl;
	std::cout << " ��������: " << getName() << std::endl;
	std::cout << " ���������� �����: " << getCountWorkshop() << std::endl;
	std::cout << " ���������� ������� �����: " << getCountActiveWorkshop() << std::endl;
	std::cout << " �������������: " << getEfficiency() << std::endl;
}