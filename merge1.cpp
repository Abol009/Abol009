#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void mergeArray(vector<int> &arr, int low, int mid, int high) {
    int i=low, j=mid+1, k=low;
    vector<int> temp(arr.size());

    while(i<=mid && j<=high) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int s=low; s<=high; s++) {
        arr[s] = temp[s];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    int mid;

    if(low < high) {
        mid = (low+high)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        mergeArray(arr, low, mid, high);
    }
}

int main() {
    ifstream inputFile("data.txt");
    ofstream outputFile("resultMerge.txt");

    int n;
    inputFile >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        inputFile >> v[i];
    }

    mergeSort(v, 0, n-1);

    outputFile << "Output : \n";
    for(int i=0; i<n; i++) {
        outputFile << v[i] << " ";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
