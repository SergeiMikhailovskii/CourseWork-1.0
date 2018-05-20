#include "Header.h"
void adminMode() {
	int role = 1;
	while (true) {
		switch (adminMenu()) {
		case 1:
			workWithAccounts();
			break;
		case 2:
			workWithData();
			break;
		case 3:
			startingMenu(role);
			break;
		default:
			cout << "Choose 1-3" << endl;
			cout << endl;
		}
	}
}
void workWithAccounts() {
	Accounts accs;
	while (true) {
		switch (accountsMenu()) {
		case 1:
			createAccountsFile(accs);
			break;
		case 2:
			showAccounts(accs);
			break;
		case 3:
			addAccount(accs);
			break;
		case 4:
			editAccount(accs);
			break;
		case 5:
			deleteAccount(accs);
			break;
		case 6:
			adminMode();
			break;
		default:
			cout << "Choose 1-6" << endl;
			break;
		}
	}
}
void createAccountsFile(Accounts accs) {
	const int codeOfEnter = 13;
	if (_getch() == codeOfEnter) {
		accs.login = "admin";
		accs.password = "12345";
		accs.role = 1;
		ofstream file("list.txt");
		if (file.is_open()) {
			file << accs.login << " " << accs.password << " " << accs.role << endl;
			file.close();
			cout << "Accounts file created!" << endl;
		}
		else {
			writeThatFileCannotBeOpened();
		}
	}
}
void showAccounts(Accounts accs) {
	ifstream file("list.txt");
	if (file.is_open()) {
		int i = 0;
		cout << "\t\tUsers" << endl;
		cout << "N  Login               Password  Role" << endl;
		while (file >> accs.login >> accs.password >> accs.role) {
			cout << setw(2) << i << " " << setw(20) << left << accs.login << setw(10) << accs.password << " " << accs.role << endl;
			i++;
		}
		file.close();
	}
	else {
		writeThatFileCannotBeOpened();
	}
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
void addAccount(Accounts accs) {
	cout << "Enter the login" << endl;
	cin >> accs.login;
	cout << "Enter the password" << endl;
	cin >> accs.password;
	cout << "Enter the role" << endl;
	inputRoleOrStatusValue(accs.role);
	ofstream file("list.txt", ios_base::app);
	if (file.is_open()) {
		file << accs.login << " " << accs.password << " " << accs.role << endl;
		file.close();
		cout << "User added" << endl;
	}
	else {
		writeThatFileCannotBeOpened();
	}
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
void editAccount(Accounts accs) {
	showAccounts(accs);
	vector <Accounts> users;
	ifstream file("list.txt");
	if (file.is_open()) {
		while (file >> accs.login >> accs.password >> accs.role) {
			users.push_back(accs);
		}
		file.close();
	}
	else {
		writeThatFileCannotBeOpened();
	}
	cout << "Enter the number of account, whose information you want to change" << endl;
	int num;
	enterAccountsVectorIndex(num, users);
	if (!isThisNumberReservedByAdminAccount(num)) {
		cout << "Enter the new login" << endl;
		isLoginUnique(users[num].login);
		cout << "Enter the new password" << endl;
		cin >> users[num].password;
		cout << "Enter the new role" << endl;
		inputRoleOrStatusValue(users[num].role);
		cout << "Information successfully changed" << endl;
		ofstream file1("list.txt");
		for (unsigned int i = 0; i < users.size(); i++) {
			file1 << users[i].login << " " << users[i].password << " " << users[i].role << endl;
		}
		file1.close();
	}
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
void deleteAccount(Accounts accs) {
	showAccounts(accs);
	vector <Accounts> users;
	ifstream file("list.txt");
	if (file.is_open()) {
		while (file >> accs.login >> accs.password >> accs.role) {
			users.push_back(accs);
		}
		file.close();
	}
	else {
		writeThatFileCannotBeOpened();
	}
	cout << "Enter the number of account, whose information you want to delete" << endl;
	int num;
	enterAccountsVectorIndex(num, users);
	if (!isThisNumberReservedByAdminAccount(num)) {
		while (file >> accs.login >> accs.password >> accs.role) {
			users.push_back(accs);
		}
		users.erase(users.begin() + num);
		cout << "User deleted" << endl;
		ofstream file1("list.txt");
		if (file1.is_open()) {
			for (unsigned int i = 0; i < users.size(); i++) {
				file1 << users[i].login << " " << users[i].password << " " << users[i].role << endl;
			}
			file1.close();
		}
		else {
			writeThatFileCannotBeOpened();
		}
	}
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
void workWithData() {
	while (true) {
		switch (dataMenu())
		{
		case 1:
			editingMode();
			break;
		case 2:
			treatmentMode();
			break;
		case 3:
			adminMode();
			break;
		default:
			cout << "Choose 1 - 3" << endl;
			break;
		}
	}
}
void editingMode() {
	vector <orders> Ord;
	orders Orders;
	while (true) {
		switch (editingMenu())
		{
		case 1:
			createOrdersFile();
			break;
		case 2:
			showOrdersFile(Orders);
			break;
		case 3:
			addOrder(Orders);
			break;
		case 4:
			editOrder(Orders, Ord);
			break;
		case 5:
			deleteOrder(Orders, Ord);
			break;
		case 6:
			workWithData();
			break;
		default:
			cout << "Choose 1- 6" << endl;
			break;
		}
	}
}
void createOrdersFile() {
	ofstream file("order.txt");
	if (file.is_open()) {
		file.close();
		cout << "Orders file created" << endl;
	}
	else {
		writeThatFileCannotBeOpened();
	}
}
void showOrdersFile(orders Orders) {
	const int valueOfEmptyOrders = 0;
	ifstream file("order.txt");
	if (file.is_open()) {
		int i = 0;
		cout << "\t\t\t\t\t\t\tOrders" << endl;
		cout << " N     Product        Mark        Surname        Name     Last Name Phone number Cost   Recept      Issue   Status" << endl;
		while (file >> Orders.product >> Orders.mark >> Orders.surname >> Orders.name >> Orders.secondName >> Orders.phoneNumber >> Orders.cost >> Orders.dayOfRecept >> Orders.monthOfRecept
			>> Orders.yearOfRecept >> Orders.dayOfIssue >> Orders.monthOfIssue >> Orders.yearOfIssue >> Orders.status) {
			printStructWithOrders(Orders, i);
			i++;
		}
		file.close();
		if (i == valueOfEmptyOrders) {
			cout << "There're no orders now!" << endl;
		}
	}
	else {
		writeThatFileCannotBeOpened();
	}
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
void addOrder(orders Orders) {
	cout << "Enter the product" << endl;
	cin >> Orders.product;
	cout << "Enter the mark" << endl;
	cin >> Orders.mark;
	cout << "Enter the surname" << endl;
	cin >> Orders.surname;
	cout << "Enter the name" << endl;
	cin >> Orders.name;
	cout << "Enter the last name" << endl;
	cin >> Orders.secondName;
	cout << "Enter the phone number" << endl;
	inputPhoneNumber(Orders.phoneNumber);
	cout << "Enter the cost" << endl;
	inputCost(Orders.cost);
	inputReceptAndIssueDates(Orders.dayOfRecept, Orders.monthOfRecept, Orders.yearOfRecept, Orders.dayOfIssue, Orders.monthOfIssue, Orders.yearOfIssue);
	cout << "Enter the status" << endl;
	inputRoleOrStatusValue(Orders.status);
	ofstream file("order.txt", ios_base::app);
	if (file.is_open()) {
		file << Orders.product << " " << Orders.mark << " " << Orders.surname << " " << Orders.name << " " << Orders.secondName << " " << Orders.phoneNumber << " " <<
			Orders.cost << " " << Orders.dayOfRecept << " " << Orders.monthOfRecept << " " << Orders.yearOfRecept << " " << Orders.dayOfIssue << " " << Orders.monthOfIssue
			<< " " << Orders.yearOfIssue << " " << Orders.status << "\n";
		file.close();
		cout << "Order added!" << endl;
	}
	else {
		writeThatFileCannotBeOpened();
	}
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
void editOrder(orders Order, vector <orders> Ord) {
	showOrdersFile(Order);
	fullfillOrdersVector(Ord);
	cout << "Enter the position of the order in the list you want to change" << endl;
	int choise;
	enterOrdersVectorIndex(choise, Ord);
	while (true) {
		bool flagOfExit = false;
		switch (editingActionsWithOrdersMenu())
		{
		case 1:
			cout << "Enter the product" << endl;
			cin >> Ord[choise].product;
			break;
		case 2:
			cout << "Enter the mark" << endl;
			cin >> Ord[choise].mark;
			break;
		case 3:
			cout << "Enter the surname" << endl;
			cin >> Ord[choise].surname;
			break;
		case 4:
			cout << "Enter the name" << endl;
			cin >> Ord[choise].name;
			break;
		case 5:
			cout << "Enter the last name" << endl;
			cin >> Ord[choise].secondName;
			break;
		case 6:
			cout << "Enter the phone number" << endl;
			inputPhoneNumber(Ord[choise].phoneNumber);
			break;
		case 7:
			cout << "Enter the cost" << endl;
			inputCost(Ord[choise].cost);
			break;
		case 8:
			cout << "Enter the day of recept" << endl;
			inputDate(Ord[choise].dayOfRecept, "day");
			break;
		case 9:
			cout << "Enter the month of recept" << endl;
			inputDate(Ord[choise].monthOfRecept, "month");
			break;
		case 10:
			cout << "Enter the year of recept" << endl;
			inputDate(Ord[choise].yearOfRecept, "year");
			break;
		case 11:
			cout << "Enter the day of issue" << endl;
			inputDate(Ord[choise].dayOfIssue, "day");
			break;
		case 12:
			cout << "Enter the month of issue" << endl;
			inputDate(Ord[choise].monthOfIssue, "month");
			break;
		case 13:
			cout << "Enter the year of issue" << endl;
			inputDate(Ord[choise].yearOfIssue, "year");
			break;
		case 14:
			cout << "Enter the status" << endl;
			inputRoleOrStatusValue(Ord[choise].status);
			break;
		case 15:
			flagOfExit = true;
			break;
		default:
			cout << "Choose 1 - 15" << endl;
			break;
		}
		if (flagOfExit) {
			break;
		}
		else if (!flagOfExit && editingActionsWithOrdersMenu() >= 1 && editingActionsWithOrdersMenu() <= 14) {
			cout << "Field successfully changed" << endl;
		}
	}
	transferOrdersToFile(Ord);
	cout << "Information edited" << endl;
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
void deleteOrder(orders Order, vector <orders> Ord) {
	fullfillOrdersVector(Ord);
	showOrdersFile(Order);
	int choise;
	cout << "Enter the number of order you want to delete" << endl;
	enterOrdersVectorIndex(choise, Ord);
	Ord.erase(Ord.begin() + choise);
	transferOrdersToFile(Ord);
	cout << "Order deleted" << endl;
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();
}
void treatmentMode() {
	orders Order;
	while (true) {
		switch (treatmentMenu())
		{
		case 1:
			sortByDate(Order);
			break;
		case 2:
			showOverduedOrders(Order);
			break;
		case 4:
			workWithData();
			break;
		case 3:
			showTotalRevenue(Order);
			break;
		default:
			cout << "Choose 1 or 2" << endl;
			break;
		}
	}
}