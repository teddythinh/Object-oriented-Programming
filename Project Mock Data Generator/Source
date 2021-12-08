#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

// ---Declaration---

class Students;
class RandomIntegerGenerator;
class RandomFloatGenerator;
class RandomAddressGenerator;
class RandomVietnameseFullnameGenerator;
class StudentsFileIO;

// ---Implementation---

// +++Data Storage+++

class Students {
private:
	string _name;
	string _studentID;
	float _gpa;
	string _phone;
	string _email;
	string _dob;
	string _address;
public:
	Students() {
		_name = "";
		_studentID = "";
		_gpa = 0;
		_phone = "";
		_email = "";
		_dob = "";
		_address = "";
	}

	Students(string name, string studentID, float gpa, string phone, string email, string dob, string address) {
		_name = name;
		_studentID = studentID;
		_gpa = gpa;
		_phone = phone;
		_email = email;
		_dob = dob;
		_address = address;
	}

	void setName(string name) { _name = name; }
	void setStudentID(string studentID) { _studentID = studentID; }
	void setGpa(float gpa) { _gpa = gpa; }
	void setPhone(string phone) { _phone = phone; }
	void setEmail(string email) { _email = email; }
	void setDob(string dob) { _dob = dob; }
	void setAddress(string address) { _address = address; }

	string getName() { return _name; }
	string getStudentID() { return _studentID; }
	float getGpa() { return _gpa; }
	string getPhone() { return _phone; }
	string getEmail() { return _email; }
	string getDob() { return _dob; }
	string getAddress() { return _address; }

	void print() {
		cout << "Name: " << _name << endl;
		cout << "Student ID: " << _studentID << endl;
		cout << "GPA: " << fixed << setprecision(2) << _gpa << endl;
		cout << "Phone: " << _phone << endl;
		cout << "Email: " << _email << endl;
		cout << "DOB: " << _dob << endl;
		cout << "Address: " << _address << endl;
	}
};

// +++Data Access+++

class StudentsFileIO {
public:
	vector<Students> readFile(string fileName) {
		ifstream file;

		file.open(fileName);

		string line;
		vector<Students> s;

		if (file.is_open()) {
			while (!file.eof()) {
				string name, gpa, studentID, phone, email, dob, address;
				getline(file, line);
				stringstream ss(line);
				getline(ss, studentID, ':');
				getline(ss, studentID, '-');
				getline(ss, name, '-');
				getline(ss, name);

				getline(file, line);
				stringstream ss2(line);
				getline(ss2, gpa, '=');
				getline(ss2, gpa, ',');
				getline(ss2, phone, '=');
				getline(ss2, phone);

				getline(file, line);
				stringstream ss3(line);
				getline(ss3, email, '=');
				getline(ss3, email);

				getline(file, line);
				stringstream ss4(line);
				getline(ss4, dob, '=');
				getline(ss4, dob);
				getline(file, line);

				stringstream ss5(line);
				getline(ss5, address, '=');
				getline(ss5, address);

				Students student(name, studentID, stof(gpa), phone, email, dob, address);
				s.push_back(student);
			}

			cout << "File is read successfully!" << endl << endl;

			return s;
		}
		else { cout << "File can not be opened!" << endl; }

		file.close();

		return s;
	}
public:
	vector<Students> writeFile(string fileName, vector<Students> s) {
		ofstream file;

		// ios::app to append to the end of the file not overwrite
		file.open(fileName, ios_base::app);
		if (file.is_open()) {
			for (int i = 3; i < s.size(); i++) {
				file << endl;
				file << "Student: " << s[i].getStudentID() << " - " << s[i].getName() << endl <<
					"GPA = " << s[i].getGpa() << ", Telephone = " << s[i].getPhone() << endl <<
					"Email = " << s[i].getEmail() << endl << "DOB = " << s[i].getDob() << endl <<
					"Address = " << s[i].getAddress();
			}

			cout << "File is written successfully!" << endl << endl;
		}
		else { cout << "File can not be opened!" << endl; }

		file.close();

		return s;
	}
};

// +++Bussiness Logic+++
class RandomIntegerGenerator {
public:
	RandomIntegerGenerator() { srand(time(NULL)); }
	int next() { return rand(); }
	int next(int ceiling) { return rand() % ceiling; }
	int next(int min, int max) { return rand() % (max - min + 1) + min; }
};

class RandomFloatGenerator {
public:
	RandomFloatGenerator() { srand(time(NULL)); }
	float next() { return (float)rand() / (float)RAND_MAX; }
	float next(float ceiling) { return (float)rand() / (float)RAND_MAX * ceiling; }
	float next(float min, float max) { return (float)rand() / (float)RAND_MAX * (max - min) + min; }
};

