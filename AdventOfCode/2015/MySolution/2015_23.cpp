#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
inc a
jio a, +2
tpl a
inc a
*/

typedef long long int64;

char Buffer[80], Buffer1[80];

struct Register {
    char name1, name2;
    int64 value1, value2;
};

struct Instruction {
    enum {Inc, Jio, Hlf, Tpl, Jie, Jmp} Type;
    char regis;
    int offset = 0;

    Instruction(const string& input) {
        if(sscanf(input.c_str(), "inc %c", &regis) == 1) {
            Type = Inc;
        }
        if(sscanf(input.c_str(), "hlf %c", &regis) == 1) {
            Type = Hlf;
        }
        if(sscanf(input.c_str(), "tpl %c", &regis) == 1) {
            Type = Tpl;
        }
        if(sscanf(input.c_str(), "jmp %c%d", Buffer, &offset) == 2) {
            Type = Jmp;
            if(Buffer[0] == '-') {
                offset = -offset;
            }
        }
        if(sscanf(input.c_str(), "jie %c, %c%d", &regis, Buffer, &offset) == 3) {
            Type = Jie;
            if(Buffer[0] == '-') {
                offset = -offset;
            }
        }
        if(sscanf(input.c_str(), "jio %c, %c%d", &regis, Buffer, &offset) == 3) {
            Type = Jio;
            if(Buffer[0] == '-') {
                offset = -offset;
            }
        }
    }

};

struct Solution {
    vector<Instruction> Instructions;


    int64 Exculate(const unordered_map<char, int64>& input) {
        int i = 0;
        unordered_map<char, int64> Register(input);
        while (0 <= i && i < Instructions.size()) {
            switch (Instructions[i].Type) {
                case Instruction::Inc:
                    Register[Instructions[i].regis]++;
                    i++;
                    break;
                case Instruction::Jio:
                    if (Register[Instructions[i].regis] == 1) {
                        i += Instructions[i].offset;
                    } else {
                        i++;
                    }
                    break;
                case Instruction::Hlf:
                    Register[Instructions[i].regis] /= 2;
                    i++;
                    break;
                case Instruction::Tpl:
                    Register[Instructions[i].regis] *= 3;
                    i++;
                    break;
                case Instruction::Jie:
                    if (Register[Instructions[i].regis] % 2 == 0) {
                        i += Instructions[i].offset;
                    } else {
                        i++;
                    }
                    break;
                case Instruction::Jmp:
                    i += Instructions[i].offset;
                    break;
                default: break;
            }
        }
        return Register['b'];
    }

    void Solve() {
        while (true) {
            if(scanf("%[^\n]\n", Buffer) < 1) break;
            Instructions.emplace_back(Buffer);
        }
        unordered_map<char, int64> Register;
        Register['a'] = 0;
        Register['b'] = 0;
        int64 answer1 = Exculate(Register);

        Register['a'] = 1;
        Register['b'] = 0;
        int64 answer2 = Exculate(Register);
        
        printf("%lld\n", answer1);
        printf("%lld\n", answer2);


    }
};

int main() {
    Solution().Solve();
    return 0;
}