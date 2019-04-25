/* Generated by powerful Codeforces Tool
 * Author: calabash_boy_love_15 
 * Time: 2019-04-25 23:34:55
 * Personal Code Template: https://github.com/4thcalabash/ACM-Code-Library
**/
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif
#define PB(x) push_back(x)
#define rep(i,l,r) for (int i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (int i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)
#define range(x) x.begin(),x.end()
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;
/************* header ******************/

const int maxn = 1e7+100;

int cnt[maxn];
int idx[maxn];
int n;
int main(){
    untie;
    cin>>n;
    ll ans = LLONG_MAX;
    pair<int,int> ans_idx;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt[x] ++;
        if (cnt[x] == 2 && ans > x){
            ans = x;
            ans_idx = make_pair(idx[x],i);
        }
        idx[x] = i;
    }
    for (int i=1;i<maxn;i++){
        vi nums(0);
        for (int j=i;j<maxn && nums.size() < 2;j += i){
            if (cnt[j])nums.PB(j);
        }
        if (nums.size() == 2){
            int x = nums[0], y = nums[1];
            ll temp = 1ll * x * y / __gcd(x,y);
            if (temp < ans){
                ans = temp;
                ans_idx = make_pair(idx[x],idx[y]);
           } 
        
        }
    }
    if (ans_idx.first > ans_idx.second){
        swap(ans_idx.first,ans_idx.second);
    }
    cout<<ans_idx.first<<" "<<ans_idx.second<<endl;
    return 0;

}