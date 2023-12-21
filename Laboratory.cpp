#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

class Laboratory{
	friend class LaboratoryManager;
	private:
		char symbol[20]; 
		char name[50];
		double mass;
	public:
		// ham thanh vien de them chat hoa hoc
		void addChemical() {
			cout << "Enter chemical symbol: ";
			cin >> symbol;
			
			cout << "Enter chemical name: ";
			cin.ignore();
			cin.getline(name, sizeof(name));
			
			cout << "Enter mass: ";
			cin >> mass;
			cin.ignore();
		}
		
		// ham lay gia tri
		const char* getName() const {
        	return name;
    	}
    
    	const char* getSymbol() const {
        	return symbol;
   		}
    
    	double getMass() const {
        	return mass;
    	}
		
		// ham kiem tra su trung khop
		bool matchName(const char* fname) const {
			return strcmp(name, fname) == 0;
		}
		
		bool matchSymbol(const char* fsymbol) const {
			return strcmp(symbol, fsymbol) == 0;
		}
		
		bool matchMass(double m) const {
			return mass == m;
		}
		
		// ham hoan doi du lieu voi mot doi tuong khac
		void swapData(Laboratory &other) {
			swap(symbol, other.symbol);
			swap(name, other.name);
			swap(mass, other.mass);
		}
		
		// toan tu so sanh <
		bool operator <(const Laboratory &other) const {
			return strcmp(name, other.name) < 0;
		}
		
		// toan tu so sanh >
		bool operator >(const Laboratory &other) const {
			return mass > other.mass;
		}
		
		// ham hien thi thong tim
		void display() const {
        	cout << "|" << setw(39) << left << name << setw(20) << left << symbol << setw(10) << left << mass << "|" << endl;
    	}
    	
    	// xuat du lieu
    	friend ostream& operator<<(ostream& os, const Laboratory& lab);
};

ostream& operator<<(ostream& os, const Laboratory& lab) {
    os << "Name: " << lab.name << endl;
    os << "Symbol: " << lab.symbol << endl;
    os << "Mass: " << lab.mass << endl;
    return os;
}