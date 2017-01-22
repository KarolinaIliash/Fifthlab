#pragma once
template <typename Key, typename Value> // hash node class template
class hash_node {
public:
	hash_node(const Key &key, const Value &value) :
		key(key), value(value), next(nullptr){ 
	}

	Key get_key() const;

	Value get_value() const;

	void set_value(Value value);

	hash_node *get_next() const;

	void set_next(hash_node *next);

private:
	Key key; // key-value pair
	Value value;
	hash_node *next;// next bucket with the same key
};

template <typename Key, typename Value>
Key hash_node<Key, Value>::get_key() const {
	return key;
}

template <typename Key, typename Value>
Value hash_node<Key, Value>::get_value() const {
	return value;
}

template <typename Key, typename Value>
void hash_node<Key, Value>::set_value(Value value) {
	hash_node::value = value;
}

template <typename Key, typename Value>
hash_node<Key, Value>* hash_node<Key, Value>::get_next() const {
	return next;
}

template <typename Key, typename Value>
void hash_node<Key, Value>::set_next(hash_node *next) {
	hash_node::next = next;
}
