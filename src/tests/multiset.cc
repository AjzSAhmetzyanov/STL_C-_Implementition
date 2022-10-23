#include "../Multiset/s21_multiset.h"

#include <gtest/gtest.h>

#include <set>

std::initializer_list<int> init1 = {1, 1, 2, 1, 3, 4, 5, 3,
                                    4, 6, 9, 6, 6, 6, 7, 10};
std::initializer_list<int> init2 = {2, 2, 34, 63, 23, 1, 9, 4, 9, 5};

TEST(multiset_test, constr1) {
  s21::Multiset<int> ms1;
  std::multiset<int> ms2;
  auto it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, constr2) {
  s21::Multiset<int> ms1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::multiset<int> ms2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, constr3) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  auto it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, constr4) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  auto ms11 = ms1;
  auto ms22 = ms2;
  auto it1 = ms11.begin();
  for (auto it2 = ms22.begin(); it2 != ms22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms11.size(), ms22.size());
  it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, constr5) {
  s21::Multiset<int> ms1;
  std::multiset<int> ms2;
  auto ms11 = ms1;
  auto ms22 = ms2;
  auto it1 = ms11.begin();
  for (auto it2 = ms22.begin(); it2 != ms22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms11.size(), ms22.size());
  it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, constr6) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  auto ms11 = std::move(ms1);
  auto ms22 = std::move(ms2);
  auto it1 = ms11.begin();
  for (auto it2 = ms22.begin(); it2 != ms22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms11.size(), ms22.size());
  it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, constr7) {
  s21::Multiset<int> ms1;
  std::multiset<int> ms2;
  auto ms11 = std::move(ms1);
  auto ms22 = std::move(ms2);
  auto it1 = ms11.begin();
  for (auto it2 = ms22.begin(); it2 != ms22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms11.size(), ms22.size());
  it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, constr8) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  s21::Multiset<int> ms11;
  std::multiset<int> ms22;
  ms11 = std::move(ms1);
  ms22 = std::move(ms2);
  auto it1 = ms11.begin();
  for (auto it2 = ms22.begin(); it2 != ms22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms11.size(), ms22.size());
  it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, constr9) {
  s21::Multiset<std::string> ms1 = {"some", "not",  "sorted", "words",
                                    "will", "come", "out",    "sorted"};
  std::multiset<std::string> ms2 = {"some", "not",  "sorted", "words",
                                    "will", "come", "out",    "sorted"};
  auto it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, begin1) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  auto it1 = ms1.begin();
  auto it2 = ms2.begin();
  EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, begin2) {
  s21::Multiset<int> ms1;
  auto it1 = ms1.begin();
  EXPECT_NE(it1.base(), nullptr);
}

TEST(multiset_test, end1) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  auto it1 = ms1.end();
  auto it2 = ms2.end();
  it1++;
  it2++;
  EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, end2) {
  s21::Multiset<int> ms1;
  auto it1 = ms1.end();
  EXPECT_NE(it1.base(), nullptr);
}

TEST(multiset_test, empty1) {
  s21::Multiset<int> ms1;
  std::multiset<int> ms2;
  EXPECT_EQ(ms1.empty(), ms2.empty());
}

TEST(multiset_test, empty2) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  EXPECT_EQ(ms1.empty(), ms2.empty());
}

TEST(multiset_test, empty3) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  ms1.clear();
  ms2.clear();
  EXPECT_EQ(ms1.empty(), ms2.empty());
}

TEST(multiset_test, size1) {
  s21::Multiset<int> ms1;
  std::multiset<int> ms2;
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, size2) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, size3) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  ms1.clear();
  ms2.clear();
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, clear1) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  ms1.clear();
  ms2.clear();
  EXPECT_EQ(ms1.empty(), ms2.empty());
}

TEST(multiset_test, clear2) {
  s21::Multiset<int> ms1;
  std::multiset<int> ms2;
  ms1.clear();
  ms2.clear();
  EXPECT_EQ(ms1.empty(), ms2.empty());
}

TEST(multiset_test, insert1) {
  s21::Multiset<int> ms1;
  std::multiset<int> ms2;
  for (int i = 0; i < 1000; i++) {
    int num = rand();
    EXPECT_EQ(*(ms1.insert(num)), *(ms2.insert(num)));
  }
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, insert2) {
  s21::Multiset<int> ms1;
  std::multiset<int> ms2;
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(*(ms1.insert(1)), *(ms2.insert(1)));
  }
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, insert3) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  for (int i = 0; i < 100; i++) {
    int num = rand();
    ms1.insert(num);
    ms2.insert(num);
  }
  auto it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms1.size(), ms2.size());
}

