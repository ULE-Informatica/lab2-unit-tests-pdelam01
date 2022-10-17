#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 

/* 
 * wrapFunctionAdd - returns the sum of the two arguments 
 *
 * The addition of this two parameters may result in a overflow.
 * In order to avoid that, we will add a precondition test so that we guarantee theres is not a wrap.
 * If UINT_MAX - ui_a < ui_b that means the add of ui_a + ui_b will cause a overflow.
 */
unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum;
  if (UINT_MAX - ui_a < ui_b) {
    printf("Error: wrapFunctionAdd() - wrapping detected");
    exit(-1);
  }else{
    usum = ui_a + ui_b;
  }
  return usum;
}

/*
* wrapFunctionMult - returns the product of the two arguments
*
* The multiplication of this two parameters may result in a overflow.
* As we did before, we will add a precondition test so that we guarantee theres is not a wrap.
*/
unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = ui_a;
  
  if (ui_a == 0 || ui_b == 0) { /* Ensure that any of the operands is 0 */
    return 0;
  }

  if (UINT_MAX / ui_a < ui_b) {
    printf("Error: wrapFunctionMul() - wrapping detected");
    exit(-1);
  }else{
    umul *= ui_b;
  }
  
  return umul;
}

/* The PRECISION() macro and popcount() function provide the correct precision for any integer type. */
extern size_t popcount(uintmax_t);
#define PRECISION(x) popcount(x)

uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  uint32_t uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 

  /* Eliminates the possibility of shifting by greater than or equal to the number of bits that exist in the precision of the left and right operand */
  if (ui_b >= PRECISION(UINT_MAX)) {
    printf("Error: wrapFunctionMul() - wrapping detected");
    exit(-1);
  } else {
    uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 
  }


  return uShift;
}
