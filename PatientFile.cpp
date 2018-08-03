// PatientFile.cpp
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <string>

#include "PatientFile.h"
#include "LinkedListType.h"
#include "UnOrderedLinkedList.h"

using namespace std;

// global declaration
bool found, searchfound, executed = false, ins1, ins2, del1, del2, delLast;
nodeType<string> *surnameA, *nameA, *middleA, *ageA, *genderA, *statusA, *schedA;
nodeType<string> *surnameB, *nameB, *middleB, *ageB, *genderB, *statusB, *schedB;
nodeType<string> *surnameX, *nameX, *middleX, *ageX, *genderX, *statusX, *schedX;
nodeType<string> *reminderA, *reminderB, *reminderX;

// background and foreground custom color
void PatientFile::color(int code)
{
	HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(text, code);
}

// loading animation
void PatientFile::load()
{
	int z = 50;
	cout << '-' << flush;
	while (z != 0)
	{
		z--;
		Sleep(1);
		cout << "\b\\" << flush;
		Sleep(1);
		cout << "\bI" << flush;
		Sleep(1);
		cout << "\b/" << flush;
		Sleep(1);
		cout << "\b-" << flush;
	}

	cout << "\b " << flush;
}

// custom position
void PatientFile::center(int x, int y)
{
	// initialize screen
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

	// initialize x and y coordinates
	COORD cursor;
	cursor.X = x;
	cursor.Y = y;

	// set cursor position
	SetConsoleCursorPosition(screen, cursor);
}

// single character input
void PatientFile::single(char answer[30])
{
	x = 0;

	while (1)
	{
		answer[x] = _getch();

		if (answer[x] == 13)	// terminate character string when Enter key is pressed
		{
			answer[x] = '\0'; // insert terminating character
			break;
		}
		else if (answer[x] == 8 && x >= 0) // erase previously entered character when Backspace key is pressed
		{
			if (x > 0)
			{
				cout << "\b \b"; // erase previous character
				x--;
			}
			else if (x == 0)
			{
				// display nothing
			}
		}
		else if (answer[x] == 32) // display nothing when Space key is pressed
		{
			// display nothing
		}
		else if (x < 1)// display the characters
		{
			cout << answer[x];
			x++;
		}
	}

	x = 0;
}

// no space input
void PatientFile::noSpace(char user[50])
{
START:
	x = 0;

	// loop for storing the input and ignoring the space
	while (1)
	{
		user[x] = _getch(); // store character without echo

		if ((user[x] >= 0 && user[x] <= 7) || (user[x] >= 9 && user[x] <= 12) || (user[x] >= 14 && user[x] <= 45) || user[x] == 47 ||
			(user[x] >= 58 && user[x] <= 63) || (user[x] >= 91 && user[x] <= 94) || user[x] == 96 || user[x] >= 123)
		{
			// display nothing
		}
		else
		{
			if (user[x] == 13)	// terminate character string when Enter key is pressed
			{
				user[x] = '\0'; // insert terminating character
				if (user[0] == '\0')
					goto START;
				break;
			}
			else if (user[x] == 8 && x >= 0) // erase previously entered character when Backspace key is pressed
			{
				if (x > 0)
				{
					cout << "\b \b"; // erase previous character
					x--;
				}
				else if (x == 0)
				{
					// display nothing
				}
			}
			else if (x < 50) // display the characters
			{
				cout << user[x];
				x++;
			}
		}
	}

	x = 0;
}

// password input asterisk display
void PatientFile::asterisk(char password[50])
{
START:
	x = 0;

	// loop for storing password and displaying asterisk
	while (1)
	{
		password[x] = _getch(); // store character without echo

		if (password[x] == 13)	// terminate character string when Enter key is pressed
		{
			password[x] = '\0'; // insert terminating character
			if (password[0] == '\0')
				goto START;
			break;
		}
		else if (password[x] == 8 && x >= 0) // erase previously entered character when Backspace key is pressed
		{
			if (x > 0)
			{
				cout << "\b \b"; // erase previous character
				x--;
			}
			else if (x == 0)
			{
				// display nothing
			}
		}
		else if (password[x] == 32) // display nothing when Space key is pressed
		{
			// display nothing
		}
		else if (x < 50)// display asterisk
		{
			cout << "*";
			x++;
		}
	}

	x = 0;
}

// store main account
void PatientFile::store(string location, char user[50], char pass[50])
{
	// declare variables
	x = 0;

	ofstream file;

	// print main account information to main.txt
	file.open(location);
	file << user << endl << pass;

	file.close();
}

