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
vector<ll> prime;
ll cnt=0;
void makePrimeTable(){
    vector<bool> fl(1000001,false);
    for(ll i=2;i<1000001;i++){
        if(fl[i])continue;
        prime.push_back(i);
        for(ll j=i;j<1000001;j+=i)fl[j]=true;
    }
}
ll f(ll p, ll q){
    double est =1;
    est = q*q*q;
    est *= p;
    if(est>4e18)return 4e18;
    return p*q*q*q;
}

int main() {
    cin>>N;
    makePrimeTable();
    //rep(i,prime.size())cout<<prime[i]<<endl;
    ll len = prime.size();
    int q = len-1;
    for(ll p=0;p< len;p++){
        while(p<q && f(prime[p],prime[q])>N)q--;
        if(p>=q)break;
        cnt+=(q-p);
    }
    cout<<cnt<<endl;
    return 0;
}