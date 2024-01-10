#include <iostream>
using namespace std;
class User
{
protected:
	string CNIC;
	int ID;
	string UserName;
	string Password;
public:
	User()
	{
		ID = 0;
	}
	User(int id)
	{
		ID = id;
	}
	/*
	bool login(string Name, string P)
	{

	}
	*/
	void SetPassword(string P)
	{
		Password = P;
	}
	void SetUserName(string N)
	{
		UserName = N;
	}
	void SetCNIC(string C)
	{
		CNIC = C;
	}
	void setID(int id)
	{
		ID = id;
	}
	int getID()
	{
		return ID;
	}
	string getCNIC()
	{
		return CNIC;
	}

	string getName()
	{
		return UserName;
	}

	string getPassword()
	{
		return Password;
	}
	
};