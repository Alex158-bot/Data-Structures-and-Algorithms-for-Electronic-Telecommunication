#include <bits/stdc++.h>
using namespace std;

void nextBinaryString(string &s) {
    size_t pos = s.find_last_of('0');
    if (pos != string::npos) {
        s[pos] = '1';
        fill(s.begin() + pos + 1, s.end(), '0');
    } else {
        fill(s.begin(), s.end(), '0');
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string X;
        cin >> X;
        nextBinaryString(X);
        cout << X << '\n';
    }
    return 0;
}
