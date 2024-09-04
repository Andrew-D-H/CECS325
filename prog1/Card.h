#ifndef CARD_H
#define CARD_H

class Card 
{

  private:
    char rank;
    char suit;

  public:
    Card(char, char);
    void print();
    int compare(Card);

};

#endif