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
	std::cout << "������� ����� �����: ";
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
	std::cout << "������� ������� �����: ";
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
	std::cout << "� ������: ";
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
		std::cout << "������, ����� �� �������" << std::endl;
		return;
	}
	std::cout << "�����" << std::endl;
	std::cout << " �����: " << getLength() << " �" << std::endl;
	std::cout << " �������: " << getDiametr() << " �" << std::endl;
	std::cout << " � �������: " << getInRepair() << std::endl;
}