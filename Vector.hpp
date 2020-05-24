
#include <iostream>








	


template <typename T>
Vector<T>:: Vector(int cap):
capacity_(cap),
size_(0),
data_(new T[cap])
{}


template <typename T>
int Vector<T>:: size() const
{
	return size_;
}




template <typename T>
void Vector<T>:: push_back(const T& val)
{
	if (size_ == capacity_)
	{
		Vector copy(capacity_ * 2);
		copy = *this;

		swap(copy);
		capacity_ *= 2;
	}

	data_[size_++] = val;
}

template <typename T>
const T& Vector<T>:: top() const
{
	return data_[size_ - 1];
}

template <typename T>
void Vector<T>:: pop_back()
{
	size_--;
}

template <typename T>
int Vector<T>:: find(const T& val)
{
	for(int i = 0; i < size_; ++i)
	{
		if (val == data_[i])
			return i;
	}

	return -1;
}

template <typename T>
T& Vector<T>:: operator[](int ind)
{
	return data_[ind];
}

template <typename T>
const T& Vector<T>:: operator[](int ind) const
{
	return data_[ind];
}


template <typename T>
Vector<T>& Vector<T>:: operator=(const Vector& other)
{
	if (capacity_ < other.size_)
	{
		Vector tmp(other.capacity_);
		tmp = other;
		swap(tmp);
	}
	else
	{
		for (int i = 0; i < other.size_; ++i)
			data_[i] = other.data_[i];

		size_ = other.size_;
		capacity_ = other.capacity_;
	}

	return *this;
}

template <typename T>
Vector<T>:: ~Vector()
{
	delete[] data_;
}


template <typename T>
void Vector<T>:: swap(Vector& rhs)
{
	T* tmp_ptr = rhs.data_;
	rhs.data_ = data_;
	data_ = tmp_ptr;

	std:: swap(size_, rhs.size_);
	std:: swap(capacity_, rhs.capacity_);
}

template <typename T>
void Vector<T>:: reserve(int n)
{
	Vector<T> tmp(n);
	tmp.size_ = n;

	swap(tmp);
}

template <typename T>
void Vector<T>:: init(const T& val)
{
	for (int i = 0; i < size_; ++i)
		data_[i] = val;
}






















