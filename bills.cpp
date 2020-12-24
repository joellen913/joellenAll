/*Joellen Allah-Mensah
CSC 1710
08/27/2020
INTRO TO COMP SCI
*/

#include<iostream>
using namespace std;
int main()
{
int BILLS_1, BILLS_5, BILLS_10, BILLS_20, TOTAL;
	
	cout<<"ENTER YOUR NUMBER OF ONE DOLLAR BILLS:"<<endl;
	cin>>BILLS_1;

	cout<<"ENTER YOUR NUMBER OF FIVE DOLLAR BILLS:"<<endl;
	cin>>BILLS_5;

	cout<<"ENTER YOUR NUMBER OF TEN DOLLAR BILLS:"<<endl;
	cin>>BILLS_10;
	
	cout<<"ENTER YOUR NUMBER OF TWENTY DOLLAR BILLS:"<<endl;
	cin>>BILLS_20;

	TOTAL=1*BILLS_1+5*BILLS_5+10*BILLS_10+20*BILLS_20;
	cout<<"YOUR TOTAL AMOUNT OF MONEY EARNED IS"<<TOTAL<<endl;

	return 0;
}

