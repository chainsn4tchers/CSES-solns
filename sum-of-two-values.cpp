/*-----------------------------------------------
  
-----------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define vin(v) for (auto& x : v) cin >> x
#define pb(x) push_back(x);
#define mp(x, y) make_pair(x, y);
#define sz(x) (int)x.size()
#define log(x) cout << x << '\n'
 
typedef unsigned long long ull;
typedef long double         ld;
typedef long long           ll;
typedef double              dd;
 
const int MOD = 1000000007;
// const int MOD = 998244353;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> v{a};
	sort(v.begin(), v.end());
	int i = 0, j = n - 1;
	pair<int, int> p{-1, -1};
	while (i < j)
	{
		int t = v[i] + v[j];
		if (t == x)
		{
			p.first = v[i];
			p.second = v[j];
			break;
		}
		else if (t < x) ++i;
		else --j;
	}
 
	if (p.first < 0) cout << "IMPOSSIBLE\n";
	else
	{
		for (int i = 0; i < sz(a); ++i)
			if (a[i] == p.first)
			{
				p.first = i;
				cout << i + 1 << ' ';
				break;
			}
		for (int i = 0; i < sz(a); ++i)
			if (a[i] == p.second && i != p.first)
			{
				cout << i + 1 << endl;
				break;
			}
	}
	return 0;
}
