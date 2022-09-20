
class Station {
private:
	std::string name;
	int countWorkshop;
	int countActiveWorkshop;
	int efficiency;

public:
	Station();
	void setName(std::string name);
	void setCountWorkshop(int countWorkshop);
	void setCountActiveWorkshop(int countActiveWorkshop);
	void setEfficiency(int efficiency);
	std::string getName();
	int getCountWorkshop();
	int getCountActiveWorkshop();
	int getEfficiency();
	void inputForEnterName();
	void inputForEnterCountWorkshop();
	void inputForEntertCountActiveWorkshop();
	void inputForEnterEfficiency();
	void print();
	void updateStation(int action);
	bool valid();
};
