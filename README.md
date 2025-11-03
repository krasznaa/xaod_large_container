# xAOD Large Container Creation

Demonstration of creating large xAOD containers efficiently.

The repository holds 3 algorithms that demonstrate how to create an
[xAOD::PixelClusterContainer](https://gitlab.cern.ch/atlas/athena/-/blob/main/Event/xAOD/xAODInDetMeasurement/xAODInDetMeasurement/versions/PixelClusterContainer_v1.h?ref_type=heads)
efficiently, which would have a lot of elements in it.
  - `xAODMaker::PixelClusterMakerSimpleAlg` shows the most naive way of setting
    up the container. Which is the slowest method.
  - `xAODMaker::PixelXlusterMakerFastAlg` shows a small complication over the
    "simple algorithm", which perform a lot better already, with minimal
    code complexity over the "simple algorithm".
  - `xAODMaker::PicelClusterMakerUltimateAlg` shows the "ultimate" version of
    the algorithm. Which makes use of [DataPool](https://gitlab.cern.ch/atlas/athena/-/blob/main/Control/AthAllocators/AthAllocators/DataPool.h?ref_type=heads)
    for creating the [xAOD::PixelCluster](https://gitlab.cern.ch/atlas/athena/-/blob/main/Event/xAOD/xAODInDetMeasurement/xAODInDetMeasurement/versions/PixelCluster_v1.h?ref_type=heads)
    interface objects.
    * This is the variant performing the fastest.

The repository also includes `xAODMaker::PixelClusterValidatorAlg`, which is
just used to make sure that the output of the "maker algorithms" would not be
outright garbage. Though additional checks may still be useful.

To run a test job after compiling the project on top of the latest Athena
nightly, one can run something like:

```
athena.py --CA --threads=4 xAODMaker/LargeContainerProfiling.py
```

Which will output detailed performance statistics about all the algorithms in
the job.
