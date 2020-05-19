struct Phrase
{
	String key_;
	int val_;
	Phrase(String key = "", int val = 0):key_(key), val_(val) {}
	Phrase operator=(const Phrase&);
};