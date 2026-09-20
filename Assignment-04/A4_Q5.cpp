// 5) Write a program to implement a stack using (a) Two queues and (b) One Queue.

#include <iostream>
using namespace std;

class Queue{

    private: 
        int arr[256];
        int front;
        int rear;
        int count;

    public:
        Queue() : front(-1), rear(-1), count(0) {}

        bool isEmpty(){
            return(front == -1 || front > rear);
        }

        bool isFull(){
            return(rear == 255);
        }

        void enqueue(int value){
            if(isFull())
                return;
            
            if(front == -1)
                front = 0;
            
            rear++;
            arr[rear] = value;
            count++;
        }

        int dequeue(){
            if(isEmpty())
                return -1;
            int temp = arr[front];
            front++;

            if(front > rear){
                front = -1;
                rear = -1;
            }
            count--;
            return temp;
        }

        int peek(){
            return arr[front];
        }

        int size(){
            return count;
        }
};

class StackTwoQueue{
    private:
        Queue q1, q2;

    public:
        void push(int value){
            if(q1.isFull()){
                cout << "Stack Overflow" << endl;
                return;
            }
            q2.enqueue(value);
            while(!q1.isEmpty()){
                q2.enqueue(q1.dequeue());
            }
            Queue temp = q2;
            q2 = q1;
            q1 = temp;
        }

        int pop(){
            if(q1.isEmpty()){
                cout << "Stack Undeflow" << endl;
                return -1;
            }
            return q1.dequeue();
        }

        int top(){
            if(q1.isEmpty()){
                cout << "Stack Undeflow" << endl;
                return -1;
            }
            return q1.peek();
        }
};

class StackOneQueue{
    private:
        Queue q;

    public:
        void push(int value){
            if(q.isFull()){
                cout << "Stack Overflow" << endl;
                return;
            }
            int n = q.size();
            q.enqueue(value);
            for(int i = 0; i < n; i++)
                q.enqueue(q.dequeue());
        }

        int pop(){
            if(q.isEmpty()){
                cout << "Stack Undeflow" << endl;
                return -1;
            }
            return q.dequeue();
        }

        int top(){
            if(q.isEmpty()){
                cout << "Stack Undeflow" << endl;
                return -1;
            }
            return q.peek();
        }
};

int main() {
    cout << "--- Stack using TWO queues ---\n";
    StackTwoQueue s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Top: " << s1.top() << endl;   // 30
    cout << "Pop: " << s1.pop() << endl;   // 30
    cout << "Pop: " << s1.pop() << endl;   // 20
    cout << "Top: " << s1.top() << endl;   // 10

    cout << "\n--- Stack using ONE queue ---\n";
    StackOneQueue s2;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    cout << "Top: " << s2.top() << endl;   // 30
    cout << "Pop: " << s2.pop() << endl;   // 30
    cout << "Pop: " << s2.pop() << endl;   // 20
    cout << "Top: " << s2.top() << endl;   // 10

    return 0;
}