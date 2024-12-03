#include<iostream>
using namespace std;

class circularQueue{
    private:
        int n;
        int* cirQueue;
        int front;
        int rear;

    public:
        circularQueue(int n){
            this->n = n;
            cirQueue = new int[n];
            front = -1;
            rear = -1;
        }
        ~circularQueue(){
            delete[] cirQueue;
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull(){
            if((rear+1)%n == front){
                return true;
            }
            else{
                return false;
            }
        }

        bool enqueue(int val){
            if(isFull()){
                cout << "Circular Queue is full. Can't enqueue." << endl;
                return false;
            }
            else if(front == -1 && rear == -1){
                front = 0;
                rear = 0;
                cirQueue[front] = val;
                return true;
            }
            else{
                rear = (rear+1)%n;
                cirQueue[rear] = val;
                return true;
            }
        }

        bool dequeue(){
            if(isEmpty()){
                cout << "Circular queue is empty. Can't dequeue." << endl;
                return false;
            }
            else if(front == rear){
                front = -1;
                rear = -1;

                return true;
            }
            else{
                front = (front+1)%n;
                return true;
            }
        }

        int count(){
            if(isEmpty()){
                return 0;
            }
            else{
                if (rear >= front) {
                    return (rear - front + 1);
                } else {
                    return (n - front + rear + 1);
                }
            }
        }
        
        int peek(){
            if(isEmpty()){
                return -1;
            }
            else{
                return cirQueue[front];
            }
        }

        void printCQ() {
            if (isEmpty()) {
                cout << "Circular Queue is empty." << endl;
                return;
            }

            cout << "Circular Queue: ";
            if (front <= rear) {
                for (int i = front; i <= rear; ++i) {
                    cout << cirQueue[i] << " -> ";
                }
            } 
            else {
                for (int i = front; i < n; ++i) {
                    cout << cirQueue[i] << " -> ";
                }
                for (int i = 0; i <= rear; ++i) {
                    cout << cirQueue[i] << " -> ";
                }
            }
            cout << "End" << endl;
        }

};

int main(){
    int n;
    cout << "Enter capacity of circular queue: ";
    cin >> n;

    circularQueue* userCirQueue = new circularQueue(n);
    if(userCirQueue == nullptr){
        cout << "Couldn't create Circular Queue." << endl;
    }
    else{
        cout << "Circular Queue created successfully" << endl;

        do{
            int ch;
            cout << "Menu:\n\n1. Display\n2. Enqueue\n3. Dequeue\n4. Count\n5. Peek\n6. Exit" << endl;
            cout << "Enter menu choice (1-6):";
            cin >> ch;

            switch(ch){
                case 1:
                    // Display
                    userCirQueue->printCQ();
                    break;
                
                case 2:
                    // Enqueue
                    int val;
                    cout << "Enter element to be enuqueued: ";
                    cin >> val;

                    if(userCirQueue->enqueue(val)){
                        cout << "Enqueue successful." << endl;
                    }
                    else{
                        cout << "Couldn't enqueue." << endl;
                    }
                    break;
                
                case 3:
                    // Dequeue
                    if(userCirQueue->dequeue()){
                        cout << "Dequeue successful." << endl;
                    }
                    else{
                        cout << "Dequeue unsuccessful." << endl;
                    }
                    break;

                case 4:
                    // Count
                    cout << userCirQueue->count() << endl;
                    break;
                
                case 5:
                    // Peek
                    if(userCirQueue->peek() == -1){
                        cout << "Empty queue." << endl;
                    }
                    else{
                        cout << "Peek: " << userCirQueue->peek() << endl;
                    }
                    break;

                case 6:
                    // Exit
                    cout << "Exiting the program." << endl;
                    break;
                
                default:
                    cout << "Invalid choice." << endl;
            }
                if(ch == 6){
                    break;
                }
        } while(true);
    }

    delete userCirQueue;
    userCirQueue = nullptr;

    return 0;
}