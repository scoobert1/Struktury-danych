#include <iostream>

class Node {
public:
  int number;
  Node *next;

  Node(int val) : number(val), next(nullptr) {}
};

class Linkedlist {
private:
  Node *_head;

public:
  Linkedlist() : _head(nullptr) {}

  ~Linkedlist() {
    while (_head) {
      Node *temp = _head;
      _head = _head->next;

      delete temp;
    }
  }

  void addToFront(int value) {
    Node *newNode = new Node(value);
    newNode->next = _head;

    _head = newNode;

    // std::cout << "Wartosc " << value << " zostala dodana na poczatek
    // listy.\n";
  }

  void addToEnd(int value) {
    Node *newNode = new Node(value);

    // std::cout << "Wartosc " << value << " zostala dodana na koniec listy.\n";

    if (!_head) {
      _head = newNode;

      return;
    }

    Node *current = _head;

    while (current->next) {
      current = current->next;
    }

    current->next = newNode;
  }

  void addAtIndex(int value, int index) {
    if (index == 0) {
      addToFront(value);
      return;
    }

    Node *newNode = new Node(value);
    Node *current = _head;

    for (int i = 0; current && i < index - 1; i++) {
      current = current->next;
    }

    if (!current) {
      std::cout << "Indeks poza zakresem.\n";
      return;
    }

    std::cout << "Wartosc " << value << " zostala dodana na indeks " << index
              << ".\n";

    newNode->next = current->next;
    current->next = newNode;
  }

  void removeFromFront() {
    if (!_head) {
      std::cout << "Lista jest pusta.\n";
      return;
    }

    Node *temp = _head;
    _head = _head->next;

    delete temp;

    std::cout << "Pierwszy element listy zostal usuniety.\n";
  }

  void removeFromEnd() {
    if (!_head) {
      std::cout << "Lista jest pusta.\n";

      return;
    }

    if (!_head->next) {
      delete _head;
      _head = nullptr;

      return;
    }

    Node *current = _head;

    while (current->next->next) {
      current = current->next;
    }

    delete current->next;
    current->next = nullptr;

    std::cout << "Ostatni element listy zostal usuniety.\n";
  }

  void removeFromIndex(int index) {
    if (index == 0) {
      removeFromFront();
      return;
    }

    Node *current = _head;

    for (int i = 0; current && i < index - 1; i++) {
      current = current->next;
    }

    if (!current || !current->next) {
      std::cout << "Indeks poza zakresem.\n";

      return;
    }

    std::cout << "Element listy w wezle " << index << " zostal usuniety.\n";

    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
  }

  int find(int value) {
    Node *current = _head;

    int index{0};

    while (current) {
      if (current->number == value) {
        return index;
      }

      current = current->next;
      index++;
    }

    return -1;
  }

  void print() {
    Node *current = _head;

    while (current) {
      std::cout << current->number << " -> ";
      current = current->next;
    }

    std::cout << "NULL\n";
  }
};
