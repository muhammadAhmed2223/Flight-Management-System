//20I-0498
//Muhammad Ahmed
//CS-E
//Project

#include <iostream>
#include <conio.h>
#include <fstream>
#include "Plane.h"
#include "User.h"
#include "Admin.h"
#include "Passenger.h"
using namespace std;

string ChooseIDestination()
{
	int choice;
	
	while (1)
	{
		cout << "Choose Destination: " << endl;
		cout << "1. USA\n2. UAE\n3. Canada\n4. Sweden\n5. Turkey\n6. Norway\n7. KSA\n8. Spain\n9. France\n10. Portugal" << endl;
		cout << "Enter your choice " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			return "USA";
			break;
		case 2:
			return "UAE";
			break;
		case 3:
			return "Canada";
			break;
		case 4:
			return "Sweden";
			break;
		case 5:
			return "Turkey";
			break;
		case 6:
			return "Norway";
			break;
		case 7:
			return "KSA";
			break;
		case 8:
			return "Spain";
			break;
		case 9:
			return "France";
			break;
		case 10:
			return "Portugal";
			break;
		default:
			cout << "Re-enter" << endl;
			break;
		}
	}
	
}
string ChooseLDestination()
{
	int choice;
	while (1)
	{
		cout << "Choose Destination:" << endl;
		cout << "1. Islamabad\n2. Lahore\n3. Quetta\n4. Peshawar\n5. Karachi" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			return "Islamabad";
			break;
		case 2:
			return "Lahore";
			break;
		case 3:
			return "Quetta";
			break;
		case 4:
			return "Peshawar";
			break;
		case 5:
			return "Karachi";
			break;
		default:
			cout << "Re-enter" << endl;
			break;
		}
	}
	
}

