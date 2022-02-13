#ifndef LBFGSB_RB_BLAS_H_
#define LBFGSB_RB_BLAS_H_

#include "common.h"

extern void daxpy_(F77_int* n, double* da, double* dx, F77_int* incx, double* dy, F77_int* incy);
extern void dcopy_(F77_int* n, double* dx, F77_int* incx, double* dy, F77_int* incy);
extern double ddot_(F77_int* n, double* dx, F77_int* incx, double* dy, F77_int* incy);
extern void dscal_(F77_int* n, double* da, double* dx, F77_int* incx);

#endif /* LBFGSB_RB_BLAS_H_ */
