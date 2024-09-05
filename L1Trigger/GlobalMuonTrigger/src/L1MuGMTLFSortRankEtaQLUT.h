//-------------------------------------------------
//
/** \class L1MuGMTLFSortRankEtaQLUT
 *
 *   LFSortRankEtaQ look-up table
 *          
 *   this class was automatically generated by 
 *     L1MuGMTLUT::MakeSubClass()  
*/
//
//   Author :
//   H. Sakulin            HEPHY Vienna
//
//   Migrated to CMSSW:
//   I. Mikulec
//
//--------------------------------------------------
#ifndef L1TriggerGlobalMuonTrigger_L1MuGMTLFSortRankEtaQLUT_h
#define L1TriggerGlobalMuonTrigger_L1MuGMTLFSortRankEtaQLUT_h

//---------------
// C++ Headers --
//---------------

//----------------------
// Base Class Headers --
//----------------------
#include "L1Trigger/GlobalMuonTrigger/src/L1MuGMTLUT.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//              ---------------------
//              -- Class Interface --
//              ---------------------

class L1MuGMTLFSortRankEtaQLUT : public L1MuGMTLUT {
public:
  enum { DT, BRPC, CSC, FRPC };

  /// constuctor using function-lookup
  L1MuGMTLFSortRankEtaQLUT()
      : L1MuGMTLUT("LFSortRankEtaQ", "DT BRPC CSC FRPC", "eta(6) q(3)", "vlq(2) rank_etaq(2)", 7, false) {
    InitParameters();
  };

  /// destructor
  ~L1MuGMTLFSortRankEtaQLUT() override {}

  /// specific lookup function for vlq
  unsigned SpecificLookup_vlq(int idx, unsigned eta, unsigned q) const {
    std::vector<unsigned> addr(2);
    addr[0] = eta;
    addr[1] = q;
    return Lookup(idx, addr)[0];
  };

  /// specific lookup function for rank_etaq
  unsigned SpecificLookup_rank_etaq(int idx, unsigned eta, unsigned q) const {
    std::vector<unsigned> addr(2);
    addr[0] = eta;
    addr[1] = q;
    return Lookup(idx, addr)[1];
  };

  /// specific lookup function for entire output field
  unsigned SpecificLookup(int idx, unsigned eta, unsigned q) const {
    std::vector<unsigned> addr(2);
    addr[0] = eta;
    addr[1] = q;
    return LookupPacked(idx, addr);
  };

  /// access to lookup function with packed input and output

  unsigned LookupFunctionPacked(int idx, unsigned address) const override {
    std::vector<unsigned> addr = u2vec(address, m_Inputs);
    return TheLookupFunction(idx, addr[0], addr[1]);
  };

private:
  /// Initialize scales, configuration parameters, alignment constants, ...
  void InitParameters();

  /// The lookup function - here the functionality of the LUT is implemented
  unsigned TheLookupFunction(int idx, unsigned eta, unsigned q) const;

  /// Private data members (LUT parameters);
  unsigned m_version;
};
#endif
