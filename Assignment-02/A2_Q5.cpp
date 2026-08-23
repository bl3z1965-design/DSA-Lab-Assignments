// 5) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
// 𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming an array is used to store elements of the following matrices,
// implement an efficient way that reduces the space requirement.
// (a) Diagonal Matrix.
// (b) Tri-diagonal Matrix.
// (c) Lower triangular Matrix.
// (d) Upper triangular Matrix.
// (e) Symmetric Matrix

#include <iostream>
using namespace std;

const int MAX_N = 10;
class DiagonalMatrix {
    int arr[MAX_N];
    int n;
public:
    DiagonalMatrix(int size) : n(size) {
        for (int i = 0; i < n; i++) arr[i] = 0;
    }

    void set(int i, int j, int value) {
        if (i == j) arr[i] = value;
        else cout << "Invalid: off-diagonal elements are always 0\n";
    }

    int get(int i, int j) {
        return (i == j) ? arr[i] : 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << "\t";
            cout << "\n";
        }
    }
};

class TriDiagonalMatrix {
    int arr[3 * MAX_N];
    int n;
public:
    TriDiagonalMatrix(int size) : n(size) {
        for (int i = 0; i < 3 * n; i++) arr[i] = 0;
    }

    void set(int i, int j, int value) {
        if (i - j <= 1 && j - i <= 1)
            arr[2 * i + j] = value;
        else
            cout << "Invalid: outside tri-diagonal band\n";
    }

    int get(int i, int j) {
        if (i - j <= 1 && j - i <= 1)
            return arr[2 * i + j];
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << "\t";
            cout << "\n";
        }
    }
};

class LowerTriangularMatrix {
    int arr[MAX_N * (MAX_N + 1) / 2];
    int n;
public:
    LowerTriangularMatrix(int size) : n(size) {
        for (int i = 0; i < n * (n + 1) / 2; i++) arr[i] = 0;
    }

    void set(int i, int j, int value) {
        if (i >= j)
            arr[i * (i + 1) / 2 + j] = value;
        else
            cout << "Invalid: upper part is always 0\n";
    }

    int get(int i, int j) {
        if (i >= j) return arr[i * (i + 1) / 2 + j];
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << "\t";
            cout << "\n";
        }
    }
};

class UpperTriangularMatrix {
    int arr[MAX_N * (MAX_N + 1) / 2];
    int n;
public:
    UpperTriangularMatrix(int size) : n(size) {
        for (int i = 0; i < n * (n + 1) / 2; i++) arr[i] = 0;
    }

    void set(int i, int j, int value) {
        if (i <= j)
            arr[i * n - (i * (i - 1)) / 2 + (j - i)] = value;
        else
            cout << "Invalid: lower part is always 0\n";
    }

    int get(int i, int j) {
        if (i <= j) return arr[i * n - (i * (i - 1)) / 2 + (j - i)];
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << "\t";
            cout << "\n";
        }
    }
};

class SymmetricMatrix {
    int arr[MAX_N * (MAX_N + 1) / 2];
    int n;
public:
    SymmetricMatrix(int size) : n(size) {
        for (int i = 0; i < n * (n + 1) / 2; i++) arr[i] = 0;
    }

    void set(int i, int j, int value) {
        if (i < j) { int t = i; i = j; j = t; }
        arr[i * (i + 1) / 2 + j] = value;
    }

    int get(int i, int j) {
        if (i < j) { int t = i; i = j; j = t; }
        return arr[i * (i + 1) / 2 + j];
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << "\t";
            cout << "\n";
        }
    }
};

int main() {
    int n = 4;

    cout << "===== (a) Diagonal Matrix =====\n";
    DiagonalMatrix dm(n);
    for (int i = 0; i < n; i++) dm.set(i, i, 1);
    dm.display();

    cout << "\n===== (b) Tri-diagonal Matrix =====\n";
    TriDiagonalMatrix tdm(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (abs(i - j) <= 1)
                tdm.set(i, j, 1);
    tdm.display();

    cout << "\n===== (c) Lower Triangular Matrix =====\n";
    LowerTriangularMatrix ltm(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            ltm.set(i, j, 1);
    ltm.display();

    cout << "\n===== (d) Upper Triangular Matrix =====\n";
    UpperTriangularMatrix utm(n);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            utm.set(i, j, 1);
    utm.display();

    cout << "\n===== (e) Symmetric Matrix =====\n";
    SymmetricMatrix sm(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            sm.set(i, j, i + j);
    sm.display();

    return 0;
}