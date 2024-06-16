#include <iostream>
#include <fstream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    ifstream inputFile("data.txt");
    ofstream outputFile("resultBubble.txt");

    int n;
    inputFile >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        inputFile >> arr[i];
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        outputFile << arr[i] << " ";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
