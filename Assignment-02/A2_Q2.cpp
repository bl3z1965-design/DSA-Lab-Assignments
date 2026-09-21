// 2) Bubble Sort is the simplest sorting algorithm that works by repeatedly
// swapping the adjacent elements if they are in the wrong order. Code the Bubble sort
// with the following elements:
// 64 34 25 12 22 11 90

#include <iostream>
using namespace std;

void BubbleSort(int Array[], int size){
    for(int i = 0; i < size - 1; i++){
        for( int j = 0; j < size - i -1; j++){
            if (Array[j] > Array[j + 1]){
                int temp = Array[j + 1];
                Array[j + 1] = Array[j];
                Array[j] = temp;
            }
        }
    }
}

int main(){

    int Array[7] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(Array)/sizeof(Array[0]);

    cout << "Original Array: ";
    for(int i = 0; i < size; i++){
        cout << Array[i] << " ";
    }

    BubbleSort(Array, size);

    cout << "\nSorted Array: ";
    for(int i = 0; i < size; i++){
        cout << Array[i] << " ";
    }

    return 0;
}