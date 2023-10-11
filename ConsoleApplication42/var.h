#pragma once
#include <iostream>
#include <string>

using namespace std;

class var {
	int varInt;
	double varDouble;
	char* varChar;
	string varString;

	bool varIntActive = false;
	bool varDoubleActive = false;
	bool varStringActive = false;
public:
	var();
	var(int);
	var(double);
	var(const char*);
	var(string);

	int GetVarInt() const;
	double GetVarDouble() const;
	string GetVarString() const;

	bool GetVarIntActive() const;
	bool GetVarDoubleActive() const;
	bool GetVarStringActive() const;

	void SetVarInt(int);
	void SetVarDouble(double);
	void SetVarString(string);

	void SetVarIntActive(bool state);
	void SetVarDoubleActive(bool state);
	void SetVarStringActive(bool state);

	void operator+=(const var);
	void operator-=(const var);
	void operator*=(const var);
	void operator/=(const var);

	var operator=(const var);
};
ostream& operator<<(ostream&, const var&);
istream& operator>>(istream&, var&);
bool operator<(const var, const var);
bool operator>(const var, const var);
bool operator<=(const var, const var);
bool operator>=(const var, const var);
bool operator==(const var, const var);
bool operator!=(const var, const var);
var operator+(const var, const var); 
var operator-(const var, const var); 
var operator*(const var, const var); 
var operator/(const var, const var); 

