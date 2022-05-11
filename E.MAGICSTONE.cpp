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

int power(int x, int y)
{
    if (y < 0)
        return 0;
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % M;
        x = x * x % M;
        y /= 2;
    }
    return res;
}
int fact[N], inv[N];

int choose(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    int ans = (fact[n] * inv[r]) % M;
    ans = (ans * inv[n - r]) % M;
    return ans;
}

void Slypher()
{
	int n, l, r;
        cin >> n >> l >> r;
        for (int i = l; i <= r; i++)
        {
            int ans = 0;
            if ((i + n) % 2 == 0)
                ans = choose(n, (i + n) / 2);
            cout << ans << ' ';
        }
        cout << '\n';
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
