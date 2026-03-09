# /root/llvm/src/llvm-project/llvm/tools/llvm-sbt   Opts.td
# /root/llvm/build/22.1.0/tools/llvm-sbt            Opts.inc

add_subdirectory(tblgen)

set(LLVM_LINK_COMPONENTS
        AllTargetsDescs
        AllTargetsDisassemblers
        AllTargetsInfos
        Core
        MC
        MCDisassembler
        Object
        Option
        Support
)

# ========================= TableGen ========================= #
# 1. llvm-tblgen --gen-opt-parser-defs Opts.td
# tableGen 输入源文件
set(LLVM_TARGET_DEFINITIONS Opts.td)
# llvm-tblgen
# Emitter: -gen-opt-parser-defs OptParserEmitter
tablegen(LLVM Opts.inc -gen-opt-parser-defs)
add_public_tablegen_target(SbtOptsTableGen)

# 2. llvm-sbt-tblgen --gen-x86-trans tblgen/X86Trans.td
# 替换tblgen路径
set(ORIGINAL_LLVM_TABLEGEN_EXE ${LLVM_TABLEGEN_EXE})
set(LLVM_TABLEGEN_EXE $<TARGET_FILE:llvm-sbt-tblgen>)

# 添加头文件路径
set(X86_TD_DIR "/root/llvm/src/llvm-project/llvm/lib/Target/X86")
set(RISCV_TD_DIR "/root/llvm/src/llvm-project/llvm/lib/Target/RISCV")


set(LLVM_TARGET_DEFINITIONS tblgen/X86.td)
tablegen(LLVM Trans/X86.inc -gen-x86-instr -I${X86_TD_DIR})
add_public_tablegen_target(X86InstrTableGen)

set(LLVM_TARGET_DEFINITIONS tblgen/RISCV.td)
tablegen(LLVM Trans/RISCV.inc -gen-riscv-instr -I${RISCV_TD_DIR})
add_public_tablegen_target(RISCVInstrTableGen)

# 添加依赖
add_dependencies(X86InstrTableGen llvm-sbt-tblgen)
add_dependencies(RISCVInstrTableGen llvm-sbt-tblgen)
# 恢复路径
set(LLVM_TABLEGEN_EXE ${ORIGINAL_LLVM_TABLEGEN_EXE})

# ========================= llvm-sbt ========================= #

file(GLOB_RECURSE Src
        src/*.cpp
)

add_llvm_tool(llvm-sbt
    ${Src}
    DEPENDS
    SbtOptsTableGen
    X86InstrTableGen
    RISCVInstrTableGen
    GENERATE_DRIVER
)

target_include_directories(llvm-sbt PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
