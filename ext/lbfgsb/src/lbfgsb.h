#ifndef LBFGSB_RB_LBFGSB_H_
#define LBFGSB_RB_LBFGSB_H_

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "common.h"

#define TRUE_ (1)
#define FALSE_ (0)

extern void setulb_(F77_int* n, F77_int* m, double* x, double* l, double* u, F77_int* nbd, double* f, double* g, double* factr,
                   double* pgtol, double* wa, F77_int* iwa, char* task, F77_int* iprint, char* csave, F77_int* lsave, F77_int* isave,
                   double* dsave);

extern void mainlb_(F77_int* n, F77_int* m, double* x, double* l, double* u, F77_int* nbd, double* f, double* g, double* factr,
                   double* pgtol, double* ws, double* wy, double* sy, double* ss, double* wt, double* wn, double* snd,
                   double* z__, double* r__, double* d__, double* t, double* xp, double* wa, F77_int* index, F77_int* iwhere,
                   F77_int* indx2, char* task, F77_int* iprint, char* csave, F77_int* lsave, F77_int* isave, double* dsave);

extern void active_(F77_int* n, double* l, double* u, F77_int* nbd, double* x, F77_int* iwhere, F77_int* iprint, F77_int* prjctd, F77_int* cnstnd,
                   F77_int* boxed);

extern void bmv_(F77_int* m, double* sy, double* wt, F77_int* col, double* v, double* p, F77_int* info);

extern void cauchy_(F77_int* n, double* x, double* l, double* u, F77_int* nbd, double* g, F77_int* iorder, F77_int* iwhere, double* t,
                   double* d__, double* xcp, F77_int* m, double* wy, double* ws, double* sy, double* wt, double* theta, F77_int* col,
                   F77_int* head, double* p, double* c__, double* wbp, double* v, F77_int* nseg, F77_int* iprint, double* sbgnrm,
                   F77_int* info, double* epsmch);

extern void cmprlb_(F77_int* n, F77_int* m, double* x, double* g, double* ws, double* wy, double* sy, double* wt, double* z__,
                   double* r__, double* wa, F77_int* index, double* theta, F77_int* col, F77_int* head, F77_int* nfree, F77_int* cnstnd,
                   F77_int* info);

extern void errclb_(F77_int* n, F77_int* m, double* factr, double* l, double* u, F77_int* nbd, char* task, F77_int* info, F77_int* k);

extern void formk_(F77_int* n, F77_int* nsub, F77_int* ind, F77_int* nenter, F77_int* ileave, F77_int* indx2, F77_int* iupdat, F77_int* updatd,
                  double* wn, double* wn1, F77_int* m, double* ws, double* wy, double* sy, double* theta, F77_int* col, F77_int* head,
                  F77_int* info);

extern void formt_(F77_int* m, double* wt, double* sy, double* ss, F77_int* col, double* theta, F77_int* info);

extern void freev_(F77_int* n, F77_int* nfree, F77_int* index, F77_int* nenter, F77_int* ileave, F77_int* indx2, F77_int* iwhere, F77_int* wrk,
                  F77_int* updatd, F77_int* cnstnd, F77_int* iprint, F77_int* iter);

extern void hpsolb_(F77_int* n, double* t, F77_int* iorder, F77_int* iheap);

extern void lnsrlb_(F77_int* n, double* l, double* u, F77_int* nbd, double* x, double* f, double* fold, double* gd, double* gdold,
                   double* g, double* d__, double* r__, double* t, double* z__, double* stp, double* dnorm, double* dtd,
                   double* xstep, double* stpmx, F77_int* iter, F77_int* ifun, F77_int* iback, F77_int* nfgv, F77_int* info, char* task,
                   F77_int* boxed, F77_int* cnstnd, char* csave, F77_int* isave, double* dsave);

extern void matupd_(F77_int* n, F77_int* m, double* ws, double* wy, double* sy, double* ss, double* d__, double* r__, F77_int* itail,
                   F77_int* iupdat, F77_int* col, F77_int* head, double* theta, double* rr, double* dr, double* stp, double* dtd);

extern void prn1lb_(F77_int* n, F77_int* m, double* l, double* u, double* x, F77_int* iprint, F77_int* itfile, double* epsmch);

extern void prn2lb_(F77_int* n, double* x, double* f, double* g, F77_int* iprint, F77_int* itfile, F77_int* iter, F77_int* nfgv, F77_int* nact,
                   double* sbgnrm, F77_int* nseg, char* word, F77_int* iword, F77_int* iback, double* stp, double* xstep);

extern void prn3lb_(F77_int* n, double* x, double* f, char* task, F77_int* iprint, F77_int* info, F77_int* itfile, F77_int* iter, F77_int* nfgv,
                   F77_int* nintol, F77_int* nskip, F77_int* nact, double* sbgnrm, double* time, F77_int* nseg, char* word, F77_int* iback,
                   double* stp, double* xstep, F77_int* k, double* cachyt, double* sbtime, double* lnscht);

extern void projgr_(F77_int* n, double* l, double* u, F77_int* nbd, double* x, double* g, double* sbgnrm);

extern void subsm_(F77_int* n, F77_int* m, F77_int* nsub, F77_int* ind, double* l, double* u, F77_int* nbd, double* x, double* d__, double* xp,
                  double* ws, double* wy, double* theta, double* xx, double* gg, F77_int* col, F77_int* head, F77_int* iword, double* wv,
                  double* wn, F77_int* iprint, F77_int* info);

extern void dcsrch_(double* f, double* g, double* stp, double* ftol, double* gtol, double* xtol, double* stpmin, double* stpmax,
                   char* task, F77_int* isave, double* dsave);

extern void dcstep_(double* stx, double* fx, double* dx, double* sty, double* fy, double* dy, double* stp, double* fp,
                   double* dp, F77_int* brackt, double* stpmin, double* stpmax);

extern void timer_(double* ttime);

#endif /* LBFGSB_RB_LBFGSB_H_ */
