#include <iostream>
using namespace std;
class Passenger: public User
{
	string Passport;
	bool visa;
	bool local;
public:
	Passenger()
	{
		Passport = " ";
		visa = false;
		local = false;
		ID = 0;
	}
	Passenger(int id):User(id)
	{
		Passport = " ";
		visa = false;
		local = false;
	}
	void setPassport(string P)
	{	
		Passport = P;
	}
	void setVisa(bool S)
	{
		visa = S;
	}
	void setLocal(bool L)
	{
		local = L;
	}

	string getPassport()
	{
		return Passport;
	}
};