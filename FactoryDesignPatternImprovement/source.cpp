#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <memory>
#include <map>
#include <iomanip>

using namespace std;

class Shape {
protected:
	string _shape;
	
public:
	Shape() { _shape = ""; }
	Shape(string shape) { _shape = shape; }
	virtual ~Shape() {}

public:
	void setShape(string shape) { _shape = shape; }
	virtual string magicWord() = 0;
	virtual shared_ptr<Shape> clone() = 0;

public:
	virtual string toString() {
		stringstream ss;
		ss << "Shape: " << _shape;
		string str = ss.str();
		return str;
	}
};

class Rectangle : virtual public Shape {
private:
	double _width;
	double _height;
public:
	Rectangle() { _width = 0; _height = 0; }
	Rectangle(double width, double height) { _width = width;  _height = height; }
	~Rectangle() {}

public:
	double getWidth() { return _width; }
	double getHeight() { return _height; }

	void setWidth(double width) { _width = width; }
	void setHeight(double height) { _height = height; }

public:
	double getPerimeter() { return 2 * (_width + _height); }
	double getArea() { return _width * _height; }

public:
	shared_ptr<Shape> clone() { return make_shared<Rectangle>(_width, _height); }
	string magicWord() { return "Rectangle"; }

public:
	string toString() {
		stringstream ss;

		ss << "Rectangle: " << "Width = " << _width;
		ss << ", Height = " << _height;
		if (getArea() == int(getArea())) {
			ss << " => Area = " << int(getArea());
		}
		else {
			ss << " => Area = " << fixed << setprecision(2) << getArea();
		}
		if (getPerimeter() == int(getPerimeter())) {
			ss << ", Perimeter = " << int(getPerimeter());
		}
		else {
			ss << ", Perimeter = " << fixed << setprecision(2) << getPerimeter();
		}

		string ans;
		ans = ss.str();
		return ans;
	}
};

class Circle : virtual public Shape {
private:
	double _radius;
public:
	Circle(double radius) { _radius = radius; }
	Circle() { _radius = 0; }
	~Circle() {}

public:
	double getRadius() { return _radius; }

	void setRadius(double radius) { _radius = radius; }

public:
	double getArea() { return _radius * _radius * 3.14; }
	double getPerimeter() { return 2 * _radius * 3.14; }

public:
	shared_ptr<Shape> clone() { return make_shared<Circle>(_radius); }
	string magicWord() { return "Circle"; }

public:
	string toString() {
		stringstream ss;
		ss << "Circle: " << "Radius = " << _radius;
		if (getArea() == int(getArea())) {
			ss << " => Area = " << int(getArea()) << ", Perimeter = " << int(getPerimeter());
		}
		else {
			ss << " => Area = " << fixed << setprecision(2) << getArea() << ", Perimeter = " << getPerimeter();
		}
		string ans;
		ans = ss.str();
		return ans;
	}
};

class Triangle : virtual public Shape {
private:
	double _side1;
	double _side2;
	double _side3;
public:
	Triangle() { _side1 = 0; _side2 = 0; _side3 = 0; }
	Triangle(double side1, double side2, double side3) {
		_side1 = side1;
		_side2 = side2;
		_side3 = side3;
	}
	~Triangle() {}

public:
	double getSide1() { return _side1; }
	double getSide2() { return _side2; }
	double getSide3() { return _side3; }

	void setSide1(double side1) { _side1 = side1; }
	void setSide2(double side2) { _side2 = side2; }
	void setSide3(double side3) { _side3 = side3; }

public:
	double getPerimeter() { return _side1 + _side2 + _side3; }
	double getArea() {
		double s = getPerimeter() / 2;
		return sqrt(s * (s - _side1) * (s - _side2) * (s - _side3));
	}

public:
	string magicWord() { return "Triangle"; }
	shared_ptr<Shape> clone() { return make_shared<Triangle>(_side1, _side2, _side3); }

public:
	string toString() {
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
			ss << ", Perimeter = " << int(getPerimeter());
		}
		else {
			ss << ", Perimeter = " << fixed << setprecision(2) << getPerimeter();
		}

		string ans;
		ans = ss.str();
		return ans;
	}
};

class ShapeFactory {
public:
	map<string, shared_ptr<Shape>> _prototypes;
private:
	inline static shared_ptr<ShapeFactory> _instance = NULL;
	ShapeFactory() {
		auto rec = make_shared<Rectangle>();
		auto cir = make_shared<Circle>();
		auto tri = make_shared<Triangle>();

		_prototypes.insert({ "Rectangle", rec });
		_prototypes.insert({ "Circle", cir });
		_prototypes.insert({ "Triangle", tri });
	}
public:
	static shared_ptr<ShapeFactory> getInstance() {
		if (_instance == nullptr) {
			auto temp = new ShapeFactory();
			_instance = shared_ptr<ShapeFactory>(temp);
		}
		return _instance;
	}

	shared_ptr<Shape> createShape(string shape) {
		auto it = _prototypes[shape];
		auto result = it->clone();
		return result;
	}

	void printAll(vector<shared_ptr<Shape>> shapes) {
		for (auto it = shapes.begin(); it != shapes.end(); it++) {
			cout << (*it)->toString() << endl;
		}
	}
};

class ShapeFileIO {
public:
	void readFile(string fileName, vector<shared_ptr<Shape>>& shapes) {
		ifstream inFile;
		inFile.open(fileName);

		if (!inFile) {
			cout << "Unable to open file";
			exit(1);
		}
		string line, width, height, radius, side1, side2, side3;
		while (!inFile.eof()) {
			getline(inFile, line);
			stringstream ss(line);
			getline(ss, width, '=');
			getline(ss, width, ',');
			getline(ss, height, '=');
			getline(ss, height);
			if (line.find("Rectangle") != string::npos) {
				auto base_ptr = ShapeFactory::getInstance()->createShape("Rectangle");
                		auto rectangle = dynamic_pointer_cast<Rectangle>(base_ptr);
				rectangle->setWidth(stod(width));
				rectangle->setHeight(stod(height));
				shapes.push_back(rectangle);
			}

			getline(inFile, line);
			stringstream ss2(line);
			getline(ss2, radius, '=');
			getline(ss2, radius);
			if (line.find("Circle") != string::npos) {
				auto base_ptr = ShapeFactory::getInstance()->createShape("Circle");
          		     	auto circle = dynamic_pointer_cast<Circle>(base_ptr);
				circle->setRadius(stod(radius));
				shapes.push_back(circle);
			}

			getline(inFile, line);
			stringstream ss3(line);
			getline(ss3, side1, '=');
			getline(ss3, side1, ',');
			getline(ss3, side2, '=');
			getline(ss3, side2, ',');
			getline(ss3, side3, '=');
			getline(ss3, side3);
			if (line.find("Triangle") != string::npos) {
				auto base_ptr = ShapeFactory::getInstance()->createShape("Triangle");
              			auto triangle = dynamic_pointer_cast<Triangle>(base_ptr);
				triangle->setSide1(stod(side1));
				triangle->setSide2(stod(side2));
				triangle->setSide3(stod(side3));
				shapes.push_back(triangle);
			}
		}
		cout << "File read successfully" << endl << endl;
		inFile.close();
	}
};

int main() {
	shared_ptr<ShapeFactory> factory = ShapeFactory::getInstance();
	vector<shared_ptr<Shape>> shapes;
	ShapeFileIO fileIO;
	fileIO.readFile("data.txt", shapes);
	factory->printAll(shapes);

	cout << endl << "Press any key to exit . . .";
	cin.get();

	return 0;
}
