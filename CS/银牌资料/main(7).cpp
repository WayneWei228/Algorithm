/*
 After the first K swaps, we compute where each cow ends up. If a cow started at the i-th position, let its new position be pi. Let’s also track the set si of all positions that cow i reached during the K swaps. This does not take too much memory because the sum of the sizes of all sets si is bounded by 2K+N (every swap, at most two cows move, thus adding at most two elements to the sets).
 
 Let’s build a directed graph on the positions that shows how the cows move every K swaps. We have N directed edges from all i to pi (1≤i≤N). This graph is a bunch of cycles because after K swaps, there is exactly one cow in each position, so the outdegree and indegree of each node is one. Therefore, the graph is a bunch of disjoint cycles.
 
 We claim that the answers for all cows in the same cycle are the same. Because everything repeats every K swaps, if two cows have ever been in the same position after a multiple of K swaps, they would visit the same positions eventually. After K swaps, cow i goes to position pi, so the answers for cow i and cow pi are the same. This logic extends to every cow in the cycle (the answer for cow pi is equal to cow P_{pi} and so on).
 
 So, what exactly is the answer for some cycle? It’s the size of the union of all the sets si for each cow i in the cycle. In other words, the answer is the number of unique positions in all the sets in the cycle. The complexity of this solution is O(N+K).
 
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int N,K;
int A[200001],B[200001]; //input
int P[100001]; //as described in analysis
vector<int>S[100001]; //as described in analysis
int from[100001]; //from[i] = where the cow in position i originated from
int cnt[100001]; //array to keep track of uniquePos
int uniquePos; //# of unique reachable positions

//add in S_node
void add(int node){
    // for (int x:S[node]){
    //     if (cnt[x]==0)
    //         uniquePos++;
    //     cnt[x]++;
    // }
}

//remove S_node
void remove(int node){
    // for (int x:S[node]){
    //     if (cnt[x]==1)
    //         uniquePos--;
    //     cnt[x]--;
    // }
}

bool vis[100001];
queue<int>q; //stores all nodes in current cycle

void dfs(int node){
    vis[node]=true;
    add(node);
    q.push(node);
    if (!vis[P[node]])
        dfs(P[node]);
}

int main(){
    // cin>>N>>K;
    // for (int i=0;i<K;i++)
    //     cin>>A[i]>>B[i];
    // //initialize from and S
    // for (int i=1;i<=N;i++){
    //     from[i]=i;
    //     S[i].push_back(i);
    // }
    // //simulate the first K swaps, keeping track of where each position can reach
    // for (int i=0;i<K;i++){
    //     S[from[A[i]]].push_back(B[i]);
    //     S[from[B[i]]].push_back(A[i]);
    //     swap(from[A[i]],from[B[i]]);
    // }
    
    // for(int i=1;i<=N;i++){
    //     printf("point%d:",i);
    //     for(int j=0;j<S[i].size();j++){
    //         printf("%d",S[i][j]);
    //     }
        
    //     printf("\n");
    // }
    
    // //compute array P after first K swaps
    // for (int i=1;i<=N;i++){
    //      P[from[i]]=i;
    //     cout<<"i"<<from[i]<<P[from[i]]<<endl;
        
    // }
       
    
    // int ans[100001];
    // //run a DFS on each cycle
    // for (int i=1;i<=N;i++)
    //     if (!vis[i]){
    //         dfs(i);
    //         int tempAns=uniquePos; //the answer
    //         //assign the answer for all nodes in the cycle, which we've stored in this queue
    //         while (!q.empty()){
    //             remove(q.front());
    //             ans[q.front()]=tempAns;
    //             q.pop();
    //         }
    //     }
    // for (int i=1;i<=N;i++)
    //     cout<<ans[i]<<endl;
    return 0;
}

/*
 1 2 3 4 5
 
 2 1
 
 2 1 3 4 5
 
 1 3
  
 3 1 2 4 5
 
 
 
 5 4
 1 3
 1 2
 2 3
 2 4
 
 1 2 3 4 5
 
 3 2 1 4 5
 2 3 1 4 5
 2 1 3 4 5
 2 4 3 1 5

 3 4 2 1 5
 4 3 2 1 5
 4 2 3 1 5
 4 1 3 2 5
 
 3 1 4 2 5
 1 3 4 2 5
 1 4 3 2 5
 1 2 3 4 5
 
 1->3->2->4->2->1
 
 
 
 
 
 
 */
