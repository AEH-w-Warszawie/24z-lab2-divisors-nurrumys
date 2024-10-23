#include <iostream>
#include <vector>

std::vector<int> divisors(int n) {
    std::vector<int> divs;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
        }
    }
    return divs;
}

void printDivisors(const std::vector<int>& divs) {
    for (int d : divs) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}


