#include "shared_pointer_pot.h"
#include "gtest/gtest.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class SharedPointerPotTest : public testing::Test {
protected:
//  vector<Ingredient> ingredients_;
 
  virtual void SetUp() {
    Ingredient x("fafa");
/*
    ingredients_.push_back(Ingredient("banana"));
    ingredients_.push_back(Ingredient("carot"));
*/
  }

  void ConstructorTestor(string s) {
    SharedPointerPot p(s);
    ASSERT_EQ(s, p.GetName());
  } 
};

TEST_F(SharedPointerPotTest, Constructor){
  SharedPointerPot p("old-one");
  ASSERT_EQ("old-one", p.GetName());
  ConstructorTestor("hoge");
}

