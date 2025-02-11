#include <iostream>
#include <stack>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListStack {
private:
    stack<Node*> nodeStack;
    Node* head;

public:
    LinkedListStack() : head(nullptr) {}

    // Push element to stack (Linked List)
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        nodeStack.push(newNode);
    }

    // Pop element from stack (Linked List)
    void pop() {
        if (head == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        nodeStack.pop();
        delete temp;
    }

    // Peek top element
    int top() {
        if (head == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return head->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Display elements of stack
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    LinkedListStack stack;
    int choice, value;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top Element: " << stack.top() << endl;
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}