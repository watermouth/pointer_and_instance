#ifndef UNIQUE_POINTER_POT_H_
#define UNIQUE_POINTER_POT_H_

#include "ingredient.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "boost/interprocess/smart_ptr/unique_ptr.hpp"
#include "boost/checked_delete.hpp"

using std::cout;
using std::endl;
using std::vector;
using boost::interprocess::unique_ptr;
typedef unique_ptr<Ingredient, boost::checked_deleter<Ingredient> > IngredientUniquePtr; 

class UniquePointerPot {
private:
  // bad declaration: unique_ptr cannot be used in container.
  // The unique_ptr of C++11 can be used.
  vector<IngredientUniquePtr> mIngredients; 
  std::string mName;
/*
  void PushBackNewElement(const IngredientUniquePtr& p){
    mIngredients.push_back(IngredientUniquePtr(new Ingredient(*p)));
  } 
  IngredientUniquePtr NewElement(const IngredientUniquePtr& p) const {
    return IngredientUniquePtr(new Ingredient(*p));
  }
*/
public: 
  explicit UniquePointerPot(std::string name)
    : mName(name)
  {
    cout << "UniquePointerPot: c'tor " << mName << endl;
  }
  ~UniquePointerPot() {
    cout << "UniquePointerPot: d'tor " << mName << endl;
  }
  UniquePointerPot(const UniquePointerPot& obj)
    : mName(obj.mName), mIngredients(obj.mIngredients)
  {
    cout << "UniquePointerPot: copy c'tor " << obj.mName << endl;
    for(size_t i=0; i != obj.mIngredients.size(); ++i){
      //IngredientUniquePtr x(new Ingredient(*(obj.mIngredients[i])));
      //mIngredients.push_back(x);
    }
/*
    std::transform(obj.mIngredients.begin(), obj.mIngredients.end(),
      std::back_inserter(mIngredients), NewElement); 
    std::for_each(obj.mIngredients.begin(),obj.mIngredients.end(),
      PushBackNewElement); 
*/
  }
/*
  UniquePointerPot &operator=(const UniquePointerPot& obj) {
    cout << "UniquePointerPot: operator= " << mName << " <- "
         << obj.mName << endl;
    if (this != &obj) {
      mIngredients.clear();
      for(size_t i=0; i != obj.mIngredients.size(); ++i){
        mIngredients.push_back(
          IngredientUniquePtr(new Ingredient(*(obj.mIngredients[i])))
        );
      }
      mName = obj.mName;
    }
    return *this;
  }
*/
  void SetIngredient(Ingredient &obj) {
    cout << "UniquePointerPot: SetIngredient " << obj.GetName() << endl;
    // RAII
    mIngredients.push_back(IngredientUniquePtr(new Ingredient(obj)));
  }
  vector<Ingredient> GetIngredients() {
    cout << "UniquePointerPot: GetIngredients" << endl;
    vector<Ingredient> out;
    //out.reserve(mIngredients.size());
    for(size_t i=0; i != mIngredients.size(); ++i){
      out.push_back(Ingredient(*(mIngredients[i])));
    }
/*
    std::transform(mIngredients.begin(), mIngredients.end(),
      std::back_inserter(out), NewElement); 
*/
    return out;
  }
  void RemoveIngredients() {
    cout << "UniquePointerPot: RemoveIngredients" << endl;
    mIngredients.clear();
  }
  void CountIngredients() {
    cout << "UniquePointerPot: CountIngredients " 
            << mIngredients.size() << endl;
  }

};


#endif //  UNIQUE_POINTER_POT_H_

