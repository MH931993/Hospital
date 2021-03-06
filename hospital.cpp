// تمرین 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<fstream>
#include<map>
#include <iterator>
#include <algorithm>
using namespace std;

multimap <int, string> savedpatient;







class Phone {


private:

	string mobile;
public:
	string get_phone() {

		
		char msg1[] = "Mobile number is not 11 digits, tray again";
		char msg2[] = "Mobile does not start with 0";
		char msg3[] = "Mobile number must not have script";

	START:
		try {
			mobile.clear();
			cin >> mobile;

			if (mobile.length() != 11) {
				throw msg1;
			}



			if (mobile[0] != '0') {

				throw msg2;

			}
			for (int i = 0; i < 10; i++) {
				for (char j = 'a'; j <= 'z'; j++)
				{
					for (char k = 'A'; k <= 'z'; k++) {
						if (mobile[i] == j|| mobile[i] == k)
						{
							throw msg3;
						}
					}
				}

			}
		}

		catch (char msg[]) {

			cout << msg << endl;
			goto START;
		}

		return mobile;
	}



};

class Name
{
private:

	string name;
public:
	string get_name() {


		char msg1[] = "Name must heve script, tray again";

	START:
		try {
			name.clear();
			cin >> name;

			for (int i = 0; i < name.length(); i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (name[i] == j)
					{
						throw msg1;


					}
				}
			}
		}
		catch (char msg[]) {

			cout << msg << endl;
			goto START;
		}

		return name;
	}
};
class Id {

private:

