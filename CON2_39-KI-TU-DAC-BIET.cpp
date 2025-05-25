#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char findNthCharOptimized(const string& s, long long N) {
    long long len = s.size();
    if (N <= len) {
        return s[N - 1];
    }

    while (N > len) {
        long long prev_len = (len - 1) / 2;
        if (N == prev_len + 1) {
            return s[0];
        } else if (N > prev_len + 1) {
            N -= (prev_len + 1);
        }
        len = prev_len;
    }
    return s[N - 1];
}

int main() {
    string s;
    long long N;
    cin >> s >> N;

    cout << findNthCharOptimized(s, N) << endl;

    return 0;
}
