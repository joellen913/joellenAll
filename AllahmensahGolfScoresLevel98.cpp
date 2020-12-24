/* 
Joellen Allah-Mensah
students/jallah/csc1710/AllahmensahGolfScores98.cpp
AllahmensahGolfScores98.cpp
11/11/2020

Options Chosen To Code:
- grade level A program (92%) 
- 9-hole subtotal function (6%)
*/

//ppd's
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<iomanip>
using namespace std;

//prototypes
void loadArrays(int par[], string names[], int results[][30], string scores);
void pplresults(int par[], string names[], int results[][30], string scores);
void scoreTotalsAndNineHoleSubtotals(int par[], string names[], int results[][30], string scores);
void nineHoleSubtotal(int par[], string names[], int results[][30], string scores);
void winner(int par[], string names[], int results[][30], string scores);


int main()
{

	//variables 
	int par[20]; //initialise pars to 20 elements
	string scores; 
	string names[5]; //initialize names to 5
	int results[30][30]; //initialize results to 30 by 30 
        int col;
	int name1sum, name2sum, name3sum, name4sum; 
	int player1strokes, player2strokes, player3strokes, player4strokes;
	int name1SecondHalf, name2SecondHalf, name3SecondHalf, name4SecondHalf;

	//function calls 
	loadArrays(par, names, results, scores);
	scoreTotalsAndNineHoleSubtotals(par, names, results, scores);
	cout<<endl; //spacing 
	winner(par, names, results, scores);
	pplresults(par, names, results, scores);

	return 0;
}

//first function, loads each part of the datafile array into variables 
void loadArrays(int par[], string names[], int results[][30], string scores)
{

        int col;
	
        ifstream inData; //declare inData

        inData.open("scores"); //opens datafile 

        //pars
        for(int i=0; i<18; i++)	//loops and stores pars 
        {
                inData>>par[i];
        }

        //names
        for(int i=0; i<4;i++)  //loops and stores names of players 
        {
                inData>>names[i];
        }

        //scores
        for(int row=0; row<18;row++)    //loops and stores the players scores using 2 dimensional array 
        {
                for(col=0; col<4;col++)
                {
                        inData>>results[row][col];
                }
        }

	inData.close();
}

//second function-outputs the total scores of each player as well as their 9 hole subtotals 
void scoreTotalsAndNineHoleSubtotals(int par[], string names[], int results[][30], string scores)
{

	
			//first players score total 
	int name1sum=0;
	int col;
	int name1SecondHalf, name2SecondHalf, name3SecondHalf, name4SecondHalf;
	for(int row=0; row<18;row++)
        {
		for(col=0; col<1;col++)
                {
			name1sum+=results[row][col];  //adds up the contents of the first row, stores it 
			
                }
	
	}
		
		
			//second players score total
	int name2sum=0;
      	
        for(int row=0; row<18;row++)
        {
		for(col=1; col<2;col++)
                {
			name2sum+=results[row][col];  //adds up the contents of the second row, stores it 
                }
        	
        }
	
 	
	
			//third players score total 
	int name3sum=0;

        for(int row=0; row<18;row++)
        {
                for(col=2; col<3;col++)
                {
                        name3sum+=results[row][col];   //adds up the contents of the third row, stores it 
                }
                 
        }
               
	 	

		//fourth players score total 
	int name4sum=0;

        for(int row=0; row<18;row++)
        {
                for(col=3; col<4;col++)
                {
                        name4sum+=results[row][col];  //adds up the contents of the fourth row, stores it 
                }
	
        }


							//SCORES AND NINE HOLE SUBTOTALS 
				
	//outputs the first name and its score 
        for(int i=0; i<1;i++)
        {
                cout<<setw(8)<<right<<names[i]<<" "<<setw(4)<<name1sum;
        }

	//subtotal for name 1
        int name1FirstHalf=0;
        for(int row=0; row<9;row++)
        {
                for(col=0; col<1;col++)
                {
                        name1FirstHalf+=results[row][col];  //adds up the pars for the first half of the game

                }
        }

        name1SecondHalf=name1sum-name1FirstHalf; //gets second half by subtracting first half by their total score
        cout<<setw(5)<<"("<<name1FirstHalf<<" - "<<name1SecondHalf<<")"<<endl;   //subtracts the firsthalf par score with the total par score to get 2nd half 



	//output second name and its score
	for(int i=1; i<2;i++)
        {
                cout<<setw(8)<<right<<names[i]<<" "<<setw(4)<<name2sum; 
        }


       	//subtotal for name 2
        int name2FirstHalf=0;
        for(int row=0; row<9;row++)
        {
                for(col=1; col<2;col++)
                {
                        name2FirstHalf+=results[row][col]; //adds up the pars for the first half of the game
                }
        }

        name2SecondHalf=name2sum-name2FirstHalf; //gets second half by subtracting first half by their total score
        cout<<setw(5)<<"("<<name2FirstHalf<<" - "<<name2SecondHalf<<")"<<endl;  //subtracts the firsthalf par score with the total par score to get 2nd half 


	//outputs the third name and its score
	for(int i=2; i<3;i++)
        {
                cout<<setw(8)<<right<<names[i]<<" "<<setw(4)<<name2sum;
        }

       
 	//subtotal for name 3
        int name3FirstHalf=0;
        for(int row=0; row<9;row++)
        {
                for(col=2; col<3;col++)
                {
                        name3FirstHalf+=results[row][col]; //adds up the pars for the first half of the game		
                }
        }

        name3SecondHalf=name3sum-name3FirstHalf; //gets second half by subtracting first half by their total score
        cout<<setw(5)<<"("<<name3FirstHalf<<" - "<<name3SecondHalf<<")"<<endl;  //subtracts the firsthalf par score with the total par score to get 2nd half


	//outputs the fourth name and its score 
	for(int i=3; i<4;i++)
        {
                cout<<setw(8)<<right<<names[i]<<" "<<setw(4)<<name4sum;
        }


	//subtotal for name 4
        int name4FirstHalf=0;
        for(int row=0; row<9;row++)
        {
                for(col=3; col<4;col++)
                {
                        name4FirstHalf+=results[row][col];   //adds up the pars for the first half of the game
                }
        }

        name4SecondHalf=name4sum-name4FirstHalf; //gets second half by subtracting first half by their total score
        cout<<setw(5)<<"("<<name4FirstHalf<<" - "<<name4SecondHalf<<")"<<endl;  //subtracts the firsthalf par score with the total par score to get 2nd half


}
	

