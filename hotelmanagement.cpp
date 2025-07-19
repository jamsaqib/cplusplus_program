#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <cstdlib>
using namespace std;

void clearScreen() {
system("cls");
}

string isAlphaString(string prompt) {
string input;
bool found = false;
while (!found) {
    cout << prompt;
    getline(cin, input);
    found = true;
    for (int i = 0; i < input.length(); i++) {
        if (!isalpha(input[i]) && input[i] != ' ') {
            found = false;
            cout << "Invalid input! Only letters allowed.\n";
            break;
        }
    }
}
return input;
}

int isNumber(string prompt) {
string input;
bool found = false;
while (!found) {
    cout << prompt;
    getline(cin, input);
    found = true;
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            found = false;
            cout << "Invalid input! Only numbers allowed.\n";
            break;
        }
    }
}
return atoi(input.c_str());
}
// user
bool isUserIdExists(string id) {
ifstream infile("users.txt");
string line, uid, name;
while (getline(infile, line)) {
    stringstream ss(line);
    ss >> uid >> name;
    if (uid == id)
        return true;
}
return false;
}


void addUser() {
string id, name;
cin.ignore();  

cout << "Enter User ID: ";
getline(cin, id);

while (isUserIdExists(id)) {
    cout << "User ID already exists."<<endl;
	cout<< "Enter another ID : ";
    getline(cin, id);
}

name = isAlphaString("Enter User Name: ");

ofstream outFile("users.txt", ios::app);
outFile << id << " " << name << endl;  
cout << "User added.\n";
}


bool getUserInfo(const string& id, string& name) {
ifstream infile("users.txt");
string line, uid;
while (getline(infile, line)) {
    stringstream ss(line);
    ss >> uid >> name;
    if (uid == id)
        return true;
}
return false;
}


//manu

void addMenuItem() {
cin.ignore();
string name = isAlphaString("Enter Item Name : ");
int price = isNumber("Enter Price : ");
ofstream outFile("menu.txt", ios::app);
outFile << name << " " << price << endl;
cout << "Item added.\n";
}

void displayMenuItems() {
string name;
int price;
ifstream inFile("menu.txt");
cout << "\n--- MENU ITEMS ---\n";
while (inFile >> name >> price) {
    cout << "Name: " << name << " | Price: " << price << endl;
}
inFile.close();
}

void updateMenuItem() {
string name, search;
int price;
int found = 0;

cout << "Enter item name to update: ";
cin >> search;

ifstream inFile("menu.txt");
ofstream outFile("temp.txt");
while (inFile >> name >> price) {
    if (name == search) {
        found = 1;
        cin.ignore();
        name = isAlphaString("Enter new name: ");
        price = isNumber("Enter new price: ");
    }
    outFile << name << " " << price << endl;
}
inFile.close();
outFile.close();
remove("menu.txt");
rename("temp.txt", "menu.txt");

if (found == 1) cout << "Item updated.\n";
else cout << "Item not found.\n";
}

void deleteMenuItem() {
string name, search;
int price;
int found = 0;

cout << "Enter item name to delete: ";
cin >> search;

ifstream inFile("menu.txt");
ofstream outFile("temp.txt");
while (inFile >> name >> price) {
    if (name == search) {
        found = 1;
        continue;
    }
    outFile << name << " " << price << endl;
}
inFile.close();
outFile.close();
remove("menu.txt");
rename("temp.txt", "menu.txt");

if (found == 1) cout << "Item deleted.\n";
else cout << "Item not found.\n";
}

void bookTable() {
int tableNo;
string userId;
cout << "Enter table number to book: ";
cin >> tableNo;
cin.ignore();
cout << "Enter your User ID: ";
getline(cin, userId);

if (!isUserIdExists(userId)) {
    cout << "User ID not found. Please add user first.\n";
    return;
}

ifstream inFile("tables.txt");
ofstream outFile("temp.txt");
int tNo;
string status;
int booked = 0;

while (inFile >> tNo >> status) {
    if (tNo == tableNo && status == "Free") {
        outFile << tNo << " " << userId << endl;
        booked = 1;
    } else {
        outFile << tNo << " " << status << endl;
    }
}

inFile.close();
outFile.close();
remove("tables.txt");
rename("temp.txt", "tables.txt");

if (booked == 1) cout << "Table booked.\n";
else cout << "Booking failed.\n";
}

