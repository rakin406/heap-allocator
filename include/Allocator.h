//
// Created by rakin on 12/14/2023.
//

#ifndef HEAP_ALLOCATOR_ALLOCATOR_H
#define HEAP_ALLOCATOR_ALLOCATOR_H

#include <memory>

class Allocator {
public:
    Allocator(std::size_t size);

    ~Allocator();

private:
    std::size_t m_size{};
    std::unique_ptr<int[]> m_ptr{};
};

#endif //HEAP_ALLOCATOR_ALLOCATOR_H
