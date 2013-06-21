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
  void Release() {
    for(std::vector<Ingredient*>::iterator it = mIngredients.begin();
        it != mIngredients.end(); ++it){
      delete (*it);
    } 
  } 

public: 
  PointerPot(std::string name) : mName(name) {
    cout << "PointerPot: c'tor " << mName << endl;
  }
  ~PointerPot() {
    cout << "PointerPot: d'tor " << mName << endl;
    Release();
  }
  PointerPot(const PointerPot& obj) {
    cout << "PointerPot: copy c'tor " << obj.mName << endl;
  // Trap!!
    mIngredients = obj.mIngredients;
    mName = obj.mName;
  }
  PointerPot &operator=(const PointerPot& obj) {
    cout << "PointerPot: operator= " << mName << " <- "
         << obj.mName << endl;
    if (this != &obj) {
  // Trap!!
      mIngredients = obj.mIngredients;
      mName = obj.mName;
    }
    return *this;
  }
  void SetIngredient(Ingredient &obj) {
    cout << "PointerPot: SetIngredient " << endl;
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
    Release();    
    mIngredients.clear();
  }
  void CountIngredients() {
    cout << "PointerPot: CountIngredients " 
            << mIngredients.size() << endl;
  }

};


#endif //  POINTER_POT_H_

