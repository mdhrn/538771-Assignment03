// g++ -std=c++17 -Wall -Wextra problem2.cpp -o problem2
#include <iostream>

struct DynArray {
    int* data ; // pointer to heap - allocated buffer
    int size ; // number of elements in use
    int capacity ; // total allocated slots
};

// O(1)
// fixed number of operations, no loops and no recussion (direct value assignment and allocating initial buffer)
// 1. Initialize array with capacity=2, size=0, allocate heap buffer
void initArray(DynArray& a) {
    a.capacity = 2;
    a.size = 0;
    a.data = new int[a.capacity];
}

// O(1)
// releasing memory and resetting value takes constant time
// 2. Release heap buffer and reset size and capacity to 0
void freeArray(DynArray& a) {
    delete[] a.data;
    a.data = nullptr;
    a.size = 0;
    a.capacity = 0;
}

// O(1)
// adding element to the end of array is constant time
// 3. Append value, double capacity if needed
void pushBack(DynArray& a, int value) {
    if (a.size == a.capacity) {
        // Double the capacity
        int newCapacity = a.capacity * 2;
        int* newData = new int[newCapacity];
        // Copy old data
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];
        }
        // Free old buffer
        delete[] a.data;
        // Update pointer and capacity
        a.data = newData;
        a.capacity = newCapacity;
    }
    a.data[a.size] = value;
    a.size++;
}

// O(n)
// in worst case, inserting at index 0 requires shifting all n elements in array one slot to right
// 4. Insert value at position index, shift elements >= index one slot right
void insertAt(DynArray& a, int index, int value) {
    // Grow if necessary
    if (a.size == a.capacity) {
        int newCapacity = a.capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];
        }
        delete[] a.data;
        a.data = newData;
        a.capacity = newCapacity;
    }
    
    // Shift elements to the right
    for (int i = a.size; i > index; i--) {
        a.data[i] = a.data[i - 1];
    }
    
    // Insert the value
    a.data[index] = value;
    a.size++;
}

// O(n)
// in worst case, removing at index 0 requires shifting all n-1 subsequent elements one slot to left
// 5. Remove element at position index, shift subsequent elements left
void removeAt(DynArray& a, int index) {
    // Shift elements to the left
    for (int i = index; i < a.size - 1; i++) {
        a.data[i] = a.data[i + 1];
    }
    a.size--;
}

// O(1)
// in array we can do direct access at any index without iteration
// 6. Return element at index
int getAt(const DynArray& a, int index) {
    return a.data[index];
}

// O(1)
// direct memory assignment at index is an instant operation
// 7. Set element at index to value
void setAt(DynArray& a, int index, int value) {
    a.data[index] = value;
}

// O(n)
// to print every single element in array we need to iterate through 0 to size-1
// 8. Print in format: [10, 20, 30] (size=3, cap=4)
void printDynArr(const DynArray& a) {
    std::cout << "[";
    for (int i = 0; i < a.size; i++) {
        if (i > 0) std::cout << ", ";
        std::cout << a.data[i];
    }
    std::cout << "] (size=" << a.size << ", cap=" << a.capacity << ")" << std::endl;
}

int main(){
    DynArray arr;
    initArray(arr);

    // 1. pushback until resize is triggered
    for (int i = 1; i <= 5; i++) {
        pushBack(arr, i * 10);

    }
    
    printDynArr(arr);

    // 2. insertAt index 2
    insertAt(arr, 2, 25);
    printDynArr(arr);

    // 3. removeAt index 0
    removeAt(arr, 0);
    printDynArr(arr);

    // 4. getAt / setAt index 3
    std::cout << "Element at index 2: " << getAt(arr, 2) << std::endl;

    setAt(arr, 2, 99);
    printDynArr(arr);

    freeArray(arr);

}
