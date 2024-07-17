// Alvin Hang
// Class (CECS 325-01)
// Project Name (Prog 1 - Fibonacci Solitaire)
// Due Date (09/25/2023)
//
// I certify that this program is my own original work. I did not copy any part of
// this program from any other source. I further certify that I typed each and every
// line of code in this program.

#include "deck.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
using namespace std;

Deck::Deck()
{
    top = 0;
    pile.reserve(52);
    refreshDeck();
}

void Deck::refreshDeck()
{
    top = 0;
    pile.clear();

    char rank[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suit[] = {'S', 'H', 'D', 'C'};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            Card card;
            card.setCard(rank[j], suit[i]);
            pile.push_back(card);
        }
    }
}

Card Deck::deal()
{
    return pile[top++];
}

void Deck::shuffle()
{
    srand(time(NULL));
    int a, b;
    const int shuffleTimes = 10000;

    for (int i = 0; i < shuffleTimes; i++)
    {
        a = rand() % 52;
        b = rand() % 52;

        Card storedCards = pile[a];
        pile[a] = pile[b];
        pile[b] = storedCards;
    }
}

bool Deck::isEmpty()
{
    if ((52 - top) < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Deck::show()
{
    for (int i = 0; i < 52; i++)
    {
        if (i % 13 == 0)
        {
            cout << endl;
        }
        pile[i].show();
    }
    cout << endl;
}
