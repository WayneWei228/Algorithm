//2018 US Open Contest, Silver, Problem 3. Multiplayer Moo
/*
 在游戏结束的时候，每个格子中都包含一个数。在这个时刻，如果一头奶牛创建了一个由连通的格子组成的领域，大小不小于其他所有领域，那这头奶牛就获胜。一个“领域”被定义为一些具有相同数字编号的格子，其中每个在领域中的格子都直接与另一个同一领域中的格子通过上、下、左或者是右相邻（对角线不计）
 
 由于以单牛形式进行游戏有点无聊，奶牛们也对双牛组队进行游戏感兴趣。同一队的两头奶牛像之前一样可以创建一个领域，但是现在领域中的格子可以属于队伍中的任一头奶牛。

 给定游戏棋盘的最终状态，请帮助奶牛们计算任何单头奶牛拥有的最大的领域包含的格子数量，以及任何两头奶牛组成的队伍占有的最大的领域包含的格子的数量。两头奶牛占有的领域必须要同时包含队伍中两头奶牛的编号，不能仅仅包含一头。
 
 
 This problem is an exercise in recursive (depth first) searching to identify the connected components in a graph.

 The first task is much simpler than the second. We make a graph where every cell is a node, and two adjacent cells are connected with an edge if they contain the same number. We then launch a recursive "flood fill" from every cell (skipping the ones already visited) that fans out to label every connected region while adding up its size. My code below actually does something slightly different -- but ultimately equivalent -- by building a separate graph for each distinct ID number and then recursively searching through all of these (this allows me to re-use most of the code I wrote for the first task for the second task).

 For the second task, we build a graph for every pair of cows (x,y) where the nodes are the regions we computed in the first task, and the edges connect adjacent regions where one is labeled by cow x and the other by cow y. Each node in this graph is given a "size" which is the same as the corresponding region size from the first task. We then launch a recursive flood fill on each of these graphs to find whichever one has the largest region.

 There are two important ideas to employ here in order to make our solutions run quickly. One is to make sure each region from the first task gets compressed to a single node in the second task. If we don't do this, then in the second task we might end up recursively scanning through the same large region over and over, wasting considerable time. The other idea is that when we do our recursive searching, we need to be sure the running time only depends on the number of edges in the graph, not the number of nodes, since each of the (x,y) pairwise graphs for the second task involves a large number of nodes but likely very few edges. For example, we would not want to keep an array of "have I been there" flags for every node, which is initialized to false for each recursive search. Instead, in the solution below, we use a map data structure for this purpose, which only creates flags as they are needed, avoiding the initialization of flags for nodes that ultimately end up not being relevant.
 
 
 
 * each region from the first task gets compressed to a single node in the second task
 * running time only depends on the number of edges in the graph, not the number of nodes
 
 C++ Map find函数和count函数
 
 count函数
 之前一直以为count函数可以返回map中一个key出现的频次，即key对应的value值，主要是离散化处理计数时想当然了。
 仔细理解加实践之后，count函数返回的是一个容器中，某一元素出现的次数，对于map，即返回key出现的次数，但是map中的key是不允许重复出现的，故count函数返回值只能是1（存在）或0（不存在）。

 find函数
 使用find，返回的是被查找元素的位置，没有则返回map.end(）
 要找到某一个key的value值

 map<int, int> t;
 if(t.find(key) != t.end()){
     t.find(key)->sencond;
 }

 */
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int N, B[1001][1001], cellid[1001][1001], global_regid;

struct Graph {
    map<int,set<int> > out_edges;
    map<int,int> nodesize;  // size of each node
    map<int,int> regid;  // region ID to which it belongs
    map<int,int> regsize;          // size of each region
};

typedef pair<int,int> pii;
map<int, Graph> G1; // Graphs for all possible single IDs
map<pii, Graph> G2; // Graphs for all possible adjacent region pairs

// Return size of region reachable from nodeid
int visit(Graph &G, int nodeid, int regid)
{
    if (G.regid.count(nodeid) > 0) {
        return 0;  // already visited?  bail out
    }
    G.regid[nodeid] = regid;                  // mark this node as visited
    int a = G.nodesize[nodeid];               // tally up region size
    for (int nbrid : G.out_edges[nodeid])
        a += visit(G, nbrid, regid);
    G.regsize[regid] = a;
    return a;
}

// Compute region sizes and return largest region size in graph.
// Running time only depends on # of edges, not # of nodes, so graph can be very sparse
int largest_region(Graph &G)
{
    int m = 0;
    for (auto &p : G.out_edges) {
        // map<int,set<int> >
        //     node, out_edges
        m = max(m, visit(G, p.first, ++global_regid));
    }
    return m;
}

void add_edge(Graph &G, int node1, int node2)
{
    G.out_edges[node1].insert(node2);
    G.out_edges[node2].insert(node1);
    G.nodesize[node1] = G.nodesize[node2] = 1;
}

// Add edge between two regions in a region pair graph
void add_G2_edge(int i1, int j1, int i2, int j2)
{
    int b1 = B[i1][j1], b2 = B[i2][j2], c1 = cellid[i1][j1], c2 = cellid[i2][j2];
    if (b1 > b2) { swap (b1,b2); swap(c1,c2); }
    int r1 = G1[b1].regid[c1], r2 = G1[b2].regid[c2];
    pii p = make_pair(b1, b2);
    add_edge(G2[p], r1, r2);
    G2[p].nodesize[r1] = G1[b1].regsize[r1];
    G2[p].nodesize[r2] = G1[b2].regsize[r2];
}

int main(void)
{
    // freopen("multimoo.in", "r", stdin);
	// freopen("multimoo.out", "w", stdout);
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> B[i][j];
            cellid[i][j] = i*N+j;    // unique ID for each cell
        }
    }
    cout << endl;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << cellid[i][j] << ' ';
        }
        cout << endl;
    }
    // Build primary graph
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            add_edge(G1[B[i][j]],cellid[i][j],cellid[i][j]);
            if (i<N && B[i+1][j] == B[i][j]) add_edge(G1[B[i][j]], cellid[i][j], cellid[i+1][j]);
            if (j<N && B[i][j+1] == B[i][j]) add_edge(G1[B[i][j]], cellid[i][j], cellid[i][j+1]);
        }
    }
    // Find largest region in primary graph
    int answer1 = 0;
    // map<int, Graph> 
    for (auto &p : G1) {
        answer1 = max(answer1,largest_region(p.second));
    }
    
    // Build secondary graphs based on regions of the primary graph that are adjacent
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i<N && B[i+1][j] != B[i][j]) add_G2_edge(i,j,i+1,j);
            if (j<N && B[i][j+1] != B[i][j]) add_G2_edge(i,j,i,j+1);
        }
    }
    // Find largest region in secondary graphs
    int answer2 = 0;
    for (auto &p : G2) answer2 = max(answer2, largest_region(p.second));
    
    cout << answer1 << "\n";
    cout << answer2 << "\n";
    
    return 0;
}

/*
4
2 3 9 3
4 9 9 1
9 9 1 7
2 1 1 9
*/