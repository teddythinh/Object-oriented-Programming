#include <iostream>

using namespace std;

class RandomIntegerGenerator {
public:
	//RandomIntegerGenerator() { srand(time(NULL)); }
	int next() { return rand(); }
	int next(int ceiling) { return rand() % ceiling; }
	int next(int left, int right) { return rand() % (right - left + 1) + left; }
};

class Dice {
private:
    RandomIntegerGenerator _rng;
public:
    
    int roll() {
        int result = _rng.next(1, 6);
        return result;
    }
};

int32_t main() {
    srand(time(NULL));

    Dice d;
    RandomIntegerGenerator rng;

    int n = rng.next(3, 8);
    cout << "There are " << n << " times to dice." << endl;

    int total = 0;
    for (int i = 0; i < n; i++) {
        int result = d.roll();
        cout << "Time " << i + 1 << ": " << result << endl;
        total += result;
    }
    cout << "Point after " << n << " times is: " << total << endl;


    
    return 0;
}