	string code;
public:
	string get_Id() {


		char msg1[] = "Mobile number is not 9 digits, tray again";
		

	START:
		try {
			code.clear();
			cin >> code;

			if (code.length() != 9) {
				throw msg1;
			}



			
		}

		catch (char msg[]) {

			cout << msg << endl;
			goto START;
		}

		return code;
	}

};













	class Person {

	protected:
		string name, family, address, phone;
		int age;

	public:

		Person() {}
		Person(string name, string family, string address, string phone, int age) {

			this->name = name;
			this->family = family;
			this->address = address;
			this->phone = phone;
			this->age = age;
		}
		void setName(string name) {
			this->name = name;
		}
		void setFamily(string family) {
			this->family = family;
		}
		void setAddress(string address) {
			this->address = address;
		}
		void setPhone(string phone) {
			this->phone = phone;
		}
		void setAge(int age) {
			this->age = age;
		}

		string getName() const {
			return name;
		}
		string getFamily()const {
			return family;
		}
		string getAddress()const {
			return address;
		}
		string getPhone()const {
			return phone;
		}
		int getAge()const {
			return age;
		}

		void report() const {

			cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << endl;

		}



	};

	class Employee :public Person {

		int idnumber;


	public:
		Employee() {}
		~Employee() { cout << "destructor of Employee is called!" << endl; }
		Employee(string name, string family, string address, string phone, int age, int idnumber)
			:Person(name, family, address, phone, age) {

			this->idnumber = idnumber;

		}

		int getIdnumber()const {

			return idnumber;

		}

		void setIdnumber(int idnumber) {

			this->idnumber = idnumber;

		}



	};

	class Patient : public Person {


	private:

		int fileNumber;
		string kind, dname;

		//vector<Course> Courses;
	public:
		Patient() {}
		Patient(string name, string family, string address, string phone, int age, int fileNumber, string kind, string dname) :Person(name, family, address, phone, age) {

			this->fileNumber = fileNumber;
			this->kind = kind;
			this->dname = dname;
		}

		void setfilenumber(int filenumber) {

			this->fileNumber = fileNumber;

		}
		void setkind(string kind) {

			this->kind = kind;

		}
		void setdname(string dname) {

			this->dname = dname;

		}

		int getfilenumber()const {

			return fileNumber;

		}
		string getkind()const {

			return kind;

		}
		string getdname()const { return dname; }


		void report() const {

			cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << setw(4) << fileNumber << setw(4) << kind << setw(4) << dname << endl;

		}


	};
	class Doctor :public Employee {

	private:

		string proficiency;

	public:
		Doctor() {
		}
		Doctor(string name, string family, string address, string phone, int age, int idnumber, string proficiency) :Employee(name, family, address, phone, age, idnumber) {


			this->proficiency = proficiency;
		}



		void setproficiency(string proficiency) { this->proficiency = proficiency; }
		string getproficiency() { return proficiency; }
		void report() const {

			cout << getName() << setw(6) << " " << getFamily() << setw(10) << getAddress() << setw(4) << getPhone() << setw(4) << getAge() << setw(4) << getIdnumber() << setw(4) << endl;

		}


	};




	//##############################################################
	//
	//#########################  PATIENT  ###########################

	vector <Patient> listst, listst2;
	fstream outputfile;
	void writest() {

		int filenumber, age;
		string name, family, address, phone, kind, dname;
		cout << "\n Enter the number of file of patient: ";
		cin >> filenumber;
		cout << "\n Enter the name of Patient: ";
		Name nm;
		name = nm.get_name();
		cout << "\n Enter the family of Patient: ";
		Name fa;
		name = fa.get_name();
		cout << "\n Enter the address of Patient: ";
		cin >> address;
		cout << "\n Enter the phone of Patient: ";
		Phone ph;
		phone = ph.get_phone();
		cout << "\n Enter the kind of the ill of Patient: ";
		cin >> kind;
		cout << "\n Enter the doctor name of Patient: ";
		cin >> dname;
		
		listst.push_back(Patient(name, family, address, phone, age, filenumber, kind, dname));

		outputfile.open("patient.csv", ios::app);
		outputfile << name + "," + family + "," + address + "," + kind + phone + ","
			+ to_string(filenumber) + "," + dname << endl;

	}
	void displayallpat() {

		system("cls");
		cout << "\n\n\t\tALL PATIENT RESULT \n\n";
		cout << "==========================================================\n";
		cout << "Name       Family        Address   Phone   age   Filenumber   kind of ill   doctor name" << endl;
		cout << "==========================================================\n";
		for (int i = 0; i < listst.size(); i++)
		{

			listst[i].report();
		}

	}
	void displayonepat(int filenumber) {

		system("cls");
		cout << "\n\n\t\tALL PATIENT RESULT \n\n";
		cout << "==========================================================\n";
		cout << "Name       Family        Address   Phone   age   Filenumber  kind of ill    doctor name" << endl;
		cout << "==========================================================\n";

		for (int i = 0; i < listst.size(); i++)
		{
			if (listst[i].getfilenumber() == filenumber) {
				listst[i].report();
			}
		}

	}
	void modify(int filenumber) {
		string name, family, phone;
		int a;
		for (int i = 0; i < listst.size(); i++)
		{
			if (listst[i].getfilenumber() == filenumber) {
				cout << "\n\n\n\tSELECT MENU";
				cout << "\n\n\n\t1. NAME";
				cout << "\n\n\t2. FAMILY";
				cout << "\n\n\t3. PHONE";
				cout << "\n\n\n\tEnter Choice (1/2/3)? ";
				cin >> a;
				switch (a)
				{
				case 1: cout << "Enter a name" << endl; cin >> name; listst[i].setName(name); break;
				case 2: cout << "Enter a family" << endl; cin >> family; listst[i].setFamily(family); break;
				case 3: cout << "Enter a phone" << endl; cin >> phone; listst[i].setPhone(phone); break;

				}

			}
		}

	}
	void deleteallstudent() {

		listst.clear();

	}
	void delete_patient(int filenumber) {


		for (int i = 0; i < listst.size(); i++) {

			if (listst[i].getfilenumber() != filenumber) {

				listst2.push_back(listst[i]);


			}
		}

		listst = listst2;
		vector<Patient>().swap(listst2);


	}



	multimap <int, string> getsavedpatient() {
		return savedpatient;
	}
	//##############################################################
	//
	//#########################  Doctor  ###########################

	vector <Doctor> listTA, listTA2;
	fstream outputfileTA;
	void writeDO() {

		int idnumber, age;
		string name, family, address, phone, Proficiency;

		cout << "\n Enter the id number of doctor: ";
		Id iD;
		code = iD.get_Id();
		cout << "\n Enter the name of doctor: ";
		Name nm;
		name = nm.get_name();
		cout << "\n Enter the family of doctor: ";
		Name fa;
		name = fa.get_name();
		cout << "\n Enter the address of doctor: ";
		cin >> address;
		cout << "\n Enter the phone of doctor: ";
		Phone ph;
		phone = ph.get_phone();
		cout << "\n Enter the proficiency of Teacher: ";
		cin >> Proficiency;
		cout << "\n Enter the age of Teacher: ";
		cin >> age;


		listTA.push_back(Doctor(name, family, address, phone, age, idnumber, Proficiency));
		outputfileTA.open("doctor.csv", ios::app);
		outputfileTA << name + "," + family + "," + address + "," + to_string(age) + phone + ","
			+ to_string(idnumber) + "," + Proficiency << endl;
	}
	void displayallDoc() {

		system("cls");
		cout << "\n\n\t\tALL PATIENT RESULT \n\n";
		cout << "==========================================================\n";
		cout << "Name       Family        Address   Phone   age   code      kind of ill" << endl;
		cout << "==========================================================\n";
		for (int i = 0; i < listTA.size(); i++)
		{

			listTA[i].report();
		}

	}
	void displayoneDO(int filenumber) {

		system("cls");
		cout << "\n\n\t\tALL PATIENT RESULT \n\n";
		cout << "==========================================================\n";
		cout << "Name       Family        Address   Phone   age   filenumber   doctor name   kind of ill" << endl;
		cout << "==========================================================\n";

		for (int i = 0; i < listTA.size(); i++)
		{
			if (listTA[i].getIdnumber() == filenumber) {
				listTA[i].report();
			}
		}

	}
	void modifyDO(int filenumber) {
		string name, family, phone;
		int a;
		for (int i = 0; i < listTA.size(); i++)
		{
			if (listTA[i].getIdnumber() == filenumber) {
				cout << "\n\n\n\tSELECT MENU";
				cout << "\n\n\n\t1. NAME";
				cout << "\n\n\t2. FAMILY";
				cout << "\n\n\t3. PHONE";
				cout << "\n\n\n\tEnter Choice (1/2/3)? ";
				cin >> a;
				switch (a)
				{
				case 1: cout << "Enter a name" << endl; cin >> name; listTA[i].setName(name); break;
				case 2: cout << "Enter a family" << endl; cin >> family; listTA[i].setFamily(family); break;
				case 3: cout << "Enter a phone" << endl; cin >> phone; listTA[i].setPhone(phone); break;

				}

			}
		}

	}
	void deleteallTA() {

		listTA.clear();

	}
	void delete_DO(int donumber) {


		for (int i = 0; i < listTA.size(); i++) {

			if (listTA[i].getIdnumber() != donumber) {

				listTA2.push_back(listTA[i]);


			}
		}

		listTA = listTA2;
		vector<Doctor>().swap(listTA2);


	}

	void printsavedpatient(int code) {

		multimap<int, string> list = getsavedpatient();
		for (multimap<int, string> ::iterator it = list.begin(); it != list.end(); it++) {

			if (code == it->first) {
				cout << it->second;
			}



		}

	}

	//##############################################################################
	//
	//###################################  MENU ####################################

	void intro() {
		system("cls");
		cout << "\n\n\n\t\t  SYSTEM HOSPITAL";
		cout << "\n\n\t\t  ADVANCED C++ PROJECT";
		cout << "\n\n\n\tMADE BY : MARYAM HAKIM";
		cout << "\n\tSCHOOL : QOM UNIVERSITY";
		cin.get();
	}
	void report_men() {

		int a, e, f, filenumber;
		system("cls");
		cout << "\n\n\n\tREPORT MENU";
		cout << "\n\n\n\t1. REPORTS";
		cout << "\n\n\t2. Back to Main Menu";
		cout << "\n\n\n\tEnter Choice (1/2/3)? ";
		cin >> a;
		switch (a)
		{
		case 1:
		{	system("cls");
		cout << "\n\n\n\tREPORTs MENU";
		cout << "\n\n\t1. PATIENT Reports";
		cout << "\n\n\t2. DOCTOR Reports";
		cout << "\n\n\n\tEnter Choice (1/2)? ";
		cin >> e;
		switch (e)
		{
		case 1:
		{	system("cls");
		cout << "\n\n\n\tSELECT";
		cout << "\n\n\t1. All Patient Report";
		cout << "\n\n\t2. Patient Report";
		cout << "\n\n\n\tEnter Choice (1/2)? ";
		cin >> f;
		switch (f)
		{
		case 1:  displayallpat(); break;
		case 2: cout << "\n Enter the number of patient: "; cin >> filenumber;
			displayonepat(filenumber); break;
		default:
			break;
		}

		break; }
		case 2:
		{	system("cls");
		cout << "\n\n\n\tSELECT";
		cout << "\n\n\t1. All Doctor Report";
		cout << "\n\n\t2. Doctor Report";
		cout << "\n\n\n\tEnter Choice (1/2)? ";
		cin >> f;
		switch (f)
		{
		case 1: displayallDoc(); break;
		case 2: cout << "\n Enter the number of doctor: "; cin >> filenumber;
			displayoneDO(filenumber); break;
		default:
			break;
		}

		break; }




		default:
			break;
		}


		break;

		}
		case 2:break;
		}

	}



	void entry_men() {
		int a, num;
		char choice;
		system("cls");
		cout << "\n\n\n\tENTRY MENU";
		cout << "\n\n\t1.ENTRY MENU PATIENT";
		cout << "\n\n\t2.ENTRY MENU DOCTOR";
		cout << "\n\n\t3.BACK TO MAIN MENU";
		cout << "\n\n\tPlease Enter Your Choice (1-3) ";

		cin >> a;
		switch (a)
		{
		case 1:
		{    system("cls");
		cout << "\n\n\n\tENTRY MENU PATIENT";
		cout << "\n\n\t1.CREATE PATIENT RECORD";
		cout << "\n\n\t2.MODIFY PATIENT RECORD";
		cout << "\n\n\t3.DELETE PATIENT RECORD";
		cout << "\n\n\t4.DELETE PATIENT RECORDS";
		cout << "\n\n\t5.BACK TO MAIN MENU";
		cout << "\n\n\tPlease Enter Your Choice (1-5) ";
		cin >> a;
		switch (a) {
		case 1:
			do {
				writest();
				cout << "\n patient record has been created";

				system("cls");
				cout << "Do you want to insert new record of patient? Y|N";
				cin >> choice;
				system("cls");
			} while (choice == 'Y' || choice == 'y');
			break;
		case 2: cout << "\nEnter the number of patient " << endl;
			cin >> num; modify(num); break;
			break;
		case 3: cout << "\nEnter the number of patient " << endl;
			cin >> num; delete_patient(num); break;
			break;
		case 4:  deleteallstudent(); break;
		case 5: break;
		}
		break;
		}
		case 2:
		{   system("cls");
		cout << "\n\n\n\tENTRY MENU DOCTOR";
		cout << "\n\n\t1.CREATE DOCTOR RECORD";
		cout << "\n\n\t2.MODIFY DOCTOR RECORD";
		cout << "\n\n\t3.DELETE DOCTOR RECORD";
		cout << "\n\n\t4.DELETE DOCTOR RECORDS";

		cout << "\n\n\t5.BACK TO MAIN MENU";
		cout << "\n\n\tPlease Enter Your Choice (1-5) ";
		cin >> a;
		switch (a) {
		case 1:
			do {
				writeDO();
				cout << "\n Doctor record has been created";

				system("cls");
				cout << "Do you want to insert new record of Doctor? Y|N";
				cin >> choice;
				system("cls");
			} while (choice == 'Y' || choice == 'y');
			break;
		case 2: cout << "\nEnter the number of doctor " << endl;
			cin >> num; modifyDO(num); break;
			break;
		case 3: cout << "\nEnter the number of doctor " << endl;
			cin >> num; delete_DO(num); break;
			break;
		case 4:  deleteallTA(); break;
		case 5: break;
		}
		break;
		}


		case 3:break;

		}
















	}




	int main()
	{
		int a;
		do {
			system("cls");
			cout << "\n\n\n\tMAIN MENU";
			cout << "\n\n\t01. REPORT MENU";
			cout << "\n\n\t02. ENTRY/EDIT MENU";
			cout << "\n\n\t03. EXIT";
			cout << "\n\n\tPlease Select Your Option (1-3) ";

			cin >> a;
			system("cls");
			switch (a)
			{
			case 1:report_men(); break;
			case 2:entry_men();
			case 3:break;
			}
		} while (a != 3);


		_getch();
		return 0;
	}


