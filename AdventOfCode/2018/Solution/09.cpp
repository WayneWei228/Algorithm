#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;

// 双向链表
struct Node {
    int Worth;
    Node *Prev, *Next;
};

struct Solution {
    int Player;
    // O(n)
    int64 Win(int lastMarble) {
        Node *current = new Node;
        current->Prev = current->Next = current;
        current->Worth = 0;
        vector<int64> score(Player);
        for (int i = 1; i <= lastMarble; ++i) {
            if (i % 23 == 0) {
                // score -> 0 ~ Player - 1
                int currentPlayer = (i - 1) % Player;
                score[currentPlayer] += i;
                // 向前走7步
                for (int i = 0; i < 7; ++i) current = current->Prev;
                // 加上值
                score[currentPlayer] += current->Worth;
                // 前后节点相连接
                Node *prev = current->Prev, *next = current->Next;
                prev->Next = next;
                next->Prev = prev;
                // 当前节点删除
                delete current;
                // 当前节点等于消除节点后面的节点
                current = next;
            } else {
                // 现在为向后移一格节点
                current = current->Next;
                // next 为后两格节点 和 新节点
                Node *next = current->Next, *newNode = new Node;
                // 新节点与current 和 next 连接
                newNode->Prev = current;
                newNode->Next = next;
                newNode->Worth = i;
                current->Next = next->Prev = newNode;
                // 现在位置为新节点
                current = newNode;
            }
        }
        // 全删掉
        for (Node *i = current->Next; i != current; i = i->Next) {
            delete i;
        }
        delete current;
        return *max_element(score.begin(), score.end());
    }

    void Solve() {
        int lastMarble;
        scanf("%d%*[^h]h%d points", &Player, &lastMarble);
        printf("%lld\n", Win(lastMarble));
        printf("%lld\n", Win(lastMarble * 100));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
