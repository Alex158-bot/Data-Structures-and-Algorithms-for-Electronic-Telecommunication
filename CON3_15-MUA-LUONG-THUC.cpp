#include <iostream>
using namespace std;
//9/10
void solve() {
    int N, S, M;
    cin >> N >> S >> M;

    if (M > N) {
        cout << "-1"<<endl;
        return;
    }
    
    int total_food_needed = S * M;  
    int available_days = S - (S / 7); 
    
    
    if (available_days * N < total_food_needed) {
        cout << "-1"<<endl;
        return;
    }
    
    int min_days_to_buy = (total_food_needed + N - 1) / N;  
    cout << min_days_to_buy << endl;;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
