//
// Created by rakin on 12/14/2023.
//

#include "Allocator.h"

#include <memory>

Allocator::Allocator(std::size_t size)
        : m_ptr{std::make_unique<int[]>(size)} {
}
