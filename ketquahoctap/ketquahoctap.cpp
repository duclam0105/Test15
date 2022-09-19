#include "ketquahoctap.h"

void Ketquahoctap::setSemester(string semester)			{ this->semester = semester; }
void Ketquahoctap::setGPA(float grade)					{ this->gpa = grade; }
string Ketquahoctap::getSemester()						{ return this->semester; }
float Ketquahoctap::getGPA()							{ return this->gpa; }
void Ketquahoctap::insertResult() {
	cout << "Semester: ";
	cin >> this->semester;
	cout << "GPA: ";
	cin >> this->gpa;
}
void Ketquahoctap::showResult() {
	cout << "Semester: " << this->semester << " - GPA: " << this->gpa << endl;
}