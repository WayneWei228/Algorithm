#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int x;
        cin >> x;
        vector<int> binary;
        while (x != 0) {
            int remainder = x % 2;
            binary.push_back(remainder);
            x /= 2;
        }
        binary.resize(32);
        for (int i = 0; i < binary.size() - 1; i++) {
            if (binary[i] == 2) {
                binary[i + 1] += 1;
                binary[i] = 0;
            }
            if (binary[i] != 0 && binary[i + 1] != 0) {
                if (binary[i] == binary[i + 1]) {
                    binary[i] = -binary[i];
                    binary[i + 2] += binary[i + 1];
                    binary[i + 1] = 0;
                } else {
                    binary[i] = binary[i + 1];
                    binary[i + 1] = 0;
                }
            }
        }
        while (!binary.empty() && binary[binary.size() - 1] == 0) {
            binary.pop_back();
        }
        cout << binary.size() << endl;
        bool head = true;
        for (auto i : binary) {
            if (head) {
                head = false;
                cout << i;
            } else {
                cout << " " << i;
            }
        }
        cout << "\n";
    }
    return 0;
}