// 3) Write a program interleave the first half of the queue with second half.
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

#include <iostream>
using namespace std;
#define MAX_SIZE 100

int Queue[MAX_SIZE];
int front = -1;
int rear = -1;
int counter = 0;
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
    counter++;
}

int dequeue(){
    if(isEmpty()){
        cout << "Queue Underflow! Cannot Dequeque Queue is empty" << endl;
        return -1;
    }

    int temp = Queue[front];

    if (front == rear){
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % MAX_SIZE;
    counter--;
    return temp;
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

void interleave(){
    int firsthalf[MAX_SIZE];
    int size = counter;
    cout << size;
    if(size % 2 != 0)
        return;
    int half = size/2;
    for(int i = 0; i < half; i++){
        firsthalf[i] = dequeue();
    }
    for(int i = 0; i < half; i++){
        enqueue(firsthalf[i]);
        enqueue(dequeue());
    }
}

int main(){
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    for(int i = 0; i < size; i++){
        int x;
        cout << "Enter Element " << i+1 << ": ";
        cin >> x;
        enqueue(x);
    }
    cout << "Queue before interleave: ";
    display();
    interleave();
    cout << "Queue after interleave: ";
    display();
    return 0;
}
