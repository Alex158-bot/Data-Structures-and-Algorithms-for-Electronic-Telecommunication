#include <iostream>
#include <vector>
using namespace std;

void generatePartitions(int n, int maxVal, vector<int>& current) {
    if (n == 0) {
        cout << "(";
        for (size_t i = 0; i < current.size(); ++i) {
            if (i > 0) cout << " ";
            cout << current[i];
        }
        cout << ")"<<" ";
        return;
    }
    
    for (int i = min(n, maxVal); i >= 1; --i) {
        current.push_back(i);
        generatePartitions(n - i, i, current);
        current.pop_back();
    }
}

void solve(int N) {
    vector<int> current;
    generatePartitions(N, N, current);
    cout<<endl;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        solve(N);
    }
    return 0;
}
