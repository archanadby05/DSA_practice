#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
private:
    stack<int> s1, s2;

public:
    // Enqueue element into queue
    void enqueue(int val) {
        s1.push(val);
    }

    // Dequeue element from queue
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    // Get front element
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Check if queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    // Display queue elements
    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        stack<int> temp = s2;
        stack<int> rev;
        while (!temp.empty()) {
            rev.push(temp.top());
            temp.pop();
        }
        temp = s1;
        while (!temp.empty()) {
            rev.push(temp.top());
            temp.pop();
        }
        while (!rev.empty()) {
            cout << rev.top() << " -> ";
            rev.pop();
        }
        cout << "NULL" << endl;
    }
};

int main() {
    QueueUsingStack queue;
    int choice, value;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout << "Front Element: " << queue.front() << endl;
                break;
            case 4:
                queue.display();
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