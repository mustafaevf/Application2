
class Pipe {
private:
	int length;
	int diametr;
	bool inRepair;


public:
	int getLength();
	int getDiametr();
	bool getInRepair();
	void setLength(int length);
	void setDiametr(int diametr);
	void setInRepair(bool inRepair);
	void inputForEnterLength();
	void inputForEnterDiametr();
	void inputForEnterInRepair();
	void print();
};

