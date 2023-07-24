#pragma once
#include <iostream>
#include <numeric>
#include <vector>

namespace cjl
{
  struct Node
  {
    int value{0};
    Node* next{nullptr};
    explicit Node (const int& value);
  };

  class LinkedList
  {
    public:
      LinkedList();
      LinkedList(const int& value);
      LinkedList(LinkedList &&) = default;
      LinkedList(const LinkedList &) = default;
      LinkedList &operator=(LinkedList &&) = default;
      LinkedList &operator=(const LinkedList &) = default;
      ~LinkedList();

      void printList() const;
      void printHead() const;
      void printTail() const;
      void printLength() const;
      Node* getHead() const;
      Node* getTail() const;
      int getLength() const;
      void append(const int& value);
      void deleteLast();
      void prepend(const int& value);
      void deleteFirst();
      Node* get(const int& index) const;
      bool set(const int& index, const int& value);
      bool insert(const int& index, const int& value);
      void deleteNode(const int& index);
      void reserve();

    private:
      Node *head{nullptr}, *tail{nullptr};
      std::size_t length{0};
  };
} // cjl

