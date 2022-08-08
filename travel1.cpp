#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

struct Coordinate
{ // 结构体，记录坐标
    double X, Y;

    bool operator<(const Coordinate &that) const
    {
        return X < that.X || X == that.X && Y < that.Y;
    }
};

typedef map<Coordinate, int>::iterator Type1;
typedef pair<Type1, bool> Type2;

struct Solution
{
    int N;                    // N个坐标
    vector<Coordinate> C;     // 记录出现过的坐标
    map<Coordinate, int> CNo; // 用整数来表示坐标

    int ReadCoordinate()
    { // 读一组数组
        Coordinate c;
        cin >> c.X >> c.Y;
        Type2 result = CNo.insert(make_pair(c, C.size()));
        if (result.second)
            C.push_back(c);
        return result.first->second;
    }

    double Distance(int c1, int c2)
    {                                            // 计算两点的欧式距离
        double dx = pow((C[c2].X - C[c1].X), 2); // 两点x坐标差的平方
        double dy = pow((C[c2].Y - C[c1].Y), 2); // 两点y坐标差的平方
        double ans = sqrt(dx + dy);              // 开根号求距离
        return ans;
    }

    void Solve()
    {
        int N;
        scanf("%d", &N);
        vector<int> place;
        place.resize(N);
        for (int i = 0; i < N; i++)
        {
            place[i] = ReadCoordinate();
        }

        // for(int i = 0; i < N; i++) {
        //     cout << place[i] << " ";
        // }
        cout << endl;
        double ans = numeric_limits<double>::max();
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 5; k++)
                {
                    for (int z = 1; z <= 5; z++)
                    {
                        for (int x = 1; x <= 5; x++)
                        {
                                set<int> arr;
                                arr.insert(i);
                                arr.insert(j);
                                arr.insert(k);
                                arr.insert(z);
                                arr.insert(x);
                                if(arr.size() == 5) {
                                    double result = Distance(i, j) + Distance(j, k) + Distance(k, z) + Distance(z, x);
                                    if(result < ans) {
                                        cout << i << " " << j << " " << k << " " << z << " " << x << endl;
                                        ans = result;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
};

int main()
{
    Solution().Solve();
    return 0;

}