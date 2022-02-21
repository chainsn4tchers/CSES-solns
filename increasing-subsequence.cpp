#include <bits/stdc++.h>
using namespace std;
 
#define pb(x) push_back(x)
 
int main()
{
	int n; cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	vector<int> lis {a[0]};
	for (int i = 1; i < n; ++i) {
		if (lis.back() < a[i]) lis.pb(a[i]);
		else {
			int index = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
			lis[index] = a[i];
		}
	}
 
	cout << lis.size() << endl;
}
