#include<iostream>
using namespace std;

class Queue{
    private:
        int n;
        int* queue;
        int front;
        int rear;

    public:
        Queue(int n){
            this->n = n;
            queue = new int[n];
            front = -1;
            rear = -1;
        }
        ~Queue(){
            delete[] queue;
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                cout << "Empty queue." << endl;
                return true;
            } 
            else{
                return false;
            }
        }

        bool isFull(){
            if(rear == n-1){
                cout << "Queue is full." << endl;
                return true;
            }
            else{
                return false;
            }
        }

        bool enqueue(int val){
            if(isFull()){
                cout << "Queue is full. Can't enqueue." << endl;
                return false;
            }
            else if(front == -1 && rear == -1){
                front = 0;
                rear = 0;
                queue[front] = val;
                return true;
            }
            else{
                queue[++rear] = val;
                return true;
            }
        }

        bool dequeue(){
            if(isEmpty()){
                cout << "Queue is empty. Can't dequeue." << endl;
                return false;
            }
            else if(front == rear){
                front = -1;
                rear = -1;
                return true;
            }
            else{
                ++front;
                return true;
            }
        }

        int count(){
            if(isEmpty()){
                return 0;
            }
            else{
                return (rear - front + 1);
            }
        }

        int peek(){
            if(isEmpty()){
                return -1;
            }
            else{
                return queue[front];
            }
        }

        void printQ(){
            if(isEmpty()){
                return;
            }
            else{
                cout << "Queue: " << endl;
                for(size_t i{front}; i<=rear; ++i){
                    cout << queue[i] <<" -> ";
                }
                cout << "End" << endl;
                return;
            }
        }

};

int main(){
    int n;
    cout << "Enter queue size: ";
    cin >> n;

    Queue* userQueue = new Queue(n);
    if(userQueue == nullptr){
        cout << "Queue not created." << endl;
    }
    
    else{
        cout << "Queue created successfully" << endl;

        do{
            int ch;
            cout << "Menu:\n\n1. Display\n2. Enqueue\n3. Dequeue\n4. Count\n5. Peek\n6. Exit" << endl;
            cout << "Enter menu choice (1-6):";
            cin >> ch;

            switch(ch){
                case 1:
                    // Display
                    userQueue->printQ();
                    break;
                
                case 2:
                    // Enqueue
                    int val;
                    cout << "Enter element to be enuqueued: ";
                    cin >> val;

                    if(userQueue->enqueue(val)){
                        cout << "Enqueue successful." << endl;
                    }
                    else{
                        cout << "Couldn't enqueue." << endl;
                    }
                    break;
                
                case 3:
                    // Dequeue
                    if(userQueue->dequeue()){
                        cout << "Dequeue successful." << endl;
                    }
                    else{
                        cout << "Dequeue unsuccessful." << endl;
                    }
                    break;

                case 4:
                    // Count
                    cout << userQueue->count() << endl;
                    break;
                
                case 5:
                    // Peek
                    if(userQueue->peek() == -1){
                        cout << "Empty queue." << endl;
                    }
                    else{
                        cout << "Peek: " << userQueue->peek() << endl;
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

    delete userQueue;
    userQueue = nullptr;

    return 0;
}