#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<ll, ll> > vp;
typedef pair<ll, ll> pr;
typedef tuple<ll, ll, ll> ti;

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i > _a; i--)
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

ld pi = 3.141592653589793238;
ll M = 1e9 + 7;

ll gcd(ll a, ll b) {
    if (a == 0) return b;

    return gcd(b % a, a);
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

bool compare(pr p1, pr p2) {
	return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, m, k, q, x, y;
    string s;
    bool flag;

	cin >> n >> k;

	vll nums(n);
	vin(nums);

	vll v = nums;

	sort(v.begin(), v.end());

	int i = 0, j = v.size() - 1;
	bool found = false;

	while (i < j) {
		if (i > 0 && v[i] == v[i - 1]) {
			i++;
			continue;
		}
		ll sum = v[i] + v[j];
		if (sum == k) {
			found = true;
			break;
		} else if (sum > k)	j--;
		else	i++;
	}

	if (found && v[i] + v[j] == k) {
		auto it = find(nums.begin(), nums.end(), v[i]);
		auto it2 = find(nums.rbegin(), nums.rend(), v[j]);

		i = it - nums.begin() + 1;
		j = nums.rend() - it2;

		cout << min(i, j) << ' ' << max(i, j) << '\n';
	}
	else	cout << "IMPOSSIBLE\n";

    return 0;
}
