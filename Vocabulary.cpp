#include "Vocabulary.h"




struct Phrase
{
	String key_;
	int val_;
};



bool operator== (const Phrase& lhs, const Phrase& rhs)
{
	return lhs.key_ == rhs.key_;
}





Vocabulary:: Vocabulary():
prev_(0),
table_(100),
next_(257)
{
	for (char i = -128; i != 127; ++i)
	{
		Phrase ph;
		ph.key_ = String(i);
		ph.val_ = i + 129;
		table_.push_back(ph);
	}

	Phrase ph;
	ph.key_ = String(127);
	ph.val_ = 255;
	table_.push_back(ph);

}


int Vocabulary:: insert(char c)
{
	String copy = word_;
	word_ += c;

	int index;

	Phrase ph;
	ph.key_ = word_;
	ph.val_ = 0;

	if ((index = table_.find(ph)) < 0) // Phrase operator==()
	{
		Phrase ph;
		ph.key_ = word_;
		ph.val_ = next_++;
		
		table_.push_back(ph);


		int res = prev_;
		word_ = c; // because there are all symbols


		ph.key_ = c;
		prev_ = table_[table_.find(ph)].val_;

		return res;
	}


	prev_ = table_[index].val_;

	return -1;
}

int Vocabulary:: result()
{
	return prev_;
}


Vocabulary:: ~Vocabulary()
{
}