// preLogin processes
void PatientFile::preLogin()
{
START:
	// prompt user for username
	system("color F0");
	center(30, 10);
	color(177);
	cout << "Enter Username\n";
	center(30, 11);
	color(191);
	noSpace(username);

	system("cls");
	system("color F0");

	center(30, 10);
	color(177);
	cout << "Verify Username\n";
	center(30, 11);
	color(191);
	noSpace(usernameCheck);

	system("cls");
	system("color F0");

	// check if username input and program username matched
	if (!strcmp(username, usernameCheck))
	{
		// initialize directory and file location
		folder = "C:/PatientFileIndex/central.txt";

		// read main account
		ifstream mainInput;
		mainInput.open(folder);

		// check main.txt availability
		if (mainInput.is_open())
		{
			// if main.txt is available
			// read main account information from main.txt
			center(35, 10);
			cout << "Loading ";
			load();
			mainInput >> user;
			mainInput >> pass;

			mainInput.close();

			// proceed to login
			login();
		}
		else
		{
			// if main.txt is not available
			// prompt user for username and password that would access the program
			mainInput.close();
			color(177);
			cout << "Patient File Index\n";
			color(240);
			Sleep(300);
			cout << "Please enter your desired username and password.\n";
			Sleep(300);
			cout << "It will serve as your account to access the program.\n";
			Sleep(300);
			cout << "Save a copy of the account somewhere safe." << endl << endl;
			Sleep(300);

		PASSAGAIN:
			color(177);
			cout << "Username: ";
			color(191);
			cout << username << endl;
			Sleep(300);
			color(177);
			cout << "Password: ";
			color(191);
			asterisk(pass);
			cout << endl;
			color(177);
			cout << "Re-enter Password: ";
			color(191);
			asterisk(passCheck);
			color(240);

			// compare password and re-entered password
			if (!strcmp(pass, passCheck))
			{
				// if pass and passCheck matched
				// create directory for main.txt
				CreateDirectory("C:/PatientFileIndex/", NULL);

				cout << "\n\nSaving ";
				load();
				cout << endl;

				// store account to main.txt
				store(folder, username, pass);

				cout << "Account created successfully.\n\nRestarting\n";
				Sleep(3000);

				// call preLogin function to start over
				system("cls");
				preLogin();
			}
			else
			{
				// if pass and passCheck did not match
				// call preLogin function to start over
				cout << endl;
			AGAIN:
				color(177);
				cout << "\nPassword did not match. \nTry Again?(Y/N): ";
				color(191);
				cin.sync();
				single(tryAgain);
				cout << endl;
				color(240);

				// options to Try Again
				switch (tryAgain[0])
				{
				case 'Y':
				case 'y':
					cout << endl;
					goto PASSAGAIN;
					break;
				case 'N':
				case 'n':
					cout << "\nRestarting\n";
					Sleep(1500);
					system("cls");
					preLogin();
					break;
				default:
					cout << "Invalid\n";
					goto AGAIN;
				}
			}
		}
	}
	else
	{
		// if username did not match
		// start over
		system("cls");
		goto START;
	}
}

