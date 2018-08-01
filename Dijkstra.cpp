#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, d[MAXV];
bool vis[MAXV];
struct ac
{
    int v, dis;
};
vector<ac> Adj[MAXV];
void Dijkstra(int s)
{
    memset(d, INF, sizeof(d));
    memset(vis, false, sizeof(vis));
    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == 0 && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int j = 0; j < Adj[u].size(); j++)
        {
            int v = Adj[u][j].v;
            if (vis[v] == false && d[u] + Adj[u][j].dis < d[v])
            {
                d[v] = d[u] + Adj[u][j].dis;
            }
        }
    }
}

int main(){
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u, v, cost;
        cin >> u >> v >> cost;
        Adj[u].push_back(ac{v, cost});
    }
    Dijkstra(1);
    for (int i = 1; i <= n; ++i){
        cout << "1 -> " << i << ": ";
        if (d[i] >= INF)
            cout << "INF" << endl;
        else
            cout << d[i] << endl;
    }
    return 0;
}
