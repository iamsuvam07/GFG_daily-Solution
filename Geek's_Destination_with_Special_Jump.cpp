
class Solution {
    using ll = long long;
    const ll MOD = 1e9 + 7;

    ll a, b, c, cycle;

    ll normalTime(ll x) {
        if (x <= a) return x;

        ll k = (x - a + c - 1) / c;

        return x + 2 * b * k;
    }

    ll sumNormal(ll L, ll R) {
        if (L > R) return 0;

        ll sumX = (L + R) * (R - L + 1) / 2;
        ll sumK = 0;

        L = max(L, a + 1);

        if (L > R) return sumX;

        for (ll rem = 0; rem < c; rem++) {

            ll first = L + (rem - L % c + c) % c;

            if (first > R) continue;

            ll cnt = (R - first) / c + 1;

            ll k = (first - a + c - 1) / c;

            sumK += cnt * k + cnt * (cnt - 1) / 2;
        }

        return sumX + 2 * b * sumK;
    }

public:
    int minTime(int A, int B, int d, int l, int r) {

        a = A;
        b = B;
        c = a - b;
        cycle = a + b;

        ll normal = normalTime(d);

        ll L = d - r;
        ll R = d - l;


        ll low = 1, high = d, limit = 0;

        while (low <= high) {

            ll mid = low + (high - low) / 2;

            if (normalTime(mid) + 1 < normal) {
                limit = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        ll beneficialR = min(R, limit);

        ll ans = 0;

        if (L <= beneficialR) {
            ans = sumNormal(L, beneficialR);
            ans += beneficialR - L + 1;
        }

        ll remainingL = max(L, limit + 1);

        if (remainingL <= R) {
            ans += (R - remainingL + 1) * normal;
        }

        return ans % MOD;


    }
};