#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void quickSort(vector<int> &arr, int lb, int ub) {
    // base case
    if(lb >= ub)
        return;

    int pivot = lb, l = lb, r = ub, temp;

    
    while(l < r) {
    
        while(arr[l] <= arr[pivot] && l < r) {
            l++;
        }

        while(arr[r] > arr[pivot]) {
            r--;
        }

        if(l < r) {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }
    }

    // swap arr[pivot] and arr[r]
    temp = arr[pivot];
    arr[pivot] = arr[r];
    arr[r] = temp;

    // break arr in two parts
    quickSort(arr, lb, r-1);
    quickSort(arr, r+1, ub);
}

int main() {
    ifstream inputFile("data.txt");
    int n;
    inputFile >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        inputFile >> v[i];
    }

    inputFile.close();

    quickSort(v, 0, n-1);

    ofstream outputFile("result.txt");
    for(int i=0; i<n; i++) {
        outputFile << v[i] << " ";
    }
    outputFile.close();

    cout << "Sorting completed. Check output.txt for sorted numbers." << endl;

    return 0;
}
