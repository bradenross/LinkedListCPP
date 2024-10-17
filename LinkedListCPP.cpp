// LinkedListCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public: 
    LinkedList() : head(NULL) {}

    void addNodeToStart(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;

        head = newNode;
    }

    void addNodeToEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void addNodeAtIndex(int value, int index) {
        Node* newNode = new Node();
        newNode->data = value;

        if (index == 0) {
            addNodeToStart(value);
        }

        Node* temp = head;
        for (int i = 0; i < index - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Index out of range." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNodeAtStart() {
        if (!head) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteNodeAtEnd() {
        if (!head) {
            return;
        }
        
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deleteNodeAtIndex(int index) {
        if (index == 0) {
            deleteNodeAtStart();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Index out of range" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void displayList() {
        if (head == NULL) {
            cout << "Empty List" << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    int choice = 0;

    while (true) {
        cout << "Choose and option:\n(1) Add new node to start\n(2) Add new node to end\n(3) Add node at index\n(4) Delete node at start\n(5) Delete node at end\n(6) Delete node at index\n(7) Display Linked List\n(0) Quit\n";
        cin >> choice;
        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            cout << "Enter new value: ";
            int newValue = 0;
            cin >> newValue;

            list.addNodeToStart(newValue);
            list.displayList();
        }
        else if (choice == 2) {
            cout << "Enter new value: ";
            int newValue = 0;
            cin >> newValue;

            list.addNodeToEnd(newValue);
            list.displayList();
        }
        else if (choice == 3) {
            cout << "Enter new value: ";
            int newValue = 0;
            cin >> newValue;
            cout << "Enter index: ";
            int index = 0;
            cin >> index;
            list.addNodeAtIndex(newValue, index);
            list.displayList();
        }
        else if (choice == 4) {
            list.deleteNodeAtStart();
            list.displayList();
        }
        else if (choice == 5) {
            list.deleteNodeAtEnd();
            list.displayList();
        }
        else if (choice == 6) {
            cout << "Enter index: ";
            int newValue = 0;
            cin >> newValue;
            list.deleteNodeAtIndex(newValue);
            list.displayList();
        }
        else if (choice == 7){
            list.displayList();
        }
    }
}