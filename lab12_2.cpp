#include<iostream>
#include<string>
#include <ctime>
#include <cstdlib>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	srand(time(0));
	
	int randomnum = rand()%13+1;
	
    return randomnum;

}

int calScore(int x,int y,int z){

	if(x >=10){
		x = 0;
	}
	else if(y >=10)
	{
		y = 0;
	}
	else if(z >= 10)
	{
		z = 0;
	}

	int sum = x+y+z;
	
	if(sum >=10)
	{
		sum = sum%10;
	}

	return sum; 
}

int findYugiAction(int s){	
	if(s == 9) return 2; // Yugi will definitely stay (2) when current score (s) is equal to 9
	else if(s < 6) return 1; // Yugi will definitely draw (1) when current score (s) is less than 6
	else{
		int TrueFalse = rand()%100 +1;
		if(TrueFalse <= 69)return 1;
		else return 2;
		

		// If current score is 6,7,8, Yugi will draw with probability 69% and will stay with probability 31% 
		// Write conditions here using random number 
	}
}

void checkWinner(int p, int y){

	cout << "\n---------------------------------\n";

	if(p > y)
	{
		cout <<   "|         Player wins!!!        |";

	}
	else if(y >p)
	{
		cout <<   "|          Yugi wins!!!         |";

	}
	else if(p == y)
	{
		cout <<   "|             Draw!!!           |";
	}
	cout << "\n---------------------------------\n";

	
}

int main(){	
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(),drawCard(),0}; //This line of code is not completed. You need to initialize value of yugiCards[].
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],0);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2); //This line of code is not completed. You need to set the condition to do loop if user's input is not 1 or 2. 
	if(playerAction == 1){
		//The following lines of code are not completed. Please correct it.
		int Player3card[2] = {drawCard(),0};
		playerScore = calScore(Player3card[0],playerScore,0);
		
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[Player3card[0]] << "\n";
		cout << "Your new score: " << playerScore << "\n";
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	//The following lines of code for Yugi's turn are not completed. Please correct it.
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],0);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		int Yugi3card[2] = {drawCard(),0};
		yugiScore = calScore(Yugi3card[0],yugiScore,0);

		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " << cardNames[Yugi3card[0]] << "\n";
		cout << "Yugi's new score: " << yugiScore << "\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore);
}
