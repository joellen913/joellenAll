//Joellen Allah-Mensah
//Lauren Cookman
//Collin Senecal
#include<iostream>
#include<ctime>
#include<string>
#include<iomanip>
using namespace std;

//rules of the game: 2 players roll 4 dice, the first person to get all 4 dice to match wins!


int main()
{
	int number;
	//Player one variables 
	int p1num=1, p1counter=0;
	string player1;
	int p1dice1, p1dice2, p1dice3, p1dice4;

	//Player Two Variables
	int p2num=1, p2counter=0;
	string player2;
	int p2dice1, p2dice2, p2dice3, p2dice4;

	cout<<"Lets play a Game! You vs. Your friend: The first one to roll all die the same number wins!"<<endl;
	cout<<endl;
	
	//first player
	cout<<"Please enter your name: ";
	cin>>player1;
	
	//second player
	cout<<"Please enter your friends name: ";
	cin>>player2;

	//chose special number
	cout<<"Choose a special number: ";
	cin>>number;
	
	//call for random number 
	srand(time(0));


	//PLAYER ONES ATTEMPTS 
	do
	{
		//rolls
		p1dice1=rand()%6+1;
		p1dice2=rand()%6+1;
		p1dice3=rand()%6+1;
		p1dice4=rand()%6+1;
	
		p1num++;
		p1counter++;
		

	}while((p1dice1!=number)||(p1dice2!=number)||(p1dice3!=number)||(p1dice4!=number));

		cout<<setw(30)<<player1<<"'s Rolls"<<endl;
		cout<<setw(14)<<"Attempt #"<<setw(10)<<"Dice 1"<<setw(8)<<"Dice 2"<<setw(8)<<"Dice 3"<<setw(8)<<"Dice 4"<<endl;
		cout<<setw(12)<<p1num<<setw(10)<<p1dice1<<setw(8)<<p1dice2<<setw(8)<<p1dice3<<setw(8)<<p1dice4<<endl;

	
	//PLAYER TWO (FRIEND)'S ATTEMPTS
	do
	{
		//rolls
		p2dice1=rand()%6+1;
		p2dice2=rand()%6+1;
		p2dice3=rand()%6+1;
		p2dice4=rand()%6+1;
		
		p2num++;
		p2counter++;

	}while((p2dice1!=number)||(p2dice2!=number)||(p2dice3!=number)||(p2dice4!=number));
		
		cout<<setw(64)<<player2<<"'s Rolls"<<endl;	
		cout<<setw(59)<<"Attempt #"<<setw(10)<<"Dice 1"<<setw(8)<<"Dice 2"<<setw(8)<<"Dice 3"<<setw(8)<<"Dice 4"<<endl;
		cout<<setw(57)<<p2num<<setw(10)<<p2dice1<<setw(8)<<p2dice2<<setw(8)<<p2dice3<<setw(8)<<p2dice4<<endl;
		
		


	//output each players number of attempts 	
	cout<<player1<<"'s Attempts: "<<p1counter<<endl;
	cout<<player2<<"'s Attempts: "<<p2counter<<endl;

	//declare winner 
	if(p1counter<p2counter)
	{
		cout<<"The winner of this game is "<<player1<<"!"<<endl;
	}
	if (p2counter<p1counter)
	{
		cout<<"The winner of this game is "<<player2<<"!"<<endl;
	}


	return 0;


}


