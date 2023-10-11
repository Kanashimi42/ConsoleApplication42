#include "var.h"

using namespace std;
var::var() { }
var::var(int element) { varInt = element; varIntActive = true; }
var::var(double element) { varDouble = element; varDoubleActive = true; }
var::var(string element) { varString = element; varStringActive = true; }
var::var(const char* element) {
	varChar = new char[strlen(element) + 1];
	strcpy_s(varChar, strlen(element) + 1, element);
	varString = string(varChar);
	varStringActive = true;
}
int var::GetVarInt() const { return varInt; }
double var::GetVarDouble() const { return varDouble; }
string var::GetVarString() const { return varString; }

bool var::GetVarIntActive() const { return varIntActive; }
bool var::GetVarDoubleActive() const { return varDoubleActive; }
bool var::GetVarStringActive() const { return varStringActive; }
void var::SetVarInt(int element) { varInt = element; }
void var::SetVarDouble(double element) { varDouble = element; }
void var::SetVarString(string element) { varString = element; }

void var::SetVarIntActive(bool status) { varIntActive = status; }
void var::SetVarDoubleActive(bool status) { varDoubleActive = status; }
void var::SetVarStringActive(bool status) { varStringActive = status; }

void var::operator+=(const var a) {
	if (varIntActive && a.GetVarIntActive())
		varInt += a.GetVarInt();
	else if (varDoubleActive && a.GetVarDoubleActive())
		varDouble += a.GetVarDouble();
	else if (varStringActive && a.GetVarStringActive())
		varString += a.GetVarString();
	else if (varDoubleActive && a.GetVarIntActive()) {
		varDouble += a.GetVarInt();

		varDoubleActive = 1;
		varStringActive = 0;
		varIntActive = 0;
	}
	else if (varStringActive && a.GetVarIntActive()) {
		varString += to_string(a.GetVarInt());

		varDoubleActive = 0;
		varStringActive = 1;
		varIntActive = 0;
	}
	else if (varIntActive && a.GetVarDoubleActive()) {
		varInt += a.GetVarDouble();

		varDoubleActive = 0;
		varStringActive = 0;
		varIntActive = 1;
	}
	else if (varStringActive && a.GetVarDoubleActive()) {
		varString += to_string(a.GetVarDouble());

		varDoubleActive = 0;
		varStringActive = 1;
		varIntActive = 0;
	}
	else if (varIntActive && a.GetVarStringActive()) {
		varInt += stoi(a.GetVarString());

		varDoubleActive = 0;
		varStringActive = 0;
		varIntActive = 1;
	}
	else if (varDoubleActive && a.GetVarStringActive()) {
		varDouble += stod(a.GetVarString());

		varDoubleActive = 1;
		varStringActive = 0;
		varIntActive = 0;
	}
	else
		cout << "Error!" << endl;
}
void var::operator-=(const var a) {
	if (varIntActive && a.GetVarIntActive())
		varInt -= a.GetVarInt();
	else if (varDoubleActive && a.GetVarDoubleActive())
		varDouble -= a.GetVarDouble();
	else if (varStringActive && a.GetVarStringActive()) {}
	else if (varDoubleActive && a.GetVarIntActive()) {
		varDouble -= a.GetVarInt();

		varDoubleActive = 1;
		varStringActive = 0;
		varIntActive = 0;
	}
	else if (varStringActive && a.GetVarIntActive()) {}
	else if (varIntActive && a.GetVarDoubleActive()) {
		varInt -= a.GetVarDouble();

		varDoubleActive = 0;
		varStringActive = 0;
		varIntActive = 1;
	}
	else if (varStringActive && a.GetVarDoubleActive()) {}
	else if (varIntActive && a.GetVarStringActive()) {
		varInt -= stoi(a.GetVarString());

		varDoubleActive = 0;
		varStringActive = 0;
		varIntActive = 1;
	}
	else if (varDoubleActive && a.GetVarStringActive()) {
		varDouble -= stod(a.GetVarString());

		varDoubleActive = 1;
		varStringActive = 0;
		varIntActive = 0;
	}
	else
		cout << "Error!" << endl;
}
void var::operator*=(const var a) {
	if (varStringActive && a.GetVarStringActive()) {
		char temp[200];
		int y = 0;
		string tempStr;

		for (int i = 0; i < varString.length(); i++)
			for (int j = 0; j < a.GetVarString().length(); j++)
				if (varString[i] == a.GetVarString()[j])
					temp[y++] = varString[i];

		temp[y] = '\0';
		varString = temp;
	}
}
void var::operator/=(const var a) {
	if (varStringActive && a.GetVarStringActive()) {
		char temp[200];
		int y = 0;
		string tempStr;

		for (int i = 0; i < varString.length(); i++)
			for (int j = 0; j < a.GetVarString().length(); j++)
				if (varString[i] == a.GetVarString()[j])
					break;
				else if (j == a.GetVarString().length() - 1)
					temp[y++] = varString[i];

		temp[y] = '\0';
		varString = temp;
	}
}

