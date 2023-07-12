#pragma once
#include <string>

class Student
{
private:
	std::string name[20];
	std::string lastname[20];
	int marks[5];
	double avg_marks;
	std::string str_avg_marks;

public:
	Student();
	Student(std::string name, std::string lastname, int marks[5]);
	static bool f1(Student stud1, Student stud2)
	{
		return stud1.Count_bad_marks() > stud2.Count_bad_marks();
	};
	static bool f2(Student stud1, Student stud2)
	{
		return stud1.Get_avarage() < stud2.Get_avarage();
	};
	static bool f3(Student stud1, Student stud2)
	{
		return stud1.Get_avarage() > stud2.Get_avarage();
	};
	std::string Get_name();
	std::string Get_lastname();
	std::string Get_str_avarage();
	int Get_mark(int index);
	void Set_name(std::string name);
	void Set_lastname(std::string lastname);
	void Set_mark(int mark, int index);
	void Set_avarage(double avg);
	int Count_bad_marks();
	double Get_avarage();
	int Marks_sum();
	std::string precision_2(float number)
	{
		int decimal_part = (number * 10) - ((int)number * 10);
		return std::to_string((int)number) + "." + std::to_string(decimal_part);
	}

};

