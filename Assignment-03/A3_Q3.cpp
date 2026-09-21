// 3. Write a program that checks if an expression has balanced parentheses.

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

        void pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return;
            }
            Array[top--];
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

        char peek(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return '\0';
            }
            return Array[top];
        }
};

bool check_parentheses(char open, char close){
    return((open == '(' && close == ')') || 
           (open == '[' && close == ']') || 
           (open == '{' && close == '}'));
}

bool balanced_parentheses(char str[]){
    Stack s;
    int size = 0;
    while(str[size] != '\0')
        size++;
    for(int i = 0; i < size; i++){
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{')
            s.push(ch);
        else if(ch == ')' || ch == ']' || ch == '}'){
            if(s.isEmpty() || !check_parentheses(s.peek(), ch))
                return false;
            s.pop();
        }
    }
    return true;
}

int main(){
    Stack s;
    char string[MAX_SIZE];
    cout << "Enter a string: ";
    cin.getline(string, MAX_SIZE);

    if(balanced_parentheses(string))
        cout << "The exprssion has a balanced parantheses" << endl;
    else
        cout << "The exprssion does not have a balanced parantheses" << endl;
}