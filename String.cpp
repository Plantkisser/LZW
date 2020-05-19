#include "String.h"





bool operator==(const String& lhs, const String& rhs)
{
	return  lhs.lexic_compare(rhs);
}

String operator+(const String& lhs, const String& rhs)
{
	String tmp = lhs;
	tmp += rhs;
	return tmp;
}



String:: String(int size):
str_(new char[size]),
len_(0),
capacity_(size)
{
	for (int i = 0; i < capacity_; ++i)
		str_[i] = '\0';
}

String:: String(const char* other)
{
	if (!other)
	{
		str_ = new char[ST_CAP];
		len_ = 0;
		capacity_ = ST_CAP;

		for (int i = 0; i < capacity_; ++i)
		str_[i] = '\0';
	}
	else
	{
		len_ = std:: strlen(other);
		capacity_ = len_ + 1;

		str_ = new char[capacity_];

		for (int i = 0; i <  len_; ++i)
			str_[i] = other[i];
		for (int i = len_; i < capacity_; ++i)
			str_[i] = '\0';
	}
}



String:: String(char c):
str_(new char[2]),
len_(1),
capacity_(2)
{
	str_[0] = c;
	for (int i = 1; i < capacity_; ++i)
		str_[i] = '\0';
}

String:: String(const String& rhs):
capacity_(ST_CAP > rhs.capacity_? ST_CAP : rhs.capacity_),
str_(new char[capacity_]),
len_(rhs.len_)
{
	for (int i = 0; i < rhs.len_; ++i)
		str_[i] = rhs.str_[i];
	for (int i = len_; i < capacity_; ++i)
		str_[i] = '\0';
}


String String:: operator+=(const String& rhs)
{
	int cap = 0;
	for(cap = capacity_; cap < rhs.len_ + len_; cap *= 2);

	String tmp(cap + 1);
	
	int i = 0;
	for (i = 0; i < len_; ++i)
	{
		tmp.str_[i] = str_[i];
	}

	for (i = 0; i < rhs.len_; ++i)
	{
		tmp.str_[i + len_] = rhs.str_[i];
	}
	tmp.len_ = len_  + rhs.len_; 

	//std:: cout << tmp.str_ << len_ + rhs.len_ <<  std:: endl;

	swap(tmp);

	//std:: cout << str_ << len_ + rhs.len_ <<  std:: endl;

	return *this;

}


bool String:: lexic_compare(const String& other) const
{
	if (other.len_ != len_)
		return false;

	for (int i = 0; i < len_; ++i)
	{
		if (other.str_[i] != str_[i])
			return false;
	}

	return true;
}

int String:: strlen()
{
	return len_;
}

void String:: swap(String& other)
{
	char* tmp = str_;
	str_ = other.str_;
	other.str_ = tmp;
	std:: swap(other.len_, len_);
	std:: swap(other.capacity_, capacity_);

	//std:: cout << str_ << " " << other.str_ << std:: endl;
}


String:: ~String()
{
	//std:: cout << (int)str_[0] << std:: endl;

	delete[] str_;
	str_ = nullptr;
}




String& String:: operator=(const String& other)
{
	String tmp (other);

	swap(tmp);

	return *this;
}


void String:: print()
{
	std:: cout <<"PRINT " << str_ << std:: endl;
}






