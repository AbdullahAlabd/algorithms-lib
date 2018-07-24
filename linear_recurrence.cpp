// https://en.wikibooks.org/wiki/Linear_Algebra/Topic:_Linear_Recurrences
// 
//    cn cn-1 ... cn-k         f(n)            f(n+1)
//    1  0 ...... 0            f(n-1)          f(n)
//    0  1 ...... 0      X     .         =     .
//    .............            .               .
//    0  0  0  1  0            f(n-k)          f(n-k+1)
//
//    where f(n+1) = cn * f(n) + cn-1 * f(n-1) + ..... + cn-k * f(n-k).
