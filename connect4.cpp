#include "connect4.h"
#include "Controller.cpp"
#include "View.cpp"
#include "time.h"


//welcome fucntion
void showWelcome() 
{
	WORD Attributes = 0;
    //SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    SetConsoleColour(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    cout << "\nWelcome to Team RAAY's Connect4 Play Station!" << endl << endl;
    ResetConsoleColour(Attributes);
	
}

//Menu Function
void showMenu()
{	
	WORD Attributes = 0;
    SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "  1. Start Playing : Single Game " << endl;
    ResetConsoleColour(Attributes);	
    
    SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	cout << "  2. Match " << endl;
	ResetConsoleColour(Attributes);	
	
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED );
	cout << "  3. Show Leaderboard  " << endl;
	ResetConsoleColour(Attributes);	
	
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	cout << "  4. Connect 5  " << endl;
	ResetConsoleColour(Attributes);	
	
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
	cout << "  5. Connect 6  " << endl;
	ResetConsoleColour(Attributes);	
	
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "  6. Exit " << endl << endl;
	ResetConsoleColour(Attributes);	
	
	cout<< "Please select an option: ";
	 
		
}

void print_board(int A[6][7])
{
	cout << endl << "Here is the board showing below:" << endl;
	for (int i = 0;i<6;i++)
	{
		cout << endl;
		for (int j = 0;j<7;j++)
		{
			if(A[i][j] == 1)
			{
				WORD Attributes = 0;
	            SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << A[i][j] << " ";	
	            //cout << endl<< player;
	            ResetConsoleColour(Attributes);	
			}
			if(A[i][j] == 2)
			{
				WORD Attributes = 0;
	            SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << A[i][j] << " ";	
	            //cout << endl<< player;
	            ResetConsoleColour(Attributes);	
			}
			if(A[i][j] == 0)
			{
				cout << A[i][j] << " ";	
			}
		}
	}
	cout << endl << endl;
}

void print_board2(int A[6][9])
{
	cout << endl << "Here is the initial board showing below:" << endl;
	for (int i = 0;i<6;i++)
	{
		cout << endl;
		for (int j = 0;j<9;j++)
		{
			if(A[i][j] == 1)
			{
				WORD Attributes = 0;
				SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << A[i][j] << " ";
				//cout << endl<< player;
				ResetConsoleColour(Attributes);
			}
			if(A[i][j] == 2)
			{
				WORD Attributes = 0;
				SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << A[i][j] << " ";
				//cout << endl<< player;
				ResetConsoleColour(Attributes);
			}
			if(A[i][j] == 0)
			{
				cout << A[i][j] << " ";
			}
		}
	}
	cout << endl << endl;
}

