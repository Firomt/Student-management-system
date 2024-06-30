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

 void editStudent(Student*head)
{
    Student*temp1=head;
    int studID;
    string newgrade;

    cout<<"please enter the Student ID for whom record is edited: "<<endl;
    cin>>studID;
    bool found = false;
    if(head==NULL){
        cout<<"student not found!"<<endl;
        //return;
    }
    while (temp1 != NULL) {
        if (temp1->ID == studID) {
            found = true;
            break;
        }
        temp1=temp1->next;
    }
    if(found){
     cout<<"please enter the new grade of the student "<<endl;
     cin>>newgrade;
     temp1->grade=newgrade;
     cout<<"the student's grade is updated to the new grade successfully! the new updated student record is as follows "<<endl;
     cout<<"Name: "<<temp1->name<<", ID:"<<temp1->ID<<", grade:"<<temp1->grade<<endl;
    }
    else{
        cout<<"Student with the given ID is not found! "<<endl;
    }
}

Student* deletefirststudent(Student*& head)
 {
    if (head != NULL) {
        Student* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }
    return head;

}

void deletestudent(Student*&head){

    Student*temp1=head;
    int studID;
    cout<<"please enter the ID of the student to be deleted: "<<endl;
    cin>>studID;
    if(head->ID==studID){
        head=deletefirststudent(head);
        cout<<"Student record deleted successfully! "<<endl;
         return;
    }


    bool found = false;

    while(temp1!=NULL){
            if(temp1->ID==studID){
                found=true;
                break;
            }
        temp1=temp1->next;
    }


   if (found) {
        if (temp1->prev != NULL) {
            temp1->prev->next = temp1->next;
        }
        if (temp1->next != NULL) {
            temp1->next->prev = temp1->prev;
        }
        delete temp1;
        cout << "Student record deleted successfully!" << endl;
    } else {
        cout << "Student with the given ID is not found!" << endl;
    }
   
}

 void displaystudent(Student*head){
        Student*temp1=head;
        if(head==NULL){
            cout<<"no Student record found"<<endl;
        }
        while(temp1!=NULL){
            cout<<"Name:"<<temp1->name<<", ID: "<<temp1->ID<<", Grade: "<<temp1->grade<<endl;
            temp1=temp1->next;

        }
      


    }

    int main(){
      Student*head=NULL;
      
       head= storestudentrecord(head,"firo",11,"A");
       head= storestudentrecord(head,"john",12,"B");
       head= storestudentrecord(head,"abebe",13,"A+");
       head= storestudentrecord(head,"chala",14,"B+");
       head= storestudentrecord(head,"Daniel",15,"C+");
       head= storestudentrecord(head,"Gemechu",16,"D");
       head= storestudentrecord(head,"Nati",17,"F");
       head= storestudentrecord(head,"Bona",18,"B+");
       head= storestudentrecord(head,"Hailu",19,"C");
       head= storestudentrecord(head,"Habtamu",20,"B");
       

       int choice;
       while(1){
        cout << "\n*****************----- WELCOME TO STUDENT MANAGEMENT SYSTEM -----**********" << endl;
        cout << "1. Display Students" << endl;
        cout << "2. Add New Student"<<endl;
        cout << "3. Search Student" << endl;
        cout << "4. Edit Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;
        cout << "Please Enter your choice: ";
        
        cin >> choice;
        switch(choice){
        case 1:
            displaystudent(head);
            break;
        case 2:
            head = addNewStudent(head);
             break;
        case 3:
           searchstudent(head);
            break;
        case 4:
            editStudent(head);
            break;
        case 5:
             deletestudent(head);
            break;
        case 6:
            cout << "Exiting program.......Exited!" << endl;

                exit(0);
        default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }






        }

        return 0;
       }



