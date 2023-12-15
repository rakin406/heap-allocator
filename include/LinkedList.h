//
// Created by rakin on 12/14/2023.
//

#ifndef HEAP_ALLOCATOR_LINKEDLIST_H
#define HEAP_ALLOCATOR_LINKEDLIST_H

#include <memory>

/**
 * @brief A custom implementation of linked list.
 * @tparam T Type
 */
template <class T> class LinkedList
{
  public:
    struct Node
    {
        T data{};
        std::unique_ptr<Node> next{};
    };

    /**
     * @brief Constructor
     */
    LinkedList() : m_head{nullptr}, m_tail{nullptr}, m_size{0} {}

    // ------- Element access -------

    /**
     * @brief Access the first element.
     * @return Data of type T.
     */
    [[nodiscard]] T first() const { return this->m_head->data; }

    /**
     * @brief Access the last element.
     * @return Data of type T.
     */
    [[nodiscard]] T last() const { return this->m_tail->data; }

    // ------- Capacity -------

    /**
     * @brief Check whether the list is empty.
     * @return True if the list is empty, and false otherwise.
     */
    [[nodiscard]] bool isEmpty() const { return this->m_size == 0; }

    /**
     * @brief Get the number of elements in the list.
     * @return The number of elements.
     */
    [[nodiscard]] int size() const { return this->m_size; }

    /**
     * @brief Add data to the end of the list.
     * @param data Data of type T.
     * @return Last node from the list.
     */
    const Node *append(T data)
    {
        std::unique_ptr<Node> newNode{};
        newNode->data = data;
        newNode->next = nullptr;

        std::unique_ptr<Node> lastNode{};

        if (this->m_head == nullptr)
        {
            this->m_head = newNode;
            lastNode = this->m_head;
        }
        else
        {
            // TODO: Choose a better name for this.
            std::unique_ptr<Node> temp{this->m_head};
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            lastNode = temp->next;
        }

        return lastNode.get();
    }

    /**
     * @brief Delete all data from the list.
     */
    void clear()
    {
        std::unique_ptr<Node> temp{this->m_head};
        while (temp->next != nullptr)
        {
            this->m_head = this->m_head->next; // Make next node the head
            temp = temp->next;
        }
    }

    /**
     * @brief Get the number of times the data appears in the list.
     * @param data Data of type T.
     * @return The number of data.
     */
    [[nodiscard]] int count(T data) const
    {
        std::unique_ptr<Node> temp{this->m_head};
        int count{0};
        while (temp->next != nullptr)
        {
            if (temp->data == data)
                ++count;
            temp = temp->next;
        }

        return count;
    }

  private:
    std::unique_ptr<Node> m_head{};
    std::unique_ptr<Node> m_tail{};
    int m_size{};
};

#endif // HEAP_ALLOCATOR_LINKEDLIST_H
