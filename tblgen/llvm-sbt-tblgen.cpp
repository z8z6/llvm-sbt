#include "llvm/TableGen/Main.h"
#include "llvm/Support/InitLLVM.h"

int main(int argc, char **argv) {
  llvm::InitLLVM X(argc, argv);
  llvm::cl::ParseCommandLineOptions(argc, argv);

  llvm::MultiFileTableGenMainFn MainFn = nullptr;
  return TableGenMain(argv[0], MainFn);
}