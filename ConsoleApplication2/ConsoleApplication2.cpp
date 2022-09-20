#include <iostream>
#include <string>
#include <fstream>
#include "Pipe.h"
#include "Station.h"

using namespace std;

int loop = 1;

void clearCin() {
	cin.clear();
	cin.ignore(123, '\n');
}

void validateCin()
{
	if (cin.fail()) {
		clearCin();
		return;
	}
}


void printMenu() {
	cout << "1. Добавить трубу" << endl;
	cout << "2. Добавить станцию" << endl;
	cout << "3. Просмотр всех объектов" << endl;
	cout << "4. Редактировать трубу" << endl;
	cout << "5. Редактировать станцию" << endl;
	cout << "6. Сохранить" << endl;
	cout << "7. Загрузить" << endl;
	cout << "0. Выйти" << endl;
}

void clearMenu() {
	system("cls");
}


void SaveToFile(string path, Pipe& pipe, Station& station) {
	clearMenu();
	ofstream fout;
	fout.open(path + ".txt", ofstream::trunc);
	if (fout.is_open()) {
		if (pipe.getLength() != 0 && station.getName() != "") {
			fout << pipe.getLength() << endl;
			fout << pipe.getDiametr() << endl;
			fout << pipe.getInRepair() << endl;
			fout << station.getName() << endl;
			fout << station.getCountWorkshop() << endl;
			fout << station.getCountActiveWorkshop() << endl;
			fout << station.getEfficiency() << endl;
			cout << "Файл " << path << ".txt" << " сохранен" << endl;
		}
		else {
			cout << "Ошибка сохранения. Создайте все объекты" << endl;
			
		}
		printMenu();
		
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
	fout.close();
	loop = 1;
}

void LoadFromFile(string path, Pipe& pipe, Station& station) {
	clearMenu();
	ifstream fin;
	fin.open(path + ".txt");
	if (fin.is_open()) {
		int ch;
		string name;

		for (int i = 0; i <= 6; i++) {
			if (i == 3)
			{
				fin >> name;
			}
			else {
				fin >> ch;
			}
			
			switch (i) {
			case 0:
				pipe.setLength(ch);
				break;
			case 1:
				pipe.setDiametr(ch);
				break;
			case 2:
				pipe.setInRepair(ch);
				break;
			case 3:
				station.setName(name);
				break;
			case 4:
				station.setCountWorkshop(ch);
				break;
			case 5:
				station.setCountActiveWorkshop(ch);
				break;
			case 6:
				station.setEfficiency(ch);
				break;
			}
			
		}
		cout << "Файл загружен" << endl;
		printMenu();
		
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
	fin.close();
	loop = 1;
}

void createPipe(Pipe& pipe) {
	clearMenu();
	pipe.inputForEnterLength();
	pipe.inputForEnterDiametr();
	pipe.inputForEnterInRepair();
	clearMenu();
	cout << "Труба добавлена" << endl;
	printMenu();
	loop = 1;
}

void createStation(Station& station) {
	clearMenu();
	station.inputForEnterName();
	station.inputForEnterCountWorkshop();
	station.inputForEntertCountActiveWorkshop();
	station.inputForEnterEfficiency();
	clearMenu();
	cout << "Станция добавлена" << endl;
	printMenu();
	loop = 1;
}


void updateStation(Station& station) {
	clearMenu();
	if (!station.valid()) {
		cout << "Добавте станцию" << endl;
		printMenu();
		loop = 1;
		return;
	}
	int action;
	cout << "Количество цехов: " << station.getCountWorkshop() << "\nРабочих цехов: " << station.getCountActiveWorkshop() << "\n0. Отключить\n1. Включить" << endl;
	cin >> action;
	clearMenu();
	if (action == 0)
	{
		station.updateStation(0);
	}
	else if (action == 1) {
		station.updateStation(1);
	}
	else {
		cout << "Повторите попытку" << endl;
		updateStation(station);
	}
	printMenu();
	loop = 1;
}


void updatePipe(Pipe& pipe) {
	clearMenu();
	if (!pipe.valid()) {
		cout << "Добавте трубу" << endl;
		printMenu();
		loop = 1;
		return;
	}
	int action;
	cout << "Статус трубы: " << (pipe.getInRepair() ? "true":"false") << "\n0. Отключить\n1. Включить" << endl;
	cin >> action;
	clearMenu();
	if (action == 0) {
		if (pipe.getInRepair() != 0) {
			pipe.setInRepair(0);
			cout << "Труба отключена" << endl;
		}
		else {
			cout << "Труба уже отключена" << endl;
		}
	} else if(action == 1) {
		if (pipe.getInRepair() != 1) {
			pipe.setInRepair(1);
			cout << "Труба включена" << endl;
		}
		else {
			cout << "Труба уже включена" << endl;
		}
	}
	else {
		cout << "Повторите попытку" << endl;
	}
	
	printMenu();
	loop = 1;

}

void printObjects(Pipe& pipe, Station& station) {
	clearMenu();
	pipe.print();
	station.print();
	printMenu();
	loop = 1;
}


int main() {
	setlocale(LC_ALL, "");
	Pipe pipe;
	Station station;
	clearMenu();
	printMenu();
	int menu;
	string path;
	while (loop != 0)
	{
		cout << "Введите пункт меню: ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			return 0;
			break;
		case 1:
			loop = 0;
			createPipe(pipe);			
			break;
		case 2:
			loop = 0;
			createStation(station);
			break;
		case 3:
			loop = 0;
			printObjects(pipe, station);
			break;
		case 4:
			loop = 0;
			updatePipe(pipe);
			break;
		case 5:
			loop = 0;
			updateStation(station);
			break;
		case 6:
			loop = 0;
			cout << "Введите название файла для сохранения: ";
			cin >> path;
			SaveToFile(path, pipe, station);
			break;
		case 7:
			loop = 0;
			cout << "Введите название файла для загрузки: ";
			cin >> path;
			LoadFromFile(path, pipe, station);
			break;
		default:
			return 0;
			break;
		}
	}
	return 1;
}
