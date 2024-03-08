/*************************************************
* Program: Lab 6a - Student.h
* ================================================
* Programmer: Cameron Abo
* Class: CS 1C M/W 10:30a
*************************************************/
#pragma once
#include <iostream>
#include <string>

using namespace std;
struct Student
{
	int id;
	string name;
	Student* next;
};
