import FWCore.ParameterSet.Config as cms

#
# Geometry master configuration
#
# Ideal geometry, needed for simulation
from GeometryReaders.XMLIdealGeometryESSource.cmsGeometryDB_cff import *
from Geometry.MuonNumbering.muonNumberingInitialization_cfi import *
from Geometry.TrackerNumberingBuilder.trackerNumberingGeometryDB_cfi import *
from Geometry.EcalCommonData.ecalSimulationParameters_cff   import *
from Geometry.HcalCommonData.hcalSimDBConstants_cff         import *
from Geometry.MuonNumbering.muonGeometryConstants_cff       import *
from Geometry.MuonNumbering.muonOffsetESProducer_cff        import *
