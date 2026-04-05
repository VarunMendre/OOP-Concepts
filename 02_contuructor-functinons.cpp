// rules :

// 1. constructor doesn't have return type
// 2. constructor name is same as class name
// 3. constructor must be public

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

/*

JS code :

class Employee {
    constructor(name, company, age) {
        this.Name = name;
        this.Company = company;
        this.Age = age;
    }

    introduceYourself() {
        console.log("Name - " + this.Name);
        console.log("Company - " + this.Company);
        console.log("Age - " + this.Age);
    }
}

const emp1 = new Employee("Varun", "Google", 30);
emp1.introduceYourself();




*/