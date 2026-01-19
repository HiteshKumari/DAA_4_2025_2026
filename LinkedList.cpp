#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtMiddle(int val, int pos) {
    if (pos <= 1 || head == NULL) {
        insertAtBeginning(val);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd() {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

void deleteAtMiddle(int pos) {
    if (head == NULL || pos <= 1) {
        deleteAtBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next->next != NULL; i++) {
        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void Display() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertAtEnd(5);
    insertAtEnd(8);
    insertAtBeginning(2);
    insertAtMiddle(6, 3);

    Display();

    deleteAtBeginning();
    deleteAtMiddle(2);
    deleteAtEnd();

    Display();

    return 0;
}
