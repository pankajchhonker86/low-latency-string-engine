#include <iostream>
#include <iomanip>
#include "custom_string.hpp"

int main() {
    std::cout << "=== Low-Latency String Engine Execution ===\n\n";

    LowLatencyString small_str("Stack Context Buffer");
    LowLatencyString large_str("Enforcing heap fallback routine allocation due to size threshold parameters scaling past maximum stack buffer allocation size.");

    std::cout << "String: \"" << small_str.c_str() << "\"\n";
    std::cout << "Allocated on Heap: " << std::boolalpha << small_str.is_heap_allocated() << "\n\n";

    std::cout << "String: \"" << large_str.c_str() << "\"\n";
    std::cout << "Allocated on Heap: " << std::boolalpha << large_str.is_heap_allocated() << "\n\n";

    CustomStringView view(large_str.c_str(), 9);
    std::cout << "Zero-Copy Token Substring View Size: " << view.size() << " bytes\n";

    return 0;
}