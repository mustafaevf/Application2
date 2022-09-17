#include "Pipe.h"
#include <iostream>



int Pipe::getLength() {
	return this->length;
}

int Pipe::getDiametr() {
	return this->diametr;
}

bool Pipe::getInRepair() {
	return this->inRepair;
}

void Pipe::setLength(int length) {
	if (length >= 0) {
		this->length = length;
	}
}

void Pipe::setDiametr(int diametr) {
	if (diametr >= 0) {
		this->diametr = diametr;
	}
}
void Pipe::setInRepair(bool inRepair) {
	this->inRepair = inRepair;
}

void Pipe::inputForEnterLength() {
	int length;
	std::cout << "Введите длину трубы: ";
	std::cin >> length;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(12321313, '\n');
		inputForEnterLength();
	}
	setLength(length);
}

void Pipe::inputForEnterDiametr() {
	int diametr;
	std::cout << "Введите диаметр трубы: ";
	std::cin >> diametr;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(12321313, '\n');
		inputForEnterDiametr();
	}
	setDiametr(diametr);
}

void Pipe::inputForEnterInRepair() {
	bool inRepair;
	std::cout << "В работе: ";
	std::cin >> inRepair;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(12321313, '\n');
		inputForEnterInRepair();
	}
	setInRepair(inRepair);
}
void Pipe::print() {

	if (getLength() == 0) {
		std::cout << "Ошибка, труба не найдена" << std::endl;
		return;
	}
	std::cout << "Труба" << std::endl;
	std::cout << " Длина: " << getLength() << " м" << std::endl;
	std::cout << " Диаметр: " << getDiametr() << " м" << std::endl;
	std::cout << " В ремонте: " << getInRepair() << std::endl;
}