// login processes
void PatientFile::login()
{
	attempt = 1;
START:
	system("color f0");
	// check if attempt is greater than 1
	if (attempt > 1)
	{
		// if is greater than 1
		// display attempt
		center(30, 9);
		cout << "Attempt: " << attempt << "\n";
	}

	// prompt user for username and password
	strcpy_s(USER, username);
	center(30, 10);
	color(177);
	cout << "Enter Your Password";
	center(30, 11);
	color(191);
	asterisk(PASS);

AGAIN:
	color(240);
	// check if USER and PASS match the database
	if (!strcmp(user, USER) && !strcmp(pass, PASS))
	{
		// if it matched
		// proceed to program
		system("cls");
		system("color f0");
		center(30, 10);
		color(177);
		cout << "logging you in,";
		center(30, 11);
		color(191);
		cout << USER;

		// check for existing lists
		// then store data to corresponding lists
		ifstream check;
		check.open("C:/PatientFileIndex/surname.txt");

		if (check.is_open())
		{
			string data;
			ifstream name, middle, age, gender, status, sched;

			found = true;

			UnorderedLinkedList<string> surnameList;
			while (getline(check, data))
			{
				surnameList.InsertLast(data, surnameA, surnameB);
			}
			check.close();

			name.open("C:/PatientFileIndex/name.txt");
			UnorderedLinkedList<string> nameList;
			while (getline(name, data))
			{
				nameList.InsertLast(data, nameA, nameB);
			}
			name.close();

			middle.open("C:/PatientFileIndex/middle.txt");
			UnorderedLinkedList<string> middleList;
			while (getline(middle, data))
			{
				middleList.InsertLast(data, middleA, middleB);
			}
			middle.close();

			age.open("C:/PatientFileIndex/age.txt");
			UnorderedLinkedList<string> ageList;
			while (getline(age, data))
			{
				ageList.InsertLast(data, ageA, ageB);
			}
			age.close();

			gender.open("C:/PatientFileIndex/gender.txt");
			UnorderedLinkedList<string> genderList;
			while (getline(gender, data))
			{
				genderList.InsertLast(data, genderA, genderB);
			}
			gender.close();

			status.open("C:/PatientFileIndex/status.txt");
			UnorderedLinkedList<string> statusList;
			while (getline(status, data))
			{
				statusList.InsertLast(data, statusA, statusB);
			}
			status.close();

			sched.open("C:/PatientFileIndex/sched.txt");
			UnorderedLinkedList<string> schedList;
			while (getline(sched, data))
			{
				schedList.InsertLast(data, schedA, schedB);
			}
			sched.close();

			if (surnameA != NULL)
			{
				buildRe();
				UnorderedLinkedList<string> resort;
				resort.reSort(reminderA, reminderB);
			}
			else
				found = false;
		 
		}
		else
		{
			found = false;
			surnameA = nameA = middleA = ageA = genderA = statusA = schedA = NULL;
			surnameB = nameB = middleB = ageB = genderB = statusB = schedB = NULL;
		}

		check.close();

		Sleep(1500);
		system("cls");
	}
	else
	{
		// if it does not match
		// prompt user to try again
		center(30, 13);
		cout << "Access Denied";

		// check if attempt is still tolerable
		if (attempt < 5)
		{
			// if still is
			// prompt user to try again
			cin.sync();
			center(30, 14);
			cout << "\t\t\t\t\t";
			center(30, 14);
			color(177);
			cout << "Try Again?(Y/N): ";
			color(191);
			single(tryAgain);
			cout << endl;
			color(240);
		}
		else
		{
			// if is not
			// exit
			center(30, 13);
			cout << "Attempt Exceeded";
			center(30, 14);
			cout << "BYE";
			Sleep(1500);
			exit(0);
		}

		// options to try again
		switch (tryAgain[0])
		{
		case 'Y':
		case 'y':
			attempt++;
			system("cls");
			goto START;
			break;
		case 'N':
		case 'n':
			center(30, 15);
			cout << "BYE";
			Sleep(1500);
			exit(0);
			break;
		default:
			center(30, 14);
			cout << "\t\t\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t\n";
			center(30, 15);
			cout << "Invalid";
			goto AGAIN;
		}
	}
}

// menu
void PatientFile::menu()
{
	// diplay options
	system("color f0");
	color(15);
	cout << "HOME\n\n";
	Sleep(100);
	color(177);
	cout << "What do you like to do?\n"; Sleep(100);
	color(240);
	cout << "   (A) Show File\n"; Sleep(100);
	cout << "   (B) Search Record\n"; Sleep(100);
	cout << "   (C) Add or Edit Record\n"; Sleep(100);
	cout << "   (D) Delete Record\n"; Sleep(100);
	cout << "   (E) Exit\n"; Sleep(100);
	cout << "   (F) Print\n\n"; Sleep(100);
	color(177);
	cout << "Reminders:" << endl;
	color(240);

	if (reminderA != NULL)
	{
		reminderX = reminderA;
		while (reminderX != NULL)
		{
			cout << reminderX->info << endl;
			reminderX = reminderX->link;
		}
	}
	else
		cout << "It's lonely here." << endl;

AGAIN:
	// prompt user to select action
	cin.sync();
	color(177);
	cout << "\nOption: ";
	color(191);
	single(choice); cout << endl;
	color(240);

	switch (choice[0])
	{
	case 'A':
	case 'a':
		system("cls");
		display();
		break;
	case 'B':
	case 'b':
		system("cls");
		search();
		break;
	case 'C':
	case 'c':
		system("cls");
		add();
		break;
	case 'D':
	case 'd':
		system("cls");
		del();
		break;
	case 'E':
	case 'e':
		cout << "\nBYE\n";
		Sleep(1500);
		close = false;
		break;
	case 'F':
	case 'f':
		system("cls");
		print();
		break;
	default:
		cout << "Invalid\n";
		goto AGAIN;
	}
}

