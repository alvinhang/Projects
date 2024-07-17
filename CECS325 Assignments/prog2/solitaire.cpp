// Alvin Hang
// Class (CECS 325-01)
// Project Name (Prog 2 - Single File Fibo Solitaire)
// Due Date (09/25/2023)
//
// I certify that this program is my own original work. I did not copy any part of
// this program from any other source. I further certify that I typed each and every
// line of code in this program.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

class Card
{
private:
    char rank;
    char suit;

public:
    Card();
    Card(char r, char s);
    void setCard(char r, char s);
    int getValue();
    void show();
};

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

enum MenuOption
{
    NEW_DECK = 1,
    DISPLAY_DECK,
    SHUFFLE_DECK,
    PLAY_SOLITAIRE,
    WIN_FIBO_SOLITAIRE,
    EXIT
};

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
