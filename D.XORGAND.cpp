/*
Slypherx - Ayush Gupta
Pune Institute of Computer Technology
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define vin(v,n)     for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define all(xx)       xx.begin(), xx.end()

const int MOD = 1e9 + 7;
int fpow(int x, int y);
int gcd(int a, int b);

int msb(int n)
{
    int res = 0;
    while ((1LL << res) <= n)
        res++;
    return res;
}

void Slypher()
{
	int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> cnt(n + 1, vector<int>(32));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 32; j++)
            cnt[i + 1][j] = cnt[i][j];
        cnt[i + 1][msb(a[i])]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int p = msb(x), ans = 0;
        for (int i = 0; i < 32; i++)
            if (i != p)
                ans += cnt[r][i] - cnt[l - 1][i];
            cout << ans << '\n';
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test)
	{
		Slypher();
	}
	return 0;
}

int fpow(int x, int y)
{
	x = x % MOD;
	int sum = 1;
	while (y)
	{
		if (y & 1)sum = sum * x;
		sum %= MOD;
		y = y >> 1;
		x = x * x;
		x %= MOD;
	}
	return sum;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
