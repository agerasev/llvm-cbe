#include "AddrspaceResolver.h"

#include "llvm/Transforms/Utils/Cloning.h"

namespace llvm_opencl {
  AddrspaceResolver::AddrspaceResolver() {

  }

  void AddrspaceResolver::resolve(Module &M) {
    std::unique_ptr<Module> L = CloneModule(M);
    //M.getFunctionList().clear();

    for (Module::iterator I = M.begin(), E = M.end(); I != E; ++I) {
      outs() << I->getName() << "\n";
    }
  }
}
