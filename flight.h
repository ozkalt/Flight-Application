/****************************
* @Author					*
* Author name: Tuðba Özkal	*							
* Student ID : 150120053	*							
* Date		 : 04.06.2015	*
*****************************/

#include<iostream>
#include<string>

using namespace std;

class Flight {
private:
	string cName, cID;
	double cCost;
public:
	Flight(){}
	Flight(string name, string ID, double cost){
		cName = name;
		cID = ID;
		cCost = cost;
	}

	void setCost(const double);
	double cost();
	friend ostream& operator<<(ostream& output, const Flight &n);
};

void Flight::setCost(const double newCost){
	cCost = newCost;
}

double Flight::cost(){
	return cCost;
}

template<class T>
ostream& operator<< (ostream& output, const Flight &n){
	output << ". Flight Name: " << n.cName << "#" << n.cID << "Cost: " << n.cCost << endl;
	return output;
}