// Idea of bundling or tightly coupling data and functions that operate on that data into a single unit is called encapsulation.
// It is one of the fundamental principles of object-oriented programming (OOP) and helps to achieve data hiding and abstraction.
// we do this to prevent direct access to some of an object's components, which can help to protect the integrity of the data and prevent unintended interference or misuse.

#include <bits/stdc++.h>
using namespace std;

class Employee
{

private:
    string Name;
    string Company;
    int Age;

public:
    // getter is used to access the private data members and setter is used to modify the private data members.

    // getter and setter functions for Name, Company and Age
    void setName(string name)
    {
        if (name.length() > 5)
            Name = name;
        else
        {
            cout << "Name should be at least 5 characters long." << endl;
        }
    }
    string getName()
    {
        return Name;
    }

    void setCompany(string company)
    {
        if (company.length() > 5)
            Company = company;
        else
        {
            cout << "Company name should be at least 5 characters long." << endl;
        }
    }
    string getCompany()
    {
        return Company;
    }

    void setAge(int age)
    {

        if (age >= 18)
            Age = age;
        else
        {
            cout << "Age should be at least 18." << endl;
        }
    }
    int getAge()
    {
        return Age;
    }

    void IntroduceYourself()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    Employee(string name, string company, int age) // constructor
    {
        Name = name;
        Company = company;
        Age = age;
    }
};
int main()
{

    Employee emp1 = Employee("Varun", "Google", 30);

    emp1.setAge(15); // using setter to modify the age

    cout << emp1.getName() << " is " << emp1.getAge() << " years old." << endl;

    return 0;
}


/*

same JS code :

class Employee {
    constructor(name, company, age) {
        this._name = name;
        this._company = company;
        this._age = age;
    }

    // getter and setter for name
    get name() {
        return this._name;
    }

    set name(name) {
        if (name.length > 5) {
            this._name = name;
        } else {
            console.log("Name should be at least 5 characters long.");
        }
    }

    // getter and setter for company
    get company() {
        return this._company;
    }

    set company(company) {
        if (company.length > 5) {
            this._company = company;
        } else {
            console.log("Company name should be at least 5 characters long.");
        }
    }

    // getter and setter for age
    get age() {
        return this._age;
    }

    set age(age) {
        if (age >= 18) {
            this._age = age;
        } else {
            console.log("Age should be at least 18.");
        }
    }

    introduceYourself() {
        console.log(`Name - ${this._name}`);
        console.log(`Company - ${this._company}`);
        console.log(`Age - ${this._age}`);
    }
}

const emp1 = new Employee("Varun", "Google", 30);
emp1.age = 15; // using setter to modify the age
console.log(`${emp1.name} is ${emp1.age} years old.`);

console.log(emp1.Name); // undefined, because Name is a private variable and cannot be accessed directly


*/
