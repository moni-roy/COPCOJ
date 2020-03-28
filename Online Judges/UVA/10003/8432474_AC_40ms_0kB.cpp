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
#define mkp                 make_pair
#define mem(a,b)            memset(a,b,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define IO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define gcd(a,b)            __gcd(a,b)
#define FOR(i,a,b)			for(int i=a;i<=b;i++)
#define RFOR(i,a,b)			for(int i=a;i>=b;i--)

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
template <class T> inline string toString(T t) { stringstream ss; ss<<t; return ss.str();}
template <class T> inline long long toLong(T t) {stringstream ss;ss<<t;long long ret;ss>>ret;return ret;}
template <class T> inline int toInt(T t) {stringstream ss;ss<<t;int ret;ss>>ret;return ret;}
template <class T> inline bool leapYear(T t){if(!(t%(T)400) || (!(t%(T)4) && t%(T)100)) return true; return false;}

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra
/*                 _                      */
/*____________|\/||_||\||_________________*/

string buffer;
int INT(){
	getline(cin,buffer);
	return toInt(buffer);
}
int LONG(){
	getline(cin,buffer);
	return toLong(buffer);
}

#define MX 1000010
#define MD 1e9+7

ll x[55],res[55][55],mid[55][55],l,k;

int main()
{
    IO;
    while(cin>>l && l)
    {
        cin>>k;
        for(int i=1;i<=k;i++) cin>>x[i];
        x[0]=0;
        x[++k]=l;
        for (int s = 0; s<=k; s++)                    //s - length(size) of substring
        {
            for (int L = 0; L+s<=k; L++)                //L - left point
            {
                int R = L + s;                            //R - right point
                if (s < 2)
                {
                    res[L][R] = 0;                          //DP base - nothing to break
                    mid[L][R] = L;                          //mid is equal to left border
                    continue;
                }
                int mleft = mid[L][R-1];                  //Knuth's trick: getting bounds on M
                int mright = mid[L+1][R];
                res[L][R] = 1000000000000000000LL;
                for (int M = mleft; M<=mright; M++)       //iterating for M in the bounds only
                {
                    ll tres = res[L][M] + res[M][R] + (x[R]-x[L]);
                    if (res[L][R] > tres)                   //relax current solution
                    {
                        res[L][R] = tres;
                        mid[L][R] = M;
                    }
                }
            }
        }
        ll Ans = res[0][k];
        cout<<"The minimum cutting is "<<Ans<<"."<<endl;
    }
    return 0;
}
