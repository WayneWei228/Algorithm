#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> gis;
    int leftmost;
    cin >> leftmost;
    gis.push_back(leftmost);
    for (int i = 1; i < N; i++) {
        int x;
        cin >> x;
        if (x > *(gis.end() - 1)) {
            gis.push_back(x);
        }
    }

    cout << gis.size() << endl;
    bool head = true;
    for (int i = 0; i < gis.size(); i++) {
        if (head) {
            cout << gis[i];
            head = false;
        } else {
            cout << " " << gis[i];
        }
    }
    cout << endl;
    return 0;
}