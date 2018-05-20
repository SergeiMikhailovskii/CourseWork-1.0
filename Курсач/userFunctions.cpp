#include "Header.h"
void userMode() {
	int role = 0;
	while (true) {
		switch (userMenu())
		{
		case 1:
			treatmentMode();
			break;
		case 2:
			searchingMode();
			break;
		case 3:
			sortingMode();
			break;
		case 4:
			startingMenu(role);
			break;
		default:
			cout << "Choose 1-4" << endl;
			break;
		}
	}
}
void sortByDate(orders Order) {
	vector <orders> Ord;
	fullfillOrdersVector(Ord);
	for (unsigned int i = 0; i < Ord.size() - 1; i++) {
		for (unsigned int j = i + 1; j < Ord.size(); j++) {
			if (Ord[i].yearOfIssue > Ord[j].yearOfIssue) {
				swap(Ord[i], Ord[j]);
			}
			else if (Ord[i].yearOfIssue == Ord[j].yearOfIssue && Ord[i].monthOfIssue > Ord[j].monthOfIssue) {
				swap(Ord[i], Ord[j]);
			}
			else if (Ord[i].yearOfIssue == Ord[j].yearOfIssue && Ord[i].monthOfIssue == Ord[j].monthOfIssue && Ord[i].dayOfIssue > Ord[j].dayOfIssue) {
				swap(Ord[i], Ord[j]);
			}
		}
	}
	transferOrdersToFile(Ord);
	cout << "Orders sorted by date of issue" << endl;
	showOrdersFile(Order);
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
void sortingMode() {
	while (true) {
		switch (sortingMenu())
		{
		case 1:
			sortOrders("mark");
			break;
		case 2:
			sortOrders("surname");
			break;
		case 3:
			sortOrders("cost");
			break;
		case 4:
			userMode();
			break;
		default:
			cout << "Choose 1-4" << endl;
			break;
		}
	}
}
void sortOrders(const string a) {
	vector <orders> Ord;
	fullfillOrdersVector(Ord);
	for (unsigned int i = 0; i < Ord.size() - 1; i++) {
		for (unsigned int j = i + 1; j < Ord.size(); j++) {
			if (a == "cost" && Ord[i].cost > Ord[j].cost) {
				swap(Ord[i], Ord[j]);
			}
			else if (a == "surname" && Ord[i].surname > Ord[j].surname) {
				swap(Ord[i], Ord[j]);
			}
			else if (a == "mark" && Ord[i].mark > Ord[j].mark) {
				swap(Ord[i], Ord[j]);
			}
		}
	}
	showOrdersVector(Ord);
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
void showOrdersVector(vector<orders> Ord) {
	cout << " N     Product        Mark        Surname        Name     Last Name Phone number Cost     Recept    Issue   Status" << endl;
	for (unsigned int i = 0; i < Ord.size(); i++) {
		printStructWithOrders(Ord[i], i);
	}
}
void searchingMode() {
	while (true) {
		switch (searchingMenu()) {
		case 1:
			searchData("surname");
			break;
		case 2:
			searchData("name");
			break;
		case 3:
			searchData("phone");
			break;
		case 4:
			userMode();
			break;
		}
	}
}
void searchData(const string a) {
	vector <orders> Ord;
	fullfillOrdersVector(Ord);
	orders Orders;
	showOrdersFile(Orders);
	cout << "Enter the " << a << "/part of it" << endl;
	string input;
	cin >> input;
	int counter = 0;
	cout << " N     Product        Mark        Surname        Name     Last Name Phone number Cost     Recept    Issue   Status" << endl;
	for (unsigned int i = 0; i < Ord.size(); i++) {
		if ((a == "name" && (Ord[i].name).find(input) != string::npos) || (a == "phone" && (Ord[i].phoneNumber).find(input) != string::npos) ||
			(a == "surname" && (Ord[i].surname).find(input) != string::npos)) {
			printStructWithOrders(Ord[i], i);
			counter++;
		}
	}
	if (counter == 0) {
		cout << "There're no users with such " << a << " in list" << endl;
	}
	else {
		cout << "Users found: " << counter << endl;
	}
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
//By days of issue
void showTotalRevenue(orders Order) {
	cout << endl;
	vector <orders> Ord;
	fullfillOrdersVector(Ord);
	int fDay, fMonth, fYear, lDay, lMonth, lYear;
	long int fDate, lDate;
	long int curDate = 0;
	int sum = 0;
	showOrdersFile(Order);
	areRevenueDatesRight(fDay, fMonth, fYear, lDay, lMonth, lYear, fDate, lDate);
	cout << endl;
	cout << " N     Product        Mark        Surname        Name     Last Name Phone number Cost     Recept    Issue   Status" << endl;
	for (unsigned int i = 0; i < Ord.size(); i++) {
		curDate = Ord[i].dayOfIssue + Ord[i].monthOfIssue * 100 + Ord[i].yearOfIssue * 10000;
		if (curDate > fDate && curDate < lDate) {
			printStructWithOrders(Ord[i], i);
			sum += Ord[i].cost;
		}
	}
	cout << "Total Revenue: " << sum << endl;
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
//Shows by date of issue
void showOverduedOrders(orders Order) {
	cout << endl;
	vector <orders> Ord;
	fullfillOrdersVector(Ord);
	int curDay, curMonth, curYear, counterForOverdued = 0, counterForNotOverdued = 0;
	showOrdersFile(Order);
	enterCurrentDate(curDay, curMonth, curYear);
	cout << endl;
	//Will contain indexes of orders, which are overdued
	vector<int> indexesOverdued;
	vector<int> indexesNotOverdued;
	for (unsigned int i = 0; i < Ord.size(); i++) {
		if (curYear > Ord[i].yearOfIssue || (curYear == Ord[i].yearOfIssue && curMonth > Ord[i].monthOfIssue) || (curYear == Ord[i].yearOfIssue &&
			curMonth == Ord[i].monthOfIssue && curDay > Ord[i].dayOfIssue)) {
			indexesOverdued.push_back(i);
			counterForOverdued++;
		}
		else {
			counterForNotOverdued++;
			indexesNotOverdued.push_back(i);
		}
	}
	if (counterForOverdued != 0) {
		cout << "Overdued orders:" << endl;
		cout << " N     Product        Mark        Surname        Name     Last Name Phone number Cost   Recept      Issue   Status" << endl;
		for (unsigned int i = 0; i < indexesOverdued.size(); i++) {
			printStructWithOrders(Ord[indexesOverdued[i]], indexesOverdued[i]);
		}
	}
	else {
		cout << "There're no overduded orders" << endl;
	}
	if (counterForNotOverdued != 0) {
		cout << "Orders in a planned manner: " << endl;
		cout << " N     Product        Mark        Surname        Name     Last Name Phone number Cost   Recept      Issue   Status" << endl;
		for (unsigned int i = 0; i < indexesNotOverdued.size(); i++) {
			printStructWithOrders(Ord[indexesNotOverdued[i]], indexesNotOverdued[i]);
		}
		cout << endl;
	}
	else {
		cout << "All orders are overdued" << endl;
	}
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}