#include <iostream>
#include <cstring>
using namespace std;
//int number = 100;

class Game {
	public:
	
	void setName(string b)
	{
    name = b;
	}

	string getName() {
		return (name);
	}
	
	private:
	string name;
	int score;
};

int main(){
	string n;
	Game game;
	cout << " What is the game you wanna play? ";
	cin>> n;
	
	game.setName (n);
	
	cout << "Playing " << game.getName () << endl;
	
	return 0;
}