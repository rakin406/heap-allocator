//
// Created by rakin on 12/15/2023.
// Test file for Linked List.
//

#include "LinkedList.h"

#include <gtest/gtest.h>

namespace
{
// THE ANSWER TO LIFE, THE UNIVERSE, AND EVERYTHING!
constexpr int ANSWER{42};

TEST(LinkedListTest, GetFirstElement)
{
    LinkedList<int> list{};
    list.append(ANSWER);
    EXPECT_EQ(ANSWER, list.first());
}
} // namespace
