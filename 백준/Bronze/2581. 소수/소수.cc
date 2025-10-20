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

        for(int i = 2; i <= N; i++){
            sieve_table[i] = true;
        }

        for(int i = 2; i*i<=N; i++){
            if(sieve_table[i]){
                for(int j = i*i; j<=N; j+=i){
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

    constexpr int MAX_PRIME = 10001;
    constexpr ConstexprSieve<MAX_PRIME> prime_table;

    int M, N; cin >> M >> N;
    int ans = 0;
    int MIN = 0;
    for(int i=M; i <= N; i++){
        if(prime_table.is_prime(i)) {
            ans += i;
            if(!MIN) MIN = i;
        }
    }
    if(ans == 0) cout << -1;
    else{
        cout << ans << '\n' << MIN;
    }
}

