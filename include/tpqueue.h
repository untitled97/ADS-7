// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Item {
        T value;
        Item* next;
    };
    Item* head = nullptr;
    Item* tail = nullptr;
    TPQueue::Item* create(const T&);
 public:
    bool isEmpty()const {
        return head == nullptr;
    }
    void push(const T&);
    T pop();
    ~TPQueue() {
        while (head != nullptr) {
            pop();
        }
    }
};

template<typename T>
T TPQueue<T>::pop() {
    if (isEmpty()) {
        throw std::string("Empty!");
    } else {
        Item* temp = head->next;
        T value = head->value;
        delete head;
        head = temp;
        return value;
    }
}

template<typename T>
void TPQueue<T>::push(const T& value) {
    if (isEmpty()) {
        head = create(value);
    } else if (head->value.prior < value.prior) {
        Item* temp = new Item;
        temp->value = value;
        temp->next = head;
        head = temp;
    }

template<typename T>
typename TPQueue<T>::Item* TPQueue<T>::create(const T& value) {
    Item* temp = new Item;
    temp->value = value;
    temp->next = nullptr;
    return temp;
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
