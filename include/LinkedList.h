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
    LinkedList() : m_head{nullptr}, m_tail{nullptr} {}

    /**
     * @brief Add data to the end of the list.
     * @param data Data of type T.
     * @return Last node from the list.
     */
    const Node *append(T data)
    {
        std::unique_ptr<Node> temp{};
        temp->data = data;
        temp->next = nullptr;

        std::unique_ptr<Node> lastNode{nullptr};

        if (this->m_head == nullptr)
        {
            this->m_head = temp;
            lastNode = this->m_head;
        }
        else
        {
            // TODO: Choose a better name for this.
            std::unique_ptr<Node> ptr{this->m_head};
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            lastNode = ptr->next;
        }

        return lastNode;
    }

  private:
    std::unique_ptr<Node> m_head{};
    std::unique_ptr<Node> m_tail{};
};

#endif // HEAP_ALLOCATOR_LINKEDLIST_H
