#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

char Buffer[80], Buffer0[80], Buffer1[80], Buffer2[80];

// Sue 1: children: 1, cars: 8, vizslas: 7
/*
"Sue 0: children: 3, cats: 7, samoyeds: 2, pomeranians: 3, akitas: 0, 
vizslas: 0, goldfish: 5,trees: 3, cars: 2, perfumes: 1"
*/

// Sue 1: children: 3, cats: 10, pomeranians: 2
struct Sue {
    int name;
    map<string, int> have;
    Sue (const string& input) {
        int b0, b1, b2;
        sscanf(input.c_str(), "Sue %d: %[^:]: %d, %[^:]: %d, %[^:]: %d", 
        &name, Buffer0, &b0, Buffer1, &b1, Buffer2, &b2);
        have[Buffer0] = b0;
        have[Buffer1] = b1;
        have[Buffer2] = b2;
    }
};

struct Solution {
    vector<Sue> Aunt;
    map<string, int> already;
    void Solve() {
        already["children"] = 3;
        already["cats"] = 7;
        already["samoyeds"] = 2;
        already["pomeranians"] = 3;
        already["akitas"] = 0;
        already["vizslas"] = 0;
        already["goldfish"] = 5;
        already["trees"] = 3;
        already["cars"] = 2;
        already["perfumes"] = 1;

        // Aunt.emplace_back("Sue 1: children: 3, cats: 7, samoyeds: 2, pomeranians: 3, akitas: 0,"
        // "vizslas: 0, goldfish: 5,trees: 3, cars: 2, perfumes: 1");



        while (true) {
            if(scanf("%[^\n]\n", Buffer) < 1) break;
            Aunt.emplace_back(Buffer);
        }

        int answer1 = 0;

        for(int i = 0; i < 500; i++) {
            bool flag = true;
            for(map<string, int>::iterator it = Aunt[i].have.begin(); it != Aunt[i].have.end(); it++) {
                if(it -> second != already[it -> first]) {
                    flag = false;
                }
            }
            if(flag) {
                answer1 = Aunt[i].name;
                break;
            }
        }
        printf("%d\n", answer1);

        string cats = "cats";
        string trees = "trees";
        string pomeranians = "pomeranians";
        string goldfish = "goldfish";

        int answer2 = 0;
   
        for(int i = 0; i < 500; i++) {
            bool flag = true;
            // cout << "i " << i << endl;
            for(map<string, int>::iterator it = Aunt[i].have.begin(); it != Aunt[i].have.end(); ++it) {
                // cout << it -> first << " " << it -> second << endl;
                if(it -> first == cats || it -> first == trees) {
                    if(it -> second <= already[it -> first]) {
                        flag = false;
                    }
                } 
                else if(it -> first == pomeranians || it -> first == goldfish) {
                    if(it -> second >= already[it -> first]) {
                        flag = false;
                    }
                }
                else {
                    if(it -> second != already[it -> first]) {
                        flag = false;
                    }
                }
            }
            if(flag) {
                answer2 = Aunt[i].name;
            }
        }
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}