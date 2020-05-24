template <typename T, typename U>
struct Node
{
	T key_;
	U value_;
	Node<T, U>* left_, right_;
	Node(const T& k) {key = k; left = right = nullptr;}
};

template <typename T, typename U>
class Mymap
{
private:
	Node<T, U> hd_node_;
	int counter_;
public:
	Mymap();
	~Mymap();
	void insert(const T& key);
	bool find_or_insert(const T& key, U& res);	
};


Mymap:: Mymap():
counter_(0),
hd_node_(0)
{}


template <typename T, template U>
bool Mymap<T, U>:: find_or_insert(const T& key, U& res) // true - find
{
	bool fl = find_tree(hd_node_, key, res); // change res if find is succesful

	if (!fl) insert_tree(hd_node_, key, counter_);

	return fl;
}

