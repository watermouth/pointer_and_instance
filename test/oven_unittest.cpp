#include "gtest/gtest.h"
#include "ingredient.h"
#include "oven.h"

#include <string>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

using boost::shared_ptr;
using boost::scoped_ptr;

class OvenTest : public testing::Test {
protected:
  shared_ptr<Ingredient> apple_ptr_, banana_ptr_, carot_ptr_;
  scoped_ptr<Oven> scoped_oven_;
  scoped_ptr<SharedPointerPot> spot_;

  void SetUp() {
    apple_ptr_ = shared_ptr<Ingredient>(new Ingredient("apple"));
    banana_ptr_.reset(new Ingredient("banana"));
    carot_ptr_.reset(new Ingredient("carot"));
    scoped_oven_.reset(new Oven());
    spot_.reset(new SharedPointerPot("sp"));
    spot_->SetIngredient(*apple_ptr_);
    spot_->SetIngredient(*banana_ptr_);
    spot_->SetIngredient(*carot_ptr_);
  }

};

TEST_F(OvenTest, Constructor) {
  Oven o1;
  std::vector<SharedPointerPot> pots(o1.GetPots());
  EXPECT_EQ(0, pots.size());
}

TEST_F(OvenTest, PushBackPotTest){
  scoped_oven_->PushBackPot(*spot_);
  std::vector<SharedPointerPot> pots = scoped_oven_->GetPots(); 
  EXPECT_EQ(1, pots.size());
  EXPECT_EQ("sp", pots[0].GetName());
  std::vector<Ingredient> ingredients = pots[0].GetIngredients();
  EXPECT_EQ(3, ingredients.size()); 

  scoped_oven_->PushBackPot(SharedPointerPot("emptypot"));
  pots = scoped_oven_->GetPots(); 
  EXPECT_EQ(2, pots.size());
  EXPECT_EQ("sp", pots[0].GetName());
  ingredients = pots[1].GetIngredients();
  EXPECT_EQ(0, ingredients.size()); 
}