//third function to output the pars of each player and their totals, as well as their strokes 
void pplresults(int par[], string names[], int results[][30], string scores)
{
	
	int parSum; 
	int col;
	int player1strokes, player2strokes, player3strokes, player4strokes; 

	//outputs numbers 1-18 using variable "a"
	cout<<endl;
	
	cout<<setw(10);
	for(int a=1; a<9;a++)
	{
		cout<<a<<"  ";
	}                           //put into two seperate loops for spacing concerns 
	 for(int a=9; a<19;a++)
        {
                cout<<a<<" ";
        }


	cout<<setw(8)<<"Score"; //score title 
	
	cout<<endl; 

	//name 1
	for(int i=0; i<1;i++)
        {
                cout<<setw(8)<<right<<names[i]<<" ";
        }
        
	//name one's column
	for(int col=0; col<1;col++)
        {
                for(int row=0; row<18; row++)
                {		
			int i=0; 
		
			//accounting for birdies and eagles 
			if (par[row]-results[row][col]==1)  //if the par-the players par value is 1, its a birdie
			{
				cout<<results[row][col]<<"*"<<" ";
			}		
			else if(par[row]-results[row][col]==2) //if the par - the player pars value is 2, its an eagle
			{
				cout<<results[row][col]<<"!"<<" ";
			}
			else   //else, output normal par value
			{
				cout<<results[row][col]<<"  ";
			}	
			 
			//cout<<results[row][col]<<"  ";                               		
               	}

       	}
	
	//name 1 score 	
	int name1sum=0; 
	for(int row=0; row<18;row++)
	{
                for(col=0; col<1;col++)
                {
			name1sum+=results[row][col];
                }
	}
	cout<<setw(5)<<name1sum<<endl;   //outputs total score
    
	
	 //name 2
        for(int i=1; i<2;i++)
        {
                cout<<setw(8)<<right<<names[i]<<" ";
        }

        //name two's column
        for(int row=0; row<18;row++)
        {
                for(col=1; col<2;col++)
                {
			//birdies and eagles same process

                	int i=0;
                        if (par[row]-results[row][col]==1)
                        {
                                cout<<results[row][col]<<"*"<<" ";
                        }
                        else if(par[row]-results[row][col]==2)
                        {
                                cout<<results[row][col]<<"!"<<" ";
                        }
                        else
                        {
                                cout<<results[row][col]<<"  ";
                        }

                }

        }

        //name 2 score
	int name2sum=0;
        for(int row=0; row<18;row++)
        {
                for(col=1; col<2;col++)
                {
                        name2sum+=results[row][col];
                }
        }
        cout<<setw(5)<<name2sum<<endl;  //outputs total score

	
	//name 3
        for(int i=2; i<3;i++)
        {
                cout<<setw(8)<<right<<names[i]<<" ";
        }

        //name three's row
        for(int row=0; row<18;row++)
        {
                for(col=2; col<3;col++)
                {
			//birdies and eagles same process
                        int i=0;
                        if (par[row]-results[row][col]==1)  
                        {
                                cout<<results[row][col]<<"*"<<" ";
                        }
                        else if(par[row]-results[row][col]==2) 
                        {
                                cout<<results[row][col]<<"!"<<" ";
                        }
                        else
                        {
                                cout<<results[row][col]<<"  "; 
                        }
                }

        }

        //name 3 score
	int name3sum=0;
        for(int row=0; row<18;row++)
        {
                for(col=2; col<3;col++)
                {
                        name3sum+=results[row][col];
                }
        }
        cout<<setw(5)<<name3sum<<endl; //outputs total score


	//name 4
        for(int i=3; i<4;i++)
        {
                cout<<setw(8)<<right<<names[i]<<" ";
        }

        //name four's row
        for(int row=0; row<18;row++)
        {
                for(col=3; col<4;col++)
                {
                        int i=0;
			//birdies and eagles same process

                        if (par[row]-results[row][col]==1)
                        {
                                cout<<results[row][col]<<"*"<<" ";
                        }
                        else if(par[row]-results[row][col]==2)
                        {
                                cout<<results[row][col]<<"!"<<" ";
                        }
                        else
                        {
                                cout<<results[row][col]<<"  ";
                        }
                }

        }

        //name 4 score
	int name4sum=0;
        for(int row=0; row<18;row++)
        {
                for(col=3; col<4;col++)
                {
                        name4sum+=results[row][col];
                }
        }
        cout<<setw(5)<<name4sum<<endl;   //outputs total score
	

}

