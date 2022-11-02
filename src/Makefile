CC = gcc
FLAGS = -lgtest -lpthread -lstdc++

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
	$(CC) $(SRC_SET) -o test_set $(FLAGS)
	./test_set --gtest_brief=1

vector_test:
	$(CC) $(SRC_VECTOR) -o test_vector $(FLAGS) 
	./test_vector --gtest_brief=1

list_test:
	$(CC) $(SRC_LIST) -o test_list $(FLAGS) 
	./test_list --gtest_brief=1

queue_test:
	$(CC) $(SRC_QUEUE) -o test_queue $(FLAGS) 
	./test_queue --gtest_brief=1

stack_test:
	$(CC) $(SRC_STACK) -o test_stack $(FLAGS)
	./test_stack --gtest_brief=1

array_test:
	$(CC) $(SRC_ARRAY) -o test_array $(FLAGS)
	./test_array --gtest_brief=1

multiset_test:
	$(CC) $(SRC_MULTISET) -o test_multiset $(FLAGS)
	./test_multiset --gtest_brief=1

map_test:
	$(CC) $(SRC_MAP) -o test_map $(FLAGS)
	./test_map --gtest_brief=1

test: queue_test

style:
	clang-format -n *.h
	clang-format -n tests/*.cc

clean:
	rm -rf test_map test_set test_array test_multiset test_vector \
	test_list test_stack test_queue
	rm -rf *.gcda *.gcno *.info