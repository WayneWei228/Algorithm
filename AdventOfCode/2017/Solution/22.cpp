#include <cstdio>
#include <deque>
#include <string>
using namespace std;

template <typename T>
struct InfiniteArray {
    deque<T> Data;
    int Offset = 0;

    T& operator[](int n) {
        n += Offset;
        while (int(Data.size()) <= n) Data.emplace_back();
        while (n < 0) {
            Data.emplace_front();
            ++Offset;
            ++n;
        }
        return Data[n];
    }
};

char Buffer[80];

struct Board {
    InfiniteArray<InfiniteArray<char>> A;

    Board& Read() {
        while (scanf("%s", Buffer) == 1) {
            string s = Buffer;
            A.Data.emplace_back(
                InfiniteArray<char>{{s.begin(), s.end()}});
        }
        return *this;
    }
};

int DX[4]{0, -1, 0, 1}, DY[4]{1, 0, -1, 0};

struct Solution {
    int Compute1(Board b) {
        int x = b.A.Data.size() / 2;
        int y = b.A.Data[0].Data.size() / 2;
        int direction = 1;
        int answer = 0;
        for (int i = 0; i < 10000; ++i) {
            char& c = b.A[x][y];
            switch (c) {
                case '#':
                    direction = (direction + 3) % 4;
                    c = '.';
                    break;
                default:
                    direction = (direction + 1) % 4;
                    c = '#';
                    ++answer;
                    break;
            }
            x += DX[direction];
            y += DY[direction];
        }
        return answer;
    }

    int Compute2(Board b) {
        int x = b.A.Data.size() / 2;
        int y = b.A.Data[0].Data.size() / 2;
        int direction = 1;
        int answer = 0;
        for (int i = 0; i < 10000000; ++i) {
            char& c = b.A[x][y];
            switch (c) {
                case 'W':
                    ++answer;
                    c = '#';
                    break;
                case '#':
                    direction = (direction + 3) % 4;
                    c = 'F';
                    break;
                case 'F':
                    direction = (direction + 2) % 4;
                    c = '.';
                    break;
                default:
                    direction = (direction + 1) % 4;
                    c = 'W';
                    break;
            }
            x += DX[direction];
            y += DY[direction];
        }
        return answer;
    }

    void Solve() {
        auto b = Board().Read();
        printf("%d\n", Compute1(b));
        printf("%d\n", Compute2(b));
    }
};

int main() {
    Solution().Solve();
    return 0;
}