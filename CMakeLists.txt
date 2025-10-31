# Copyright (C) 2002-2025 CERN for the benefit of the ATLAS collaboration

# Set up the project.
cmake_minimum_required(VERSION 3.25)
project(xAODLargeContainer VERSION 0.1.0 LANGUAGES CXX)

# Find Athena.
find_package(Athena REQUIRED)

# Set up CTest.
atlas_ctest_setup()

# Set up the ATLAS project.
atlas_project(USE Athena ${Athena_VERSION})

# Set up the runtime environment setup script(s).
lcg_generate_env( SH_FILE ${CMAKE_BINARY_DIR}/${ATLAS_PLATFORM}/env_setup.sh )
install( FILES ${CMAKE_BINARY_DIR}/${ATLAS_PLATFORM}/env_setup.sh
   DESTINATION . )

# Set up CPack.
atlas_cpack_setup()
