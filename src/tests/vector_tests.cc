#include <gtest/gtest.h>

#include <vector>

#include "../Vector/s21_vector.h"

TEST(vector_test, at1) {
  s21::Vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < vec1.size(); i++) {
    EXPECT_EQ(vec1.at(i), vec2.at(i));
  }
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, at_exeptions) {
  s21::Vector<int> vec1 = {1, 2, 3};
  try {
    vec1.at(3);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const &err) {
    EXPECT_EQ(err.what(), std::string("out_of_range"));
  }
  try {
    vec1.at(-2);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const &err) {
    EXPECT_EQ(err.what(), std::string("out_of_range"));
  }
}

TEST(vector_test, operator_brackets) {
  s21::Vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < vec1.size(); i++) {
    EXPECT_EQ(vec1[i], vec2[i]);
  }
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, front) {
  s21::Vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.front(), vec2.front());
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, back) {
  s21::Vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.back(), vec2.back());
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, data) {
  s21::Vector<int> vec1;
  EXPECT_EQ(vec1.data(), nullptr);
  s21::Vector<int> vec2 = {1, 2, 3};
  EXPECT_FALSE(vec2.data() == nullptr);
}

TEST(vector_test, begin) {
  s21::Vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  auto iter1 = vec1.begin();
  auto iter2 = vec2.begin();
  EXPECT_EQ(*iter1, *iter2);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, end) {
  s21::Vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  auto iter1 = vec1.end();
  auto iter2 = vec2.end();
  EXPECT_EQ(*(iter1 - 1), *(iter2 - 1));
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, empty) {
  s21::Vector<int> vec1;
  EXPECT_EQ(vec1.empty(), true);
  vec1 = {1, 2, 3};
  EXPECT_EQ(vec1.empty(), false);
}

TEST(vector_test, size) {
  s21::Vector<int> vec1;
  std::vector<int> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), 0);
  vec1 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, reserve) {
  s21::Vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};
  vec1.reserve(100);
  vec2.reserve(100);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
  vec1.reserve(0);
  vec2.reserve(0);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());

  try {
    vec1.reserve(-1);
    FAIL() << "vector::reserve";
  } catch (std::length_error const &err) {
    EXPECT_EQ(err.what(), std::string("vector::reserve"));
  }
}

TEST(vector_test, capacity) {
  s21::Vector<int> vec1;
  std::vector<int> vec2;
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
  vec1 = {1, 2, 3};
  vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, shrink_to_fit) {
  s21::Vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.push_back(11);
  vec2.push_back(11);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());

  vec1.shrink_to_fit();
  vec2.shrink_to_fit();

  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, clear) {
  s21::Vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.clear();
  vec2.clear();

  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, insert) {
  s21::Vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto iter1 = vec1.end();
  auto iter2 = vec2.end();
  vec1.insert(iter1, 11);
  vec2.insert(iter2, 11);
  EXPECT_EQ(vec1[10], vec2[10]);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());

  iter1 = vec1.begin();
  iter2 = vec2.begin();
  vec1.insert(iter1 + 5, 11);
  vec2.insert(iter2 + 5, 11);
  EXPECT_EQ(vec1[5], vec2[5]);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, erase) {
  s21::Vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto iter1 = vec1.end();
  auto iter2 = vec2.end();
  vec1.erase(iter1 - 1);
  vec2.erase(iter2 - 1);
  EXPECT_EQ(vec1[8], vec2[8]);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());

  iter1 = vec1.begin();
  iter2 = vec2.begin();
  vec1.erase(iter1);
  vec2.erase(iter2);
  EXPECT_EQ(vec1[0], vec2[0]);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());

  try {
    vec1.erase(iter1 + 500);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const &err) {
    EXPECT_EQ(err.what(), std::string("Out of range"));
  }
}

TEST(vector_test, push_back) {
  s21::Vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.push_back(11);
  vec2.push_back(11);
  EXPECT_EQ(vec1[10], vec2[10]);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, pop_back) {
  s21::Vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.pop_back();
  vec2.pop_back();

  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
  s21::Vector<int> vec3;
  std::vector<int> vec4;
  // vec3.pop_back();
  // vec4.pop_back();
  // EXPECT_EQ(vec3.size(), vec4.size());
  // EXPECT_EQ(vec3.capacity(), vec4.capacity());
}

TEST(vector_test, swap) {
  s21::Vector<int> vec1 = {1, 2, 3};
  s21::Vector<int> vec1_1 = {3, 2, 1};
  vec1.swap(vec1_1);
  for (int i = 0, j = 3; i < 3; i++) {
    EXPECT_EQ(vec1_1[i], i + 1);
    EXPECT_EQ(vec1[i], j--);
  }
}

TEST(vector_test, resize) {
  s21::Vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {3, 2, 1};
  vec1.push_back(5);
  vec2.push_back(5);

  vec1.resize(10);
  vec2.resize(10);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());

  s21::Vector<int> vec3 = {1, 2, 3};
  std::vector<int> vec4 = {3, 2, 1};
  vec1.resize(2);
  vec2.resize(2);
  EXPECT_EQ(vec3.size(), vec4.size());
  EXPECT_EQ(vec3.capacity(), vec4.capacity());
}

TEST(vector_test, operator_eq) {
  s21::Vector<int> vec1 = {1, 2, 3, 5, 6, 3, 4};
  s21::Vector<int> vec2;
  vec2 = vec1;
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
  auto it_2 = vec2.begin();
  for (auto it = vec1.begin(); it != vec1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(vector_test, emplace) {
    struct structure {
        int x_;
        long double y_;
        char z_;
        bool operator==(const structure &other) const {
            return (x_ == other.x_ && y_ == other.y_ && z_ == other.z_);
        }
        structure() {
            x_ = 0;
            y_ = 0;
            z_ = 0;
        }
        structure(int x, long double y, char z) : x_(x), y_(y), z_(z) {}
    };
    const structure elem1 = {6, 7., '8'};
    const structure elem2 = {7, 8., '9'};
    const structure expecting_result = {1, 2., '3'};
    std::initializer_list<structure> a = {elem1, elem2};
    s21::Vector<structure> vec1(a);
    auto it = vec1.begin();
    vec1.emplace(it, 1, 2., '3');
    auto it_res = vec1.begin();
    EXPECT_TRUE(*it_res == expecting_result);
    ++it_res;
    EXPECT_TRUE(*it_res == elem1);
    ++it_res;
    EXPECT_TRUE(*it_res == elem2);
}

TEST(vector_test, emplace_back) {
    struct structure {
        int x_;
        long double y_;
        char z_;
        bool operator==(const structure &other) const {
            return (x_ == other.x_ && y_ == other.y_ && z_ == other.z_);
        }
        structure() {
            x_ = 0;
            y_ = 0;
            z_ = 0;
        }
        structure(int x, long double y, char z) : x_(x), y_(y), z_(z) {}
    };
    const structure elem1 = {6, 7., '8'};
    const structure elem2 = {7, 8., '9'};
    const structure expecting_result = {1, 2., '3'};
    std::initializer_list<structure> a = {elem1, elem2};
    s21::Vector<structure> vec1(a);
    vec1.emplace_back(1, 2., '3');
    auto it_res = vec1.begin();
    EXPECT_TRUE(*it_res == elem1);
    ++it_res;
    EXPECT_TRUE(*it_res == elem2);
    ++it_res;
    EXPECT_TRUE(*it_res == expecting_result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}