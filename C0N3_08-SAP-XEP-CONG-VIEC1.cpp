#include<bits/stdc++.h>

using namespace std;

struct Congviec {
    int start, finish;
};

bool compare(Congviec a, Congviec b) {
    return a.finish < b.finish;
}

void maxActivities(int N, vector<int> &S, vector<int> &F) {
    vector<Congviec> activities(N);
    for (int i = 0; i < N; i++) {
        activities[i] = {S[i], F[i]};
    }
    
    sort(activities.begin(), activities.end(), compare);
    
    int count = 1;
    int last_finish = activities[0].finish;
    
    for (int i = 1; i < N; i++) {
        if (activities[i].start >= last_finish) {
            count++;
            last_finish = activities[i].finish;
        }
    }
    
    cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> S(N), F(N);
        for (int i = 0; i < N; i++) cin >> S[i];
        for (int i = 0; i < N; i++) cin >> F[i];
        
        maxActivities(N, S, F);
    }
    
    return 0;
}