class RandomAddressGenerator {
private:
	RandomIntegerGenerator _rig;
	string _street[12] = { "Hai Ba Trung" , "Trinh Van Can",
						"Hai Trieu",  "Nguyen An Ninh",
						"Nguyen Van Troi",  "Truong Dinh",
						"Ham Nghi", "Nguyen Binh Khiem",
						"Pasteur", "Truong Han Sieu",
						"Han Thuyen", "Nguyen Van Linh" };

	int _ward = 0;

	string _district[19] = { "District 1", "District 2", "District 3",
							"District 4", "District 5", "District 6",
							"District 7", "District 8", "District 9",
							"District 10", "District 11", "District 12",
							"Go Vap District", "Tan Binh District",
							"Tan Phu District", "Binh Thanh District",
							"Binh Tan District", "Binh Chanh District",
							"Phu Nhuan District" };
public:
	string next() {
		int randomNumberForStreet = _rig.next(1, 12);
		_ward = _rig.next(1, 20);
		int randomNumberForDistrict = _rig.next(1, 19);

		stringstream ss;
		ss << _rig.next(1, 100) << " " << _street[randomNumberForStreet] << ", Ward " << _ward << ", "
			<< _district[randomNumberForDistrict] << ", Ho Chi Minh city";
		string address = ss.str();
		return address;
	}
};

class RandomVietnameseFullnameGenerator {
private:
	RandomIntegerGenerator _rig;
	string _firstName[12] = { "Pham", "Nguyen", "Le", "Phan", "Tran", "Hoang","Huynh", "Dang",
	"Ngo", "Duong", "Ly", "Vo" };
	string _middleName[12] = { "Huy", "Le", "Tuan", "Van", "Thi", "Cuong", "Trung", "Anh",
	"Thu", "Bao", "Minh", "Thien" };
	string _lastName[12] = { "Thinh", "Tu", "Dang", "Duong", "An", "Minh", "Binh", "Thien",
	"Nhat", "Dat", "Tran", "Trung" };
public:
	string next() {
		int numForFirstName = _rig.next(0, 11);
		int numForMiddleName = _rig.next(0, 11);
		int numForLastName = _rig.next(0, 11);

		stringstream ss;
		ss << _firstName[numForFirstName] << " " << _middleName[numForMiddleName] << " " <<
			_lastName[numForLastName];
		string result = ss.str();
		return result;
	}
};

// +++UI and Represenation+++

int main() {
	RandomIntegerGenerator rng;
	RandomVietnameseFullnameGenerator rvfg;
	RandomFloatGenerator rfg;
	RandomAddressGenerator radg;
	StudentsFileIO sfio;

	Students s;
	vector<Students> students;
	vector<Students> students2;

	// read file and store data into vector of Students
	students2 = sfio.readFile("students.txt");
	for (int i = 0; i < students2.size(); i++) {
		students.push_back(students2[i]);
	}

	int n = rng.next(5, 10);
	cout << "There are " << 3 + n << " students." << endl;
	cout << "(3 students that are hard-coded from the file and " << n << " students randomly generated.)\n\n";

	float sum = 0;
	for (int i = 0; i < n; i++) {
		s.setName(rvfg.next());
		s.setStudentID(to_string(rng.next(15, 21)) + to_string(rng.next(10, 20)) + to_string(rng.next(1000, 9999)));
		s.setGpa(rfg.next(1, 10));
		s.setPhone("0" + to_string(rng.next(100, 999)) + "-" + to_string(rng.next(100, 999)) + "-" + to_string(rng.next(100, 999)));
		s.setEmail(s.getStudentID() + "@student.hcmus.edu.vn");
		s.setDob(to_string(rng.next(1, 31)) + "/" + to_string(rng.next(1, 12)) + "/" + to_string(rng.next(1990, 2000)));
		s.setAddress(radg.next());

		sum += s.getGpa();
		students.push_back(s);
	}

	float average = 0;
	average = sum / n;
	cout << "Average GPA of all students: " << average << endl << endl;
	cout << "All the students have higher GPA than average: " << endl;

	for (int i = 0; i < n; i++) {
		if (students[i].getGpa() > average) {
			cout << students[i].getStudentID() << " - " << students[i].getName() <<
				", GPA:" << fixed << setprecision(2) << students[i].getGpa() << endl;
		}
	}

	cout << endl;
	students = sfio.writeFile("students.txt", students);

	cout << "Press any key to exit...";
	cin.get();

	return 0;
}
