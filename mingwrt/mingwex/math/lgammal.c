/*							lgaml()
 *
 *	Natural logarithm of gamma function
 *
 *
 *
 * SYNOPSIS:
 *
 * long double x, y, __lgammal_r();
 * int* sgngaml;
 * y = __lgammal_r( x, sgngaml );
 *
 * long double x, y, lgammal();
 * y = lgammal( x);
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns the base e (2.718...) logarithm of the absolute
 * value of the gamma function of the argument. In the reentrant
 * version, the sign (+1 or -1) of the gamma function is returned
 * in the variable referenced by sgngaml.
 *
 * For arguments greater than 33, the logarithm of the gamma
 * function is approximated by the logarithmic version of
 * Stirling's formula using a polynomial approximation of
 * degree 4. Arguments between -33 and +33 are reduced by
 * recurrence to the interval [2,3] of a rational approximation.
 * The cosecant reflection formula is employed for arguments
 * less than -33.
 *
 * Arguments greater than MAXLGML (10^4928) return MAXNUML.
 *
 *
 *
 * ACCURACY:
 *
 *
 * arithmetic      domain        # trials     peak         rms
 *    IEEE         -40, 40        100000     2.2e-19     4.6e-20
 *    IEEE    10^-2000,10^+2000    20000     1.6e-19     3.3e-20
 * The error criterion was relative when the function magnitude
 * was greater than one but absolute when it was less than one.
 *
 */

/*
 * Copyright 1994 by Stephen L. Moshier
 */

/*
 * 26-11-2002 Modified for mingw.
 * Danny Smith <dannysmith@users.sourceforge.net>
 */

#ifndef __MINGW32__
#include "mconf.h"
#ifdef ANSIPROT
extern long double fabsl ( long double );
extern long double lgaml ( long double );
extern long double logl ( long double );
extern long double expl ( long double );
extern long double gammal ( long double );
extern long double sinl ( long double );
extern long double floorl ( long double );
extern long double powl ( long double, long double );
extern long double polevll ( long double, void *, int );
extern long double p1evll ( long double, void *, int );
extern int isnanl ( long double );
extern int isfinitel ( long double );
#else
long double fabsl(), lgaml(), logl(), expl(), gammal(), sinl();
long double floorl(), powl(), polevll(), p1evll(), isnanl(), isfinitel();
#endif
#ifdef INFINITIES
extern long double INFINITYL;
#endif
#ifdef NANS
extern long double NANL;
#endif
#else /* __MINGW32__ */
#include "cephes_mconf.h"
#endif /* __MINGW32__ */

#if UNK
static long double S[9] = {
-1.193945051381510095614E-3L,
 7.220599478036909672331E-3L,
-9.622023360406271645744E-3L,
-4.219773360705915470089E-2L,
 1.665386113720805206758E-1L,
-4.200263503403344054473E-2L,
-6.558780715202540684668E-1L,
 5.772156649015328608253E-1L,
 1.000000000000000000000E0L,
};
#endif
#if IBMPC
static const uLD S[] = {
{ { 0xbaeb,0xd6d3,0x25e5,0x9c7e,0xbff5, XPD } },
{ { 0xfe9a,0xceb4,0xc74e,0xec9a,0x3ff7, XPD } },
{ { 0x9225,0xdfef,0xb0e9,0x9da5,0xbff8, XPD } },
{ { 0x10b0,0xec17,0x87dc,0xacd7,0xbffa, XPD } },
{ { 0x6b8d,0x7515,0x1905,0xaa89,0x3ffc, XPD } },
{ { 0xf183,0x126b,0xf47d,0xac0a,0xbffa, XPD } },
{ { 0x7bf6,0x57d1,0xa013,0xa7e7,0xbffe, XPD } },
{ { 0xc7a9,0x7db0,0x67e3,0x93c4,0x3ffe, XPD } },
{ { 0x0000,0x0000,0x0000,0x8000,0x3fff, XPD } }
};
#endif
#if MIEEE
static long S[27] = {
0xbff50000,0x9c7e25e5,0xd6d3baeb,
0x3ff70000,0xec9ac74e,0xceb4fe9a,
0xbff80000,0x9da5b0e9,0xdfef9225,
0xbffa0000,0xacd787dc,0xec1710b0,
0x3ffc0000,0xaa891905,0x75156b8d,
0xbffa0000,0xac0af47d,0x126bf183,
0xbffe0000,0xa7e7a013,0x57d17bf6,
0x3ffe0000,0x93c467e3,0x7db0c7a9,
0x3fff0000,0x80000000,0x00000000,
};
#endif

