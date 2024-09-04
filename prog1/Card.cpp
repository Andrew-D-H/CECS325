// Andrew Hua
// CECS 325-01
// Prog 1 – One Card War
// Due 09/18/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(char suit, char rank) {
    Card::suit = suit;
    Card::rank = rank;
}

void Card::print() {
    if (rank == 'T') {
        cout << "10" << suit;
    } else {
        cout << rank << suit;
    }
}

int Card::compare(Card opponentCard) {
	if(rank > opponentCard.rank)
		return 1;
	else if (rank == opponentCard.rank)
		return 0;
	else
		return -1;
}