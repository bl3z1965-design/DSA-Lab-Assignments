// 2) Develop a menu driven program demonstrating the following operations on Circular Queues:
// enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>
using namespace std;
#define MAX_SIZE 10

int Queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty(){
    return(front == -1);
}

bool isFull(){
    return((rear + 1) % MAX_SIZE == front);
}

void enqueue(int value){
    if(isFull()){
        cout << "Queue Overflow! Cannot enqueue " << value << endl;
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX_SIZE;
    Queue[rear] = value;
}

void dequeue(){
    if(isEmpty()){
        cout << "Queue Underflow! Cannot Dequeque Queue is empty" << endl;
        return;
    }

    cout << Queue[front] << " Dequeued" << endl;

    if (front == rear){
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % MAX_SIZE;
}

void display(){
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Queue: ";
    int i = front;
    while(true){
        cout << Queue[i] << " ";
        if(i == rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    cout << endl;
}

void peek(){
    if(isEmpty()){
        cout << "Queue Underflow! Cannot Dequeque Queue is empty" << endl;
        return;
    }
    cout << "Front of the element: " << Queue[front] << endl;
}

int main(){
    int choice = 0;
    while(choice != 7){
        cout << "---MENU---" << endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Peek(Front Element)" << endl;
        cout << "4.isEmpty"  << endl;
        cout << "5.isFull" << endl;
        cout << "6.Display" << endl;
        cout << "7.Exit" << endl;
        cout << "Choose an option from th Menu (1-7): ";
        cin >> choice;
        switch(choice){
            case 1:
                int n;
                cout << "Enter a value to Enqueue: ";
                cin >> n;
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                if(isEmpty())
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Queue is not Empty" << endl;
                break;
            case 5:
                if(isFull())
                    cout << "Queue is Full" << endl;
                else
                    cout << "Queue is not Full" << endl;
                break;
            case 6:
                display();
                break;
            case 7:
                cout << "Exiting the Menu" << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}
