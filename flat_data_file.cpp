#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// Owner
bool checkCnicExist(string cnic) {
    ifstream in("owner_data.txt");
    string c, name, phone;
    while (in >> c >> name >> phone) {
        if (c == cnic) return true;
    }
    return false;
}

void enterOwnerData() {
    string cnic, name, phone;
    cout << "Enter CNIC: ";
    cin >> cnic;
    if (checkCnicExist(cnic)) {
        cout << "CNIC already exists!\n";
        return;
    }
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Phone: ";
    cin >> phone;

    ofstream out("owner_data.txt", ios::app);
    out << cnic << " " << name << " " << phone << endl;
    cout << "Owner data saved.\n";
}

void searchOwnerData() {
    string cnic, c, name, phone;
    cout << "Enter CNIC to search: ";
    cin >> cnic;
    bool found = false;
    ifstream in("owner_data.txt");
    while (in >> c >> name >> phone) {
        if (c == cnic) {
            cout << "CNIC: " << c << "\nName: " << name << "\nPhone: " << phone << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "CNIC not found.\n";
}

void displayAllOwners() {
    string c, name, phone;
    ifstream in("owner_data.txt");
    while (in >> c >> name >> phone) {
        cout << "\nCNIC: " << c << "\nName: " << name << "\nPhone: " << phone << endl;
    }
}

// Flat
bool checkFlatExist(string flatNo) {
    ifstream in("flat_data.txt");
    string f, floor, rooms;
    while (in >> f >> floor >> rooms) {
        if (f == flatNo) return true;
    }
    return false;
}

void enterFlatData() {
    string f, floor, rooms;
    cout << "Enter Flat No: ";
    cin >> f;
    if (checkFlatExist(f)) {
        cout << "Flat already exists!\n";
        return;
    }
    cout << "Enter Floor: ";
    cin >> floor;
    cout << "Enter No. of Rooms: ";
    cin >> rooms;

    ofstream out("flat_data.txt", ios::app);
    out << f << " " << floor << " " << rooms << endl;
    cout << "Flat data saved.\n";
}

void searchFlatData() {
    string f, floor, rooms, flatNo;
    cout << "Enter Flat No to search: ";
    cin >> flatNo;
    bool found = false;
    ifstream in("flat_data.txt");
    while (in >> f >> floor >> rooms) {
        if (f == flatNo) {
            cout << "Flat No: " << f << "\nFloor: " << floor << "\nRooms: " << rooms << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Flat not found.\n";
}

void displayAllFlats() {
    string f, floor, rooms;
    ifstream in("flat_data.txt");
    while (in >> f >> floor >> rooms) {
        cout << "\nFlat No: " << f << "\nFloor: " << floor << "\nRooms: " << rooms << endl;
    }
}

// Car
bool checkEngineExist(string engine) {
    ifstream in("car_data.txt");
    string name, model, e;
    while (in >> name >> model >> e) {
        if (e == engine) return true;
    }
    return false;
}

void enterCarData() {
    string name, model, engine;
    cout << "Enter Car Name: ";
    cin >> name;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Engine No: ";
    cin >> engine;

    if (checkEngineExist(engine)) {
        cout << "Engine No already exists!\n";
        return;
    }

    ofstream out("car_data.txt", ios::app);
    out << name << " " << model << " " << engine << endl;
    cout << "Car data saved.\n";
}

void searchCarData() {
    string name, model, engine, eng;
    cout << "Enter Engine No to search: ";
    cin >> eng;
    bool found = false;
    ifstream in("car_data.txt");
    while (in >> name >> model >> engine) {
        if (engine == eng) {
            cout << "Car: " << name << "\nModel: " << model << "\nEngine: " << engine << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Engine No not found.\n";
}

void displayAllCars() {
    string name, model, engine;
    ifstream in("car_data.txt");
    while (in >> name >> model >> engine) {
        cout << "\nCar: " << name << "\nModel: " << model << "\nEngine: " << engine << endl;
    }
}


int main() {
    int choice;
        system("cls");
        cout << "\n--- Main Menu ---\n";
        cout << "1. Owner Data\n";
        cout << "2. Flat Data\n";
        cout << "3. Car Data\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int oChoice;
            cout << "\n--- Owner Menu ---\n";
            cout << "1. Enter Owner\n";
            cout << "2. Search Owner\n";
            cout << "3. Display All Owners\n";
            cout << "Enter your choice: ";
            cin >> oChoice;

            if (oChoice == 1) enterOwnerData();
            else if (oChoice == 2) searchOwnerData();
            else if (oChoice == 3) displayAllOwners();
            else cout << "Invalid Owner Choice\n";

        } else if (choice == 2) {
            int fChoice;
            cout << "\n--- Flat Menu ---\n";
            cout << "1. Enter Flat\n";
            cout << "2. Search Flat\n";
            cout << "3. Display All Flats\n";
            cout << "Enter your choice: ";
            cin >> fChoice;

            if (fChoice == 1) enterFlatData();
            else if (fChoice == 2) searchFlatData();
            else if (fChoice == 3) displayAllFlats();
            else cout << "Invalid Flat Choice\n";

        } else if (choice == 3) {
            int cChoice;
            cout << "\n--- Car Menu ---\n";
            cout << "1. Enter Car\n";
            cout << "2. Search Car\n";
            cout << "3. Display All Cars\n";
            cout << "Enter your choice: ";
            cin >> cChoice;

            if (cChoice == 1) enterCarData();
            else if (cChoice == 2) searchCarData();
            else if (cChoice == 3) displayAllCars();
            else cout << "Invalid Car Choice\n";

        } else if (choice == 4) {
            cout << "Exiting program.\n";
        } 

        system("pause");

    return 0;
}
