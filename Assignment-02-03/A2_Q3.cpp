// 3) Design the Logic to Find a Missing Number in a Sorted Array. Given an array of
// n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted
// Array
// (a) Linear time
// (b) Using binary search.

#include <iostream>
using namespace std;

void LinearSearch(int Array[], int size){
    for(int i = 0; i < size - 1; i++){
        if(Array[i] != i + 1){
            cout << "Missing number is: " << i + 1 << endl;
            return;
        }
    }
    cout << "Missing number is: " << size << endl;
}

void BinarySearch(int Array[], int size){
    int min = 0, max = size - 2;
    while(min <= max){
        int mid = (min + max)/2;
        if(Array[mid] == mid + 1)
            min = mid + 1;
        else
            max = mid - 1;
    }
    cout << "Missing number is: " << min + 1 << endl;
}

int main(){
    int Array[100] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    int choice;
    cout << "Choose '1' for Linear Search or '2' for Binary Search: ";
    cin >> choice;
    switch(choice){
        case 1:
            LinearSearch(Array, 10);
            break;
        case 2:
            BinarySearch(Array, 10);
            break;
        default:
            cout << "Invalid Choice" << endl;
    }
    return 0;
}