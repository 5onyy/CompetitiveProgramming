#include <bits/stdc++.h>
#define ll long long
#define ms(a) memset(a,0,sizeof(a))
#define vi vector<int>
#define pii pair<int,int>
#define eps 1e-9
#define MAX 10005
using namespace std;

vi adj[MAX];
vi low(MAX,0),num(MAX,-1);
int parent[MAX],art[MAX];
int root,t,special,pidRoot;

void dfs(int u){
    low[u] = num[u] = t++;
    art[u]=1;
    for(int i = 0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(num[v] == -1){
            parent[v]=u;
            if(u == root)special++;
            dfs(v);
            if(low[v]>=num[u]){art[u]++;}
            low[u] = min(low[u],low[v]);
        }else if(v!=parent[u]){
            low[u]=min(low[u],num[v]);
        }
    }
    if(u==root)--art[u];
}

bool custom(pii A, pii B){
    if(A.first>B.first)return true;
    else if(A.first == B.first){
        if(A.second<B.second)return true;
    }
    return false;
}

int main(){
	freopen("10765.INP","r",stdin);
	freopen("10765.OUT","w",stdout);
    int n,m;
    while(cin>>n>>m && !(n==0 && m==0)){
        int x,y;
        while(cin>>x>>y && !(x==-1 && y==-1)){
           adj[x].push_back(y);
           adj[y].push_back(x);
        }

        if(num[0]!=-1)  continue;
        root = 0;t = 0; special=0;
        dfs(root);
        vector<pii>points;
        for(int i = 0;i<n;i++){
            if(art[i]!=0)points.push_back(pii(art[i],i));
        }
        sort(points.begin(),points.end(),custom);
        for(int i = 0;i<m;i++){
            cout<<points[i].second<<" "<<points[i].first<<endl;
        }
        low.assign(MAX,0);  num.assign(MAX,-1); ms(adj);    ms(parent); ms(art);
        cout<<endl;
    }
}
