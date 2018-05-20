#pragma once
#define NOMINMAX
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
struct Accounts {
	string login;
	string password;
	int role;
};
struct orders {
	string product;
	string mark;
	string surname;
	string name;
	string secondName;
	string phoneNumber;
	int cost;
	int dayOfRecept;
	int monthOfRecept;
	int yearOfRecept;
	int dayOfIssue;
	int monthOfIssue;
	int yearOfIssue;
	int status;
};
void inputNumber(int &number);
void startingMenu(int &role);
void registrateUser(int &role);
void loginUser(int &role);
void adminMode();
void userMode();
void transferOrdersToFile(vector<orders> Ord);
void fullfillOrdersVector(vector<orders> &Ord);
void showOverduedOrders(orders Order);
void workWithAccounts();
void createAccountsFile(Accounts accs);
void showAccounts(Accounts accs);
void addAccount(Accounts accs);
void editAccount(Accounts accs);
void deleteAccount(Accounts accs);
void workWithData();
void editingMode();
void createOrdersFile();
void showOrdersFile(orders Orders);
void addOrder(orders Orders);
void editOrder(orders Order, vector <orders> Ord);
void deleteOrder(orders Order, vector <orders> Ord);
void sortByDate(orders Order);
void treatmentMode();
void sortingMode();
void searchingMode();
void showTotalRevenue(orders Order);
void sortOrders(const string a);
void searchData(const string a);
void showOrdersVector(vector<orders> Ord);
void writeThatFileCannotBeOpened();
void checkIfFilesExist();
void inputCost(int &a);
void printStructWithOrders(orders Orders, int i);
void enterCurrentDate(int &a, int &b, int &c);
void enterOrdersVectorIndex(int &a, vector<orders> Ord);
void enterAccountsVectorIndex(int &a, vector<Accounts> accs);
void inputPhoneNumber(string &number);
void inputPassword(string &password);
void createPassword(string &password);
void exitFromTheProgram();
void inputDate(int &number, const string parameter);
void inputRoleOrStatusValue(int &a);
void inputReceptAndIssueDates(int &rDay, int &rMonth, int &rYear, int &iDay, int &iMonth, int &iYear);
int mobileOperatorsListMenu();
int editingActionsWithOrdersMenu();
int sortingMenu();
int adminMenu();
int userMenu();
int accountsMenu();
int dataMenu();
int editingMenu();
int treatmentMenu();
int searchingMenu();
bool isLoginUnique(string &login);
bool isThisNumberReservedByAdminAccount(int x);
bool areRevenueDatesRight(int &fDay, int &fMonth, int &fYear, int &lDay, int &lMonth, int &lYear, long int &fDate, long int &lDate);