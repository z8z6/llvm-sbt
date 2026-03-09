#include "llvm/TableGen/TableGenBackend.h"
#include <iostream>

using namespace llvm;

namespace
{
  int RVInstCount = 0;
  void classDeclare(const Record* Instr, raw_ostream& O)
  {
    auto Name = Instr->getName();
    O << "class " << Name << ";\n";
  }
} // namespace

class RISCVEmitter {
  const RecordKeeper &RK;

public:
  explicit RISCVEmitter(const RecordKeeper &RK) : RK(RK) {}
  // 入口函数
  void run(raw_ostream &O) const;
};

void RISCVEmitter::run(raw_ostream& O) const
{
  emitSourceFileHeader("RVision RISCV Instruction Classes",O);

  auto RVInstrs = RK.getAllDerivedDefinitions("RVInstCommon");
  O << "\n[RISCV]\n";
  for (auto* Instr : RVInstrs) {
    classDeclare(Instr, O);
    RVInstCount++;
  }

  std::cout << "RISCV Count: " << RVInstCount << std::endl;
}

static TableGen::Emitter::OptClass<RISCVEmitter>
    R("gen-riscv-instr", "Generate RISCV Instr class");