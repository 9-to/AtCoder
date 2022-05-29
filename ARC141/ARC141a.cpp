#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

/* alias */
using ll = unsigned long long;
//using ll = long long;
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

ll T;
string S[10010];
ll strToll(string s){
    ll outp = 0;
    ll ten = 1;
    for(int i=s.size()-1;i>=0;i--){
        outp += ten*(s[i]-'0');
        ten *= 10;
    }
    return outp;
}
string llTostr(ll n){
    string s;
    ll tmp = n;
    while(tmp>0){
        s = char(tmp%10 + '0') + s;
        tmp /= 10;
    }
    return s;
}

int main() {
    cin>>T;
    rep(i,T){
        cin>>S[i];
    }
    rep(i,T){
        string s = S[i];
        ll len = S[i].size();
        ll sl = strToll(s);
        string o99;
        rep(i,len-1){
            o99 = o99 + '9';
        }
        ll ans = strToll(o99);
        rrep(i,len/2){//i=sublen
            if(len%i!=0)continue;
            string originS = s.substr(0,i);
            ll s0 = strToll(originS);
            ll s1 = s0-1;
            ll rep = len/i;
            string o1,o0;
            rep(i,rep){
                o0 = o0 + llTostr(s0);
                o1 = o1 + llTostr(s1);
            }
            ll o0ll = strToll(o0);
            ll o1ll = strToll(o1);
            if(o0ll<=sl)ans = max(ans,o0ll);
            if(o1ll<=sl)ans = max(ans,o1ll); 
        }
        cout<<ans<<endl;
    }
    return 0;
}