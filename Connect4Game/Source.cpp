#include<iostream> // this will allow me to display an output and allow the player to give input into my game
#include<string>
#include<sstream>
using namespace std;

char slot[6][7]; // this will let my game store what is inside each slot of the board 
				// the board is a 7 x 6 so this creates 6 horizontal arrays with 7 slots in each (0-6)

void playerName(string& p1Name, string& p2Name)
{
	cout << "What is your name Player 1: "; // asks the players there names and stores it in a variable
	cin >> p1Name;

	cout << "What is your name Player 2: ";
	cin >> p2Name;
}

void playerInput(int& player, string& p1Name, string& p2Name, int& input)
{

		if (player == 1)
		{
		cout << p1Name << " What is your move: ";
		cin >> input; // asks and recieves the players move 
		}

		else if (player == 2)
		{
			cout << p2Name << " What is your move: ";
			cin >> input;
		}

		if (input < 1 || input > 7)
		{
			cout << "Invalid move" << endl;
			playerInput(player, p1Name, p2Name, input); // stops the player from inputting a number that doesn't coresspond to the board
		}
}

void dropCounter(int& input, int& player, int& itterations, string& p1Name, string& p2Name)
{
	bool found = false;
	itterations = 5;
	do
	{

		if (slot[itterations][input - 1] == ' ') // checks to see which is the first free space in the column that the counter can go in
		{
			if (itterations >= 0)
			{
				found = true;
			}
			else
			{
				cout << "Column Full Try Somewhere else" << endl;
				itterations = 5;
				playerInput(player, p1Name, p2Name, input); // stops player from overfilling a column
			}
		}
		else
		{
			itterations -= 1;//move up 1
		}
	} while (found == false);
}

void updateGrid(int& player, int& input, int& itterations, char& p1Symbol, char& p2Symbol)
{
	if (player == 1)
	{
		slot[itterations][input-1] = p1Symbol;
	}
	else if (player == 2)
	{
		slot[itterations][input-1] = p2Symbol; // places the counter of the respective players turn
	}
}

void display(int& player, int& input, int& itterations)
{
	for (int a = 0; a <= 5; a++) // this creates 6 rows of the shape created below 
	{
		for (int b = 0; b <= 6; b++) {
			cout << "|" << slot[a][b]; //creates board using | and places array inside the gap
		}
		cout << "|" << endl; // ending line and closes the board
	}

	cout << " 1 2 3 4 5 6 7" << endl; // this puts the numbers 1-7 under the columns 
}

