#include "ingredient.h"
#include <iostream>

using namespace std; 

Ingredient::Ingredient(string name)
  : mName(name)
  {
    cout << "Ingredient: c'tor " << name << endl;
}

Ingredient::~Ingredient() {
  cout << "Ingredient: d'tor " << mName << endl;
}

Ingredient::Ingredient(const Ingredient& obj) { 
  cout << "Ingredient: copy c'tor " << obj.mName << endl; 
  mName = obj.mName;
}

Ingredient &Ingredient::operator=(const Ingredient& obj) {
  cout << "Ingredient: operator=: "
       << mName << " <- " << obj.mName << endl;
  if (this != &obj) {
    mName = obj.mName;
  }
  return *this;
} 

string Ingredient::GetName() const {
  return mName;
}

