#include <bits/stdc++.h>
using namespace std;

struct Job {//Ðinh nghia cong viec gom: id la ma cong viec, deadline: thoi gian toi da, profit loi nhua
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit; 
// so sanh de sap xep cong viec theo loi nhuan giam dan
pair<int, int> maxProfit(Job jobs[], int n) {
    sort(jobs, jobs + n, cmp); 
    //sap xep theo cong viec voi loi nhuan giam dan
 //ham tra ve mot pair<int,int> maxprofit(job jo[], int n (so luong cong viec)
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    
    vector<bool> slot(maxDeadline + 1, false); 
    int countJobs = 0, totalProfit = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline); j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                countJobs++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    
    return {countJobs, totalProfit};
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<Job> jobs(N);
        for (int i = 0; i < N; i++) {
            cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        }
        pair<int, int> result = maxProfit(jobs.data(), N);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
