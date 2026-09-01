// 7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an
// inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to
// count the number of inversions in an array.

#include <iostream>
using namespace std;
# define SIZE 100

int main(){

    int Array[SIZE], n, count = 0;

    cout << "Enter the size of array:";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter element " << i+1 <<": ";
        cin >> Array[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(Array[i] > Array[j])
                count ++;
        }
    }

    cout << "Number of inversions: " << count << endl;

    return 0;
}