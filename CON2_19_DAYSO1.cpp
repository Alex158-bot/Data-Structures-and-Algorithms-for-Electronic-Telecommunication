#include <bits/stdc++.h>
using namespace std;

void generateTriangle(vector<int> &arr) {
    vector<vector<int>> triangle;
    triangle.push_back(arr);
    
    while (triangle.back().size() > 1) {
        vector<int> nextRow;
        vector<int> &prevRow = triangle.back();
        for (size_t i = 0; i < prevRow.size() - 1; ++i) {
            nextRow.push_back(prevRow[i] + prevRow[i + 1]);
        }
        triangle.push_back(nextRow);
    }

    for (const auto &row : triangle) {
        cout << "[";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << triangle[i][j];
        }
        cout << "]\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0;i<n;i++){
        	cin>>arr[i];
		}
        
        generateTriangle(arr);
    }
    return 0;
}

