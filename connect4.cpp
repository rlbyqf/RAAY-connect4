#include "connect4.h"
#include "Controller.cpp"
#include "View.cpp"
#include "time.h"
//welcome fucntion
void showWelcome() {
	
	cout << "\nWelcome to Team RAAY's Connect4 Play Station!" << endl << endl;
}

//Menu Function
void showMenu()
{	
   cout << "  1. Start Playing : Single Game " << endl
		
		//<< "3. Redefine usernames" << endl
		<< "  2. Match " << endl
		<< "  3. Show Leaderboard  " << endl
		<< "  4. Exit " << endl << endl
		<< "Please select an option: ";
		
}

void print_board(int A[6][7])
{
	cout << endl << "Here is the initial board showing below:" << endl;
	for (int i = 0;i<6;i++)
	{
		cout << endl;
		for (int j = 0;j<7;j++)
		{
			cout << A[i][j] << " ";
		}
	}
	cout << endl << endl;
}

int player_mode(int mode)
{
	//int mode;
	cout << "Now before start playing, please select TWO_PLAYERS or CPU mode: ";
	cin >> mode;//mode =1 or 2
	//mode = 1;
	return mode;
}

string get_name(string& one)
{
	command(1);
	cin >> one;
	//one = "Nina";
	return one;
}

string get_name2(string two)
{
	command(2);
	cin >> two;
	//two = "yang";
	return two;
}

int make_move(int A[6][7], string player, int check)
{
	int choice;
	sendstringmessage(player);
	cin >> choice;
	choice--;

	if (A[0][choice] != 0)
	{
		command(3);
		make_move(A, player, check);
		return 0;
	}
	if (choice > 6 || choice < 0)
	{
		command(5);
		make_move(A, player, check);
		return 0;
	}
	if (choice == 8)
	{
		command(5);
		make_move(A, player, check);
		return 0;
	}
	else
	{
		for (int i = 5; i >= 0;i--)
		{
			if (A[i][choice] == 0)
			{
				A[i][choice] = check;
				if (check == 1)
					check++;
				if (check == 2)
					check--;

				command(4);
				print_board(A);

				return check;
			}
		}
	}
	return 0;
}

bool win_case(int board[6][7], int char_piece, string player) // standard connect 4 board is 6x7
{
	bool winCase = false;
	//6 row 7 column

	// horizontal win
	if (!winCase)
		for (int row = 0; row <= 5; row++)
		{
			for (int col = 0; col <= 3; col++)
			{
				if (board[row][col] == char_piece && board[row][col + 1] == char_piece && board[row][col + 2] == char_piece && board[row][col + 3] == char_piece)
				{

					sendwinner(player);
					winCase = true;
				}
			}
		}

	if (!winCase)
		// vertical win
		for (int col = 0; col <= 6; col++)
		{
			for (int row = 0; row <= 2; row++)
			{
				if (board[row][col] == char_piece && board[row + 1][col] == char_piece && board[row + 2][col] == char_piece && board[row + 3][col] == char_piece)
				{
					sendwinner(player);
					winCase = true;
				}
			}
		}

	if (!winCase)
		// diagonal win 
		for (int col = 0; col <= 3; col++)
		{
			for (int row = 0; row <= 2; row++)
			{
				if (board[row][col] == char_piece && board[row + 1][col + 1] == char_piece && board[row + 2][col + 2] == char_piece && board[row + 3][col + 3] == char_piece)
				{
					sendwinner(player);
					winCase = true;
				}
			}
		}

	if (!winCase)
		// diagonal win
		for (int col = 6; col >= 3; col--)
		{
			for (int row = 0; row <= 2; row++)
			{
				if (board[row][col] == char_piece && board[row + 1][col - 1] == char_piece && board[row + 2][col - 2] == char_piece && board[row + 3][col - 3] == char_piece)
				{
					sendwinner(player);
					winCase = true;
				}
			}
		}

	// return true if there is a winning case
	return winCase;
}


