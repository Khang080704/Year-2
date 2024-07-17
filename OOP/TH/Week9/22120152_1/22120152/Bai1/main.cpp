#include"Student.h"
#include<vector>

int main()
{
	
	int n; 
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cin.ignore();
	vector<Student> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	string input = "Student.txt";
	ofstream writter(input, ios::out);
	for (int i = 0; i < n; i++) {
		writter << data[i] << endl;
	}
	
	string output = "Student.txt";
	ifstream reader(output, ios::in);
	while (!reader.eof()) {
		string temp;
		getline(reader, temp);
		cout << temp << endl;
	}

	writter.close();
	reader.close();

}