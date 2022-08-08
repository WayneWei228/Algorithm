#include <cstdio>
#include <string>
using namespace std;

char Buffer[105];

struct Solution {
    void Solve(int caseNo) {
        scanf("%s", Buffer);
        string s = Buffer;
        switch(s[s.size() - 1]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':    
            case 'O':   
            case 'U':    
                printf("Case #%d: %s is ruled by Alice.\n", caseNo, s.c_str());
                break;
            case 'y':
                printf("Case #%d: %s is ruled by nobody.\n", caseNo, s.c_str());
                break;
            default:
                printf("Case #%d: %s is ruled by Bob.\n", caseNo, s.c_str());
                break;
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}