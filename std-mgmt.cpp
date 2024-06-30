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

     Student* addNewStudent(Student* head) {
    string name, grade;
    int ID;

    cout << "Enter the name of the student: \n";
   
    cin>>name;

    cout << "Enter the ID of the student:\n ";
    cin >> ID;

    cout << "Enter the grade of the student:\n ";
    cin >> grade;

    head = storestudentrecord(head, name, ID, grade);

    cout << "Student record added successfully!" << endl;

    return head;
}

  void searchstudent(Student* head) {
    int studID;
    cout << "Please enter the student ID to be searched: "<<endl;
    cin >> studID;

    Student* temp1 = head;
    bool found = false;

    while (temp1 != NULL) {
        if (temp1->ID == studID) {
            found = true;
            break;
        }
        temp1 = temp1->next;
    }

    if (found) {
        cout << "Student Found! Student information is as follows:" << endl;
        cout << "Name: " << temp1->name << ", ID: " << temp1->ID << ", grade: " << temp1->grade << endl;
    } else {
        cout << "Student with ID " << studID << " not found." << endl;
    }
   
}