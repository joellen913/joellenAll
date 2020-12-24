/*Joellen Allah-Mensah
home/students/jallah/csc1710/lab10
10/22/2020
AllahmensahLab10.cpp
*/

#include<iostream>
#include<cmath>
using namespace std;

//global variables for pi 
const double PI=3.14159;

//prototypes for distance and radius 
double distance(double x1, double y1, double x2, double y2);
double radius(double x1, double y1, double x2, double y2);
//circumeference and area with default value of 1
double circumference(double x1=1, double y1=1, double x2=1, double y2=1);
double area(double x1=1, double y1=1, double x2=1, double y2=1);
//overload distance prototype
double distance(double x2, double y2);
//overload radius prototype
double radius(double x2, double y2);
int main()
{

	//coordinate variables 
	double x1, y1, x2, y2;
	double rad;
	double radiusSum; 
	//prompts user to enter first coordinate 
	cout<<"Enter the coordinates of your first point, separated by a space: ";
	cin>>x1>>y1;
	cout<<endl;
	//second coordinates 
	cout<<"Now enter the coordinates of your second point, separated by a space: ";
	cin>>x2>>y2;
	cout<<endl;

	//outputs for distance 
	cout<<"Distance: "<<distance(x1, y1, x2, y2);
	//overload distance call
	cout<<distance(x2, y2)<<endl;
	//outputs for radius, circumference, and area 
	cout<<"Radius: "<<radius(x1, y1, x2, y2);
	//overload radius call
	cout<<radius(x2, y2)<<endl;
	cout<<"Circumference: "<<circumference(x1, y1, x2, y2)<<endl;
	cout<<"Area: "<<area(x1, y1, x2, y2)<<endl;

	return 0; 
}

//double function 
double distance(double x1, double y2, double x2, double y2)
{
	double distanceSum;
	distanceSum=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	//returns distance
	return distanceSum;
}

//radius function (where h & k are centers, x & y are the points of the circle)
double radius(double x1, double y1, double x2, double y2)
{
	double radiusSum;
	//sets new value equal to distance function call 
	radiusSum=distance(x1, y1, x2, y2);
	//returns radius
	return radiusSum;
}

//circumference function
double circumference(double x1, double y1, double x2, double y2)
{
	double circSum, rad;
       	rad=distance(x1, y1, x2, y2);
	circSum=2*PI*rad; 
	return circSum; 
	//returns circumference
}

//area function 
double area(double x1, double y1, double x2, double y2)
{
	double areaSum, radiusSum, rad; 
	rad=distance(x1, y1, x2, y2);
	areaSum=PI*pow(rad, 2);
	//returns area 
	return areaSum;
}

