#include <cassert>
#include "../src/vector.hpp"

using rva::Vector;

void test_empty_vector() {
	Vector<int> v;

	assert(v.get_size() == 0);
	assert(v.has_item(5) == false);
}

void test_push_back() {
	Vector<int> v;

	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	assert(v.get_size() == 3);
	assert(v.has_item(5) == true);
	assert(v.has_item(6) == true);
	assert(v.has_item(7) == true);
}

void test_insert() {
	Vector<int> v;

	v.push_back(5);
	v.push_back(7);

	assert(v.insert(1, 6) == true);
	assert(v.get_size() == 3);
	assert(v.has_item(6) == true);
}

void test_insert_bad_position() {
	Vector<int> v;

	v.push_back(5);

	assert(v.insert(10, 7) == false);
	assert(v.get_size() == 1);
	assert(v.has_item(7) == false);
}

void test_remove_first() {
	Vector<int> v;

	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	assert(v.remove_first(6) == true);
	assert(v.get_size() == 2);
	assert(v.has_item(6) == false);
}

void test_remove_bad_item() {
	Vector<int> v;

	v.push_back(5);

	assert(v.remove_first(100) == false);
	assert(v.get_size() == 1);
}

int main() {
	test_empty_vector();
	test_push_back();
	test_insert();
	test_insert_bad_position();
	test_remove_first();
	test_remove_bad_item();

	return 0;
}