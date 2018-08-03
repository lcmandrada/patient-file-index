// PatientFile.h
#include <fstream>
#include <string>

#include "LinkedListType.h"

using namespace std;

class PatientFile
{
public:
	void color(int code);
	void load();
	void center(int x, int y);
	void noSpace(char user[50]);
	void asterisk(char actualPass[50]);
	void single(char answer[30]);
	void store(string location, char user[50], char pass[50]);
	void preLogin();
	void login();
	void menu();
	void display();
	int searchProtocol(string surname, string name, string middle);
	void search();
	void addProtocol(nodeType<string> *&last, string data);
	void sortProtocol(int position, nodeType<string> *&first, nodeType<string> *&last);
	void add();
	void delProtocol(nodeType<string> *&first, nodeType<string> *&last, int position);
	void del();
	void save();
	void buildRe();
	void printProtocol();
	void print();

	bool close = true;
private:
	int x, attempt;
	char tryAgain[30], choice[30], password[50], username[50], usernameCheck[50];
	char user[50], pass[50], passCheck[50];
	char USER[50], PASS[50];
	string folder;
};