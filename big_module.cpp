#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<math.h>
#include <cassert>

const int  inf = (int)1e9 + 7;
using namespace std;
template<typename T>
ostream& operator<< (ostream& out, const vector<T>& s) {
    for (const auto& i : s) {
        out << i << " ";
    }
    return out;
}
int mul(int a, int b) {
    return int((a * 1ll * b) % inf);
}
int pow(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = mul(a, ans);
            ans = ans % inf;
        }
        a = mul(a, a);
        b = b >> 1;
    }
    return ans;

}
const int N = 1000 * 200;
int f[N], F[N];

void precalc() {
    F[0] = f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = mul(f[i - 1], i);
        F[i] = pow(f[i], inf - 2);
    }
}
int C(int n, int k) {
    return mul(f[n], mul(F[n - k], F[k]));
}



int main() {
    precalc();
    cout << C(6, 4);
}

//-3 -2 -1 0 1 2 3 4 5 
