#include<iostream>
#include<string> 
#include<fstream> 
#include<cstring> 
#include<iomanip> 
using namespace std;

//struct 
struct studentType
{
	string studentFName;
	string studentLName;
	string fullname; 
	int testScore;  
	char grade;
};
studentType students; //declare struct 

//prototypes
void loadArray(studentType students[], string names);
void assignGrade(studentType students[], string names);
int highestScore(studentType students[]);
void printResult(studentType students[], int loading); 

//main 
int main()
{
	string names; 
	int loading; 
	studentType students[20];  //initialize struct array to 20 
	loadArray(students, names); //calls loadArray 

	cout<<endl;   //spacing 
	cout<<endl;
	assignGrade(students, names);  //calls assign grade
	cout<<endl;
	loading=highestScore(students); //sets loading variable equal to highest score function 
	printResult(students, loading); //highest score function is passed to print result function
	return 0; 
} 

//function to load in array 
void loadArray(studentType students[], string names)
{

	ifstream inData;
	inData.open("names"); //opens datafile 
	
 	int i; 

	//reading in students data into struct array 
	for(i=0; i<20; i++)
	{
		//stores each part of struct to from datafile 
		inData>>students[i].studentFName>>students[i].studentLName>>students[i].testScore; 
	}
	
	//outputting the contents of struct 
	
	inData.close();  //close datafile 

}

//function to assign grade to student 
void assignGrade(studentType students[], string names)
{
	//structs
	string studentFName;
        string studentLName;

	//fullname=students[i].studentFName
	int testScore, scoress; 
	char grade; 

	cout<<"Student Name"<<setw(17)<<"Test Score"<<setw(9)<<"Grade"<<endl;
	int i; 
	for(i=0; i<20; i++)
	{
		if(students[i].testScore>=90)
			students[i].grade='A';
		else if(students[i].testScore>=80)
                        students[i].grade='B';
		else if(students[i].testScore>=70)
			students[i].grade='C';
		else if(students[i].testScore>=60)
                        students[i].grade='D';
                else if(students[i].testScore>=50)
                        students[i].grade='E';
		else
                        students[i].grade='F'; 

	
	scoress=students[i].testScore; //score struct reassigned to scoress variable 
	
	//concatination of first and last name struct set to new struct variable 
	students[i].fullname=students[i].studentLName+", "+students[i].studentFName; 
	cout<<left<<setw(20)<<students[i].fullname<<" "; //alignment and cout for fullname 
	cout<<right<<setw(5)<<scoress<<" "; //alignment and cout for scores
	cout<<right<<setw(10)<<students[i].grade<<" "<<endl; //alignment and cout for grades

	}

}

//function to find highest score 
int highestScore(studentType students[])
{
	//declarations 
	string studentFName;
        string studentLName;
	string names; 
        int testScore;
        char grade;
	int i;
	int largestIndex=0;

	//loop through each student
	for(i=1; i<20;i++)
	{
		//highest=students[i].testScore;
		if(students[i].testScore>students[largestIndex].testScore)
		{
			//reassign i to new variable 
			largestIndex=i; 
		} 
	}
	return largestIndex;
}

//function to print names of highest score 
void printResult(studentType students[], int large)
{
	string studentFName;
	string studentLName;
	string names; 
	int testScore;
	char grade; 

	int i; 
	
	//couts the highest test score found from function above 
	cout<<"Highest Test Score: "<<students[large].testScore<<endl;
	 
	
	cout<<"Students having the highest test score: "<<endl;
	for(i=0;i<20;i++)  //loops through students 
	{
		if(students[i].testScore==students[large].testScore)  //if students test score is the highest test score
			cout<<students[i].studentLName<<", "<<students[i].studentFName<<endl; //cout students full name 
	}
}
	
		
		



