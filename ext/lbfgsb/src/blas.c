/**
 * L-BFGS-B is released under the “New BSD License” (aka “Modified BSD License”
 * or “3-clause license”)
 * Please read attached file License.txt
 */
#include "blas.h"

int daxpy_(long *n, double *da, double *dx, long *incx, double *dy, long *incy)
{
  long i__1;
  static long i__, m, ix, iy, mp1;

  --dy;
  --dx;

  /* constant times a vector plus a vector. */
  /* uses unrolled loops for increments equal to one. */
  /* jack dongarra, linpack, 3/11/78. */
  if (*n <= 0) {
    return 0;
  }
  if (*da == 0.) {
    return 0;
  }
  if (*incx == 1 && *incy == 1) {
    goto L20;
  }

  /* code for unequal increments or equal increments */
  /*   not equal to 1 */
  ix = 1;
  iy = 1;
  if (*incx < 0) {
    ix = (-(*n) + 1) * *incx + 1;
  }
  if (*incy < 0) {
    iy = (-(*n) + 1) * *incy + 1;
  }
  i__1 = *n;
  for (i__ = 1; i__ <= i__1; ++i__) {
    dy[iy] += *da * dx[ix];
    ix += *incx;
    iy += *incy;
  }
  return 0;

  /* code for both increments equal to 1 */
  /* clean-up loop */
L20:
  m = *n % 4;
  if (m == 0) {
    goto L40;
  }
  i__1 = m;
  for (i__ = 1; i__ <= i__1; ++i__) {
    dy[i__] += *da * dx[i__];
  }
  if (*n < 4) {
    return 0;
  }
L40:
  mp1 = m + 1;
  i__1 = *n;
  for (i__ = mp1; i__ <= i__1; i__ += 4) {
    dy[i__] += *da * dx[i__];
    dy[i__ + 1] += *da * dx[i__ + 1];
    dy[i__ + 2] += *da * dx[i__ + 2];
    dy[i__ + 3] += *da * dx[i__ + 3];
  }
  return 0;
}

int dcopy_(long *n, double *dx, long *incx, double *dy, long *incy)
{
  long i__1;
  static long i__, m, ix, iy, mp1;

  --dy;
  --dx;

  /* copies a vector, x, to a vector, y. */
  /* uses unrolled loops for increments equal to one. */
  /* jack dongarra, linpack, 3/11/78. */
  if (*n <= 0) {
    return 0;
  }
  if (*incx == 1 && *incy == 1) {
    goto L20;
  }

  /* code for unequal increments or equal increments */
  /*   not equal to 1 */
  ix = 1;
  iy = 1;
  if (*incx < 0) {
    ix = (-(*n) + 1) * *incx + 1;
  }
  if (*incy < 0) {
    iy = (-(*n) + 1) * *incy + 1;
  }
  i__1 = *n;
  for (i__ = 1; i__ <= i__1; ++i__) {
    dy[iy] = dx[ix];
    ix += *incx;
    iy += *incy;
  }
  return 0;

  /* code for both increments equal to 1 */
  /* clean-up loop */
L20:
  m = *n % 7;
  if (m == 0) {
    goto L40;
  }
  i__1 = m;
  for (i__ = 1; i__ <= i__1; ++i__) {
    dy[i__] = dx[i__];
  }
  if (*n < 7) {
    return 0;
  }
L40:
  mp1 = m + 1;
  i__1 = *n;
  for (i__ = mp1; i__ <= i__1; i__ += 7) {
    dy[i__] = dx[i__];
    dy[i__ + 1] = dx[i__ + 1];
    dy[i__ + 2] = dx[i__ + 2];
    dy[i__ + 3] = dx[i__ + 3];
    dy[i__ + 4] = dx[i__ + 4];
    dy[i__ + 5] = dx[i__ + 5];
    dy[i__ + 6] = dx[i__ + 6];
  }
  return 0;
}

double ddot_(long *n, double *dx, long *incx, double *dy, long *incy)
{
  long i__1;
  double ret_val;
  static long i__, m, ix, iy, mp1;
  static double dtemp;

  --dy;
  --dx;

  /* forms the dot product of two vectors. */
  /* uses unrolled loops for increments equal to one. */
  /* jack dongarra, linpack, 3/11/78. */
  ret_val = 0.;
  dtemp = 0.;
  if (*n <= 0) {
    return ret_val;
  }
  if (*incx == 1 && *incy == 1) {
    goto L20;
  }

  /* code for unequal increments or equal increments */
  /*   not equal to 1 */
  ix = 1;
  iy = 1;
  if (*incx < 0) {
    ix = (-(*n) + 1) * *incx + 1;
  }
  if (*incy < 0) {
    iy = (-(*n) + 1) * *incy + 1;
  }
  i__1 = *n;
  for (i__ = 1; i__ <= i__1; ++i__) {
    dtemp += dx[ix] * dy[iy];
    ix += *incx;
    iy += *incy;
  }
  ret_val = dtemp;
  return ret_val;

  /* code for both increments equal to 1 */
  /* clean-up loop */
L20:
  m = *n % 5;
  if (m == 0) {
    goto L40;
  }
  i__1 = m;
  for (i__ = 1; i__ <= i__1; ++i__) {
    dtemp += dx[i__] * dy[i__];
  }
  if (*n < 5) {
    goto L60;
  }
L40:
  mp1 = m + 1;
  i__1 = *n;
  for (i__ = mp1; i__ <= i__1; i__ += 5) {
    dtemp = dtemp + dx[i__] * dy[i__] + dx[i__ + 1] * dy[i__ + 1]
      + dx[i__ + 2] * dy[i__ + 2] + dx[i__ + 3] * dy[i__ + 3] + dx[i__ + 4] * dy[i__ + 4];
  }
L60:
  ret_val = dtemp;
  return ret_val;
}

int dscal_(long *n, double *da, double *dx, long *incx)
{
  long i__1, i__2;
  static long i__, m, mp1, nincx;

  --dx;

  /* scales a vector by a constant. */
  /* uses unrolled loops for increment equal to one. */
  /* jack dongarra, linpack, 3/11/78. */
  /* modified 3/93 to return if incx .le. 0. */
  if (*n <= 0 || *incx <= 0) {
    return 0;
  }
  if (*incx == 1) {
    goto L20;
  }

  /* code for increment not equal to 1 */
  nincx = *n * *incx;
  i__1 = nincx;
  i__2 = *incx;
  for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
    dx[i__] = *da * dx[i__];
  }
  return 0;

  /* code for increment equal to 1 */
  /* clean-up loop */
L20:
  m = *n % 5;
  if (m == 0) {
    goto L40;
  }
  i__2 = m;
  for (i__ = 1; i__ <= i__2; ++i__) {
    dx[i__] = *da * dx[i__];
  }
  if (*n < 5) {
    return 0;
  }
L40:
  mp1 = m + 1;
  i__2 = *n;
  for (i__ = mp1; i__ <= i__2; i__ += 5) {
    dx[i__] = *da * dx[i__];
    dx[i__ + 1] = *da * dx[i__ + 1];
    dx[i__ + 2] = *da * dx[i__ + 2];
    dx[i__ + 3] = *da * dx[i__ + 3];
    dx[i__ + 4] = *da * dx[i__ + 4];
  }
  return 0;
}
