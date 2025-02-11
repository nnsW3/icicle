#include <cuda_runtime.h>
#include <stdbool.h>

#ifndef _GRUMPKIN_POSEIDON_H
#define _GRUMPKIN_POSEIDON_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct scalar_t scalar_t;
typedef struct DeviceContext DeviceContext;
typedef struct TreeBuilderConfig TreeBuilderConfig;
typedef struct PoseidonInst PoseidonInst;
typedef struct HashConfig HashConfig;


cudaError_t grumpkin_poseidon_create_cuda(
  PoseidonInst** poseidon,
  unsigned int arity,
  unsigned int alpha,
  unsigned int partial_rounds,
  unsigned int full_rounds_half,
  const scalar_t* round_constants,
  const scalar_t* mds_matrix,
  const scalar_t* non_sparse_matrix,
  const scalar_t* sparse_matrices,
  const scalar_t* domain_tag,
  DeviceContext* ctx);

cudaError_t grumpkin_poseidon_load_cuda(
  PoseidonInst** poseidon,
  unsigned int arity,
  DeviceContext* ctx);

cudaError_t grumpkin_poseidon_hash_many_cuda(
  const PoseidonInst* poseidon,
  const scalar_t* inputs,
  scalar_t* output,
  unsigned int number_of_states,
  unsigned int input_block_len,
  unsigned int output_len,
  HashConfig* cfg);

cudaError_t grumpkin_poseidon_delete_cuda(PoseidonInst* poseidon);

#ifdef __cplusplus
}
#endif

#endif