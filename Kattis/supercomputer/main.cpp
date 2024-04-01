#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define N 1000111
#define node vector<int>::iterator
using namespace std;

int pos,n,q;
int A, B, K;
int a[N];
int st[4*N];

void build(int id, int l, int r){
    if (l==r){
        a[l]=abs(a[l]-1);
        st[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    if (pos<=mid) build(id*2, l, mid);
    else build(id*2+1, mid+1, r);
    st[id]= st[id*2] + st[id*2+1];
}

int get(int id, int l, int r){
    if (A > r || B < l) return 0;
    if (l >= A && r<= B) return st[id];
    int mid=(l+r)/2;
    return get(id*2, l, mid) + get(id*2+1, mid+1, r);
}

int main(){
    cin >> n >> q;
    FOR(i, 1, q){
        char cmd;   cin>>cmd;
        if (cmd=='F'){
            cin >> pos;
            build(1,1,n);
        }
        else{
            cin >> A >> B;
            cout << get(1, 1, n) <<"\n";
        }
    }
}
