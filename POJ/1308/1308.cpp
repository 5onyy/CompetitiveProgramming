#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

struct node
{
	int s, v;
}edge[100];

bool cmp(struct node a,struct node b)
{
	return a.v<b.v;
}

int mark[100];
int num[100];

int main()
{
	int a, b, cas = 0, n, m, err;

	while(scanf("%d%d",&a,&b)==2)
	{
		cas++;n = m = 0;
		if(a==-1)
			break;
		if(a==0)
		{
			printf("Case %d is a tree.\n",cas);
			continue;
		}
		memset(mark,0,sizeof(mark));
		err = 0;
		edge[n].s = a,edge[n].v = b;
		if(a==b)
			err = 1;
		if(!mark[a])
		{
			num[m++] = a;
			mark[a] = 1;
		}
		if(!mark[b])
		{
			num[m++] = b;
			mark[b] = 1;
		}
		n++;
		while(scanf("%d%d",&a,&b)==2)
		{
			if(!a)
				break;
			else
			{
				if(a==b)
					err = 1;
				edge[n].s = a;
				edge[n++].v = b;
				if(!mark[a])
				{
					num[m++] = a;
					mark[a] = 1;
				}
				if(!mark[b])
				{
					num[m++] = b;
					mark[b] = 1;
				}
			}
		}
		if(err||m!=n+1)
		{
			printf("Case %d is not a tree.\n",cas);
			goto con;
		}
		printf("Case %d is a tree.\n",cas);
con:
		;
	}
	return 1;
}
