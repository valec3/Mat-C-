#include <iostream>
#include <cmath>
typedef long long ll;

ll count_primes_up_to(ll n) {
    if (n < 2) {
        return 0;
    }

    ll count = 0;
    bool *is_prime = new bool[n + 1];
    std::fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i <= sqrt(n); ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            count++;
        }
    }

    delete[] is_prime;
    return count;
}

ll count_numbers_with_3_divisors(ll p, ll q) {
    ll count_q = count_primes_up_to(sqrt(q));
    ll count_p_minus_one = count_primes_up_to(sqrt(p - 1));

    return count_q - count_p_minus_one;
}
int main() {
    ll p, q;
    std::cin >> p >> q;

    ll result = count_numbers_with_3_divisors(p, q);

    std::cout << result << std::endl;

    return 0;
}
