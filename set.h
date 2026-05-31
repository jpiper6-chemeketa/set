#pragma once

#include <algorithm>
#include <array>

template<typename T>
class Set {
public:
  Set(): m_size(0), m_capacity(8), m_values(new T[8])
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
    std::copy(other.m_values, other.m_values + m_size, m_values);
  }

  Set& operator=(const Set<T>& other)
  {
    if (this != &other) {
      delete[] m_values;
      m_values = new T[other.m_size];
      m_size = other.m_size;
      std::copy(other.m_values, other.m_values + m_size, m_values);
    }
    return *this;
  }

  bool operator==(const Set<T>& other) const
  {
    return false;
  }

  bool contains(const T& value) const
  {
    return std::find(m_values, m_values + m_capacity, value)
           != m_values + m_capacity;
  }

  void add(const T& value)
  {
    T* existing = std::find(m_values, m_values + m_size, value);
    if (existing == m_values + m_size) {
      if (m_size == m_capacity) {
        T* values = new T[m_capacity * 2];

        std::copy(m_values, m_values + m_capacity, values);

        delete[] m_values;
        m_values = values;
        m_capacity = m_capacity * 2;
      }

      m_values[m_size] = value;
      ++m_size;
    }
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
    m_size = 0;
  }

  std::string toString() const
  {
    return std::string();
  }

  Set<T> intersectionWith(const Set<T>& other) const
  {
    return Set();
  }

private:
  T* m_values;
  size_t m_size;
  size_t m_capacity;
};