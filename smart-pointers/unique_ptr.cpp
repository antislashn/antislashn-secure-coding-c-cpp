#include <iostream>
#include <memory>

class Person {
public:
    Person(const std::string& name) : name(name) {
        std::cout << "Person created: " << name << std::endl;
    }
    ~Person() {
        std::cout << "Person destroyed: " << name << std::endl;
    }
    void display() const {
        std::cout << "Person: " << name << std::endl;
    }
private:
    std::string name;
};


void foo(const std::unique_ptr<Person>& personPtr ){
    personPtr->display();
}

int main() {
    std::unique_ptr<Person> personPtr = std::make_unique<Person>("John Doe");
    personPtr->display();
    foo(personPtr);
    personPtr->display();
    return 0;
}

