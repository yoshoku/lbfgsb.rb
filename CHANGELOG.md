## 0.3.0
- Add library name prefix to functions derived from blas and linpack
to avoid errors due to collision with the blas functions called by numo-linalg.

## 0.2.0
- Add an option to minimize method for calculating both function value and gradient vector using fnc.
If true is given to jcb, fnc is assumed to return the function value and gardient vector as [f, g] array.

## 0.1.0
- First release.
