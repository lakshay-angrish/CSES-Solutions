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
typedef vector<pair<int, int> > vp;
typedef pair<int, int> pr;
typedef tuple<int, int, int> ti;

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i > _a; i--)
#define pb push_back
#define print(v) cout << v << '\n'
#define pr_vec(v)   for (auto i: v) cout << i << ' '
#define vin(v)  for (auto &i: v)    cin >> i

ld pi = 3.141592653589793238;
ll M = 1e9 + 7;

int gcd(int a, int b) {
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t, n, m, k, q, x, y;
	string s;
	bool flag;

	cin >> t;
	while (t--) {
		cin >> x >> y;
        ll i, j;
        n = max(x, y);
        m = n * n;
        if (n & 1) {
            i = 1;
            j = n;            
        } else {
            i = n;
            j = 1;
        }

        m -= abs(i - x) + abs(j - y);
        cout << m << '\n';
	}

    return 0;
}
