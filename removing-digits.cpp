#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD 1000000007
#define dMOD 1e9 + 7
#define dd double
#define LOG(x) cout << x << '\n'
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
    int n, count = 0;
    cin >> n;
	while (n > 0)
	{
		int i = n;
		int max = -1;
		while (i)
		{
			if (i % 10 > max) max = i % 10;
			i /= 10;
		}
		n = n - max;
		++count;
	}
	LOG(count);
	return 0;
}
