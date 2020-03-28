/* * * * * * * * * * * * * * *
 * :Krishna (MRoy)
 * :JU
 * :mkroy.cs@gmail.com
 * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
//~ c
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <climits>
//~ c++
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <functional>

using namespace std;

typedef long long          	ll;
typedef long long unsigned 	llu;
typedef double             	dl;
typedef pair<int,int>      	pii;
typedef pair<ll,ll>     	pll;
typedef vector<int>        	vi;
typedef vector<ll>        	vl;
typedef map<int,int> 		mii;
typedef map<ll,ll>         	mll;
typedef map<string,int>    	msi;
typedef map<char,int>      	mci;
typedef pair<int ,pii>      piii;
typedef vector<pii>         vpii;
typedef vector<piii>        vpiii;
//~ Define
#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define P                   push
#define zero(a)             memset(a,0,sizeof a)
#define minus(a)            memset(a,-1,sizeof a)
#define setinf(a)           memset(a,126,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define I_O                 ios_base::sync_with_stdio(0); cin.tie(0)
#define gcd(a,b)            __gcd(a,b)
//~ Input
#define sci(a)              scanf("%d",&a)
#define scii(a,b)           scanf("%d%d",&a,&b)
#define sciii(a,b,c)        scanf("%d%d%d",&a,&b,&c)
#define scl(a)              scanf("%lld",&a)
#define scll(a,b)           scanf("%lld%lld",&a,&b)
#define sclll(a,b,c)        scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a)              scanf("%lf",&a)
#define sc                  scanf
//~ Output
#define endl                '\n'
#define nl                  puts("")
#define sp                  printf(" ");
#define SP                  cout<<" ";
#define tcase(cs)           printf("Case %d:",++cs)
#define pri(a)              printf("%d",a)
#define prl(a)              printf("%lld",a)
#define prd(a)              printf("%lf",a)
#define pr                  printf

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

/******************************Let's GO*********************************/
ll n, m, cs = 0, x, p;
string s;
int main()
{
//    I_O;
    while (cin >> n >> m)
    {
        if (n + m == 0) break;
        queue<ll> q, qq;
        for (int i = 1; i <= min(n, 1000ll); i++) q.push(i);
        cout << "Case " << ++cs << ":" << endl;
        for (int i = 0; i < m; i++)
        {
            cin >> s;
            if (s == "N")
            {
                if (!q.empty()) cout << q.front(), q.push(q.front()), q.pop();
                else cout << qq.front(), qq.push(qq.front()), qq.pop();
                cout << endl;
            }
            else
            {
                cin >> x;
                if (q.empty())
                {
                    q.P(x);
                    while (!qq.empty())
                    {
                        p = qq.front(), qq.pop();
                        if (p != x) q.push(p);
                    }
                }
                else
                {
                    qq.P(x);
                    while (!q.empty())
                    {
                        p = q.front(), q.pop();
                        if (p != x) qq.push(p);
                    }
                }
            }
        }
    }
    return 0;
}
