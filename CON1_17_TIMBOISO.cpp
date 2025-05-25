#include <bits/stdc++.h>
using namespace std;
//Su dung thuat toan BFS de tim boi so nho nhat co chua 9 0

void findSmallestMultiple(int N) {
    queue<string> q;
    unordered_set<int> visited;
    
    q.push("9");  

    while (!q.empty()) {
        string num = q.front();
        q.pop();

        long long val = stoll(num);  

        if (val % N == 0) {  
            cout << num << endl;
            return;
        }

        int modValue = val % N;  
        if (!visited.count(modValue)) {
            visited.insert(modValue);
            q.push(num + "0");
            q.push(num + "9");
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        findSmallestMultiple(N);
    }
    return 0;
}

