#include "regularStudent.h"

extern set<string> listID;

void regularStudent::insertData() {
	student::insertData();
	setType(regular_s);
}

void regularStudent::showInfo() {
	student::showInfo();
	cout << endl;
}