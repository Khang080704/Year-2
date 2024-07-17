#include "ComplexShape.h"
void ComplexShape::input() {
	std::cout << "Nhap so luong hinh chu nhat: ";
	int n; cin >> n;
	
	for (int i = 0; i < n; i++) {
		Rectangle* rec = new Rectangle();
		rec->input();
		addShape(rec);
	}

	std::cout << "Nhap so luong hinh tron: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		Circle* cir = new Circle();
		cir->input();
		Children.push_back(cir);
	}
}
void ComplexShape::addShape(Shape* shape) {
	Children.push_back(shape);
}
void ComplexShape::output() {
	/*for (int i = 0; i < Children.size(); i++) {
		Children[i]->print();
	}*/
	cout << "Danh sach cac hinh: " << endl;
	for (auto& shape : Children) {
		cout << shape->toString();
	}
	cout << endl;
}
bool ComplexShape::IsSelected(Point src) {
	for (int i = 0; i < Children.size(); i++) {
		if (Children[i]->IsSelected(src)) {
			cout << "Diem nam trong hinh" << endl;
			return true;
		}
		else {
			cout << "Diem nam ngoai hinh" << endl;
			return false;
		}
	}
}
double ComplexShape::SumOfCircleArea() {
	double circleArea = 0.0;
	for (int i = 0; i < Children.size(); i++) {
		if (Children[i]->getName() == "Circle") {
			circleArea += Children[i]->CalArea();
		}
	}
	return circleArea;
 }
double ComplexShape::SumOfRectangleArea() {
	double recArea = 0.0;
	for (int i = 0; i < Children.size(); i++) {
		if (Children[i]->getName() == "Rectangle") {
			recArea += Children[i]->CalArea();
		}
	}
	return recArea;
}
Shape* ComplexShape::findMaxCircleArea() {
	Shape* result = new Circle();
	int index = 0;
	//find first circle in array
	for (int i = 0; i < Children.size(); i++) {
		if (Children[i]->getName() == "Circle") {
			result = Children[i];
			index = i;
			break;
		}
	}

	for (int i = index; i < Children.size(); i++) {
		if (result->CalArea() < Children[i]->CalArea() && Children[i]->getName() == "Circle") {
			result = Children[i];
		}
	}

	return result;
}
double ComplexShape::sumArea() {
	double sum = 0.0;
	for (int i = 0; i < Children.size(); i++) {
		sum += Children[i]->CalArea();
	}
	return sum;
}
void ComplexShape::writeToFile(string name) {
	ofstream writter(name, ios::binary | ios::out);
	
	for (int i = 0; i < Children.size(); i++) {
		writter.write((const char*)&Children[i], sizeof(Shape*));
	}

	writter.close();
}
void ComplexShape::ReadFromFile(string name) {
	ifstream reader(name, ios::binary | ios::in);
	vector<Shape*> data(Children.size());

	for (int i = 0; i < Children.size(); i++) {
		reader.read((char*)&data[i], sizeof(Shape*));
		data[i]->print();
	}
	reader.close();

}