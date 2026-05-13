#include <cassert>
#include "../src/doubly_linked_list.hpp"

using rva::DoublyLinkedList;

void test_empty_list() {
	DoublyLinkedList<int> list;

	assert(list.get_size() == 0);
	assert(list.has_item(5) == false);
}

void test_push_back() {
	DoublyLinkedList<int> list;

	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	assert(list.get_size() == 3);
	assert(list.has_item(5) == true);
	assert(list.has_item(6) == true);
	assert(list.has_item(7) == true);
}

void test_remove_only_item() {
	DoublyLinkedList<int> list;

	list.push_back(5);

	assert(list.remove_first(5) == true);
	assert(list.get_size() == 0);
	assert(list.has_item(5) == false);
}

void test_remove_first_item() {
	DoublyLinkedList<int> list;

	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	assert(list.remove_first(5) == true);
	assert(list.get_size() == 2);
	assert(list.has_item(5) == false);
	assert(list.has_item(6) == true);
	assert(list.has_item(7) == true);
}

void test_remove_middle_item() {
	DoublyLinkedList<int> list;

	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	assert(list.remove_first(6) == true);
	assert(list.get_size() == 2);
	assert(list.has_item(6) == false);
}

void test_remove_last_item() {
	DoublyLinkedList<int> list;

	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	assert(list.remove_first(7) == true);
	assert(list.get_size() == 2);
	assert(list.has_item(7) == false);
}

void test_remove_bad_item() {
	DoublyLinkedList<int> list;

	list.push_back(5);

	assert(list.remove_first(100) == false);
	assert(list.get_size() == 1);
}

int main() {
	test_empty_list();
	test_push_back();
	test_remove_only_item();
	test_remove_first_item();
	test_remove_middle_item();
	test_remove_last_item();
	test_remove_bad_item();

	return 0;
}