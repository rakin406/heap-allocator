//
// Created by rakin on 12/15/2023.
// Test file for Linked List.
//

#include "LinkedList.h"

#include <gtest/gtest.h>

namespace
{
TEST(LinkedListTest, FirstElement)
{
    LinkedList<int> list{};
    list.append(42);
    list.append(4);
    list.append(2);
    EXPECT_EQ(42, list.first());
}

TEST(LinkedListTest, LastElement)
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
    list.append(0);
    EXPECT_EQ(2, list.count(42));
}

TEST(LinkedListTest, EmptyList)
{
    LinkedList<int> list{};
    EXPECT_TRUE(list.isEmpty());
    list.append(42);
    EXPECT_FALSE(list.isEmpty());
}

TEST(LinkedListTest, ListSize)
{
    LinkedList<int> list{};
    list.append(0);
    list.append(0);
    list.append(7);
    EXPECT_EQ(3, list.size());
}

TEST(LinkedListTest, AppendElement)
{
    LinkedList<int> list{};
    list.append(42);
    EXPECT_EQ(42, list.first());
}

TEST(LinkedListTest, PrependElement)
{
    LinkedList<int> list{};
    list.prepend(1);
    EXPECT_EQ(1, list.first());
    list.prepend(0);
    EXPECT_EQ(0, list.first());
}

TEST(LinkedListTest, ClearList)
{
    LinkedList<int> list{};
    list.append(4);
    list.append(2);
    list.clear();
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedListTest, RemoveFirstElement)
{
    LinkedList<int> list{};
    list.append(4);
    list.append(2);
    list.popFirst();
    EXPECT_EQ(2, list.first());
}

TEST(LinkedListTest, RemoveLastElement)
{
    LinkedList<int> list{};
    list.append(4);
    list.append(2);
    list.popLast();
    EXPECT_EQ(4, list.last());
}
} // namespace
