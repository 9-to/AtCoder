#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

/* alias */
using ull = unsigned long long;
using ll = long long;
/* define short */
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define rrepd(i,n) for(ll i=n;i>=1;i--)

ll N;
vector<ll> V[100002];//グラフ
ll colors[100001];//{0,1}

void dfs(ll pos, ll cur){//深さ優先探索
    colors[pos] = cur;
    for(auto i:V[pos]){
        if(colors[i]==-1) dfs(i,1-cur);
    }
}

int main() {
    cin>>N;
    rrep(i,N)colors[i]=-1;
    rep(i,N-1){
        ll a,b;
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    dfs(1,1);
    vector<ll> G1,G0;
    rrep(i,N){
        if(colors[i]==0)G0.push_back(i);
        if(colors[i]==1)G1.push_back(i);
    }
    if(G1.size()>G0.size()){
        rep(i,N/2){
            if(i)cout<<" ";
            cout<<G1[i];
        }
    }else{
        rep(i,N/2){
            if(i)cout<<" ";
            cout<<G0[i];
        }
    }
    cout<<endl;
    return 0;
}