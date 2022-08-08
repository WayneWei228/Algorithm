#include <bits/stdc++.h>
using namespace std;
/*
If the average percentage is equal to 100, the grade should be A+ 

If the average percentage is above 90 (inclusive), the grade should be A. 

If the average percentage is above 80 (inclusive), the grade should be B. 

If the average percentage is above 70 (inclusive), the grade should be C. 

If the average percentage is above 60 (inclusive), the grade should be D. 

If the average percentage is above 40 (inclusive), the grade should be E. 

If the average percentage is below 40, the grade should be F. 
*/ 
int main() {
    int grade;
    cin >> grade;
    if(grade > 100) {
        return 0;
    }
    if(grade == 100) {
        cout << "grade: A+" << endl;
    } else if(grade >= 90) {
        cout << "grade: A" << endl;
    } else if(grade >= 80) {
        cout << "grade: B" << endl;
    } else if(grade >= 70) {
        cout << "grade: C" << endl;
    } else if(grade >= 60) {
        cout << "grade: D" << endl;
    } else if(grade >= 40) {
        cout << "grade: E" << endl;
    } else {
        cout << "grade: F" << endl;
    }
    return 0;
}