//function to output the winner based on the least amount of pars
void winner(int par[], string names[], int results[][30], string scores)
{

	int name1sum=0;
        int col;

	//find the total score of first player again 
        for(int row=0; row<18;row++)
        {
                for(col=0; col<1;col++)
                {
                        name1sum+=results[row][col];

                }

        }

         //find the total score of second player again
        int name2sum=0;

        for(int row=0; row<18;row++)
        {
                for(col=1; col<2;col++)
                {
                        name2sum+=results[row][col];
                }

        } 


	//find the total score of third player again
	int name3sum=0;

        for(int row=0; row<18;row++)
        {
                for(col=2; col<3;col++)
                {
                        name3sum+=results[row][col];
                }

        }



	 //find the total score of fourth player again
        int name4sum=0;

        for(int row=0; row<18;row++)
        {
                for(col=3; col<4;col++)
                {
                        name4sum+=results[row][col];
                }
        }


	//add the given pars to find its sum 
	int parSum=0;
	for(int i=0; i<18; i++)
        {
		parSum+=par[i];
        }	

	//variables for each players strokes (given par total - players par sum) 
	int player1strokes, player2strokes, player3strokes, player4strokes; 

	//subtract the players totals with the given par total to find total strokes 	
	player1strokes=name1sum-parSum;  
	player2strokes=name2sum-parSum;  
	player3strokes=name3sum-parSum;  
	player4strokes=name4sum-parSum;
	

	//for each player, see if they have the least stroke number 

	//if player 1 has the lowest stroke 
	if((player1strokes<player2strokes)&&(player1strokes<player3strokes)&&(player1strokes<player4strokes))
	{
		//player 1's name
		for(int i=0; i<1;i++)
        	{
                	cout<<names[i];
       		}
		//declare winner
		cout<<" was the winner with a score of "<<player1strokes<<"."<<endl;
	}


	 //if player 2 has the lowest stroke
	else if((player2strokes<player1strokes)&&(player2strokes<player3strokes)&&(player2strokes<player4strokes))
	{	
		//player 2's name
                for(int i=1; i<2;i++)
                {
                        cout<<names[i];
                }
		//declare winner
                cout<<" was the winner with a score of "<<player2strokes<<"."<<endl; 
	}


	 //if player 3 has the lowest stroke
	else if((player3strokes<player1strokes)&&(player3strokes<player2strokes)&&(player3strokes<player4strokes))
	{
                //player 3's name
                for(int i=2; i<3;i++)
                {
                        cout<<names[i];
                }
                //declare winner
                cout<<" was the winner with a score of "<<player3strokes<<"."<<endl;
	}


	 //if player 4 has the lowest stroke
	else if((player4strokes<player1strokes)&&(player4strokes<player2strokes)&&(player4strokes<player3strokes))
	{
                //player 4's name
                for(int i=1; i<2;i++)
                {
                        cout<<names[i];
                }
                //declare winner
                cout<<" was the winner with a score of "<<player4strokes<<"."<<endl;
	}
	
 
}

