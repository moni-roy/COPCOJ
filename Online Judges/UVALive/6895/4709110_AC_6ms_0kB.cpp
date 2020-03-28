#include <bits/stdc++.h>
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
//~ Output                  
#define endl                '\n'
#define nl                  puts("")
#define sp                  printf(" ");
#define tcase(cs)           printf("Case %d:",++cs)
#define pri(a)              printf("%d",a)
#define prl(a)              printf("%lld",a)
#define prd(a)              printf("%lf",a)

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)

//~ cout << fixed << setprecision(20) << p << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

/******************************Let's GO*********************************/

int ts,n,m1,m2,m3,k,a,flg,Ans;
mii tue;
int fls[1505][1505];

int main()
{
	cin>>ts;
	while(ts--){
		tue.clear();
		zero(fls);
		cin>>n>>m1>>m2>>m3;
		for (int i = 0; i < m1; i += 1)
		{
			cin>>a;
			tue[a]=1;
		}
		flg=0;
		for (int i = 0; i < m2; i += 1)
		{
			cin>>k;
			for (int j = 0; j < k; j += 1)
			{
				cin>>fls[i][j];
				
			}
		}
		for (int i = 0; i < m3; i += 1)
		{
			cin>>k;
			for (int j = 0; j < k+1; j += 1)
			{
				cin>>a;
				tue[a]=1;
			}
		}
		Ans=1;
		for (int i = 0; i < m2; i += 1)
		{
			flg=0;
			for (int j = 0;  fls[i][j]; j += 1)
			{
				if(!tue[fls[i][j]])
				{
					flg=1;
				}
			}
			if(flg==0){
				Ans=0;
				break;
			}
		}
		
		if(Ans) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
2
6 2 1 5
1
2
3 1 2 6
1 1 6
1 2 6
2 1 6 3
2 2 4 1
2 5 6 2
6 2 0 5
1
2
1 1 6
1 2 6
2 1 6 3
2 2 4 1
2 5 6 2
*/