#include "inserviceStudent.h"

extern set<string> listID;

//IN-SERVICE STUDENT FUNCTION
void inserviceStudent::setLocation(const string& location)		{ this->location = location; }
string inserviceStudent::getLocation()							{ return this->location; }

void inserviceStudent::insertData(){
	student::insertData();
	string tmp_location;
	cout << "Location Training: ";
	cin.ignore();
	getline(cin, tmp_location);
	chuanhoaTen(tmp_location);
	this->location = tmp_location;
	this->setType(inservice_s);
}

void inserviceStudent::showInfo(){
	student::showInfo();
	cout << " - Location Training: " << this->location << endl;
}
