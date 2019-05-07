#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
const int maxm = 100000;
typedef pair<int,int> pii;
int main(){
    srand(time(0));
    cout<<maxn<<" "<<maxm<<endl;
    for (int i=0;i<maxn;i++){
        int f = rand()%2;
        f = 1;
        if (f)cout<<"B";
        else cout<<"W";
    }
    cout<<endl;
    vector<pii> edges(0);
    for (int i=1;i<maxn;i++){
        edges.push_back(make_pair(i,i+1));
    }
    edges.push_back(make_pair(maxn,1));
    random_shuffle(edges.begin(),edges.end());
    for (pii pr : edges){
        int u,v;
        tie(u,v) = pr;
        cout<<u<<" "<<v<<endl;
    }
    return 0;
}
