#include<iostream>
using namespace std;

class Plane
{
	int ID;
	int TotalSeats;
	int Economy;
	int Business;
	bool stop;
	string Destination;
	string InBetween;
public:
	Plane()
	{
		TotalSeats = 60;
		Economy = 50;
		Business = 10;
		stop = false;
		Destination = "NULL";
		InBetween = "NULL";
	}
	Plane(int id, int E, int B, bool S, string D, string I)
	{
		ID = id;
		Economy = E;
		Business = B;
		TotalSeats = Economy + Business;
		stop = S;
		Destination = D;
		InBetween = I;
	}
	void setEconomy(int E)
	{
		Economy = E;
	}
	void setBusiness(int B)
	{
		Business = B;
	}
	void setStop(bool S)
	{

		if (S == true)
		{
			stop = S;
			cout << "Enter stop" << endl;
			cin >> InBetween;
		}
		else
		{
			stop = S;
			InBetween = "NULL";
		}
	}
	void setDestination(string D)
	{
		Destination = D;
	}
	int getTotalSeats()
	{
		return TotalSeats;
	}
	int getEconomy()
	{
		return Economy;
	}
	int getBusiness()
	{
		return Business;
	}
	string getDestination()
	{
		return Destination;
	}
	int getID()
	{
		return ID;
	}
	bool BookedBusiness()
	{
		if (Business > 0)
		{
			Business--;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool BookedEconomy()
	{
		if (Economy > 0)
		{
			Economy--;
			return true;
		}
		else
		{
			return false;
		}
	}
};