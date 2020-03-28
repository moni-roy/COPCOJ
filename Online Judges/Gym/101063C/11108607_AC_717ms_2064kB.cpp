#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
typedef double dl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef pair<int, pii> piii;
typedef vector<pii> vii;
typedef vector<piii> viii;

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

#define bitCount(x)          __builtin_popcountll(x)

template <class T> inline T BMOD( T p, T e, T m )
{
    T ret = 1;
    while ( e )
    {
        if ( e & 1 ) ret = ( ret * p ) % m;
        p = ( p * p ) % m;
        e >>= 1;
    }
    return ( T )ret;
}
template <class T> inline T MODINV( T a, T m )
{
    return BMOD( a, m - 2, m );
}
template <class T> inline T isPrime( T a )
{
    for ( T i = 2; i <= sqrt( double( a ) ); i++ )
    {
        if ( a % i == 0 )
        {
            return 0;
        }
    }
    return 1;
}
template <class T> inline T lcm( T a, T b )
{
    return ( a / gcd( a, b ) ) * b;
}
template <class T> inline T power( T a, T b )
{
    return ( b == 0 ) ? 1 : a * power( a, b - 1 );
}
template <class T> inline string to_str( T t )
{
    stringstream ss;
    ss << t;
    return ss.str();
}
//-------------------------------------

const int MX = 2000;
ll mp[MX + 10];
int main()
{
    int n, m, k, a;
    cin >> n >> m;
    for ( int i = 0; i < n; i++ )
    {
        cin >> k;
        int msk = 0;
        for ( int j = 0; j < k; j++ )
        {
            cin >> a;
            msk |= ( 1 << ( a - 1 ) );
        }
        mp[msk]++;
    }
    ll Ans = 0;
    double g;
    cin >> g;
    for ( int i = 1; i < ( 1 << m ); i++ )
    {
        for ( int j = i + 1 ; j < ( 1 << m ); j++ )
        {
            if ( mp[i] > 0 && mp[j] > 0 )
            {
                int t = bitCount( i & j );
                int tt = bitCount( i | j );
                if ( t * 1.0  >= ( tt * 1.0 * g ) )
                {
                    ll x = mp[i];
                    ll y = mp[j];
                    Ans += ( x * y );
                }
            }
        }
        Ans += ( mp[i] * ( mp[i] - 1 ) / 2 );
    }
    cout << Ans << endl;
    return 0;
}

