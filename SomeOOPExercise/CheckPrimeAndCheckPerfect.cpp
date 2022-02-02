#include <iostream>
#include <regex>

using namespace std;

class Integer {
private:
    int _value;
public:
    Integer(int value) { _value = value; }
    int getValue() { return _value; }
    void setValue(int value) { _value = value; }

    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    bool isPerfect(int num) {
        // perfect number: sum of divisors = num * 2
        // example 6: 1 + 2 + 3 + 6 = 12 = num * 2

        int sum = num;
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        return sum == num * 2;
    }
};

bool checkNumber(string str) {
    regex pattern("\\d+");
    bool result = regex_match(str, pattern);
    return result;
}

int main() {
    while(true) {
        string num;
        cout << "Input a number: ";
        cin >> num;
        if(checkNumber(num)) {
            
            cout << "1. Check if the number is prime.\n";
            cout << "2. Check if the number is perfect.\n";
            cout << "3. Check if the number is prime and perfect.\n";
            cout << "4. Exit." << endl;
            
            int choice;
            cout << "Your choice: ";
            cin >> choice;

            Integer i(stoi(num));
            switch (choice) {
                case 1:
                    if (i.isPrime(i.getValue())) {
                        cout << num << " is a prime number." << endl;
                    } else {
                        cout << num << " is not prime number." << endl;
                    }
                    break;
                case 2:
                    if (i.isPerfect(i.getValue())) {
                        cout << num << " is a perfect number." << endl;
                    } else {
                        cout << num << " is not a perfect number." << endl;
                    }
                    break;
                case 3:
                    if (i.isPrime(i.getValue()) && i.isPerfect(i.getValue())) {
                        cout << num << " is a prime number and a perfect number." << endl;
                    } else if (i.isPrime(i.getValue())) {
                        cout << num << " is a prime number." << endl;
                    } else if (i.isPerfect(i.getValue())) {
                        cout << num << " is a perfect number." << endl;
                    } else {
                        cout << num << " is not a prime number and is not a perfect number." << endl;
                    }
                    break;
                case 4:
                    return 0;
                default:
                    cout << "Nhap sai" << endl;
                    break;
            }
        } else {
            cout << "Nhap sai" << endl;
        }
    }
}