bool computer_turn(int A[6][7],string player) // standard connect 4 board is 6x7
{
	srand(time(NULL));
	bool winning=false;
	bool winCase = false;
	cout << "computer's turn: " << endl;
if(!winCase) //vertical
	{
		for(int i=5;i>2;i--)
			for(int j=0;j<7;j++)
				if(A[i][j]==1&&A[i-1][j]==1&&A[i-2][j]==1&&A[i-3][j]==0)
				{
					A[i-3][j]=2;
					print_board(A);
					winning=win_case(A,2,"Computer");
					if(winning)
					{
						//cout << " Computer has won!" << endl;
						return 0;
					}
					human_turn(A,player);
					return 0;
				}
	}
	if(!winCase) //horizontal
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(A[i][j]==1&&A[i][j+1]==1&&A[i][j+2]==1&&A[i][j+3]==0)
				{
					A[i][j+3] = 2;
					print_board(A);
					winning=win_case(A,2,"Computer");
					if(winning)
					{
						//cout << " Computer has won!" << endl;
						return 0;
					}
					human_turn(A,player);			
					return 0;
				}
			}
		}
	if(!winCase) //diagnal right
	{
		for(int i=5;i>2;i--)
			for(int j=0;j<4;j++)
				if(A[i][j]==1&&A[i+1][j+1]==1&&A[i+2][j+2]==1&&A[i+3][j+3]==0)
				{
					A[i+3][j+3]=2;
					print_board(A);
					winning=win_case(A,2,"Computer");
					if(winning)
					{
						//cout << " Computer has won!" << endl;
						return 0;
					}
					human_turn(A,player);
					return 0;
				}
	}
	if(!winCase) // diagnal left
	{
		for(int i=5;i>2;i--)
			for(int j=3;j<7;j++)
				if(A[i][j]==1&&A[i+1][j-1]==1&&A[i+2][j-2]==1&&A[i+3][j-3]==0)
				{
					A[i+3][j-3]=2;
					print_board(A);
					winning=win_case(A,2,"Computer");
					if(winning)
					{
						//cout << " Computer has won!" << endl;
						return 0;
					}
					human_turn(A,player);
					return 0;
				}
	}
	
	if(!winCase) // fill horizontal holes with 2s
	{
		for(int i=5;i>-1;i--)
			for(int j=1;j<6;j++)
				if(A[i][j-1]==1&&A[i][j+1]==1&&A[i][j]==0)
				{
					A[i][j]=2;
					print_board(A);
					winning=win_case(A,2,"Computer");
					if(winning)
					{
						//cout << " Computer has won!" << endl;
						return 0;
					}
					human_turn(A,player);
					return 0;
				}
	}
	
	if(!winCase) //search for 2's and place left horizontally
	{
		for(int i=5;i>-1;i--)
			for(int j=1;j<7;j++)
				if(A[i][j]==2&&A[i][j-1]==0&&A[i+1][j-1]!=0)
				{
					A[i][j-1]=2;
					print_board(A);
					cout<<"placing left";
					winning=win_case(A,2,"Computer");
					if(winning)
					{
						//cout << " Computer has won!" << endl;
						return 0;
					}
					human_turn(A,player);
					return 0;
				}
	}
	
	if(!winCase) //search for 2's and place right horizontally
	{
		for(int i=5;i>-1;i--)
			for(int j=0;j<6;j++)
				if(A[i][j]==2&&A[i][j+1]==0&&A[i-1][j+1]!=0)
				{
					A[i][j+1]=2;
					print_board(A);
					cout <<"placing right";
					winning=win_case(A,2,"Computer");
					if(winning)
					{
						//cout << " Computer has won!" << endl;
						return 0;
					}
					human_turn(A,player);
					return 0;
				}
	}
	
	if(!winCase) //search for 2's and place vertically
	{
		for(int i=5;i>0;i--)
			for(int j=0;j<7;j++)
				if(A[i][j]==2&&A[i-1][j]==0)
				{
					A[i-1][j]=2;
					print_board(A);
					winning=win_case(A,2,"Computer");
					if(winning)
					{
						//cout << " Computer has won!" << endl;
						return 0;
					}
					human_turn(A,player);
					return 0;
				}
	}
	
	//cout << "made it";
	int choice = rand() % 7 + 1;
	choice--;
	//cout << choice;
	for(int i = 5; i >= 0;i--)
	{
		if(A[i][choice]==0)
		{
			A[i][choice]=2;
			print_board(A);
			winning=win_case(A,2,"Computer");
			if(winning)
			{
				//cout << " Computer has won!" << endl;
				return 0;
			}
			human_turn(A,player);
			return 0;
		}
	}
	

	return 0;
}


