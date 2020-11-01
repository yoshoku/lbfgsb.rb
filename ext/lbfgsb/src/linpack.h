#ifndef LBFGSB_RB_LINPACK_H_
#define LBFGSB_RB_LINPACK_H_

#include <math.h>

extern int dpofa_(double *a, long *lda, long *n, long *info);
extern int dtrsl_(double *t, long *ldt, long *n, double *b, long *job, long *info);

#endif /* LBFGSB_RB_LINPACK_H_ */
