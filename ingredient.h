#ifndef INGREDIENT_H_
#define INGREDIENT_H_

#include <string>

class Ingredient {
private:
  std::string mName;

public:
  Ingredient(std::string name);
  ~Ingredient(); 
  Ingredient(const Ingredient& obj); 
  Ingredient &operator=(const Ingredient& obj);
  std::string GetName() const;
};


#endif //  INGREDIENT_H_

