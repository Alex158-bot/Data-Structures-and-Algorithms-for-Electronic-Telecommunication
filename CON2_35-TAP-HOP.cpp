#include <bits/stdc++.h>
using namespace std;

int countSets(int n, int k, int s, int start = 1, int sum = 0) {
    if (k == 0) return sum == s;
    if (sum >= s) return 0;

    int ways = 0;
    for (int i = start; i <= n; i++) {
        ways += countSets(n, k - 1, s, i + 1, sum + i);
    }
    return ways;
}

int main() {
    
    while (true) {
        int n, k, s; 
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) break;
        cout << countSets(n, k, s) << endl;
    }
    return 0;
}


