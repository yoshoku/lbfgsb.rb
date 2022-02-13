#ifndef LBFGSB_RB_COMMON_H_
#define LBFGSB_RB_COMMON_H_

#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#ifdef USE_INT64
typedef int64_t F77_int;
#define PRIdF77INT PRId64
#else
typedef int32_t F77_int;
#define PRIdF77INT PRId32
#endif

#endif /* LBFGSB_RB_COMMON_H_ */
