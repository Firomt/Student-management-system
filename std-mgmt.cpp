#include<iostream>
using namespace std;
struct Student{
    string name;
    int ID;
    string grade;


    Student* prev;
    Student* next;
};