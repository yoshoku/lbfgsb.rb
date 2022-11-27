## 0.5.2
- Fix build failure with Xcode 14 and Ruby 3.1.x.

## 0.5.1
- Refactor codes and configs with RuboCop.

## 0.5.0
- Add build option to select FORTRAN integer bit size.

```
$ gem install lbfgsb -- --with-use-int64
```

- Add build option to use any blas library.

```
$ gem install lbfgsb -- --with-blas-dir=/opt/local/openblas/lib --with-blas-lib=openblas
```

- Change to use 32-bit integer for FORTRAN integer in internal functions by default.
- Introduce conventional commits.

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
