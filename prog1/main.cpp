// Andrew Hua
// CECS 325-01
// Prog 1 – One Card War
// Due 09/18/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "Deck.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	Deck myDeck;
	int ties = 0;
	int player1Wins = 0;
	int player2Wins = 0;
	string player1Name;
	string player2Name;
	cout << "Enter the name of the first player: ";
	cin >> player1Name;
	cout << "Enter the name of the second player: ";
	cin >> player2Name;
	cout << "\n\tOriginal Deck" << endl;
	myDeck.print();
	cout << endl;
	myDeck.shuffle();
	cout <<"\nShuffled Deck" << endl;
	myDeck.print();
	for(int i = 0; i < 26; i++){
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
	}
	    cout << "------Final Stats-------" << endl;
    cout << "\t" << player1Name << "\t vs. \t" << player2Name << endl;
    cout << "Wins" << "\t" << player1Wins << "\t\t" << player2Wins << endl;
    cout << "Losses" << "\t" << player2Wins << "\t\t" << player1Wins << endl;
    cout << "Ties" << "\t" << ties <<"\t\t" << ties << endl;
	return 0;
}