var var::operator=(const var element) {
	if (!element.GetVarIntActive() && !element.GetVarDoubleActive()) {

		varStringActive = 1;
		varIntActive = 0;
		varDoubleActive = 0;
		varString = element.GetVarString();
	}
	else if (!element.GetVarDoubleActive() && element.GetVarString().length() == 0) {
		varIntActive = 1;
		varStringActive = 0;
		varDoubleActive = 0;
		varInt = element.GetVarInt();
	}
	else if (!element.GetVarIntActive() && element.GetVarString().length() == 0) {

		varDoubleActive = 1;
		varIntActive = 0;
		varStringActive = 0;
		varDouble = element.GetVarDouble();
	}

	return element;
}
ostream& operator<<(ostream& os, const var& element) {
	if (element.GetVarIntActive())
		os << element.GetVarInt();
	else if (element.GetVarDoubleActive())
		os << element.GetVarDouble();
	else if (element.GetVarStringActive())
		os << element.GetVarString();

	return os;
}
istream& operator>>(istream& is, var& element) {
	if (element.GetVarIntActive()) {
		int temp;
		cin >> temp;
		element.SetVarInt(temp);
	}
	else if (element.GetVarDoubleActive()) {
		double temp;
		cin >> temp;
		element.SetVarDouble(temp);
	}
	else if (element.GetVarStringActive()) {
		string temp;
		cin >> temp;
		element.SetVarString(temp);
	}

	return is;
}
var operator+(const var a, const var b) {
	if (a.GetVarIntActive() && b.GetVarIntActive())
		return a.GetVarInt() + b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarDoubleActive())
		return a.GetVarDouble() + b.GetVarDouble();
	else if (a.GetVarStringActive() && b.GetVarStringActive())
		return a.GetVarString() + b.GetVarString();
	else if (a.GetVarIntActive() && b.GetVarDoubleActive())
		return a.GetVarInt() + b.GetVarDouble();
	else if (a.GetVarIntActive() && b.GetVarStringActive())
		return a.GetVarInt() + stoi(b.GetVarString());
	else if (a.GetVarDoubleActive() && b.GetVarIntActive())
		return a.GetVarDouble() + b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarStringActive())
		return a.GetVarDouble() + stod(b.GetVarString());
	else if (a.GetVarStringActive() && b.GetVarIntActive())
		return a.GetVarString() + to_string(b.GetVarInt());
	else if (a.GetVarStringActive() && b.GetVarDoubleActive())
		return a.GetVarString() + to_string(b.GetVarDouble());

	cout << "Error!" << endl;
	return 0;
}
var operator-(const var a, const var b) {
	if (a.GetVarIntActive() && b.GetVarIntActive())
		return a.GetVarInt() - b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarDoubleActive())
		return a.GetVarDouble() - b.GetVarDouble();
	else if (a.GetVarStringActive() && b.GetVarStringActive())
		return 0;
	else if (a.GetVarIntActive() && b.GetVarDoubleActive())
		return a.GetVarInt() - b.GetVarDouble();
	else if (a.GetVarIntActive() && b.GetVarStringActive())
		return a.GetVarInt() - stoi(b.GetVarString());
	else if (a.GetVarDoubleActive() && b.GetVarIntActive())
		return a.GetVarDouble() - b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarStringActive())
		return a.GetVarDouble() - stod(b.GetVarString());
	else if (a.GetVarStringActive() && b.GetVarIntActive())
		return a.GetVarString() - to_string(b.GetVarInt());
	else if (a.GetVarStringActive() && b.GetVarDoubleActive())
		return a.GetVarString() - to_string(b.GetVarDouble());

	cout << "Error!" << endl;
	return 0;
}
var operator*(const var a, const var b) {
	if (a.GetVarStringActive() && b.GetVarStringActive()) {
		char temp[200];
		int y = 0;

		for (int i = 0; i < a.GetVarString().length(); i++)
			for (int j = 0; j < b.GetVarString().length(); j++)
				if (a.GetVarString()[i] == b.GetVarString()[j])
					temp[y++] = a.GetVarString()[i];

		temp[y] = '\0';
		return var(temp);
	}

	cout << "Error!" << endl;
	return 0;
}
var operator/(const var a, const var b) {
	if (a.GetVarStringActive() && b.GetVarStringActive()) {
		char temp[200];
		int y = 0;

		for (int i = 0; i < a.GetVarString().length(); i++)
			for (int j = 0; j < b.GetVarString().length(); j++)
				if (a.GetVarString()[i] == b.GetVarString()[j])
					break;
				else if (j == b.GetVarString().length() - 1)
					temp[y++] = a.GetVarString()[i];

		temp[y] = '\0';
		return var(temp);
	}

	cout << "Error!" << endl;
	return 0;
}

