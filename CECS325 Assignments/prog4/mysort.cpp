// Alvin Hang
// Class (CECS 325-01)
// Project Name(Prog 4 - Sorting Contest using pThreads)
// Due Date (10/23/2023)

// I certify that this program is my own original work.I did not copy any part of
// this program from any other source.I further certify that I typed each and
// every line of code in this program.

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

struct threads
{
    int *arr;
    int n;
};

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

// Merge function
void merge(int arr[], int left, int mid, int right)
{
    int subArr1 = mid - left + 1;
    int subArr2 = right - mid;

    int L[subArr1], R[subArr2];

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
}

void *sortThreadArray(void *ptr)
{
    threads *arg = (threads *)ptr;
    mySort(arg->arr, arg->n);
    pthread_exit(NULL);
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

    // Create 10 structs to pass to the threads
    threads argList[10];
    int threadSize = count / 10;

    for (int i = 0; i < 10; i++)
    {
        argList[i].arr = &v[threadSize * i];
        argList[i].n = threadSize;
    }

    pthread_t threads[10];

    // Simplified pthread_create using a loop instead of individual calls
    for (int i = 0; i < 10; i++)
    {
        pthread_create(&threads[i], NULL, sortThreadArray, (void *)&argList[i]);
    }

    // Simplified pthread_join using a loop instead of individual calls
    for (int i = 0; i < 10; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Merge the 10 sorted arrays
    for (int i = 1; i < 10; i++)
    {
        merge(v, 0, threadSize * i - 1, threadSize * (i + 1) - 1);
    }

    fout.open(argv[2], ios::out | ios::trunc);

    for (int i = 0; i < count; i++)
    {
        fout << v[i] << endl;
    }

    fout.close();

    return 0;
}
