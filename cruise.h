/****************************
* @Author					*
* Author name: Tuðba Özkal	*
* Student ID : 150120053	*
* Date		 : 04.06.2015	*
*****************************/

#include<iostream>

using namespace std;

class Cruise{
private:
	string cName;
	double cCost;
public:
	Cruise(){}
	Cruise(string name, double cost){
		cName = name;
		cCost = cost;
	}

	void setCost(const double);
	double cost();
	friend ostream& operator<<(ostream& output, const Cruise &n);
	Cruise * c;
};

void Cruise::setCost(const double newCost){
	cCost = newCost;
}

double Cruise::cost(){
	return cCost;
}

template<class T>
ostream& operator<< (ostream& output, const Cruise &n){
	output << "Flight Name: " << n.cName << "#" << n.cID << "Cost: " << n.cCost << endl;
	return output;
}