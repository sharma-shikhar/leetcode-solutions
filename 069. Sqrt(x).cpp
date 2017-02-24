class Solution {
public:
    int mySqrt(int x) {
        double epsilon = 1E-1;
        double guess = (double)x/2;
        while (abs(guess*guess - (double)x) > epsilon) {
            guess = (guess + (double)x/guess) / 2;
        }
        return guess;
    }
};