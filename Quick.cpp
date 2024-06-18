#include <iostream>
#include <vector>
#include <fstream>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr;

    std::ifstream inputFile("data.txt");
    if(!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    int num;
    while(inputFile >> num) {
        arr.push_back(num);
    }
    inputFile.close();

    quick_sort(arr, 0, arr.size() - 1);

    std::ofstream outputFile("resultQuik.txt");
    if(!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    for (auto num : arr) {
        outputFile << num << " ";
    }
    outputFile.close();

    return 0;
}
