// Assignment 1
// Name:- Chirayu Jain
// Class:- CSC 340

// Used ChatGpt to understand the code and also create few parts which I made and have bugs.
 
#include <iostream>

using namespace std;

//Node Structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Class for linkedlist
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // insterting at the start
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // insterting at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // deleting the node which user want
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "The list is empty. Nothing to delete." << endl;
            return;
        }

        
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << value << " deleted." << endl;
            return;
        }

    
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

       
        if (current == nullptr) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        previous->next = current->next;
        delete current;
        cout << "Node with value " << value << " deleted." << endl;
    }

    // Printing the Linkedlist
    void printList() const {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

//Main function and a few tests
int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\nLinked List Menu:" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Delete node" << endl;
        cout << "4. Print list" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 4:
                cout << "Current list: ";
                list.printList();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
