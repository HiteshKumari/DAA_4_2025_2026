#include <bits/stdc++.h>
using namespace std;

int operations = 0;
int depth = 0;

void complexRec(int n, int currentDepth) {
    operations++;
    depth = max(depth, currentDepth);

    if (n <= 2) {
        operations++;
        return;
    }

    int p = n;
    while (p > 0) {
        operations++;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operations++;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations++;
    }

    reverse(small.begin(), small.end());
    operations += n;

    complexRec(n / 2, currentDepth + 1);
    complexRec(n / 2, currentDepth + 1);
    complexRec(n / 2, currentDepth + 1);
}

int main() {
    int n = 16;

    auto start = chrono::high_resolution_clock::now();
    complexRec(n, 1);
    auto end = chrono::high_resolution_clock::now();

    int timeTaken =
        chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout <<"Number of operations= "<< operations << endl;
    cout <<"Depth= " << depth << endl;
    cout <<"Time taken is "<< timeTaken<<" ms" << endl;

    return 0;
}

//Name: Hitesh Kumari
//UID: 24BCS10099
//Recurrence Relation: T(n) = 3T(n/2) + O(n log n)
//Time Complexity: T(n) = Θ(n^log2(3)) ≈ Θ(n^1.585)