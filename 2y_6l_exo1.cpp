#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Heapify a subtree rooted at index i
void heapify(vector<int>& heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;
    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

// Build a heap in linear time
void buildHeap(vector<int>& heap) {
    for (int i = heap.size() / 2 - 1; i >= 0; i--)
        heapify(heap, heap.size(), i);
}

// Insert elements one by one into a heap
void insertIntoHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    int i = heap.size() - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> data(N);
    for (int i = 0; i < N; i++)
        data[i] = rand() % 100;

    // Insert elements one by one
    vector<int> heap1;
    for (int x : data)
        insertIntoHeap(heap1, x);
    cout << "Heap after inserting one by one: ";
    for (int x : heap1) cout << x << " ";
    cout << endl;

    // Build a heap in linear time
    vector<int> heap2 = data;
    buildHeap(heap2);
    cout << "Heap after building in linear time: ";
    for (int x : heap2) cout << x << " ";
    cout << endl;

    return 0;
}
