// 1. Develop a menu driven program demonstrating the following operations on a Stack using array:
// (i)push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().

#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Stack{
    private:
        int Array[MAX_SIZE];
        int top;

    public:
        Stack() : top(-1){}

        bool isEmpty(){
            return(top == -1);
        }

        bool isFull(){
            return(top == MAX_SIZE - 1);
        }

        void push(int value){
            if(isFull()){
                cout << "Stack Overflow" << endl;
                return;
            }
            top++;
            Array[top] = value;
        }

        void pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return;
            }
            cout << "Popped Element " << Array[top--] << endl;
        }

        void display(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return;
            }
            cout << "Stack Elements (top to bottom): ";
            for(int i = top; i >= 0; i--)
                cout << Array[i] << " ";
            cout << endl;
        }

        void peek(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return;
            }
            cout << "Top Element: " << Array[top] << endl;
        }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n--- STACK OPERATIONS MENU ---\n";
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                if (s.isEmpty()) 
                    cout << "Stack is Empty" << endl;
                else 
                    cout << "Stack is not Empty" << endl;
                break;
            case 5:
                if (s.isFull()) 
                    cout << "Stack is Full" << endl;
                else 
                    cout << "Stack is not Full" << endl;
                break;
            case 6:
                s.display();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again" << endl;
        }
    } while (choice != 7);

    return 0;
}