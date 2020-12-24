/*Joellen Allah-Mensah
10/09/2020
home/students/jallah/csc1710/lab8/AllahmensahLab8.cpp
AllahmensahLab8.cpp
*/
#include<iostream>
using namespace std;
int main()
{

	//variables, assign sum and sum variable to 1
	//variables assigned to long int to take in account for numbers up to 2.147,483,647(highest integer for long int)
	long int x, sum=1, factorial;
	long int n, sum2=1, factorial2, i;

	
				//FIRST SECTION(factorial)	


	//asks user to enter int to compute the first factorial, stores the number
	cout<<"enter an integer you want the factorial to be computed less than 13: "<<endl;
	cin>>factorial;
	
	//idiot proof for anything other than an integer greater than 12
	while(factorial>=13)
	{
		cout<<"Invalid input; please reenter an integer that does not exceed 13: "<<endl;
		cin>>factorial; 
	}
	//first part of cout statement
	cout<<factorial<<"!=";
	//when x is less than or equal to factorial, if 1 is less than factorial, "x" repeats and the integer multiplies from the last 
	for(x=1;x<=factorial;++x)
	{
		if (x<factorial)
		{
			cout<<x<<"x";
		}

		sum*=x;
		
		if (x==factorial)
		cout<<x;
	}
	//last part of cout, output sum/factorial answer 
	cout<<"="<<sum<<endl;
	
	//spacing
	cout<<endl;
	cout<<endl;
		
				//SECOND SECTION (double factorial)

	//asks user to enter another integer for double factorial, stores that second integer
	//maximum integer for long int for double factorial is 17 
	cout<<"Double Factorial - Enter another integer you want the double factorial to be computed that is less than 17: "<<endl;
	cin>>factorial2;
	
	//idiot proof 
	while(factorial>17)
	cout<<"Invalid input; please reenter an integer that does not exceed 17: "<<endl;


	
	//first part of cout
	cout<<factorial2<<"!!=";

	//n is initialized to 1
	n=1;
	//while n is less than or equal to the factorial entered, if n is an odd integer, sum is multiplied by n, n goes up one, loop repeats 
	do
	{
		if(n%2!=0)
		sum2*=n;
		n++;

	}while(n<=factorial2);

	//second part of cout
	//another way to find double factorial, when i is less than or equal to the factorial times 2, i increases to find odd numbers 
	for(int i=1 ; i<=2*factorial2 ; i++)
	{
		if (i<=factorial2)
		{
			//if number is odd and not factorial, output the number followed by "x"
			if ((i%2!=0)&&(i!=factorial2))
			{
				cout<<i<<"x";
			}
			//if the number is odd and if its the factorial, output only the number and no "x"
			else if((i%2!=0)&&(i==factorial2))
			{	
				cout<<i;
			}
		}
	}
	//last part of cout, outputs the sum/double factorial answer 
	cout<<"="<<sum2<<endl;

	//spacing
	cout<<endl;
	cout<<endl;


			//THIRD SECTION (geometric series)


	//new initializations, r is a constant
	int t;
	double a, sum3, j;
	double const r=0.50;
	//ask user for starting value and term number
	cout<<"Enter your starting value: "<<endl;
	cin>>a;
	

	//ask user for term they want to go up to
	cout<<"Enter the term you'd like to go up to: "<<endl;
	cin>>t;


	//first part of cout
	cout<<"Sum of "<<t<<" terms, a="<<a<<", r="<<r<<", is ";
	
	
	//when count=0, when count is less than terms, count increments by 1
	//sum adds to previous term, repeats
	//previous term is equal to term times ration, repeats
	for(j=0;j<t;j++)
	{
		sum3=sum3+a;
		a=a*r;
	}
	//output num
	cout<<sum3<<endl;


	return 0;
}











