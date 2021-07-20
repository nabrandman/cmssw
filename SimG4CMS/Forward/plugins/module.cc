#include "SimG4CMS/Forward/interface/TotemTestGem.h"
#include "SimG4CMS/Forward/interface/CastorTestAnalysis.h"
#include "SimG4CMS/Forward/interface/ZdcTestAnalysis.h"
#include "SimG4CMS/Forward/interface/DoCastorAnalysis.h"
#include "SimG4CMS/Forward/interface/PltSD.h"
#include "SimG4CMS/Forward/interface/MtdSD.h"
#include "SimG4CMS/Forward/interface/TotemT2ScintSD.h"

#include "SimG4CMS/Forward/interface/BscTest.h"
#include "SimG4CMS/Forward/interface/BscSD.h"
#include "SimG4CMS/Forward/interface/BHMSD.h"
#include "SimG4CMS/Forward/interface/Bcm1fSD.h"

#include "SimG4CMS/Forward/plugins/SimG4FluxProducer.h"

#include "SimG4Core/SensitiveDetector/interface/SensitiveDetectorPluginFactory.h"
#include "SimG4Core/Watcher/interface/SimWatcherFactory.h"
#include "FWCore/PluginManager/interface/ModuleDef.h"

typedef BscSD BSCSensitiveDetector;
DEFINE_SENSITIVEDETECTOR(BSCSensitiveDetector);
typedef BHMSD BHMSensitiveDetector;
DEFINE_SENSITIVEDETECTOR(BHMSensitiveDetector);
typedef MtdSD MtdSensitiveDetector;
DEFINE_SENSITIVEDETECTOR(MtdSensitiveDetector);
typedef PltSD PLTSensitiveDetector;
DEFINE_SENSITIVEDETECTOR(PLTSensitiveDetector);
typedef Bcm1fSD BCM1FSensitiveDetector;
DEFINE_SENSITIVEDETECTOR(BCM1FSensitiveDetector);
typedef TotemT2ScintSD TotemT2ScintSensitiveDetector;
DEFINE_SENSITIVEDETECTOR(TotemT2ScintSensitiveDetector);
DEFINE_SIMWATCHER(CastorTestAnalysis);
DEFINE_SIMWATCHER(ZdcTestAnalysis);
DEFINE_SIMWATCHER(DoCastorAnalysis);
DEFINE_SIMWATCHER(TotemTestGem);
DEFINE_SIMWATCHER(BscTest);
DEFINE_SIMWATCHER(SimG4FluxProducer);
