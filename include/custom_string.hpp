#pragma once
#include <cstddef>

class LowLatencyString {
private:
    static constexpr size_t STACK_CAPACITY = 23;

    struct HeapData {
        char* data;
        size_t capacity;
    };

    union Storage {
        char stack_buf[STACK_CAPACITY + 1];
        HeapData heap_data;
    };

    Storage storage_;
    size_t size_;
    bool is_heap_;

public:
    LowLatencyString(const char* str);
    ~LowLatencyString();
    
    LowLatencyString(const LowLatencyString&) = delete;
    LowLatencyString& operator=(const LowLatencyString&) = delete;

    const char* c_str() const;
    size_t size() const;
    bool is_heap_allocated() const;
};

class CustomStringView {
private:
    const char* ptr_;
    size_t length_;

public:
    CustomStringView(const char* str) : ptr_(str), length_(0) {
        while(str[length_] != '\0') length_++;
    }
    CustomStringView(const char* str, size_t len) : ptr_(str), length_(len) {}

    const char* data() const { return ptr_; }
    size_t size() const { return length_; }
};