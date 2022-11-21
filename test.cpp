#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");

    int a, b;

    fin >> a >> b;

    fout << a + b << endl;
    

    return 0;
}
