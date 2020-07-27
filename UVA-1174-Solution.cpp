#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 50001
#define ll long long int
#define ull unsigned long long int
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define mod 100000007
#define pi acos(-1)
#define eps 1e-8
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / __gcd(a, b)
#define input(ara, n)          \
   for (int i = 0; i < n; i++) \
   scanf("%d", &ara[i])
#define inputl(ara, n)                   \
   for (long long int i = 0; i < n; i++) \
   scanf("%lld", &ara[i])
#define printcase(p) printf("Case %d: ", p)
#define pf(a) printf("%d\n", a);
#define pfl(a) printf("%lld\n", a);
#define pfi(a) printf("%d ", a);
#define pfll(a) printf("%lld ", a);
#define sc(a) scanf("%d", &a)
#define scc(a, b) scanf("%d %d", &a, &b)
#define sccdbl(a, b) scanf("%lf %lf", &a, &b)
#define sccc(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scccdbl(a, b, c) scanf("%lf %lf %lf", &a, &b, &c)
#define scl(a) scanf("%lld", &a)
#define sccl(a, b) scanf("%lld %lld", &a, &b)
#define scccl(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
using namespace std;
ll parent[2001], nodes, edges;
void initialize()
{
   for (ll i = 0; i < 2001; i++)
      parent[i] = i;
}
bool cmp(pair<ll, pll> a, pair<ll, pll> b)
{
   return a.first < b.first;
}
ll root(ll x)
{
   return parent[x] = (parent[x] == x) ? x : root(parent[x]);
}
void union_(ll x, ll y)
{
   ll p = root(x);
   ll q = root(y);
   parent[p] = parent[q];
}
ll kruskal(vector< pair<ll, pll> >&p)
{
   ll x, y, mnc = 0, cost;
   for (ll i = 0; i < edges; ++i)
   {
      x = p[i].second.first;
      y = p[i].second.second;
      cost = p[i].first;
      if (root(x) != root(y))
      {
         mnc += cost;
         union_(x, y);
      }
   }
   return mnc;
}
int main()
{
   int t;
   sc(t);
   while (t--)
   {
      ll c, mincost, j = 1;
      initialize();
      sccl(nodes, edges);
      unordered_map<string, ll> m;
      vector<pair<ll, pll> > p;
      string str, st;
      getchar();
      for (ll i = 0; i < edges; i++)
      {
         cin >> str >> st;
         if (m[str] == 0)
         {
            m[str] = j++;
         }
         if (m[st] == 0)
         {
            m[st] = j++;
         }
         scl(c);
         p.pb(mp(c, mp(m[str], m[st])));
      }
      sort(p.begin(), p.end(), cmp);
      mincost = kruskal(p);
      pfl(mincost);
      if (t != 0)
      {
         printf("\n");
      }
   }
   return 0;
}
