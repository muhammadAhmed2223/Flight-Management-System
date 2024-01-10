#include <iostream>
#include<fstream>
using namespace std;
class Admin : public User
{
public:
	Admin()
	{
		ID = 0;
	}
	Admin(int id):User(id)
	{

	}
	/* This could not be implemented due to violations occurred which i would be demonstrating now
	void ChangePlaneDetails()
	{
		Plane temp;
		int ID, choice = 0, pos;
		bool check;
		string tempstr;
		fstream fout("Plane.dat", ios::in | ios::binary | ios::out);
		cout << "List of Planes: " << endl;
		while (fout)
		{
			fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
			cout << temp.getID() << endl;
		}
		fout.seekg(0);
		cout << " " << endl;
		
		check = false;
		while (check == false)
		{
			cout << "Enter Plane ID" << endl;
			cin >> ID;
			while (fout)
			{
				fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
				if (temp.getID() == ID)
				{
					check = true;
				}
			}
			if (check == false)
			{
				cout << "Incorrect ID entered. Re-enter" << endl;
			}
		}
		fout.seekg(0);
		cout << " " << endl;
		
		while (choice != 5)
		{
			cout << "1. Change Destination\n2. Change Stop\n3. Remove Stop\n4. Change Seats\n5. Back" << endl;
			cout << "Enter choice" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Enter new Destination" << endl;
				cin >> tempstr;
				while (fout)
				{
					fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
					if (temp.getID() == ID)
					{
						temp.setDestination(tempstr);
						pos = fout.tellg();
						fout.seekp(pos);
						fout.write(reinterpret_cast <char*>(&temp), sizeof(temp));
					}
				}
				fout.seekg(0);
				break;
			case 2:
				cout << "Enter new Stop" << endl;
				cin >> tempstr;
				while (fout)
				{
					fout.read(reinterpret_cast <char*>(&temp), sizeof(temp));
					if (temp.getID() == ID)
					{
						temp.setDestination(tempstr);
						pos = fout.tellg();
						fout.seekp(pos);
						fout.write(reinterpret_cast <char*>(&temp), sizeof(temp));
					}
				}
				fout.seekg(0);
				break;
			}
		}
	}
	*/
};