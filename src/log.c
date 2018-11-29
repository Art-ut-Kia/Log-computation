//---------------------------------------------------------------------------
float log(float x) {
#define SQRT_05 0.7071067811865475
#define MS      8.429369702178806e-8     // mantissa scaling = sqrt(2)/2^24
#define LN_TWO  0.6931471805599453
  double m, s, r, rp;
  unsigned int u;
  int e, i;
  u = *(unsigned int*)(&x);              // IEEE754 as a 32-bit array
  e = ((u & 0x7FFFFFFF) >> 23)-127;      // exponent
  m = SQRT_05 + (u & 0x007FFFFF) * MS;   // mantissa in [0.707 ... 1.414[
  s = rp = r = (m-1)/(m+1);
  r *= r;
  for (i=1; i<5; i++) {
    rp *= r;
    s += rp/(2*i+1);
  }
  return 2*s+(e+0.5)*LN_TWO;
#undef SQRT_05
#undef MS
#undef LN_TWO
}
//---------------------------------------------------------------------------
