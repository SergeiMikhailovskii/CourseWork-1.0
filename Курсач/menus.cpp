#include "Header.h"
void startingMenu(int &role) {
	cout << "1 - registration" << endl;
	cout << "2 - login" << endl;
	cout << "3 - exit" << endl;
	int choise = 0;
	checkIfFilesExist();
	while (true) {
		inputNumber(choise);
		switch (choise)
		{
		case 1:
			registrateUser(role);
			break;
		case 2: loginUser(role);
			break;
		case 3: exitFromTheProgram();
			break;
		default:
			cout << "Choose 1 or 2!" << endl;
			break;
		}
	}
}
int adminMenu() {
	system("cls");
	cout << endl;
	cout << "Choose the category you want to work with:" << endl;
	cout << endl;
	cout << "1 - Accounts" << endl;
	cout << "2 - Data" << endl;
	cout << "3 - Back" << endl;
	int choise = 0;
	inputNumber(choise);
	cout << endl;
	return choise;
}
int accountsMenu() {
	system("cls");
	cout << endl;
	cout << "Choose the action" << endl;
	cout << "1 - create users file" << endl;
	cout << "2 - show users" << endl;
	cout << "3 - add user" << endl;
	cout << "4 - edit user's information" << endl;
	cout << "5 - delete user" << endl;
	cout << "6 - back" << endl;
	int choise;
	inputNumber(choise);
	cout << endl;
	return choise;
}
int dataMenu() {
	system("cls");
	cout << "1 - Editing mode" << endl;
	cout << "2 - Treatment mode" << endl;
	cout << "3 - Back" << endl;
	int choise;
	inputNumber(choise);
	return choise;
}
int editingMenu() {
	system("cls");
	cout << "Choose the action:" << endl;
	cout << "1 - Create file" << endl;
	cout << "2 - Show" << endl;
	cout << "3 - Add" << endl;
	cout << "4 - Edit" << endl;
	cout << "5 - Delete" << endl;
	cout << "6 - Back" << endl;
	int choise;
	inputNumber(choise);
	return choise;
}
int treatmentMenu() {
	system("cls");
	cout << endl;
	cout << "1 - Sort orders" << endl;
	cout << "2 - Show overdued orders" << endl;
	cout << "3 - Show total revenue" << endl;
	cout << "4 - Back" << endl;
	int choise;
	cin >> choise;
	cout << endl;
	return choise;
}
int userMenu() {
	system("cls");
	cout << endl;
	cout << "1 - ind. task" << endl;
	cout << "2 - search" << endl;
	cout << "3 - sort" << endl;
	cout << "4 - back" << endl;
	int choise;
	inputNumber(choise);
	cout << endl;
	return choise;
}
int sortingMenu() {
	system("cls");
	cout << endl;
	cout << "Enter the way how to sort data" << endl;
	cout << "1 - by mark of product" << endl;
	cout << "2 - by surname" << endl;
	cout << "3 - by cost" << endl;
	cout << "4 - back" << endl;
	int choise;
	cout << endl;
	inputNumber(choise);
	return choise;
}
int searchingMenu() {
	system("cls");
	cout << endl;
	cout << "Choose the point you want to search by:" << endl;
	cout << "1 - surname" << endl;
	cout << "2 - name" << endl;
	cout << "3 - by phone number" << endl;
	cout << "4 - back" << endl;
	int choise;
	inputNumber(choise);
	return choise;
}
int mobileOperatorsListMenu() {
	cout << "Enter your operator" << endl;
	cout << "1 - MTC (033)" << endl;
	cout << "2 - Velcom/MTC (029)" << endl;
	cout << "3 - Life (025)" << endl;
	int choise;
	inputNumber(choise);
	return choise;
}
int editingActionsWithOrdersMenu() {
	cout << "Choose the field you want to edit:" << endl;
	cout << "1 - product" << endl;
	cout << "2 - mark" << endl;
	cout << "3 - surname" << endl;
	cout << "4 - name" << endl;
	cout << "5 - last name" << endl;
	cout << "6 - phone number" << endl;
	cout << "7 - cost" << endl;
	cout << "8 - day of recept" << endl;
	cout << "9 - month of recept" << endl;
	cout << "10 - year of recept" << endl;
	cout << "11 - day of issue" << endl;
	cout << "12 - month of issue" << endl;
	cout << "13 - year of issue" << endl;
	cout << "14 - status" << endl;
	cout << "15 - back" << endl;
	int choise;
	inputNumber(choise);
	return choise;
}