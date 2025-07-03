#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class owner{
public:
string name;
string cnic;      
string address;
void setName(string name){
this->name=name;
}
void setCnic(string cnic){
this->cnic=cnic;
}
void setAddress(string address){
this->address=address;
}
string getName(){
return this->name;
}
string getCnic(){
return this->cnic;
}
string getAddress(){
return this->address;
}

};
class ownerhouse : public owner {
public :
string houseAddress;
int rooms; 
void setHouseAddress(string houseAddress){
this->houseAddress=houseAddress;
}
void setRoom(int rooms){
this->rooms=rooms;
}
string getHouseAddress(){
return this->houseAddress;
}
int getRoom(){
return this->rooms;
}
};


class owenrbusiness : public owner{
public :
string regNumber;
string location;
void setRegNumber(string regNumber){
this->regNumber=regNumber;
}
void setLocation(string location){
this->location=location;
}
string getRegNumber(){
return this->regNumber;
}
string getLocation(){
return this->location;
}
};
void addHouse(ownerhouse obj){
ofstream outFile("house_data.txt", ios::app);
outFile << obj.getName() << " "  << obj.getCnic() << " " << obj.getAddress() << " " << obj.getHouseAddress() << " " << obj.getRoom()<<endl;
}
void addBusiness(owenrbusiness obj1){
ofstream outFile("business_data.txt", ios::app);
outFile << obj1.getName() << " "  << obj1.getCnic() << " " << obj1.getAddress() << " " << obj1.getRegNumber() << " " << obj1.getLocation()<<endl;
}

void displayData() {
cout << "\n--- House Data ---\n";
ifstream inFile("house_data.txt");
if (!inFile) {
    cout << "No house data found.\n";
} else {
    string hname, hcnic, haddress, address;   
    int rooms;
    while (inFile >> hname >> hcnic >> haddress >> address >> rooms) {
        cout << "Name: "          << hname  << '\n';
        cout << "CNIC: "          << hcnic  << '\n';
        cout << "Address: "       << haddress << '\n';
        cout << "House Address: " << address << '\n';
        cout << "Rooms: "         << rooms << "\n\n";
    }
    inFile.close();
}

cout << "--- Business Data ---\n";
ifstream innFile("business_data.txt");
if (!innFile) {
    cout << "No business data found.\n";
} else {
    string bname, bcnic, baddr, regNum, location;
    while (innFile >> bname >> bcnic >> baddr >> regNum >> location) {
        cout << "Name: "        << bname    << '\n';
        cout << "CNIC: "        << bcnic    << '\n';
        cout << "Address: "     << baddr    << '\n';
        cout << "Reg Number: "  << regNum   << '\n';
        cout << "Location: "    << location << "\n\n";
    }
    innFile.close();
}
}

void updateHouse() {
    ifstream inFile("house_data.txt");
    ofstream outFile("temp_data.txt");
    int found = 0; 
    string hname, hcnic, haddress, hAddr,ser;
    int rooms;
    cout << "Enter CNIC to update house: ";
    cin >> ser;
    cin.ignore();

    while (inFile >> hname >> hcnic >> haddress >> hAddr >> rooms) {
        if (hcnic == ser) {
            found = 1;  
            string newName, newAddress, newHAddress;
            int newRooms;
            cout << "Enter New Name: ";
            getline(cin, newName);
            cout << "Enter New Address: ";
            getline(cin, newAddress);
            cout << "Enter New House Address: ";
            getline(cin, newHAddress);
            cout << "Enter New Rooms: ";
            cin >> newRooms;
            cin.ignore();

            outFile << newName << ' ' <<ser << ' ' << newAddress << ' ' << newHAddress << ' ' << newRooms << '\n';
        } else {
            outFile << hname << ' ' << hcnic << ' ' << haddress << ' ' << hAddr << ' ' << rooms << '\n';
        }
    }

    inFile.close();
    outFile.close();
    remove("house_data.txt");
    rename("temp_data.txt", "house_data.txt");

    if (found == 1)
        cout << "House record UPDATED.\n";
    else
        cout << "CNIC not found.\n";
}


