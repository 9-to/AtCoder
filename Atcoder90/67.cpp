#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

/* alias */
//using ull = unsigned long long;
using ll = unsigned long long;
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

ll K;
string N;
//Baseをどう表現するか
ll base8_to_ll(string n){
    ll ans=0,len = n.size();
    for(int i = 0;i<len;i++){
        ans = ans * 8 + ll(n[i]-'0');
    }
    return ans;
}
string ll_to_base9(ll n10){
    string n9="";
    if(n10==0){
        n9 = "0";
        return n9;
    }
    while(n10>0){
        char tmp = ((n10%9) + '0');
        n9 = tmp + n9;
        n10 /= 9;
    }
    return n9;
}

string num8to5(string n){
    ll len=n.size();
    rep(i,len){
        if(n[i]== '8')n[i]='5';
    }
    return n;
}


int main() {
    cin>>N>>K;
    if(N=="0"){
        cout<<0<<endl;return 0;
    }
    string N8 = N;
    rep(i,K){
        ll N10 = base8_to_ll(N8);
        string N9 = ll_to_base9(N10);
        N9 = num8to5(N9);
        N8 = N9;
    }
    cout<<N8<<endl;
    return 0;
}