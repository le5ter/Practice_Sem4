#pragma once
#include <string>

class Student
{
private:
	std::string name[20];
	std::string lastname[20];
	int marks[5];

public:
	Student();
	Student(std::string name, std::string lastname);
	Student(std::string name, std::string lastname, int marks[5]);
	std::string Get_name();
	std::string Get_lastname();
	int Get_mark(int mark);
	void Set_name(std::string name);
	void Set_lastname(std::string lastname);
	void Set_mark(int mark, int index);
};

