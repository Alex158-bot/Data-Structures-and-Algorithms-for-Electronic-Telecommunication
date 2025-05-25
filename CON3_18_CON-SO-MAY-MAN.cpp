#include<bits/stdc++.h>

using namespace std;

void findLuckyNumber(int n) {
    int count7 = n / 7;
    while (count7 >= 0) {
        int remaining = n - count7 * 7;
        if (remaining % 4 == 0) {
            int count4 = remaining / 4;
            cout << string(count4, '4') + string(count7, '7') << "\n";
            return;
        }
        count7--;
    }
    cout << "-1"<<endl;;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        findLuckyNumber(N);
    }
    return 0;
}

