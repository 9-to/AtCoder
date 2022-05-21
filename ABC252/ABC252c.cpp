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
string s[1000];
ll cnt[10][10]={};//[num][pos]

int main() {
    cin>>N;
    rrep(i,N)cin>>s[i];
    rrep(i,N){
        string str = s[i];
        rep(j,10){
            char c = str[j];
            ll cc = c-'0';
            cnt[cc][j] += 1;
        }
    }
    /*rep(i,10){
        rep(j,10){
            cout<<cnt[i][j];
        }
        cout<<endl;
    }*/
    ll mintime = 100000000000;
    rep(i,10){//num
        ll maxx = 0;//count
        ll maxpos = 0;//0~9のposition
        rep(j,10){//pos
            if(maxx<=cnt[i][j]) maxpos = j;
            maxx = max(maxx,cnt[i][j]);
        }
        //cout<<maxx<<"|"<<maxpos<<endl;
        mintime = min(mintime,maxpos+(maxx-1)*10);
    }
    cout<<mintime<<endl;
    return 0;
}