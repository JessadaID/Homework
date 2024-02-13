


#include <iostream>
#include <string>
using namespace std;

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
};

class LinkedList {
protected:
    studentNode *start, *now;

public:
    LinkedList(); // Initialize start and now
    ~LinkedList(); // Release memory allocated for all nodes
    void InsNode(char n[], int a, char s, float g); // Insert a new node before the current node
    void DelNode(); // Delete the current node
    void GoNext(); // Move to the next node
    virtual void ShowNode(); // Display data in the current node
};

class NewList : public LinkedList {
public:
    void GoFirst(); // Move to the first node
    void ShowNode() override; // Display data in all nodes from the beginning to the end
};

LinkedList::LinkedList() {
    start = now = nullptr;
}

LinkedList::~LinkedList() {
    studentNode *temp;
    now = start;
    while (now != nullptr) {
        temp = now;
        now = now->next;
        delete temp;
    }
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    studentNode *newNode = new studentNode;
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = now->next;
    now->next = newNode;
}

void LinkedList::DelNode() {
    studentNode *temp;
    if (now->next != nullptr) {
        temp = now->next;
        now->next = temp->next;
        delete temp;
    }
}

void LinkedList::GoNext() {
    if (now->next != nullptr) {
        now = now->next;
    }
}

void LinkedList::ShowNode() {
    cout << "Name: " << now->name << ", Age: " << now->age << ", Sex: " << now->sex << ", GPA: " << now->gpa << endl;
}

void NewList::GoFirst() {
    now = start;
}

void NewList::ShowNode() {
    studentNode *temp = start;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", Age: " << temp->age << ", Sex: " << temp->sex << ", GPA: " << temp->gpa << endl;
        temp = temp->next;
    }
}

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}