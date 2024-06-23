#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void insertionSort(int A[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        j = i - 1;
        int x = A[i];
        while (j > -1 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main() {
    int A[100000], n = 100000;
    ifstream input("data.txt");
    if (!input) {
        cerr << "Unable to open file";
        exit(1);
    }

    for (int i = 0; i < n; i++)
        input >> A[i];
    input.close();

    time_t end, start;
    time(&start);
    insertionSort(A, n);
    time(&end);

    ofstream output("resultInserting.txt");
    for (int i = 0; i < n; i++)
        output << A[i] << endl;
    output.close();

    cout << "Sorting is done and written to output.txt" << endl;
    cout << end - start << " seconds were taken to execute insertion sort" << endl;

    return 0;
}
