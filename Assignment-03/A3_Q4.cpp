// 4. Write a program to convert an Infix expression into a Postfix expression.

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

        char peek(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return '\0';
            }
            return Array[top];
        }
};

bool isAlphaNumeric(char ch){
    return((ch >= '0' && ch <= '9') || 
           (ch >= 'a' && ch <= 'z') || 
           (ch >= 'A' && ch <= 'Z'));
}

bool isOperator(char ch){
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence (char ch){
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '^')
        return 3;
    return 0;
}

void infixToPostfix(char infix[]){
    Stack s;
    char postfix[MAX_SIZE];
    int pid = 0;

    for(int i = 0; infix[i] != '\0'; i++){
        char ch = infix[i];
        if(isAlphaNumeric(ch))
            postfix[pid++] = ch;
        else if(ch == '(')
            s.push(ch);
        else if(ch == ')'){
            while(!s.isEmpty() && s.peek() != '(')
                postfix[pid++] = s.pop();
            s.pop();
        }
        else if(isOperator(ch)){
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(ch)){
                if(s.peek() == '^' && ch == '^')
                    break;
                postfix[pid++] = s.pop();
            }
            s.push(ch);
        }
    }

    while(!s.isEmpty())
        postfix[pid++] = s.pop();
    postfix[pid] = '\0';

    cout << "Postfix Expression: " << postfix << endl;
}

int main() {
    char infix[MAX_SIZE];
    cout << "Enter Infix Expression: ";
    cin.getline(infix, MAX_SIZE);

    cout << "Infix Expression: " << infix << endl;
    infixToPostfix(infix);

    return 0;
}