#if UNK
static long double SN[9] = {
 1.133374167243894382010E-3L,
 7.220837261893170325704E-3L,
 9.621911155035976733706E-3L,
-4.219773343731191721664E-2L,
-1.665386113944413519335E-1L,
-4.200263503402112910504E-2L,
 6.558780715202536547116E-1L,
 5.772156649015328608727E-1L,
-1.000000000000000000000E0L,
};
#endif
#if IBMPC
static const uLD SN[] = {
{ { 0x5dd1,0x02de,0xb9f7,0x948d,0x3ff5, XPD } },
{ { 0x989b,0xdd68,0xc5f1,0xec9c,0x3ff7, XPD } },
{ { 0x2ca1,0x18f0,0x386f,0x9da5,0x3ff8, XPD } },
{ { 0x783f,0x41dd,0x87d1,0xacd7,0xbffa, XPD } },
{ { 0x7a5b,0xd76d,0x1905,0xaa89,0xbffc, XPD } },
{ { 0x7f64,0x1234,0xf47d,0xac0a,0xbffa, XPD } },
{ { 0x5e26,0x57d1,0xa013,0xa7e7,0x3ffe, XPD } },
{ { 0xc7aa,0x7db0,0x67e3,0x93c4,0x3ffe, XPD } },
{ { 0x0000,0x0000,0x0000,0x8000,0xbfff, XPD } }
};
#endif
#if MIEEE
static long SN[27] = {
0x3ff50000,0x948db9f7,0x02de5dd1,
0x3ff70000,0xec9cc5f1,0xdd68989b,
0x3ff80000,0x9da5386f,0x18f02ca1,
0xbffa0000,0xacd787d1,0x41dd783f,
0xbffc0000,0xaa891905,0xd76d7a5b,
0xbffa0000,0xac0af47d,0x12347f64,
0x3ffe0000,0xa7e7a013,0x57d15e26,
0x3ffe0000,0x93c467e3,0x7db0c7aa,
0xbfff0000,0x80000000,0x00000000,
};
#endif


/* A[]: Stirling's formula expansion of log gamma
 * B[], C[]: log gamma function between 2 and 3
 */


/* log gamma(x) = ( x - 0.5 ) * log(x) - x + LS2PI + 1/x A(1/x^2)
 * x >= 8
 * Peak relative error 1.51e-21
 * Relative spread of error peaks 5.67e-21
 */
#if UNK
static long double A[7] = {
 4.885026142432270781165E-3L,
-1.880801938119376907179E-3L,
 8.412723297322498080632E-4L,
-5.952345851765688514613E-4L,
 7.936507795855070755671E-4L,
-2.777777777750349603440E-3L,
 8.333333333333331447505E-2L,
};
#endif
#if IBMPC
static const uLD A[] = {
{ { 0xd984,0xcc08,0x91c2,0xa012,0x3ff7, XPD } },
{ { 0x3d91,0x0304,0x3da1,0xf685,0xbff5, XPD } },
{ { 0x3bdc,0xaad1,0xd492,0xdc88,0x3ff4, XPD } },
{ { 0x8b20,0x9fce,0x844e,0x9c09,0xbff4, XPD } },
{ { 0xf8f2,0x30e5,0x0092,0xd00d,0x3ff4, XPD } },
{ { 0x4d88,0x03a8,0x60b6,0xb60b,0xbff6, XPD } },
{ { 0x9fcc,0xaaaa,0xaaaa,0xaaaa,0x3ffb, XPD } }
};
#endif
#if MIEEE
static long A[21] = {
0x3ff70000,0xa01291c2,0xcc08d984,
0xbff50000,0xf6853da1,0x03043d91,
0x3ff40000,0xdc88d492,0xaad13bdc,
0xbff40000,0x9c09844e,0x9fce8b20,
0x3ff40000,0xd00d0092,0x30e5f8f2,
0xbff60000,0xb60b60b6,0x03a84d88,
0x3ffb0000,0xaaaaaaaa,0xaaaa9fcc,
};
#endif

/* log gamma(x+2) = x B(x)/C(x)
 * 0 <= x <= 1
 * Peak relative error 7.16e-22
 * Relative spread of error peaks 4.78e-20
 */
