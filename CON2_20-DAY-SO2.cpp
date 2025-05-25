#include <iostream>
#include <vector>
using namespace std;

void printTriangle(vector<int>& A) {
    vector<vector<int>> triangle;
    triangle.reserve(A.size());
    triangle.push_back(A);
    
    for (size_t i = A.size(); i > 1; i--) {
        vector<int> nextRow;
        nextRow.reserve(i - 1);
        for (size_t j = 0; j < i - 1; j++) {
            nextRow.push_back(triangle.back()[j] + triangle.back()[j + 1]);
        }
        triangle.push_back(move(nextRow));
    }
    
    for (int i = triangle.size() - 1; i >= 0; i--) {
        cout << "[";
        for (size_t j = 0; j < triangle[i].size(); j++) {
            cout << triangle[i][j];
            if (j < triangle[i].size() - 1) cout << " ";
        }
        cout << "]";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int& x : A) {
            cin >> x;
        }
        printTriangle(A);
    }
    return 0;
}

