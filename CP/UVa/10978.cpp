#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) == 1 && N != 0) {
        vector<string> cards;
        cards.resize(N);
        int cur = -1;
        for (int i = 0; i < N; i++) {
            string value, suit;
            cin >> value >> suit;
            int steps = suit.size();
            while (steps > 0) {
                int next = (cur + 1) % N;
                if (cards[next] == "") {
                    steps--;
                }
                cur = next;
            }
            cards[cur] = value;
        }

        bool head = true;
        for (int i = 0; i < N; i++) {
            if (head) {
                cout << cards[i];
                head = false;
            } else {
                cout << " " << cards[i];
            }
        }
        cout << endl;
    }
    return 0;
}