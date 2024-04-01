#include<bits/stdc++.h>
using namespace std;
int t;
int a,b,x,y,n;
int main(){
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	cin>>t;
	while(t--){
        cin>>a>>b>>x>>y>>n;
        int t1=a,t2=a;
        int t3=b,t4=b;
        int n1=n,n2=n;
        long long s1=1,s2=1;
        if(t1-x<=n1) n1=n1-(t1-x),t1=x;
        else t1-=n1, n1=0;
        if(t3-y<=n1) n1=n1-(t3-y),t3=y;
        else t3-=n1, n1=0;
        if(t4-y<=n2) n2=n2-(t4-y),t4=y;
        else t4-=n2, n2=0;
        if(t2-x<=n2) n2=n2-(t2-x),t2=x;
        else t2-=n2, n2=0;
        cout<<min(1ll*t1*t3,1ll*t2*t4)<<endl;
	}
}
