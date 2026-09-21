// 2. Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.”

#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Stack{
    private:
        char Array[MAX_SIZE];
        int top;

    public:
        Stack() : top(-1){}

        bool isEmpty(){
            return(top == -1);
        }

        bool isFull(){
            return(top == MAX_SIZE - 1);
        }

        void push(char value){
            if(isFull()){
                cout << "Stack Overflow" << endl;
                return;
            }
            top++;
            Array[top] = value;
        }

        char pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return '\0';
            }
            return Array[top--];
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

int main(){
    Stack s;
    char string[MAX_SIZE];
    cout << "Enter a string: ";
    cin.getline(string, MAX_SIZE);

    int n = 0;
    while(string[n] != '\0')
        n++;

    for(int i = 0; i < n; i++)
        s.push(string[i]);

    for(int i = 0; i < n; i++)
        string[i] = s.pop();
    string[n] = '\0';
    
    cout << "String in Reverse: " << string << endl;
}