######################################################################
# CMakeLists.txt generated for component goldCodeAnalysis
# Product type: executable
######################################################################
cmake_minimum_required(VERSION 3.12)
project(goldCodeAnalysis)

######################################################################
## Path variables
######################################################################
get_filename_component(START_DIR .. ABSOLUTE)
set(MATLAB_ROOT C:/Program\ Files/MATLAB/R2021b CACHE PATH "Root of MATLAB installation")

######################################################################
## Target definition and commands
######################################################################
add_executable(goldCodeAnalysis  ${START_DIR}/goldCodeAnalysis_ert_rtw/ert_main.c ${START_DIR}/goldCodeAnalysis_ert_rtw/goldCodeAnalysis.c ${START_DIR}/goldCodeAnalysis_ert_rtw/goldCodeAnalysis_data.c)
set_target_properties(goldCodeAnalysis PROPERTIES PREFIX "" RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../$<0:>" LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../$<0:>" ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../$<0:>" POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(goldCodeAnalysis PRIVATE -DMODEL=goldCodeAnalysis -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1)
target_include_directories(goldCodeAnalysis PRIVATE ${START_DIR} ${START_DIR}/goldCodeAnalysis_ert_rtw ${MATLAB_ROOT}/extern/include ${MATLAB_ROOT}/simulink/include ${MATLAB_ROOT}/rtw/c/src ${MATLAB_ROOT}/rtw/c/src/ext_mode/common ${MATLAB_ROOT}/rtw/c/ert ${MATLAB_ROOT}/toolbox/dsp/extern/src/export/include ${MATLAB_ROOT}/toolbox/dsp/extern/src/export/include/src ${MATLAB_ROOT}/toolbox/shared/dsp/vision/matlab/include)
if(NOT MSVC)
   target_link_libraries(goldCodeAnalysis PRIVATE m)
endif()

######################################################################
## Build success message
######################################################################
add_custom_command(TARGET goldCodeAnalysis POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:goldCodeAnalysis>")

######################################################################
## Call toolchain hook function if defined
######################################################################
if(COMMAND toolchain_target_hook)
   toolchain_target_hook(goldCodeAnalysis)
endif()
