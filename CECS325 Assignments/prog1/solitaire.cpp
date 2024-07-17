// Alvin Hang
// Class (CECS 325-01)
// Project Name (Prog 1 - Fibonacci Solitaire)
// Due Date (09/25/2023)
//
// I certify that this program is my own original work. I did not copy any part of
// this program from any other source. I further certify that I typed each and every
// line of code in this program.

#include "deck.h"
#include "card.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

enum MenuOption
{
    NEW_DECK = 1,
    DISPLAY_DECK,
    SHUFFLE_DECK,
    PLAY_SOLITAIRE,
    WIN_FIBO_SOLITAIRE,
    EXIT
};

bool isFibo(int n);
void playFibonacciSolitaire(Deck &deck);
bool winFibonacciSolitaire(Deck &deck);

int main()
{
    Card currentCard;
    Deck gameDeck;
    bool playGame = true;
    int select = 0;
    int gamesPlayed = 0;
    bool hasWon = false;

    cout << "Welcome to Fibonacci Solitaire!\n";

    while (playGame)
    {
        cout << "\n1) New Deck\n2) Display Deck\n3) Shuffle Deck\n4) Play Solitaire\n5) Win Fibo Solitaire\n6) Exit\n\n";
        cin >> select;

        switch (select)
        {
        case NEW_DECK:
            gameDeck.refreshDeck();
            cout << "\nThe deck was refreshed!\n"
                 << endl;
            break;

        case DISPLAY_DECK:
            gameDeck.show();
            cout << endl;
            break;

        case SHUFFLE_DECK:
            gameDeck.shuffle();
            cout << "\nThe deck was shuffled!\n";
            break;

        case PLAY_SOLITAIRE:
            cout << "\nPlaying Fibonacci Solitaire !!!\n\n";
            playFibonacciSolitaire(gameDeck);
            gamesPlayed++;
            break;

        case WIN_FIBO_SOLITAIRE:
            gameDeck.refreshDeck();
            gameDeck.shuffle();
            cout << "\nPlaying Win Fibonacci Solitaire !!!\n\n";

            hasWon = false;

            while (!hasWon)
            {
                hasWon = winFibonacciSolitaire(gameDeck);
                gamesPlayed++;

                if (!hasWon)
                {
                    gameDeck.refreshDeck();
                    gameDeck.shuffle();
                }
            }

            break;

        case EXIT:
            cout << "\nThank you for playing!\n";
            playGame = false;
            break;

        default:
            cout << "\nInvalid selection! Please select between options 1-5\n";
            break;
        }

        cout << "\nGames Played: " << gamesPlayed << endl;
    }

    return 0;
}

bool isFibo(int n)
{
    int sq1 = sqrt(5 * n * n + 4);
    int sq2 = sqrt(5 * n * n - 4);
    if ((5 * n * n + 4) == (sq1 * sq1) || (5 * n * n - 4) == (sq2 * sq2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool winFibonacciSolitaire(Deck &deck)
{
    int sum = 0;
    int count = 0;
    bool hasWon = false;

    while (!deck.isEmpty())
    {
        Card currentCard = deck.deal();
        currentCard.show();
        sum += currentCard.getValue();

        if (isFibo(sum))
        {
            cout << "Fibo: " << sum << "\n\n";
            sum = 0;
            count++;
        }
    }

    if (count > 0)
    {
        cout << "\nWinner in " << count << " piles!\n\n";
        hasWon = true;
    }
    else
    {
        cout << "\nNo valid Fibonacci piles created, you lost!\n\n";
    }

    return hasWon;
}

void playFibonacciSolitaire(Deck &deck)
{
    int sum = 0;
    int count = 0;

    while (!deck.isEmpty())
    {
        Card currentCard = deck.deal();
        currentCard.show();
        sum += currentCard.getValue();

        if (isFibo(sum))
        {
            cout << "Fibo: " << sum << "\n\n";
            sum = 0;
            count++;
        }
    }

    if (isFibo(sum))
    {
        cout << "\nWinner in " << count << " piles!\n\n";
    }
    else
    {
        cout << "\n\nLast hand value: " << sum << endl;
        cout << "\nLoser in " << count << " piles!\n";
    }
}