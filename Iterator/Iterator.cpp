#include <iostream>
#include <vector>
#include <algorithm>

/*
	   Задание: Для FixedArray реализуйте итератор
	   Методы итератора:
	   + ++
	   + --
	   + !=
	   + *
	   + +
	   В FixedArray добавьте begin() и end():
	   Распечатайте содержимое FixedArray используя итераторы
   */


template<typename T, size_t size>
class FixedArray
{
public:
	FixedArray()
	{
		m_data = new T[size];
	}

	class Iterator
	{
	public:
		Iterator(T* ptr)
		{
			m_ptr = ptr;
		}
		Iterator operator+(const int index)
		{

			return Iterator(m_ptr + index);
		}

		bool operator!=(const Iterator& other)
		{
			return m_ptr != other.m_ptr;
		}

		bool operator==(const Iterator& other)
		{
			return m_ptr == other.m_ptr;
		}

		Iterator operator++(int)
		{
			++m_ptr;
			return *this;
		}

		Iterator operator++()
		{
			Iterator i = *this;
			m_ptr++;
			return i;
		}

		Iterator operator--(int)
		{
			--m_ptr;
			return *this;
		}

		Iterator operator--()
		{
			Iterator i = *this;
			m_ptr--;
			return i;
		}

		T& operator*()
		{
			return *m_ptr;
		}

		T* operator->()
		{
			return m_ptr;
		}
	private:
		T* m_ptr;
	};

	Iterator begin()
	{
		return Iterator(m_data);
	}

	Iterator end()
	{
		return Iterator(m_data + m_index);
	}

	void push_back(const T& element)
	{
		if (m_index < size)
		{
			m_data[m_index++] = element;
		}
		else
		{
			throw std::exception("Limit of size");
		}
	}

	T& operator[](const int element)
	{
		for (int i = 0; i < size; ++i)
		{
			if (m_data[i] == element)
			{
				return m_data[element];
			}
		}

		throw std::exception("Out of range");

	}

	~FixedArray()
	{
		delete[] m_data;
	}

private:

	friend std::ostream& operator<<(std::ostream& os, FixedArray& n)
	{
		if (n.m_index)
		{
			for (int i = 0; i < n.m_index; ++i)
				os << n[i] << ' ';
		}
		else
		{
			std::cout << "Not data";
		}
		return os;
	}
	size_t m_index = 0;
	T* m_data = nullptr;
};

int main()
{

	FixedArray<int, 5> arr;
	arr.push_back(33);
	arr.push_back(22);
	arr.push_back(100);

	FixedArray<int, 5>::Iterator begin__(arr.begin());
	FixedArray<int, 5>::Iterator end__(arr.end());

	std::cout << " operator + = " << *(begin__ + 2) << '\n';

	for (; begin__ != end__; begin__++)
	{
		std::cout << *begin__ << " ";
	}

}