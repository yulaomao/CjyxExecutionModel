#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.13.4...3.14.2)
cmake_policy(VERSION 3.13.4...3.14.2)
include(${CMAKE_CURRENT_SOURCE_DIR}/../CMake/GenerateCLPTestMacros.cmake)

#-----------------------------------------------------------------------------
# Configure & Build
#-----------------------------------------------------------------------------
GenerateCLP_TEST_PROJECT(
  NAME Cjyx3Example
)

#-----------------------------------------------------------------------------
# Test
#-----------------------------------------------------------------------------
add_test(NAME CjyxCLPExample1 COMMAND $<TARGET_FILE:${PROJECT_NAME}> --help)
add_test(NAME CjyxCLPExample2 COMMAND $<TARGET_FILE:${PROJECT_NAME}> --echo --load_freesurfer_volume FSV --stereo)
add_test(NAME CjyxCLPExample3 COMMAND $<TARGET_FILE:${PROJECT_NAME}>)
