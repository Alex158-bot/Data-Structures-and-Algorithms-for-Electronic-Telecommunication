#include <bits/stdc++.h>
using namespace std;

vector<char> ops = {'+', '-', '*'};

int calculate(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

bool checkExpression(vector<int> &nums, vector<char> &op) {
    int res = nums[0];
    for (int i = 0; i < 4; i++) {
        res = calculate(res, nums[i + 1], op[i]);
    }
    return res == 23;
}

bool solve(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    do {
        for (char op1 : ops)
            for (char op2 : ops)
                for (char op3 : ops)
                    for (char op4 : ops) {
                        vector<char> curOps = {op1, op2, op3, op4};
                        if (checkExpression(nums, curOps)) return true;
                    }
    } while (next_permutation(nums.begin(), nums.end()));
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> nums(5);
	for(int i = 0;i<nums.size();i++)
		cin>>nums[i];
		if(solve(nums)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
}
    return 0;
}

