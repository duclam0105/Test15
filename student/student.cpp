#include "student.h"

extern set<string> listID;

//STUDENT FUNCTION
void student::setID(const string& id)					{ this->id = id; }
void student::setName(const string& name)				{ this->name = name; }
void student::setDate(const string& date)				{ this->date = date; }
void student::setEntryYear(const int& year)				{ this->entryYear = year; }
void student::setGradeEntry(const float& grade)			{ this->gradeEntry = grade; }
void student::setType(const typestudent& type)			{ this->type = type; }
string student::getID()									{ return this->id; }
string student::getName()								{ return this->name; }
string student::getData()								{ return this->date; }
int student::getEntryYear()								{ return this->entryYear; }
float student::getGradeEntry()							{ return this->gradeEntry; }
typestudent student::getType()							{ return this->type; }

void student::addResult() {
	Ketquahoctap* p(new Ketquahoctap);
	p->insertResult();
	p->showResult();
	vs.push_back(p);
	int tmp;
	cout << "Nhap them? 1-Yes - 0-No: ";
	cin >> tmp;
	if (tmp == yes) {
		student::addResult();
	}
}

void student::showResult() {
	if (vs.empty()) {
		cout << "Student has no result to show!\n";
		return;
	}
	for (int i = 0; i < vs.size(); i++) {
		cout << i + 1 << ". ";
		vs[i]->showResult();
	}
}

void student::showResultBySemester() {
	int count = 0;
	string tmp_semester;
	cout << "Nhap hoc ki: ";
	cin >> tmp_semester;
	for (int i = 0; i < vs.size(); i++) {
		if (vs[i]->getSemester() == tmp_semester) {
			count++;
			cout << i + 1 << ". ";
			vs[i]->showResult();
		}
	}
	if (count == 0) {
		cout << "Khong co du lieu ket qua hoc tap cua ki " << tmp_semester << endl;
		return;
	}
}

void student::insertData() {
	string tmp_id, tmp_name, tmp_date;
	do {
		cout << "ID: ";
		cin >> tmp_id;
		/*cout << tmp_id;*/
		if (tmp_id == "0") break;
	} while ((!checkValidID(tmp_id)) || (!checkSameID(listID, tmp_id)));
	listID.insert(tmp_id);
	this->id = tmp_id;
	cin.ignore();
	do {
		cout << "Name: ";
		getline(cin, tmp_name);
		chuanhoaTen(tmp_name);
		if (tmp_name == "0") break;
	} while (!checkValidName(tmp_name));
	this->name = tmp_name;
	do {
		cout << "Date: ";
		cin >> tmp_date;
		if (tmp_date == "0") break;
	} while (!checkValidDate(tmp_date));
	this->date = tmp_date;
	cout << "Entry Year: ";
	string tmp = tmp_id.substr(0, 4);				//Entry year is auto set base on ID; VD: ID: 20174004 -> entry year: 2017
	cout << tmp << endl;
	this->entryYear = stoi(tmp);
	/*cin >> this->entryYear;*/
	cout << "Grade Entry: ";
	cin >> this->gradeEntry;
}

void student::showInfo() {
	cout << "ID: " << id << " - Name: " << name << " - Date: " << date << " - Entry Year: " << entryYear << " - Grade Entry: " << gradeEntry;
}