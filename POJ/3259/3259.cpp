#include <stdio.h>
# define INF 35000

int n, m, w;
struct node
{
	int st;
	int ed;
	int  t;
}Edge[5500];

int dis[501];

bool Relax(int u, int v, int w)
{
	bool sign;

	sign = false;
	if(dis[u]!=INF&&dis[v]>dis[u]+w)
	{
		sign = true;
		dis[v] = dis[u]+w;
	}
	return sign;
}

int bellman_ford()
{
	int i, j;
	bool sign;

	for(i = 0; i < n; i++)
		dis[i] = INF;
	dis[0] = 0;

	sign = true;
	for(i = 1; i < n&&sign; i++)
	{
		sign = false;
		for(j = 0; j < 2*m+w; j++)
			if(Relax(Edge[j].st,Edge[j].ed,Edge[j].t)==true)
				sign = true;
	}
	for(i = 0; i < 2*m+w; i++)
		if(dis[Edge[i].ed]>dis[Edge[i].st]+Edge[i].t)
			return false;
	return true;
}

void input()
{
	int i, j;
	int st, ed, t;

	scanf("%d%d%d",&n,&m,&w);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d",&st,&ed,&t);
		st--,ed--;
		Edge[i*2].st = st,Edge[i*2].ed = ed,Edge[i*2].t = t;
		Edge[i*2+1].st = ed,Edge[i*2+1].ed = st,Edge[i*2+1].t = t;
	}
	j = 2*m;
	for(i = 0; i < w; i++)
	{
		scanf("%d%d%d",&st,&ed,&t);
		st--,ed--;
		Edge[j].st = st,Edge[j].ed = ed,Edge[j++].t = -1*t;
	}
	if(bellman_ford())
		printf("NO\n");
	else
		printf("YES\n");
}

int main()
{
	int f;

	scanf("%d",&f);
	while(f--)
		input();
	return 1;
}
