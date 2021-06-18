#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<int, int> > vpi;
typedef vector<pair<ll, ll> > vpll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> ti;
 
// template<class T> using ordered_set =__gnu_pbds::tree<T, null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (ll i = (a), _b = (b); i < _b; i++)
#define FORD(i, b, a) for (ll i = (b), _a = (a); i > _a; i--)
#define pb push_back
 
#define vout(v) do {					\
	for (auto i: v)	cout << i << ' ';	\
	cout << '\n';						\
} while (false)
 
#define matout(mat) do {					\
	for (auto i: mat) {						\
		for (auto j: i)	cout << j << ' ';	\
		cout << '\n';						\
	}										\
} while (false)
 
#define vin(v)  for (auto &i: v)    cin >> i
 
#define matin(mat) do {			\
	for (auto &i: mat)	vin(i);	\
} while (false)
 
ld PI = 3.141592653589793238;
ll M = 1e9 + 7;
 
ll gcd(ll a, ll b) {
	if (a > b)	return gcd(b, a);
	if (a == 0) return b;
 
	return gcd(b % a, a);
}
 
ll power(ll x, ll y) {
	if (y == 0)
		return 1;
 
	ll p = power(x, y / 2) % M;
	p = (p * p) % M;
 
	return y % 2 ? (x * p) % M : p;
}
 
bool is_prime(ll n) {
	if (n == 2) return true;
	if (n < 2) return false;
	if (n % 2 == 0) return false;
 
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return false;
	}
 
	return true;
}
 
bool is_palindrome(string s) {
	return equal(s.rbegin(), s.rend(), s.begin());
}
 
bool two_sum(vpll& v, ll sum, vll& temp, ll i = 0) {
	ll k = i;
	ll j = v.size() - 1;
	ll m;
	while (k < j) {
		if (k > i && v[k].first == v[k - 1].first) {
			k++;
			continue;
		}
		m = v[k].first + v[j].first;
		if (m == sum) {
			temp.push_back(v[k].second);
			temp.push_back(v[j].second);
			return true;
		}
		if (m < sum)	k++;
		else		j--;
	}
	return false;
}
 
bool k_sum(vpll& v, ll sum, ll k, vll& temp, ll start = 0) {
	if (k == 2)	return two_sum(v, sum, temp, start);
	ll i = start;
	while (i < v.size() - (k - 1)) {
		if (i > start && v[i].first == v[i - 1].first) {
			i++;
			continue;
		}
		temp.push_back(v[i].second);
		bool found = k_sum(v, sum - v[i].first, k - 1, temp, i + 1);
		if (found)	return true;
		temp.pop_back();
		i++;
	}
	return false;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll t, n, m, k, q, x, y;
	string s;
	bool flag;
 
	cin >> n >> t;
	vpll v;
	FOR (i, 0, n) {
		cin >> x;
		v.push_back({x, i + 1});
	}
 
	if (n < 3) {
		cout << "IMPOSSIBLE";
		return 0;
	}
 
	sort(v.begin(), v.end());
 
	vll ans;
 
	flag = k_sum(v, t, 3, ans);
 
	if (flag)	vout(ans);
	else			cout << "IMPOSSIBLE\n";
 
	return 0;
}

