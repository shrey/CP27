

//Shrey Dubey


#include    <iostream>
#include    <string>
#include    <algorithm>
#include    <map>
#include    <unordered_map>
#include    <vector>
#include    <set>
#include    <list>
#include    <iomanip>
#include    <queue>
#include    <stack>
#include    <math.h>
#include    <climits>
#include    <bitset>
#include    <cstring>
#include    <numeric>
#include    <array>
#include    <deque>
#include    <cstdlib>
#include    <cstdio>
#include    <stdlib.h>
#include    <cerrno>
#include    <ctime>
#include    <unordered_set>
#include    <cstring>
#include    <cmath>
#include    <random>
#include    <functional>
#include    <cassert>
#include    <bitset>
#include    <chrono>


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
#define bct(x) __builtin_popcountll(x)
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
#define vs vector<string>
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
#define LG 20
#define INF 1e18
#define p 1000000007

ll dx[] = {1,0,-1,0}; // x += dx[0], y += dy[0]
ll dy[] = {0,1,0,-1}; // x += 1, y += 0 -> D
string direction = "DRUL";

/*

...
...
...

*/
const ll mod = 1e9 + 7;

ll cl(ld a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll flr(ld a){
    if(a < 0.0){
        return (ll) a - 1;
    }
    return (ll) a;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

ll pw(ll n, ll k){
    if(k == 0) return 1;
    ll t = pw(n,k/2);
    ll ans = (t*t)%mod;
    if(k % 2) return (ans*n)%mod;
    else return ans;
}

//code starts here

const ll M = 1010;
char mat[M][M];
ll vis[M][M];
pll par[M][M];
char dir[M][M];
ll n,m;


bool ok(ll i, ll j){
    if(i >= 0 && j >= 0 && i < n && j < m && mat[i][j] != '#' && !vis[i][j]) return true;
    return false;
}

void solve(){
    re n; re m;
    pll src, dest;
    forn(i,n){
        forn(j,m){
            re mat[i][j];
            if(mat[i][j] == 'A') src = mp(i,j);
            if(mat[i][j] == 'B') dest = mp(i,j);
        }
    }
    queue<pair<ll,ll> > q;
    q.push(src);
    while(!q.empty()){
        auto cur = q.front();
        // cout<<cur.ff<<"()"<<cur.sec<<"\n";
        q.pop();
        forn(k,4){
            ll x = cur.ff + dx[k], y = cur.sec + dy[k];
            if(ok(x,y)){
                vis[x][y] = 1;
                dir[x][y] = direction[k]; // the direction i choose from parent to visit x,y
                par[x][y] = cur; // marking of parent
                q.push(mp(x,y));
            }
        }
    }
    if(!vis[dest.ff][dest.sec]){
        NO;
        return;
    }
    YES;
    string ans = "";
    pll cur = dest;
    while(true){
        ans += dir[cur.ff][cur.sec];
        cur = par[cur.ff][cur.sec];
        if(cur == src) break;
    }
    reverse(all(ans));
    pr(ans.length());
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    // re t;
    while(t--) solve();
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
// always check for n = 1 condition
// check loop starting and end points :(
//when dividing with mod, use mod inverse

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