// display menu
void PatientFile::display()
{
	system("color f0");
	color(15);

	cout << "HOME // SHOW FILE\n\n";
	Sleep(100);

	color(240);
	cout << "Retrieving File ";
	load();
	system("cls");

	color(15);
	cout << "HOME // SHOW FILE\n\n";
	Sleep(100);

	// display records
	color(177);

	surnameX = surnameA;
	nameX = nameA;
	middleX = middleA;
	ageX = ageA;
	genderX = genderA;
	statusX = statusA;
	schedX = schedA;

	if (found)
	{
		while (surnameX != NULL)
		{
			Sleep(100);
			cout << "Name: " << surnameX->info << ", " << nameX->info << " " << middleX->info << endl;
			surnameX = surnameX->link;
			nameX = nameX->link;
			middleX = middleX->link;

			Sleep(100);
			cout << "Age: " << ageX->info << endl;
			ageX = ageX->link;

			Sleep(100);
			cout << "Gender: " << genderX->info << endl;
			genderX = genderX->link;

			Sleep(100);
			cout << "Status: " << statusX->info << endl;
			statusX = statusX->link;

			Sleep(100);
			cout << "Schedule: " << schedX->info << endl << endl;
			schedX = schedX->link;
		}

		cout << "File retrieval was successful.\n";
	} else
		cout << "No existing records have been found.\n";

	color(240);

	// prompt user to select next action
	Sleep(100);
	color (177);
	cout << "What do you want to do?\n";  Sleep(100);
	color (240);
	cout << "   (B) Back to Main Menu\n";  Sleep(100);
	cout << "   (E) Exit\n";  Sleep(100);
	color(240);

AGAIN:
	cin.sync();
	color(177);
	cout << "\nOption: ";
	color(191);
	single(choice); cout << endl;
	color(240);

	switch (choice[0])
	{
	case 'B':
	case 'b':
		system("cls");
		menu();
		break;
	case 'E':
	case 'e':
		cout << "\nBYE\n";
		Sleep(1500);
		close = false;
		break;
	default:
		cout << "Invalid\n";
		goto AGAIN;
	}
}

// custom linked list sequential search
int PatientFile::searchProtocol(string surname, string name, string middle)
{
	int location = 0;

	surnameX = surnameA;
	nameX = nameA;
	middleX = middleA;
	ageX = ageA;
	genderX = genderA;
	statusX = statusA;
	schedX = schedA;

	searchfound = false;

	while (surnameX != NULL)
	{
		location++;

		if (surnameX->info == surname && nameX->info == name && middleX->info == middle)
		{
			searchfound = true;
			break;
		}

		surnameX = surnameX->link;
		nameX = nameX->link;
		middleX = middleX->link;
		ageX = ageX->link;
		genderX = genderX->link;
		statusX = statusX->link;
		schedX = schedX->link;
	}

	return location - 1;
}

// search menu
void PatientFile::search()
{
	string surname, name, middle;
	int position;

	system("color f0");
	color(15);

	cout << "HOME // SEARCH RECORD\n\n";
	Sleep(100);

	if (found || executed)
	{
		// prompt user for patient
		color(177);
		cout << "Surname: ";
		color(191);
		getline(cin, surname);
		color(177);
		cout << "Given Name: ";
		color(191);
		getline(cin, name);
		color(177);
		cout << "Middle Initial: ";
		color(191);
		getline(cin, middle);
		color(240);

		color(240);
		cout << "\nRetrieving File ";
		load();
		system("cls");

		color(15);
		cout << "HOME // SEARCH RECORD\n\n";
		Sleep(100);

		position = searchProtocol(surname, name, middle);

		color(177);
		if (searchfound)
		{
			Sleep(100);
			cout << "Name: " << surnameX->info << ", " << nameX->info << " " << middleX->info << endl;

			Sleep(100);
			cout << "Age: " << ageX->info << endl;

			Sleep(100);
			cout << "Gender: " << genderX->info << endl;

			Sleep(100);
			cout << "Status: " << statusX->info << endl;

			Sleep(100);
			cout << "Schedule: " << schedX->info << endl;

			color(177);
			Sleep(100);
			cout << "\nFile retrieval was successful.\n";
			searchfound = false;
		}
		else
		{
			color(177);
			cout << "Record was not found.\n";
		}
	} 
	else
	{
		color(177);
		cout << "No existing records have been found.\n";
	}

	// prompt user to select next action
	Sleep(100);
	color(177);
	cout << "What do you want to do?\n";  Sleep(100);
	color(240);
	cout << "   (S) Search Patient\n";  Sleep(100);
	cout << "   (B) Back to Main Menu\n";  Sleep(100);
	cout << "   (E) Exit\n";  Sleep(100);
	color(240);

AGAIN:
	cin.sync();
	color(177);
	cout << "\nOption: ";
	color(191);
	single(choice); cout << endl;
	color(240);

	switch (choice[0])
	{
	case 'S':
	case 's':
		system("cls");
		search();
		break;
	case 'B':
	case 'b':
		system("cls");
		menu();
		break;
	case 'E':
	case 'e':
		cout << "\nBYE\n";
		Sleep(1500);
		close = false;
		break;
	default:
		cout << "Invalid\n";
		goto AGAIN;
	}
}

