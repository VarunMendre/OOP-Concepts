// Polymorphism : this word comes from greek language and its compound word poly morph  means many forms , ability of obj or methods to have many forms
// most common use of polymorphism is when a parent class reference is used to refer child class object
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

    virtual void Work()
    {
        cout << Name << " is checking email, task logs, performing those task... " << endl;
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
    void Work()
    {
        cout << Name << " writting " << Language << " code " << endl;
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

    void Work()
    {
        cout << Name << " is Teaching " << Subject << " for students " << endl;
    }
};

class BusDriver : public Employee
{

    string BusName;

public:
    BusDriver(string name, string company, int age, string busname)
        : Employee(name, company, age)
    {
        BusName = busname;
    }

    void Work()
    {
        cout << Name << " he is driving " << BusName << endl;
    }
};

int main()
{
    Developer d1 = Developer("Gaurav", "AWS", 26, "java");
    Teacher t1 = Teacher("Shreya", "Meta", 35, "Python");
    BusDriver b1 = BusDriver("Binod", "Volvo", 45, "Volov Bus");

    Employee *e1 = &d1;
    Employee *e2 = &t1;
    Employee *e3 = &b1;

    e1->Work();
    e2->Work();
    e3->Work();

    return 0;
}

/*
JS code :

// Polymorphism — many forms via method overriding

// Abstract base (simulated with a class that throws if Work() isn't overridden)
class AbstractEmployee {
  AskForPromotion() {
    throw new Error("AskForPromotion() must be implemented");
  }
}

class Employee extends AbstractEmployee {
  #company;  // private field (ES2022 #syntax)
  #age;

  constructor(name, company, age) {
    super();
    this.name = name;          // protected (convention: no prefix)
    this.setCompany(company);
    this.setAge(age);
  }

  setName(name) {
    if (name.length > 5) this.name = name;
    else console.log("Name should be at least 5 characters long.");
  }
  getName() { return this.name; }

  setCompany(company) {
    if (company.length > 5) this.#company = company;
    else console.log("Company name should be at least 5 characters long.");
  }
  getCompany() { return this.#company; }

  setAge(age) {
    if (age >= 18) this.#age = age;
    else console.log("Age should be at least 18.");
  }
  getAge() { return this.#age; }

  introduceYourself() {
    console.log(`Name - ${this.name}`);
    console.log(`Company - ${this.getCompany()}`);
    console.log(`Age - ${this.getAge()}`);
  }

  AskForPromotion() {
    if (this.getAge() >= 30)
      console.log("Congratulations! You got a promotion.");
    else
      console.log("Sorry, you did not get a promotion.");
  }

  // Virtual method — subclasses override this
  Work() {
    console.log(`${this.name} is checking email, task logs, performing tasks...`);
  }
}

class Developer extends Employee {
  constructor(name, company, age, language) {
    super(name, company, age);
    this.language = language;
  }

  fixBug() {
    console.log(`${this.name} fixed bug using ${this.language}`);
  }

  Work() {  // overrides Employee.Work()
    console.log(`${this.name} is writing ${this.language} code`);
  }
}

class Teacher extends Employee {
  constructor(name, company, age, subject) {
    super(name, company, age);
    this.subject = subject;
  }

  prepareChapter() {
    console.log(`${this.name} is preparing ${this.subject} chapter`);
  }

  Work() {
    console.log(`${this.name} is teaching ${this.subject} to students`);
  }
}

class BusDriver extends Employee {
  #busName;  // private field

  constructor(name, company, age, busName) {
    super(name, company, age);
    this.#busName = busName;
  }

  Work() {
    console.log(`${this.name} is driving ${this.#busName}`);
  }
}

// --- main ---
const d1 = new Developer("Gaurav", "AWS",   26, "Java");
const t1 = new Teacher  ("Shreya", "Meta",  35, "Python");
const b1 = new BusDriver("Binod",  "Volvo", 45, "Volvo Bus");

// Polymorphism — same interface, different behaviour
const employees = [d1, t1, b1];
employees.forEach(e => e.Work());



*/
