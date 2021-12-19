
//Shrey Dubey


#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<list>
#include<iomanip>
#include<queue>
#include<stack>
#include <math.h>
#include<climits>
#include<bitset>
#include<cstring>
#include<numeric>
#include<array>


using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define sec second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
#define imin INT_MIN
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define int long long
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
#define endl "\n"
#define nl cout<<"\n"
#define re cin >>
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)
#define all(x) x.begin(),x.end()

ll mod = 1e9 + 7;

ll cl(ld a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll flr(ld a){
    return (ll) a;
}



//code starts here

const ll M = 1e5+100;

void solve(){
    ll n,m; re n; re m;
    ll arr[n+1];
    for(ll i = 1; i<=n; i++){
        re arr[i];
    }
    bool ls[M] = {false}; // ls[i] is 1 if 1...i is sorted 1,2,3,4,..i, rs[i] is 1 if i,i+1...n is sorted it has
    bool rs[M] = {false};
    ls[1] = true;
    for(ll i = 2; i<=n; i++){
        if(arr[i] > arr[i-1]) ls[i] = ls[i-1];
        else ls[i] = false;
    }
    if(arr[n] == n) rs[n] = true;
    for(ll i = n-1; i>=0; i--){
        if(arr[i] == i) rs[i] = rs[i+1];
        else rs[i] = false;
    }
    vector<pair<ll,ld> > op(m);
    fo(m){
        re op[i].ff; re op[i].sec;
    }
    if(ls[n]){
        ld ans = 1.0;
        prDouble(ans);nl;
        return;
    }
    sort(op.begin(),op.end());
    ld ans = 0, alt = 1.0;
    for(auto p: op){
        if(ls[p.ff]) continue;
        // cout<<p.ff<<"()"<<alt<<"\n";
        if(p.ff == n || rs[p.ff + 1]){
            ans += alt*p.sec;
            alt *= (1-p.sec);
        }
    }
    if(ans > 1.0) ans = 1.0;
    prDouble(ans);nl;
}

int32_t main(){
    KOBE;
    ll t;
    re t;
    // t = 1;
    while(t--) solve();
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs


//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices