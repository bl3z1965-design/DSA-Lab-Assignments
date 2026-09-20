// 4) Write a program to find first non-repeating character in a string using Queue.

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

char find(char str[]){
    int freq[256] = {0};
    Queue q;
    for(int i = 0; str[i] != '\0'; i++){
        char c = str[i];
        freq[(unsigned char)c]++;
        if(freq[(unsigned char)c] == 1)
            q.enqueue(c);
        while(!q.isEmpty()){
            if(freq[(unsigned char)q.peek()] > 1)
                q.dequeue();
            else
                break;
        }
    }
    
    if(q.isEmpty())
        return '\0';
    
    return q.peek();
}

int main(){
    
    char testString[] = "minimum";
    char result = find(testString);
    
    if(result == '\0')
        cout << "No Non-repeating String found" << endl;
    else
        cout << "First Non-repeating string found: " << result << endl;

    return 0;
}