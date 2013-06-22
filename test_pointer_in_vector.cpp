#include "ingredient.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test_pointers_in_vector(){
  Ingredient a("apple"), b("banana");
  vector<Ingredient*> p_vec;
  p_vec.reserve(2);
  cout << "reserved p_vec: size = capacity" << endl;
  for(size_t i=0; i != p_vec.capacity(); ++i){
    cout << " [" << i << "]: " << p_vec[i] << endl;
  }
  p_vec.push_back(&a);
  p_vec.push_back(&b);
  cout << "after push_back" << endl;
  for(size_t i=0; i != p_vec.capacity(); ++i){
    cout << " [" << i << "]: " << p_vec[i] << endl;
  }
  Ingredient* ptr;
  ptr = p_vec[0];
  // delete ptr; // error 
  p_vec.clear();
  cout << "after clear: size = capacity" << endl;
  for(size_t i=0; i != p_vec.capacity(); ++i){
    cout << " [" << i << "]: " << p_vec[i] << endl;
  }
  cout << "size = " << p_vec.size() << endl;
  cout << endl << "exit this block" << endl;
}

int main(int argc, char** argv){
  cout << endl << "***** start main *****" << endl ;
  cout << endl << "*** test_pointers_in_vector ***" << endl;
  test_pointers_in_vector();
  cout << endl << "***** end main *****" << endl << endl;
  return 0;
}