// add new records via linked list
void PatientFile::addProtocol(nodeType<string> *&last, string data)
{
	nodeType<string> *newNode;
	newNode = new nodeType<string>;

	newNode->info = data;
	newNode->link = NULL;

	if (found || executed)
	{
		last->link = newNode;
		last = newNode;
	}
	else
		last = newNode;
}

// automatically sort added records via custom linked list insertion sort
void PatientFile::sortProtocol(int position, nodeType<string> *&first, nodeType<string> *&last)
{
	nodeType<string> *trailCurrent, *current, *LIO, *fooo;

	LIO = first;
	fooo = LIO->link;

	while (fooo->link != NULL)
	{
		LIO = LIO->link;
		fooo = fooo->link;
	}

	if (ins1)
	{
		LIO->link = fooo->link;
		fooo->link = first;
		first = fooo;
	}
	else
	{
		trailCurrent = first;
		current = trailCurrent->link;

		while (position--)
		{
			trailCurrent = trailCurrent->link;
			current = current->link;
		}

		if (ins2)
		{
			LIO->link = fooo->link;
			fooo->link = current;
			trailCurrent->link = fooo;
		}
	}

	while (last->link != NULL)
	{
		last = last->link;
	}
}

// add menu
void PatientFile::add()
{
	string surname, name, middle, age, gender, status, sched;
	int position;
	ins1 = ins2 = false;

	system("color f0");
	color(15);

	cout << "HOME // ADD RECORD\n\n";
	Sleep(100);

	color(177);
	cout << "Enter Information" << endl;
	cout << "Surname: ";
	color(191);
	getline(cin, surname);
	color(177);
	cout << "Given Name: ";
	color(191);
	getline(cin, name);
	color(177);
	cout << "Middle Initial: ";
	color(191);
	getline(cin, middle);
	color(177);
	cout << "Age: ";
	color(191);
	getline(cin, age);
	color(177);
	cout << "Gender: ";
	color(191);
	getline(cin, gender);
	color(177);
	cout << "Status: ";
	color(191);
	getline(cin, status);
	color(177);
	cout << "Schedule (YY/MM/DD 2400): ";
	color(191);
	getline(cin, sched);
	
	if (found)
	position = searchProtocol(surname, name, middle);

	color(177);
	UnorderedLinkedList<string> resort;

	if (searchfound)
	{
		cout << "\nPatient has an existing record.\n";
		color(177);
		cout << "Overwrite record? (Y/N): ";
		color(191);
		cin.sync();
		single(choice); 
		cout << endl;
		color(240);

		switch (choice[0])
		{
		case 'Y':
		case 'y':
			ageX = ageA;
			genderX = genderA;
			statusX = statusA;
			schedX = schedA;

			while (position--)
			{
				ageX = ageX->link;
				genderX = genderX->link;
				statusX = statusX->link;
				schedX = schedX->link;
			}

			ageX->info = age;
			genderX->info = gender;
			statusX->info = status;
			schedX->info = sched;

			color(240);
			cout << "\nSaving File ";
			load();
			cout << endl << endl;

			color(177);
			cout << "The record was overwritten successfully.\n";
			buildRe();
			resort.reSort(reminderA, reminderB);
			searchfound = false;
			break;
		case 'N':
		case 'n':
			break;
		default:
			cout << "Invalid\n";
			goto AGAIN;
		}
	}
	else
	{
		addProtocol(surnameB, surname);
		addProtocol(nameB, name);
		addProtocol(middleB, middle);
		addProtocol(ageB, age);
		addProtocol(genderB, gender);
		addProtocol(statusB, status);
		addProtocol(schedB, sched);

		if (found || executed)
		{
			UnorderedLinkedList<string> sort;
			position = sort.LinkedInsertionSort(surnameA, surnameB, nameA, ins1, ins2);

			sortProtocol(position, nameA, nameB);
			sortProtocol(position, middleA, middleB);
			sortProtocol(position, ageA, ageB);
			sortProtocol(position, genderA, genderB);
			sortProtocol(position, statusA, statusB);
			sortProtocol(position, schedA, schedB);
		}
		else
		{
			surnameA = surnameB;
			nameA = nameB;
			middleA = middleB;
			ageA = ageB;
			genderA = genderB;
			statusA = statusB;
			schedA = schedB;

			executed = true;
			found = true;
		}

		color(240);
		cout << "\nSaving File ";
		load();
		cout << endl << endl;

		color(177);
		cout << "Record was saved successfully.\n";

		buildRe();
		UnorderedLinkedList<string> resort;
		resort.reSort(reminderA, reminderB);
	}

	// prompt user to select next action
	Sleep(100);
	color(177);
	cout << "What do you want to do?\n";  Sleep(100);
	color(240);
	cout << "   (A) Add Patient\n";  Sleep(100);
	cout << "   (B) Back to Main Menu\n";  Sleep(100);
	cout << "   (E) Exit\n";  Sleep(100);
	color(240);

AGAIN:
	cin.sync();
	color(177);
	cout << "\nOption: ";
	color(191);
	single(choice); cout << endl;
	color(240);

	switch (choice[0])
	{
	case 'A':
	case 'a':
		system("cls");
		add();
		break;
	case 'B':
	case 'b':
		system("cls");
		menu();
		break;
	case 'E':
	case 'e':
		cout << "\nBYE\n";
		Sleep(1500);
		close = false;
		break;
	default:
		cout << "Invalid\n";
		goto AGAIN;
	}
}

