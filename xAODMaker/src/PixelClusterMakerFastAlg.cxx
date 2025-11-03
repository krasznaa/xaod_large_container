// Copyright (C) 2002-2025 CERN for the benefit of the ATLAS collaboration

// Local include(s).
#include "PixelClusterMakerFastAlg.h"

// Framework include(s).
#include "StoreGate/WriteHandle.h"

// EDM include(s).
#include "xAODInDetMeasurement/PixelClusterAuxContainer.h"

// System include(s).
#include <memory>

// Declare the algorithm.
DECLARE_COMPONENT(xAODMaker::PixelClusterMakerFastAlg)

namespace xAODMaker {

StatusCode PixelClusterMakerFastAlg::initialize() {

    ATH_CHECK(m_outputKey.initialize());
    return StatusCode::SUCCESS;
}

StatusCode PixelClusterMakerFastAlg::execute(const EventContext &ctx) const {

    // Create the WriteHandle for the output container.
    auto writeHandle = SG::makeHandle(m_outputKey, ctx);

    // Create the output container(s).
    auto container = std::make_unique<xAOD::PixelClusterContainer>();
    auto store = std::make_unique<xAOD::PixelClusterAuxContainer>();
    container->setStore(store.get());

    // Fill the container with some clusters. In a relatively efficient way.
    container->push_new(m_elements, []() { return new xAOD::PixelCluster(); });

    // Record the container in StoreGate.
    ATH_CHECK(writeHandle.record(std::move(container), std::move(store)));

    // Return gracefully.
    return StatusCode::SUCCESS;
}

} // namespace xAODMaker
