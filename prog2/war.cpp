// Andrew Hua
// CECS 325-01
// Prog 2 – More War
// Due 09/30/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Card {
	private:
	
		char suit;
		char rank;
	public:
	
		Card(char suit, char rank){
			Card::suit = suit;
			Card:: rank = rank;
		}
		
		void print(){
			if(rank == 'T')
				cout << "10" << suit;
			else
				cout << rank << suit;
		}
		
		int compare(Card card){
			map<char, int> rankings = {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}};
			if(rank == card.rank)
				return 0;
			else if(rankings[rank] > rankings[card.rank])
				return 1;
			return -1;			
		}
	
};

class Deck {
	private:
		vector<Card> deck;
	public:	
	
		Deck(){
			for(char suit: {'C', 'S', 'D', 'H'}){
				for(char rank: {'A','2', '3', '4', '5','6','7','8','9','T','J','Q','K'})
					deck.emplace_back(suit, rank);
			}
		}
			
		Card deal(){
			if(isEmpty()) throw "Deck is empty";
			Card card = deck.back();
			deck.pop_back();
			return card;
		}
		
		void print(){
			for(int i 	= 0; i < deck.size(); i++){
				deck[i].print();
				if((i+1) % 13)
					cout << ",";
				else
					cout << endl;
			}
			cout << endl;
		}
		
		void shuffle(){
			srand(time(nullptr));
			vector<Card> newDeck;
			for(int i = deck.size(); i > 0; i--){
				int randomValue = rand() % i;
				newDeck.push_back(deck[randomValue]);
				deck.erase(deck.begin() + randomValue);
			}
			deck = newDeck;
		}
		
		bool isEmpty(){
			if(deck.empty())
				return true;
			return false;
		}
};
		
int main(){
	Deck myDeck;
	int ties = 0;
	int player1Wins = 0;
	int player2Wins = 0;
	int numOfGames;
	string player1Name;
	string player2Name;
	cout << "Enter the name of the first player: ";
	cin >> player1Name;
	cout << "Enter the name of the second player: ";
	cin >> player2Name;
	cout << "How many games will they play?";
	cin >> numOfGames;
	cout << "\n Original Deck" << endl;
	myDeck.print();
	cout << endl;
	myDeck.shuffle();
	cout <<"\n Shuffled Deck" << endl;
	myDeck.print();
	for (int i = 1; i <= numOfGames; i++) {
        try {
			Card player1Card = myDeck.deal();
			Card player2Card = myDeck.deal();
			cout << endl;
			cout << "Game " << i + 1 << endl;
			cout << "--------\n";
			cout << "\t" << player1Name << "=>";
			player1Card.print();
			cout << "\n\t" << player2Name << "=>";
			player2Card.print();
			int result = player1Card.compare(player2Card);
			if(!result){
				cout << "\nTie game\n";
				ties++;
			}
			else if(result == 1){
				cout << "\n" << player1Name << "=> Winner" << endl;
				player1Wins++;
			}
			else {
				cout << "\n" << player2Name << "=> Winner" << endl;
				player2Wins++;
			}
        } catch (const char* error) {
            cout << "Error - " << error << endl;
            break;
        }
    }
	return 0;
}
