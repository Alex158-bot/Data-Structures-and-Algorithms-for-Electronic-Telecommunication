#include <bits/stdc++.h>
using namespace std;

void generateAB(string &s, int n, int index) {
    if (index == n) {
        cout << s << " ";
        return;
    }
    s[index] = 'A';
    generateAB(s, n, index + 1);
    s[index] = 'B';
    generateAB(s, n, index + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s(n, 'A');
        generateAB(s, n, 0);
        cout << "\n";
    }
    return 0;
}

