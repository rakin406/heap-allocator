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
    list.append(4);
    list.append(2);
    EXPECT_EQ(42, list.first());
}

TEST(LinkedListTest, GetLastElement)
{
    LinkedList<int> list{};
    list.append(4);
    list.append(2);
    list.append(42);
    EXPECT_EQ(42, list.last());
}

TEST(LinkedListTest, CountElement)
{
    LinkedList<int> list{};
    list.append(42);
    list.append(42);
    list.append(42);
    EXPECT_EQ(3, list.count(42));
}
} // namespace
