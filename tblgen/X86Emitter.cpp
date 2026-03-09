#include "llvm/TableGen/TableGenBackend.h"
#include <iostream>

using namespace llvm;

namespace
{
  int X86InstCount = 0;
  void classDeclare(const Record* Instr, raw_ostream& O)
  {
      auto Name = Instr->getName();
      O << "class " << Name << ";\n";
  }
} // namespace

class X86Emitter {
  const RecordKeeper &RK;

public:
  explicit X86Emitter(const RecordKeeper &RK) : RK(RK) {}
  // 入口函数
  void run(raw_ostream &O) const;
};

void X86Emitter::run(raw_ostream& O) const
{
    emitSourceFileHeader("RVision X86 Instruction Classes",O);

    auto X86Instrs = RK.getAllDerivedDefinitions("X86Inst");
    O << "\n[X86]\n";
    for (auto* Instr : X86Instrs) {
      classDeclare(Instr, O);
      X86InstCount++;
    }
    std::cout << "X86 Count: " << X86InstCount << std::endl;
}

static TableGen::Emitter::OptClass<X86Emitter>
    X("gen-x86-instr", "Generate X86 Instr class");