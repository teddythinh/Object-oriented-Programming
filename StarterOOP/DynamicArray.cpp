#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class DynamicArray {
private:
	T* _a = NULL;
	int _maxSize;
	int _currentSize;

public:
	DynamicArray() {
		_a = new T[5];
		_maxSize = 5;
		_currentSize = 0;
	}

public:
	void push_back(T value) {
		if (_currentSize == _maxSize) {
			_maxSize += 128;

			T* temp = new T[_maxSize];
			for (int i = 0; i < _currentSize; i++) temp[i] = _a[i];

			delete[] _a;
			_a = temp;
		}
		_a[_currentSize] = value;
		_currentSize++;
	}

public:
	T getAt(int index) {
		if (index >= _currentSize) throw runtime_error("Index out of range");
		T number = _a[index];
		return number;
	}

public:
	T operator[](int index) { return getAt(index); }

public:
	int size() { return _currentSize; }

public:
	~DynamicArray() {
		if (_a != NULL) delete[] _a;
	}
};

int main() {
	DynamicArray<int> a;
	a.push_back(8);
	a.push_back(9);
	a.push_back(10);

	DynamicArray<double> b;
	b.push_back(9.5);
	b.push_back(10.5);
	b.push_back(11.5);

	DynamicArray<char> c;
	c.push_back('a');
	c.push_back('b');
	c.push_back('c');
	c.push_back('d');

	DynamicArray<string> d;
	d.push_back("Thay");
	d.push_back("Quang");
	d.push_back("dep");
	d.push_back("trai");

	DynamicArray<bool> e;
	e.push_back(true);
	e.push_back(false);

	DynamicArray<short> f;
	f.push_back(1);
	f.push_back(2);
	f.push_back(3);

	DynamicArray<long> g;
	g.push_back(4);
	g.push_back(5);
	g.push_back(6);

	cout << "Number in integer data type: ";
	for (int i = 0; i < a.size(); i++) {
		try { cout << a[i] << " "; }

		catch (runtime_error ex) { cout << ex.what() << endl; }
	}
	cout << endl << "Number in double data type: ";

	for (int i = 0; i < b.size(); i++) {
		try { cout << b[i] << " "; }

		catch (runtime_error ex) { cout << ex.what() << endl; }
	}
	cout << endl << "Characters: ";

	for (int i = 0; i < c.size(); i++) {
		try { cout << c[i] << " "; }

		catch (runtime_error ex) { cout << ex.what() << endl; }
	}
	cout << endl << "A sentence: ";

	for (int i = 0; i < d.size(); i++) {
		try { cout << d[i] << " "; }

		catch (runtime_error ex) { cout << ex.what() << endl; }
	}
	cout << endl << "Using boolean data type: ";

	for (int i = 0; i < e.size(); i++) {
		try { cout << e[i] << " "; }

		catch (runtime_error ex) { cout << ex.what() << endl; }
	}
	cout << endl << "Using short data type: ";

	for (int i = 0; i < f.size(); i++) {
		try { cout << f[i] << " "; }

		catch (runtime_error ex) { cout << ex.what() << endl; }
	}
	cout << endl << "Using long data type: ";

	for (int i = 0; i < g.size(); i++) {
		try { cout << g[i] << " "; }

		catch (runtime_error ex) { cout << ex.what() << endl; }
	}
	cout << endl;

	cout << endl << "Press any key to close the window.";
	cin.get();
	return 0;
}
