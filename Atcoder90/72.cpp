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

ll H,W,ans=-1;
char C[20][20];
char f = '.';
char m = '#';
//全探索っぽいO(2^16*2^16)
ll dx[4] = {0,1,0,-1};
ll dy[4] = {1,0,-1,0};
bool used[20][20];//探索したかを確認する配列！

ll calc(ll sx,ll sy, ll px, ll py){//x==h,y==w
    if(sx==px && sy==py && used[px][py]==true)return 0;
    used[px][py] = true;
    ll outp = -17*17;
    rep(i,4){
        ll nx = px+dx[i], ny = py+dy[i];
        if(nx<0 || ny<0 || nx>=H || ny>=W || C[nx][ny]==m) continue;//端か山の場合
        if(!(sx==nx && sy==ny) && used[nx][ny]==true) continue;//次の地点が始点ではなく、通過不可能な場合
        ll v = calc(sx,sy,nx,ny);
        outp = max(outp,v+1);
    }
    used[px][py] = false;
    return outp;
}

int main() {
    //input
    cin>>H>>W;
    rep(i,H){
        rep(j,W)cin>>C[i][j];
    }
    rep(h,H){
        rep(w,W){
            ans = max(calc(h,w,h,w),ans);
        }
    }
    if(ans<=3) ans=-1;
    cout<<ans<<endl;
    return 0;
}