void updateDisplay(int& player, int& input, int& itterations, char& p1Symbol, char& p2Symbol)
{
	for (int a = 0; a <= 5; a++) // this creates 6 rows of the shape created below 
	{
		for (int b = 0; b <= 6; b++) {
			cout << "|" << slot[a][b]; //creates board using | and places array inside the gap
		}
		cout << "|" << endl; // ending line and closes the board
	}

	updateGrid(player, input, itterations, p1Symbol, p2Symbol);

	cout << " 1 2 3 4 5 6 7" << endl; // this puts the numbers 1-7 under the columns 
}

 bool checkForWinHoz(char& p1Symbol, char& p2Symbol, int& player)
 {
	 int counter = 0;
	 
	 if (player == 1) // 
	 {

		 for (int a = 0; a < 6; a++)
		 {
			 for (int b = 0; b < 7; b++)
			 {
				 if (slot[a][b] == 'x')
				 {
					 counter++;
					 if (counter == 4)
					 {
						 return true;
					 }
				 }
				 else counter = 0;

			 }
		 }
	 }

	 if (player == 2)
	 {

		 for (int a = 0; a < 6; a++)
		 {
			 for (int b = 0; b < 7; b++)
			 {
				 if (slot[a][b] == 'o')
				 {
					 counter++;
					 if (counter == 4)
					 {
						 return true;
					 }
				 }
				 else counter = 0;

			 }
		 }
	 }
	 return false;
}

 bool checkForWinVer(char& p1Symbol, char& p2Symbol, int& player)
 {
	 int counter = 0;

	 if (player == 1)
	 {

		 for (int b = 0; b < 7; b++)
		 {
			 for (int a = 0; a < 6; a++)
			 {
				 if (slot[a][b] == 'x')
				 {
					 counter++;
					 if (counter == 4)
					 {
						 return true;
					 }
				 }
				 else counter = 0;

			 }
		 }
	 }

	 if (player == 2)
	 {

		 for (int b = 0; b < 7; b++)
		 {
			 for (int a = 0; a < 6; a++)
			 {
				 if (slot[a][b] == 'o')
				 {
					 counter++;
					 if (counter == 4)
					 {
						 return true;
					 }
				 }
				 else counter = 0;

			 }
		 }
	 }
	 return false;
 }

 bool checkForWinDig1(char& p1Symbol, char& p2Symbol, int& player)
 {
	 for (int a = 0; a < 6; a++)
	 {
		 for (int b = 0; b < 7; b++)
		 {
			 if (slot[a][b] == 'x' && slot[a + 1][b + 1] == 'x' && slot[a + 2][b + 2] == 'x' && slot[a + 3][b + 3] == 'x') // right to left (\)
			 {
				 return true;
			 }
			 else if (slot[a][b] == 'o' && slot[a + 1] [b + 1] == 'o' && slot[a + 2] [b + 2] == 'o' && slot[a + 3] [b + 3] == 'o') // player 2
			 {
				 return true;
			 }
			 else if (slot[a][b] == 'x' && slot[a - 1][b + 1] == 'x' && slot[a - 2][b + 2] == 'x' && slot[a - 3][b + 3] == 'x') // left to right (/)
			 {
				 return true;
			 }
			 else if (slot[a][b] == 'o' && slot[a - 1][b + 1] == 'o' && slot[a - 2][b + 2] == 'o' && slot[a - 3][b + 3] == 'o')// player 2
			 {
				 return true;
			 }
				 
		 }
			 
	 }
	 return false;
 }

 void swapPlayer(int&player)
 {
	 if (player == 1 && player != 3)
	 {
		 player = 2;
	 }

	 else if (player == 2 && player != 3)
	 {
		 player = 1;
	 }
 }
 
 void winningMessage(bool&winner, int&player, string&p1Name, string&p2Name)
 {
	 if (winner == true)
	 {
		 if (player == 1)
		 {
			 cout << "Congratulations " << p1Name << endl;
			 system("pause");
			 player = 3;
		 }

		 if (player == 2)
		 {
			 cout << "Congratulations " << p2Name << endl;
			 system("pause");
			 player = 3;
		 }
	 }
 }

 void checkWinner(char& p1Symbol, char& p2Symbol, int& player, bool&winner)
 {
	 winner = checkForWinHoz(p1Symbol, p2Symbol, player);

	 if (winner == false)
	 {
		 winner = checkForWinVer(p1Symbol, p2Symbol, player);
	 }
	 if (winner == false)
	 {
		 winner = checkForWinDig1(p1Symbol, p2Symbol, player);
	 }
	  
 }

int main()
{
	bool winner = false;
	char p1Symbol = 'x';
	char p2Symbol = 'o';
	int player = 1;
	string p1Name = " ";
	string p2Name = " ";
	int itterations = 5;
	int input = 0 ; // will use this to select an input 

	for (int a = 0; a <= 5; a++)  //for each row
	{
		for (int b = 0; b <= 6; b++) //for each column
			slot[a][b] = ' '; // assign array
	}

	playerName(p1Name, p2Name);
	display(player, input, itterations);

	do
	{
		playerInput(player, p1Name, p2Name, input);
		dropCounter(input, player, itterations, p1Name, p2Name);
		updateDisplay(player, input, itterations, p1Symbol, p2Symbol);
		system("cls");// erases the old table
		display(player, input, itterations);
		checkWinner(p1Symbol, p2Symbol, player, winner);
		winningMessage(winner, player, p1Name, p2Name);
		swapPlayer(player);

	} while (player != 3);
	
	std::exit(EXIT_FAILURE);
	
}






