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
char a = '(';
char b = ')';
//再帰処理をさせてきそう<-させてこなかった

//ll=>base2(string)
string ll_to_s(ll n){
    string outp = "";
    rep(i,N){
        ll tmp = n%2;
        outp = char(tmp + '0') + outp;
        n /= 2;
    }
    return outp;
}

//0,1が同数か調べる
bool checkNum01(string s){
    int zero=0,one=0;
    rep(i,s.size()){
        if(s[i]=='0')zero++;
        else if(s[i]=='1')one++;
        if(zero<one) return false;//典型知識
    }
    if(zero==one)return true;
    return false;
}

//0,1を(,)に変換する
string convertSymbol(string s){
    string outp = "";
    rep(i,s.size()){
        if(s[i]=='0') outp =  outp + '(' ;
        else if(s[i]=='1') outp =outp +  ')';
    }
    return outp;
}

int main() {
    cin>>N;
    rep(i,pow(2,N)){
        string s = ll_to_s(i);
        if(checkNum01(s)){
            cout<<convertSymbol(s)<<endl;
        }
    }
    return 0;
}