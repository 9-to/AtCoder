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

ll H,W,ans;
ll P[12][10010];
//O(HW)=10^5
//行列を弄る問題

ll maximum_same(vector<ll> R) {
	map<ll, ll> Map; ll ret = 0;
	for (ll i = 0; i < R.size(); i++) {
		Map[R[i]] += 1;
		ret = max(ret, Map[R[i]]);
	}
	return ret;
}


int main() {
    //input
    cin>>H>>W;
    rep(i,H){
        rep(j,W)cin>>P[i][j];
    }
    ans = 0;
    //calculation
    for(ll i=1;i<(1<<H);i++){//h in Hの集合
        vector<ll> R;
        rep(j,W){
            ll idx = -1;
            bool flag = false;
            for(ll k=0;k<H;k++){
                if((i & (1<<k))==0)continue;//
                if(idx == -1)idx=P[k][j];
                else if(idx!=P[k][j])flag = true;//行(H)で一致しない
            }
            if(flag==false) R.push_back(idx);
        }
        ll cntH = 0, cntW = maximum_same(R);
        rep(j,H){
            if((i & (1<<j)) != 0) cntH++;
        }
        ans = max(ans,cntH*cntW);
    }

    //output
    cout<<ans<<endl;
    return 0;
}