void print_board3(int A[19][19])
{
	cout << endl << "Here is the initial board showing below:" << endl;
	for (int i = 0;i<19;i++)
	{
		cout << endl;
		for (int j = 0;j<19;j++)
		{
			if(A[i][j] == 1)
			{
				WORD Attributes = 0;
				SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << A[i][j] << " ";
				//cout << endl<< player;
				ResetConsoleColour(Attributes);
			}
			if(A[i][j] == 2)
			{
				WORD Attributes = 0;
				SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << A[i][j] << " ";
				//cout << endl<< player;
				ResetConsoleColour(Attributes);
			}
			if(A[i][j] == 0)
			{
				cout << A[i][j] << " ";
			}
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

//function to let the user play the game using different colors
/*string yellow_or_red(string color, string& one)
{
   cout<< one<<" , would you want to play with Red piece or Yellow piece? :";
   cin >> color;
   return color;
}

string yellow_or_red2(string color, string& two)
{
   cout<< two <<" you are assigned to ";
   return color;
}*/

int make_move(int A[6][7], string player, int check)
{
	int choice;
	sendstringmessage(player,A,check);
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

int make_move2(int A[6][9], string player, int check)
{
	int choice;
	sendstringmessage2(player, A, check);
	cin >> choice;
	choice--;

	if (A[0][choice] != 0)
	{
		command(3);
		make_move2(A, player, check);
		return 0;
	}
	if (choice > 8 || choice < 0)
	{
		command(5);
		make_move2(A, player, check);
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
				print_board2(A);

				return check;
			}
		}
	}
	return 0;
}

int make_move3(int A[19][19], string player, int check)
{
	int choice;
	sendstringmessage3(player, A, check);
	cin >> choice;
	choice--;

	if (A[0][choice] != 0)
	{
		command(3);
		make_move3(A, player, check);
		return 0;
	}
	if (choice > 18 || choice < 0)
	{
		command(5);
		make_move3(A, player, check);
		return 0;
	}
	else
	{
		for (int i = 18; i >= 0;i--)
		{
			if (A[i][choice] == 0)
			{
				A[i][choice] = check;
				if (check == 1)
					check++;
				if (check == 2)
					check--;

				command(4);
				print_board3(A);

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
					sendwinner(char_piece, player);
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
					//sendwinner(player);
					sendwinner(char_piece, player);
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
					//sendwinner(player);
					sendwinner(char_piece, player);
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
					//sendwinner(player);
					sendwinner(char_piece, player);
					winCase = true;
				}
			}
		}

	// return true if there is a winning case
	return winCase;
}

bool win_case2(int board[6][9], int char_piece, string player)
{
	bool winCase = false;

	// horizontal win
	if (!winCase)
		for (int row = 0; row <= 5; row++)
		{
			for (int col = 0; col <= 4; col++)
			{
				if (board[row][col] == char_piece && board[row][col + 1] == char_piece && board[row][col + 2] == char_piece && board[row][col + 3] == char_piece && board[row][col + 4] == char_piece)
				{
					sendwinner(char_piece, player);
					winCase = true;
				}
			}
		}

	if (!winCase)
		// vertical win
		for (int col = 0; col <= 8; col++)
		{
			for (int row = 0; row <= 1; row++)
			{
				if (board[row][col] == char_piece && board[row + 1][col] == char_piece && board[row + 2][col] == char_piece && board[row + 3][col] == char_piece && board[row + 4][col] == char_piece)
				{
					sendwinner(char_piece, player);
					winCase = true;
				}
			}
		}

	if (!winCase)
		// diagonal win
		for (int col = 0; col <= 4; col++)
		{
			for (int row = 0; row <= 1; row++)
			{
				if (board[row][col] == char_piece && board[row + 1][col + 1] == char_piece && board[row + 2][col + 2] == char_piece && board[row + 3][col + 3] == char_piece && board[row + 4][col + 4] == char_piece)
				{
					sendwinner(char_piece, player);
					winCase = true;
				}
			}
		}

	if (!winCase)
		// diagonal win
		for (int col = 8; col >= 4; col--)
		{
			for (int row = 0; row <= 1; row++)
			{
				if (board[row][col] == char_piece && board[row + 1][col - 1] == char_piece && board[row + 2][col - 2] == char_piece && board[row + 3][col - 3] == char_piece && board[row + 4][col - 4] == char_piece)
				{
					sendwinner(char_piece, player);
					winCase = true;
				}
			}
		}

	// return true if there is a winning case
	return winCase;
}

bool win_case3(int board[19][19], int char_piece, string player)
{
	bool winCase = false;

	// horizontal win
	if (!winCase)
		for (int row = 0; row <= 18; row++)
		{
			for (int col = 0; col <= 13; col++)
			{
				if (board[row][col] == char_piece && board[row][col + 1] == char_piece && board[row][col + 2] == char_piece && board[row][col + 3] == char_piece && board[row][col + 4] == char_piece && board[row][col + 5] == char_piece)
				{
					sendwinner(char_piece, player);
					winCase = true;
				}
			}
		}

	if (!winCase)
		// vertical win
		for (int col = 0; col <= 18; col++)
		{
			for (int row = 0; row <= 13; row++)
			{
				if (board[row][col] == char_piece && board[row + 1][col] == char_piece && board[row + 2][col] == char_piece && board[row + 3][col] == char_piece && board[row + 4][col] == char_piece && board[row + 5][col] == char_piece)
				{
					sendwinner(char_piece, player);
					winCase = true;
				}
			}
		}

	if (!winCase)
		// diagonal win
		for (int col = 0; col <= 13; col++)
		{
			for (int row = 0; row <= 13; row++)
			{
				if (board[row][col] == char_piece && board[row + 1][col + 1] == char_piece && board[row + 2][col + 2] == char_piece && board[row + 3][col + 3] == char_piece && board[row + 4][col + 4] == char_piece && board[row + 5][col + 5] == char_piece)
				{
					sendwinner(char_piece, player);
					winCase = true;
				}
			}
		}

	if (!winCase)
		// diagonal win
		for (int col = 18; col >= 5; col--)
		{
			for (int row = 0; row <= 13; row++)
			{
				if (board[row][col] == char_piece && board[row + 1][col - 1] == char_piece && board[row + 2][col - 2] == char_piece && board[row + 3][col - 3] == char_piece && board[row + 4][col - 4] == char_piece && board[row + 5][col - 5] == char_piece)
				{
					sendwinner(char_piece, player);
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
	
	WORD Attributes = 0;
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);	
	cout << "computer's turn: " << endl;
	ResetConsoleColour(Attributes);
	
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
	if(!winCase) //horizontal right
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
	if(!winCase) //horizontal left
		for(int i = 0; i < 6; i++)
		{
			for(int j = 3; j < 8; j++)
			{
				if(A[i][j]==1&&A[i][j-1]==1&&A[i][j-2]==1&&A[i][j-3]==0&&A[i+1][j-3]!=0)
				{
					A[i][j-3] = 2;
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
				if(A[i][j]==1&&A[i-1][j+1]==1&&A[i-2][j+2]==1&&A[i-3][j+3]==0&&A[i-2][j+3]!=0)
				{
					A[i-3][j+3]=2;	
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
				if(A[i][j]==1&&A[i-1][j-1]==1&&A[i-2][j-2]==1&&A[i-3][j-3]==0&&A[i-2][j-3]!=0)
				{
					A[i-3][j-3]=2;
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
				if(A[i][j]==2&&A[i][j+1]==0&&A[i+1][j+1]!=0)
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
	int check=1;
	bool winning=false;
	sendstringmessage(player,A,check);
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

bool fullboard(int A[6][7])
{
    bool full = false;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(A[i][j] == 0)
                full = true;
        }
    }
    return full;
}

bool fullboard2(int A[6][9])
{
	bool full = false;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(A[i][j] == 0)
				full = true;
		}
	}
	return full;
}

bool fullboard3(int A[19][19])
{
	bool full = false;
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 19; j++)
		{
			if(A[i][j] == 0)
				full = true;
		}
	}
	return full;
}

int showMatch(int A[6][7],string one, string two, int& oneWins, int& twoWins, int& games, bool win)
{
	int winner;
	while(!win && fullboard(A))
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
    if(!(fullboard(A)))
    {
        winner = 3;
        cout << "Draw" << endl;
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
	int connect5[6][9];
	int connect6[19][19];
	string one,two;
	//string red, yellow;
    int mode =1;
	int check=1;
  	bool win = false;
  	int player1wins = 0;
	int player2wins = 0;
	int gameNum = 0;
  	//WORD Attributes = 0;

	//clear the board
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
	const int CONNECT_5 = 4;
	const int CONNECT_6 = 5;
	const int EXIT = 6;
	
	cout << fixed << showpoint << setprecision(1); //sets to 1 decimal place
	
	do{
       showWelcome(); //show the welcome message first
       showMenu();//show the menu option
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
                   while (!win && fullboard(A)) 
				   {
                    if (!win)
					 {
                        make_move(A, one, 1);
                        win = win_case(A, 1, one);
                     }
                    if (!win) 
					{
                        make_move(A, two, 2);
                        win = win_case(A, 2, two);
                    }
                   }
                    if (!(fullboard(A)))
                    {
                        cout << "Draw" << endl;
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

				 player1wins = 0;
				 player2wins = 0;
				 gameNum = 0;
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
				 	if(player1wins == 2 || (player1wins > player2wins))
				 		cout << one << " wins the match!" << endl;
				 	else if(player2wins == 2 || (player2wins > player1wins))
				 		cout << two << " wins the match!" << endl;
				 	else
				 		cout << "Draw" << endl;
				 }
                 break;
                 
            case CONNECT_5:
            	//CONNECT 5
				for(int i=0;i<6;i++)
				{
					for (int j=0;j<9;j++)
					{
						connect5[i][j]=0;
					}
				}
				print_board2(connect5);
				win = false;
				one = get_name(one);
				two = get_name2(two);
				while (!win && fullboard2(connect5))
				{
					if (!win)
					{
						make_move2(connect5, one, 1);
						win = win_case2(connect5, 1, one);
					}
					if (!win)
					{
						make_move2(connect5, two, 2);
						win = win_case2(connect5, 2, two);
					}
				}
				if (!(fullboard2(connect5)))
				{
					cout << "Draw" << endl;
				}
          	 	break;

            case CONNECT_6:
            	//CONNECT 6
				for(int i=0;i<19;i++)
				{
					for (int j=0;j<19;j++)
					{
						connect6[i][j]=0;
					}
				}
				print_board3(connect6);
				win = false;
				one = get_name(one);
				two = get_name2(two);
				while (!win && fullboard3(connect6))
				{
					if (!win)
					{
						make_move3(connect6, one, 1);
						win = win_case3(connect6, 1, one);
					}
					if (!win)
					{
						make_move3(connect6, two, 2);
						win = win_case3(connect6, 2, two);
					}
				}
				if (!(fullboard3(connect6)))
				{
					cout << "Draw" << endl;
				}
				break;
            
      }
  }
} while (option != EXIT);

	return 0;
}

