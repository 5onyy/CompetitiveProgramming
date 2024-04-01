#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define MAX 2005
int main() {
	int n,t;
	map<int,int> imap;
	cin>>t;
	vector<int> uplist,downlist,sq;
	map<int,int>::iterator it;
	while(t--) {
		cin>>n;
		int tn=0;
		int w;
		imap.clear();
		while(tn<n) {
			cin>>w;
			imap.insert(make_pair(w,++tn));
		}
		//second maximum descending subsequence
		uplist.resize(n);
		sq.clear();
		it=imap.begin();
		for(it; it!=imap.end(); it++) {
			sq.push_back(it->second);
		}
		for(int i=0; i<n; i++) {
			uplist[i]=1;
			for(int j=0; j<i; j++)
				if(sq[i]<sq[j]) {
					uplist[i]=max(uplist[j]+1,uplist[i]);
					//break;
				}
		}
		 //second maximum descending subsequence reverse direction
		downlist.resize(n);
		for(int i=n-1; i>-1; i--) {
			downlist[i]=1;
			for(int j=n-1; j>i; j--)
				if(sq[i]<sq[j]) {
					downlist[i]=max(downlist[j]+1,downlist[i]);
					//break;
				}
		}
		int imax=0;
		for(int i=0; i<n; i++) {
			imax=max(imax,uplist[i]+downlist[i]-1);
		}
		cout<<imax<<endl;
	}
	return 0;
}
