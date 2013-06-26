#include "ingredient.h"
#include "scoped_pointer_pot.h"
#include <iostream>
#include <string>

using namespace std;

void put_ingredients_in_a_scoped_pointer_pot() {
  cout << "start this block" << endl;
  ScopedPointerPot p("pot");
  p.CountIngredients();
  Ingredient a("apple"), b("banana");
  p.SetIngredient(a);
  p.CountIngredients();
  p.SetIngredient(b); 
  p.CountIngredients();
  
  cout << "reversed ingredients" << endl;
  vector<Ingredient> reversed = 
    vector<Ingredient>(p.GetIngredients());
  cout << "clear reversed ingredients" << endl;
  reversed.clear();
 
  p.RemoveIngredients();
  p.CountIngredients();

  cout << endl << "exit this block" << endl;
}

void copy_a_scoped_pointer_pot() {
  cout << "start this block" << endl;
  ScopedPointerPot p("first");
  Ingredient a("apple"), b("banana");
  p.SetIngredient(a);
  p.SetIngredient(b); 
  p.CountIngredients();
  p.RemoveIngredients();
  cout << "--- copy and assignment --- " << endl;
  ScopedPointerPot p_copied(p);
  ScopedPointerPot p_assigned("second");
  p_assigned = p;
  p_copied.RemoveIngredients();
  p_assigned.RemoveIngredients();
  cout << endl << "exit this block" << endl;
}

int main(int argc, char** argv){
  cout << endl << "***** start main *****" << endl ;
  cout << endl << "*** put_ingredients_in_a_scoped_pointer_pot ***" << endl;
  put_ingredients_in_a_scoped_pointer_pot();
  cout << endl << "*** copy_a_scoped_pointer_pot ***" << endl;
  copy_a_scoped_pointer_pot();
  cout << endl << "***** end main *****" << endl << endl;
  return 0;
}

