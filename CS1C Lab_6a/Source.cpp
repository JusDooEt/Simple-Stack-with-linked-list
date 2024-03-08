/*************************************************
* Program: Lab 6a - Source.cpp
* ================================================
* Programmer: Cameron Abo
* Class: CS 1C M/W 10:30a
*************************************************/

#include "Student.h"

void insertStudent(Student*& head);
void deleteStudent(Student*& head);
void showLtoR(Student*& head);

int main()
{
	char answer = '\0';
	Student* head = NULL;
	cout << "Insert a student record (Y or N)? ";
	cin >> answer;
	while (toupper(answer) == 'Y')
	{
		insertStudent(head);
		cout << "Insert another student record into the list (Y or N): ";
		cin >> answer;
		system("cls");
	}
	if (head == nullptr)
	{
		cout << "The list is empty.\n\n";
		return 0;
	}
	cout << "Here is the list of students:\n";
	showLtoR(head);
	system("pause");
	system("cls");
	cout << "Do you want to remove a student from the list (Y or N)? ";
	cin >> answer;
	if (toupper(answer) == 'Y')
		deleteStudent(head);
	system("cls");
	if (head != nullptr)
	{
		cout << "Here is the list of students from left to right.\n";
		showLtoR(head);
		system("pause");
		system("cls");
	}
	// ---------------
	else
	{
		cout << "The list is empty.\n\n";
	}
	// ---------------
	return 0;
}
// --------------------------
// Complete this function
void insertStudent(Student*& head)
{
	Student* stdPtr = new Student;
	cout << "ID: ";
	cin >> stdPtr->id;
	cin.ignore();
	cout << "Name: ";
	getline(cin, stdPtr->name);

	stdPtr->next = head;
	head = stdPtr;
	stdPtr = NULL;

}
// --------------------------
// --------------------------
// Complete this function
void deleteStudent(Student*& head)
{
	Student* ptr;
	Student* temp;
	int id;
	cout << "Enter the ID of the student to be removed from the lsit : ";
	cin >> id;

	ptr = head;

	if (ptr->id == id)
	{
		temp = ptr;
		ptr = temp->next;
		delete temp;
		head = ptr;
		temp = NULL;
	}
	else
	{
		while (ptr->next != NULL)
		{
			if (ptr->next->id == id)
			{
				temp = ptr->next;
				ptr->next = temp->next;
				delete temp;
				temp = NULL;
			}
			ptr = ptr->next;
		}
	}
}
// --------------------------
// --------------------------
// Complete this function
void showLtoR(Student*& head)
{
	Student* ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->id << endl;
		cout << ptr->name << endl
			<< endl;

		ptr = ptr->next;
	}
}
// --------------------------

/* OUTPUT:
Insert a student record (Y or N)? y
ID: 100
Name: Tom Lee
Insert another student record into the list (Y or N): y

(screen clears)

ID: 101
Name: Bruce Lee insertStudent()
Insert another student record into the list (Y or N): y

(screen clears)

ID: 102
Name: Sara Lee
Insert another student record into the list (Y or N): n

Here is the list of students:
102
Sara Lee

101
Bruce lee

100
Tom Lee

(screen clears)

Do you want to remove a student from the list (Y or N)? y
Enter the ID of the student to be removed from the list: 101

Here is the list of students from left to right.
102
Sara Lee

100
Tom Lee
************************************************************/