void NewRegisterPassenger()
{
	string tempName, tempPassword, confirmPassword, CNIC, PassportNum, tempstr;
	Passenger reg;
	Passenger temp;
	int tempid = 0;
	ifstream fout;
	fout.open("D:\\Passenger.dat", ios::binary);

	if (!fout)
	{
		cout << "Not opened" << endl;
	}
	
	fout.seekg(0);
	fout.clear();
	if (fout.tellg() == -1)
	{
		reg.setID(0);
	}
	else
	{
		fout.seekg(0);
		while (!fout.eof())
		{
			fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
			tempid = temp.getID();
		}
		reg.setID(tempid + 1);
	}

	cout << "Enter CNIC" << endl;
	cin >> CNIC;
	while (CNIC.length() != 13)
	{
		cout << "CNIC must be 13 digit. Re-enter" << endl;
		cin >> CNIC;
	}

	fout.clear();
	fout.seekg(0);

	cout << "teelg is "  << fout.tellg() << endl;

	while (!fout.eof())
	{
		fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
		while (temp.getCNIC() == CNIC)
		{
			cout << "CNIC already exists. Re-enter" << endl;
			cout << "Enter CNIC" << endl;
			cin >> CNIC;
			while (CNIC.length() != 13)
			{
				cout << "CNIC must be 13 digit. Re-enter" << endl;
				cin >> CNIC;
			}
			fout.seekg(0, ios::beg);
		}
		if (fout.tellg() == -1)
		{
			break;
		}
	}

	reg.SetCNIC(CNIC);

	cout << "Enter UserName" << endl;
	cin >> tempName;

	fout.clear();
	fout.seekg(0);

	while (!fout.eof())
	{
		fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
		if (temp.getName() == tempName)
		{
			cout << "UserName already exists. Re-enter" << endl;
			cout << "Enter UserName" << endl;
			cin >> tempName;
			fout.seekg(0);
		}
		if (fout.tellg() == -1)
		{
			break;
		}
	}

	reg.SetUserName(tempName);

	bool passwordcheck = false;
	char pwd[9];
	int i;
	while (passwordcheck == false)
	{
		cout << "Enter New Password" << endl;
		for (i = 0; i < 8; i++)
		{
			pwd[i] = _getch();
			cout << "*";
		}
		pwd[i] = '\0';
		cout << endl;
		tempPassword = pwd;
		if (tempPassword.length() != 8)
		{
			cout << "Password must be of 8 characters. RE-enter" << endl;
			passwordcheck = false;
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				if (tempPassword[i] >= 65 && tempPassword[i] <= 90)
				{
					passwordcheck = true;
				}
			}
			if (passwordcheck == false)
			{
				cout << "Password must have atleast one Upper Case letter" << endl;
			}

			if (passwordcheck == true)
			{
				passwordcheck = false;
				for (int i = 0; i < 8; i++)
				{
					if (tempPassword[i] >= 97 && tempPassword[i] <= 122)
					{
						passwordcheck = true;
					}
				}
				if (passwordcheck == false)
				{
					cout << "Password must have atleast one Lower Case letter" << endl;
				}

				if (passwordcheck == true)
				{
					passwordcheck = false;
					for (int i = 0; i < 8; i++)
					{
						if ((tempPassword[i] >= 33 && tempPassword[i] <= 47) || (tempPassword[i] >= 58 && tempPassword[i] <= 64) || (tempPassword[i] >= 91 && tempPassword[i] <= 96) || (tempPassword[i] >= 123 && tempPassword[i] <= 126))
						{
							passwordcheck = true;
						}
					}
					if (passwordcheck == false)
					{
						cout << "Password must have atleast one Special Character" << endl;
					}

					if (passwordcheck == true)
					{
						passwordcheck = false;
						for (int i = 0; i < 8; i++)
						{
							if (tempPassword[i] >= 48 && tempPassword[i] <= 57)
							{
								passwordcheck = true;
							}
						}
						if (passwordcheck == false)
						{
							cout << "Password must have atleast one Numeric Character" << endl;
						}
					}
				}
			}
		}
	}

	cout << "Re-enter Password" << endl;
	for (i = 0; i < 8; i++)
	{
		pwd[i] = _getch();
		cout << "*";
	}
	pwd[i] = '\0';
	confirmPassword = pwd;
	cout << endl;

	while (tempPassword != confirmPassword)
	{
		cout << "Passwords do not match. Re-enter" << endl;
		cout << "Re-enter to Confirm Password" << endl;
		for (i = 0; i < 8; i++)
		{
			pwd[i] = _getch();
			cout << "*";
		}
		pwd[i] = '\0';
		confirmPassword = pwd;
		cout << endl;
	}

	reg.SetPassword(tempPassword);

	cout << "Enter Passport Number" << endl;
	cin >> PassportNum;

	fout.clear();
	fout.seekg(0);

	while (!fout.eof())
	{
		fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
		if (temp.getPassport() == PassportNum)
		{
			cout << "Passport number already exists. Re-enter" << endl;
			cout << "Enter Passport Number" << endl;
			cin >> PassportNum;
			fout.seekg(0);
		}
		if (fout.tellg() == -1)
		{
			break;
		}
	}

	reg.setPassport(PassportNum);

	char check;

	cout << "Does your passport have VISA stamp? (Y/N)" << endl;
	cin >> check;
	while (check != 'Y' && check != 'N')
	{
		cout << "Incorrect choice. Only Y or N. Re-enter" << endl;
		cout << "Does your passport have VISA stamp? (Y/N)" << endl;
		cin >> check;
	}
	if (check == 'Y')
	{
		reg.setVisa(true);
	}
	else
	{
		reg.setVisa(false);
	}

	cout << "Is your Passport:\n 1. Local\n 2. Foreign?" << endl;
	cin >> check;
	while (check != '1' && check != '2')
	{
		cout << "Incorrect choice. Only 1 or 2. Re-enter" << endl;
		cout << "Is your Passport:\n 1. Local\n 2. Foreign?" << endl;
		cin >> check;
	}
	if (check == '1')
	{
		reg.setLocal(true);
	}
	else
	{
		reg.setLocal(false);
	}

	fout.close();

	//Add to a new Passenger object
	ofstream fin;
	fin.open("D:\\Passenger.dat", ios::binary | ios::app);
	if (!fin)
	{
		cout << "Error" << endl;
	}
	else
	fin.write(reinterpret_cast <char*>(&reg), sizeof(reg));
	fin.close();

	cout << "Done";
}


