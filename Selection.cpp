#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> selection_sort(std::vector<int> arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        std::swap(arr[i], arr[min_idx]);
    }
    
    return arr;
}

int main() {
    std::ifstream inputFile("data.txt");
    std::ofstream outputFile("resultSelection.txt");
    
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }
    
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }
    
    std::vector<int> arr;
    int num;
    while (inputFile >> num) {
        arr.push_back(num);
    }
    
    std::vector<int> sorted_arr = selection_sort(arr);
    
    for (int i = 0; i < sorted_arr.size(); i++) {
        outputFile << sorted_arr[i] << " ";
    }
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}
