#include <bits/stdc++.h>

void bubbleSort(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(std::vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; 
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(std::vector<int> &arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void heapify(std::vector<int> &arr, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int> &arr){
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// int getMax(std::vector<int> &arr) {
//     int n = arr.size();
//     int mx = arr[0];
//     for (int i = 1; i < n; i++)
//         if (arr[i] > mx)
//             mx = arr[i];
//     return mx;
// }

// void countSort(std::vector<int> &arr, int exp) {
//     int n = arr.size();
//     std::vector<int> output;
//     int i, count[10] = { 0 };

//     for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
//     for (i = 1; i < 10; i++) count[i] += count[i - 1];
//     for (i = n - 1; i >= 0; i--) {
//         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//         count[(arr[i] / exp) % 10]--;
//     }

//     for (i = 0; i < n; i++) arr[i] = output[i];
// }

// void radixsort(std::vector<int> &arr) {
//     int m = getMax(arr);
//     for (int exp = 1; m / exp > 0; exp *= 10) countSort(arr, exp);
// }

void printArray(std::vector<int> &arr) {
    for (int &val : arr) std::cout << val << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> bs = {5, 1, 4, 2, 8};
    std::vector<int> ss = {64, 25, 12, 22, 11};
    std::vector<int> is = {12, 11, 13, 5, 6};
    std::vector<int> qs = {10, 7, 8, 9, 1, 5};
    std::vector<int> ms = {12, 11, 13, 5, 6, 7};
    std::vector<int> hs = {9, 4, 3, 8, 10, 2, 5};
    // std::vector<int> rs = { 170, 45, 75, 90, 802, 24, 2, 66 };
    bubbleSort(bs);
    selectionSort(ss);
    insertionSort(is);
    quickSort(qs, 0, qs.size() - 1);
    mergeSort(ms, 0, ms.size() - 1);
    heapSort(hs);
    // radixsort(rs);
    printArray(bs); 
    printArray(ss);
    printArray(is);
    printArray(qs);
    printArray(ms);
    printArray(hs);
    // printArray(rs);

    return 0;
}