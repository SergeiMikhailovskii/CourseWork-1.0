#include "Header.h"
void inputNumber(int &number) {
	while (true) {
		cin >> number;
		if (cin.get() == '\n') {
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Wrong input" << endl;
	}
}
void inputRoleOrStatusValue(int &a) {
	while (true) {
		inputNumber(a);
		if (a == 0 || a == 1) {
			break;
		}
		cout << "Choose only 0 or 1" << endl;
	}
}
bool areRevenueDatesRight(int &fDay, int &fMonth, int &fYear, int &lDay, int &lMonth, int &lYear, long int &fDate, long int &lDate) {
	while (true) {
		cout << "Enter the first day" << endl;
		inputDate(fDay, "day");
		cout << "Enter the month" << endl;
		inputDate(fMonth, "month");
		cout << "Enter the year" << endl;
		inputDate(fYear, "year");
		enterCurrentDate(lDay, lMonth, lYear);
		fDate = fDay + fMonth * 100 + fYear * 10000;
		lDate = lDay + lMonth * 100 + lYear * 10000;
		if (fDate < lDate) {
			return true;
		}
		cout << "First date should be earlier than last" << endl;
		cout << endl;
	}
}
bool isLoginUnique(string &login) {
	while (true) {
		cin >> login;
		Accounts account;
		ifstream file("list.txt");
		bool flag = true;
		while (file >> account.login >> account.password >> account.role) {
			if (account.login == login) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			cout << "This login already exists. Please, try again" << endl;
		}
		else {
			return flag;
		}
	}
}
bool isThisNumberReservedByAdminAccount(int x) {
	if (x == 0) {
		cout << "This account belongs to the admin, who can't be deleted or edited. Sorry :(" << endl;
		return true;
	}
	return false;
}
void inputCost(int &a) {
	while (true) {
		cin >> a;
		if (cin.get() == '\n' && (!cin.fail())) {
			if (a >= 0) {
				break;
			}
			else {
				cout << "Cost can't be less than 0" << endl;
			}
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
void inputPhoneNumber(string &number) {
	cout << "Number should be in format +375(XX)XXXXXXX" << endl;
	number += "+375";
	switch (mobileOperatorsListMenu())
	{
	case 1:
		number += "33";
		break;
	case 2:
		number += "29";
		break;
	case 3:
		number += "33";
		break;
	default:
		cout << "Choose 1 to 3" << endl;
		break;
	}
	string shortNumber;
	const int shortNumberLength = 7;
	while (true) {
		cout << "Enter the number: " << endl;
		cin >> shortNumber;
		bool phoneFromNumbers = true;
		for (unsigned int i = 0; i < shortNumber.length(); i++) {
			if (shortNumber[i]<'0' || shortNumber[i]>'9') {
				phoneFromNumbers = false;
				break;
			}
		}
		if (shortNumber.length() == shortNumberLength && phoneFromNumbers) {
			number += shortNumber;
			break;
		}
		cout << "Phone number should contain 7 numbers. Please, try again." << endl;
	}
}
void inputPassword(string &password) {
	password = "";
	int code;
	while (true) {
		cout << "Enter the password" << endl;
		code = _getch();
		system("cls");
		if (code == 13) {
			break;
		}
		else if (code == 8 && password.length() != 0) {
			password.erase(password.begin() + password.length() - 1);
		}
		else if (code == 8 && password.length() == 0) {
			cout << "You can't delete, as password doesn't contain anything now" << endl;
		}
		else {
			password += code;
		}
		for (unsigned int i = 0; i < password.length(); i++) {
			cout << "*";
		}
		cout << endl;
	}
}
void inputDate(int &number, const string parameter) {
	while (true) {
		inputNumber(number);
		if (parameter == "day") {
			if (number >= 1 && number <= 31) {
				return;
			}
		}
		else if (parameter == "month") {
			if (number >= 1 && number <= 12) {
				return;
			}
		}
		else if (parameter == "year") {
			if (number >= 2018 && number <= 2020) {
				return;
			}
		}
		cout << "Incorrect " << parameter << endl;
	}
}
void inputReceptAndIssueDates(int &rDay, int &rMonth, int &rYear, int &iDay, int &iMonth, int &iYear) {
	double rDate = 0;
	double iDate = 0;
	while (true) {
		cout << "Enter the recept day:" << endl;
		inputDate(rDay, "day");
		cout << "Enter the recept month:" << endl;
		inputDate(rMonth, "month");
		cout << "Enter the recept year:" << endl;
		inputDate(rYear, "year");
		cout << "Enter the issue day:" << endl;
		inputDate(iDay, "day");
		cout << "Enter the issue month:" << endl;
		inputDate(iMonth, "month");
		cout << "Enter the issue year:" << endl;
		inputDate(iYear, "year");
		rDate = rDay + rMonth * 100 + rYear * 10000;
		iDate = iDay + iMonth * 100 + iYear * 10000;
		if (iDate > rDate) {
			break;
		}
		cout << "Date of recept should be earlier than date of issue" << endl;
	}
}