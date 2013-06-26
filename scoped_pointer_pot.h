#ifndef SCOPED_POINTER_POT_H_
#define SCOPED_POINTER_POT_H_

#include "ingredient.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "boost/scoped_ptr.hpp"

using std::cout;
using std::endl;
using boost::scoped_ptr;

class ScopedPointerPot {
private:
  // bad declaration: scoped_ptr cannot be used in container.
  std::vector<scoped_ptr<Ingredient> > mIngredients; 
  std::string mName;
  // bad : this makes error. scoped_ptr can't be copy constructed.
/*
  void PushBackNewElement(scoped_ptr<Ingredient> p){
    mIngredients.push_back(scoped_ptr<Ingredient>(new Ingredient(*p)));
  } 
  scoped_ptr<Ingredient> NewElement(const scoped_ptr<Ingredient>& p) const {
    return scoped_ptr<Ingredient>(new Ingredient(*p));
  }
*/
public: 
  explicit ScopedPointerPot(std::string name)
    : mName(name)
  {
    cout << "ScopedPointerPot: c'tor " << mName << endl;
  }
  ~ScopedPointerPot() {
    cout << "ScopedPointerPot: d'tor " << mName << endl;
  }
  ScopedPointerPot(const ScopedPointerPot& obj)
    : mName(obj.mName)
  {
    cout << "ScopedPointerPot: copy c'tor " << obj.mName << endl;
    for(int i=0; i != mIngredients.size(); ++i){
      mIngredients[i] = scoped_ptr<Ingredient>(
        new Ingredient(*(obj.mIngredients[i])));
    }
/*
    std::for_each(mIngredients.begin(),mIngredients.end(),
      PushBackNewElement); 
*/
  }
  ScopedPointerPot &operator=(const ScopedPointerPot& obj) {
    cout << "ScopedPointerPot: operator= " << mName << " <- "
         << obj.mName << endl;
    if (this != &obj) {
      for(int i=0; i != mIngredients.size(); ++i){
        mIngredients[i] = scoped_ptr<Ingredient>(
          new Ingredient(*(obj.mIngredients[i])));
      }
      mName = obj.mName;
    }
    return *this;
  }
  void SetIngredient(Ingredient &obj) {
    cout << "ScopedPointerPot: SetIngredient " << obj.GetName() << endl;
    // RAII
    mIngredients.push_back(scoped_ptr<Ingredient>(new Ingredient(obj)));
  }
  std::vector<Ingredient> GetIngredients() {
    cout << "ScopedPointerPot: GetIngredients" << endl;
    std::vector<Ingredient> out;
    out.resize(mIngredients.size());
/*
    std::transform(mIngredients.begin(), mIngredients.end(),
      std::back_inserter(out), NewElement); 
*/
    return out;
  }
  void RemoveIngredients() {
    cout << "ScopedPointerPot: RemoveIngredients" << endl;
    mIngredients.clear();
  }
  void CountIngredients() {
    cout << "ScopedPointerPot: CountIngredients " 
            << mIngredients.size() << endl;
  }

};


#endif //  SCOPED_POINTER_POT_H_

