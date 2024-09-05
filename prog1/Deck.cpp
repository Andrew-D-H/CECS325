// Andrew Hua
// CECS 325-01
// Prog 1 – One Card War
// Due 09/18/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "Deck.h"
#include <iostream>


using namespace std;

Deck::Deck() {
	char suits[] = {'C', 'S', 'D', 'H'};
	char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

	int index = 0;
	for (char suit : suits){
		for (char rank : ranks) {
			deck[index] = Card(suit	, rank);
			++index;
		}
	}
	numCards = sizeof(deck) / sizeof(deck[0]); 
}

Card Deck::deal(){
	if (numCards == 0)
		throw range_error("Deck is empty!");

	Card card = deck[numCards - 1];
	deck[numCards - 1] = Card(); 
	numCards--;                   
	return card; 
}

void Deck::shuffle(){
	srand(time(0));
    for(int i = 0; i < 52; i++){
        int x = rand() % 52;
        int y = rand() % 52;
        Card temp = deck[x];
        deck[x] = deck[y];
        deck[y] = temp;
    }
}

void Deck::print(){
	for(int i = 0; i < 52; i++){
		deck[i].print();
		if((i+1)%13)
			cout << " , ";
		else
			cout << endl;
	}
	cout << endl;
}