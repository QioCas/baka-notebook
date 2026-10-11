const int N = 1e7 + 5;
int spf[N];
vector<int> primes;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (!spf[i]) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (p > spf[i] || 1LL * i * p >= N)
                break;

            spf[i * p] = p;
        }
    }
}

// Tra ve cac cap {prime, exponent}
vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> res;

    while (x > 1) {
        int p = spf[x], cnt = 0;

        while (x % p == 0) {
            x /= p;
            cnt++;
        }

        res.push_back({p, cnt});
    }

    return res;
}