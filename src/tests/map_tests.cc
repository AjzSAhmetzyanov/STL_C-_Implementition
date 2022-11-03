#include <gtest/gtest.h>

#include <map>

#include "../Map/s21_map.h"
 
TEST(map_test, constr1) {
    s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    auto it1 = m1.begin();
    for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
    it1 = m1.begin();
    for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
        EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constr2) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.size(), m2.size());
  m1.insert({1, 1});
  m2.insert({1, 1});
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constr3) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  auto m11 = m1;
  auto m22 = m2;
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it2++, it1++)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constr4) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  auto m11 = std::move(m1);
  auto m22 = std::move(m2);
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it2++, it1++)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, at1) {
 s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
 std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
 for (size_t i = 1; i < m1.size(); i++)
     EXPECT_EQ(m1.at(i), m2.at(i));
}

TEST(map_test, at3) {
 s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
 std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
 EXPECT_EQ(m1.at(100), m2.at(100));
}

TEST(map_test, begin1) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, empty1) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, empty2) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, size1) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;
  std::pair<int, int> pair = {1, 1};
  m1.insert(pair);
  m2.insert(pair);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size2) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size3) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, clear1) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear2) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear3) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, insert1) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert2) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

 TEST(map_test, insert5) {
     s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
     std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
     EXPECT_EQ(m1.empty(), m2.empty());
     EXPECT_EQ(m1.insert_or_assign(3, 1).second, m2.insert_or_assign(3,
     1).second); EXPECT_EQ(m1.at(3), m2.at(3)); EXPECT_EQ(m1.empty(),
     m2.empty()); EXPECT_EQ(m1.size(), m2.size());
 }

 TEST(map_test, insert6) {
     s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
     std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
     EXPECT_EQ(m1.empty(), m2.empty());
     EXPECT_EQ(m1.insert_or_assign(2, 1).second, m2.insert_or_assign(2,
     1).second); EXPECT_EQ(m1.at(2), m2.at(2)); EXPECT_EQ(m1.empty(),
     m2.empty()); EXPECT_EQ(m1.size(), m2.size());
 }

TEST(map_test, erase1) {  // exception leak
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.size(), m2.size());
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, erase2) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap1) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  s21::Map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap2) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  s21::Map<int, int> m11 = {
      {389, 12}, {3829, 12}, {111, 12}, {189, 12}, {11, 12}};
  std::map<int, int> m22 = {
      {389, 12}, {3829, 12}, {111, 12}, {189, 12}, {11, 12}};
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap3) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;
  s21::Map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

 TEST(map_test, contains1) {
   s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
   EXPECT_EQ(m1.contains(1), true);
 }

 TEST(map_test, contains2) {
   s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
   EXPECT_EQ(m1.contains(5), true);
 }
TEST(map_test, merge1) {
s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
s21::Map<int, int> m11 = {{389, 12}, {3829, 12}, {111, 12}, {189, 12}, {11, 12}};
std::map<int, int> m22 = {{389, 12}, {3829, 12}, {111, 12}, {189, 12}, {11, 12}};
m1.merge(m11);
m2.merge(m22);
EXPECT_EQ(m1.size(), m2.size());
EXPECT_EQ(m11.size(), m22.size());
auto it1 = m1.begin();
for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++) EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, merge2) {
s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
s21::Map<int, int> m11 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
std::map<int, int> m22 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
m1.merge(m11);
m2.merge(m22);
EXPECT_EQ(m1.size(), m2.size());
EXPECT_EQ(m11.size(), m22.size());
auto it1 = m1.begin();
for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++) EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, merge3) {
s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
s21::Map<int, int> m11 = {{389, 12}, {3829, 12}, {111, 12}, {189, 12}, {11, 12},
                          {1, 1},    {2, 2},     {100, 3},  {4, 4},    {5, 5}};
std::map<int, int> m22 = {{389, 12}, {3829, 12}, {111, 12}, {189, 12}, {11, 12},
                          {1, 1},    {2, 2},     {100, 3},  {4, 4},    {5, 5}};
m1.merge(m11);
m2.merge(m22);
EXPECT_EQ(m1.size(), m2.size());
EXPECT_EQ(m11.size(), m22.size());
auto it1 = m1.begin();
for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++) EXPECT_EQ((*it1).second, (*it2).second);
}

// TEST(map_test, emplace) {
//   struct structure {
//     int x_;
//     long double y_;
//     char z_;
//     bool operator==(const structure &other) const {
//       return (x_ == other.x_ && y_ == other.y_ && z_ == other.z_);
//     }
//     bool operator>(const structure &other) const { return x_ > other.x_; }
//     bool operator<(const structure &other) const { return x_ < other.x_; }
//     bool operator>=(const structure &other) const { return x_ >= other.x_; }
//     bool operator<=(const structure &other) const { return x_ <= other.x_; }
//     structure() {
//       x_ = 0;
//       y_ = 0;
//       z_ = 0;
//     }
//     structure(int x, long double y, char z) : x_(x), y_(y), z_(z) {}
//   };
//   const structure elem1 = {6, 7., '8'};
//   const structure elem2 = {7, 8., '9'};
//   const structure expecting_result = {1, 2., '3'};
//   std::initializer_list<std::pair<structure, int>> a = {{elem1, 1}, {elem2, 1}};
//   s21::Map<structure, int> map1(a);
//   std::pair<structure, int> pair1 = {expecting_result, 3};
//   auto v1 = map1.emplace(pair1);
//   auto it_res = map1.begin();
//   EXPECT_TRUE((*it_res).first == expecting_result);
//   EXPECT_TRUE((*it_res).second == 3);
//   ++it_res;
//   EXPECT_TRUE((*it_res).first == elem1);
//   EXPECT_TRUE((*it_res).second == 1);
//   ++it_res;
//   EXPECT_TRUE((*it_res).first == elem2);
//   EXPECT_TRUE((*it_res).second == 1);
//   EXPECT_EQ(v1.at(0).second, true);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
