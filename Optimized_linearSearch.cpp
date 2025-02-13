#include <iostream>
using namespace std;

int optimizedLinearSearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        if (arr[left] == key) return left;
        if (arr[right] == key) return right;
        left++;
        right--;
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the element to search: ";
    cin >> key;
    
    int result = optimizedLinearSearch(arr, n, key);
    
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
