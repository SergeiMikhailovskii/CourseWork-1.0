#include "Header.h"
void loginUser(int &role) {
	const int roleOfAdmin = 1;
	const int roleOfUser = 0;
	const int roleOfUnacceptedAdmin = 2;
	const int codeOfEnter = 13;
	system("cls");
	cout << "Enter your login" << endl;
	string enteredLogin;
	cin >> enteredLogin;
	cout << endl;
	string enteredPassword;
	inputPassword(enteredPassword);
	Accounts accounts;
	bool flag = false;
	ifstream list("list.txt");
	if (list.is_open()) {
		while (list >> accounts.login >> accounts.password >> role) {
			if (enteredPassword == accounts.password && enteredLogin == accounts.login) {
				flag = true;
				break;
			}
		}
		list.close();
	}
	else {
		writeThatFileCannotBeOpened();
	}
	cout << endl;
	if (flag) {
		cout << "Enter successed!" << endl;
		if (role == roleOfAdmin) {
			adminMode();
		}
		else if (role == roleOfUser) {
			userMode();
		}
		else if (role == roleOfUnacceptedAdmin) {
			cout << "Wait,while you would be accepted by admin or register as user" << endl;
		}
	}
	else {
		cout << "Enter failed! Please, try again." << endl;
		loginUser(role);
	}
}
void registrateUser(int &role) {
	system("cls");
	Accounts accounts;
	const int roleOfAdmin = 1;
	const int roleOfUnacceptedAdmin = 2;
	const int codeOfEnter = 13;
	cout << "Enter the Login" << endl;
	isLoginUnique(accounts.login);
	cout << endl;
	createPassword(accounts.password);
	cout << "Enter the role" << endl;
	inputRoleOrStatusValue(role);
	if (role == roleOfAdmin)
		role = roleOfUnacceptedAdmin;			//∆дем подтверждени€
	ofstream list("list.txt", ios_base::app);
	if (list.is_open()) {
		list << accounts.login << " " << accounts.password << " " << role << endl;
		list.close();
	}
	else {
		writeThatFileCannotBeOpened();
	}
	cout << "User registered!" << endl;
	cout << "Do you want to enter to your account? Press Enter, if yes" << endl;
	char choise = _getch();
	if (choise == codeOfEnter) {
		loginUser(role);
	}
	else {
		exitFromTheProgram();
	}
}
void transferOrdersToFile(vector<orders> Ord) {
	ofstream file1("order.txt");
	if (file1.is_open()) {
		for (unsigned int i = 0; i < Ord.size(); i++) {
			file1 << Ord[i].product << " " << Ord[i].mark << " " << Ord[i].surname << " " << Ord[i].name << " " << Ord[i].secondName << " " << Ord[i].phoneNumber << " " <<
				Ord[i].cost << " " << Ord[i].dayOfRecept << " " << Ord[i].monthOfRecept << " " << Ord[i].yearOfRecept << " " << Ord[i].dayOfIssue << " " << Ord[i].monthOfIssue
				<< " " << Ord[i].yearOfIssue << " " << Ord[i].status << "\n";
		}
		file1.close();
	}
	else {
		writeThatFileCannotBeOpened();
	}
}
void fullfillOrdersVector(vector<orders> &Ord) {
	orders Order;
	ifstream file("order.txt");
	if (file.is_open()) {
		while (file >> Order.product >> Order.mark >> Order.surname >> Order.name >> Order.secondName >> Order.phoneNumber >> Order.cost >> Order.dayOfRecept >> Order.monthOfRecept >>
			Order.yearOfRecept >> Order.dayOfIssue >> Order.monthOfIssue >> Order.yearOfIssue >> Order.status) {
			Ord.push_back(Order);
		}
		file.close();
	}
	else {
		writeThatFileCannotBeOpened();
	}
}
void writeThatFileCannotBeOpened() {
	cout << "File can't be opened!" << endl;
}
void checkIfFilesExist() {
	ifstream file("list.txt");
	if (!file.is_open()) {
		Accounts account;
		createAccountsFile(account);
		file.close();
	}
	ifstream file1("order.txt");
	if (!file1.is_open()) {
		createOrdersFile();
		file1.close();
	}
}
void printStructWithOrders(orders Orders, int i) {
	if (Orders.product.length() >= 15) {
		Orders.product = Orders.product.substr(15);
	}
	if (Orders.mark.length() >= 10) {
		Orders.mark = Orders.mark.substr(10);
	}
	if (Orders.name.length() >= 10) {
		Orders.name = Orders.name.substr(10);
	}
	if (Orders.surname.length() >= 15) {
		Orders.surname = Orders.surname.substr(15);
	}
	cout << setw(2) << i << " " << setw(15) << Orders.product << " " << setw(10) << Orders.mark << " " << setw(15) << Orders.surname << " " << setw(10) << Orders.name << " "
		<< setw(10) << Orders.secondName << " " << setw(13) << Orders.phoneNumber << " " << setw(4) << Orders.cost << " " << setw(2) << Orders.dayOfRecept << "." <<
		setw(2) << Orders.monthOfRecept << "." << setw(4) << Orders.yearOfRecept << " " << setw(2) <<
		Orders.dayOfIssue << "." << setw(2) << Orders.monthOfIssue << "." << setw(4) << Orders.yearOfIssue << " " << setw(1) << Orders.status << endl;
}
void enterCurrentDate(int &a, int &b, int &c) {
	cout << "1 - enter date by self" << endl;
	cout << "2 - get date from computer" << endl;
	int choise;
	inputNumber(choise);
	switch (choise)
	{
	case 1:
		cout << "Enter the last day" << endl;
		inputDate(a, "day");
		cout << "Enter the month" << endl;
		inputDate(b, "month");
		cout << "Enter the year" << endl;
		inputDate(c, "year");
		break;
	case 2:
		SYSTEMTIME st;
		GetSystemTime(&st);
		a = st.wDay;
		b = st.wMonth;
		c = st.wYear;
		cout << "Current day: " << a << "." << b << "." << c << endl;
	default:
		cout << "Choose 1 or 2" << endl;
		break;
	}
}
void enterOrdersVectorIndex(int &a, vector<orders> Ord) {
	while (true) {
		inputNumber(a);
		if (a >= 0 && a < Ord.size()) {
			break;
		}
		cout << "Index can't be less than 0 or bigger then " << Ord.size() << endl;
	}
}
void enterAccountsVectorIndex(int &a, vector<Accounts> accs) {
	while (true) {
		inputNumber(a);
		if (a >= 0 && a < accs.size()) {
			break;
		}
		cout << "Index can't be less than 0 or bigger then " << accs.size() << endl;
	}
}
void createPassword(string &password) {
	bool containNumbers = false;
	bool containCapitalLetters = false;
	bool containLowercaseLetters = false;
	while (true) {
		cout << "Your password should contain numbers, capital letters & lowercase letters" << endl;
		cout << "Enter the password" << endl;
		cin >> password;
		for (unsigned int i = 0; i < password.length(); i++) {
			if (password[i] >= '0' && password[i] <= '9') {
				containNumbers = true;
			}
			else if (password[i] >= 'a' && password[i] <= 'z') {
				containLowercaseLetters = true;
			}
			else if (password[i] >= 'A' && password[i] <= 'Z') {
				containCapitalLetters = true;
			}
		}
		if (containCapitalLetters && containNumbers && containLowercaseLetters) {
			break;
		}
		cout << "Please, try again" << endl;
	}
}
void exitFromTheProgram() {
	cout << "Bye-bye" << endl;
	Sleep(1000);
	exit(1);
}