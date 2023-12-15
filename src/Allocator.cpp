//
// Created by rakin on 12/14/2023.
//

#include "Allocator.h"

#include <string_view>
#include <memory>

Allocator::Allocator(std::size_t size, uint32_t objects,
              std::string_view *name)
        : m_ptr{std::make_unique<int[]>(size)} {
}
