# llvm/utils/TableGen/CMakeLists.txt
# llvm/tools/llvm-tblgen/llvm-tblgen.cpp
# /root/llvm/build/22.1.0/bin

set(LLVM_LINK_COMPONENTS Support)

add_tablegen(llvm-sbt-tblgen LLVM
  DESTINATION "${LLVM_TOOLS_INSTALL_DIR}"
  EXPORT LLVM

  X86Emitter.cpp
  RISCVEmitter.cpp
  llvm-sbt-tblgen.cpp

  $<TARGET_OBJECTS:obj.LLVMTableGenBasic>
  $<TARGET_OBJECTS:obj.LLVMTableGenCommon>

  PARTIAL_SOURCES_INTENDED

  DEPENDS
  intrinsics_gen # via llvm-min-tablegen
)

# not used
function(sbt_tblgen project ofn)
  set(LLVM_TABLEGEN_EXE $<TARGET_FILE:llvm-sbt-tblgen>)
  add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${ofn} ${EXTRA_OUTPUTS}
    COMMAND ${tablegen_exe} ${ARG_UNPARSED_ARGUMENTS}
    ${tblgen_includes}
    ${LLVM_TABLEGEN_FLAGS}
    ${LLVM_TARGET_DEFINITIONS_ABSOLUTE}
    ${tblgen_change_flag}
    ${additional_cmdline}
    DEPENDS ${ARG_DEPENDS} ${tablegen_depends}
    ${global_tds}
    ${LLVM_TARGET_DEFINITIONS_ABSOLUTE}
    ${LLVM_TARGET_DEPENDS}
    ${LLVM_TABLEGEN_JOB_POOL}
    COMMENT "Building ${ofn}..."
  )
endfunction()