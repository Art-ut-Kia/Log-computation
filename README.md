# Log-computation
Neperian logarithm computation for compilers that doesn't implement it

The microtec C compiler for 68040 doesn't implement the natural logarithm fonction.

This project is a C function that operates on a float type (single precision) and returns the natural logarithm with the float type.

The computation is based on the development in series of the ArcTanH function.
Reference : [wikipedia](https://en.wikipedia.org/wiki/Logarithm#Power_series)

Furthermore it computes separatly the log of exponent and mantissa to bound the error in +/- 10^-9, i.e. at a levl lower than float quantification error.
