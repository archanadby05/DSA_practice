#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) 
        return -1; // Base case

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid; // Element found
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target); // Search right half
    else
        return binarySearchRecursive(arr, left, mid - 1, target); // Search left half
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearchRecursive(arr, 0, n - 1, target);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
