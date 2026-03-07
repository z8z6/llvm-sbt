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

set(LLVM_TARGET_DEFINITIONS Opts.td)
tablegen(LLVM Opts.inc -gen-opt-parser-defs)
add_public_tablegen_target(SbtOptsTableGen)

add_llvm_tool(llvm-sbt
        llvm-sbt.cpp
        DEPENDS
        SbtOptsTableGen
        GENERATE_DRIVER
)
