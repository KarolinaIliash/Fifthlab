#pragma once
#include "hash_node.h"
#include "hash_key.h"

template <typename Key, typename Value, typename Func = hash_key<Key> >
class hash_map
{
public:
	hash_map() {
		// construct zero initialized hash table of size
		table = new hash_node<Key, Value> *[TABLE_SIZE]();
	}
	~hash_map();
	bool get(const Key &key, Value &value);
	void put(const Key &key, const Value &value);

	bool remove(const Key &key);
private:
	hash_node<Key, Value> **table;// hash table
	Func hash_func;
};

template <typename Key, typename Value, typename Func = hash_key<Key> >
hash_map<Key, Value, Func>::~hash_map() {
	for (int i = 0; i < TABLE_SIZE; ++i) {// delete all buckets one by one
		hash_node<Key, Value> *entry = table[i];
		while (entry != NULL) {
			hash_node<Key, Value> *prev = entry;
			entry = entry->get_next();
			delete prev;
		}
		table[i] = NULL;
	}
	delete[] table;// delete the hash table
}

template <typename Key, typename Value, typename Func = hash_key<Key> >
bool hash_map<Key, Value, Func>::get(const Key &key, Value &value) {
	unsigned long hash_value = hash_func(key);
	hash_node<Key, Value> *entry = table[hash_value];

	while (entry != nullptr) {
		if (entry->get_key() == key) {
			value = entry->get_value();
			return true;
		}
		entry = entry->get_next();
	}
	return false;
}

template <typename Key, typename Value, typename Func = hash_key<Key>>
void hash_map<Key, Value, Func>::put(const Key &key, const Value &value) {
	unsigned long hash_value = hash_func(key);
	hash_node<Key, Value> *prev = nullptr;
	hash_node<Key, Value> *entry = table[hash_value];

	while (entry != nullptr && entry->get_key() != key) {
		prev = entry;
		entry = entry->get_next();
	}

	if (entry == nullptr) {
		entry = new hash_node<Key, Value>(key, value);
		if (prev == nullptr) {
			table[hash_value] = entry;// insert as a first bucket
		}
		else {
			prev->set_next(entry);
		}
	}
	else {
		entry->set_value(value);// only update the value
	}
}

template <typename Key, typename Value, typename Func = hash_key<Key>>
bool hash_map<Key, Value, Func>::remove(const Key &key) {
	unsigned long hash_value = hash_func(key);
	hash_node<Key, Value> *prev = nullptr;
	hash_node<Key, Value> *entry = table[hash_value];
	while (entry != nullptr && entry->get_key() != key) {
		prev = entry;
		entry = entry->get_next();
	}

	if (entry == nullptr) {// key wasn't found
		return false;
	}
	else {
		if (prev == nullptr) {
			table[hash_value] = entry->get_next();// remove the first bucket of the list
		}
		else {
			prev->set_next(entry->get_next());
		}
		delete entry;
	}
	return true;
}


