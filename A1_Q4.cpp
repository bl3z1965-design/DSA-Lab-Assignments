// 4) Implement the logic to
//     a. Reverse the elements of an array
//     b. Find the matrix multiplication
//     c. Find the Transpose of a Matrix
#include <iostream>
using namespace std;
#define MAX_SIZE 100

void reverse(){
    int arr[MAX_SIZE];
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Enter Element " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "\nOriginal Array:";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    int temp, end = n-1;
    for(int i = 0; i < n/2; i++){
        temp = arr[i];
        arr[i] = arr[end];
        arr[end] = temp;
        end--;
    }
    cout << "\nReversed Array:";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void multiplication(){
    int arr1[3][6] = {
    {1, 2, 3, 4, 5, 6},
    {7, 8, 9, 10, 11, 12},
    {13, 14, 15, 16, 17, 18}
    };
    int arr2[6][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25},
    {26, 27, 28, 29, 30}
    };

    cout << "First Array: " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            cout << arr1[i][j] << "\t";
        }
        cout << endl; 
    }
    cout << "Second Array: " << endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            cout << arr2[i][j] << "\t";
        }
        cout << endl; 
    }
    int product[3][5] = {0};
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            for(int k = 0; k < 6; k++){
                product[i][j] += arr1[i][k] * arr2[k][i];
            }
        }
    }
    cout << "Product Matrix:" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            cout << product[i][j] << "\t";
        }
        cout << endl; 
    }
}

void transpose(){
    int arr[4][7] = {
        {1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26, 27, 28}
    };
    int t_arr[7][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 7; j++){
            t_arr[j][i] = arr[i][j];
        }
    }

    cout << "Original Matrix: " << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 7; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl; 
    }
    cout << "Transpose Matrix: " << endl;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 4; j++){
            cout << t_arr[i][j] << "\t";
        }
        cout << endl; 
    }
}
int main(){
    reverse();
    multiplication();
    transpose();
    return 0;
}