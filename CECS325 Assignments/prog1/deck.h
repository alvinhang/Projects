// Alvin Hang
// Class (CECS 325-01)
// Project Name (Prog 1 - Fibonacci Solitaire)
// Due Date (09/25/2023)
//
// I certify that this program is my own original work. I did not copy any part of
// this program from any other source. I further certify that I typed each and every
// line of code in this program.

#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <vector>
using namespace std;

class Deck
{
private:
    int top;
    vector<Card> pile;

public:
    Deck();
    void refreshDeck();
    Card deal();
    void shuffle();
    bool isEmpty();
    void show();
};

#endif