#include <iostream>
#include <vector>
#include <boost/interprocess/smart_ptr/unique_ptr.hpp>
#include <boost/checked_delete.hpp>

using namespace std;
using boost::interprocess::unique_ptr;
using boost::checked_deleter;

typedef unique_ptr<int, checked_deleter<int> > unique_pointer;

int main() {
  unique_pointer x1(new int);
  return 0;
}

