#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <map>
#include <string>

using namespace std;

// --- Forward declaration ---

class Employee;

class DailyEmployee;
class HourlyEmployee;
class ProductEmployee;
class Manager;

class EmployeeFactory;

class EmployeeFileIO;

// --- Implementation ---
class Employee {
protected:
    string _name;
public:
    Employee() {
        _name = "";
    }
    Employee(string name) {
        _name = name;
    }

public:
    void setEmployeeName(string name) { _name = name; }
    virtual string magicWord() = 0;
    virtual shared_ptr<Employee> clone() = 0;

public:
    virtual void print() {
        cout << "Type of employee: ";
    }
};

class DailyEmployee : virtual public Employee {
private:
    int _salaryPerDay;
    int _totalDays;
public:
    DailyEmployee() : Employee() {
        _salaryPerDay = 0;
        _totalDays = 0;
    }
    DailyEmployee(string name, int salaryPerDay, int totalDays) : Employee(name) {
        _salaryPerDay = salaryPerDay;
        _totalDays = totalDays;
    }

public:
    int getSalaryPerDay() { return _salaryPerDay; }
    int getTotalDays() { return _totalDays; }

    void setSalaryPerDay(int salaryPerDay) { _salaryPerDay = salaryPerDay; }
    void setTotalDays(int totalDays) { _totalDays = totalDays; }

public:
    string magicWord() { return "DailyEmployee"; }
    shared_ptr<Employee> clone() {
        return make_shared<DailyEmployee>(_name, _salaryPerDay, _totalDays);
    }

public:
    int calculateSalary() {
        return _salaryPerDay * _totalDays;
    }
    void print() {
        Employee::print();
        cout << "DailyEmployee" << endl;
        cout << "Salary per day: " << _salaryPerDay << "$" << endl;
        cout << "Total days: " << _totalDays << endl;
        cout << "Salary: " << calculateSalary() << "$" << endl << endl;
    }
};

class HourlyEmployee : virtual public Employee {
private:
    int _salaryPerHour;
    int _totalHours;
public:
    HourlyEmployee() : Employee() {
        _salaryPerHour = 0;
        _totalHours = 0;
    }
    HourlyEmployee(string name, int salaryPerHour, int totalHours) : Employee(name) {
        _salaryPerHour = salaryPerHour;
        _totalHours = totalHours;
    }

public:
    int getSalaryPerHour() { return _salaryPerHour; }
    int getTotalHours() { return _totalHours; }

    void setSalaryPerHour(int salaryPerHour) { _salaryPerHour = salaryPerHour; }
    void setTotalHours(int totalHours) { _totalHours = totalHours; }

public:
    string magicWord() { return "HourlyEmployee"; }
    shared_ptr<Employee> clone() {
        return make_shared<HourlyEmployee>(_name, _salaryPerHour, _totalHours);
    }

public:
    int calculateSalary() {
        return _salaryPerHour * _totalHours;
    }

    void print() {
        Employee::print();
        cout << "HourlyEmployee" << endl;
        cout << "Salary per hour: " << _salaryPerHour << "$" << endl;
        cout << "Total hours: " << _totalHours << endl;
        cout << "Salary: " << calculateSalary() << "$" << endl << endl;
    }
};

class ProductEmployee : virtual public Employee {
private:
    int _salaryPerProduct;
    int _totalProducts;
public:
    ProductEmployee() : Employee() {
        _salaryPerProduct = 0;
        _totalProducts = 0;
    }
    ProductEmployee(string name, int salaryPerProduct, int totalProducts) : Employee(name) {
        _salaryPerProduct = salaryPerProduct;
        _totalProducts = totalProducts;
    }

public:
    int getSalaryPerProduct() { return _salaryPerProduct; }
    int getTotalProducts() { return _totalProducts; }

    void setSalaryPerProduct(int salaryPerProduct) { _salaryPerProduct = salaryPerProduct; }
    void setTotalProducts(int totalProducts) { _totalProducts = totalProducts; }

public:
    string magicWord() { return "ProductEmployee"; }
    shared_ptr<Employee> clone() {
        return make_shared<ProductEmployee>(_name, _salaryPerProduct, _totalProducts);
    }

public:
    int calculateSalary() {
        return _salaryPerProduct * _totalProducts;
    }

    void print() {
        Employee::print();
        cout << "ProductEmployee" << endl;
        cout << "Salary per product: " << _salaryPerProduct << "$" << endl;
        cout << "Total products: " << _totalProducts << endl;
        cout << "Salary: " << calculateSalary() << "$" << endl << endl;
    }
};

class Manager : public Employee {
private:
    int _totalEmployees;
    int _payPerEmployee;
    int _fixedSalary;
public:
    Manager() : Employee() {
        _totalEmployees = 0;
        _payPerEmployee = 0;
        _fixedSalary = 0;
    }
    Manager(string name, int totalEmployees, int payPerEmployee, int fixedSalary) : Employee(name) {
        _totalEmployees = totalEmployees;
        _payPerEmployee = payPerEmployee;
        _fixedSalary = fixedSalary;
    }

public:
    int getTotalEmployees() { return _totalEmployees; }
    int getPayPerEmployee() { return _payPerEmployee; }
    int getFixedSalary() { return _fixedSalary; }

    void setTotalEmployees(int totalEmployees) { _totalEmployees = totalEmployees; }
    void setPayPerEmployee(int payPerEmployee) { _payPerEmployee = payPerEmployee; }
    void setFixedSalary(int fixedSalary) { _fixedSalary = fixedSalary; }

public:
    string magicWord() { return "Manager"; }
    shared_ptr<Employee> clone() {
        return make_shared<Manager>(_name, _totalEmployees, _payPerEmployee, _fixedSalary);
    }

public:
    int calculateSalary() {
        return _totalEmployees * _payPerEmployee + _fixedSalary;
    }

