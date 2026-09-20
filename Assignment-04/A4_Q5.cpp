// 5) Write a program to implement a stack using (a) Two queues and (b) One Queue.

#include <iostream>
using namespace std;

class Queue{

    private: 
        char arr[256];
        int front;
        int rear;

    public:
        Queue() : front(-1), rear(-1) {}

        bool isEmpty(){
            return(front == -1 || front > rear);
        }

        bool isFull(){
            return(rear == 255);
        }

        void enqueue(char value){
            if(isFull())
                return;
            
            if(front == -1)
                front = 0;
            
            rear++;
            arr[rear] = value;
        }

        void dequeue(){
            if(isEmpty())
                return;
            
            front++;

            if(front > rear){
                front = -1;
                rear = -1;
            }
        }

        char peek(){
            return arr[front];
        }
};

class StackTwoQueue{
    private:
        Queue q1, q2;

    public:
        void push(){
            
        }

};