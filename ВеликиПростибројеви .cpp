#include <iostream>
#include <random>
using namespace std;

typedef uint64_t ull;
typedef __uint128_t uLL;

uLL stepen(ull a, ull n, ull m) {
    uLL res = 1;
    uLL base = a % m;
    while (n) {
        if (n & 1) res = (res * base) % m;
        base = (base * base) % m;
        n >>= 1;
    }
    return res;}

bool fermaovTest(ull p, int k) {
    if (p < 4) return p == 2 || p == 3;
    static random_device rd;
    static mt19937_64 gen(rd());
    uniform_int_distribution<ull> dist(2, p - 2);

    for (int i = 0; i < k; ++i) {
        ull a = dist(gen);
        if (stepen(a, p - 1, p) != 1)
            return false;
    }
    return true;
}

int main() {
    ull a;
    while (cin >> a) {
        if (fermaovTest(a, 10))  
            cout << a << endl;
    }
    return 0;}
