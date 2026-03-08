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

# tableGen 输入源文件
set(LLVM_TARGET_DEFINITIONS Opts.td)
# llvm-tblgen
# Emitter: -gen-opt-parser-defs OptParserEmitter
tablegen(LLVM Opts.inc -gen-opt-parser-defs)
add_public_tablegen_target(SbtOptsTableGen)


set(LLVM_TARGET_DEFINITIONS tblgen/X86.td)
tablegen(LLVM Trans/X86Trans.inc -gen-x86-trans)
add_public_tablegen_target(X86TransTableGen)
add_dependencies(X86TransTableGen llvm-sbt-tblgen)

file(GLOB_RECURSE Src
        src/*.cpp
        tblgen/X86Emitter.cpp
)

add_llvm_tool(llvm-sbt
        ${Src}
        DEPENDS
        SbtOptsTableGen
        X86TransTableGen
        GENERATE_DRIVER
)

target_include_directories(llvm-sbt PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