void NewRegisterAdmin()
{
	Admin reg;
	int choice = 0, tempid = 0;
	string tempName, tempPassword, confirmPassword, CNIC;
	Admin temp;
	ifstream fout("D:\\Admin.dat", ios::binary);
	if (!fout)
	{
		cout << "Not opened" << endl;
	}

	fout.seekg(0);
	fout.clear();
	if (fout.tellg() == -1)
	{
		reg.setID(0);
	}
	else
	{
		fout.seekg(0);
		while (!fout.eof())
		{
			fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
			tempid = temp.getID();
		}
		reg.setID(tempid + 1);
	}

	cout << "Enter CNIC" << endl;
	cin >> CNIC;
	while (CNIC.length() != 13)
	{
		cout << "CNIC must be 13 digit. Re-enter" << endl;
		cin >> CNIC;
	}

	fout.clear();
	fout.seekg(0);

	cout << "teelg is " << fout.tellg() << endl;

	while (!fout.eof())
	{
		fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
		while (temp.getCNIC() == CNIC)
		{
			cout << "CNIC already exists. Re-enter" << endl;
			cout << "Enter CNIC" << endl;
			cin >> CNIC;
			while (CNIC.length() != 13)
			{
				cout << "CNIC must be 13 digit. Re-enter" << endl;
				cin >> CNIC;
			}
			fout.seekg(0, ios::beg);
		}
		if (fout.tellg() == -1)
		{
			break;
		}
	}

	reg.SetCNIC(CNIC);

	cout << "Enter UserName" << endl;
	cin >> tempName;

	fout.clear();
	fout.seekg(0);

	while (!fout.eof())
	{
		fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
		if (temp.getName() == tempName)
		{
			cout << "UserName already exists. Re-enter" << endl;
			cout << "Enter UserName" << endl;
			cin >> tempName;
			fout.seekg(0);
		}
		if (fout.tellg() == -1)
		{
			break;
		}
	}

	reg.SetUserName(tempName);


	bool passwordcheck = false;

	char pwd[9];
	int i;
	while (passwordcheck == false)
	{
		cout << "Enter New Password" << endl;
		for (i = 0; i < 8; i++)
		{
			pwd[i] = _getch();
			cout << "*";
		}
		pwd[i] = '\0';
		cout << endl;
		tempPassword = pwd;
		if (tempPassword.length() != 8)
		{
			cout << "Password must be of 8 characters. RE-enter" << endl;
			passwordcheck = false;
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				if (tempPassword[i] >= 65 && tempPassword[i] <= 90)
				{
					passwordcheck = true;
				}
			}
			if (passwordcheck == false)
			{
				cout << "Password must have atleast one Upper Case letter. RE-enter" << endl;
			}

			if (passwordcheck == true)
			{
				passwordcheck = false;
				for (int i = 0; i < 8; i++)
				{
					if (tempPassword[i] >= 97 && tempPassword[i] <= 122)
					{
						passwordcheck = true;
					}
				}
				if (passwordcheck == false)
				{
					cout << "Password must have atleast one Lower Case letter. Re-enter" << endl;
				}

				if (passwordcheck == true)
				{
					passwordcheck = false;
					for (int i = 0; i < 8; i++)
					{
						if ((tempPassword[i] >= 33 && tempPassword[i] <= 47) || (tempPassword[i] >= 58 && tempPassword[i] <= 64) || (tempPassword[i] >= 91 && tempPassword[i] <= 96) || (tempPassword[i] >= 123 && tempPassword[i] <= 126))
						{
							passwordcheck = true;
						}
					}
					if (passwordcheck == false)
					{
						cout << "Password must have atleast one Special Character. Re-enter" << endl;
					}

					if (passwordcheck == true)
					{
						passwordcheck = false;
						for (int i = 0; i < 8; i++)
						{
							if (tempPassword[i] >= 48 && tempPassword[i] <= 57)
							{
								passwordcheck = true;
							}
						}
						if (passwordcheck == false)
						{
							cout << "Password must have atleast one Numeric Character. Re-enter" << endl;
						}
					}
				}
			}
		}
	}

	cout << "Re-enter Password" << endl;
	for (i = 0; i < 8; i++)
	{
		pwd[i] = _getch();
		cout << "*";
	}
	pwd[i] = '\0';
	confirmPassword = pwd;
	cout << endl;

	while (tempPassword != confirmPassword)
	{
		cout << "Passwords do not match. Re-enter" << endl;
		cout << "Re-enter to Confirm Password" << endl;
		for (i = 0; i < 8; i++)
		{
			pwd[i] = _getch();
			cout << "*";
		}
		pwd[i] = '\0';
		confirmPassword = pwd;
		cout << endl;
	}

	reg.SetPassword(tempPassword);

	//Add to a new Admin object
	ofstream fin("D:\\Admin.dat", ios::binary | ios::out | ios::app);
	fin.write(reinterpret_cast <char*>(&reg), sizeof(reg));


}

