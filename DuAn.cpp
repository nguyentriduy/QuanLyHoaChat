#include <bits/stdc++.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include "LaboratoryManager.cpp"

using namespace std;

int main() {
    LaboratoryManager manager;

    int choice;
	
	//su dung do while tao mot menu
    do {
        cout << setw(60)<< setfill('+') << "" << setfill(' ') << endl;
        cout << "|" << setw(14) << "" << setw(44) << left << "Manage your laboratory" << "|" << endl;
        cout << "|" << setw(14) << "" << setw(44) << left << "(1). Adding chemicals." << "|" << endl;
        cout << "|" << setw(14) << "" << setw(44) << left << "(2). Find data about chemical." << "|" << endl;
        cout << "|" << setw(14) << "" << setw(44) << left << "(3). Remove an chemical." << "|" << endl;
        cout << "|" << setw(14) << "" << setw(44) << left << "(4). Sort and print list of chemicals." << "|" << endl;
        cout << "|" << setw(14) << "" << setw(44) << left << "(5). Save to file Laboratory." << "|" << endl;
        cout << "|" << setw(14) << "" << setw(44) << left << "(6). Exit." << setw(42) << "|" << endl;
        cout << setw(60)<< setfill('+') << "" << setfill(' ') << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
		
		// xu ly lua chon cua nguoi dung
        switch (choice) {
        	
            case 1: // thêm các hợp chất hóa học
            	system("cls");
            	int numberChemicals;
            	cout << "Number of chemicals want to add: ";
            	cin >> numberChemicals;
            	for (int i = 0; i < numberChemicals; i++){
            		manager.addChemical();
            		cout << endl;
				}
				system("pause");
				system("cls");
                break;
                
            case 2: // tim kiem thong tin hop chat
            	system("cls");
            	char fname[50];
				cout << "Enter name to find Chemical: ";
				cin.getline(fname, sizeof(fname));
                manager.find(fname);
                system("pause");
                system("cls");
                break;
                
            case 3: // xoa mot hop chat
            	system("cls");
                manager.removeChemical();
                system("pause");
                system("cls");
                break;
                
            case 4: // sap xep va in danh sach cac hop chat
            	system("cls");
                manager.sortChemicals();
                system("pause");
                system("cls");
                break;
                
            case 5: // ghi du lieu vao file
            	system("cls");
                manager.saveToFile();
                system("pause");
                system("cls");
                break;
                
            case 6: // thoat chuong trinh
            	system("cls");
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}