// 5) Write a program to find sum of every row and every column in a two-dimensional
// array
#include <iostream>
using namespace std;

int main(){
    int arr[100][100], rows, columns;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of rows: ";
    cin >> columns;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << "Enter element " << i << j << ": ";
            cin >> arr[i][j];
        }
    }
    cout << "\nDisplaying Array: " << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Sum of rows:" << endl;
    for(int i = 0; i < rows; i++){
        int sum = 0;
        for(int j = 0; j < columns; j++){
            sum += arr[i][j];
        }
        cout << "Sum of Row " << i+1 << ": " << sum << endl;
    }
    cout << "Sum of columns:" << endl;
    for(int i = 0; i < columns; i++){
        int sum = 0;
        for(int j = 0; j < rows; j++){
            sum += arr[j][i];
        }
        cout << "Sum of Column " << i+1 << ": " << sum << endl;
    }
    return 0;
}