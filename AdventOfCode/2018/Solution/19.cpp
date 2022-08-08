#include <cstdio>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int64;
typedef function<void(int*)> Instruction;

Instruction Addr(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] + m[b]; };
}

Instruction Addi(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] + b; };
}

Instruction Mulr(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] * m[b]; };
}

Instruction Muli(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] * b; };
}

Instruction Banr(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] & m[b]; };
}

Instruction Bani(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] & b; };
}

Instruction Borr(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] | m[b]; };
}

Instruction Bori(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] | b; };
}

Instruction Setr(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a]; };
}

Instruction Seti(int a, int b, int c) {
    return [=](int* m) { return m[c] = a; };
}

Instruction Gtir(int a, int b, int c) {
    return [=](int* m) { return m[c] = a > m[b]; };
}

Instruction Gtri(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] > b; };
}

Instruction Gtrr(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] > m[b]; };
}

Instruction Eqir(int a, int b, int c) {
    return [=](int* m) { return m[c] = a == m[b]; };
}

Instruction Eqri(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] == b; };
}

Instruction Eqrr(int a, int b, int c) {
    return [=](int* m) { return m[c] = m[a] == m[b]; };
}

char Buffer[80];

struct Solution {
    unordered_map<string, function<Instruction(int, int, int)>> Op{
        {"addr", Addr}, {"addi", Addi}, {"mulr", Mulr}, {"muli", Muli},
        {"banr", Banr}, {"bani", Bani}, {"borr", Borr}, {"bori", Bori},
        {"setr", Setr}, {"seti", Seti}, {"gtir", Gtir}, {"gtri", Gtri},
        {"gtrr", Gtrr}, {"eqir", Eqir}, {"eqri", Eqri}, {"eqrr", Eqrr},
    };
    vector<Instruction> Input;
    int Ip;

    void Solve() {
        scanf("#ip%d", &Ip);
        int a, b, c;
        while (scanf("%s%d%d%d", Buffer, &a, &b, &c) == 4) {
            Input.emplace_back(Op[Buffer](a, b, c));
        }
        int m0[6]{};
        printf("%d\n", Run(m0));
        int64 e = 2 * 2 * 19 * 11 + 6 * 22 + 2;
        e += (27 * 28 + 29) * 30 * 14 * 32;
        int64 divisorSum = 0, i = 1;
        for (; i * i < e; ++i) {
            if (e % i == 0) divisorSum += i + e / i;
        }
        if (i * i == e) divisorSum += i;
        printf("%lld\n", divisorSum);
    }

    int Run(int* m) {
        while (0 <= m[Ip] && m[Ip] < Input.size()) {
            Input[m[Ip]](m);
            ++m[Ip];
        }
        return m[0];
    }
};

int main() {
    Solution().Solve();
    return 0;
}
