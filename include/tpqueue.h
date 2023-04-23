// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {  
 private:
    struct Item {
      T data;
      Item* next;
    } *head;
  Item* create(const T& value) {
    Item* item = new Item;
    item->data = value;
    item->next = nullptr;
    return item;
  }

 public:
  TPQueue(): head(nullptr) {}
  bool Empty() const {
    return (head == nullptr);
  }
  void push(const T& value) {
    Item* item = create(value);
    if (head == nullptr)
      head = create(value);
    else if (value.prior <= head->data.prior) {
      Item* current = head;
      while ((current->next != nullptr) && (current->next->data.prior > value.prior))
        current = current->next;
      item->next = current->next;
      current->next = item;
    } else {
      item->next = head;
      head = item;
    }
  }
  const T pop() {
    if (!Empty()) {
      Item* item = head->next;
      T value = head->data;
      head = item;
      return value;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
