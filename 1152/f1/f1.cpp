#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
const int maxk = 12+2;
const int maxmask = (1 << 4) + 5;
const int mod = 1e9 + 7;
inline void add(int &target,int val){
    (target += val) %= mod;
}
int n,K,m;
int dp[maxn][maxmask][maxk];

int main(){
    scanf("%d%d%d",&n,&K,&m);
    dp[0][0][0] = 1;
    for (int i=0;i<n;i++){
        for (int mask = 0;mask < (1 << m);mask ++){
            for (int k=0;k<=K;k++){
                if (!dp[i][mask][k])continue;
                //not use
                add(dp[i+1][(mask>>1)][k],dp[i][mask][k]);
                //use
                add(dp[i+1][(mask>>1) | (1<<(m-1))][k+1],1ll * dp[i][mask][k] * (1+__builtin_popcount(mask) ) % mod);
            }
        }
    }
    int ans = 0;
    for (int i=n;i<=n;i++){
        for (int mask = 0;mask < (1<< m);mask++){
            for (int k = K;k <= K;k++){
                add(ans,dp[i][mask][k]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}