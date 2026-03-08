# llvm/utils/TableGen/CMakeLists.txt
# /root/llvm/build/22.1.0/bin
# llvm/tools/llvm-tblgen/llvm-tblgen.cpp

set(LLVM_LINK_COMPONENTS Support)

add_tablegen(llvm-sbt-tblgen LLVM
        DESTINATION "${LLVM_TOOLS_INSTALL_DIR}"
        EXPORT LLVM
        X86Emitter.cpp
        Main.cpp
        $<TARGET_OBJECTS:obj.LLVMTableGenBasic>
        $<TARGET_OBJECTS:obj.LLVMTableGenCommon>

        PARTIAL_SOURCES_INTENDED

        DEPENDS
        intrinsics_gen # via llvm-min-tablegen
)
