




#include <iostream>

struct Node {
    int id;
    Node* next;
    Node* prev;
};

void insertAfter(Node* current, Node* newNode) {
    if (current == nullptr || newNode == nullptr)
        return;

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr)
        current->next->prev = newNode;

    current->next = newNode;
}

void removeNode(Node* target) {
    if (target == nullptr)
        return;

    if (target->prev != nullptr)
        target->prev->next = target->next;

    if (target->next != nullptr)
        target->next->prev = target->prev;

    target->prev = nullptr;
    target->next = nullptr;
}

int main() {

    Node node{0, nullptr, nullptr};
    Node newNode{1, nullptr, nullptr};
    Node newNode2{2, nullptr, nullptr};

    insertAfter(&node, &newNode);

    std::cout << "Next node ID: "
              << node.next->id << std::endl;

    std::cout << "Previous node ID: "
              << newNode.prev->id << std::endl;

    insertAfter(&newNode, &newNode2);

    std::cout << "Next node ID: "
              << newNode.next->id << std::endl;

    std::cout << "Previous node ID: "
              << newNode.prev->id << std::endl;

    removeNode(&newNode2);

    std::cout << "After removal: "
              << (newNode.next == nullptr) << std::endl;

    return 0;
}