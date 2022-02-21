#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD 1000000007
#define sz(x) (int)x.size()
#define dMOD 1e9 + 7
#define dd double
#define LOG(x) cout << x << '\n'
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
    string s1, s2;
    cin >> s1 >> s2;
    int n = sz(s1);
    int m = sz(s2);
 
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; ++i)
    	for (int j = 0; j < m + 1; ++j)
    		if (i == 0 || j == 0) dp[i][j] = max(i, j);
    dp[0][0] = 0;
 
    for (int i = 1; i < n + 1; ++i)
    	for (int j = 1; j < m + 1; ++j)
    	{
    		if (s1[i - 1] != s2[j - 1])
    			dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
    		else
    			dp[i][j] = dp[i - 1][j - 1];
    	}
    LOG(dp[n][m]);
	return 0;
}
