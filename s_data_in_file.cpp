#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Sirf ek function: roll no check karega
bool checkRollExists(string roll) {
	ifstream in("student_data.txt");
	string r, name, fname, gender, blood;
	while (in >> r >> name >> fname >> gender >> blood) {
		if (r == roll)
			return true;
	}
	return false;
}

int main() {
	int choice;
	do {
		cout << "\n--- Student Menu ---\n";
		cout << "1. Enter Data\n";
		cout << "2. Search by Roll No\n";
		cout << "3. Display All Data\n";
		cout << "4. Update Data\n";
		cout << "5. Delete Data\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			string roll, name, fname, gender, blood;
			cout << "Enter Roll No: ";
			cin >> roll;

			if (checkRollExists(roll)) {
				cout << "This Roll No already exists!\n";
			} else {
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Father's Name: ";
				cin >> fname;
				cout << "Enter Gender: ";
				cin >> gender;
				cout << "Enter Blood Group: ";
				cin >> blood;

				ofstream out("student_data.txt", ios::app);
				out << roll << " " << name << " " << fname << " " << gender << " " << blood << endl;
				cout << "Data saved successfully!\n";
			}

			cin.ignore();
			cout << "\nPress Enter to continue...";
			cin.get();
		}

		else if (choice == 2) {
			string roll, r, name, fname, gender, blood;
			bool found = 0;
			cout << "Enter Roll No to Search: ";
			cin >> roll;

			ifstream in("student_data.txt");
			while (in >> r >> name >> fname >> gender >> blood) {
				if (r == roll) {
					cout << "\n--- Student Found ---\n";
					cout << "Roll No: " << r << "\nName: " << name
					     << "\nFather's Name: " << fname << "\nGender: "
					     << gender << "\nBlood Group: " << blood << endl;
					found = 1;
					break;
				}
			}

			if (!found)
				cout << "Roll No not found!\n";

			cin.ignore();
			cout << "\nPress Enter to continue...";
			cin.get();
		}

		else if (choice == 3) {
			string r, name, fname, gender, blood;
			ifstream in("student_data.txt");
			cout << "\n--- All Students ---\n";
			while (in >> r >> name >> fname >> gender >> blood) {
				cout << "\nRoll No: " << r << "\nName: " << name
				     << "\nFather's Name: " << fname << "\nGender: "
				     << gender << "\nBlood Group: " << blood << endl;
			}

			cin.ignore();
			cout << "\nPress Enter to continue...";
			cin.get();
		}

		else if (choice == 4) {
			string roll, r, name, fname, gender, blood;
			bool found = 0;
			cout << "Enter Roll No to Update: ";
			cin >> roll;

			ifstream in("student_data.txt");
			ofstream temp("temp.txt");

			while (in >> r >> name >> fname >> gender >> blood) {
				if (r == roll) {
					cout << "Enter New Name: ";
					cin >> name;
					cout << "Enter New Father's Name: ";
					cin >> fname;
					cout << "Enter New Gender: ";
					cin >> gender;
					cout << "Enter New Blood Group: ";
					cin >> blood;
					found = 1;
				}
				temp << r << " " << name << " " << fname << " " << gender << " " << blood << endl;
			}

			in.close();
			temp.close();
			remove("student_data.txt");
			rename("temp.txt", "student_data.txt");

			if (found)
				cout << "Data updated successfully!\n";
			else
				cout << "Roll No not found!\n";

			cin.ignore();
			cout << "\nPress Enter to continue...";
			cin.get();
		}

		else if (choice == 5) {
			string roll, r, name, fname, gender, blood;
			bool found = 0;
			cout << "Enter Roll No to Delete: ";
			cin >> roll;

			ifstream in("student_data.txt");
			ofstream temp("temp.txt");

			while (in >> r >> name >> fname >> gender >> blood) {
				if (r != roll) {
					temp << r << " " << name << " " << fname << " " << gender << " " << blood << endl;
				} else {
					found = 1;
				}
			}

			in.close();
			temp.close();
			remove("student_data.txt");
			rename("temp.txt", "student_data.txt");

			if (found)
				cout << "Data deleted successfully!\n";
			else
				cout << "Roll No not found!\n";

			cin.ignore();
			cout << "\nPress Enter to continue...";
			cin.get();
		}

		else if (choice != 0) {
			cout << "Invalid option!\n";
			cin.ignore();
			cout << "\nPress Enter to continue...";
			cin.get();
		}

	} while (choice != 0);

	cout << "Program exited.\n";
	return 0;
}
