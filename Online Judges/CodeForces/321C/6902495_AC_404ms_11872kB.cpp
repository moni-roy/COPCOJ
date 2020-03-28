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

#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define mem(a,b)            memset(a,b,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define IO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define gcd(a,b)            __gcd(a,b)

#define I(a)                scanf("%d",&a)
#define I2(a,b)             scanf("%d%d",&a,&b)
#define L(a)                scanf("%lld",&a)
#define L2(a,b)             scanf("%lld%lld",&a,&b)
#define D(a)                scanf("%lf",&a)

#define SP                  cout<<" ";
#define PI(a)               printf("%d",a)
#define PL(a)               printf("%lld",a)
#define PD(a)               printf("%lf",a)
#define CHK                 cout<<"MK"<<endl

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}
template <class T> inline string to_str(T t) { stringstream ss; ss<<t; return ss.str();}

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

#define MX 100010
#define MD 1e9+7

vi g[MX];
int vs[MX],subTree[MX],total,Ans[MX];

void DFS(int u,int p){
	subTree[u]=1;
	total++;
	for(int i=0;i<(int)g[u].size();i++){
		int v = g[u][i];
		if( v == p || vs[v]) continue;
		DFS(v,u);
		subTree[u] += subTree[v];
	}
	return ;
}

int GetCenter(int u,int p){
	for(int i=0;i<(int)g[u].size();i++){
		int v = g[u][i];
		if(vs[v] || v == p) continue;
		if(subTree[v] > total/2){
			return GetCenter(v,u);
		}
	}
	return u;
}

void Decompose(int u,int l){
	total = 0;
	DFS(u,-1);
	int center = GetCenter(u,-1);
	vs[center]=1;
	Ans[center]= 'A'+l;
	for(int i=0;i<(int)g[center].size();i++){
		int v = g[center][i];
		if(vs[v]) continue;
		Decompose(v,l+1);
	}
	return ;
}

int main()
{
	IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int n,a,b;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	//~ CHK;
	Decompose(1,0);
	for(int i=1;i<=n;i++){
		cout<<(char)Ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
