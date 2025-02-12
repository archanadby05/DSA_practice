#include <iostream>
using namespace std;

class Deque {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    // Insert at front
    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Insert at rear
    void insertRear(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Delete from front
    void deleteFront() {
        if (!front) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }
        delete temp;
    }

    // Delete from rear
    void deleteRear() {
        if (!rear) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear) {
            rear->next = nullptr;
        } else {
            front = nullptr;
        }
        delete temp;
    }

    // Get front element
    int getFront() {
        return front ? front->data : -1;
    }

    // Get rear element
    int getRear() {
        return rear ? rear->data : -1;
    }

    // Display deque
    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Deque deque;
    int choice, value;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Get Front\n";
        cout << "6. Get Rear\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                deque.insertFront(value);
                break;
            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                deque.insertRear(value);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                cout << "Front Element: " << deque.getFront() << endl;
                break;
            case 6:
                cout << "Rear Element: " << deque.getRear() << endl;
                break;
            case 7:
                deque.display();
                break;
            case 8:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);
    
    return 0;
}