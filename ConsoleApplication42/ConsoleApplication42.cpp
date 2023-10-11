#include <iostream>
#include "var.h"

using namespace std;

int main() {


	var a = 15;
	var b = "Hello";
	var c = 7.8;
	var d = "50";

	d += a;
	cout << d << endl;

	a += d;
	cout << a << endl;

	b = d + a;
	cout << b << endl << endl;

	b = a + d;
	cout << b << endl << endl;


	if (a == b)
		cout << "Equal" << endl;
	else
		cout << "Not equal" << endl;


	a = "Microsfot";
	cout << a << endl << endl;

	b = "Windows";
	cout << b << endl << endl;

	c = a + b;
	cout << c << endl << endl;

	c = a * b;
	cout << c << endl;

	c = a / b;
	cout << c << endl;

	a *= b;
	cout << a << endl;

	b /= a;
	cout << b << endl;

	return 0;
}
