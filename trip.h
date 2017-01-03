/****************************
* @Author					*
* Author name: Tuðba Özkal	*
* Student ID : 150120053	*
* Date		 : 04.06.2015	*
****************************/
#include<iostream>
#include<string>
#define size 50

using namespace std;

template<class T>
class Trip{
public:
	Trip();
	Trip(T);
	Trip(T*, const int);
	~Trip(){	delete[] tripPtr;	}
	void add(T &);
	void setDiscount(const double);
	friend ostream& operator<< (ostream&, const Trip<T> &);
	T operator+= (Trip<T> &);
	T operator[] (int);
	
private:
	int i = 0;
	double totalCost;
	T * tripPtr;
};

template<class T>
T Trip<T>::operator[](int n) {
	return tripPtr[n];
}

template<class T>
Trip<T>::Trip(){
	tripPtr = new T[size];
}

template<class T>
Trip<T>::Trip(T f) {
	tripPtr = new T[size];
	tripPtr[i] = f;
	totalCost = totalCost + f.cost();
	i++;
}

template<class T>
Trip<T>::Trip(T *fArr, const int num) {
	tripPtr = new T[size];
	for (int j = 0; j < num; j++){
		tripPtr[i] = fArr[j];
		totalCost = totalCost + fArr[j].cost();
		i++;
	}
}

template<class T>
void Trip<T>::add(T &f) {
	tripPtr = new T[size];
	tripPtr[i] = f;
	totalCost = totalCost + f.cost();
	i++;
}

template<class T>
ostream& operator<< (ostream& output, const Trip<T> &n){
	output << "Trip transfer count: " << n.i << endl;
	for (int j = 1; j < 25; j++){
		output << "*";
	}
	output << endl;
	for (int k = 1; k <= i; k++){
		ostream& operator<< (ostream& output, const Trip<T> &n);
		output << "Trip total cost: " << n.totalCost << endl;
	}
	for (int j = 1; j < 25; j++){
		output << "*";
	}
	output << endl;
	return output;
}

template<class T>
T Trip<T>::operator+=(Trip<T> &n) {
	tripPtr = new T[size];
	for (int j = 0; n[j] != NULL; j++){
		tripPtr[i + 1] = n[j];
		i++;
	}
}

template<class T>
void Trip<T>::setDiscount(const double dc){
	string err_msg = ("Discount out of range!");
	if (dc > 0 && dc < 40){
		cout << "Discount: " << dc << endl;
		double temp = 0;
		temp = totalCost * dc;
		temp /= 100;
		cout << "Discount amount: " << temp << endl;
		totalCost -= temp;
		cout << "Discounted cost: " << temp << endl;
	}
	else
		throw err_msg;
}