//Covid-19 Patient Management System applying OOP concepts
//OOP Concepts applied: Classes and Objects, Access Specifiers, Encapsulation

//Libraries
#include<iostream> 
#include<conio.h>
#include<string>

using namespace std;

class Patient {
private:
	string id, name, age, doctor, condition; //private variables
public:
	//setters - assigning user value to private variables
	void setId(string a) { id = a; }
	void setName(string b) { name = b; }
	void setAge(string c) { age = c; }
	void setDoctor(string d) { doctor = d; }
	void setCondition(string e) { condition = e; }
	//getters - getting the values from private variables
	string getId() { return id; }
	string getName() { return name; }
	string getAge() { return age; }
	string getDoctor() { return doctor; }
	string getCondition() { return condition; }
};

//initializing functions with counter as parameter
void addPatient(int counter);
void deletePatient(int counter);
void editPatient(int counter);
void searchPatient(int counter);
void viewAllPatients(int counter);
void quit();

//counter for Patient array
int counter = 0;

//function for incrementing counter
void increment(int a) {
	a++;
	counter = a;
}

//function for decrementing counter
void decrement(int a) {
	a--;
	counter = a;
}

//Patient class array initialization
Patient patients[10];

//main function
int main() {
	string choice;
	//Main Menu
	system("CLS");
	cout << "COVID-19 PATIENT MANAGEMENT SYSTEM\n\n";
	cout << "[1]ADD PATIENT\n";
	cout << "[2]DELETE PATIENT\n";
	cout << "[3]EDIT PATIENT\n";
	cout << "[4]SEARCH PATIENT\n";
	cout << "[5]VIEW ALL PATIENTS\n";
	cout << "[6]QUIT\n\n";

	cout << "ENTER CHOICE: ";
	getline(cin, choice);
	system("CLS");

	if (choice == "1") {
		addPatient(counter); //function call
	}
	else if (choice == "2") {
		deletePatient(counter); //function call
	}
	else if (choice == "3") {
		editPatient(counter); //function call	
	}
	else if (choice == "4") {
		searchPatient(counter); //function call	
	}
	else if (choice == "5") {
		viewAllPatients(counter); //function call	
	}
	else if (choice == "6") {
		quit();	 //function call
	}
	else {
		main();  //function call to self(main)
	}

	_getch();
	return 0;
}


