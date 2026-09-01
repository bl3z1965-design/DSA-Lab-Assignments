// 8) Write a program to count the total number of distinct elements in an array of
// length n.

#include <iostream>
using namespace std;
#define SIZE 100

int main(){

    int Array[SIZE], n, count = 0;

    cout << "Enter the size of array:";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter element " << i+1 <<": ";
        cin >> Array[i];
    }

    for(int i = 0; i < n - 1; i++){
        for( int j = 0; j < n - i -1; j++){
            if (Array[j] > Array[j + 1]){
                int temp = Array[j + 1];
                Array[j + 1] = Array[j];
                Array[j] = temp;
            }
        }
    }

    for(int i = 1; i < n; i++){
        if(Array[i] > Array[i-1])
            count++;
    }

    cout << "Total number of unique elements in Array: " << count << endl;

    return 0;

}