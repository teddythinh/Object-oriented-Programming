#include<iostream>
#include <vector>
#include <numeric>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

class RandomIntegerGenerator {
public:
	//RandomIntegerGenerator() { srand(time(NULL)); }
	int next() { return rand(); }
	int next(int ceiling) { return rand() % ceiling; }
	int next(int left, int right) { return rand() % (right - left + 1) + left; }
};

class MobileNetwork {
private:
    string _name;
    vector<string> _prefixes;
public:
    string name() const { return _name; }
    vector<string> prefixes() const { return _prefixes; }
    MobileNetwork() { 
        _name = "";
        _prefixes = vector<string>();
    }
    MobileNetwork(string name, vector<string> prefixes) {
        _name = name;
        _prefixes = prefixes;
    }
};

class Telephone {
private:
    MobileNetwork _network;
    string _prefix;
    string _number;
public:
    MobileNetwork network() const { return _network; }
    string prefix() const { return _prefix; }
    string toString() const { 
        stringstream ss;
        ss << _network.name() << ": " << _prefix << _number;
        string ans = ss.str();
        return ans;    
    }
    Telephone() {
        _network = MobileNetwork();
        _prefix = "";
        _number = "";
    }
    Telephone(MobileNetwork network, string prefix, string number) {
        _network = network;
        _prefix = prefix;
        _number = number;
    }
};

class TelephoneMock {
private:
    vector<MobileNetwork> _supportedNetwork() {
        // MobileNetwork("Viettel", { "086", "096", "097", "098", "032", "033", "034", "035", "036", "037", "038", "039" });
        // MobileNetwork("Vinaphone", { "088", "091", "094", "083", "084", "085", "081", "082" });
        // MobileNetwork("Mobiphone", { "089", "090", "093", "070", "079", "077", "076", "078" });
        // MobileNetwork("Vietnamobile", { "092", "056", "058" });
        // MobileNetwork("GMobile", { "099", "059" });
        // MobileNetwork("Itelecom", { "087" });

        vector<MobileNetwork> networks = vector<MobileNetwork>();
        networks.push_back(MobileNetwork("Viettel", { "086", "096", "097", "098", "032", "033", "034", "035", "036", "037", "038", "039" }));
        networks.push_back(MobileNetwork("Vinaphone", { "088", "091", "094", "083", "084", "085", "081", "082" }));
        networks.push_back(MobileNetwork("Mobifone", { "089", "090", "093", "070", "079", "077", "076", "078" }));
        networks.push_back(MobileNetwork("Vietnamobile", { "092", "056", "058" }));
        networks.push_back(MobileNetwork("GMobile", { "099", "059" }));
        networks.push_back(MobileNetwork("Itelecom", { "087" }));
        return networks;
    }
    RandomIntegerGenerator _rig;
public:
    Telephone generateTelephoneNumber() {
        int index = _rig.next(0, _supportedNetwork().size() - 1);
        MobileNetwork network = _supportedNetwork()[index];

        vector<string> prefixes = network.prefixes();
        index = _rig.next(0, prefixes.size() - 1);
        string prefix = prefixes[index];

        stringstream writer;
        for(int i = 0; i < 7; i++) {
            writer << _rig.next(10);
        }
        string numbers = writer.str();

        Telephone tel = Telephone(network, prefix, numbers);
        return tel;
    } 
};


int main() {
    srand(time(NULL));
    
    // Generate 10 random phone numbers
    TelephoneMock mock;
    for(int i = 1; i <= 10; i++) {
        Telephone tel = mock.generateTelephoneNumber();
        cout << tel.toString() << endl;
    }    
}
