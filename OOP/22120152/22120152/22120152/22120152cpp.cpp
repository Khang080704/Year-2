#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Student
{
public:
	string name;
	string id;
	string birthDay;
	double midTerm, finalTerm, practice;
	Student();
	Student(string name, string id, string birrthDay
			,double midTerm, double finalTerm, double practice);
	Student Copy(Student a);
	double average() {
		return 1.0*(midTerm + finalTerm + practice) / 3;
	}
	void print();

private:
	
};

class QLSinhVien {
private:
	Student* sv;
	int number;
public:
	QLSinhVien();
	~QLSinhVien();
	void readFile(string input);
	void writeFile(string output, Student a);
	void findUnderAverge(string output);
};


int main() {
	QLSinhVien data;
	string input = "input.txt";
	string output = "output.txt";
	data.readFile(input);
	data.findUnderAverge(output);
	
}

Student::Student()
{
	name = "";
	id = "";
	birthDay = "";
	midTerm = finalTerm = practice = 0;
}

Student::Student(string name, string id, string birthDay
	, double midTerm, double finalTerm, double practice) {
	this->name = name;
	this->id = id;
	this->birthDay = birthDay;
	this->midTerm = midTerm;
	this->finalTerm = finalTerm;
	this->practice = practice;
}

Student Student::Copy(Student a) {
	Student copy;
	copy.name = a.name;
	copy.birthDay = a.birthDay;
	copy.id = a.id;
	copy.midTerm = a.midTerm;
	copy.finalTerm = a.finalTerm;
	copy.practice = a.practice;
	return copy;
}
void Student::print() {
	cout << name << " - " << id << " - " << birthDay << endl;
	cout << practice << " " << midTerm << " "<<finalTerm << endl;
}

QLSinhVien::QLSinhVien() {
	sv = NULL;
	number = 0;
}
QLSinhVien::~QLSinhVien() {
	delete[] sv;
	number = 0;
}
void QLSinhVien::readFile(string input) {
	
	ifstream reader(input, ios::in);
	string buffer[100];
	sv = new Student[100];
	int count = 0;
	
	while (!reader.eof()) {
		for (int i = 0; i < 6; i++) {
			getline(reader, buffer[i]);
		}
		Student a(buffer[0], buffer[1], buffer[2], stod(buffer[3]),
			stod(buffer[4]), stod(buffer[5]));
		sv[count] = sv[count].Copy(a);
		count++;
	}
	number = count;
	for (int i = 0; i < number; i++) {
		sv[i].print();
	}

	reader.close();
}

void QLSinhVien::findUnderAverge(string output) {
	double sum = 0.0;
	for (int i = 0; i < number; i++) {
		sum += sv[i].average();
	}
	double averageAll = sum / number;
	ofstream writter(output, ios::out);
		
	for (int i = 0; i < number; i++) {
		if (sv[i].average() < averageAll) {
			writter << sv[i].name << " - " << sv[i].id << " - " << sv[i].birthDay << endl;
		}
	}
}