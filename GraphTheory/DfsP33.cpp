// 图论 P33
// #include<iostream>
// #include<cstdio>
// #include<cmath>

// char map[9][9];
// int n,m,t;
// int di,dj;
// bool escape;
// int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

// void dfs(int si,int sj,int cnt)
// {
//     int i,temp;

//     if(si>n || sj > m || si <= 0 || sj <= 0)
//     {
//         return;
//     }
//     if(si == di && sj == dj && cnt == t)
//     {
//         escape = 1;
//         return;
//     }
//     temp = (t-cnt)-fabs(si-di)-fabs(sj-dj);
//     if(temp < 0 || temp%2){
//         return;
//     }
//     for(i=0;i<4;i++)
//     {
//         if(map[ si+dir[i][0] ][sj+dir[i][1]] != 'X')
//         {
//             map[si+dir[i][0]][sj + dir[i][1]] = 'X';
//             dfs(si+dir[i][0],sj+dir[i][1],cnt+1);
//             if(escape) return;
//             map[si+dir[i][0]][sj+dir[i][1]]='X';
//         }
//     }
//     return;
// }


// int main(){
//     int i,j;
//     int si,sj;
//     while (scanf("%d%d%d",&n,&m,&t))
//     {
//     int wall = 0;
//     char temp;
//     for(i=0;i<=n;i++)
//     {
//         for(j=0;j<=m;j++)
//         {
//             scanf("%c",&map[i][j]);
//             if(map[i][j]=='S')
//             {
//                 si=i;sj=j;
//             }
//             else if(map[i][j]=='D')
//             {
//                 di = i;dj=j;
//             }
//             else if(map[i][j]=='X')
//             {
//                 wall ++;
//             }
//         }
//         scanf("%c",&temp);
//     }
//     if(n*m-wall <= t){
//         printf("NO\n");
//         continue;
//     }
//     escape = 0;
//     map[si][sj]='X';
//     dfs(si,sj,0);
//     if(escape){
//         printf("YES\n");
//     }
//     else
//     {
//         printf("NO\n");
//     }
    
//     }
//     return 0;
// }

//标答
// #include <cstdio> 
// #include <cmath> //用到了求绝对值的函数 fabs 
// char map[9][9]; //迷宫地图
// int n, m, t; //迷宫的大小，及迷宫的门会在第 t 秒开启
// int di, dj; //(di,dj)：门的位置
// bool escape; //是否成功逃脱的标志，escape 为 1 表示能成功逃脱
// int dir[4][2] = { {0,-1}, {0,1}, {1,0}, {-1,0} }; //分别表示下、上、左、右四个方向
// //已经到达(si,sj)位置，且已经花费 cnt 秒
// void dfs( int si, int sj, int cnt ) 
// { 
//  int i, temp; 
//  if( si>n || sj>m || si<=0 || sj<=0 ) return; //边界
//  if( si==di && sj==dj && cnt==t ) //成功逃脱
//  { 
//  escape = 1; return;
//  } 
//  //abs(x-ex) + abs(y - ey)表示现在所在的格子到目标格子的距离(不能走对角线) 
//  //t-cnt 是实际还需要的步数，将他们做差
//  //如果 temp < 0 或者 temp 为奇数，那就不可能到达！
//  temp = (t-cnt) - fabs(si-di) - fabs(sj-dj); //搜索过程当中的剪枝
//  if( temp<0 || temp%2 ) return;
//  for( i=0; i<4; i++ ) 
//  { 
//  if( map[ si+dir[i][0] ][ sj+dir[i][1] ] != 'X') 
//  { 
//  //前进方向！将当前方格设置为墙壁‘X’
//  map[ si+dir[i][0] ][ sj+dir[i][1] ] = 'X'; 
//  dfs(si+dir[i][0], sj+dir[i][1], cnt+1); //从下一个位置继续搜索
//  if(escape) return; 
//  map[ si+dir[i][0] ][ sj+dir[i][1] ] = '.'; //后退方向！恢复现场！
//  } 
//  } 
//  return; 
// } 
// int main( ) 
// { 
//  int i, j; //循环变量
//  int si, sj; //小狗的起始位置
//  while( scanf("%d%d%d", &n, &m, &t) ) 
//  { 
//  if( n==0 && m==0 && t==0 ) break; //测试数据结束
//  int wall = 0; 
//  char temp; 
//  scanf( "%c", &temp ); //见下面的备注
//  for( i=1; i<=n; i++ ) 
//  { 
//  for( j=1; j<=m; j++ ) 
//  { 
//  scanf( "%c", &map[i][j] ); 
//  if( map[i][j]=='S' ){ si=i; sj=j; } 
//  else if( map[i][j]=='D' ){ di=i; dj=j; } 
//  else if( map[i][j]=='X' ) wall++; 
//  } 
//  scanf( "%c", &temp ); 
//  } 
//  if( n*m-wall <= t ) //搜索前的剪枝
//  { 
//  printf( "NO\n" ); continue; 
//  } 
//  escape = 0; 
//  map[si][sj] = 'X'; 
//  dfs( si, sj, 0 ); 
//  if( escape ) printf( "YES\n" ); //成功逃脱
//  else printf( "NO\n" ); 
//  } 
//  return 0; 
// }







































