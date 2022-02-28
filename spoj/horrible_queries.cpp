#include <bits/stdc++.h>

#define vi vector<int>
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define f(i, x, n) for (int i = x; i < n; i++)
#define ll long long int
using namespace std;

int main()
{
    optimize();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        ll a[n];
        memset(a, 0, sizeof(a));
        while (c--)
        {   
            ll x;
            cin >> x;
            ll p, q, v;
            if (x == 0)
            {
                cin >> p >> q >> v;
                for (ll i = p-1; i < q; i++)
                {
                    a[i] += v;
                }
            }
            else if(x==1)
            {
                cin >> p >> q;
                ll sum = 0;
                for (ll i = p-1; i < q; i++)
                {
                    sum += a[i];
                }
                cout << sum << endl;
            }
        }
    }
    return 0;
}