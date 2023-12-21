#include <bits/stdc++.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Laboratory.cpp"

using namespace std;

class LaboratoryManager {
	private:
		vector<Laboratory> labs;
		vector<Laboratory> labsName;
		vector<Laboratory> labsMass;
	public:
		// ham de them hop chat hoa hoc
		void addChemical() {
			Laboratory newLab;					// khoi tao mot doi tuong moi
			newLab.addChemical();				// goi phuong thuc addChemical cua doi tuong de them hop chat
			labs.push_back(newLab);				// them doi tuong moi vao vector labs
		}
		
		// hàm tìm hợp chất hóa học theo tên
		void find(const char* fname) const {	// ham find nhan con tro const char* la ten(fname) can tim kiem
        	bool found = false;					// khoi tao bien found de theo doi co tim thay khong

        	for (const auto& lab : labs) {		// vong lap for duyet qua vector labs chua cac doi tuong Laboratory
            	if (lab.matchName(fname)) {		// kiem tra xem ten cua mot doi tuong co trung voi fname khong
                	cout << lab;				// neu trung, xuat thong tin doi tuong bang toan tu <<
                	found = true;				// dat found = true de bao la tim thay
            	}
        	}

        	if (!found) {
            cout << "Not Found!\n";
        	}
    	}
		
		// ham xoa hop chat hoa hoc
		void removeChemical() {
			char searchSymbol[20];											// khai bao mang ky tu de luu tru ky hieu chat can xoa
			bool found = false;												// bien theo doi de xem co tim thay va xoa khong
			cout << "Enter sign Chemistry: ";
			cin >> searchSymbol;
			cin.ignore();
			
			for (auto it = labs.begin(); it != labs.end(); ++ it) {
				if(it->matchSymbol(searchSymbol)) {							// kiem tra ki hieu co trung voi doi tuong can xoa khong
					it->swapData(labs.back());								// hoan doi du lieu cua doi tuong can xoa voi doi tuong cuoi trong vector
					found = true;											// dat found = true neu tim thay va da xoa
					cout << "Complete!" << endl;
					labs.pop_back();										// xoa du lieu cuoi trong vector
					break;													// dừng vòng lặp khi tìm thấy đối tượng
				}
			}
			if (!found) cout << "Not found! Please try again!" << endl;
		}
		
		// ham sap xep va in hoa chat
		void sortChemicals() {
			
			// sao chep vector labs vao vector labsMass va vector labsName de giu nguyen danh sach goc
			labsName = labs;
			labsMass = labs;
			
			int n;
			cout << "List of chemicals based on:" << endl;
			cout << "1. Name" << endl;
			cout << "2. Mass" << endl;
			cout << "Enter your choice: ";
			cin >> n;
			
			if (n==1){
				sort(labsName.begin(), labsName.end(), [](const Laboratory& a, const Laboratory& b){
					return a < b; 			// sap xep danh sach labsName theo ten
				});	
				
				cout << setw(71)<< setfill('_') << "" << setfill(' ') << endl;
        		cout << "|" << setw(5) << "" << setw(64) << left << "List of chemicals in descending order based on name" <<"|" << endl;
        		cout << "|" << setw(69) << setfill(' ') << "" << "|" << endl;
        		cout << "|" << setw(39) << left << "NAME" << setw(20) << left << "SYMBOL" << setw(10) << left << "MASS" << "|" << endl;
        		
				for (const auto& lab : labsName) {
            		lab.display();			// xuat thong tin tu danh sach da sap xep
       			}
        		cout << "|" << setw(69) << setfill('_') << "" << "|" << endl;
    			}
    			
    		else if (n==2){
   				sort(labsMass.begin(), labsMass.end(), [](const Laboratory& a, const Laboratory& b){
					return a > b;			// sap xep danh sach labsMass theo thu tu giam dan theo khoi luong
				});
					
				cout << setw(71)<< setfill('_') << "" << setfill(' ') << endl;
        		cout << "|" << setw(5) << "" << setw(64) << left << "List of chemicals in descending order based on mass"<< "|" << endl;
        		cout << "|" << setw(69) << setfill(' ') << "" << "|" << endl;
       			cout << "|" << setw(39) << left << "NAME" << setw(20) << left << "SYMBOL" << setw(10) << left << "MASS" << "|" << endl;
       			
				for (const auto& lab : labsMass) {
           			lab.display();			// xuat thong tin tu danh sach da sap xep
     			}
       			cout << "|" << setw(69) << setfill('_') << "" << "|" << endl;	
				}	
		}
		
		// ham luu vao file
		void saveToFile() const {
	        ofstream file("Laboratory.txt");			// mo mot tep voi ten Laboratory.txt de ghi du lieu
	
	        if (file.is_open()) {						// kiem tra xem co mo tep thanh cong khong
	        	file << setw(71)<< setfill('_') << "" << setfill(' ') << endl;
	            file << "|" << setw(20) << "" << setw(49) << left << "L I S T   O F   C H E M I S T R I E S"<< "|" << endl;
	            file << "|" << setw(39) << left << "NAME" << setw(20) << left << "SYMBOL" << setw(10) << left << "MASS" << "|" << endl;
	            
	            for (const auto& lab : labs) {
	            	// ghi thong tin moi hop chat vao tep
	                file << "|" << setw(39) << left << lab.name << setw(20) << left << lab.symbol << setw(10) << left << lab.mass << "|" << endl;
	            }
	            file << setw(71)<< setfill('_') << "" << setfill(' ') << endl;
	
	            cout << "Printed to file 'Laboratory.txt'" << endl;
	            file.close();							// dong tap tin khi ghi xong
	        } else {
	            cout << "Error opening the file 'Laboratory.txt'" << endl;
	        }
    	}
};