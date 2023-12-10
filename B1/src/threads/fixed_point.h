#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H

/* Basic definitions of fixed point. */
typedef int fixed_t;
/* 16 LSB used for fractional part. */
#define FP_SHIFT_AMOUNT 16

/* Convert integer to fixed point */
#define FP_CONST(x) ((fixed_t)(x << FP_SHIFT_AMOUNT))

/* Convert x to integer (rounding to nearest) */
#define FP_ROUND(x) (x >= 0 ? ((x + (1 << (FP_SHIFT_AMOUNT - 1))) >> FP_SHIFT_AMOUNT) \
                            : ((x - (1 << (FP_SHIFT_AMOUNT - 1))) >> FP_SHIFT_AMOUNT))

/* Convert x to integer (rounding toward zero) */
#define FP_INT_PART(x) (x >> FP_SHIFT_AMOUNT)


/* fixed point plus fixed point */
#define FP_ADD(x,y) (x + y)

/* fixed point minus fixed point */
#define FP_SUB(x,y) (x - y)

/* Multiply two fixed point */
#define FP_MULT(x,y) ((fixed_t)(((int64_t) x) * y >> FP_SHIFT_AMOUNT))

/* Divide two fixed-point */
#define FP_DIV(x,y) ((fixed_t)((((int64_t) x) << FP_SHIFT_AMOUNT) / y))


/* fixed point plus integer */
#define FP_ADD_MIX(x,y) (x + (y << FP_SHIFT_AMOUNT))

/* fixed point minus integer */
#define FP_SUB_MIX(x,y) (x - (y << FP_SHIFT_AMOUNT))

/* Multiply a fixed point by an integer */
#define FP_MULT_MIX(x,y) (x * y)

/* Devide a fixed point by an integer */
#define FP_DIV_MIX(x,y) (x / y)


#endif /* thread/fixed_point.h */
