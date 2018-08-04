/*
Patient File Index
Luke Clark M. Andrada

Patient File Index
	[1] to store patient files (filestream)
	[2] to display patient files (iostream)
	[3] to search for a specific patient record (linked list sequential search)
	[4] to add new patient records or edit existing files (linked list)
	[5] to delete pre-existing records (linked list)
	[5] to automatically sort the lists (linked list insertion list)
	[6] to display sorted appointment reminders (insertion sort)
	[7] to provide basic login security system (filestream)

Patient File
	[a] Name
	[b] Age
	[c] Gender
	[c] Status (Diagnosis)
	[d] Schedule (Appointment)
*/

// Central.cpp
#include <iostream>
#include <Windows.h>
#include "PatientFile.h"

using namespace std;

int main()
{
	// PatientFile instance
	PatientFile call;

	system("color F0");

	// set the console title
	SetConsoleTitle("Patient File Index");

	// call preLogin()
	call.preLogin();

	while (call.close)
	{
		call.menu();
	}

	call.save();

	return 0;
}
