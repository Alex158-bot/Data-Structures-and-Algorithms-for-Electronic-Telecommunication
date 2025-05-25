#include <iostream>
#include <vector>
using namespace std;

vector<string> generateGrayCode(int n) {
    if (n == 1) return {"0", "1"};
    vector<string> prev = generateGrayCode(n - 1);
    vector<string> result;
    for (string s : prev) result.push_back("0" + s);
    for (auto it = prev.rbegin(); it != prev.rend(); ++it) result.push_back("1" + *it);
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<string> grayCodes = generateGrayCode(n);
    for (const string &code : grayCodes) cout << code << " ";
    cout<<endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

