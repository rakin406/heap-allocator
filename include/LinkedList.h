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
    [[nodiscard]] T first() const
    {
        if (this->isEmpty())
            return nullptr;
        return m_head->data;
    }

    /**
     * @brief Access the last element.
     * @return Data of type T.
     */
    [[nodiscard]] T last() const
    {
        if (this->isEmpty())
            return nullptr;
        return m_tail->data;
    }

    // ------- Capacity -------

    /**
     * @brief Get the number of times the data appears in the list.
     * @param data Data of type T.
     * @return The number of data.
     */
    [[nodiscard]] int count(T data) const
    {
        std::unique_ptr<Node> temp{m_head};
        int count{0};
        while (temp->next != nullptr)
        {
            if (temp->data == data)
                ++count;
            temp = temp->next;
        }

        return count;
    }

    /**
     * @brief Check whether the list is empty.
     * @return True if the list is empty, and false otherwise.
     */
    [[nodiscard]] bool isEmpty() const { return m_size == 0; }

    /**
     * @brief Get the number of elements in the list.
     * @return The number of elements.
     */
    [[nodiscard]] int size() const { return m_size; }

    // ------- Modifiers -------

    /**
     * @brief Add an element to the end of the list.
     * @param data Data of type T.
     */
    void append(T data)
    {
        std::unique_ptr<Node> newNode{};
        newNode->data = data;
        newNode->next = nullptr;

        if (this->isEmpty())
        {
            m_head = newNode;
        }
        else
        {
            m_tail->next = newNode;
        }

        m_tail = newNode;
        ++m_size;
    }

    /**
     * @brief Add an element to the beginning of the list.
     * @param data Data of type T.
     */
    void prepend(T data)
    {
        m_head = std::make_unique<Node>(data, m_head);
        if (this->isEmpty())
            m_tail = m_head;
        ++m_size;
    }

    /**
     * @brief Remove all elements from the list.
     */
    void clear()
    {
        std::unique_ptr<Node> temp{m_head};
        while (temp->next != nullptr)
        {
            m_head = m_head->next;
            temp = temp->next;
        }
        m_size = 0;
    }

    /**
     * @brief Remove the first element of the list.
     */
    void popFirst()
    {
        m_head = m_head->next;
        --m_size;
        if (this->isEmpty())
            m_tail = nullptr;
    }

    /**
     * @brief Remove the last element of the list.
     */
    void popLast()
    {
        // Get second last node
        std::unique_ptr<Node> temp{m_head};
        while (temp->next->next != nullptr)
            temp = temp->next;
        temp->next = nullptr;
        m_tail = temp;

        --m_size;
        if (this->isEmpty())
            m_tail = nullptr;
    }

  private:
    std::unique_ptr<Node> m_head{};
    std::unique_ptr<Node> m_tail{};
    int m_size{};
};

#endif // HEAP_ALLOCATOR_LINKEDLIST_H
