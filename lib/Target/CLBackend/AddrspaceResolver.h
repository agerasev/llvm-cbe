#pragma once

#include "llvm/IR/Module.h"


namespace llvm_opencl {
  using namespace llvm;

  class AddrspaceResolver {
  public:
    AddrspaceResolver();
    void resolve(Module &M);
  };
}