// delete record via linked list
void PatientFile::delProtocol(nodeType<string> *&first, nodeType<string> *&last, int position)
{
	nodeType<string> *trailCurrent, *current;

	if (del1 != true && del2 != true && delLast == true)
	{	}
		// cout << "Cannot delete from an empty list." << endl;
	else
	{
		if (del1) //Case 2 
		{
			current = first;
			first = first->link;

			if (first == NULL)    //the list has only one node
			{
				last = NULL;
				found = executed = false;
			}

			delete current;
		}
		else //search the list for the node with the given info
		{
			trailCurrent = first;  //set trailCurrent to point
									//to the first node
			current = first->link; //set current to point to 
			//the second node

			while (position--)
			{
				trailCurrent = current;
				current = current->link;
			}//end while

			if (del2) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;

				if (delLast)   //node to be deleted was the last node
				{
					last = trailCurrent; //update the value 
					//of last
				}

				delete current;  //delete the node from the list
			}
			else
				cout << "The item to be deleted is not in "
				<< "the list." << endl;
		}//end else
	}//end else
}

// delete menu
void PatientFile::del()
{
	string surname, name, middle;
	int position;

	system("color f0");
	color(15);

	cout << "HOME // DELETE RECORD\n\n";
	Sleep(100);

	if (found || executed)
	{
		// prompt user for patient
		color(177);
		cout << "Surname: ";
		color(191);
		getline(cin, surname);
		color(177);
		cout << "Given Name: ";
		color(191);
		getline(cin, name);
		color(177);
		cout << "Middle Initial: ";
		color(191);
		getline(cin, middle);
		color(240);

		searchProtocol(surname, name, middle);

		color(177);
		if (searchfound)
		{
			UnorderedLinkedList<string> del;
			UnorderedLinkedList<string> resort;

		CONFIRM:
			cin.sync();
			color(177);
			cout << "\nDelete " << surnameX->info << ", " << nameX->info << " " << middleX->info << "? (Y/N): ";
			color(191);
			single(choice); cout << endl;
			color(240);

			switch (choice[0])
			{
			case 'Y':
			case 'y':
				position = del.DeleteNode(surname, surnameA, surnameB, del1, del2, delLast);
				delProtocol(nameA, nameB, position);
				delProtocol(middleA, middleB, position);
				delProtocol(ageA, ageB, position);
				delProtocol(genderA, genderB, position);
				delProtocol(statusA, statusB, position);
				delProtocol(schedA, schedB, position);
				if (surnameA == NULL)
				{
					executed = false;
				}

				if (surnameA != NULL)
				{
					buildRe();
					resort.reSort(reminderA, reminderB);
				} else
					reminderA = reminderB = NULL;

				color(240);
				cout << "\nDeleting File ";
				load();
				cout << endl << endl;

				color(177);
				cout << "Deletion was successful.\n";
				break;
			case 'N':
			case 'n':
				break;
			default:
				cout << "Invalid\n";
				goto CONFIRM;
			}

			searchfound = false;
		}
		else
		{
			color(177);
			cout << "\nRecord was not found.\n";
		}
	}
	else
	 {
		 color(177);
		 cout << "No existing records have been found.\n";
	 }
	
	
	// prompt user to select next action
	Sleep(100);
	color(177);
	cout << "What do you want to do?\n";  Sleep(100);
	color(240);
	cout << "   (D) Delete Record\n";  Sleep(100);
	cout << "   (B) Back to Main Menu\n";  Sleep(100);
	cout << "   (E) Exit\n";  Sleep(100);
	color(240);

AGAIN:
	cin.sync();
	color(177);
	cout << "\nOption: ";
	color(191);
	single(choice); cout << endl;
	color(240);

	switch (choice[0])
	{
	case 'D':
	case 'd':
		system("cls");
		del();
		break;
	case 'B':
	case 'b':
		system("cls");
		menu();
		break;
	case 'E':
	case 'e':
		cout << "\nBYE\n";
		Sleep(1500);
		close = false;
		break;
	default:
		cout << "Invalid\n";
		goto AGAIN;
	}
}

