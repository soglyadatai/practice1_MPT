add_executable(doubly_linked_list_tests
	doubly_linked_list_test.cpp
	templates_doubly_linked_list.cpp
)

target_link_libraries(doubly_linked_list_tests
	${CONTAINERS_LIB}
)

add_test(doubly_linked_list_tests doubly_linked_list_tests)

add_executable(vector_tests
	vector_test.cpp
	templates_vector.cpp
)

target_link_libraries(vector_tests
	${CONTAINERS_LIB}
)

add_test(vector_tests vector_tests)