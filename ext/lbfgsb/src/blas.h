#ifndef LBFGSB_RB_BLAS_H_
#define LBFGSB_RB_BLAS_H_

#include <math.h>

extern int lbfgsb_rb_daxpy_(long *n, double *da, double *dx, long *incx, double *dy, long *incy);
extern int lbfgsb_rb_dcopy_(long *n, double *dx, long *incx, double *dy, long *incy);
extern double lbfgsb_rb_ddot_(long *n, double *dx, long *incx, double *dy, long *incy);
extern int lbfgsb_rb_dscal_(long *n, double *da, double *dx, long *incx);

#endif /* LBFGSB_RB_BLAS_H_ */
