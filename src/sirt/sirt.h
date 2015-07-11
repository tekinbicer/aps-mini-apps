#ifndef DISP_APPS_RECONSTRUCTION_SIRT_SIRT_H
#define DISP_APPS_RECONSTRUCTION_SIRT_SIRT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <chrono>
#include "hdf5.h"
#include "string.h"
#include "trace_data.h"
#include "trace_utils.h"
#include "reduction_space_a.h"
#include "data_region_base.h"

class SIRTReconSpace : 
  public AReductionSpaceBase<SIRTReconSpace, float>
{
  private:
    float *coordx = nullptr;
    float *coordy = nullptr;
    float *ax = nullptr;
    float *ay = nullptr;
    float *bx = nullptr;
    float *by = nullptr;
    float *coorx = nullptr;
    float *coory = nullptr;
    float *leng = nullptr;
    float *leng2 = nullptr;
    int *indi = nullptr;

    int num_grids;

    /* Profiler variables */
    std::chrono::time_point<std::chrono::system_clock> 
      start, end, start_all, end_all,
      start_replica, end_replica;
    std::chrono::duration<double> 
      timer_coordinates, timer_sort_int,
      timer_dist, timer_simdata, timer_update_replica,
      timer_update_replica_loop1, timer_update_replica_loop2,
      timer_merge_trim, timer_all;

  protected:
    // Forward projection
    float CalculateSimdata(
        float *recon,
        int len,
        int *indi,
        float *leng);

    void UpdateReconReplica(
        float simdata,
        float ray,
        int curr_slice,
        int const * const indi,
        float *leng2,
        float *leng, 
        int len,
        int suma_beg_offset);

  public:
    SIRTReconSpace(int rows, int cols) : 
      AReductionSpaceBase(rows, cols) {}

    virtual ~SIRTReconSpace(){
      PrintProfileInfo();
      Finalize();
    }

    void Reduce(MirroredRegionBareBase<float> &input);
    // Backward Projection
    void UpdateRecon(
        ADataRegion<float> &recon,                  // Reconstruction object
        DataRegion2DBareBase<float> &comb_replica); // Locally combined replica


    void Initialize(int n_grids);
    virtual void CopyTo(SIRTReconSpace &target){
      target.Initialize(num_grids);
    }
    void Finalize();
    /* Execution Profiler */
    void PrintProfileInfo();
};

#endif    // DISP_APPS_RECONSTRUCTION_SIRT_SIRT_H
