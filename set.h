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
      m_values(new T[other.m_capacity])
  {
    std::copy(other.m_values, other.m_values + m_size, m_values);
  }

  Set& operator=(const Set<T>& other)
  {
    if (this != &other) {
      delete[] m_values;
      m_values = new T[other.m_capacity];
      std::copy(other.m_values, other.m_values + other.m_size, m_values);

      m_size = other.m_size;
      m_capacity = other.m_capacity;
    }

    return *this;
  }

  bool operator==(const Set<T>& other) const
  {
    if (m_size != other.m_size)
      return false;

    for (size_t i = 0; i < m_size; ++i) {
      if (!other.contains(m_values[i]))
        return false;
    }

    return true;
  }

  bool contains(const T& value) const
  {
    return std::find(m_values, m_values + m_size, value) != m_values + m_size;
  }

  void add(const T& value)
  {
    T* existing = std::find(m_values, m_values + m_size, value);
    if (existing == m_values + m_size) {
      if (m_size == m_capacity) {
        T* values = new T[m_capacity * 2];

        std::copy(m_values, m_values + m_size, values);

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
    return static_cast<int>(m_size);
  }

  void remove(const T& value)
  {
    T* existing = std::find(m_values, m_values + m_size, value);
    if (existing != m_values + m_size) {
      std::copy(existing + 1, m_values + m_size, existing);
      --m_size;
    }
  }

  T removeSmallest()
  {
    if (m_size == 0)
      throw std::out_of_range("Can not removeSmallest on an empty set");

    T min = *std::min_element(m_values, m_values + m_size);
    remove(min);

    return min;
  }

  void clear()
  {
    m_size = 0;
  }

  std::string toString() const
  {
    std::stringstream stream;

    stream << '{';
    for (size_t i = 0; i < m_size; ++i) {
      if (i > 0)
        stream << ',';
      stream << m_values[i];
    }
    stream << '}';

    return stream.str();
  }

  Set<T> intersectionWith(const Set<T>& other) const
  {
    Set<T> intersection = other;
    for (size_t i = 0; i < m_size; ++i) {
      intersection.add(m_values[i]);
    }
    return intersection;
  }

private:
  size_t m_size;
  size_t m_capacity;
  T* m_values;
};