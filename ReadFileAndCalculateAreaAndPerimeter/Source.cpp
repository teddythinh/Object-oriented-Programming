#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Shape;
class Rectangle;
class Circle;
class Triangle;
class ShapeFileIO;

class Shape {
public:
	virtual string printAllInformation() {
		stringstream ss;
		ss << "Shape: " << endl;
		string ans;
		ans = ss.str();
		return ans;
	}
};

class Rectangle : public Shape {
private:
	float _width;
	float _height;
public:
	Rectangle(float width, float height) { _width = width; _height = height; }
	Rectangle() { _width = 0; _height = 0; }

	void setWidth(float width) { _width = width; }
	void setHeight(float height) { _height = height; }

	float getWidth() { return _width; }
	float getHeight() { return _height; }

	float getPerimeter() {
		float ans = 2 * (_width + _height);
		return ans;
	}
	float getArea() {
		float ans = _width * _height;
		return ans;
	}

	string printAllInformation() {
		stringstream ss;
		ss << "Rectangle: " << "Width = " << _width;
		ss << " Height = " << _height;
		if (getArea() == int(getArea())) {
			ss << " Area = " << int(getArea());
		}
		else {
			ss << " Area = " << fixed << setprecision(2) << getArea();
		}
		if (getPerimeter() == int(getPerimeter())) {
			ss << ", Perimeter = " << int(getPerimeter()) << endl;
		}
		else {
			ss << " Perimeter = " << fixed << setprecision(2) << getPerimeter() << endl;
		}
		string ans;
		ans = ss.str();
		return ans;
	}
};

class Circle : public Shape {
private:
	float _radius;
public:
	Circle(int radius) { _radius = radius; }
	Circle() { _radius = 0; }

	void setRadius(int radius) { _radius = radius; }

	float getRadius() { return _radius; }

	float getPerimeter() {
		float ans = 2 * 3.14 * _radius;
		return ans;
	}
	float getArea() {
		float ans = 3.14 * _radius * _radius;
		return ans;
	}

	string printAllInformation() {
		stringstream ss;
		ss << "Circle: " << "Radius = " << _radius;
		if (getArea() == int(getArea())) {
			ss << " => Area = " << int(getArea()) << ", Perimeter = " << int(getPerimeter()) << endl;
		}
		else {
			ss << " => Area = " << fixed << setprecision(2) << getArea() << ", Perimeter = " << getPerimeter() << endl;
		}
		string ans;
		ans = ss.str();
		return ans;
	}
};

class Triangle : public Shape {
private:
	float _side1;
	float _side2;
	float _side3;
public:
	Triangle(int side1, int side2, int side3) { _side1 = side1; _side2 = side2; _side3 = side3; }
	Triangle() { _side1 = 0; _side2 = 0; _side3 = 0; }

	void setSide1(int side1) { _side1 = side1; }
	void setSide2(int side2) { _side2 = side2; }
	void setSide3(int side3) { _side3 = side3; }

	float getSide1() { return _side1; }
	float getSide2() { return _side2; }
	float getSide3() { return _side3; }

	float getPerimeter() {
		float ans = _side1 + _side2 + _side3;
		return ans;
	}

	float getArea() {
		float s = getPerimeter() / 2;
		float ans = sqrt(s * (s - _side1) * (s - _side2) * (s - _side3));
		return ans;
	}

	string printAllInformation() {
		stringstream ss;
		ss << "Triangle: ";
		ss << "A = " << _side1;
		ss << ", B = " << _side2;
		ss << ", C = " << _side3;
		if (getArea() == int(getArea())) {
			ss << " => Area = " << int(getArea());
		}
		else {
			ss << " => Area = " << fixed << setprecision(2) << getArea();
		}
		if (getPerimeter() == int(getPerimeter())) {
			ss << ", Perimeter = " << int(getPerimeter()) << endl;
		}
		else {
			ss << ", Perimeter = " << fixed << setprecision(2) << getPerimeter() << endl;
		}

		string ans;
		ans = ss.str();
		return ans;
	}
};

class ShapeFileIO {
public:
	void readFile(string fileName, vector<Shape*>& shapes) {
		ifstream file;
		file.open("data.txt");

		string line, width, height, radius, side1, side2, side3;

		if (file.is_open()) {
			while (!file.eof()) {
				getline(file, line);
				stringstream ss(line);
				getline(ss, width, '=');
				getline(ss, width, ',');
				getline(ss, height, '=');
				getline(ss, height);
				if (line.find("Rectangle") != string::npos) {
					Rectangle* r = new Rectangle(stof(width), stof(height));
					shapes.push_back(r);
				}

				getline(file, line);
				stringstream ss2(line);
				getline(ss2, radius, '=');
				getline(ss2, radius);
				if (line.find("Circle") != string::npos) {
					Circle* c = new Circle(stof(radius));
					shapes.push_back(c);
				}

				getline(file, line);
				stringstream ss3(line);
				getline(ss3, side1, '=');
				getline(ss3, side1, ',');
				getline(ss3, side2, '=');
				getline(ss3, side2, ',');
				getline(ss3, side3, '=');
				getline(ss3, side3);
				if (line.find("Triangle") != string::npos) {
					Triangle* t = new Triangle(stof(side1), stof(side2), stof(side3));
					shapes.push_back(t);
				}
			}
			cout << "Read file successfully!" << endl << endl;
		}
		else {
			cout << "Can not open file!" << endl;
		}
	}
};

int main() {
	vector<Shape*> shapes;
	ShapeFileIO reader;
	reader.readFile("data.txt", shapes);
	for (int i = 0; i < shapes.size(); i++) {
		cout << shapes[i]->printAllInformation();
	}

	for (int i = 0; i < shapes.size(); i++) {
		delete shapes[i];
	}

	cout << endl << "Press any key to exit . . . ";
	cin.get();

	return 0;
}
