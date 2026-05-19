#pragma once

#include <algorithm>
#include <array>

template<typename T>
class Set {
public:
  Set(): m_size(0), m_capacity(8), m_values(new T[m_capacity])
  {
  }

  ~Set()
  {
    delete[] m_values;
  }

  Set(const Set<T>& other):
      m_size(other.m_size), m_capacity(other.m_capacity),
      m_values(new T[m_capacity])
  {
    for (int i = 0; i < m_size; ++i) {
      m_values[i] = other.m_values[i];
    }
  }

  Set& operator=(const Set<T>& other)
  {
    return *this;
  }

  bool operator==(const Set<T>& other)
  {
    return false;
  }

  bool contains(const T& value) const
  {
    return false;
  }

  void add(const T& value)
  {
  }

  int getSize() const
  {
    return m_size;
  }

  void remove(const T& it)
  {
  }

  T removeSmallest()
  {
    return T{};
  }

  void clear()
  {
  }

  std::string toString()
  {
    return std::string();
  }

  Set<T> intersectionWith(const Set<T>& other)
  {
    return Set();
  }

private:
  T* m_values;
  int m_size;
  int m_capacity;
};