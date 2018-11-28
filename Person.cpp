#include "Person.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Person::Person() {
  name = "";
  age = 0;
}

Person::Person(string _name, int _age) {
  name = _name;
  if (_age >= 0 && _age < 120) {
    age = _age;
  } else {
    throw std::invalid_argument("Invalid age");
  }
}

string Person::getName() const { return name; }

int Person::getAge() const { return age; }

void Person::print() const {
  cout << "Name : " << name << endl;
  cout << "Age : " << age << endl;
}

void Person::setName(string name) { this->name = name; }

void Person::setAge(int age) {
  if (age >= 0 && age < 120) {
    this->age = age;
  } else {
    throw std::invalid_argument("Invalid Age");
  }
}