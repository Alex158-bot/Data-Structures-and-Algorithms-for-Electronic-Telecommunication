#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    string s;
    deque<int> dq;
    while (n--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "PRINTFRONT")
        {
            if (dq.size())
                cout << dq.front() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "POP")
        {
            if (dq.size())
                dq.pop_front();
        }
    }
}
