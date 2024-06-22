#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void shell_sort(vector<int>& arr) {
    int n = arr.size();
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

void print_steps(vector<int>& arr, ofstream& outFile) {
    int n = arr.size();
    int gap = n / 2;
    while (gap > 0) {
        outFile << "\nStep: Gap = " << gap << endl;
        for (int i = 0; i < n; i++) {
            outFile << arr[i] << " ";
        }
        outFile << endl;
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
    outFile << "\nSorted array:" << endl;
    for (int i = 0; i < n; i++) {
        outFile << arr[i] << " ";
    }
    outFile << endl;
}

int main() {
    ifstream inFile("data.txt");
    ofstream outFile("resultShell.txt");

    vector<int> arr;
    int num;
    while (inFile >> num) {
        arr.push_back(num);
    }

    cout << "Original array:" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    shell_sort(arr);
    print_steps(arr, outFile);

    inFile.close();
    outFile.close();

    return 0;
}