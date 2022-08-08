#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100005;
struct node
{
	//s用来记录desk[i]的元素个数，表示第i个柜子已存s次物品 
	//num表示第i个柜子的第num个格子存入一个物品
	//w表示该格子存入的物品 
	vector<int> num,w;//用vector动态数组节省内存，以防MLE 
	int s = 0;
} desk[MAX];
int main()
{
	int n,q;
	cin>>n>>q;
	while(q--)
	{
		int x,a,b,c;
		cin>>x;
		if(x == 1)
		{
			cin>>a>>b>>c;
			desk[a].s++; //第a个柜子存入物品
			desk[a].num.push_back(b);//第b个格子中 
			desk[a].w.push_back(c);//存入物品c 
		}
		else
		{
			cin>>a>>b;
			for(int i = desk[a].s - 1;i >= 0;i--)//从后往前，因为格子存放会有更新 
			{
				if(desk[a].num[i] == b)//如果查询到该柜子的格子 
				{
					cout<<desk[a].w[i]<<endl;//输出该格子内的物品 
					break;//因此时是最新的存放情况，所以有解后需要直接退出查询 
				}
			}
		}
	} 
	return 0;
}