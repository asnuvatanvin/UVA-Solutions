#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 100001
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
int X[] = {-1, -1, 0, 0, 1, 1};
int Y[] = {-1, 0, -1, 1, 0, 1};
int node[201][201];
int visited[201][201];
int n;
bool bfs(int s1, int s2)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         visited[i][j] = false;
      }
   }
   queue<int> q;
   q.push(s1);
   q.push(s2);
   visited[s1][s2] = true;
   int u1, u2, v1, v2;
   while (!q.empty())
   {
      u1 = q.front();
      q.pop();
      v1 = q.front();
      q.pop();
      for (int i = 0; i < 6; i++)
      {
         u2 = u1 + X[i];
         v2 = v1 + Y[i];
         if (u2 >= 0 && v2 >= 0 && u2 < n && v2 < n && node[u2][v2] != 2 && visited[u2][v2] == false)
         {
            visited[u2][v2] = true;
            if (u2 == n - 1)
            {
               return true;
            }
            q.push(u2);
            q.push(v2);
         }
      }
   }
   return false;
}
int main()
{
   int i = 1;
   while (sc(n) && n)
   {
      string str;
      //getchar();
      int k = 0;
      for (int i = 0; i < n; i++)
      {
         cin >> str;
         for (int j = 0; j < n; j++)
         {
            if (str[j] == 'b')
            {
               node[i][j] = 1;
            }
            else
            {
               node[i][j] = 2;
            }
         }
      }
      for (int j = 0; j < n; j++)
      {
         if (node[0][j] == 1)
         {
            if (bfs(0, j))
            {
               printf("%d B\n", i++);
               k = 1; 
               break;
            }
         }
      }
      if (k == 0)
      {
         printf("%d W\n", i++);
      }
   }
   return 0;
}