// save files to local storage
void PatientFile::save()
{
	ofstream saveFile;

	if (surnameA != NULL)
	{
		saveFile.open("C:/PatientFileIndex/surname.txt");
		surnameX = surnameA;
		while (surnameX != NULL)
		{
			saveFile << surnameX->info << endl;
			surnameX = surnameX->link;
		}
		saveFile.close();

		saveFile.open("C:/PatientFileIndex/name.txt");
		nameX = nameA;
		while (nameX != NULL)
		{
			saveFile << nameX->info << endl;
			nameX = nameX->link;
		}
		saveFile.close();

		saveFile.open("C:/PatientFileIndex/middle.txt");
		middleX = middleA;
		while (middleX != NULL)
		{
			saveFile << middleX->info << endl;
			middleX = middleX->link;
		}
		saveFile.close();

		saveFile.open("C:/PatientFileIndex/age.txt");
		ageX = ageA;
		while (ageX != NULL)
		{
			saveFile << ageX->info << endl;
			ageX = ageX->link;
		}
		saveFile.close();

		saveFile.open("C:/PatientFileIndex/gender.txt");
		genderX = genderA;
		while (genderX != NULL)
		{
			saveFile << genderX->info << endl;
			genderX = genderX->link;
		}
		saveFile.close();

		saveFile.open("C:/PatientFileIndex/status.txt");
		statusX = statusA;
		while (statusX != NULL)
		{
			saveFile << statusX->info << endl;
			statusX = statusX->link;
		}
		saveFile.close();

		saveFile.open("C:/PatientFileIndex/sched.txt");
		schedX = schedA;
		while (schedX != NULL)
		{
			saveFile << schedX->info << endl;
			schedX = schedX->link;
		}
		saveFile.close();
	}
	 else
	 {
		 saveFile.open("C:/PatientFileIndex/surname.txt");
		 saveFile << "";
		 saveFile.close();

		 saveFile.open("C:/PatientFileIndex/name.txt");
		 saveFile << "";
		 saveFile.close();

		 saveFile.open("C:/PatientFileIndex/middle.txt");
		 saveFile << "";
		 saveFile.close();

		 saveFile.open("C:/PatientFileIndex/age.txt");
		 saveFile << "";
		 saveFile.close();

		 saveFile.open("C:/PatientFileIndex/gender.txt");
		 saveFile << "";
		 saveFile.close();

		 saveFile.open("C:/PatientFileIndex/status.txt");
		 saveFile << "";
		 saveFile.close();

		 saveFile.open("C:/PatientFileIndex/sched.txt");
		 saveFile << "";
		 saveFile.close();
	 }

	printProtocol();
}

// build reminder list
void PatientFile::buildRe()
{
	string temp;

	reminderA = reminderB = NULL;

	surnameX = surnameA;
	nameX = nameA;
	middleX = middleA;
	schedX = schedA;

	while (surnameX != NULL)
	{
		if (schedX->info != "None")
		{
			nodeType<string> *reminder;
			reminder = new nodeType<string>;

			temp = schedX->info + " // " + surnameX->info + ", " + nameX->info + " " + middleX->info;

			reminder->info = temp;
			reminder->link = NULL;

			if (reminderA == NULL)
			{
				reminderA = reminder;
				reminderB = reminder;
			}
			else
			{
				reminderB->link = reminder;
				reminderB = reminder;
			}
		}

		surnameX = surnameX->link;
		nameX = nameX->link;
		middleX = middleX->link;
		schedX = schedX->link;
	}
}

