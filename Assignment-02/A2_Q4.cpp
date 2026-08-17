// 4) String Related Programs 
// (a) Write a program to concatenate one string to another string. 
// (b) Write a program to reverse a string. 
// (c) Write a program to delete all the vowels from the string. 
// (d) Write a program to sort the strings in alphabetical order. 
// (e) Write a program to convert a character from uppercase to lowercase.

#include <iostream>
// #include <string>
using namespace std;

void concatenate(char str1[], int maximum, char str2[]) {
    int i = 0;
    while(str1[i] != '\0') {
        i++;
    }

    int j = 0;
    while(str2[j] != 0 && i < maximum -1) {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str2[j] = '\0';
}

int main() {
    char str1[100], str2[50];

    cout << "Enter the first string: ";
    cin.getline(str1, 90);

    cout << "Enter the second string: ";
    cin.getline(str2, 40);

    concatenate(str1, 100, str2);

    cout << "Concatenated: " << str1 << endl;
    return 0;
}