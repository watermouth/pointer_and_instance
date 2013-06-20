#ifndef PLAIN_POT_H_
#define PLAIN_POT_H_

#include "ingredient.h"
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

class PlainPot {
private:
  std::vector<Ingredient> mIngredients; 
  std::string mName;

public: 
  PlainPot(std::string name) : mName(name) {
    cout << "PlainPot: c'tor " << mName << endl;
  }
  ~PlainPot() { cout << "PlainPot: d'tor " << mName << endl;}
  PlainPot(const PlainPot& obj) {
    cout << "PlainPot: copy c'tor " << obj.mName << endl;
    mIngredients = obj.mIngredients;
    mName = obj.mName;
  }
  PlainPot &operator=(const PlainPot& obj) {
    cout << "PlainPot: operator= " << mName << " <- "
         << obj.mName << endl;
    if (this != &obj) {
      mIngredients = obj.mIngredients;
      mName = obj.mName;
    }
    return *this;
  }
  void SetIngredient(const Ingredient& obj) {
    cout << "PlainPot: SetIngredient " << endl;
    mIngredients.push_back(obj);
  }
  std::vector<Ingredient> GetIngredients() {
    cout << "PlainPot: GetIngredients" << endl;
    return mIngredients;
  }
  void RemoveIngredients() {
    cout << "PlainPot: RemoveIngredients" << endl;
    mIngredients.clear();
  }
  void CountIngredients() {
    cout << "PlainPot: CountIngredients " 
            << mIngredients.size() << endl;
  }

};


#endif //  PLAIN_POT_H_

