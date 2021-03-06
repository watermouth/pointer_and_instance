#include "ingredient.h"
#include "shared_pointer_pot.h"
#include <iostream>
#include <string>
#include <boost/scoped_ptr.hpp>

using namespace std;
using boost::scoped_ptr;

void put_ingredients_in_a_shared_pointer_pot() {
  cout << "start this block" << endl;
  SharedPointerPot p("pot");
  p.CountIngredients();
  Ingredient a("apple"), b("banana");
  p.SetIngredient(a);
  p.CountIngredients();
  p.SetIngredient(b); 
  p.CountIngredients();
  
  cout << "get ingredients" << endl;
  vector<Ingredient> reversed = 
    vector<Ingredient>(p.GetIngredients());
  cout << "clear the ingredients" << endl;
  reversed.clear();
 
  p.RemoveIngredients();
  p.CountIngredients();

  cout << endl << "exit this block" << endl;
}

void copy_a_shared_pointer_pot() {
  cout << "start this block" << endl;
  SharedPointerPot p("first");
  Ingredient a("apple"), b("banana");
  p.SetIngredient(a);
  p.SetIngredient(b); 
  p.CountIngredients();
  p.RemoveIngredients();
  cout << "--- copy and assignment --- " << endl;
  SharedPointerPot p_copied(p);
  SharedPointerPot p_assigned("second");
  p_assigned = p;
  p_copied.RemoveIngredients();
  p_assigned.RemoveIngredients();
  cout << endl << "exit this block" << endl;
}

void clone_a_shared_pointer_pot() {
  cout << "start this block" << endl;
  SharedPointerPot p("vegitable_pot");
  Ingredient b("blackberry"),c("carot");
  p.SetIngredient(b);
  p.SetIngredient(c); 
  p.CountIngredients();
  
  cout << "--- clone ---" << endl;
  cout << "   copy c'tor: Does call"
          " copy c'tor on the following line?" << endl;
  scoped_ptr<SharedPointerPot> cloned(p.Clone()); 
  cloned->CountIngredients();
  cloned->RemoveIngredients(); // automatically released on this line!
  cout << "   double call" << endl;
  scoped_ptr<SharedPointerPot> dummy(new SharedPointerPot("dummy"));
  dummy.reset(p.Clone()); 
  dummy.reset(p.Clone()); 
  cout << endl << "exit this block" << endl;
}

int main(int argc, char** argv){
  cout << endl << "***** start main *****" << endl ;
  cout << endl << "*** put_ingredients_in_a_shared_pointer_pot ***" << endl;
  put_ingredients_in_a_shared_pointer_pot();
  cout << endl << "*** copy_a_shared_pointer_pot ***" << endl;
  copy_a_shared_pointer_pot();
  cout << endl << "*** clone_a_shared_pointer_pot ***" << endl;
  clone_a_shared_pointer_pot();
  cout << endl << "***** end main *****" << endl << endl;
  return 0;
}

