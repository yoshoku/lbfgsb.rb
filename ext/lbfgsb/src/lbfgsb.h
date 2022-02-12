#ifndef LBFGSB_RB_LBFGSB_H_
#define LBFGSB_RB_LBFGSB_H_

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE_ (1)
#define FALSE_ (0)

extern void setulb_(long* n, long* m, double* x, double* l, double* u, long* nbd, double* f, double* g, double* factr,
                   double* pgtol, double* wa, long* iwa, char* task, long* iprint, char* csave, long* lsave, long* isave,
                   double* dsave);

extern void mainlb_(long* n, long* m, double* x, double* l, double* u, long* nbd, double* f, double* g, double* factr,
                   double* pgtol, double* ws, double* wy, double* sy, double* ss, double* wt, double* wn, double* snd,
                   double* z__, double* r__, double* d__, double* t, double* xp, double* wa, long* index, long* iwhere,
                   long* indx2, char* task, long* iprint, char* csave, long* lsave, long* isave, double* dsave);

extern void active_(long* n, double* l, double* u, long* nbd, double* x, long* iwhere, long* iprint, long* prjctd, long* cnstnd,
                   long* boxed);

extern void bmv_(long* m, double* sy, double* wt, long* col, double* v, double* p, long* info);

extern void cauchy_(long* n, double* x, double* l, double* u, long* nbd, double* g, long* iorder, long* iwhere, double* t,
                   double* d__, double* xcp, long* m, double* wy, double* ws, double* sy, double* wt, double* theta, long* col,
                   long* head, double* p, double* c__, double* wbp, double* v, long* nseg, long* iprint, double* sbgnrm,
                   long* info, double* epsmch);

extern void cmprlb_(long* n, long* m, double* x, double* g, double* ws, double* wy, double* sy, double* wt, double* z__,
                   double* r__, double* wa, long* index, double* theta, long* col, long* head, long* nfree, long* cnstnd,
                   long* info);

extern void errclb_(long* n, long* m, double* factr, double* l, double* u, long* nbd, char* task, long* info, long* k);

extern void formk_(long* n, long* nsub, long* ind, long* nenter, long* ileave, long* indx2, long* iupdat, long* updatd,
                  double* wn, double* wn1, long* m, double* ws, double* wy, double* sy, double* theta, long* col, long* head,
                  long* info);

extern void formt_(long* m, double* wt, double* sy, double* ss, long* col, double* theta, long* info);

extern void freev_(long* n, long* nfree, long* index, long* nenter, long* ileave, long* indx2, long* iwhere, long* wrk,
                  long* updatd, long* cnstnd, long* iprint, long* iter);

extern void hpsolb_(long* n, double* t, long* iorder, long* iheap);

extern void lnsrlb_(long* n, double* l, double* u, long* nbd, double* x, double* f, double* fold, double* gd, double* gdold,
                   double* g, double* d__, double* r__, double* t, double* z__, double* stp, double* dnorm, double* dtd,
                   double* xstep, double* stpmx, long* iter, long* ifun, long* iback, long* nfgv, long* info, char* task,
                   long* boxed, long* cnstnd, char* csave, long* isave, double* dsave);

extern void matupd_(long* n, long* m, double* ws, double* wy, double* sy, double* ss, double* d__, double* r__, long* itail,
                   long* iupdat, long* col, long* head, double* theta, double* rr, double* dr, double* stp, double* dtd);

extern void prn1lb_(long* n, long* m, double* l, double* u, double* x, long* iprint, long* itfile, double* epsmch);

extern void prn2lb_(long* n, double* x, double* f, double* g, long* iprint, long* itfile, long* iter, long* nfgv, long* nact,
                   double* sbgnrm, long* nseg, char* word, long* iword, long* iback, double* stp, double* xstep);

extern void prn3lb_(long* n, double* x, double* f, char* task, long* iprint, long* info, long* itfile, long* iter, long* nfgv,
                   long* nintol, long* nskip, long* nact, double* sbgnrm, double* time, long* nseg, char* word, long* iback,
                   double* stp, double* xstep, long* k, double* cachyt, double* sbtime, double* lnscht);

extern void projgr_(long* n, double* l, double* u, long* nbd, double* x, double* g, double* sbgnrm);

extern void subsm_(long* n, long* m, long* nsub, long* ind, double* l, double* u, long* nbd, double* x, double* d__, double* xp,
                  double* ws, double* wy, double* theta, double* xx, double* gg, long* col, long* head, long* iword, double* wv,
                  double* wn, long* iprint, long* info);

extern void dcsrch_(double* f, double* g, double* stp, double* ftol, double* gtol, double* xtol, double* stpmin, double* stpmax,
                   char* task, long* isave, double* dsave);

extern void dcstep_(double* stx, double* fx, double* dx, double* sty, double* fy, double* dy, double* stp, double* fp,
                   double* dp, long* brackt, double* stpmin, double* stpmax);

extern void timer_(double* ttime);

#endif /* LBFGSB_RB_LBFGSB_H_ */
