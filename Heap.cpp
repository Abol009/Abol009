#include <iostream>
#include <fstream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < n && arr[i] < arr[l])
        largest = l;
    
    if (r < n && arr[largest] < arr[r])
        largest = r;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    ifstream inputFile("data.txt");
    ofstream outputFile("resultHeap.txt");
    
    int n;
    inputFile >> n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        inputFile >> arr[i];
    }
    
    heap_sort(arr, n);
    
    for(int i=0; i<n; i++){
        outputFile << arr[i] << " ";
    }
    
    inputFile.close();
    outputFile.close();

    return 0;
}