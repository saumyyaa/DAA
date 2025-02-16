#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort (O(n²))
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Merge Sort (O(n log n))
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Binary Search (O(log n))
int binarySearch(vector<int>& arr, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        (arr[mid] < key) ? left = mid + 1 : right = mid - 1;
    }
    return -1;
}

// Function to display the array
void displayArray(vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    
    // Measure Bubble Sort Time
    auto start = high_resolution_clock::now();
    bubbleSort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Bubble Sorted Array: ";
    displayArray(arr);
    cout << "Bubble Sort Execution Time: " << duration.count() << " microseconds\n\n";

    // Reset array and measure Merge Sort Time
    arr = {64, 25, 12, 22, 11};
    start = high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    
    cout << "Merge Sorted Array: ";
    displayArray(arr);
    cout << "Merge Sort Execution Time: " << duration.count() << " microseconds\n\n";

    // Binary Search
    int key = 22;
    int index = binarySearch(arr, 0, arr.size() - 1, key);
    if (index != -1)
        cout << "Element " << key << " found at index " << index << endl;
    else
        cout << "Element " << key << " not found in array\n";

    return 0;
}
