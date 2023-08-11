#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, w, n, i, j, p;
    freopen("12455.INP","r",stdin);
    freopen("12455.OUT","w",stdout);
    cin>>t;
    while(t--) {
        cin>>w>>n;
        int dp[1005] = {};
        dp[0] = 1;
        for(i = 0; i < n; i++) {
            cin>>p;
            for(j = w-p; j >= 0; j--) {
                if(dp[j] && !dp[j+p])
                    dp[j+p] = 1;
            }
        }
        if(dp[w])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
