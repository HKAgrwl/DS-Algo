#include <iostream>
using namespace std;

class Student{
    int sem;//class is now a private data member
    public:
    string name;
    int age;
    bool gender;

    // Parametrised Constructor:-
    Student(string s,int a,int g){
        cout<<"Parametrised Constructor"<<endl;
        name=s;
        age=a;
        gender=g;
    }
    // default condtructor:-
    Student(){
        cout<<"Default Constructor"<<endl;
    }

    Student(Student &a){
        cout<<"Copy Constructor"<<endl;
        name=a.name;
        age=a.age;
        gender=a.gender;
        //Separately defined copy constructor as above, creates deep copy of the object.
        // Default copy constructors create shallow copy of the object.
    }

    ~Student(){
        cout<<"Destructor Called"<<endl;
    }

    void setsem(int x){
        sem=x;
    }
    void PrintInfo(){
        cout<<name<<endl;
        cout<<sem<<endl;
    }

    // oprator overloading
    bool operator == (Student &a){
        if(name==a.name && age==a.age && gender==a.gender){
            return true;
        }else{
            return false;
        }
    }

};

int main()  
{
    // Student a;
    // a.name = "Harsh";
    // a.age=19;
    // a.gender =0;


    // Student arr[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     cin>>arr[i].name;
    //     cin>>arr[i].age;
    //     cin>>arr[i].gender;
    // }
    // a.setsem(13);
    // a.PrintInfo();

    Student a("Harsh",19,0);

    Student b("Rahul",15,0);
    b.PrintInfo();
    Student c;
    Student d = a;
    return 0;
}
