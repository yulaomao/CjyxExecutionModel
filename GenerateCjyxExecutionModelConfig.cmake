# Generate the CjyxExecutionModelConfig.cmake file in the build tree
# and configure one in the installation tree.

# Settings specific to build trees
#
#

set(CjyxExecutionModel_INCLUDE_DIRS_CONFIG ${CjyxExecutionModel_INCLUDE_DIRS})

set(CjyxExecutionModel_LIBRARIES_CONFIG ModuleDescriptionParser)
if(CjyxExecutionModel_USE_JSONCPP)
  set(DEFAULT_SEM_TARGET_LIBRARIES_CONFIG ${JsonCpp_LIBRARIES})
endif()

set(CjyxExecutionModel_USE_FILE_CONFIG
  ${CjyxExecutionModel_BINARY_DIR}/UseCjyxExecutionModel.cmake)

set(CjyxExecutionModel_DEFAULT_CLI_RUNTIME_OUTPUT_DIRECTORY_CONFIG
  ${CjyxExecutionModel_DEFAULT_CLI_RUNTIME_OUTPUT_DIRECTORY}
  )
set(CjyxExecutionModel_DEFAULT_CLI_LIBRARY_OUTPUT_DIRECTORY_CONFIG
  ${CjyxExecutionModel_DEFAULT_CLI_LIBRARY_OUTPUT_DIRECTORY}
  )
set(CjyxExecutionModel_DEFAULT_CLI_ARCHIVE_OUTPUT_DIRECTORY_CONFIG
  ${CjyxExecutionModel_DEFAULT_CLI_ARCHIVE_OUTPUT_DIRECTORY}
  )

set(CjyxExecutionModel_DEFAULT_CLI_INSTALL_RUNTIME_DESTINATION_CONFIG
  ${CjyxExecutionModel_DEFAULT_CLI_INSTALL_RUNTIME_DESTINATION}
  )
set(CjyxExecutionModel_DEFAULT_CLI_INSTALL_LIBRARY_DESTINATION_CONFIG
  ${CjyxExecutionModel_DEFAULT_CLI_INSTALL_LIBRARY_DESTINATION}
  )
set(CjyxExecutionModel_DEFAULT_CLI_INSTALL_ARCHIVE_DESTINATION_CONFIG
  ${CjyxExecutionModel_DEFAULT_CLI_INSTALL_ARCHIVE_DESTINATION}
  )

set(CjyxExecutionModel_DEFAULT_CLI_TARGETS_FOLDER_PREFIX_CONFIG
  ${CjyxExecutionModel_DEFAULT_CLI_TARGETS_FOLDER_PREFIX}
  )

set(CjyxExecutionModel_LIBRARY_DIRS_CONFIG
  ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
  ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
  )

set(CjyxExecutionModel_DEFAULT_CLI_LIBRARY_WRAPPER_CXX_CONFIG
  ${CjyxExecutionModel_DEFAULT_CLI_LIBRARY_WRAPPER_CXX}
  )

# Configure CjyxExecutionModelConfig.cmake for the build tree.
#
configure_file(
  ${CjyxExecutionModel_SOURCE_DIR}/CjyxExecutionModelConfig.cmake.in
  ${CjyxExecutionModel_BINARY_DIR}/CjyxExecutionModelConfig.cmake
  @ONLY
  )

# Settings specific for installation trees
#
#

# TODO - Configure CjyxExecutionModelConfig.cmake for the install tree.
#
#configure_file(
#  ${CjyxExecutionModel_SOURCE_DIR}/CjyxExecutionModelInstallConfig.cmake.in
#  ${CjyxExecutionModel_BINARY_DIR}/install/CjyxExecutionModelConfig.cmake
#  @ONLY
#  )
