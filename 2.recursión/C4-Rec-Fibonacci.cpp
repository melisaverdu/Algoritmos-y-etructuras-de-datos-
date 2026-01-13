#include <iostream>
#include <string>

using namespace std;

int fibonacci(int n) {
	if (n <= 2) return 1;
	else		return fibonacci(n-1) + fibonacci(n-2);
}

int fiboTail(int actual, int previo, int n) {
if (n == 1) return actual;
else		return fiboTail(actual + previo, actual, n-1);
}

int main()
{	int a=9;
	cout<<"Fibonacci de "<<a<<" = "<<fibonacci(a)<<endl;
	cout<<"Fibonacci de "<<a<<" = "<<fiboTail(1,0,a)<<endl;
	
	
	return 0;
}

/*
int gcd(int m, int n) {
	if (m % n == 0) return n;
	else if (m < n) return gcd(n, m); 
	else return gcd(n, m % n);
}*/