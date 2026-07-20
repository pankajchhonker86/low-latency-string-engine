#include "custom_string.hpp"
#include <cstring>

LowLatencyString::LowLatencyString(const char* str) {
    size_ = std::strlen(str);
    if (size_ <= STACK_CAPACITY) {
        std::memcpy(storage_.stack_buf, str, size_);
        storage_.stack_buf[size_] = '\0';
        is_heap_ = false;
    } else {
        storage_.heap_data.data = new char[size_ + 1];
        std::memcpy(storage_.heap_data.data, str, size_);
        storage_.heap_data.data[size_] = '\0';
        storage_.heap_data.capacity = size_;
        is_heap_ = true;
    }
}

LowLatencyString::~LowLatencyString() {
    if (is_heap_) {
        delete[] storage_.heap_data.data;
    }
}

const char* LowLatencyString::c_str() const {
    return is_heap_ ? storage_.heap_data.data : storage_.stack_buf;
}

size_t LowLatencyString::size() const { return size_; }
bool LowLatencyString::is_heap_allocated() const { return is_heap_; }