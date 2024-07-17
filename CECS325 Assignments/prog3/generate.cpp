// Alvin Hang
// Class (CECS 325-01)
// Project Name(Prog 3 - Sorting Contest)
// Due Date (10/09/2023)

// I certify that this program is my own original work.I did not copy any part of
// this program from any other source.I further certify that I typed each and
// every line of code in this program.

#include <iostream>
#include <fstream>

using namespace std;

int main(int count, char *argv[])
{
    if (count < 4)
    {
        cout << "Please enter 3 parameters:\n";
        cout << "     Parameter 1: total count of numbers you want.\n";
        cout << "     Parameter 2: min value.\n";
        cout << "     Parameter 3: max value.\n";
        cout << "Example: %generate 10000000 100000 999999\n";
        exit(EXIT_SUCCESS);
    }

    for (int i = 0; i < count; i++)
    {
        cout << "argv[" << i << "]:" << argv[i] << endl;
    }
    int counter = stoi(argv[1]);
    int min = stoi(argv[2]);
    int max = stoi(argv[3]);

    ofstream fout;
    fout.open("numbers.txt", ios::out | ios::trunc);
    for (int i = 0; i < counter; i++)
    {
        fout << (rand() % (max - min + 1) + min) << endl;
    }
    fout.close();
    return 0;
}
