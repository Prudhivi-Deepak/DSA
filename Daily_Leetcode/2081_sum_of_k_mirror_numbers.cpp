#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long kMirror(int k, int n) {
        long long totalSum = 0;
        int foundCount = 0;

        for (int digitLength = 1; foundCount < n; digitLength++) {
            bool isOddLength = digitLength % 2 == 1;
            int prefixLength = (digitLength + 1) / 2;

            long long start = pow(10, prefixLength - 1);
            long long end = pow(10, prefixLength);

            for (long long prefix = start; prefix < end && foundCount < n; prefix++) {
                long long palindrome = isOddLength
                    ? buildOddPalindrome(prefix)
                    : buildEvenPalindrome(prefix);

                if (isPalindromeInBase(palindrome, k)) {
                    totalSum += palindrome;
                    foundCount++;
                }
            }
        }

        return totalSum;
    }

private:
    long long buildEvenPalindrome(long long prefix) {
        long long reversed = reverseDigits(prefix);
        int digitCount = prefix == 0 ? 1 : log10(prefix) + 1;
        return prefix * pow(10, digitCount) + reversed;
    }

    long long buildOddPalindrome(long long prefix) {
        long long trimmed = prefix / 10;
        long long reversed = reverseDigits(trimmed);
        int digitCount = trimmed == 0 ? 0 : log10(trimmed) + 1;
        return prefix * pow(10, digitCount) + reversed;
    }

    long long reverseDigits(long long x) {
        long long reversed = 0;
        while (x > 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return reversed;
    }

    bool isPalindromeInBase(long long number, int base) {
        vector<int> digits;
        while (number > 0) {
            digits.push_back(number % base);
            number /= base;
        }

        int i = 0, j = digits.size() - 1;
        while (i < j) {
            if (digits[i++] != digits[j--]) return false;
        }
        return true;
    }
};
