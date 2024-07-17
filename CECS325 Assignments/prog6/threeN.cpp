// Alvin Hang
// Class (CECS 325-01)
// Project Name(Prog 6 - 3N+1)
// Due Date (11/15/2023)

// I certify that this program is my own original work.I did not copy any part of
// this program from any other source.I further certify that I typed each and
// every line of code in this program.

#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int threeN(int n)
{
    // Collatz conjecture
    if (n == 1)
    {
        return 1;
    }
    // Even case check
    else if (n % 2 == 0)
    {
        return n / 2;
    }
    else
    {
        // Odd case check and checks for overflow
        if (n > (INT_MAX - 1) / 3)
        {
            throw overflow_error(to_string(3 * n + 1));
        }
        return 3 * n + 1;
    }
}

// Checks if the number is odd and not 1
bool isOddAndNotOne(int x)
{
    return x % 2 != 0 && x != 1;
}

void printSequence(const vector<int> &sequence)
{
    int start = sequence.front();
    int steps = sequence.size() - 1;
    // Finds the max element in the sequence
    int max = *max_element(sequence.begin(), sequence.end());
    // Counts the odd numbers except for 1
    int odds = count_if(sequence.begin(), sequence.end(), isOddAndNotOne);
    int evens = steps - odds;

    cout << "\tstart: " << start << endl;
    cout << "\tsteps: " << steps << endl;
    cout << "\tmax: " << max << endl;
    cout << "\todds: " << odds << endl;
    cout << "\tevens: " << evens << endl
         << endl;
}

void generate(int value, vector<int> &sequence)
{
    sequence.push_back(value);

    if (value != 1)
    {
        int next = threeN(value);
        generate(next, sequence);
    }
}

vector<int> sequenceVector(int start)
{
    vector<int> sequence;
    bool overflow = false;

    try
    {
        generate(start, sequence);
    }
    catch (const overflow_error &error)
    {
        cout << "Overflow for n: " << sequence.back() << endl;
        // Prints the error message
        cout << "3n + 1: " << error.what() << endl
             << endl;
        overflow = true;
    }

    for (int num : sequence)
    {
        // If overflow occurs, the sequence will print followed by the overflow message
        if (num == sequence.back() && overflow)
        {
            cout << "->"
                 << "(" << num << ")"
                 << "->"
                 << "(###overflow###)";
        }
        else
        {
            cout << "->"
                 << "(" << num << ")";
        }
    }
    cout << endl
         << endl;

    if (!overflow)
    {
        printSequence(sequence);
    }

    return sequence;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        int n;
        cout << "Enter a candidate number: ";
        cin >> n;
        sequenceVector(n);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            int start = stoi(argv[i]);
            cout << "Solving 3n+1: " << endl;
            cout << "Starting number: " << start << endl;
            sequenceVector(start);
        }
    }

    return 0;
}
