#include <iostream>
#pragma once

class Array {
public:
  Array(const int s = 10) : _elements_in_array(0), _size(s) {
    _arr = new int[_size];
  }

  ~Array() { delete[] _arr; }

  // O(n)
  void addToFront(int value) {
    if (_size == _elements_in_array) {
      expand();
    }

    for (int i = _elements_in_array; i > 0; i--) {
      _arr[i] = _arr[i - 1];
    }

    _arr[0] = value;
    _elements_in_array++;

    // std::cout << "Wartosc " << value
    // << " zostala dodana na poczatek tablicy.\n";
  }

  // O(1)
  void addToEnd(int value) {
    if (_size == _elements_in_array) {
      expand();
    }

    _arr[_elements_in_array] = value;
    _elements_in_array++;

    // std::cout << "Wartosc " << value << " zostala dodana na koniec
    // tablicy.\n";
  }

  // O(n)
  void addAtIndex(int value, int index) {
    if (index < 0 || index > _elements_in_array) {
      return;
    }

    if (_size == _elements_in_array) {
      expand();
    }

    for (int i = _elements_in_array; i > index; i--) {
      _arr[i] = _arr[i - 1];
    }

    _arr[index] = value;
    _elements_in_array++;

    std::cout << "Wartosc " << value << " zostala dodana na indeks " << index
              << ".\n";
  }

  // O(n)
  void removeFromFront() {
    if (_elements_in_array == 0) {
      std::cout << "Tablica jest pusta.\n";

      return;
    }

    for (int i = 0; i < _elements_in_array; i++) {
      _arr[i] = _arr[i + 1];
    }

    _elements_in_array--;

    std::cout << "Pierwszy element tablicy zostal usuniety.\n";
  }

  // O(1)
  void removeFromEnd() {
    if (_elements_in_array == 0) {
      std::cout << "Tablica jest pusta.\n";

      return;
    }

    _elements_in_array--;

    std::cout << "Ostatni element tablicy zostal usuniety.\n";
  }

  // O(n)
  void removeFromIndex(int index) {
    if (index >= _elements_in_array) {
      std::cout << "Indeks poza zakresem.\n";

      return;
    }

    for (int i = index; i < _elements_in_array; i++) {
      _arr[i] = _arr[i + 1];
    }

    _elements_in_array--;

    std::cout << "Element tablicy o indeksie " << index
              << " zostal usuniety.\n";
  }

  // O(n)
  int find(int value) {
    for (int i = 0; i < _elements_in_array; i++) {
      if (_arr[i] == value) {
        return i;
      }
    }

    return -1;
  }

  // Do debugowania
  void print() {
    std::cout << "[  ";

    for (int i = 0; i < _elements_in_array; i++) {
      std::cout << _arr[i] << "\t";
    }

    std::cout << "  ]";
  }

private:
  int _elements_in_array = 0;
  int *_arr;
  int _size;

  // O(n) -> w przypadku, gdy dodamy element do tablicy, lecz jest ona za mala,
  // to zlozonosc obliczeniowa dodawania do tablicy moze wzrosnac nawet do
  // O(n^2)
  void expand() {
    _size *= 2;
    int *newArray = new int[_size];

    for (int i = 0; i < _elements_in_array; i++) {
      newArray[i] = _arr[i];
    }

    delete[] _arr;
    _arr = newArray;
  }
};
