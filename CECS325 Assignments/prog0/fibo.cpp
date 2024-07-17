//    Alvin Hang
//    Class (CECS 325-01)
//    Project Name (Prog 0 - Linux and C++ install)
//    Due Date (09/06/2023)
//
//    I certify that this program is my own original work. I did not copy any part of
//    this program from any other source. I further certify that I typed each and every
//    line of code in this program.

#include <iostream>
using namespace std;

//Fibo function
int fibo(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return fibo(n-1) + fibo(n-2); // recursion
}

int main()
{
	for (int i = 0; i <= 20; i++)
		cout << i << ":" << fibo(i)<<endl;

	return 0;
}
