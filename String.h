#pragma once
#define ST_CAP 10
#include <iostream>
#include <cstring>



class String
{
private:
	char* str_;
	int len_;
	int capacity_;
public:
	String(int size = ST_CAP);
	String(char);
	String(const String&);
	String(const char* other);
	~String();

	String operator+=(const String&);

	bool lexic_compare(const String&) const;
	int strlen();
	void swap(String&);

	String& operator=(const String&);
	void print();
};


bool operator==(const String& lhs, const String& rhs);

String operator+(const String& lhs, const String& rhs);
