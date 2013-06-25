#ifndef SHARED_POINTER_POT_H_
#define SHARED_POINTER_POT_H_

#include "ingredient.h"
#include <string>
#include <vector>
#include <iostream>
#include "boost/shared_ptr.hpp"

using std::cout;
using std::endl;
using boost::shared_ptr;

class SharedPointerPot {
private:
  std::vector<shared_ptr<Ingredient> > mIngredients; 
  std::string mName;
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
  SharedPointerPot Clone() const {
    cout << "SharedPointerPot: Clone" << endl;
    SharedPointerPot obj(mName); 
    for(size_t i = 0; i != mIngredients.size(); ++i){
      obj.mIngredients.push_back(
        shared_ptr<Ingredient>(new Ingredient(*(mIngredients[i])))
      );
    }
    return obj;
  }
  void SetIngredient(Ingredient &obj) {
    cout << "SharedPointerPot: SetIngredient " << obj.GetName() << endl;
    // RAII
    mIngredients.push_back(shared_ptr<Ingredient>(new Ingredient(obj)));
    // mIngredients.push_back(shared_ptr<Ingredient>(&obj)); // memory leaks!
  }
  std::vector<Ingredient> GetIngredients() {
    cout << "SharedPointerPot: GetIngredients" << endl;
    std::vector<Ingredient> out(mIngredients.size(),
      Ingredient("no_name"));
    for(size_t i=0; i != mIngredients.size(); ++i){
      out[i] = *(mIngredients[i]);
    }
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