//addPatient function
void addPatient(int counter) {
	string id, name, age, doctor, condition;
	cout << "ADD PATIENT\n\n";
	if (counter < 10) {
		cout << "Enter ID: ";
		getline(cin, id); //getline - just like cin but includes white spaces
		cout << "Enter Name: ";
		getline(cin, name);
		cout << "Enter Age: ";
		getline(cin, age);
		cout << "Enter Doctor: ";
		getline(cin, doctor);
		cout << "Enter Condition: ";
		getline(cin, condition);
		patients[counter].setId(id); //assigning the values entered to book object
		patients[counter].setName(name);
		patients[counter].setAge(age);
		patients[counter].setDoctor(doctor);
		patients[counter].setCondition(condition);
		increment(counter);	//calling function to increment counter
		cout << "\nPATIENT ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	else {
		cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF PATIENTS TOBE ADDED!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
}

//deletePatient function
void deletePatient(int counter) {
	string id;
	int choice;
	cout << "DELETE PATIENT\n\n";
	if (counter == 0) {
		cout << "THERE IS NO PATIENT TO DELETE!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout << "Enter ID: ";
	getline(cin, id);

	for (int i = 0; i < counter; i++) {
		//finding a match using for loop
		if (patients[i].getId() == id) {
			cout << "\nPATIENT FOUND\n\n";
			cout << "Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
			cin >> choice;
			if (choice == 1) {
				patients[i].setId(""); //setting the value to none
				patients[i].setName("");
				patients[i].setAge("");
				patients[i].setDoctor("");
				patients[i].setCondition("");
				for (int a = i; a < counter; a++) {
					//adjusting the values after deletion of data eg. data from patient[4] copied to book[3]
					patients[a] = patients[a + 1];
				}
				patients[9].setId(""); //adjustment if the library is full(10 books)
				patients[9].setName("");
				patients[9].setAge("");
				patients[9].setDoctor("");
				patients[9].setCondition("");
				decrement(counter); //calling function to decrement counter
				cout << "\nPATIENT SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
				_getch();
				main();
			}
			else {
				main();
			}
		}
	}
	cout << "\nPATIENT NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();

}
void editPatient(int counter) {
	system("CLS");
	string editId, choice;
	string id, name, age, doctor, condition;
	cout << "\nEDIT PATIENT\n\n";
	if (counter == 0) {
		cout << "THERE IS NO PATIENT TO EDIT!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout << "Enter ID: ";
	getline(cin, editId);
	for (int i = 0; i < counter; i++) {
		//finding a match using for loop
		if (patients[i].getId() == editId) {
			cout << "\nPATIENT FOUND!\n\n";
			cout << "ID: " << patients[i].getId() << endl;
			cout << "NAME: " << patients[i].getName() << endl;
			cout << "AGE: " << patients[i].getAge() << endl;
			cout << "DOCTOR: " << patients[i].getDoctor() << endl;
			cout << "CONDITION: " << patients[i].getCondition() << endl;
			cout << "\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
			getline(cin, choice);
			if (choice == "1") {
				//re-entering values
				cout << "Enter ID: ";
				getline(cin, id);
				cout << "Enter Name: ";
				getline(cin, name);
				cout << "Enter Age: ";
				getline(cin, age);
				cout << "Enter Doctor: ";
				getline(cin, doctor);
				cout << "Enter Condition: ";
				getline(cin, condition);
				patients[i].setId(id);
				patients[i].setName(name);
				patients[i].setAge(age);
				patients[i].setDoctor(doctor);
				patients[i].setCondition(condition);
				cout << "\nPATIENT EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
				_getch();
				editPatient(counter);//function call to self
			}
			else {
				main();
			}
		}
	}
	cout << "\nPATIENT NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();
}
void searchPatient(int counter) {
	string id;
	int choice;
	bool print = false; //boolean expression to decide which to print
	cout << "SEARCH PATIENT\n\n";
	if (counter == 0) {
		cout << "THERE IS NO PATIENT TO SEARCH!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout << "Enter ID: ";
	getline(cin, id);
	for (int i = 0; i < counter; i++) {
		//finding a match using for loop
		if (patients[i].getId() == id) {
			cout << "\nPATIENT FOUND!\n\n";
			cout << "ID: " << patients[i].getId() << endl;
			cout << "NAME: " << patients[i].getName() << endl;
			cout << "AGE: " << patients[i].getAge() << endl;
			cout << "DOCTOR: " << patients[i].getDoctor() << endl;
			cout << "CONDITION: " << patients[i].getCondition() << endl;
			print = true;
		}
	}
	if (print) {
		cout << "\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	//if there's no patient found
	else {
		cout << "\nPATIENT NOT FOUND!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
}
void viewAllPatients(int counter) {
	//iterating all the values on the library using patient array
	cout << "VIEW ALL PATIENTS\n\n";
	for (int i = 0; i < counter; i++) {
		cout << "PATIENT DETAILS\n\n";
		cout << "ID: " << patients[i].getId() << endl;
		cout << "NAME: " << patients[i].getName() << endl;
		cout << "AGE: " << patients[i].getAge() << endl;
		cout << "DOCTOR: " << patients[i].getDoctor() << endl;
		cout << "CONDITION: " << patients[i].getCondition() << endl << endl;
	}
	cout << "Press any key to continue . . .";
	_getch();
	main();
}
void quit() {
	//quit function
	_exit(1);
}