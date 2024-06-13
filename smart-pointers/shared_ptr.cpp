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

void foo(std::shared_ptr<Person>& ptr){
    std::shared_ptr<Person> pt = ptr;
    std::cout << "count dans foo : " << pt.use_count() << std::endl;
}
int main() {
    std::shared_ptr<Person> personPtr1 = std::make_shared<Person>("Jane Doe");
    {
        foo(personPtr1);
        std::shared_ptr<Person> personPtr2 = personPtr1;
        personPtr2->display();
        std::cout << "count : " << personPtr1.use_count() << std::endl;
    } // personPtr2 est détruit ici
    std::cout << "count : " << personPtr1.use_count() << std::endl;
    return 0;
}

