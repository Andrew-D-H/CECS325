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
			for(char suit: {'C', 'S', 'D', 'H'})
				for(char rank: {'A','2', '3', '4', '5','6','7','8','9','T','J','Q','K'})
					decks.emplace_back(suit, rank)
		}
			
		Card deal(){
			Card card = deck.pop_back();
			return card;
		}
		
		void print(){
			
		}
};
		
int main(){
	return 0;
}
