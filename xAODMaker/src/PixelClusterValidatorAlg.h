// Copyright (C) 2002-2025 CERN for the benefit of the ATLAS collaboration
#ifndef XAODMAKER_PIXELCLUSTERVALIDATORALG_H
#define XAODMAKER_PIXELCLUSTERVALIDATORALG_H

// Framework include(s).
#include "AthenaBaseComps/AthReentrantAlgorithm.h"
#include "StoreGate/ReadHandleKey.h"

// EDM include(s).
#include "xAODInDetMeasurement/PixelClusterContainer.h"

namespace xAODMaker {

/// Algorithm "validating" an existing @c xAOD::PixelClusterContainer
class PixelClusterValidatorAlg : public AthReentrantAlgorithm {

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

    /// Input xAOD PixelCluster container
    SG::ReadHandleKey<xAOD::PixelClusterContainer> m_inputKey{
        this, "Input", "PixelClusters",
        "Name of the input xAOD::PixelClusterContainer"};

    /// @}

}; // class PixelClusterValidatorAlg

} // namespace xAODMaker

#endif // XAODMAKER_PIXELCLUSTERVALIDATORALG_H
