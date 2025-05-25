#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<string> result;

void backtrack(string s) {
    if (s.size() == N) {
        int count = 0;
        for (int i = 0; i <= N - K; i++) {
            if (s.substr(i, K) == string(K, 'A')) {
                count++;
                if (count > 1) return; 
            }
        }
        if (count == 1) result.push_back(s);
        return;
    }
    backtrack(s + 'A');
    backtrack(s + 'B');
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
   
    if (K > N) {
        cout << "0\n";
        return 0;
    }

    backtrack("");
    cout << result.size() << '\n';
    for (const string &s : result) cout << s << '\n';
    return 0;
}

