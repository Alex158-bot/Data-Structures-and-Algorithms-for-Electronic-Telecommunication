#include <iostream>
using namespace std;

string grayToBinary(string gray) {
    string binary = gray;  
    for (int i = 1; i < gray.length(); i++) {
        binary[i] = ((binary[i - 1] - '0') ^ (gray[i] - '0')) + '0';
    }
    return binary;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string gray;
        cin >> gray;
        cout << grayToBinary(gray) << endl;
    }
    return 0;
}

