#include <bits/stdc++.h>
using namespace std;

bool canRearrange(string s, int d) {
    int n = s.length();
    unordered_map<char, int> freq; // Frequency map to count occurrences of each character
    priority_queue<pair<int, char>> maxHeap; // Max heap to store characters by frequency

    // Count frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    // Push frequencies into the max heap
    for (const auto& it : freq) {
        maxHeap.push({it.second, it.first});
    }

    // Check if the most frequent character can be placed without violating the distance constraint
    if (maxHeap.top().first > (n + d - 1) / d) {
        return false; // Not possible to rearrange
    }

    // Result string to store the rearranged characters
    string result(n, ' ');
    int idx = 0; // Index to place characters in the result

    // Place characters in the result string
    while (!maxHeap.empty()) {
        auto [count, ch] = maxHeap.top(); // Get the character with the highest frequency
        maxHeap.pop(); // Remove it from the heap

        // Place the character 'count' times in the result
        for (int i = 0; i < count; i++) {
            // If we reach the end of the string, wrap around
            if (idx >= n) {
                idx = (idx % d == 0) ? 1 : (idx + 1);
            }
            result[idx] = ch; // Place the character
            idx += d; // Move index by d
        }
    }

    // If we successfully placed all characters, return true
    return true;
}

int main() {
    int T; // Number of test cases
    cin >> T; // Read number of test cases
    while (T--) {
        int D; // Distance constraint
        string S; // Input string
        cin >> D >> S; // Read D and S for each test case
        cout << (canRearrange(S, D) ? 1 : -1) << ?
