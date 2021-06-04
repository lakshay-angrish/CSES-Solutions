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
 
ll factor(ll n) {
	if (n % 2 == 0)	return 2;
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0)	return i;
	}
	return n;
}
 
int floor_index(vi& v, int l, int r, int k) {
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] <= k)	l = m;
		else			r = m;
	}
	return l;
}
 
int ceil_index(vi& v, int l, int r, int k) {
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] >= k)	r = m;
		else		l = m;
	}
	int ans = v[l] >= k ? l : r;
 
	if (ans < 0 || ans >= v.size())	return -1;
	return ans;
}

bool valid(vll& v, ll tasks, ll time) {
	ll done = 0;
	for (auto i: v)
		done += time / i;
	return done >= tasks;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll t, n, m, k, q, x, y;
	string s;
	bool flag;
 
	cin >> n >> t;
	vll v(n);
	vin(v);

	sort(v.begin(), v.end());

	ll left = 0, right = v[0] * t, mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (valid(v, t, mid))	right = mid;
		else					left = mid + 1;
	}

	cout << left << '\n';
 
	return 0;
}