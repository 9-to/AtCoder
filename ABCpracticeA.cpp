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

int main() {
  string Sset[4] = {"dream", "dreamer", "erase", "eraser"};
  string S;
  bool ans = true;
  int i;
  cin>>S;
  reverse(all(S));
  for(i=0;i<4;i++) reverse(all(Sset[i]));
  for(i=0;i<S.size();){
    bool tmp = false;
    for(int j=0;j<4;j++){
      string s = Sset[j];
      if(S.substr(i,s.size())==s){
        tmp = true;
        i += s.size();
      }
    }
    if(!tmp){
      ans = false;
      break;
    }
  }
  YESNO(ans);
  return 0;
}