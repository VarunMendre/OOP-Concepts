// Abstaction 
// process of hiding complex things behind a procedure that makes thing easier to understand and use.
// we do this to hide the complexity of the system and only expose the necessary details to the user 


// C++ Code : 
#include <bits/stdc++.h>
using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0; 
    // pure virtual function, 
    // virtual means it can be overridden in the derived class 
    // and = 0 means it is a pure virtual function, 
    // it has no implementation in the base class 
    // and must be implemented in the derived class
};
class Employee : AbstractEmployee
{

private:
    string Name;
    string Company;
    int Age;

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

    Employee(string name, string company, int age) // constructor
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void AskForPromotion() {
        if(Age >= 30) {
            cout << "Congradulations! you got promotion" << endl;
        }else {
            cout << "Sorry, you not get promotion" << endl;
        }
    }
};
int main()
{

    Employee emp1 = Employee("Varun", "Google", 26);
    Employee emp2 = Employee("Sharry", "Google", 30);

    emp1.AskForPromotion();
    emp2.AskForPromotion();

    return 0;
}


/**
JS Code : 

class AbstractEmployee {
  constructor() {
    if (this.constructor === AbstractEmployee) {
      throw new Error("Cannot instantiate abstract class");
    }
  }

  // abstract method
  askForPromotion() {
    throw new Error("Method must be implemented");
  }
}

class Employee extends AbstractEmployee {
  #name;
  #company;
  #age;

  constructor(name, company, age) {
    super();
    this.#name = name;
    this.#age = age;
    this.#company = company;
  }

  setName(name) {
    if (name.length > 5) {
      this.#name = name;
    } else {
      console.log("Name Should be at least 5 characters long");
    }
  }

  getName() {
    return this.#name;
  }

  setCompany(company) {
    if (company.length > 5) {
      this.#company = company;
    } else {
      console.log("company name should be at least 5 characters long");
    }
  }

  getCompany() {
    return this.#company;
  }

  setAge(age) {
    if (age >= 18) {
      this.#age = age;
    } else {
      console.log("age Should be at least 18 years old");
    }
  }

  getAge() {
    return this.#age;
    }
    

    askForPromotion() {
        if (this.#age >= 30) {
            console.log(`Congratulations! ${this.#name}, you got promotion`);
        }
        else {
            console.log(`Sorry, ${this.#name} you didn't get promotion`);
        }
    }
}


// main
const emp1 = new Employee("Varun", "Google", 26);
const emp2 = new Employee("Sharry", "Google", 30);

emp1.askForPromotion();
emp2.askForPromotion();


 */
