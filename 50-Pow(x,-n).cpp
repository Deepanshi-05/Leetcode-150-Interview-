class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;  // Base case: x^0 = 1

    long long N = n;  // Use long long to handle edge case of INT_MIN
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    double result = 1.0;
    while (N > 0) {
        if (N % 2 == 1) {  // If N is odd
            result *= x;
        }
        x *= x;  // Square the base
        N /= 2;  // Reduce N by half
    }

    return result;
    }
};