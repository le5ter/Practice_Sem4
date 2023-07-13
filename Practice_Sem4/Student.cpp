#include "Student.h"
#include <math.h>
#include <iostream>

Student::Student()
{
    *this->name = "";
    *this->lastname = "";
    this->avg_marks = 0;
    this->str_avg_marks = "";
    for (int i = 0; i < 5; i++)
    {
        marks[i] = 0;
    }
}

Student::Student(std::string name, std::string lastname, int marks[5])
{
    this->Set_name(name);
    this->Set_lastname(lastname);
    this->Set_mark(marks[0], 0);
    this->Set_mark(marks[1], 1);
    this->Set_mark(marks[2], 2);
    this->Set_mark(marks[3], 3);
    this->Set_mark(marks[4], 4);
    double res = 0;
    for (int i = 0; i < 5; i++)
    {
        res += marks[i];
    }
    avg_marks = res / 5;
    str_avg_marks = precision_2(avg_marks);
    //str_avg_marks = std::to_string(avg_marks);

}

std::string Student::Get_name()
{
    return *this->name;
}

std::string Student::Get_lastname()
{
    return *this->lastname;
}

std::string Student::Get_str_avarage()
{
    return this->str_avg_marks;
}

int Student::Get_mark(int index)
{
    return marks[index];
}

void Student::Set_name(std::string name)
{
    *this->name = name;
}

void Student::Set_lastname(std::string lastname)
{
    *this->lastname = lastname;
}

void Student::Set_mark(int mark, int index)
{
    this->marks[index] = mark;
}

void Student::Set_avarage(double avg)
{
    this->avg_marks = avg;
}

int Student::Count_bad_marks()
{
    int res = 0;
    for (int i = 0; i < 5; i++)
    {
        if (marks[i] == 2)
        {
            res += 1;
        }
    }
    return res;
}

double Student::Get_avarage()
{
    return avg_marks;
}

int Student::Marks_sum()
{
    int res = 0;
    for (int i = 0; i < 5; i++)
    {
        res += marks[i];
    }
    return res;
}
