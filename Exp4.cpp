#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int heap[MAX];
int heapSize = 0;

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insert(int val) {
    if (heapSize == MAX) {
        cout << "Heap Full\n";
        return;
    }
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
}

bool search(int key) {
    for (int i = 0; i < heapSize; i++) {
        if (heap[i] == key)
            return true;
    }
    return false;
}

void deleteAny(int key) {
    int index = -1;
    for (int i = 0; i < heapSize; i++) {
        if (heap[i] == key) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Element Not Found\n";
        return;
    }

    heap[index] = heap[heapSize - 1];
    heapSize--;

    heapifyDown(index);
    heapifyUp(index);
}

void printHeap() {
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    insert(2);
    insert(4);
    insert(6);
    insert(1);

    printHeap();

    if (search(4))
        cout << "Element Found\n";
    else
        cout << "Element Not Found\n";

    deleteAny(4);
    printHeap();

    return 0;
}
