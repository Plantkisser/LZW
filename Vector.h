#pragma once


template <typename T>

class Vector
{
private:
	int size_, capacity_;
	T* data_;
public:
	Vector(int cap = 100);
	~Vector();
	void push_back(const T&);
	const T& top() const;
	void pop_back();
	int find(const T&);

	Vector& operator=(const Vector<T>&);

	T& operator[](int);
	const T& operator[](int) const;
	void swap(Vector& rhs);
	int size() const;
	void reserve(int);
	void init(const T&);
};


#include "Vector.hpp"