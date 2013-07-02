#include "shared_pointer_pot.h"
#include <boost/scoped_ptr.hpp>

class Oven {
public:
  Oven(); 
  ~Oven();
  void PushBackPot(const SharedPointerPot& );
  std::vector<SharedPointerPot> GetPots() const;

private:
  Oven(const Oven&);
  Oven& operator=(const Oven&);
  class Impl;
  //Impl* mPimpl;
  boost::scoped_ptr<Impl> mPimpl;
};


