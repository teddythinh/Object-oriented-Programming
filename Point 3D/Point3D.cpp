#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

// Declaration of the class
class Point2D;
class Point3D;
class RandomIntegerGenerator;
class StringToPoint3D;
class FileIO;

// Implementation of the class
class Point2D {
private:
	int _x;
	int _y;
public:
	Point2D(int x, int y) {
		this->_x = x;
		this->_y = y;
	}

	int getX() { return this->_x; }
	int getY() { return this->_y; }

	virtual void print() { cout << "(" << getX() << "," << getY() << ")" << endl; }
};

class Point3D : public Point2D {
private:
	int _z;
public:
	int getZ() { return _z; }

	void setZ(int z) { _z = z; }

	Point3D(int x, int y, int z) : Point2D(x, y) { this->_z = z; }

	void print() { cout << "(" << getX() << ", " << getY() << ", " << getZ() << ")" << endl; }
};

class RandomIntegerGenerator {
public:
	RandomIntegerGenerator() { srand(time(NULL)); }
	int next() { return rand(); }
	int next(int ceiling) { return rand() % ceiling; }
	int next(int left, int right) { return rand() % (right - left + 1) + left; }
};

class StringToPoint3D {
public:
	bool isValid(string input) {
		// the valid input is a string of 3 digits eg "1, 2, 3"
		const string pattern = "\\d+, \\d+, \\d+";
		regex rgx(pattern);
		bool valid = regex_match(input, rgx);
		return valid;
	}

public:
	Point3D* convert(string input) {
		Point3D* p = NULL;
		if (isValid(input)) {
			//! The first way is using tokenizer
			/*
			vector<string> tokens;
			istringstream iss(input);
			string token;
			while (getline(iss, token, ',')) {
				tokens.push_back(token);
			}
			int x = stoi(tokens[0]);
			int y = stoi(tokens[1]);
			int z = stoi(tokens[2]);
			p = new Point3D(x, y, z);
			*/

			//! The second way is using stringstream
			string x, y, z;
			stringstream ss(input);
			getline(ss, x, ',');
			getline(ss, y, ' ');
			getline(ss, y, ',');
			getline(ss, z, ' ');
			getline(ss, z);
			p = new Point3D(stoi(x), stoi(y), stoi(z));
		}
		return p;
	}
};

class FileIO {
public:
	void saveFile(string filename, vector<Point3D> data) {
		ofstream outfile(filename);
		for (int i = 0; i < data.size(); i++) {
			outfile << "(" << data[i].getX() << ", " <<
				data[i].getY() << ", " << data[i].getZ() << ")" << endl;
		}
		cout << "All points are saved successfully." << endl;
		outfile.close();
	}
};

int main() {
	// Call class StringToPoint3D to convert string to Point3D
	// Call vector<Point3D> data to store all Point3D objects
	// Call class FileIO to save data to a file
	StringToPoint3D stp;
	vector<Point3D> points;
	FileIO fio;

	// Call class RandomIntegerGenerator to generate random integer
	RandomIntegerGenerator rig;
	int n = rig.next(3, 7);

	// Request user to input n Point3D objects
	cout << "Please input " << n << " points: ";
	cout << " (The valid inputs are 3 digits separated by comma.)" << endl;
	string input;

	// Convert string to Point3D object and store them in vector<Point3D> data
	for (int i = 0; i < n; i++) {
		getline(cin, input);
		if (stp.isValid(input)) {
			Point3D* p = NULL;
			p = stp.convert(input);
			points.push_back(*p);
		}
		else {
			cout << "Invalid input. Please input again!" << endl;
			i--;
		}
	}

	cout << endl;
	// Print all Point3D objects in vector<Point3D> data
	for (int i = 0; i < points.size(); i++) {
		points[i].print();
	}

	cout << endl;
	// Call saveFile to save all Point3D objects in vector<Point3D> data
	fio.saveFile("point3d.txt", points);

	cout << endl << "Press any key to exit..." << endl;
	cin.get();
}
