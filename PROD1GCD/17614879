#include <bits/stdc++.h>
 
using namespace std;

vector <long long> primes;

const int N = 10000000;

int lp[N+1];

void genPrimes() {
    primes.reserve(N / 10);
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int p : primes) {
            int q = i * p;
            if (q > N || p > lp[i]) {
                break;
            }
            lp[q] = p;
        }
    }
}

long long mod = 1000000007;

long long pw(long long a, long long n) {
    n %= mod - 1;
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a;
            if (res >= mod) {
                res %= mod;
            }
        }
        a = a * a;
        if (a >= mod) {
            a %= mod;
        }
        n >>= 1;
    }
    return res;
}

long long solve(int n, int m) {
    if (n > m) {
        swap(n, m);
    }
    long long res = 1;
    for (int p : primes) {
        if (p > n) break;
        long long pa = 0;
        long long n1 = n, m1 = m;
        while (n1 && m1) {
            n1 /= p, m1 /= p;
            pa += n1 * m1;
        }
        
        res = res * pw(p, pa);
        if (res >= mod) {
            res %= mod;
        }
    }
    return res;
}

int main() {
     genPrimes();
    int t;
    scanf("%d",&t);
    while(t--) {
       
        int n, m;
        scanf("%d %d",&n,&m);
        printf("%lld\n",solve(n, m));
    }

    return 0;
}