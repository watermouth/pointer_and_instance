#include "ingredient.h"
#include "plain_pot.h"
#include <iostream>
#include <string>

using namespace std;

void construct_and_destroy(){
  cout << "start this block" << endl;
  cout << "make ingredients" << endl;
  Ingredient carot("carot"), apple("apple"), johndoe(""); 

  cout << "assignment " << endl;
  johndoe = carot;
  cout << "copy c'tor" << endl;
  Ingredient apple2(apple);
  
  cout << endl << "exit this block" << endl;
}

void put_ingredients_in_a_pot() {
  cout << "start this block" << endl;
  PlainPot p("pot");
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

void copy_a_plain_pot() {
  cout << "start this block" << endl;
  PlainPot p("first");
  Ingredient a("apple"), b("banana");
  p.SetIngredient(a);
  p.SetIngredient(b); 
  p.CountIngredients();
  
  PlainPot p_copied(p);
  PlainPot p_assigned("second");
  p_assigned = p;
  
  cout << endl << "exit this block" << endl;
}

int main(int argc, char** argv){
  cout << endl << "***** start main *****" << endl ;
  cout << endl << "*** construct_and_destroy ***" << endl;
  construct_and_destroy();
  cout << endl << "*** put_ingredients_in_a_pot ***" << endl;
  put_ingredients_in_a_pot();
  cout << endl << "*** copy_a_plain_pot ***" << endl;
  copy_a_plain_pot();
  cout << endl << "***** end main *****" << endl << endl;
  return 0;
}

