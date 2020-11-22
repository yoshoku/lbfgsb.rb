#ifndef LBFGSB_RB_BLAS_H_
#define LBFGSB_RB_BLAS_H_

#include <math.h>

extern int daxpy_(long *n, double *da, double *dx, long *incx, double *dy, long *incy);
extern int dcopy_(long *n, double *dx, long *incx, double *dy, long *incy);
extern double ddot_(long *n, double *dx, long *incx, double *dy, long *incy);
extern int dscal_(long *n, double *da, double *dx, long *incx);

#endif /* LBFGSB_RB_BLAS_H_ */
