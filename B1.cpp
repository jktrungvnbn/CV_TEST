
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int partition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}


void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

int main() {
    const int SIZE = 100;
    int arr[SIZE];

    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    cout << "mang ban dau :\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, SIZE - 1);

    cout << "Mang sau sap xep :\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