void cancelBooking() {
int tableNo;
cout << "Enter table number to cancel: ";
cin >> tableNo;

ifstream inFile("tables.txt");
ofstream outFile("temp.txt");
int tNo;
string status;
int cancelled = 0;

while (inFile >> tNo >> status) {
    if (tNo == tableNo && status != "Free") {
        outFile << tNo << " Free" << endl;
        cancelled = 1;
    } else {
        outFile << tNo << " " << status << endl;
    }
}

inFile.close();
outFile.close();
remove("tables.txt");
rename("temp.txt", "tables.txt");

if (cancelled == 1) cout << "Booking cancelled.\n";
else cout << "Cancellation failed.\n";
}

void showTables() {
ifstream inFile("tables.txt");
string status;
int tNo;
cout << "\n--- TABLE STATUS ---\n";
while (inFile >> tNo >> status) {
    cout << "Table " << tNo << ": ";
    if (status == "Free") {
        cout << "Free";
    } else {
        string name, contact;
        if (getUserInfo(status, name)) {
            cout << "Booked by " << name << " (ID: " << " )";
        } else {
            cout << "Booked (Unknown user)";
        }
    }
    cout << endl;
}
inFile.close();
}

void initTables() {
ofstream outFile("tables.txt");
for (int i = 1; i <= 10; i++) {
    outFile << i << " Free" << endl;
}
outFile.close();
cout << "All tables reset to 'Free'.\n";
}

int main() {
mainStart:
clearScreen();
int choice;
cout << "==== RESTAURANT SYSTEM ====\n";
cout << "1. Menu Management\n";
cout << "2. Table Booking\n";
cout << "3. User Management\n";
cout << "4. Exit\n";
cout << "Select option : ";
cin >> choice;

if (cin.fail() || choice < 1 || choice > 4) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input! Enter number (1-4).\n";
    system("pause");
    goto mainStart;
}

switch (choice) {
    case 1:
    menuStart:
        clearScreen();
        int m;
        cout << "---- MENU MANAGEMENT ----\n";
        cout << "1. Add Item\n";
        cout << "2. Show Items\n";
        cout << "3. Update Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Back\n";
        cout << "Choice : ";
        cin >> m;

        if (cin.fail() || m < 1 || m > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter number  (1-5).\n";
            system("pause");
            goto menuStart;
        }

        switch (m) {
            case 1: addMenuItem(); 
			break;
            case 2: displayMenuItems(); 
			break;
            case 3: updateMenuItem(); 
			break;
            case 4: deleteMenuItem(); 
			break;
            case 5: goto mainStart;
        }
        system("pause");
        goto menuStart;

    case 2:
    tableStart:
        clearScreen();
        int t;
        cout << "---- TABLE BOOKING ----\n";
        cout << "1. Book Table\n";
        cout << "2. Cancel Booking\n";
        cout << "3. Show Tables\n";
        cout << "4. Reset Tables\n";
        cout << "5. Back\n";
        cout << "Choice : ";
        cin >> t;

        if (cin.fail() || t < 1 || t > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter numbe (1-5).\n";
            system("pause");
            goto tableStart;
        }

        switch (t) {
            case 1: 
			bookTable(); 
			break;
            case 2:
			 cancelBooking(); 
			break;
            case 3:
			 showTables(); 
			break;
            case 4:
			 initTables(); 
			break;
            case 5:
			 goto mainStart;
        }
        system("pause");
        goto tableStart;

    case 3:
        clearScreen();
        cout << "--- USER MANAGEMENT ---\n";
        addUser();
        system("pause");
        goto mainStart;

    case 4:
        exit(0);
}

return 0;
}



