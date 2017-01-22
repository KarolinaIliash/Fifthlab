#pragma once
#include <string>
#include <functional>

static const int TABLE_SIZE = 128;

typedef unsigned char byte;

// Default hash function class
template <typename Key>
struct hash_key {
	unsigned long operator()(const Key& key) const;
};

template <typename Key>
unsigned long hash_key<Key>::operator()(const Key& key) const
{
	std::hash<Key> h;
	size_t res = h(key);
	return res % TABLE_SIZE;
}