    void print() {
        Employee::print();
        cout << "Manager" << endl;
        cout << "Total employees: " << _totalEmployees << endl;
        cout << "Pay per employee: " << _payPerEmployee << "$" << endl;
        cout << "Fixed salary: " << _fixedSalary << "$" << endl;
        cout << "Salary: " << calculateSalary() << "$" << endl << endl;
    }
};

class EmployeeFactory {
public:
    map <string, shared_ptr<Employee>> _prototype;

private:
    inline static shared_ptr<EmployeeFactory> _instance = NULL;

    EmployeeFactory() {
        auto dailyEmployee = make_shared<DailyEmployee>();
        auto hourlyEmployee = make_shared<HourlyEmployee>();
        auto productEmployee = make_shared<ProductEmployee>();
        auto manager = make_shared<Manager>();

        _prototype.insert({ dailyEmployee->magicWord(), dailyEmployee });
        _prototype.insert({ hourlyEmployee->magicWord(), hourlyEmployee });
        _prototype.insert({ productEmployee->magicWord(), productEmployee });
        _prototype.insert({ manager->magicWord(), manager });

    }

public:
    static shared_ptr<EmployeeFactory> getInstance() {
        if (_instance == nullptr) {
            auto temp = new EmployeeFactory();
            _instance = shared_ptr<EmployeeFactory>(temp);
        }
        return _instance;
    }

    shared_ptr<Employee> createEmployee(string employee) {
        auto it = _prototype[employee];
        auto result = it->clone();
        return result;
    }

    void printAll(vector<shared_ptr<Employee>> employees) {
        for (auto it = employees.begin(); it != employees.end(); it++) {
            (*it)->print();
        }
    }
};

class EmployeeFileIO {
public:
    vector<shared_ptr<Employee>> readFile(string fileName) {
        vector<shared_ptr<Employee>> employees;
        ifstream file(fileName);

        if (!file) {
            cout << "Cannot open file!" << endl;
            exit(1);
        }

        while (!file.eof()) {
            string line;
            getline(file, line);

            string type, name, salaryPerDay, totalDays, salaryPerHour, totalHours,
                salaryPerProduct, totalProducts, payPerEmployee, totalEmployees, fixedSalary;
            if (line.empty()) {
                continue;
            }

            stringstream ss(line);
            getline(ss, type, ':');

            if (type == "DailyEmployee") {
                getline(ss, name, ' ');
                getline(ss, name);

                getline(file, line);
                stringstream ss(line);
                getline(ss, salaryPerDay, '=');
                getline(ss, salaryPerDay, '$');
                getline(ss, totalDays, '=');
                getline(ss, totalDays);

                auto baseEmployee = EmployeeFactory::getInstance()->createEmployee(type);
                auto employee = dynamic_pointer_cast<DailyEmployee>(baseEmployee);
                employee->setSalaryPerDay(stoi(salaryPerDay));
                employee->setTotalDays(stoi(totalDays));
                employees.push_back(employee);

            }
            else if (type == "HourlyEmployee") {
                getline(ss, name, ' ');
                getline(ss, name);

                getline(file, line);
                stringstream ss(line);
                getline(ss, salaryPerHour, '=');
                getline(ss, salaryPerHour, '$');
                getline(ss, totalHours, '=');
                getline(ss, totalHours);

                auto baseEmployee = EmployeeFactory::getInstance()->createEmployee(type);
                auto employee = dynamic_pointer_cast<HourlyEmployee>(baseEmployee);
                employee->setSalaryPerHour(stoi(salaryPerHour));
                employee->setTotalHours(stoi(totalHours));
                employees.push_back(employee);

            }
            else if (type == "ProductEmployee") {
                getline(ss, name, ' ');
                getline(ss, name);

                getline(file, line);
                stringstream ss(line);
                getline(ss, salaryPerProduct, '=');
                getline(ss, salaryPerProduct, '$');
                getline(ss, totalProducts, '=');
                getline(ss, totalProducts);

                auto baseEmployee = EmployeeFactory::getInstance()->createEmployee(type);
                auto employee = dynamic_pointer_cast<ProductEmployee>(baseEmployee);
                employee->setSalaryPerProduct(stoi(salaryPerProduct));
                employee->setTotalProducts(stoi(totalProducts));
                employees.push_back(employee);

            }
            else if (type == "Manager") {
                getline(ss, name, ' ');
                getline(ss, name);

                getline(file, line);
                stringstream ss(line);
                getline(ss, fixedSalary, '=');
                getline(ss, fixedSalary, '$');
                getline(ss, totalEmployees, '=');
                getline(ss, totalEmployees, ';');
                getline(ss, payPerEmployee, '=');
                getline(ss, payPerEmployee);

                auto baseEmployee = EmployeeFactory::getInstance()->createEmployee(type);
                auto employee = dynamic_pointer_cast<Manager>(baseEmployee);
                employee->setFixedSalary(stoi(fixedSalary));
                employee->setTotalEmployees(stoi(totalEmployees));
                employee->setPayPerEmployee(stoi(payPerEmployee));
                employees.push_back(employee);

            }
        }
        file.close();
        return employees;
    }
};

// --- Main function ---
int main() {
    shared_ptr<EmployeeFactory> factory = EmployeeFactory::getInstance();

    vector<shared_ptr<Employee>> employees;

    EmployeeFileIO fileIO;
    employees = fileIO.readFile("November2021.txt");

    factory->printAll(employees);

    cout << "Press any key to exit . . .";
    cin.get();

    return 0;
}
