/*
    Programmer: Hershey Beatrice A. Marbeda
    Instructor: Dr. Steven Carver
    Course: CSCI 202: Data Structures and Algorithm
    College: Ivy Tech Community College
 
    Assignment: M01.2: Efficiency
    Purpose: to demonstrate different Big O notation or efficient a code is
 
    Example Code Reference: https://www.geeksforgeeks.org/analysis-algorithms-big-o-analysis/
 */

#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;

const int N = 3; // Size for the matrix

/*
Ranking based on efficiency
     1. O(1) - Constant Time or O(n) - Linear Time
     2. O(log n) - Logarithmic Time
     3. O(n^2) - Quadratic Time
     4. O(n^3) - Cubic Time
     5. O(2^n) - Exponential Time
 */

// Function Prototypes
bool findElement(int arr[], int n, int key);
int binarySearch(int arr[], int l, int r, int x);
void bubbleSort(int arr[], int n);
void multiply(int mat1[][N], int mat2[][N], int res[][N]);
void generateSubsets(int arr[], int n);

int main()
{
    // Table Heading
    cout << string(100, '*') << endl
         << "\t\t\t\t\t\t\tM01-Programming #1.2: Efficiency (Big O)" << endl
         << string(100, '*') << endl
         << "Welcome to Big O Example Codes from Geeks!\n\n";
    
    // O(n) - Linear Time
    int arr1[] = {31, 0, 10, 3, 5};
    int key = 3;
    clock_t start = clock(); // Start timing
    cout << "Testing O(n) - Linear Time (findElement):" << endl;
    bool found = findElement(arr1, 5, key);
    
    cout << "Element " << key << " found: ";
    if (found)
    {
        cout << "Yes" << endl;
    }
    
    else
    {
        cout << "No" << endl;
    }
    cout << "Time taken: " << fixed << setprecision(8) << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;
    
    // O(log n) - Logarithmic Time
    int arr2[] = {31, 10, 1, 4, 55}; // Must be sorted for binary search
    key = 4;
    cout << "\nTesting O(log n) - Logarithmic Time (binarySearch):" << endl;
    int result = binarySearch(arr2, 0, 4, key);
    cout << "Element " << key << " found at index: ";
    if (result != -1)
    {
        cout << result << endl;
    }
    
    else
    {
        cout << "Not found" << endl;
    }
    cout << "Time taken: " << fixed << setprecision(8) << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;
    
    // O(n^2) - Quadratic Time
    int arr3[] = {5, 1, 4, 2, 8};
    cout << "\nTesting O(n^2) - Quadratic Time (bubbleSort):" << endl;
    bubbleSort(arr3, 5);
    cout << "Sorted elements: ";
    for (int num : arr3)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "Time taken: " << fixed << setprecision(8) << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;
    
    // O(n^3) - Cubic Time
    int mat1[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int res[N][N]; // Resultant matrix
    cout << "\nTesting O(n^3) - Cubic Time (matrix multiplication):" << endl;
    multiply(mat1, mat2, res);
    cout << "Resultant matrix after multiplication:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Time taken: " << fixed << setprecision(8) << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;
    
    // O(2^n) - Exponential Time
    int arr4[] = {1, 2, 3};
    cout << "\nTesting O(2^n) - Exponential Time (generateSubsets):" << endl;
    generateSubsets(arr4, 3);
    cout << "Time taken: " << fixed << setprecision(8) << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds\n\n\n";

    return 0;
}

// O(n) - Linear Time
bool findElement(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}

// O(log n) - Logarithmic Time
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

    // O(n^2) - Quadratic Time
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// O(n^3) - Cubic Time
void multiply(int mat1[][N], int mat2[][N], int res[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// O(2^n) - Exponential Time
void generateSubsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++) // 2^n combinations
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

