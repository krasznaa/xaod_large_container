// Copyright (C) 2002-2025 CERN for the benefit of the ATLAS collaboration
#ifndef XAODMAKER_PIXELCLUSTERMAKERULTIMATEALG_H
#define XAODMAKER_PIXELCLUSTERMAKERULTIMATEALG_H

// Framework include(s).
#include "AthenaBaseComps/AthReentrantAlgorithm.h"
#include "Gaudi/Property.h"
#include "StoreGate/WriteHandleKey.h"

// EDM include(s).
#include "xAODInDetMeasurement/PixelClusterContainer.h"

namespace xAODMaker {

/// Algorithm creating xAOD::PixelClusterContainer in "the ultimate way"
class PixelClusterMakerUltimateAlg : public AthReentrantAlgorithm {

  public:
    /// Inherit the base class's constructor(s).
    using AthReentrantAlgorithm::AthReentrantAlgorithm;

    /// Function initialising the algorithm
    virtual StatusCode initialize() override;

    /// Function executing the algorithm
    virtual StatusCode execute(const EventContext &ctx) const override;

  private:
    /// @name Algorithm properties
    /// @{

    /// Output xAOD PixelCluster container
    SG::WriteHandleKey<xAOD::PixelClusterContainer> m_outputKey{
        this, "Output", "UltimatePixelClusters",
        "Name of the output xAOD::PixelClusterContainer"};

    /// The number of clusters to create
    Gaudi::Property<unsigned int> m_elements{this, "Elements", 200000,
                                             "Number of clusters to create"};

    /// @}

}; // class PixelClusterMakerUltimateAlg

} // namespace xAODMaker

#endif // XAODMAKER_PIXELCLUSTERMAKERULTIMATEALG_H
