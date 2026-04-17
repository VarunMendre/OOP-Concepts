/*
  Inheritance in C++:
  Inheritance lets one class reuse the data and behavior of another class.
  A derived class gets the members of a base class and can also add its own features.

  Common inheritance types:
  1. Single inheritance      -> one derived class from one base class
  2. Multilevel inheritance  -> class derived from a derived class
  3. Multiple inheritance    -> one class inherits from more than one base class
  4. Hierarchical inheritance-> many derived classes from one base class
  5. Hybrid inheritance      -> combination of two or more types

  Access modes in inheritance:
  - public    -> base public stays public, base protected stays protected
  - protected -> base public/protected become protected
  - private   -> base public/protected become private

  Important points used in this file:
  - Abstract class: a class with at least one pure virtual function
  - Pure virtual function: makes a class incomplete and forces derived classes to define behavior
  - Encapsulation: private data is accessed through public setters/getters
  - Protected members: accessible inside derived classes
*/

#include <bits/stdc++.h>
using namespace std;

class AbstractEmployee
{
    // Pure virtual function: every concrete derived class must define it.
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
{

private:
    // Private members can be accessed only inside Employee.
    string Company;
    int Age;

protected:
    // Protected member can be used inside derived classes like Developer and Teacher.
    string Name;

public:
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

    // Constructor initializes the basic details of every employee.
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    // Employee gives its own implementation of the abstract behavior.
    void AskForPromotion()
    {
        if (Age >= 30)
        {
            cout << "Congradulations! you got promotion" << endl;
        }
        else
        {
            cout << "Sorry, you not get promotion" << endl;
        }
    }
};

// Public inheritance models an "is-a" relationship:
// Developer is an Employee.
class Developer : public Employee
{
public:
    string Language;

    // Calls the base-class constructor first, then sets Language.
    Developer(string name, string company, int age, string language)
        : Employee(name, company, age)
    {
        Language = language;
    }

    void fixBug()
    {
        cout << Name << " Fixed bug using " << Language << endl;
    }
};

class Teacher : public Employee
{
public:
    string Subject;

    // Reuses Employee data and adds Teacher-specific data.
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age)
    {
        Subject = subject;
    }

    void prepareChapter()
    {
        cout << Name << " is preparing " << Subject << " chapter " << endl;
    }
};

int main()
{
    Developer d1 = Developer("Gaurav", "AWS", 26, "java");
    // d1.fixBug();
    // d1.AskForPromotion();

    Teacher t1 = Teacher("Shreya", "Meta", 35, "Python");
    t1.prepareChapter();
    t1.AskForPromotion();

    return 0;
}

/*
JavaScript version of the same logic:

class Employee {
  constructor(name, company, age) {
    this.name = name;
    this.company = company;
    this.age = age;
  }

  setName(name) {
    if (name.length > 5) {
      this.name = name;
    } else {
      console.log("Name should be at least 5 characters long.");
    }
  }

  getName() {
    return this.name;
  }

  setCompany(company) {
    if (company.length > 5) {
      this.company = company;
    } else {
      console.log("Company name should be at least 5 characters long.");
    }
  }

  getCompany() {
    return this.company;
  }

  setAge(age) {
    if (age >= 18) {
      this.age = age;
    } else {
      console.log("Age should be at least 18.");
    }
  }

  getAge() {
    return this.age;
  }

  introduceYourself() {
    console.log("Name - " + this.name);
    console.log("Company - " + this.company);
    console.log("Age - " + this.age);
  }

  askForPromotion() {
    if (this.age >= 30) {
      console.log("Congratulations! you got promotion");
    } else {
      console.log("Sorry, you did not get promotion");
    }
  }
}

class Developer extends Employee {
  constructor(name, company, age, language) {
    super(name, company, age);
    this.language = language;
  }

  fixBug() {
    console.log(this.name + " Fixed bug using " + this.language);
  }
}

class Teacher extends Employee {
  constructor(name, company, age, subject) {
    super(name, company, age);
    this.subject = subject;
  }

  prepareChapter() {
    console.log(this.name + " is preparing " + this.subject + " chapter");
  }
}

const d1 = new Developer("Gaurav", "AWS", 26, "java");
const t1 = new Teacher("Shreya", "Meta", 35, "Python");

t1.prepareChapter();
t1.askForPromotion();
*/
