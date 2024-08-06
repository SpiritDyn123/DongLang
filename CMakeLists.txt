cmake_minimum_required(VERSION 3.22)  
project(DongLang VERSION 1.0)  

set(CMAKE_CXX_STANDARD 17)  

include(ProcessorCount)
ProcessorCount(PROCESSOR_COUNT)
message(STATUS "processor_cnt:${PROCESSOR_COUNT}")

set(CMAKE_BUILD_PARALLEL_LEVEL ${PROCESSOR_COUNT})

#可能不起作用

set(CMAKE_CXX_COMPILER clang++)

# 调试信息
set(CMAKE_CXX_FLAGS "-g")

#include
include_directories(
	. 
	/data/app/llvm/include
	/data/app/antlr4-runtime/cpp/include/antlr4-runtime) 

#libraries path
link_directories(
	/data/app/llvm/lib/
	/data/app/antlr4-runtime/cpp/lib/
)

# app cpp files
file(GLOB_RECURSE SRC_FILES 
	${PROJECT_SOURCE_DIR}/font/*.cpp
	${PROJECT_SOURCE_DIR}/src/*.cpp
    #${PROJECT_SOURCE_DIR}/font/**/*.cpp # 从src目录及其子目录中查找  
)  

message(STATUS "SRC_FILES:${PROJECT_SOURCE_DIR} ${SRC_FILES}")

add_executable(DongLang main.cpp ${SRC_FILES})

