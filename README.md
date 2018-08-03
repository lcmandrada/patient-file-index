# Patient File Index

**Legacy Project

A basic console application written in c++ with the following objectives:
- to store patient files (filestream)
- to display patient files (iostream)
- to search for a specific patient record (linked list sequential search)
- to add new patient records or edit existing files (linked list)
- to delete pre-existing records (linked list)
- to automatically sort the lists (linked list insertion list)
- to display sorted appointment reminders (insertion sort)
- to provide basic login security system (filestream)

It produces a file with the following content:
- Name
- Age
- Gender
- Status (Diagnosis)
- Schedule (Appointment)

# Build

It was built using Visual Studio since some of the functions employed are not available in GCC.
It may be necessary to edit the properties of the project to successfully build it.
In **Configuration Properties** > **General**, configure the **Character Set** to **Use Multi-Byte Character Set**.