#if UNK
static long double B[7] = {
-2.163690827643812857640E3L,
-8.723871522843511459790E4L,
-1.104326814691464261197E6L,
-6.111225012005214299996E6L,
-1.625568062543700591014E7L,
-2.003937418103815175475E7L,
-8.875666783650703802159E6L,
};
static long double C[7] = {
/* 1.000000000000000000000E0L,*/
-5.139481484435370143617E2L,
-3.403570840534304670537E4L,
-6.227441164066219501697E5L,
-4.814940379411882186630E6L,
-1.785433287045078156959E7L,
-3.138646407656182662088E7L,
-2.099336717757895876142E7L,
};
#endif
#if IBMPC
static const uLD B[] = {
{ { 0x9557,0x4995,0x0da1,0x873b,0xc00a, XPD } },
{ { 0xfe44,0x9af8,0x5b8c,0xaa63,0xc00f, XPD } },
{ { 0x5aa8,0x7cf5,0x3684,0x86ce,0xc013, XPD } },
{ { 0x259a,0x258c,0xf206,0xba7f,0xc015, XPD } },
{ { 0xbe18,0x1ca3,0xc0a0,0xf80a,0xc016, XPD } },
{ { 0x168f,0x2c42,0x6717,0x98e3,0xc017, XPD } },
{ { 0x2051,0x9d55,0x92c8,0x876e,0xc016, XPD } }
};
static const uLD C[] = {
{ { 0xaa77,0xcf2f,0xae76,0x807c,0xc008, XPD } },
{ { 0xb280,0x0d74,0xb55a,0x84f3,0xc00e, XPD } },
{ { 0xa505,0xcd30,0x81dc,0x9809,0xc012, XPD } },
{ { 0x3369,0x4246,0xb8c2,0x92f0,0xc015, XPD } },
{ { 0x63cf,0x6aee,0xbe6f,0x8837,0xc017, XPD } },
{ { 0x26bb,0xccc7,0xb009,0xef75,0xc017, XPD } },
{ { 0x462b,0xbae8,0xab96,0xa02a,0xc017, XPD } }
};
#endif
#if MIEEE
static long B[21] = {
0xc00a0000,0x873b0da1,0x49959557,
0xc00f0000,0xaa635b8c,0x9af8fe44,
0xc0130000,0x86ce3684,0x7cf55aa8,
0xc0150000,0xba7ff206,0x258c259a,
0xc0160000,0xf80ac0a0,0x1ca3be18,
0xc0170000,0x98e36717,0x2c42168f,
0xc0160000,0x876e92c8,0x9d552051,
};
static long C[21] = {
/*0x3fff0000,0x80000000,0x00000000,*/
0xc0080000,0x807cae76,0xcf2faa77,
0xc00e0000,0x84f3b55a,0x0d74b280,
0xc0120000,0x980981dc,0xcd30a505,
0xc0150000,0x92f0b8c2,0x42463369,
0xc0170000,0x8837be6f,0x6aee63cf,
0xc0170000,0xef75b009,0xccc726bb,
0xc0170000,0xa02aab96,0xbae8462b,
};
#endif

/* log( sqrt( 2*pi ) ) */
static const long double LS2PI  =  0.91893853320467274178L;
#define MAXLGM 1.04848146839019521116e+4928L


/* Logarithm of gamma function */
/* Reentrant version */

long double __lgammal_r(long double x, int* sgngaml)
{
long double p, q, w, z, f, nx;
int i;

*sgngaml = 1;
#ifdef NANS
if( isnanl(x) )
	return(NANL);
#endif
#ifdef INFINITIES
if( !isfinitel(x) )
	return(INFINITYL);
#endif
if( x < -34.0L )
	{
	q = -x;
	w = __lgammal_r(q, sgngaml); /* note this modifies sgngam! */
	p = floorl(q);
	if( p == q )
		{
lgsing:
		_SET_ERRNO(EDOM);
		mtherr( "lgammal", SING );
#ifdef INFINITIES
		return (INFINITYL);
#else
		return (MAXNUML);
#endif
		}
	i = p;
	if( (i & 1) == 0 )
		*sgngaml = -1;
	else
		*sgngaml = 1;
	z = q - p;
	if( z > 0.5L )
		{
		p += 1.0L;
		z = p - q;
		}
	z = q * sinl( PIL * z );
	if( z == 0.0L )
		goto lgsing;
/*	z = LOGPI - logl( z ) - w; */
	z = logl( PIL/z ) - w;
	return( z );
	}

if( x < 13.0L )
	{
	z = 1.0L;
	nx = floorl( x +  0.5L );
	f = x - nx;
	while( x >= 3.0L )
		{
		nx -= 1.0L;
		x = nx + f;
		z *= x;
		}
	while( x < 2.0L )
		{
		if( fabsl(x) <= 0.03125 )
			goto lsmall;
		z /= nx +  f;
		nx += 1.0L;
		x = nx + f;
		}
	if( z < 0.0L )
		{
		*sgngaml = -1;
		z = -z;
		}
	else
		*sgngaml = 1;
	if( x == 2.0L )
		return( logl(z) );
	x = (nx - 2.0L) + f;
	p = x * polevll( x, B, 6 ) / p1evll( x, C, 7);
	return( logl(z) + p );
	}

if( x > MAXLGM )
	{
	_SET_ERRNO(ERANGE);
	mtherr( "lgammal", OVERFLOW );
#ifdef INFINITIES
	return( *sgngaml * INFINITYL );
#else
	return( *sgngaml * MAXNUML );
#endif
	}

q = ( x - 0.5L ) * logl(x) - x + LS2PI;
if( x > 1.0e10L )
	return(q);
p = 1.0L/(x*x);
q += polevll( p, A, 6 ) / x;
return( q );


lsmall:
if( x == 0.0L )
	goto lgsing;
if( x < 0.0L )
	{
	x = -x;
	q = z / (x * polevll( x, SN, 8 ));
	}
else
	q = z / (x * polevll( x, S, 8 ));
if( q < 0.0L )
	{
	*sgngaml = -1;
	q = -q;
	}
else
	*sgngaml = 1;
q = logl( q );
return(q);
}

/* This is the C99 version */

long double lgammal(long double x)
{
  int local_sgngaml=0;
  return (__lgammal_r(x, &local_sgngaml));
}