int human_turn(int A[6][7],string player)
{
	int choice;
	bool winning=false;
	sendstringmessage(player);
	cin >> choice;
	choice--;
	
	if(A[0][choice] !=0)
	{		
		command(3);
		human_turn(A,player);
		return 0;
	}
	if(choice > 6 || choice < 0)
	{
		command(5);
		human_turn(A,player);
		return 0;
	}
	if(choice == 8)
	{
		command(5);
		human_turn(A,player);
		return 0;
	}
	else 
	{
		for(int i = 5; i >= 0;i--)
		{
			if(A[i][choice]==0)
			{
				A[i][choice]=1;
				
				command(4);
				print_board(A);
				winning=win_case(A,1,player);
				if(winning)
				{
					//cout << player << " has won!" << endl;
					return 0;
				}
				computer_turn(A,player);
				return 0;
			}
		}
	}
	return 0;
}



int showMatch(int A[6][7],string one, string two, int& oneWins, int& twoWins, int& games, bool win)
{
	int winner; 
	while(!win)
	{
		if(!win)
		{
			make_move(A,one,1);
			win = win_case(A,1,one);
			if(win)
			{
				oneWins++;
				winner = 1;
			}
		}
		if(!win)
		{
			make_move(A,two,2);
			win = win_case(A,2,two);
			if(win)
			{
				twoWins++;
				winner = 2;
			}
		}	
	}
	games++;
	return winner;
}


/*---------------------------------------------------------------

						END FUNCTIONS

---------------------------------------------------------------*/


int main()
{
	int option; //menu option
	int A[6][7];
	string one,two;
    int mode =1;
	int check=1;
  	bool win = false;
	
	for(int i=0;i<6;i++)
	{	
		for (int j=0;j<7;j++)
		{
			A[i][j]=0;		
		}
	}

	// constants for menu options
	const int PLAY_CONNECT4 = 1;
	const int MATCH = 2;
	const int SHOW_LEADERBOARD = 3;
	//const int REDEFINE_USERNAMES = 3;
	const int EXIT = 4;
	
	cout << fixed << showpoint << setprecision(1); //sets to 1 decimal place
	
	do{
       showWelcome(); //show the welcome message first
       showMenu();
       cin >> option;
      
      //Validate menu option
      while (option < PLAY_CONNECT4 || option > EXIT)
      {
        cout << "Please enter a valid menu option: ";
        cin >> option;
      }
	  
      //If user does not want to quit, proceed.
      if (option != EXIT)
      {
        switch (option)
        {
            case PLAY_CONNECT4:
            	for(int i=0;i<6;i++)
				{		
					for (int j=0;j<7;j++)
					{
						A[i][j]=0;		
					}
				}
                print_board(A);
				mode=player_mode(mode);
				
                if (mode == 1)//mode 1- two players
                {
                	win = false;
                  	one = get_name(one);
	                two = get_name2(two);
                    while(!win)
	                {
    	              if(!win)
    	              {
		               make_move(A,one,1);
	  	               win = win_case(A,1,one);
    	              }
    	              if(!win)
    	              {		
    	               make_move(A,two,2);
		               win = win_case(A,2,two);
    	              }
	                }
                }
                else if(mode == 2)//mode 2- CPU opponent
                {
                	one = get_name(one);
                    human_turn(A,one); 
                }
                else//check  for the user's input is 1 or 2
                {
                    cout<<"Invalid mode selection! Please enter 1 or 2.";
                }
                break;
                                                   
            case SHOW_LEADERBOARD:
                 //showLeaderboard()
                 break;
                 
            
            case MATCH:
                 //showMatch();
                 int player1wins = 0;
				 int player2wins = 0;
				 int gameNum = 0;
				 
				 for(int i=0;i<6;i++)
					{	
					for (int j=0;j<7;j++)
						{
							A[i][j]=0;		
						}
					}
				 print_board(A);
				 one = get_name(one);
	             two = get_name2(two);
	             
				 while((player1wins != 2 && player2wins !=2) && gameNum != 3)
				 {
				 	 win = false;
				 	 for(int i=0;i<6;i++)
					{	
					for (int j=0;j<7;j++)
						{
							A[i][j]=0;		
						}
					}
				 	 showMatch(A,one,two,player1wins,player2wins,gameNum,win);
				 }
				 if(player1wins == 2 || player2wins ==2 || gameNum == 3)
				 {
				 	if(player1wins == 2)
				 		cout << one << " wins the match!" << endl;
				 	else if(player2wins == 2)
				 		cout << two << " wins the match!" << endl;
				 	else
				 		cout << "Draw" << endl;
				 }
                 break;
        }
      }
    } while (option != EXIT);
	
	
	return 0;
}

