CC = gcc 
FLAGS = -Wall -Werror -Wextra -std=c++17
DOP = -lgtest -lpthread -lstdc++

TEST = all_tests

SRC_MAP = tests/map_tests.cc
SRC_SET = tests/set_tests.cc
SRC_ARRAY = tests/array_tests.cc
SRC_MULTISET = tests/multiset_tests.cc
SRC_VECTOR = tests/vector_tests.cc
SRC_LIST = tests/list_tests.cc
SRC_QUEUE = tests/deque_tests.cc
SRC_STACK = tests/stack_tests.cc

HEADER = s21_containers.h
HEADER_PLUS = s21_containersplus.h

SRC_CONTAINERS = $(SRC_LIST) $(SRC_MAP) $(SRC_QUEUE) \
				$(SRC_SET) $(SRC_STACK) $(SRC_VECTOR)

SRC_CONTAINERSPLUS = $(SRC_ARRAY) $(SRC_MULTISET)

set_test:
	$(CC) $(FLAGS) $(SRC_SET) -o test_set $(DOP)
	./test_set --gtest_brief=1

vector_test:
	$(CC) $(FLAGS) $(SRC_VECTOR) -o test_vector $(DOP) 
	./test_vector --gtest_brief=1

list_test:
	$(CC) $(FLAGS) $(SRC_LIST) -o test_list $(DOP) 
	./test_list --gtest_brief=1

queue_test:
	$(CC) $(FLAGS) $(SRC_QUEUE) -o test_queue $(DOP) 
	./test_queue --gtest_brief=1

stack_test:
	$(CC) $(FLAGS) $(SRC_STACK) -o test_stack $(DOP)
	./test_stack --gtest_brief=1

array_test:
	$(CC) $(FLAGS) $(SRC_ARRAY) -o test_array $(DOP)
	./test_array --gtest_brief=1

multiset_test:
	$(CC) $(FLAGS) $(SRC_MULTISET) -o test_multiset $(DOP)
	./test_multiset --gtest_brief=1

map_test:
	$(CC) $(FLAGS) $(SRC_MAP) -o test_map $(DOP) 
	./test_map --gtest_brief=1

test: list_test 

style:
	clang-format -n *.h

leaks:
	leaks -atExit -- ./test_array
	leaks -atExit -- ./test_list
	leaks -atExit -- ./test_map
	leaks -atExit -- ./test_multiset
	leaks -atExit -- ./test_queue
	leaks -atExit -- ./test_set
	leaks -atExit -- ./test_stack
	leaks -atExit -- ./test_vector
	
clean:
	rm -rf test_map test_set test_array test_multiset test_vector \
	test_list test_stack test_queue
	rm -rf *.gcda *.gcno *.info