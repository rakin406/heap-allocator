//
// Created by rakin on 12/14/2023.
//

#ifndef HEAP_ALLOCATOR_ALLOCATOR_H
#define HEAP_ALLOCATOR_ALLOCATOR_H

#include <string_view>
#include <memory>

 /**
  * @brief Class for heap allocation.
  */
class Allocator {
public:
    /**
     * @brief Constructor.
     * @param size Fixed memory block size.
     * @param objects Amount of blocks. 0 means get new blocks from the
     * heap as necessary. Default is 0.
     * @param name Allocator name.
     */
    Allocator(std::size_t size, uint32_t objects = 0,
              std::string_view *name = nullptr);

    ~Allocator();

private:
    std::size_t m_size{};
    std::unique_ptr<int[]> m_ptr{};
};

#endif //HEAP_ALLOCATOR_ALLOCATOR_H
