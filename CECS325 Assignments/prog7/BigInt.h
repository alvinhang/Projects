// Alvin Hang
// Class (CECS 325-01)
// Project Name(Prog 7 - BigInt)
// Due Date (12/06/2023)

// I certify that this program is my own original work.I did not copy any part of
// this program from any other source.I further certify that I typed each and
// every line of code in this program.

#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>

using namespace std;

class BigInt
{
private:
    vector<char> v;

public:
    BigInt();
    BigInt(int);
    BigInt(string);
    int operator[](int) const;
    int size() const;
    BigInt operator+(const BigInt &) const;
    BigInt operator++();
    BigInt operator++(int);
    BigInt operator*(const BigInt &) const;
    BigInt half() const;
    bool isOdd() const;
    bool isEven() const;
    bool operator==(const BigInt &) const;
    bool operator<(const BigInt &) const;

    friend ostream &operator<<(ostream &, const BigInt &);
};

#endif
