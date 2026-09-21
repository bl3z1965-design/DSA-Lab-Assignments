// 1) Implement the binary search algorithm regarded as a fast search algorithm
// with run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

void BinarySearch(int Array[], int size, int target){
    int min = 0, max = size - 1;
    while(min <= max){
        int mid = (min + max)/2;
        if (Array[mid] == target){
            cout << target << " found at position " << mid+1 << endl;
            return;
        }
        else if (Array[mid] < target)
            min = mid + 1; 
        else if (Array[mid] > target)
            max = mid - 1;
    }
    cout << target << " not found" << endl;
}

int main(){

    int arr[100], n, target;
    cout << "Enter the size of the array(1-100): ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Enter the element you want to search: ";
    cin >> target;

    BinarySearch(arr, n, target);

    return 0;
}