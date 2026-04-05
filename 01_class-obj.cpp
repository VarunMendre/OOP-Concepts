// C++ code :
#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    string Name;
    string Company;
    int Age;

    void IntroduceYourself()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
};
int main()
{

    Employee emp1;
    emp1.Name = "Varun";
    emp1.Company = "Google";
    emp1.Age = 30;

    emp1.IntroduceYourself();
    return 0;
}

/**
JS code :

class Employee {
    // without constructor :

    let Name = "";
    let Company = "";
    let Age = 0;

    introduceYourself() {
        console.log("Name - " + this.Name);
        console.log("Company - " + this.Company);
        console.log("Age - " + this.Age);
    }
}

const emp1 = new Employee();
emp1.Name = "Varun";
emp1.Company = "Google";
emp1.Age = 30;

emp1.introduceYourself();

const emp2 = new Employee();
emp2.Name = "Alice";
emp2.Company = "Microsoft";
emp2.Age = 25;

emp2.introduceYourself();

 */