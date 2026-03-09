
#include "llvm-sbt.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/LLVMDriver.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

int llvm_sbt_main(int Argc, char **Argv, const ToolContext &) {
  cl::ParseCommandLineOptions(Argc, Argv);
  return 0;
}