//
// Created by rakin on 12/15/2023.
// Test file for Linked List.
//

#include "LinkedList.h"

#include <gtest/gtest.h>

namespace
{
TEST(LinkedListTest, GetFirstElement)
{
    LinkedList<int> list{};
    list.append(42);
    EXPECT_EQ(42, list.first());
}
} // namespace
