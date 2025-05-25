#include <iostream>
#include <vector>
using namespace std;

int minOperations(const vector<int>& target) {
    int res = target[0];
    for (int i = 1; i < target.size(); ++i)
        if (target[i] > target[i - 1])
            res += target[i] - target[i - 1];
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> target(n);
        for (int i = 0; i < n; ++i)
            cin >> target[i];
        cout << minOperations(target) << endl;
    }
    return 0;
}

