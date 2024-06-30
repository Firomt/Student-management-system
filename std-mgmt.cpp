#include<iostream>
using namespace std;
struct Student{
    string name;
    int ID;
    string grade;


    Student* prev;
    Student* next;
};
Student* storestudentrecord(Student*head,string name,int ID,string grade){
    Student * newstudent= new Student();
    newstudent->name=name;
    newstudent->ID=ID;
    newstudent->grade=grade;
    newstudent->prev=NULL;
    newstudent->next=NULL;
    if (head==NULL)
    {
        head=newstudent;
    }else{
         Student* temp1 = head;
      /*  while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = newstudent;
        newstudent->prev = temp1;
    }*/
   temp1->prev=newstudent;
   newstudent->next=temp1;
   head=newstudent;
    

    }
    return head;}