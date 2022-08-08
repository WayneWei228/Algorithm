#include <cstdio>
#include <vector>
using namespace std;

// 412 players; last marble is worth 71646 points
typedef long long int64;

struct Node {
    int Worth;
    Node *pre, *next;
};

struct Solution {
    int last, size;
    int64 MyMethod() {
        vector<int64> score;
        vector<int> V = {0, 1};
        int no = 1;
        int id = 1;
        // insert and erase 复杂度 O(n) so total O(n ^ 2);
        for (int i = 2; i <= last; i++) {
            id = (id % size + 1);
            if (i % 23 == 0) {
                no -= 7;
                if (no < 0) no += int(V.size());
                score[id] += V[no] + i;
                V.erase(V.begin() + no);
                if (no == int(V.size())) no = 0;
            } else {
                (++no == int(V.size())) ? no = 1 : no++;
                V.insert(V.begin() + no, i);
            }
        }
        return *max_element(score.begin(), score.end());
    }

    int64 biaoda() {
        vector<int64> score(size);
        Node* current = new Node;
        current->next = current->pre = current;
        current->Worth = 0;
        for (int i = 1; i <= last; i++) {
            if (i % 23 == 0) {
                int id = (i - 1) % size;
                score[id] += i;
                for (int i = 0; i < 7; i++) current = current->pre;
                score[id] += current->Worth;
                Node *Pre = current->pre, *Next = current->next;
                Pre->next = Next;
                Next->pre = Pre;
                delete current;
                current = Next;
            } else {
                current = current->next;
                Node *Next = current->next, *newNode = new Node;
                newNode->Worth = i;
                newNode->pre = current;
                newNode->next = Next;
                Next->pre = current->next = newNode;
                current = newNode;
            }
        }
        for (Node* i = current->next; i != current; i = i->next) {
            delete i;
        }
        delete current;
        return *max_element(score.begin(), score.end());
    }

    void Solve() {
        scanf("%d players; last marble is worth %d points ", &size,
              &last);
        printf("%lld\n", biaoda());
        last *= 100;
        printf("%lld\n", biaoda());
    }
};

int main() {
    Solution().Solve();
    return 0;
}