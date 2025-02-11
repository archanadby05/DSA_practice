#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
private:
    queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int val) {
        q2.push(val);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    // Pop element from stack
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        q1.pop();
    }

    // Get top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    // Check if stack is empty
    bool isEmpty() {
        return q1.empty();
    }

    // Display stack elements
    void display() {
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " -> ";
            temp.pop();
        }
        cout << "NULL" << endl;
    }
};

int main() {
    StackUsingQueue stack;
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