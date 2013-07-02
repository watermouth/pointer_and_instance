#ifndef SHARED_POINTER_POT_H_
#define SHARED_POINTER_POT_H_

#include "ingredient.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "boost/shared_ptr.hpp"

using std::cout;
using std::endl;
using boost::shared_ptr;

class SharedPointerPot {
private:
  std::vector<shared_ptr<Ingredient> > mIngredients; 
  std::string mName;
  // if this return type is value, then you are to make 2 instance
  // for one return value. 
  static const Ingredient& NewElement(const shared_ptr<Ingredient>& p) {
    return *p;
  }
  static const boost::shared_ptr<Ingredient> NewElementPtr(const shared_ptr<Ingredient>& p) {
    return boost::shared_ptr<Ingredient>(new Ingredient(*p));
  }

public: 
  explicit SharedPointerPot(std::string name)
    : mName(name)
  {
    cout << "SharedPointerPot: c'tor " << mName << endl;
  }
  ~SharedPointerPot() {
    cout << "SharedPointerPot: d'tor " << mName << endl;
  }
  SharedPointerPot(const SharedPointerPot& obj)
    : mName(obj.mName), mIngredients(obj.mIngredients)
  {
    cout << "SharedPointerPot: copy c'tor " << obj.mName << endl;
  }
  SharedPointerPot &operator=(const SharedPointerPot& obj) {
    cout << "SharedPointerPot: operator= " << mName << " <- "
         << obj.mName << endl;
    if (this != &obj) {
      mIngredients = obj.mIngredients;
      mName = obj.mName;
    }
    return *this;
  }
  SharedPointerPot* Clone() const {
    cout << "SharedPointerPot: Clone" << endl;
    SharedPointerPot *obj = new SharedPointerPot(mName); 
    obj->mIngredients.reserve(mIngredients.size());
    std::transform(mIngredients.begin(), mIngredients.end(),
      std::back_inserter(obj->mIngredients), NewElementPtr); 
/*
    for(size_t i = 0; i != mIngredients.size(); ++i){
      obj->mIngredients.push_back(
        shared_ptr<Ingredient>(new Ingredient(*(mIngredients[i])))
      );
    }
*/
    return obj;
  }
  std::string GetName() const {
    return mName;
  }
  void SetIngredient(Ingredient &obj) {
    cout << "SharedPointerPot: SetIngredient " << obj.GetName() << endl;
    // RAII
    mIngredients.push_back(shared_ptr<Ingredient>(new Ingredient(obj)));
    // mIngredients.push_back(shared_ptr<Ingredient>(&obj)); // memory leaks!
  }
  std::vector<Ingredient> GetIngredients() {
    cout << "SharedPointerPot: GetIngredients" << endl;
    std::vector<Ingredient> out;
    out.reserve(mIngredients.size());
    std::transform(mIngredients.begin(), mIngredients.end(),
      std::back_inserter(out), NewElement); 
/*
    for(size_t i=0; i != mIngredients.size(); ++i){
      out.push_back(*mIngredients[i]);
    }
*/
    return out;
  }
  void RemoveIngredients() {
    cout << "SharedPointerPot: RemoveIngredients" << endl;
    mIngredients.clear();
  }
  void CountIngredients() {
    cout << "SharedPointerPot: CountIngredients " 
            << mIngredients.size() << endl;
  }

};


#endif //  SHARED_POINTER_POT_H_

