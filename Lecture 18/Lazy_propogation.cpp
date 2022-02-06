

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

// ll dx[] = {1,0,-1,0};
// ll dy[] = {0,1,0,-1};

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

const ll M = 2e5+100;

vector<ll> st(4*M+1);
vector<ll> lazy(4*M+1);
ll a[M],n,q;


// v -> segment tree index
// tl -> leftmost index of the range, initially it's 0
// tr -> rightmost index of the range, initially it's n-1
void build(ll v, ll tl, ll tr){
    // cout<<v<<"()"<<tl<<"()"<<tr<<"\n";
    if(tl == tr){
        st[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm); // build the left half
    build(2*v+1,tm+1,tr); // build the right half
    st[v] = st[2*v] + st[2*v+1]; // change in case of max,min
}

// can also take the values of lazy vector to be -1 initially

// 3,4,5,6,7
// l = 1, r = 3, change = 8
// 3,8,8,8,7

void push(ll v, ll tl, ll tr, ll change){
    if(lazy[v] != 0){
        st[v] += (tr-tl+1)*lazy[v]; // st[v] += lazy[v] in case of max/min
        if(tl != tr){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if(change != 0){
        st[v] += change*(tr-tl+1); //change similarly to above
        if(tl != tr){
            lazy[2*v] += change;
            lazy[2*v+1] += change;
        }
    }
}

// to query the value
//l -> leftmost element of the query range
//r -> rightmost element of query range
// tl -> leftmost index of the original range, initially it's 0
// tr -> rightmost index of the original range, initially it's n-1


ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0; //change, max -> -1e15, min -> 1e15
    push(v,tl,tr,0);
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) + query(2*v+1,tm+1,tr,l,r); //change
}

//to update range
//l and r -> the range a[l...r]+= change to be done
//change is the number to be added

void update_range(ll v, ll tl, ll tr, ll l, ll r, ll change){
    push(v,tl,tr,0);
    if(tl > r || tr < l) return;
    if((tl >= l && tr <= r) || tl == tr){
        push(v,tl,tr,change);
        return;
    }
    ll tm = (tl + tr)/2;
    update_range(2*v,tl,tm,l,r,change);
    update_range(2*v+1,tm+1,tr,l,r,change);
    st[v] = st[2*v] + st[2*v+1]; //change here
}


void solve(){
    re n; re q;
    fo(n) re a[i];
    build(1,0,n-1);
    while(q--){
        ll t; re t;
        if(t == 1){
            ll l,r,x;
            re l; re r; re x;
            l--; r--;
            update_range(1,0,n-1,l,r,x);
        }else{
            ll k; re k;
            k--;
            ll ans = query(1,0,n-1,k,k);
            pr(ans);
        }
    }
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
