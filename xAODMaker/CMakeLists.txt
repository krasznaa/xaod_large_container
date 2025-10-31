# Copyright (C) 2002-2025 CERN for the benefit of the ATLAS collaboration

# Set the name of the package.
atlas_subdir(xAODMaker)

# Component(s) in the package.
atlas_add_component(xAODMaker
   src/*.h src/*.cxx
   LINK_LIBRARIES GaudiKernel AthenaBaseComps StoreGateLib xAODInDetMeasurement)

# Install files from the package.
atlas_install_python_modules(python/*.py)
