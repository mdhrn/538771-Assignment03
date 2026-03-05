// g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3
#include <iostream>

using namespace std;

// O(n)
// 1. Linear search --> return index of target in array or -1 if not found
int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// 2. Binary search (iterative) --> returns index of target in sorted array or -1 if not found
int binarySearch(int* arr, int n, int target) {
    int lo = 0;
    int hi = n - 1;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    return -1;
}

// 3. Generate sorted array of n distinct integers {0, 2, 4, 6, ..., 2(n-1)}
int* generateSortedArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 2 * i;  // Generate even numbers: 0, 2, 4, 6, ...
    }
    return arr;
}

int main() {
    int sizes[] = {10, 100, 1000};
    
    for (int size : sizes) {
        cout << "\n ARRAY SIZE : " << size << endl;
        
        // Generate sorted array
        int* arr = generateSortedArray(size);
        
        // Test 1: Search for element at midpoint (exists)
        int midIndex = size / 2;
        int midValue = arr[midIndex];
        
        cout << "\nTest 1: Search for value at midpoint (index " << midIndex 
                  << ", value " << midValue << ")" << endl;
        
        int linearResult = linearSearch(arr, size, midValue);
        int binaryResult = binarySearch(arr, size, midValue);
        
        cout << "  linearSearch returned: " << linearResult << endl;
        cout << "  binarySearch returned: " << binaryResult << endl;
        cout << "  Match: " << (linearResult == binaryResult ? "YES" : "NO") << endl;
        
        // Test 2: Search for value that does not exist
        int notExistValue = -1;  // -1 does not exist in the array
        
        cout << "\nTest 2: Search for value that does not exist (" 
                  << notExistValue << ")" << endl;
        
        linearResult = linearSearch(arr, size, notExistValue);
        binaryResult = binarySearch(arr, size, notExistValue);
        
        cout << "  linearSearch returned: " << linearResult << endl;
        cout << "  binarySearch returned: " << binaryResult << endl;
        cout << "  Match: " << (linearResult == binaryResult ? "YES" : "NO") << endl;
        
        // Free the allocated array
        delete[] arr;
    }
    
    return 0;
}
