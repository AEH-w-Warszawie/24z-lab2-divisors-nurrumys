#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <chrono>

using namespace std;
using namespace std::chrono;


vector<long long> divisors(long long n) {
    set<long long> divisors_set;  
    for (long long i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors_set.insert(i);
            divisors_set.insert(n / i);  
        }
    }
    
    return vector<long long>(divisors_set.begin(), divisors_set.end());
}


double measure_time(long long n) {
    auto start = high_resolution_clock::now();
    divisors(n); 
    auto stop = high_resolution_clock::now();

   
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;  
}

int main() {
    vector<long long> numbers = { 10000000000, 1000000000000000, 10000000000000000,
                                 100000000000000000, 1000000000000000000 };

    for (long long num : numbers) {
        double time_taken = measure_time(num);
        cout << "Execution time for " << num << ": " << time_taken << " seconds" << endl;
    }

    return 0;
}
