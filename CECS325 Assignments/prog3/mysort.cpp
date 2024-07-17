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

void mySort(int arr[], int n)
{
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Please include input filename and output filename in the parameter list.\n";
        cout << "Example:\n";
        cout << "     % mySort numbers.txt mySorted.txt\n";
        exit(EXIT_SUCCESS);
    }

    cout << "argv[0]: " << argv[0] << endl;
    cout << "argv[1]: " << argv[1] << endl;
    cout << "argv[2]: " << argv[2] << endl;

    const int max = 1000000;
    ofstream fout;
    ifstream fin;
    int n;

    int v[max];
    int count = 0;

    fin.open(argv[1]);
    if (!fin)
    {
        cerr << "Error: Unable to open input file." << endl;
        return EXIT_FAILURE;
    }

    while (fin >> n && count < max)
    {
        v[count++] = n;
    }

    fin.close();

    mySort(v, count);

    fout.open(argv[2], ios::out | ios::trunc);

    for (int i = 0; i < count; i++)
    {
        fout << v[i] << endl;
    }

    fout.close();

    return 0;
}
