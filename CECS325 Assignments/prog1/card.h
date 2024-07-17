// Alvin Hang
// Class (CECS 325-01)
// Project Name (Prog 1 - Fibonacci Solitaire)
// Due Date (09/25/2023)
//
// I certify that this program is my own original work. I did not copy any part of
// this program from any other source. I further certify that I typed each and every
// line of code in this program.

#ifndef CARD_H
#define CARD_H

class Card
{
private:
    char suit;
    char rank;

public:
    Card();
    Card(char, char);
    void setCard(char, char);
    void show();
    int getValue();
};

#endif