# link libraries
if(1)
	target_link_libraries(DongLang
		LLVMWindowsManifest 
		LLVMXRay 
		LLVMLibDriver 
		LLVMDlltoolDriver 
		LLVMCoverage 
		LLVMLineEditor 
		LLVMXCoreDisassembler 
		LLVMXCoreCodeGen 
		LLVMXCoreDesc 
		LLVMXCoreInfo 
		LLVMX86TargetMCA 
		LLVMX86Disassembler 
		LLVMX86AsmParser 
		LLVMX86CodeGen 
		LLVMX86Desc 
		LLVMX86Info 
		LLVMWebAssemblyDisassembler 
		LLVMWebAssemblyAsmParser 
		LLVMWebAssemblyCodeGen 
		LLVMWebAssemblyDesc 
		LLVMWebAssemblyUtils 
		LLVMWebAssemblyInfo 
		LLVMVEDisassembler 
		LLVMVEAsmParser 
		LLVMVECodeGen 
		LLVMVEDesc 
		LLVMVEInfo 
		LLVMSystemZDisassembler 
		LLVMSystemZAsmParser 
		LLVMSystemZCodeGen 
		LLVMSystemZDesc 
		LLVMSystemZInfo 
		LLVMSparcDisassembler 
		LLVMSparcAsmParser 
		LLVMSparcCodeGen 
		LLVMSparcDesc 
		LLVMSparcInfo 
		LLVMRISCVTargetMCA 
		LLVMRISCVDisassembler 
		LLVMRISCVAsmParser 
		LLVMRISCVCodeGen 
		LLVMRISCVDesc 
		LLVMRISCVInfo 
		LLVMPowerPCDisassembler 
		LLVMPowerPCAsmParser 
		LLVMPowerPCCodeGen 
		LLVMPowerPCDesc 
		LLVMPowerPCInfo 
		LLVMNVPTXCodeGen 
		LLVMNVPTXDesc 
		LLVMNVPTXInfo 
		LLVMMSP430Disassembler 
		LLVMMSP430AsmParser 
		LLVMMSP430CodeGen 
		LLVMMSP430Desc 
		LLVMMSP430Info 
		LLVMMipsDisassembler 
		LLVMMipsAsmParser 
		LLVMMipsCodeGen 
		LLVMMipsDesc 
		LLVMMipsInfo 
		LLVMLoongArchDisassembler 
		LLVMLoongArchAsmParser 
		LLVMLoongArchCodeGen 
		LLVMLoongArchDesc 
		LLVMLoongArchInfo 
		LLVMLanaiDisassembler 
		LLVMLanaiCodeGen 
		LLVMLanaiAsmParser 
		LLVMLanaiDesc 
		LLVMLanaiInfo 
		LLVMHexagonDisassembler 
		LLVMHexagonCodeGen 
		LLVMHexagonAsmParser 
		LLVMHexagonDesc 
		LLVMHexagonInfo 
		LLVMBPFDisassembler 
		LLVMBPFAsmParser 
		LLVMBPFCodeGen 
		LLVMBPFDesc 
		LLVMBPFInfo 
		LLVMAVRDisassembler 
		LLVMAVRAsmParser 
		LLVMAVRCodeGen 
		LLVMAVRDesc 
		LLVMAVRInfo 
		LLVMARMDisassembler 
		LLVMARMAsmParser 
		LLVMARMCodeGen 
		LLVMARMDesc 
		LLVMARMUtils 
		LLVMARMInfo 
		LLVMAMDGPUTargetMCA 
		LLVMAMDGPUDisassembler 
		LLVMAMDGPUAsmParser 
		LLVMAMDGPUCodeGen 
		LLVMAMDGPUDesc 
		LLVMAMDGPUUtils 
		LLVMAMDGPUInfo 
		LLVMAArch64Disassembler 
		LLVMAArch64AsmParser 
		LLVMAArch64CodeGen 
		LLVMAArch64Desc 
		LLVMAArch64Utils 
		LLVMAArch64Info 
		LLVMOrcJIT 
		LLVMWindowsDriver 
		LLVMMCJIT 
		LLVMJITLink 
		LLVMInterpreter 
		LLVMExecutionEngine 
		LLVMRuntimeDyld 
		LLVMOrcTargetProcess 
		LLVMOrcShared 
		LLVMDWP 
		LLVMDebugInfoLogicalView 
		LLVMDebugInfoGSYM 
		LLVMOption 
		LLVMObjectYAML 
		LLVMObjCopy 
		LLVMMCA 
		LLVMMCDisassembler 
		LLVMLTO 
		LLVMCFGuard 
		LLVMFrontendOpenACC 
		LLVMFrontendHLSL 
		LLVMExtensions 
		Polly 
		PollyISL 
		LLVMPasses 
		LLVMCoroutines 
		LLVMipo 
		LLVMInstrumentation 
		LLVMVectorize 
		LLVMLinker 
		LLVMFrontendOpenMP 
		LLVMDWARFLinkerParallel 
		LLVMDWARFLinker 
		LLVMGlobalISel 
		LLVMMIRParser 
		LLVMAsmPrinter 
		LLVMSelectionDAG 
		LLVMCodeGen 
		LLVMObjCARCOpts 
		LLVMIRPrinter 
		LLVMInterfaceStub 
		LLVMFileCheck 
		LLVMFuzzMutate 
		LLVMTarget 
		LLVMScalarOpts 
		LLVMInstCombine 
		LLVMAggressiveInstCombine 
		LLVMTransformUtils 
		LLVMBitWriter 
		LLVMAnalysis 
		LLVMProfileData 
		LLVMSymbolize 
		LLVMDebugInfoPDB 
		LLVMDebugInfoMSF 
		LLVMDebugInfoDWARF 
		LLVMObject 
		LLVMTextAPI 
		LLVMMCParser 
		LLVMIRReader 
		LLVMAsmParser 
		LLVMMC 
		LLVMDebugInfoCodeView 
		LLVMBitReader 
		LLVMFuzzerCLI 
		LLVMCore 
		LLVMRemarks 
		LLVMBitstreamReader 
		LLVMBinaryFormat 
		LLVMTargetParser 
		LLVMTableGen 
		LLVMSupport 
		LLVMDemangle

		rt
		dl
		m
		z
		zstd
		tinfo
		xml2
		antlr4-runtime
		gflags
		gmock
		gmock_main)

endif()
