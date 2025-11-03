// Copyright (C) 2002-2025 CERN for the benefit of the ATLAS collaboration

// Local include(s).
#include "PixelClusterMakerUltimateAlg.h"

// Framework include(s).
#include "AthAllocators/DataPool.h"
#include "StoreGate/WriteHandle.h"

// EDM include(s).
#include "xAODInDetMeasurement/PixelClusterAuxContainer.h"

// System include(s).
#include <memory>

// Declare the algorithm.
DECLARE_COMPONENT(xAODMaker::PixelClusterMakerUltimateAlg)

namespace xAODMaker {

StatusCode PixelClusterMakerUltimateAlg::initialize() {

    ATH_CHECK(m_outputKey.initialize());
    return StatusCode::SUCCESS;
}

StatusCode
PixelClusterMakerUltimateAlg::execute(const EventContext &ctx) const {

    // Create the WriteHandle for the output container.
    auto writeHandle = SG::makeHandle(m_outputKey, ctx);

    // Access the data pool that manages the interface objects.
    DataPool<xAOD::PixelCluster> interfaceItems{ctx};
    interfaceItems.reserve(m_elements);

    // Create the output container(s).
    auto container = std::make_unique<xAOD::PixelClusterContainer>(
        SG::VIEW_ELEMENTS, SG::ALWAYS_TRACK_INDICES);
    auto store = std::make_unique<xAOD::PixelClusterAuxContainer>();

    // Fill the interface container with clusters, making use of the data pool.
    for (unsigned int i = 0; i < m_elements; ++i) {
        container->push_back(interfaceItems.nextElementPtr());
    }

    // Set the auxiliary container to the correct size, and connect it to the
    // interface container.
    store->resize(m_elements);
    container->setStore(store.get());

    // Record the container in StoreGate.
    ATH_CHECK(writeHandle.record(std::move(container), std::move(store)));

    // Return gracefully.
    return StatusCode::SUCCESS;
}

} // namespace xAODMaker