void ViewDetails()
{
	cout << "NPAFS has established a network of flights in 25 countries around the globe.\n Due to COVID situation some countries have travel bans.\n NPAFS greatly value its passengers and abide by the international travelling laws.\n 50,000 passengers use NPAFS annually.\n Ten Local flights and Five International flights take off from each airport on daily basis depending on their schedule.\n Each plane of NPAFS has seating capacity of 50 passengers in economy class and 10 in business class during the COVID days.\n The days passengers are seated with a gap of one seat." << endl;
}

void Register()
{
	int choice = 0;
	while (choice != 3)
	{
		cout << "1. Admin\n2. Passenger\n3. Back" << endl;
		cin >> choice;
		while (choice < 1 || choice > 3)
		{
			cout << "Re-Enter" << endl;
			cout << "1. Admin\n2. Passenger\n3. Back" << endl;
			cin >> choice;
		}
		if (choice == 1)
		{
			NewRegisterAdmin();
		}
		else if (choice == 2)
		{
			NewRegisterPassenger();
		}
	}
}

void Login()
{
	Passenger temp;
	string name, password;
	char pwd[9];
	int i;
	bool check = false;
	ifstream fout;
	fout.open("D:\\Passenger.dat", ios::binary);

	cout << "Enter Username" << endl;
	cin >> name;

	while (!fout.eof())
	{
		fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
		if (name == temp.getName())
		{
			check = true;
			cout << "Enter Password" << endl;
			for (i = 0; i < 8; i++)
			{
				pwd[i] = _getch();
				cout << "*";
			}
			pwd[i] = '\0';
			cout << endl;
			password = pwd;
			if (password != temp.getPassword())
			{
				cout << "Incorrect Password" << endl;
			}
			else
			{
				cout << "Successfully logged in. Welcome " << temp.getName() << endl;
			}
		}
		if (fout.tellg() == -1)
		{
			break;
		}
	}

	if (check == false)
	{
		cout << "Username does not exist" << endl;
	}
}

int main()
{
	int choice = 0;

	cout << "Welcome to NPAFS System" << endl;
	
	while (1)
	{
		cout << "1. View Details\n2. Login\n3. Register\nEnter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			ViewDetails();
			break;
		case 2:
			Login();
			break;
		case 3:
			Register();
			break;
		}
	}
	
}