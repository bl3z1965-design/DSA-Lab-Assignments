// 5. Write a program for the evaluation of a Postfix expression.

#include <iostream>
#include <cmath>
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

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return 0;
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

        int peek(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return 0;
            }
            return Array[top];
        }
};

bool isNumeric(char ch){
    return((ch >= '0' && ch <= '9'));
}

bool isOperator(char ch){
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int postfixEval(char postfix[]){
    Stack s;
    for(int i = 0; postfix[i] != '\0'; i++){
        char ch = postfix[i];
        if(isNumeric(ch))
            s.push(ch - '0');
        else if(isOperator(ch)){
            int val2 = s.pop();
            int val1 = s.pop();

            switch(ch)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            case '^':
                s.push(pow(val1, val2));
                break;
            default:
                break;
            }
        }
    }
    return s.peek();
}

int main() {
    char postfix[MAX_SIZE];
    cout << "Enter Postfix Expression: ";
    cin.getline(postfix, MAX_SIZE);

    cout << "Postfix Evaluation: " << postfixEval(postfix) << endl;

    return 0;
}