#include <bits/stdc++.h>

using namespace std;
int a[1001][1001];
int td[8]={-1,-1,-1,0,0,1,1,1},
    tc[8]={-1,0,1,-1,1,-1,0,1};
int n,m,ax,ay,bx,by,cx,cy;
bool check(int i,int j){
    return (i>=1&&i<=n&&j>=1&&j<=n);
}
void dfs(int ui, int uj){
    a[ui][uj]=2;
    for(int k=0;k<8;k++){
        int vi=ui+td[k];
        int vj=uj+tc[k];
        if (check(vi,vj) && a[vi][vj]==0)
            dfs(vi,vj);
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%d %d",&ax,&ay);
    for (int i=1;i<=n;i++)
    {
        a[ax][i]=1;
        a[i][ay]=1;
    }
    int ui=ax,uj=ay,uii=ax,ujj=ay;
    while (true)
    {
        if (check(ui,uj))
        {a[ui][uj]=1; ui++;   uj++; }
        if (check(uii,ujj))
        {a[uii][ujj]=1; uii--;  ujj--;  }
         if (check(ui,uj)==false && check(uii,ujj)==false)   break;
    }
    ui=ax,uj=ay,uii=ax,ujj=ay;
    while (true)
    {
        if (check(ui,uj))
        {a[ui][uj]=1;   ui--;   uj++;  }
        if (check(uii,ujj))
        {a[uii][ujj]=1; uii++;  ujj--;  }
        if (check(ui,uj)==false && check(uii,ujj)==false)   break;
    }
    scanf("%d %d",&bx,&by);
    dfs(bx,by);
    scanf("%d %d",&cx,&cy);
    if (a[cx][cy]==2)   printf("YES");
    else printf("NO");
    return 0;
}
