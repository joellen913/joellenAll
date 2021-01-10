/*Joellen Allah-Mensah
students/jallah/csc1710/hangmanGame.cpp
hangmanGame.cpp
10/28/2020
*/

//PPD's
#include<cstring>
#include<ctime>
#include<iostream>
#include <fstream>
#include<iomanip>
using namespace std;

//function prototypes
string getWord();
string empty(string &message2);
string lettersSoFar(string letters, char guess); 
void winner(int GuessCount, string message2, string blanks);

//return both functions to the message 
int main()
{
	//main variables 
	string word, message, message2, message3; 
	string letterGuess, letters; 
        char guess;  
	int guessCount=0;

	//playful cout statement 
	cout<<"Let's Play Hangman!"<<endl;
	
	//sets new variable equal to function 
	message2=getWord();
        message3=message2;

	cout<<message2; 	
	cout<<endl;
	 
	string blanks;
	//sets blanks equal to underscore function 
	blanks = empty(message3);

	//outputs underscores
	cout <<"Your word: "<< blanks;
	cout<<endl; 
	string underscore;
	string result; 
	
	cout<<endl;
	int x = 0, length;
	string letterGuesser; 
	//while guess is under 10 and they have not guessed the message
	int wrongGuess=0; 
	while((guessCount<=10)&&(blanks!=message))
        {
		//prompt to enter letter 
		cout<<"Enter a letter: ";
        	cin>>letterGuess;
                guess=letterGuess.at(0);  
		
		//output each letter guessed so far
		//there was an issue with this part, saw two TA's and neither could figure it out 
		
		letters[x]=guess; 
		length =letters.length();  //setting length equal to the letters length
		cout << "Letters guessed: ";
		for(int i=0; i<=length; i++)
		{
			//cout the letters in addiiton to the previous ones 
			cout << letters[i];
			x++; 
		}
		cout << endl;


        //variables
       		bool check=0;
        	//string message2;
        	//string letterGuess;

		//guess count uncrements 
		guessCount++;
		
	
		//while the letters dont fill in the underscores
		for(int i=0;i<message2.length();i++)
		{ 
			//if the letter guess is inside the message 
			if(guess==message2.at(i))
                	{
			//string blanks; 
			
				//set that letter to the position of the letter over the underscore 
                		blanks.replace(i,1,letterGuess);
                              
				//check if its true 
                        	check=1;

                       	}
                }  
		//if true 
                if (check==1)
                	{
				cout<<setw(18)<<blanks<<endl;  
                        	cout<<"Correct! "; 
               		}
                	else
                	{
			//cout the body part depending on how many times the letter was wrong 
			 
			wrongGuess++;
			
				//BODY PARTS 
				if(wrongGuess==1)
				{
					cout<<"Wrong, this has costed you a head"<<endl;
					cout<<setw(40)<<"_____________   "<<endl;
					cout<<setw(40)<<"|           |   "<<endl;
					cout<<setw(40)<<"|           |   "<<endl;
					cout<<setw(40)<<"|          ( )  "<<endl;	
					cout<<setw(40)<<"|               "<<endl;
					cout<<setw(40)<<"|               "<<endl;
					cout<<setw(40)<<"|               "<<endl;
					cout<<setw(40)<<"|               "<<endl;
					cout<<setw(40)<<"|               "<<endl;
					cout<<setw(40)<<"|               "<<endl;
					cout<<setw(40)<<"________        "<<endl;
					
				}
	
				else if(wrongGuess==2)
				{
					cout<<"Wrong, this has costed you a torso"<<endl;
                                        cout<<setw(40)<<"_____________   "<<endl;
                                        cout<<setw(40)<<"|           |   "<<endl;
                                        cout<<setw(40)<<"|           |   "<<endl;
                                        cout<<setw(40)<<"|          ( )  "<<endl;
                                        cout<<setw(40)<<"|          [_]  "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"________        "<<endl;
				}
				else if (wrongGuess==3)
				{
					cout<<"Wrong, this has costed you a left arm"<<endl;
                                        cout<<setw(40)<<"_____________   "<<endl;
                                        cout<<setw(40)<<"|           |   "<<endl;
                                        cout<<setw(40)<<"|           |   "<<endl;
                                        cout<<setw(40)<<"|          ( )  "<<endl;
                                        cout<<setw(40)<<"|         /[_]  "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"________        "<<endl;
				}
				 else if (wrongGuess==4)
                                {
                                        cout<<"Wrong, this has costed you a right arm"<<endl;
                                        cout<<setw(40)<<"_____________   "<<endl;
                                        cout<<setw(40)<<"|           |   "<<endl;
                                        cout<<setw(40)<<"|           |   "<<endl;
                                        cout<<setw(40)<<"|          ( )  "<<endl;
                                        cout<<setw(39)<<"|         /[_]\\"<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"________        "<<endl;
				}
				 else if (wrongGuess==5)
                                {
                                        cout<<"Wrong, this has costed you a left leg"<<endl;
                                        cout<<setw(40)<<"_____________   "<<endl;
                                        cout<<setw(40)<<"|           |   "<<endl;
                                        cout<<setw(40)<<"|           |   "<<endl;
                                        cout<<setw(40)<<"|          ( )  "<<endl;
                                        cout<<setw(39)<<"|         /[_]\\"<<endl;
                                        cout<<setw(40)<<"|          /    "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"________        "<<endl;
                                } 
				else if (wrongGuess==6)
                                {
                                        cout<<"Wrong, this has costed you a right leg"<<endl;
                                        cout<<setw(40)<<"_____________   "<<endl;
                                        cout<<setw(40)<<"|           |   "<<endl;
                                        cout<<setw(40)<<"|           |   "<<endl;
                                        cout<<setw(40)<<"|          ( )  "<<endl;
                                        cout<<setw(39)<<"|         /[_]\\"<<endl;
                                        cout<<setw(39)<<"|          / \\ "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"|               "<<endl;
                                        cout<<setw(40)<<"________        "<<endl;
                                }
				
				else if (wrongGuess==7)
                                {
                                        cout<<"Wrong, this has costed you a left eye"<<endl;
                                        cout<<setw(40)<<"_____________    "<<endl;
                                        cout<<setw(40)<<"|           |    "<<endl;
                                        cout<<setw(40)<<"|           |    "<<endl;
                                        cout<<setw(40)<<"|         (*  )  "<<endl;
                                        cout<<setw(39)<<"|         /[_]\\ "<<endl;
                                        cout<<setw(39)<<"|          / \\  "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"________         "<<endl;
                                }		
				else if (wrongGuess==8)
                                {
                                        cout<<"Wrong, this has costed you a right eye"<<endl;
                                        cout<<setw(40)<<"_____________    "<<endl;
                                        cout<<setw(40)<<"|           |    "<<endl;
                                        cout<<setw(40)<<"|           |    "<<endl;
                                        cout<<setw(40)<<"|         (* *)  "<<endl;
                                        cout<<setw(39)<<"|         /[_]\\ "<<endl;
                                        cout<<setw(39)<<"|          / \\  "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"________         "<<endl;
                                }
				else if (wrongGuess==9)
                                {
                                        cout<<"Wrong, this has costed you a nose"<<endl;
                                        cout<<setw(40)<<"_____________    "<<endl;
                                        cout<<setw(40)<<"|           |    "<<endl;
                                        cout<<setw(40)<<"|           |    "<<endl;
                                        cout<<setw(40)<<"|         (*.*)  "<<endl;
                                        cout<<setw(39)<<"|         /[_]\\ "<<endl;
                                        cout<<setw(39)<<"|          / \\  "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"________         "<<endl;
                                }

				else if (wrongGuess==10)
                                {
                                        cout<<"Wrong, this has costed you a frown!"<<endl;
                                        cout<<setw(40)<<"_____________    "<<endl;
                                        cout<<setw(40)<<"|           |    "<<endl;
                                        cout<<setw(40)<<"|           |    "<<endl;
                                        cout<<setw(40)<<"|         (*.*)  "<<endl;
					cout<<setw(40)<<"|           ^    "<<endl;
                                        cout<<setw(39)<<"|         /[_]\\ "<<endl;
                                        cout<<setw(39)<<"|          / \\  "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"|                "<<endl;
                                        cout<<setw(40)<<"________         "<<endl;
                                }
			cout<<"Wrong Guesses: "<<wrongGuess<<"/10"<<endl; 	
			cout<<endl; 
			}
		
	     
	//output users results
	if((blanks==message2)||(guessCount==10))
	{
		winner(guessCount, message2, blanks);
	break;          
	}        
}
	return 0;
}

