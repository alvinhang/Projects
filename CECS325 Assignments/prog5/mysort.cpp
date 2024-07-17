// Alvin Hang
// Class (CECS 325-01)
// Project Name(Prog 5 - Sorting Contest using Threads)
// Due Date (11/01/2023)

// I certify that this program is my own original work.I did not copy any part of
// this program from any other source.I further certify that I typed each and
// every line of code in this program.

#include <iostream>
#include <fstream>
#include <thread>
#include <memory>
#include <algorithm>

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

void merge(int arr[], int left, int mid, int right)
{
    int subArr1 = mid - left + 1;
    int subArr2 = right - mid;

    int *L = new int[subArr1];
    int *R = new int[subArr2];

    for (int i = 0; i < subArr1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < subArr2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < subArr1 && j < subArr2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < subArr1)
        arr[k++] = L[i++];

    while (j < subArr2)
        arr[k++] = R[j++];

    // Free memory
    delete[] L;
    delete[] R;
}

void sortThreadArray(int arr[], int n)
{
    mySort(arr, n);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Please include input filename and output filename in the parameter list.\n";
        cout << "Example:\n";
        cout << "     % mySort numbers.txt mySorted.txt\n";
        exit(EXIT_SUCCESS);
    }

    const int max = 1000000;
    ofstream fout;
    ifstream fin;
    int n;

    int *v = new int[max];
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

    int threadSize = count / 10;

    thread threadarray[10];

    for (int i = 0; i < 10; i++)
    {
        threadarray[i] = thread(sortThreadArray, v + threadSize * i, threadSize);
    }

    for (int i = 0; i < 10; i++)
    {
        threadarray[i].join();
    }

    // Merge the 10 sorted arrays
    for (int i = 1; i < 10; i++)
    {
        merge(v, 0, threadSize * i - 1, threadSize * (i + 1) - 1);
    }

    // Output sorted numbers to stdout
    for (int i = 0; i < count; i++)
    {
        cout << v[i] << endl;
    }

    // Free memory
    delete[] v;

    return 0;
}
