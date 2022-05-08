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

class UnionFind{
public:
    vector<ll> par;
    void init(ll sz){
        par.resize(sz,-1);//-1で初期化
    }
    ll root(ll pos){
        /*値から根を求める*/
        if(par[pos]==-1)return pos;
        par[pos] = root(par[pos]);
        return par[pos];
    }
    void unite(ll u, ll v){
        /*木を連結する uの根をvにする*/
        u = root(u); v = root(v);
        if(u==v) return;
        par[u] = v;
    }
    bool same(ll u,ll v){
        /*同じ木にあるかを判定*/
        if(root(u)==root(v))return true;
        return false;
    }
};

UnionFind UF;
ll H,W,Q,t;
ll F[2002][2002]={0};

int main() {
    cin>>H>>W;
    cin>>Q;
    UF.init(H*W);
    rep(i,Q){
        cin>>t;
        if(t==1){
            ll r,c;
            cin>>r>>c;
            ll dx[4] = {-1, 0, 1, 0};
            ll dy[4] = {0, -1, 0, 1};
            rep(i,4){
                ll sr = r + dx[i];
                ll sc = c + dy[i];
                if(F[sr][sc]==1){
                    ll hash1 = (r-1)*W+(c-1);
                    ll hash2 = (sr-1)*W+(sc-1);
                    UF.unite(hash1,hash2);
                }
            }
            F[r][c] = 1;
        }else if(t==2){
            ll rA,cA,rB,cB;
            cin>>rA>>cA>>rB>>cB;
            if(F[rA][cA]!=1 || F[rB][cB]!=1){
                cout<<"No"<<endl;
                continue;
            }
            ll hash1 = (rA-1)*W+(cA-1);
            ll hash2 = (rB-1)*W+(cB-1);
            YesNo(UF.same(hash1,hash2));         
        }
    }
    return 0;
}