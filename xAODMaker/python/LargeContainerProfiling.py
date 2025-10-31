# Copyright (C) 2002-2025 CERN for the benefit of the ATLAS collaboration

# Core import(s).
from AthenaConfiguration.AllConfigFlags import initConfigFlags
from AthenaConfiguration.ComponentFactory import CompFactory
from AthenaConfiguration.MainServicesConfig import MainServicesCfg

# PerfMon import(s).
from PerfMonComps.PerfMonCompsConfig import PerfMonMTSvcCfg

# Set up the job's flags.
flags = initConfigFlags()
flags.Exec.MaxEvents = 100
flags.Exec.EventPrintoutInterval = 50
flags.PerfMon.doFastMonMT = True
flags.PerfMon.doFullMonMT = True
flags.fillFromArgs()
flags.lock()

# Set up the main services.
acc = MainServicesCfg(flags)
acc.merge(PerfMonMTSvcCfg(flags))

# Add the test algorithm(s) to the job.
acc.addEventAlgo(CompFactory.xAODMaker.PixelClusterMakerSimpleAlg('SimpleAlg'))

# Run the job.
acc.run()
