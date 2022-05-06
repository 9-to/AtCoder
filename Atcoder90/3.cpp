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
#define N_MAX = 100000;
ll d[100001];//最短距離
ll ans =0;
vector<ll> E[100001];
//グラフ問題
//最大の閉路を形成する
//制約から連結している←これは関係なく、最も長い経路を考えたい
ll calc(ll a){
    rep(i,N+1)d[i] = -1;
    ll maxD = 0,tmp;
    queue<ll> q;
    q.push(a);
    d[a] = 0;
    while(!q.empty()){
        ll pos = q.front();
        q.pop();
        for(auto to:E[pos]){
            if(d[to]== -1){
                d[to] = d[pos]+1;
                q.push(to);
                if(d[to]>maxD){
                    maxD = d[to];
                    tmp = to;
                }
                //cout<<to<<"|"<<d[to]<<endl;
            }
        }
    }
    return tmp;
}

int main() {
    cin>>N;
    rrep(i,N-1){
        ll a,b;
        cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    ll tmp = calc(1LL);
    //cout<<"maxdistV:"<<tmp<<endl;
    tmp = calc(tmp);
    cout<<d[tmp]+1<<endl;
    return 0;
}