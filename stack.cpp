#include<iostream>
using namespace std;

class Stack{
    private:
        int n;
        int top;
        int* stack;

    public:
        Stack(int n){
            top = -1;
            this->n = n;
            stack = new int[n];
        }

        ~Stack(){
            delete[] stack;
        }

        bool isFull(){
            if(top == n-1){
                cout << "It's Full." << endl;
                return true;
            }
            else{
                return false;
            }
        }

        bool isEmpty(){
            if(top == -1){
                cout << "It's empty." << endl;
                return true;
            }
            else{
                return false;
            }
        }

        bool push(int val){
            if(isFull()){
                cout << "No space. Stack full." << endl;
                return false;
            }
            else{
                stack[++top] = val;
                return true;
            }   
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack is empty. Cant remove anything." << endl;
                return -1;
            }
            else{
                int x = stack[top];
                --top;
                return x;
            }
        }

        bool remove(int pos) {
            if (pos < 0 || pos > top) {  // Ensure pos is within valid range
                cout << "Invalid index." << endl;
                return false;
            }

            if (isEmpty()) {
                cout << "Stack empty." << endl;
                return false;
            }

            if (pos == top) {
                --top;
                return true;
            }

            for (size_t i = pos; i < top; ++i) {
                stack[i] = stack[i + 1];
            }
            --top;
            return true;
        }

        int peek(){
            if(isEmpty()){
                cout << "Stack is empty." << endl;
                return -1;
            }
            else{
                return stack[top];
            }
        }

        int size(){
            if(top == -1){
                cout << "Stack is empty." << endl;
                return 0;
            }
            else{
                return top+1;
            }
        }

        void printS(){
            if(top == -1){
                cout << "Stack is empty." << endl;
            }
            else{
                cout << "Stack: ";
                for(size_t i{0}; i<=top; ++i){
                    cout << stack[i] << " -> ";
                }
                cout << "Top" << endl;
            }
        }
};

int main(){
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;
        
    Stack* userStack = new Stack(n); 
  
    if(userStack == nullptr){
        cout << "Stack not created." << endl;
    }
    else{
        cout << "Stack created successfully." << endl;

    do{
        int ch;
        cout << "\n1. Display\n2. Push\n3. Pop\n4. Remove\n5. Peek\n6. Size\n7. Exit" << endl << endl;
        cout << "Enter menu choice (1-7): ";
        cin >> ch;

        switch(ch){
            case 1:
                // Display
                userStack->printS();
                break;

            case 2:
                // Insert element
                int val;
                cout << "Enter element to push onto stack: ";
                cin >> val;
                userStack->push(val);
                break;
            
            case 3:
                // Pop element
                int popped = userStack->pop();
                cout << "Popped element: " << popped << endl;
                break;

            case 4:
                // Remove element - index required
                int index;
                cout << "Enter pos of element to be removed: ";
                cin >> index;

                if(userStack->remove(index)){
                    cout << "Element removed successfully." << endl; 
                }
                else{
                    cout << "Couldn't remove element." << endl;
                }
                break;

            case 5:
                // Peek - return topmost element
                cout << "Peek element" << userStack->peek() << endl;
                break;
            case 6:
                // size of stack
                cout << "Size: " << userStack->size() << endl;
                break;

            case 7:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Incorrect input choice." << endl;
        }
        
        if (ch == 7) {
            break; 
        }

    } while (true);

}
    
        delete userStack;
        userStack = nullptr;
    return 0;
}