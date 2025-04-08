#include "Array.h"
#include "Linkedlist.h"
#include <iostream>

int main() {
  std::cout << "Lista Wiazana";

  Array arr;

  arr.addToFront(5); // [ 5 ]
  arr.addToFront(4); // [ 4, 5 ]

  arr.addAtIndex(45, 1); // [ 4, 45, 5 ]
  arr.addToEnd(6);       // [ 4, 45, 5, 6 ]

  arr.removeFromFront();  // [ 45, 5, 6 ]
  arr.removeFromIndex(6); // Poza zakresem
  arr.removeFromIndex(2); // [ 45, 5 ]
  arr.removeFromEnd();    // [ 45 ]

  arr.find(3);  // Nie ma w tablicy
  arr.find(45); // Na indeksie 0

  arr.print(); // 45 -> NULL

  std::cout << "\n\nLista Wiazana\n\n";

  Linkedlist list;

  list.addToFront(5); // 5 -> NULL
  list.addToFront(4); // 4 -> 5 -> NULL

  list.addAtIndex(45, 1); // 4 -> 45 -> 5 -> NULL
  list.addToEnd(6);       // 4 -> 45 -> 5 -> 6 -> NULL

  list.removeFromFront();  // 45 -> 5 -> 6 -> NULL
  list.removeFromIndex(6); // Poza zakresem
  list.removeFromIndex(2); // 45 -> 5 -> NULL
  list.removeFromEnd();    // 45 -> NULL

  list.find(3);  // Nie ma w liscie
  list.find(45); // W wezle 0

  list.print(); // 45 -> NULL
}
