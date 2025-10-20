#include <cmath>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;



template <size_t N>
struct ConstexprSieve{
    bool sieve_table[N+1];

    constexpr ConstexprSieve() : sieve_table{}{
        sieve_table[0] = sieve_table[1] = false;

        for(size_t i = 2; i <= N; i++){
            sieve_table[i] = true;
        }

        for(size_t i = 2; i*i<=N; i++){
            if(sieve_table[i]){
                for(size_t j = i*i; j<=N; j+=i){
                    sieve_table[j] = false;
                }
            }
        }
    }

    constexpr bool is_prime(size_t p) const{
        return (p <= N) ? sieve_table[p] : false;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int MAX_PRIME = 1001;
    constexpr ConstexprSieve<MAX_PRIME> prime_table;

    int N; cin >> N;
    
    int ans = 0;
    for(int i=0; i<N; i++){
        int sub; cin >> sub;
        if(prime_table.is_prime(sub)) ans++;
    }
    cout << ans;
}

