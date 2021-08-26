#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> ti;
 
using namespace __gnu_pbds;
template <class T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (ll i = (a), _b = (b); i < _b; i++)
#define FORD(i, b, a) for (ll i = (b), _a = (a); i > _a; i--)
#define pb push_back
 
#define vout(v)               \
	do {                      \
		for (auto i : v)      \
			cout << i << ' '; \
		cout << '\n';         \
	} while (false)
 
#define matout(mat)               \
	do {                          \
		for (auto i : mat) {      \
			for (auto j : i)      \
				cout << j << ' '; \
			cout << '\n';         \
		}                         \
	} while (false)
 
#define vin(v)        \
	for (auto &i : v) \
	cin >> i
 
#define matin(mat)          \
	do {                    \
		for (auto &i : mat) \
			vin(i);         \
	} while (false)
 
ld PI = 3.141592653589793238;
ll M = 1e9 + 7;
 
ll gcd(ll a, ll b) {
	if (a > b)
		return gcd(b, a);
	if (a == 0)
		return b;
 
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
	if (n == 2)
		return true;
	if (n < 2)
		return false;
	if (n % 2 == 0)
		return false;
 
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0)
			return false;
	}
 
	return true;
}
 
bool is_palindrome(string s) {
	return equal(s.rbegin(), s.rend(), s.begin());
}
 
void insert(set<pll>& low, set<pll>& high, ll& left, ll& right, pll p, ll k) {
	if (*(low.rbegin()) > p) {
		low.insert(p);
		left += p.first;
		if (low.size() > (k + 1) / 2) {
			high.insert(*(low.rbegin()));
			right += low.rbegin()->first;
			left -= low.rbegin()->first;
			low.erase(*(low.rbegin()));
		}
	} else {
		high.insert(p);
		right += p.first;
		if (high.size() > k / 2) {
			left += high.begin()->first;
			low.insert(*(high.begin()));
			right -= high.begin()->first;
			high.erase(*(high.begin()));
		}		
	}
}
 
void remove(set<pll>& low, set<pll>& high, ll& left, ll& right, pll p, ll k) {
	if (*(low.rbegin()) >= p) {
		low.erase(p);
		left -= p.first;
	} else {
		high.erase(p);
		right -= p.first;
	}
 
	if (low.empty()) {
		left += high.begin()->first;
		low.insert(*(high.begin()));
		right -= high.begin()->first;
		high.erase(*(high.begin()));
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll t, n, m, k, q, x, y;
	string s;
	bool flag;
 
	set<pll> low, high, st;
	set<pll>::iterator it, it2;
	cin >> n >> k;
	vll v(n);
	vin(v);
 
	if (k == 1) {
		vout(vll(n, 0));
		return 0;
	}
 
	//n = 10;
	//k = 1;
	//vll v = {2, 4, 3, 5, 8, 1, 2, 1};
	//vll v(n, 1);
 
	ll left = 0, right = 0;
	low.insert({v[0], 0});
	left = v[0];
	FOR (i, 1, k)	insert(low, high, left, right, {v[i], i}, k);
 
	ll j = k, i = 0, med;
	bool odd = k % 2;
	
	while (j <= n) {
		med = low.rbegin()->first;
		cout << med * low.size() - left + right - med * high.size() << ' ';
		remove(low, high, left, right, {v[i], i}, k);
		if (j < n)	insert(low, high, left, right, {v[j], j}, k);
		i++;
		j++;
	}
	cout << '\n';
 
	return 0;
}
