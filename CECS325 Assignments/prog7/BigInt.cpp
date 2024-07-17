// Alvin Hang
// Class (CECS 325-01)
// Project Name(Prog 7 - BigInt)
// Due Date (12/06/2023)

// I certify that this program is my own original work.I did not copy any part of
// this program from any other source.I further certify that I typed each and
// every line of code in this program.

#include "BigInt.h"
#include <iostream>

using namespace std;

BigInt::BigInt()
{
    v.push_back(0);
}

BigInt::BigInt(int n)
{
    while (n > 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
}

BigInt::BigInt(string str)
{
    for (char digitChar : str)
    {
        int digit = digitChar - '0';
        v.push_back(digit);
    }
}

int BigInt::operator[](int index) const
{
    if (index < 0 || index >= v.size())
    {
        throw string("Index is out of range.");
    }
    return v[index];
}

int BigInt::size() const
{
    int count = 0;
    for (char digit : v)
    {
        count++;
    }
    return count;
}

BigInt BigInt::operator+(const BigInt &b) const
{
    BigInt result;
    int temp = 0;

    for (size_t i = 0; i < max(v.size(), b.v.size()) || temp; ++i)
    {
        if (i == result.size())
            result.v.push_back(0);

        result.v[i] += temp + (i < v.size() ? v[i] : 0) + (i < b.v.size() ? b.v[i] : 0);
        temp = result.v[i] / 10;
        result.v[i] %= 10;
    }

    while (result.v.size() > 1 && result.v.back() == 0)
    {
        result.v.pop_back();
    }

    return result;
}

BigInt BigInt::operator++()
{
    BigInt num(1);
    *this = *this + num;
    return *this;
}

BigInt BigInt::operator++(int)
{
    BigInt temp = *this;
    *this = *this + 1;
    return temp;
}

BigInt BigInt::operator*(const BigInt &b) const
{
    BigInt result;
    result.v.resize(v.size() + b.v.size(), 0);

    for (int i = 0; i < v.size(); i++)
    {
        int temp = 0;
        for (int j = 0; j < b.v.size() || temp; j++)
        {
            long long current = result.v[i + j] + v[i] * 1LL * (j < b.v.size() ? b.v[j] : 0) + temp;
            result.v[i + j] = int(current % 10);
            temp = int(current / 10);
        }
    }

    while (result.v.size() > 1 && result.v.back() == 0)
        result.v.pop_back();

    return result;
}

BigInt BigInt::half() const
{
    BigInt result = *this;
    int temp = 0;

    for (int i = result.size() - 1; i >= 0; --i)
    {
        int current = result.v[i] + temp * 10;
        result.v[i] = current / 2;
        temp = current % 2;
    }

    while (result.v.size() > 1 && result.v.back() == 0)
    {
        result.v.pop_back();
    }

    return result;
}

bool BigInt::isOdd() const
{
    return v[0] % 2 == 1;
}

bool BigInt::isEven() const
{
    return v[0] % 2 == 0;
}

bool BigInt::operator==(const BigInt &b) const
{
    return v == b.v;
}

bool BigInt::operator<(const BigInt &b) const
{
    if (v.size() != b.v.size())
    {
        return v.size() < b.v.size();
    }
    for (int i = v.size() - 1; i >= 0; --i)
    {
        if (v[i] != b.v[i])
        {
            return v[i] < b.v[i];
        }
    }
    return false;
}

ostream &operator<<(ostream &out, const BigInt &b)
{
    auto it = b.v.rbegin();

    if (b.v.size() <= 8)
    {
        while (it != b.v.rend())
        {
            out << static_cast<int>(*it);
            ++it;
        }
    }
    else
    {
        out << static_cast<int>(*it) << '.';
        ++it;
        while (it != b.v.rend())
        {
            out << static_cast<int>(*it);
            ++it;
        }
        out << "e" << (b.v.size() - 1);
    }

    return out;
}