// TEST(multiset_test, erase1) {  // exc leak
//   s21::Multiset<int> ms1;
//   EXPECT_ANY_THROW(ms1.erase(ms1.begin()));
// }

TEST(multiset_test, erase2) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  EXPECT_EQ(ms1.size(), ms2.size());
  auto it1 = ms1.begin();
  auto it2 = ms2.begin();
  ms1.erase(it1);
  ms2.erase(it2);
  it1 = ms1.begin();
  it2 = ms2.begin();
  for (; it2 != ms2.end(); it1++, it2++) EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(ms1.size(), ms2.size());
}

TEST(multiset_test, erase3) {  // exc leak
  s21::Multiset<int> ms1 = init1;
  EXPECT_ANY_THROW(ms1.erase(ms1.end()));
}

TEST(multiset_test, swap1) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  s21::Multiset<int> ms11;
  std::multiset<int> ms22;
  ms1.swap(ms11);
  ms2.swap(ms22);
  EXPECT_EQ(ms1.size(), ms2.size());
  EXPECT_EQ(ms11.size(), ms22.size());
  auto it1 = ms1.begin();
  auto it11 = ms11.begin();
  auto it2 = ms2.begin();
  auto it22 = ms22.begin();
  for (; it2 != ms2.end(); it1++, it2++) EXPECT_EQ(*it1, *it2);
  for (; it22 != ms22.end(); it11++, it22++) EXPECT_EQ(*it11, *it22);
}

TEST(multiset_test, swap2) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  s21::Multiset<int> ms11 = init2;
  std::multiset<int> ms22 = init2;
  ms1.swap(ms11);
  ms2.swap(ms22);
  EXPECT_EQ(ms1.size(), ms2.size());
  EXPECT_EQ(ms11.size(), ms22.size());
  auto it1 = ms1.begin();
  auto it11 = ms11.begin();
  auto it2 = ms2.begin();
  auto it22 = ms22.begin();
  for (; it2 != ms2.end(); it1++, it2++) EXPECT_EQ(*it1, *it2);
  for (; it22 != ms22.end(); it11++, it22++) EXPECT_EQ(*it11, *it22);
}

TEST(multiset_test, merge1) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  s21::Multiset<int> ms11 = init2;
  std::multiset<int> ms22 = init2;
  ms1.merge(ms11);
  ms2.merge(ms22);
  auto it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, merge2) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  s21::Multiset<int> ms11;
  std::multiset<int> ms22;
  ms1.merge(ms11);
  ms2.merge(ms22);
  auto it1 = ms1.begin();
  for (auto it2 = ms2.begin(); it2 != ms2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, count1) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  EXPECT_EQ(ms1.count(1), ms2.count(1));
  EXPECT_EQ(ms1.count(2), ms2.count(2));
  EXPECT_EQ(ms1.count(6), ms2.count(6));
}

TEST(multiset_test, count2) {
  s21::Multiset<int> ms1;
  std::multiset<int> ms2;
  EXPECT_EQ(ms1.count(1), ms2.count(1));
  EXPECT_EQ(ms1.count(2), ms2.count(2));
  EXPECT_EQ(ms1.count(6), ms2.count(6));
}

TEST(multiset_test, count3) {
  s21::Multiset<int> ms1 = {1, 1, 1, 1, 1, 1, 1, 1};
  std::multiset<int> ms2 = {1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(ms1.count(1), ms2.count(1));
  EXPECT_EQ(ms1.count(2), ms2.count(2));
  EXPECT_EQ(ms1.count(6), ms2.count(6));
}

TEST(multiset_test, find1) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  EXPECT_EQ(*(ms1.find(1)), *(ms2.find(1)));
  EXPECT_EQ(*(ms1.find(2)), *(ms2.find(2)));
  EXPECT_EQ(*(ms1.find(6)), *(ms2.find(6)));
}

TEST(multiset_test, find2) {
  s21::Multiset<int> ms1;
  EXPECT_EQ(ms1.find(1).base(), ms1.end().base());
  EXPECT_EQ(ms1.find(2).base(), ms1.end().base());
  EXPECT_EQ(ms1.find(6).base(), ms1.end().base());
}

