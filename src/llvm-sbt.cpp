
#include "llvm-sbt.h"
#include "Opts.inc"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/LLVMDriver.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

int llvm_sbt_main(int argc, char **argv, const ToolContext &) {
  dbgs() << "[llvm-sbt]: first init at 2026.3.7\n";
  cl::ParseCommandLineOptions(argc, argv);
  //cl::HideUnrelatedOptions();
  return 0;
}