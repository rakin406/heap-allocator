//
// Created by rakin on 12/14/2023.
//

#ifndef HEAP_ALLOCATOR_ALLOCATOR_H
#define HEAP_ALLOCATOR_ALLOCATOR_H

#include "LinkedList.h"

// NOTE: This is an unfinished project.

/**
 * @brief Class for heap allocation.
 * @tparam T Type
 */
template <class T>
class Allocator
{
  public:
    /**
     * @brief Constructor.
     * @param size Size of the fixed blocks.
     * @param objects Maximum number of objects.
     */
    Allocator(std::size_t size, int objects = 0) {}

    /**
     * @brief Destructor.
     */
    ~Allocator() {}

    void* allocate()
    {
        T* ptr{};
        m_freeList.append(ptr);
    }

    void* deallocate(void* memory) { m_freeList.append(memory); }

  private:
    const std::size_t m_blockSize{};
    const std::size_t m_objectSize{};
    LinkedList<T> m_freeList{};
};

#endif  // HEAP_ALLOCATOR_ALLOCATOR_H
