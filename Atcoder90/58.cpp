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

ll K,N;
ll a[1<<18];
ll Q = 100000;
//K<10^18のため、O(K)だとTLEになる
//巡回性を利用する？

ll calc(ll n){
    ll outp = 0;
    ll tmp = n;
    while(tmp>0){
        outp += tmp % 10;
        tmp /= 10;
    }
    return outp;
}


int main() {
    cin>>N>>K;
    vector<ll> c,cp;
    ll pos,ii;
    rrep(i,K){
        N = (N+calc(N))%Q;
        if(N==0){
            cout<<0<<endl;
            return 0;
        }
        auto result = find(all(c),N);
        if(result!=c.end()){
            pos = distance(c.begin(),result);
            //cout<<c.size()<<"|"<<pos<<endl;
            ii = i;
            copy(result,c.end(),back_inserter(cp));
            break;
        }
        c.push_back(N);
    }
    if(cp.size()!=0){
        K = (K-ii+1)%cp.size();
        if(K!=0)cout<<cp[K-1]<<endl;
        else cout<<cp[cp.size()-1]<<endl;
    }else{
        cout<<N<<endl;
    }
    return 0;
}
