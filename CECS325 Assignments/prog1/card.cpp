// Alvin Hang
// Class (CECS 325-01)
// Project Name (Prog 1 - Fibonacci Solitaire)
// Due Date (09/25/2023)
//
// I certify that this program is my own original work. I did not copy any part of
// this program from any other source. I further certify that I typed each and every
// line of code in this program.

#include <iostream>
#include "card.h"

using namespace std;

Card::Card()
{
    suit = 'Z';
    rank = 'Z';
}

Card::Card(char r, char s)
{
    rank = r;
    suit = s;
}

void Card::setCard(char r, char s)
{
    rank = r;
    suit = s;
}

int Card::getValue()
{
    if (rank == 'A')
    {
        return 1;
    }
    else if (rank == 'T' || rank == 'J' || rank == 'Q' || rank == 'K')
    {
        return 10;
    }
    else
    {
        return (int)rank - 48;
    }
}

void Card::show()
{
    if (rank == 'T' && suit == 'S')
    {
        cout << "10"
             << "♠"
             << ", ";
    }
    else if (rank == 'T' && suit == 'H')
    {
        cout << "10"
             << "♥"
             << ", ";
    }
    else if (rank == 'T' && suit == 'D')
    {
        cout << "10"
             << "♦"
             << ", ";
    }
    else if (rank == 'T' && suit == 'C')
    {
        cout << "10"
             << "♣"
             << ", ";
    }
    else if (suit == 'S')
    {
        cout << rank << "♠"
             << ", ";
    }
    else if (suit == 'H')
    {
        cout << rank << "♥"
             << ", ";
    }
    else if (suit == 'D')
    {
        cout << rank << "♦"
             << ", ";
    }
    else if (suit == 'C')
    {
        cout << rank << "♣"
             << ", ";
    }
}