bool operator<(const var a, const var b) {
	if (a.GetVarIntActive() && b.GetVarIntActive())
		return a.GetVarInt() < b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarDoubleActive())
		return a.GetVarDouble() < b.GetVarDouble();
	else if (a.GetVarStringActive() && b.GetVarStringActive())
		return a.GetVarString().length() < b.GetVarString().length();
	else if (a.GetVarIntActive() && b.GetVarDoubleActive())
		return a.GetVarInt() < b.GetVarDouble();
	else if (a.GetVarIntActive() && b.GetVarStringActive())
		return a.GetVarInt() < b.GetVarString().length();
	else if (a.GetVarDoubleActive() && b.GetVarIntActive())
		return a.GetVarDouble() < b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarStringActive())
		return a.GetVarDouble() < b.GetVarString().length();
	else if (a.GetVarStringActive() && b.GetVarIntActive())
		return a.GetVarString().length() < b.GetVarInt();
	else if (a.GetVarStringActive() && b.GetVarDoubleActive())
		return a.GetVarString().length() < b.GetVarDouble();

	cout << "Error!" << endl;
	return 0;
}
bool operator>(const var a, const var b) {
	if (a.GetVarIntActive() && b.GetVarIntActive())
		return a.GetVarInt() > b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarDoubleActive())
		return a.GetVarDouble() > b.GetVarDouble();
	else if (a.GetVarStringActive() && b.GetVarStringActive())
		return a.GetVarString().length() > b.GetVarString().length();
	else if (a.GetVarIntActive() && b.GetVarDoubleActive())
		return a.GetVarInt() > b.GetVarDouble();
	else if (a.GetVarIntActive() && b.GetVarStringActive())
		return a.GetVarInt() > b.GetVarString().length();
	else if (a.GetVarDoubleActive() && b.GetVarIntActive())
		return a.GetVarDouble() > b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarStringActive())
		return a.GetVarDouble() > b.GetVarString().length();
	else if (a.GetVarStringActive() && b.GetVarIntActive())
		return a.GetVarString().length() > b.GetVarInt();
	else if (a.GetVarStringActive() && b.GetVarDoubleActive())
		return a.GetVarString().length() > b.GetVarDouble();

	cout << "Error!" << endl;
	return 0;
}
bool operator<=(const var a, const var b) {
	if (a.GetVarIntActive() && b.GetVarIntActive())
		return a.GetVarInt() <= b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarDoubleActive())
		return a.GetVarDouble() <= b.GetVarDouble();
	else if (a.GetVarStringActive() && b.GetVarStringActive())
		return a.GetVarString().length() <= b.GetVarString().length();
	else if (a.GetVarIntActive() && b.GetVarDoubleActive())
		return a.GetVarInt() <= b.GetVarDouble();
	else if (a.GetVarIntActive() && b.GetVarStringActive())
		return a.GetVarInt() <= b.GetVarString().length();
	else if (a.GetVarDoubleActive() && b.GetVarIntActive())
		return a.GetVarDouble() <= b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarStringActive())
		return a.GetVarDouble() <= b.GetVarString().length();
	else if (a.GetVarStringActive() && b.GetVarIntActive())
		return a.GetVarString().length() <= b.GetVarInt();
	else if (a.GetVarStringActive() && b.GetVarDoubleActive())
		return a.GetVarString().length() <= b.GetVarDouble();

	cout << "Error!" << endl;
	return 0;
}
bool operator>=(const var a, const var b) {
	if (a.GetVarIntActive() && b.GetVarIntActive())
		return a.GetVarInt() >= b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarDoubleActive())
		return a.GetVarDouble() >= b.GetVarDouble();
	else if (a.GetVarStringActive() && b.GetVarStringActive())
		return a.GetVarString().length() >= b.GetVarString().length();
	else if (a.GetVarIntActive() && b.GetVarDoubleActive())
		return a.GetVarInt() >= b.GetVarDouble();
	else if (a.GetVarIntActive() && b.GetVarStringActive())
		return a.GetVarInt() >= b.GetVarString().length();
	else if (a.GetVarDoubleActive() && b.GetVarIntActive())
		return a.GetVarDouble() >= b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarStringActive())
		return a.GetVarDouble() >= b.GetVarString().length();
	else if (a.GetVarStringActive() && b.GetVarIntActive())
		return a.GetVarString().length() >= b.GetVarInt();
	else if (a.GetVarStringActive() && b.GetVarDoubleActive())
		return a.GetVarString().length() >= b.GetVarDouble();

	cout << "Error!" << endl;
	return 0;
}
bool operator==(const var a, const var b) {
	if (a.GetVarIntActive() && b.GetVarIntActive())
		return a.GetVarInt() == b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarDoubleActive())
		return a.GetVarDouble() == b.GetVarDouble();
	else if (a.GetVarStringActive() && b.GetVarStringActive())
		return a.GetVarString().length() == b.GetVarString().length();
	else if (a.GetVarIntActive() && b.GetVarDoubleActive())
		return a.GetVarInt() == b.GetVarDouble();
	else if (a.GetVarIntActive() && b.GetVarStringActive())
		return a.GetVarInt() == b.GetVarString().length();
	else if (a.GetVarDoubleActive() && b.GetVarIntActive())
		return a.GetVarDouble() == b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarStringActive())
		return a.GetVarDouble() == b.GetVarString().length();
	else if (a.GetVarStringActive() && b.GetVarIntActive())
		return a.GetVarString().length() == b.GetVarInt();
	else if (a.GetVarStringActive() && b.GetVarDoubleActive())
		return a.GetVarString().length() == b.GetVarDouble();

	cout << "Error!" << endl;
	return 0;
}
bool operator!=(const var a, const var b) {
	if (a.GetVarIntActive() && b.GetVarIntActive())
		return a.GetVarInt() != b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarDoubleActive())
		return a.GetVarDouble() != b.GetVarDouble();
	else if (a.GetVarStringActive() && b.GetVarStringActive())
		return a.GetVarString().length() != b.GetVarString().length();
	else if (a.GetVarIntActive() && b.GetVarDoubleActive())
		return a.GetVarInt() != b.GetVarDouble();
	else if (a.GetVarIntActive() && b.GetVarStringActive())
		return a.GetVarInt() != b.GetVarString().length();
	else if (a.GetVarDoubleActive() && b.GetVarIntActive())
		return a.GetVarDouble() != b.GetVarInt();
	else if (a.GetVarDoubleActive() && b.GetVarStringActive())
		return a.GetVarDouble() != b.GetVarString().length();
	else if (a.GetVarStringActive() && b.GetVarIntActive())
		return a.GetVarString().length() != b.GetVarInt();
	else if (a.GetVarStringActive() && b.GetVarDoubleActive())
		return a.GetVarString().length() != b.GetVarDouble();

	cout << "Error!" << endl;
	return 0;
}