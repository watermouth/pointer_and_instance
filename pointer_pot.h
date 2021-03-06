#ifndef POINTER_POT_H_
#define POINTER_POT_H_

#include "ingredient.h"
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

class PointerPot {
private:
  std::vector<Ingredient* > mIngredients; 
  std::string mName;
public: 
  explicit PointerPot(std::string name)
    : mName(name)
  {
    cout << "PointerPot: c'tor " << mName << endl;
  }
  ~PointerPot() {
    cout << "PointerPot: d'tor " << mName << endl;
    // if delete Ingredients here, then original owner deletes those again and error occurs.
  }
  PointerPot(const PointerPot& obj)
    : mName(obj.mName), mIngredients(obj.mIngredients)
  {
    cout << "PointerPot: copy c'tor " << obj.mName << endl;
  }
  PointerPot &operator=(const PointerPot& obj) {
    cout << "PointerPot: operator= " << mName << " <- "
         << obj.mName << endl;
    if (this != &obj) {
      mIngredients = obj.mIngredients;
      mName = obj.mName;
    }
    return *this;
  }
  PointerPot Clone() const {
    cout << "PointerPot: Clone" << endl;
    PointerPot obj(mName); 
    for(size_t i = 0; i != mIngredients.size(); ++i){
      obj.mIngredients.push_back(new Ingredient(*(mIngredients[i])));
    }
    return obj;
  }
  /// use this for cloned object
  void Release() {
    for(size_t i=0; i != mIngredients.size(); ++i){
      cout << "deleting..." << endl;
      delete mIngredients[i];
      cout << "...deleted" << endl;
    }
    RemoveIngredients();
  } 

  void SetIngredient(Ingredient &obj) {
    cout << "PointerPot: SetIngredient " << obj.GetName() << endl;
    mIngredients.push_back(&obj);
  }
  std::vector<Ingredient> GetIngredients() {
    cout << "PointerPot: GetIngredients" << endl;
    std::vector<Ingredient> out(mIngredients.size(),
      Ingredient("no_name"));
    for(size_t i=0; i != mIngredients.size(); ++i){
      out[i] = *(mIngredients[i]);
    }
    return out;
  }
  void RemoveIngredients() {
    cout << "PointerPot: RemoveIngredients" << endl;
    mIngredients.clear();
  }
  void CountIngredients() {
    cout << "PointerPot: CountIngredients " 
            << mIngredients.size() << endl;
  }

};


#endif //  POINTER_POT_H_

