# Low-Latency String Engine

A high-performance, low-latency custom string implementation in C++ optimized for cache locality and minimal dynamic heap allocations. 

## 🚀 Key Features

*   **Small String Optimization (SSO):** Strings below a strict internal byte threshold (`STACK_CAPACITY`) are stored directly on the stack, bypassing expensive heap allocations entirely.
*   **Heap Fallback Routine:** Safely drops back to dynamic allocation dynamically when size thresholds exceed stack memory parameters.
*   **Zero-Copy Substring Tokenization:** Provides lightning-fast string views without triggering additional memory overhead or re-allocations.
*   **SIMD Vectorization Ready:** Compiles with targeted `-mavx2` optimization flags for high-throughput block operations.

## 🛠️ Compilation and Execution

Since the project uses performance-critical C++ features, it can be compiled directly via a native C++ compiler (supporting C++17 or higher) to bypass environment layout noise:

```powershell
# Compile the engine
g++ -std=c++1z -mavx2 -O3 -I./include (Get-ChildItem ./src/*.cpp | Select-Object -ExpandProperty FullName) -o string_engine.exe

# Run the executable
.\string_engine.exe