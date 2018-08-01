#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f
#define CLR(a,b) memset(a,b,sizeof a)
using namespace std;

struct Edge{
    int nex,to,w;
}edge[3000005];
int head[30010];
int cnt;
int n;
inline void add(int u,int v,int w){
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].nex=head[u];
    head[u]=cnt++;
}
inline void read(int&x) {
    int f=1;x=0;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    x=x*f;
}
int dis[30010];
void spfa(int s){
    queue<int>q;
    bool vis[30010];
    CLR(vis, 0);
    CLR(dis,inf);
    vis[s]=1;
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        vis[f]=0;
        for(int i=head[f];~i;i=edge[i].nex){
            int v=edge[i].to;
            if(dis[v]>dis[f]+edge[i].w){
                dis[v]=dis[f]+edge[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m; 
    CLR(head,-1);
    cnt = 0;
    for(int i = 0; i<m;i++){
    	int v,u,w;
        cin >> u >> v >> w;
        add(u,v,w);
    }
    spfa(1);
	for(int i = 1; i <= n; ++i) {
		cout << "1 -> " << i <<": " ;
		if(dis[i]>=inf)
			cout << "INF" << endl;
		else
			cout << dis[i] << endl;
	}
    return 0;
}