void updateBusiness() {
    ifstream inFile("business_data.txt");
    ofstream outFile("temp_data.txt");
    int found = 0;              
    string bname, bcnic, baddress, regnum, location;
    string ser;

    cout << "Enter CNIC to update business: ";
    cin  >> ser;
    cin.ignore();

    while (inFile >> bname >> bcnic >> baddress >> regnum >> location) {
        if (bcnic == ser) {
            found = 1;       
            string newName, newAddress, newReg, newLocation;

            cout << "Enter New Name: "; 
			 getline(cin, newName);
            cout << "Enter New Address: "; 
			 getline(cin, newAddress);
            cout << "Enter New RegNumber: "; 
			 getline(cin, newReg);
            cout << "Enter New Location: ";  
			getline(cin, newLocation);

            outFile << newName << ' ' << ser  << ' '<< newAddress  << ' ' << newReg << ' ' << newLocation << '\n';
        } else {
            outFile << bname << ' ' << bcnic << ' ' << baddress << ' ' << regnum << ' ' << location << '\n';
        }
    }
    inFile.close();
    outFile.close();
    remove("business_data.txt");
    rename("temp_data.txt", "business_data.txt");

    if (found == 1)
        cout << "Business record UPDATED.\n";
    else
        cout << "CNIC not found.\n";
}

void deleteHouse() {
    ifstream inFile("house_data.txt");
    ofstream outFile("temp_data.txt");
    int found = 0;               
    string hname, hcnic, haddress, hAddr;
    int rooms;
    string ser;

    cout << "Enter CNIC to delete house: ";
    cin  >> ser;
    cin.ignore();

    while (inFile >> hname >> hcnic >> haddress >> hAddr >> rooms) {
        if (hcnic == ser) {
            found = 1;         
        } else {
            outFile << hname << ' ' << hcnic << ' ' << haddress << ' '  << hAddr << ' ' << rooms << '\n';
        }
    }
    inFile.close();
    outFile.close();
    remove("house_data.txt");
    rename("temp_data.txt", "house_data.txt");

    if (found == 1)
        cout << "House record DELETED.\n";
    else
        cout << "CNIC not found.\n";
}

void deleteBusiness() {
    ifstream inFile("business_data.txt");
    ofstream outFile("temp_data.txt");
    int found = 0;          
    string bname, bcnic, baddress, regnum, location;
    string ser;

    cout << "Enter CNIC to delete business: ";
    cin  >> ser;
    cin.ignore();

    while (inFile >> bname >> bcnic >> baddress >> regnum >> location) {
        if (bcnic == ser) {
            found = 1;  
        } else {
            outFile << bname << ' ' << bcnic << ' ' << baddress << ' ' << regnum << ' ' << location << '\n';
        }
    }
    inFile.close();
    outFile.close();
    remove("business_data.txt");
    rename("temp_data.txt", "business_data.txt");

    if (found == 1)
        cout << "Business record DELETED.\n";
    else
        cout << "CNIC not found.\n";
}


int main(){
ownerhouse house1;
owenrbusiness business1;
string n;
int r;
cout<<"---House Data---"<< endl;
cout<<"Enter Name: ";
getline(cin ,n);
house1.setName(n);
cout<<"Enter cnic: ";
getline(cin,n);
house1.setCnic(n);
cout<<"Enter Address: ";
getline(cin,n);
house1.setAddress(n);
cout<<"Enter house Address: ";
getline(cin,n);
house1.setHouseAddress(n);
cout<<"Enter rooms: ";
cin>>r;
house1.setRoom(r);
addHouse(house1);

cin.ignore();


cout<<"---Business Data---"<< endl;
cout<<"Enter Name: ";
getline(cin ,n);
business1.setName(n);
cout<<"Enter cnic: ";
getline(cin,n);
business1.setCnic(n);
cout<<"Enter Address: ";
getline(cin,n);
business1.setAddress(n);
cout<<"Enter reg Number: ";
getline(cin,n);
business1.setRegNumber(n);
cout<<"Enter location: ";
getline(cin,n);
business1.setLocation(n);
addBusiness(business1);

// cout<<"Name"<<house1.getName()<<endl;
//cout<<"cnic"<<house1.getCnic()<<endl;
//cout<<"Address"<< house1.getAddress()<<endl;
//cout<<"house Address"<<house1.getHouseAddress()<<endl;
//cout<<"rooms"<<house1.getRoom()<<endl;
//
// cout<<"Name"<<business1.getName()<<endl;
//cout<<"cnic"<<business1.getCnic()<<endl;
//cout<<"Address"<< business1.getAddress()<<endl;
//cout<<"house Address"<< business1.getRegNumber()<<endl;
//cout<<"rooms"<<business1.getLocation()<<endl;
displayData();
updateBusiness();
deleteHouse();  
deleteBusiness();
return 0;

}


