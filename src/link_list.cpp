#include "link_list/link_list.hpp"

namespace cjl
{
  Node::Node (const int& value)
    : value{value}
  {
  }

  LinkedList::LinkedList()
    : head{nullptr}
    , tail{nullptr}
    , length{0}
  {
  }

  LinkedList::LinkedList(const int& value)
  {
    head = tail = new Node{value};
    length = 1;
  }

  LinkedList::~LinkedList()
  {
    auto temp = head;
    while (head)
    {
      head = temp->next;
      delete temp;
      temp = head;
    }
  }

  void LinkedList::printList() const
  {
    Node* temp = head;
    while (temp)
    {
      std::cout << temp->value << '\n';
      temp = temp->next;
    }
  }

  void LinkedList::printHead() const
  {
    if (head)
    {
      std::cout << "Head: " << head->value << '\n';
    }
    else
    {
      std::cout << "Head: nullptr\n";
    }
  }

  void LinkedList::printTail() const
  {
    if (head)
    {
      std::cout << "Tail: " << tail->value << '\n';
    }
    else
    {
      std::cout << "Tail: nullptr\n";
    }
  }

  void LinkedList::printLength() const
  {
    std::cout << "Length: " << length << '\n';
  }

  Node* LinkedList::getHead() const
  {
    return head;
  }

  Node* LinkedList::getTail() const
  {
    return tail;
  }

  int LinkedList::getLength() const
  {
    return length;
  }

  void LinkedList::append(const int& value)
  {
    Node* new_node = new Node{value};
    if (length == 0)
    {
      head = tail = new_node;
    }
    else
    {
      tail->next = new_node;
      tail = new_node;
    }
    ++length;
  }

  void LinkedList::deleteLast()
  {
    if (length == 0)
    {
      return;
    }
    Node* temp = head;
    if (length == 1)
    {
      head = tail = nullptr;
    }
    else
    {
      Node* pre_temp = nullptr;
      while (temp->next)
      {
        pre_temp = temp;
        temp = temp->next;
      }
      tail = pre_temp;
      tail->next = nullptr;
    }
    delete temp;
    --length;
  }

  void LinkedList::prepend(const int& value)
  {
    Node* new_node = new Node{value};
    if (length == 0)
    {
      head = tail = new_node;
    }
    else
    {
      new_node->next = head;
      head = new_node;
    }
    ++length;
  }

  void LinkedList::deleteFirst()
  {
    if (length == 0)
    {
      return;
    }
    Node* temp;
    if (length == 1)
    {
      temp = head;
      head = tail = nullptr;
    }
    else
    {
      temp = head;
      head = head->next;
    }
    delete temp;
    --length;
  }

  Node* LinkedList::get(const int& index) const
  {
    if (index < 0 || index >= length)
    {
      return nullptr;
    }
    auto temp = head;
    std::vector<std::size_t> idx(index);
    for (const auto &id : idx)
    {
      temp = temp->next;
    }
    return temp;
  }

  bool LinkedList::set(const int& index, const int& value)
  {
    if (index < 0 || index >= length)
    {
      return false;
    }
    auto temp = get(index);
    if (temp)
    {
      temp->value = value;
      return true;
    }
    return false;
  }

  bool LinkedList::insert(const int& index, const int& value)
  {
    if (index < 0 || index >= length)
    {
      return false;
    }
    if (index == 0)
    {
      prepend(value);
      return true;
    }
    if (index == length)
    {
      append(value);
      return true;
    }
    Node* new_node = new Node{value};
    Node* temp = get(index - 1);
    if (temp)
    {
      new_node->next = temp->next;
      temp->next = new_node;
      ++length;
      return true;
    }
    return false;
  }

  void LinkedList::deleteNode(const int& index)
  {
    if (index < 0 || index >= length)
    {
      return;
    }
    if (index == 0)
    {
      return deleteFirst();
    }
    if (index == length)
    {
      return deleteLast();
    }
    Node* temp = get(index - 1);
    Node* to_be_deleted = temp->next;
    temp->next = to_be_deleted->next;
    delete to_be_deleted;
    --length;
  }

} // cjl

