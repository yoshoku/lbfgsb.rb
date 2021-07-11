## 0.4.1
- Remove dependent gem's type declaration file from installation files.

## 0.4.0
- Add type declaration file: sig/lbfgsb.rbs

## 0.3.2
- Refactor native extension codes.
- Update documentations.

## 0.3.1
- Add GC guard to narray given to native extension method.

## 0.3.0
- Add library name prefix to functions derived from blas and linpack
to avoid errors due to collision with the blas functions called by numo-linalg.

## 0.2.0
- Add an option to minimize method for calculating both function value and gradient vector using fnc.
If true is given to jcb, fnc is assumed to return the function value and gardient vector as [f, g] array.

## 0.1.0
- First release.