TEST(multiset_test, find3) {
  s21::Multiset<int> ms1 = {1, 1, 1, 1, 1, 1, 1, 1};
  std::multiset<int> ms2 = {1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(*(ms1.find(1)), *(ms2.find(1)));
}

TEST(multiset_test, contains1) {
  s21::Multiset<int> ms1 = init1;
  EXPECT_EQ(ms1.contains(1), true);
  EXPECT_EQ(ms1.contains(2), true);
  EXPECT_EQ(ms1.contains(6), true);
}

TEST(multiset_test, contains2) {
  s21::Multiset<int> ms1;
  EXPECT_EQ(ms1.contains(1), false);
  EXPECT_EQ(ms1.contains(2), false);
  EXPECT_EQ(ms1.contains(6), false);
}

TEST(multiset_test, contains3) {
  s21::Multiset<int> ms1 = {1, 1, 1, 1, 1, 1, 1, 1};
  std::multiset<int> ms2 = {1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(ms1.contains(1), true);
  EXPECT_EQ(ms1.contains(2), false);
  EXPECT_EQ(ms1.contains(6), false);
}

TEST(multiset_test, equal_range1) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  auto pair1 = ms1.equal_range(9);
  auto pair2 = ms2.equal_range(9);
  EXPECT_EQ(*(pair1.first), *(pair2.first));
  EXPECT_EQ(*(pair1.second), *(pair2.second));
  pair1 = ms1.equal_range(1);
  pair2 = ms2.equal_range(1);
  EXPECT_EQ(*(pair1.first), *(pair2.first));
  EXPECT_EQ(*(pair1.second), *(pair2.second));
  pair1 = ms1.equal_range(2);
  pair2 = ms2.equal_range(2);
  EXPECT_EQ(*(pair1.first), *(pair2.first));
  EXPECT_EQ(*(pair1.second), *(pair2.second));
}

TEST(multiset_test, equal_range2) {
  s21::Multiset<int> ms1;
  auto pair1 = ms1.equal_range(9);
  EXPECT_EQ(pair1.first.base(), ms1.end().base());
  EXPECT_EQ(pair1.second.base(), ms1.end().base());
  pair1 = ms1.equal_range(1);
  EXPECT_EQ(pair1.first.base(), ms1.end().base());
  EXPECT_EQ(pair1.second.base(), ms1.end().base());
  pair1 = ms1.equal_range(2);
  EXPECT_EQ(pair1.first.base(), ms1.end().base());
  EXPECT_EQ(pair1.second.base(), ms1.end().base());
}

TEST(multiset_test, lower_bound1) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  auto it1 = ms1.lower_bound(9);
  auto it2 = ms2.lower_bound(9);
  EXPECT_EQ(*(it1), *(it2));
  it1 = ms1.lower_bound(1);
  it2 = ms2.lower_bound(1);
  EXPECT_EQ(*(it1), *(it2));
  it1 = ms1.lower_bound(2);
  it2 = ms2.lower_bound(2);
  EXPECT_EQ(*(it1), *(it2));
}

TEST(multiset_test, upper_bound1) {
  s21::Multiset<int> ms1 = init1;
  std::multiset<int> ms2 = init1;
  auto it1 = ms1.upper_bound(9);
  auto it2 = ms2.upper_bound(9);
  EXPECT_EQ(*(it1), *(it2));
  it1 = ms1.upper_bound(1);
  it2 = ms2.upper_bound(1);
  EXPECT_EQ(*(it1), *(it2));
  it1 = ms1.upper_bound(2);
  it2 = ms2.upper_bound(2);
  EXPECT_EQ(*(it1), *(it2));
}

TEST(multiset_test, emplace) {
  struct structure {
    int x_;
    long double y_;
    char z_;
    bool operator==(const structure &other) const {
      return (x_ == other.x_ && y_ == other.y_ && z_ == other.z_);
    }
    bool operator>(const structure &other) const { return x_ > other.x_; }
    bool operator<(const structure &other) const { return x_ < other.x_; }
    bool operator>=(const structure &other) const { return x_ >= other.x_; }
    bool operator<=(const structure &other) const { return x_ <= other.x_; }
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
  s21::Multiset<structure> set1(a);
  auto v1 = set1.emplace(1, 2., '3');
  auto it_res = set1.begin();
  EXPECT_TRUE(*it_res == expecting_result);
  ++it_res;
  EXPECT_TRUE(*it_res == elem1);
  ++it_res;
  EXPECT_TRUE(*it_res == elem2);
  EXPECT_EQ(v1.at(0).second, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}