string getWord()
{
	//variables 
	string filename, message;
	int messageNum=30;
	int wordSize;
	string str1;
	
	
        //prompt user to enter file
        ifstream inData; 
        cout<<"Enter the input file name: ";
	cin>>filename; 
	//opens string file 
        inData.open(filename.c_str());
	//gets random word 
	srand(time(0));
	//loops through string file until random line 
	for(int i=0;i<rand()%messageNum+1;i++)
	{
		//gets a random line in inData file, calls it message 
		getline(inData,message);
	}

	//closes file 
	inData.close();

	return message;

}


//function to replace word with underscores 
string empty(string &message2)
{ 
	
	string blanks;
	//message length loop
	for(int i=0;i<=message2.length();i++)
        {
	//blanks is equal to the message 
        blanks=message2; 
	//replace each message position character with an underscore 
	message2[i]='_';
	}
        return blanks;
}

//function to output users winning or losing result 
void winner(int guessCount, string message2, string blanks)
{ 
	string message; 
	//if the underscore is equal to the message and if the guess count is under ten times 
	if((blanks==message2)&&(guessCount<=10))
		//output their results
		cout<<"You win hangman!"<<endl;
	else 
		cout<<"Sorry, you lose hangman!"<<endl;
	
	//output the secret word
	//issue with this, nothing outputs for message
	cout<<"The secret word was \""<<message2<<"\"!"<<endl;
}



		
