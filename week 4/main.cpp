
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

// Function to perform the calculation
double calculate(long long iterations, double param1, double param2) {
    double result = 1.0;
    // Loop for a large number of iterations
    for (long long i = 1; i <= iterations; ++i) {
        // Calculate intermediate values
        double j1 = i * param1 - param2;
        double j2 = i * param1 + param2;
        
        // Perform calculations and update result
        result -= (1.0 / j1);
        result += (1.0 / j2);
    }
    return result;
}

int main() {
    // Record the start time
    auto start_time = std::chrono::high_resolution_clock::now();
    
    // Call the calculate function with specified parameters
    // The multiplication by 4 is done after the function call as in the Python code
    double result = calculate(200000000LL, 4.0, 1.0) * 4.0;
    
    // Record the end time
    auto end_time = std::chrono::high_resolution_clock::now();
    
    // Calculate the duration of execution
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    
    // Print the result with high precision
    std::cout << std::fixed << std::setprecision(12) << "Result: " << result << std::endl;
    
    // Print the execution time with specified precision
    std::cout << std::fixed << std::setprecision(6) << "Execution Time: " << elapsed_time.count() << " seconds" << std::endl;
    
    return 0;
}
