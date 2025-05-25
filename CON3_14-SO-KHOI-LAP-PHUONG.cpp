#include <bits/stdc++.h>
using namespace std;

bool isCube(long long x) {
    if (x < 0) return false;
    long long r = round(cbrt(x));
    return r * r * r == x;
}

long long findLargestCube(const string &s) {
    long long maxCube = -1;
    int len = s.length();
    unordered_set<long long> cubes;

    // T?o t?t c? các s? có th? t? chu?i và ki?m tra xem chúng có ph?i là l?p phuong không
    for (int mask = 1; mask < (1 << len); ++mask) {
        string numStr;
        for (int i = 0; i < len; ++i) {
            if (mask & (1 << i)) {
                numStr += s[i];
            }
        }
        if (numStr[0] == '0' && numStr.size() > 1) continue; // B? qua các s? b?t d?u b?ng '0'
        long long num = stoll(numStr);
        if (isCube(num)) {
            cubes.insert(num);
        }
    }

    // Tìm s? l?n nh?t trong t?p h?p các l?p phuong
    for (auto cube : cubes) {
        if (cube > maxCube) {
            maxCube = cube;
        }
    }

    return maxCube;
}

int main() {
    
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        string N; cin >> N;
        cout << findLargestCube(N) << "\n";
    }
    return 0;
}
