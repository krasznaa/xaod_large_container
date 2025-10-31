// Copyright (C) 2002-2025 CERN for the benefit of the ATLAS collaboration

// Local include(s).
#include "PixelClusterMakerSimpleAlg.h"

// Framework include(s).
#include "StoreGate/WriteHandle.h"

// EDM include(s).
#include "xAODInDetMeasurement/PixelClusterAuxContainer.h"

// System include(s).
#include <memory>

// Declare the algorithm.
DECLARE_COMPONENT(xAODMaker::PixelClusterMakerSimpleAlg)

namespace xAODMaker {

StatusCode PixelClusterMakerSimpleAlg::initialize() {

    ATH_CHECK(m_outputKey.initialize());
    return StatusCode::SUCCESS;
}

StatusCode PixelClusterMakerSimpleAlg::execute(const EventContext &ctx) const {

    // Create the WriteHandle for the output container.
    auto writeHandle = SG::makeHandle(m_outputKey, ctx);

    // Create the output container(s).
    auto container = std::make_unique<xAOD::PixelClusterContainer>();
    auto store = std::make_unique<xAOD::PixelClusterAuxContainer>();
    container->setStore(store.get());

    // Fill the container with some clusters. In the simplest / most naive way
    // possible.
    for (unsigned int i = 0; i < m_elements; ++i) {
        container->push_back(std::make_unique<xAOD::PixelCluster>());
    }

    // Record the container in StoreGate.
    ATH_CHECK(writeHandle.record(std::move(container), std::move(store)));

    // Return gracefully.
    return StatusCode::SUCCESS;
}

} // namespace xAODMaker
