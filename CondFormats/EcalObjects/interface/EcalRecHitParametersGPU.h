#ifndef CondFormats_EcalObjects_interface_EcalRecHitParametersGPU_h
#define CondFormats_EcalObjects_interface_EcalRecHitParametersGPU_h

#include <array>

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/propagate_const_array.h"
#include "HeterogeneousCore/CUDAUtilities/interface/device_unique_ptr.h"

#ifndef __CUDACC__
#include "HeterogeneousCore/CUDAUtilities/interface/HostAllocator.h"
#include "HeterogeneousCore/CUDACore/interface/ESProduct.h"
#endif  // __CUDACC__

class EcalRecHitParametersGPU {
public:
  struct Product {
    edm::propagate_const_array<cms::cuda::device::unique_ptr<int[]>> ChannelStatusToBeExcluded;
    edm::propagate_const_array<cms::cuda::device::unique_ptr<int[]>> expanded_v_DB_reco_flags;
    edm::propagate_const_array<cms::cuda::device::unique_ptr<uint32_t[]>> expanded_Sizes_v_DB_reco_flags;
    edm::propagate_const_array<cms::cuda::device::unique_ptr<uint32_t[]>> expanded_flagbit_v_DB_reco_flags;
  };

#ifndef __CUDACC__
  EcalRecHitParametersGPU(edm::ParameterSet const &);

  ~EcalRecHitParametersGPU() = default;

  Product const &getProduct(cudaStream_t) const;

  using intvec = std::reference_wrapper<std::vector<int, cms::cuda::HostAllocator<int>> const>;
  using uint32vec = std::reference_wrapper<std::vector<uint32_t, cms::cuda::HostAllocator<uint32_t>> const>;
  std::tuple<intvec, intvec, uint32vec, uint32vec> getValues() const {
    return {ChannelStatusToBeExcluded_,
            expanded_v_DB_reco_flags_,
            expanded_Sizes_v_DB_reco_flags_,
            expanded_flagbit_v_DB_reco_flags_};
  }

private:
  std::vector<int, cms::cuda::HostAllocator<int>> ChannelStatusToBeExcluded_;
  std::vector<int, cms::cuda::HostAllocator<int>> expanded_v_DB_reco_flags_;
  std::vector<uint32_t, cms::cuda::HostAllocator<uint32_t>> expanded_Sizes_v_DB_reco_flags_,
      expanded_flagbit_v_DB_reco_flags_;

  cms::cuda::ESProduct<Product> product_;
#endif  // __CUDACC__
};

#endif  // CondFormats_EcalObjects_interface_EcalRecHitParametersGPU_h
