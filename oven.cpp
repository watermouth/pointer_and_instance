#include "oven.h"
#include <boost/shared_ptr.hpp>

using std::vector;
using boost::shared_ptr;

class Oven::Impl {
public:
  vector<shared_ptr<SharedPointerPot> > mPotPtrs; 

};

Oven::Oven() : mPimpl(new Impl()) {}
Oven::~Oven() {
  //delete mPimpl;
}

void Oven::PushBackPot(const SharedPointerPot& obj) {
  mPimpl->mPotPtrs.push_back(shared_ptr<SharedPointerPot>(obj.Clone()));
}

vector<SharedPointerPot> Oven::GetPots() const {
  vector<SharedPointerPot> out;
  out.reserve(mPimpl->mPotPtrs.size());
  for(size_t i=0; i != mPimpl->mPotPtrs.size(); ++i) {
     out.push_back(*(mPimpl->mPotPtrs[i])); 
  } 
  return out;
}
 
