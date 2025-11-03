// Copyright (C) 2002-2025 CERN for the benefit of the ATLAS collaboration

// Local include(s).
#include "PixelClusterValidatorAlg.h"

// Framework include(s).
#include "StoreGate/ReadHandle.h"

// Declare the algorithm.
DECLARE_COMPONENT(xAODMaker::PixelClusterValidatorAlg)

namespace xAODMaker {

StatusCode PixelClusterValidatorAlg::initialize() {

    ATH_CHECK(m_inputKey.initialize());
    return StatusCode::SUCCESS;
}

StatusCode PixelClusterValidatorAlg::execute(const EventContext &ctx) const {

    // Create the ReadHandle for the input container.
    auto readHandle = SG::makeHandle(m_inputKey, ctx);

    // Access some simple properties of all objects.
    float totalWidth = 0.f;
    for (const xAOD::PixelCluster *cluster : *readHandle) {
        totalWidth += cluster->widthInEta();
    }
    ATH_MSG_DEBUG("Total width in eta of all clusters: " << totalWidth);

    // Return gracefully.
    return StatusCode::SUCCESS;
}

} // namespace xAODMaker
