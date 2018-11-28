#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Person.h"

constexpr int MAX_STUDENTS = 30;

int main() {
  std::vector<Person> people;

  bool invalidAge;

  for (int i = 0; i < MAX_STUDENTS; i++) {
    Person student{};
    std::string name;
    int age;

    std::cout << "Enter your name or End if finished: ";
    std::cin >> name;

    // If user enters "End", break out of loop
    if (name == "End") {
      break;
    }

    student.setName(name);

    do {
      invalidAge = false;
      std::cout << "Enter your age: ";
      std::cin >> age;

      try {
        student.setAge(age);
      } catch (std::invalid_argument invalidArg) {
        std::cerr << "\nError: " << invalidArg.what() << std::endl;
        invalidAge = true;
      }

    } while (invalidAge);

    people.push_back(student);
  }

  // Print the result
  for (auto person : people) {
    person.print();
  }

  int x;
  std::cout << "Press any key to exit...";
  std::cin >> x;
  return 0;
}
