#include <iostream>
#include <string>
#include <cstring>
#include <map> //map容器的头文件
using namespace std;
const int Inf = 9999999;
int graph[205][205]; //存邻接矩阵
bool vis[205];       //标记最短路径
int dist[205], path[202], kill[202], node[202], army[202], road[202];
// dist存最短路径，path存路径，kill存杀敌数，node存经过城市数量
// army存各城市的士兵，road存最短路数量
int n;
map<string, int> M;             //字符串映射到整型
map<int, string> N;             //整型映射到字符串 ，方便输出
void Dijkstra(int Sta, int End) //最短路径模板+条件判断
{
    memset(vis, 0, sizeof(vis));
    memset(dist, Inf, sizeof(dist));
    memset(path, -1, sizeof(path));
    memset(kill, 0, sizeof(kill));
    memset(node, 0, sizeof(node));
    memset(road, 0, sizeof(road));
    vis[Sta] = true; //标记原点
    dist[Sta] = 0;   //原点距离为0
    int i;
    for (i = 0; i < n; i++)
    {
        if (!vis[i] && graph[Sta][i]) //初始化原点到连通城市的关系
        {
            dist[i] = graph[Sta][i]; //最短路径
            node[i] = 1;             //经过的城市数
            kill[i] = army[i];       //杀敌数
            path[i] = Sta;           //路径
            road[i] = 1;             //路径数
        }
    }
    while (1)
    {
        int Min = Inf, v = Sta;
        for (i = 0; i < n; i++) //找出原点到其他城市最短的路径
        {
            if (!vis[i] && dist[i] < Min)
            {
                Min = dist[i];
                v = i;
            }
        }
        if (v == End) //找到原点到终点的最短路径，退出循环
            break;
        vis[v] = true;          //标记，表示原点到v是最短路径
        for (i = 0; i < n; i++) //通过v更新原点到其他城市的最短路径
        {
            if (!vis[i] && graph[v][i] + Min <= dist[i])
            {
                if (graph[v][i] + Min < dist[i]) //优先判断路径
                {
                    dist[i] = graph[v][i] + Min;
                    node[i] = node[v] + 1;       //前面经过的城市数 + 这个城市
                    kill[i] = kill[v] + army[i]; //前面所杀的敌人数 + 这个城市的士兵数
                    path[i] = v;
                    road[i] = road[v];
                }
                else
                {
                    road[i] += road[v]; //累计所有最短路径
                    if (node[v] + 1 >= node[i])
                    {
                        if (node[v] + 1 > node[i]) //路径相同考虑经过的城市数
                        {
                            kill[i] = kill[v] + army[i];
                            node[i] = node[v] + 1;
                            path[i] = v;
                        }
                        else //路径和经过的城市数都相同判断杀敌数
                        {
                            if (kill[v] + army[i] > kill[i])
                            {
                                kill[i] = kill[v] + army[i];
                                path[i] = v;
                            }
                        }
                    }
                }
            }
        }
    }
}
void Find(int x) //递归输出路径
{
    if (path[x] != -1)
    {
        Find(path[x]);
        cout << N[path[x]] << "->";
    }
}
int main()
{
    ios::sync_with_stdio(false); //取消cin于stdin的同步，使cin与scanf处理数据速度接近
    string s, e;
    int i, m;
    cin >> n >> m >> s >> e;
    M[s] = 0; //用0表示原点
    N[0] = s;
    army[0] = 0; //原点士兵数为 0
    string str;
    for (i = 1; i < n; i++)
    {
        cin >> str >> army[i];
        M[str] = i; //数据映射
        N[i] = str;
    }
    string x, y;
    int w;
    memset(graph, Inf, sizeof(graph)); //图初始化为互不连通
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        graph[M[x]][M[y]] = w; //邻接矩阵
        graph[M[y]][M[x]] = w; //双向
    }
    Dijkstra(M[s], M[e]);
    Find(M[e]);
    cout << e << endl;
    cout << road[M[e]] << ' ' << dist[M[e]] << ' ' << kill[M[e]] << endl;
    return 0;
}