void PatientFile::printProtocol()
{
	surnameX = surnameA;
	nameX = nameA;
	middleX = middleA;
	statusX = statusA;
	schedX = schedA;

	string practitioner, prescription;

	ifstream user;
	user.open("C:/PatientFileIndex/central.txt");
	getline(user, practitioner);
	user.close();

	ofstream saveFile;

	if (surnameA != NULL)
	{
		while (surnameX != NULL)
		{
			saveFile.open("C:/PatientFileIndex/" + surnameX->info + nameX->info + middleX->info + ".txt");
			saveFile << "Name: " << surnameX->info + ", " + nameX->info + " " + middleX->info << endl;
			saveFile << "Status: " << statusX->info << endl;
			saveFile << "Schedule: " << schedX->info << endl;
			saveFile << "Prescription:";

			// add status here for more diagnosis
			if (statusX->info == "Hypertension")
				prescription = "\n\tMedicine: Metropolol Succinate\n\tDosage: 25mg Tablet Maintenance Intake\n\tFrequency: 2x a day";
			else if (statusX->info == "Diarrhea")
				prescription = "\n\tMedicine: Loperamide\n\tDosage: 1 Capsule\n\tFrequency: Once";
			else if (statusX->info == "Migraine")
				prescription = "\n\tMedicine: Aspirin\n\tDosage: 1 325mg Tablet\n\tFrequency: Every 4-6 hours";
			else if (statusX->info == "Flu")
				prescription = "\n\tMedicine: Ibuprofen\n\tDosage: 800mg Tablet\n\tFrequency: Every 6 hours";
			else
				prescription = "";

			saveFile << prescription << endl << endl;
			saveFile << "Medical Practitioner: " << practitioner;
			saveFile.close();

			surnameX = surnameX->link;
			nameX = nameX->link;
			middleX = middleX->link;
			statusX = statusX->link;
			schedX = schedX->link;
		}
	}
}

void PatientFile::print()
{
	printProtocol();

	string surname, name, middle;
	int position;

	system("color f0");
	color(15);

	cout << "HOME // PRINT RECORD\n\n";
	Sleep(100);

	if (found || executed)
	{
		// prompt user for patient
		color(177);
		cout << "Surname: ";
		color(191);
		getline(cin, surname);
		color(177);
		cout << "Given Name: ";
		color(191);
		getline(cin, name);
		color(177);
		cout << "Middle Initial: ";
		color(191);
		getline(cin, middle);
		color(240);

		color(240);
		cout << "\nRetrieving File ";
		load();
		system("cls");

		color(15);
		cout << "HOME // PRINT RECORD\n\n";
		Sleep(100);

		string path;
		path = surname + name + middle;

		ifstream printRecord;
		printRecord.open("C:/PatientFileIndex/" + path + ".txt");

		color(177);
		if (printRecord.is_open())
		{
			string line;

			while (getline(printRecord, line))
			{
				Sleep(100);
				cout << line << endl;
			}

			color(177);
			Sleep(100);
			cout << "\nFile retrieval was successful.\n";
			searchfound = false;
		}
		else
		{
			color(177);
			cout << "Record was not found.\n";
		}
	}
	else
	{
		color(177);
		cout << "No existing records have been found.\n";
	}

	// prompt user to select next action
	Sleep(100);
	color(177);
	cout << "What do you want to do?\n";  Sleep(100);
	color(240);
	cout << "   (P) Print Record\n";  Sleep(100);
	cout << "   (B) Back to Main Menu\n";  Sleep(100);
	cout << "   (E) Exit\n";  Sleep(100);
	color(240);

AGAIN:
	cin.sync();
	color(177);
	cout << "\nOption: ";
	color(191);
	single(choice); cout << endl;
	color(240);

	switch (choice[0])
	{
	case 'P':
	case 'p':
		system("cls");
		print();
		break;
	case 'B':
	case 'b':
		system("cls");
		menu();
		break;
	case 'E':
	case 'e':
		cout << "\nBYE\n";
		Sleep(1500);
		close = false;
		break;
	default:
		cout << "Invalid\n";
		goto AGAIN;
	}
}