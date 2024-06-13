#include <iostream>
#include <memory>

class Node : public std::enable_shared_from_this<Node> {
public:
    Node(int value) : value(value) {
        std::cout << "Node created: " << value << std::endl;
    }
    ~Node() {
        std::cout << "Node destroyed: " << value << std::endl;
    }
    void setNext(std::shared_ptr<Node> nextNode) {
        next = nextNode;
    }
    void display() const {
        std::cout << "Node: " << value << std::endl;
    }
private:
    int value;
    std::weak_ptr<Node> next;
};


int main() {
    auto node1 = std::make_shared<Node>(1);
    auto node2 = std::make_shared<Node>(2);
    node1->setNext(node2);
    node2->setNext(node1);
    return 0;
}

