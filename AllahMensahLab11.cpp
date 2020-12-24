/*
Joellen Allah-Mensah
students/jallah/csc1710/lab11/AllahmensahLab11.cpp
AllahmensahLab11.cpp
11/06/2020
*/

//ppds
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std; 

//prototypes 
int loadArray(int a[], string filename);
void printArray(int values[], int size);
void sortArray(int a[], int size); 
void median(int a[], int size);
void searchArray(int a[], int size);

 
int main()
{
	string filename; 
	//prompt to enter filename
	cout<<"Enter the array datafile name: ";
        cin>>filename;     //stores filename

	int sizeOfArray, a[100]; //initialize the size of array 
	int i;  
 
	sizeOfArray=loadArray(a, filename); //set variable equal to load array function 
	cout<<"Unsorted Array"<<endl; //title
	printArray(a, sizeOfArray);  //prints array

	cout<<endl; 
	
	cout<<"Sorted Array"<<endl; //title
	sortArray(a, sizeOfArray);  //sorts array
	printArray(a, sizeOfArray); //prints sorted array
	cout<<endl; 
	median(a, sizeOfArray);     //prints max, min, and median 	
	cout<<endl; 

	cout<<"Searching For A Number"<<endl;    //title
	searchArray(a, sizeOfArray); //prints search array function
	
		
	return 0; 

} 

//function prints array 
void printArray(int values[], int size)
{
 
	int j; 
 	
	//while looping through array, print out values 
	for(int j=0;j<size;j++)
        {
                cout<<"A["<<j<<"]="<<values[j]<<endl;

        }
}


//reads in array values 
int loadArray(int a[], string filename)
{
	
	//for inData 
	ifstream inData; 
	int i=0;
   
        //int i=0;
        //int a[11];
	int sizeOfArray;
	
     	//opens datafile 
        inData.open(filename.c_str());
	
	cout<<endl; 
	
	//inputs datafile into the array
	inData>>a[i];
	
	//while array isnt -1, loop through and output contents of array
	while(a[i]!=-1)
	{
		i++;
		inData>>a[i];
	}	
	
	//close file 
	inData.close();

	//return the contents of array 
	return i; 
}

//function to sort array 
void sortArray(int a[], int size)
{
	int index, smallestIndex, i, temp;

	
	//while looping through array, use Bubble sort 
	for(index=0; index<size-1;index++)
	{
		//smallest number is set to the currently read number 
		smallestIndex=index;
		for(i=smallestIndex+1;i<size;i++)
		{
			//if its less then the smallest num, smallest num becomes i 
			if(a[i]<a[smallestIndex])
				smallestIndex=i;
		}
		if(index!=smallestIndex)
		{
			//switches currently read value with smallest value 
			temp=a[smallestIndex];
			a[smallestIndex]=a[index];
			a[index]=temp;
		}
	}
}		

//function to find max, min, and median 
void median(int a[], int size)
{
	int sizeOfArray, max, i;  

	//min
	cout<<"Minimum Value"<<endl; 
	//takes min value from sort array
	cout<<"A[0]="<<a[0]<<endl;

	cout<<endl; 

	cout<<"Maximum Value"<<endl; 
	//takes max value from sort array 
	cout<<"A["<<size-1<<"]="<<a[size-1]<<endl;
		
}

//function to search for integer 
void searchArray(int a[], int size)
{
	int checkInt; 

	//user prompt
	cout<<"Enter a non-negative integer: ";
	cin>>checkInt;
	
	int count=0;

	//loop through array 
	for (int i=0; i<size; i++)
	{
		//if that number is in the array, count it 
		if (a[i]==checkInt)
			++count;
	}
	//final output 
	cout<<"Number of occurences of the integer "<<checkInt<<": "<<count<<endl; 
 
}

