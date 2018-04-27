#include <iostream>
#include <cstring>
using namespace std;
//int number = 100;
typedef unsigned char* ByteArray;

class Game {
	public:
	
	Game () {
		setName ("Minesweeper");
		 // construct - returns the function after creating an object
		getName ();
		setScore ();
		getScore ();
						
		}
	
	void setName(string b)
	{
    name = b;
	}

	string getName() {
		return (name);
	}
	int setScore () {
		score++;
	}
	int getScore () {
		return score;
	}
	
	private:
	string name;
	int score=0;
};

class MineSweeper: public Game {
	public:
	int mine;
	int x, y;// rows = x; columns= y;
	int sel_sq;
	int bomb_sq;
	ByteArray *m = new ByteArray[y];
	
	MineSweeper(): Game () {
	setBoard ();
	setMines ();
	
	}
	
	

	void setBoard () {
		cout << ' ' << endl;
		cout << "Enter the board size :\n";
		cout<< "x =";
		cin >> x;
		cout << endl;
		cout << "y =";
		cin >> y;
		cout<< endl;
		
		for (int i = 0; i < y; i++) {
			m[i] = new unsigned char[x]; // one item of array y [i] is equal to an array of x items.
			//m is now a y by x array. x - width, y - height
		}
			
		for (int i = 0; i < y; i++){
			for (int j = 0;j < x; j++)
			{
				m[i][j] = '.';
			}
		}
	}
	
	void setMines () {
		cout << "Enter amount of mines (not more than 10)for your field: " << endl;
		cin >> mine;
		cout << endl;
		cout << mine << " mines are..."; 

	int* mines = new int[mine*2];// double, because we need 2 coordinates for each mine
	int mx, my; // coordinates
	
	for (int n = 0; n < mine*2; n+=2)
	{
		mx = rand() % x;
		my = rand() % y;	

		while (1) {
			 int i; 
			 
			 for (i = 0; i < n; i+=2) { 
			 
			 //if mine already placed here -  randomize one more time
			 if (mines[i] == mx && mines[i+1] == my) // coordinates go after each other in the array
				
				{ mx = rand() % x; 
				  my = rand() % y; 
				  break; 
				} 
			} 
			if (i == n) //all mines are planted - get out of the loop
			break; 
		} 
		
		// coordinates of mines go after each other in the array
		 mines[n] = mx; 
		 mines[n + 1] = my;
		
	}
	cout << " ...planted in the play board" << endl; 
	cout << endl;
	}
	
	
	// Трудности с функцикией печати поля..
	 void print(unsigned char** m, int x, int y){

		cout << '\t';
		for (int a = 0; a < x; a++)
		{
			cout << a << ' ';
		}
		cout << '\n';
		
		for (int i = 0; i < y; i++)
		{
			cout << i << '\t';
			for (int j = 0; j < x;j++)
			{
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}
		cout<< endl;
	}
	
	void getSquare () {
		
		cout << "Let's play! Enter coordinates : "<<endl; 
		 
		 cout << "x ="; 
		 cin >> x;
		 cout << endl;
		 cout << "y =";
		 cin >> y;
		 cout << endl; 
	}
};


int main(){
	string n;
	//unsigned char m [e] [f];
	int x,y;
	//Game game;
	cout << " What is the game you wanna play? ";
	cin>> n;
	MineSweeper minesweeper;
	minesweeper.setName (n);
	
	
	cout << "Playing " << minesweeper.getName () << endl;
	//game.setScore ();
	
	//cout << "your score is " << game.getScore () << endl;
//	minesweeper.print(m [e] [f], x, y);
	
	
	return 0;
}