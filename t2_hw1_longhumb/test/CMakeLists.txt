add_executable(test_long_number
    main.cpp
)

target_link_libraries(test_long_number PRIVATE
    ${LIBRARY}
)