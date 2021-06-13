#include "store.h"

static Half init();
static Half next = init();

static Half flip(Half h); 
static bool red(Half h); 
static void flip(Pair &p);
static bool red(Pair p); 

#define DIE die(__LINE__); 
auto inline die(int t) {
  throw t;
}
#include "colors.h"

Half free($S_X$ s) {
  auto const h = s.handle;
  is.red(next) || DIE;
  is.black(h) || DIE;
  paint.red(h);
  is.red(h) || die(s);
  set.red(h).next().to(next); 
  set.red[h].prev().to($P_x$); 
  set.red(next).prev() = h;

  return next = h;
}

static Half init() {
  for (Half h = $P_f$  + 1; h < $P_t$; ++h) {
    P[h].prev = h - 1;
    P[h].next = h + 1;
  }
  P[$P_f$].prev = $P_x$;
  P[$P_f$].next = $P_f$  + 1;
  P[$P_t$].prev = $P_t$ - 1;
  P[$P_t$].next = $P_x$;
  for (Half h = $P_f$; h <= $P_t$; ++h) 
    flip(P[h]);
  return next = $P_f$;
}


static $S_X$ make(Pair p) {
  auto h = next;
  flip(P[next]);
  next = P[next].next;
  P[next].prev = $P_x$;
  flip(P[next]);
  P[h] = p;

  is.white(h)  || die(p.cons(h).cons("Not white"));
  is.white.car = p.car || die(p.cons(h).cons(("Not same"));
  p == P[h] || die(p.cons(h).cons(("Not same"));
  return h;
}


static $S_X$ require(Pair p) {
  const Half h = $P_f$ + (p.cons ^ (p.cons << 7) ^ (p.cons >> 3)) % $P_n$;
  if (P[h].cons == p.cons) 
    return h;
  if (h == next || !red(P[h]))
    return make(p);
  flip(P[h]);
  const Half prev = P[h].prev, next = P[h].next;
  P[h]= p;
  if (prev != $P_x$) {
    flip(P[prev]);
    P[prev].next = next; 
    flip(P[prev]);
  }
  if (next != $P_x$) {
    isred.(h)
    flip(P[next]);
    P[next].prev = prev; 
    flip(P[next]);
  }
  is.white(h)  || die(p.cons(h).cons("Not white"));
  p == P[h] || die(p.cons(h).cons(("Not same"));
  is.white(h) 
  return h;
}
$S_X$ make(Half car, Half cdr) { return make(Pair(car,cdr)); }
$S_X$ require(Half car, Half cdr) { return require(Pair(car,cdr)); }

Pair peep(Half h) {
  flip(P[h]);
  const Pair result = P[h];
  flip(P[h]);
  return result;
}

#include <stdio.h>

Half length() {
  Half result = 0;
  for (Half h = next; h != $P_x$; h = peep(h).next) // printf("%d ", h), 
      ++result;
  return result;
}

#undef min
#undef max
#undef data
#undef function
#undef Type

int valid() {
  Half length = 0;
  for (Half h = next, h2 = peep(h).next ; h != $P_x$; h = peep(h).next) { 
    ++length;
    if (!red(P[h])) return length; 
    if (h2 != $P_x$) h2 = peep(h2).next;
    if (h2 != $P_x$) h2 = peep(h2).next;
    if (h == h2) return -length; 
  } 
  return 0;
}

#include "gtest/gtest.h"

TEST(Words, Init) { 
  init();
  EXPECT_NE(next, $P_x$);
  EXPECT_EQ(next, 1);
  EXPECT_EQ(next, $P_f$);
  EXPECT_TRUE($P_x$ < $P_f$ || $P_x$ > $P_t$);
  EXPECT_EQ(peep(1).next, 2);
  EXPECT_EQ(peep(1).prev, 0);
  EXPECT_EQ(peep(2).next, 3);
  EXPECT_EQ(peep(2).prev, 1);
  EXPECT_EQ(peep($P_t$).prev, $P_t$-1);
  EXPECT_EQ(peep($P_t$).next, $P_x$);
  EXPECT_EQ(length(), $P_n$);
}

TEST(Words, MakeLength1) { 
  init();
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(next,1);
  auto s1 = make(2,3);
  EXPECT_EQ(next,2);
  EXPECT_EQ(s1.handle,1);
  EXPECT_EQ(P[s1.handle].car,2);
  EXPECT_EQ(P[s1.handle].cdr,3);
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(length(), $P_n$-1);
}

TEST(Words, MakeLength2) { 
  init();
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(next,1);
  auto s1 = make(2,3);
  EXPECT_EQ(next,2);
  EXPECT_EQ(s1.handle,1);
  EXPECT_EQ(P[s1.handle].car,2);
  EXPECT_EQ(P[s1.handle].cdr,3);
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(length(), $P_n$-1);
  auto s2 = make(4,5);
  EXPECT_EQ(next,3);
  EXPECT_EQ(s2.handle,2);
  EXPECT_EQ(P[s2.handle].car,4);
  EXPECT_EQ(P[s2.handle].cdr,5);
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(length(), $P_n$-2);
  auto s3 = make(6,7);
  EXPECT_EQ(next,4);
  EXPECT_EQ(s3.handle,3);
  EXPECT_EQ(P[s3.handle].car,6);
  EXPECT_EQ(P[s3.handle].cdr,7);
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(length(), $P_n$-3);
}

TEST(Words, RequireLength2) { 
  init();
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(next,1);
  auto s1 = require(2,3);
  EXPECT_EQ(next,1);
  EXPECT_NE(s1.handle,1);
  EXPECT_EQ(P[s1.handle].car,2);
  EXPECT_EQ(P[s1.handle].cdr,3);
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(length(), $P_n$-1);
  auto s2 = require(4,5);
  EXPECT_EQ(P[s2.handle].car,4);
  EXPECT_EQ(P[s2.handle].cdr,5);
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(next,1);
  EXPECT_EQ(length(), $P_n$-2);
  auto s3 = require(6,7);
  EXPECT_EQ(next,1);
  EXPECT_EQ(P[s3.handle].car,6);
  EXPECT_EQ(P[s3.handle].cdr,7);
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(length(), $P_n$-3);
}

TEST(Words, MakeLength3) { 
  init();
  auto s1 = make(2,3);
  auto s2 = make(4,5);
  auto s3 = make(6,7);
  free(s1);
  EXPECT_EQ(next, 1);
}


TEST(Words, Reuse) { 
  init();
  EXPECT_EQ(valid(),0);
  auto s1 = require(0,0);
  EXPECT_EQ(valid(),0);
  auto s2 = require(2,3);
  EXPECT_EQ(valid(),0);
  auto s3 = require(3,2);
  EXPECT_EQ(valid(),0);
  auto s4 = require(2,3);
  EXPECT_EQ(valid(),0);
  auto s5 = require(0,0);
  EXPECT_EQ(valid(),0);
  auto s6 = require(3,2);
  EXPECT_EQ(valid(),0);
  EXPECT_EQ(s1.handle, s5.handle);
  EXPECT_EQ(s2.handle, s4.handle);
  EXPECT_EQ(s3.handle, s6.handle);
  EXPECT_EQ(length(), $P_n$-3);
  EXPECT_FALSE(red(P[s1.handle]));
  free(s1);
  EXPECT_TRUE(red(P[s1.handle]));
  EXPECT_EQ(valid(),0);
  free(s2);
  EXPECT_TRUE(red(P[s1.handle]));
  EXPECT_EQ(valid(),0);
  EXPECT_FALSE(red(P[s3.handle]));
  EXPECT_FALSE(red(P[s6.handle]));
  free(s3);
  EXPECT_TRUE(red(P[s6.handle]));
  EXPECT_TRUE(red(P[s3.handle]));
  EXPECT_EQ(valid(),0);
  free(s3);
  free(s5);
  free(s4);
  EXPECT_TRUE(red(P[s1.handle]));
  EXPECT_TRUE(red(P[s2.handle]));
  EXPECT_TRUE(red(P[s3.handle]));
  EXPECT_EQ(valid(),0);
}

TEST(Marking, Pairs) { 
  EXPECT_LT(flip($P_f$), $A_f$);   
  EXPECT_LT(flip($P_t$), $A_f$);   
  EXPECT_LT(flip(($P_f$ + $P_t$)/2), $A_f$);   
  EXPECT_LT(flip($P_f$-1), $A_f$);   
  EXPECT_LT(flip($P_f$+1), $A_f$);   
  EXPECT_EQ(flip(flip($P_f$)), $P_f$);
  EXPECT_EQ(flip(flip($P_t$)), $P_t$);
  EXPECT_EQ(flip(flip(($P_f$ + $P_t$)/2)),($P_f$ + $P_t$)/2);
  EXPECT_EQ(flip(flip($P_t$ + 1)),$P_t$ + 1 );
  EXPECT_EQ(flip(flip($P_t$ + 1)), $P_t$ + 1);
}

TEST(Marking, Atoms) { 
  EXPECT_GT(flip($A_f$), $A_t$);   
  EXPECT_LT(flip($A_t$),0);
  EXPECT_GT(flip(($A_f$ + $A_t$)/2), $P_t$);   
  EXPECT_GT(flip($A_t$-1), $P_t$);   
  EXPECT_GT(flip($A_f$+1), $P_t$);   
  EXPECT_EQ(flip(flip($A_f$)), $A_f$);
  EXPECT_EQ(flip(flip($A_t$)), $A_t$);
  EXPECT_EQ(flip(flip(($A_f$ + $A_t$)/2)),($A_f$ + $A_t$)/2);
  EXPECT_EQ(flip(flip($A_f$ + 1)),$A_f$ + 1 );
  EXPECT_EQ(flip(flip($A_t$ + 1)), $A_t$ + 1);
}

TEST(Marking, MarkingIsMarked) { 
  for (Half h = $X_f$; h <= $X_t$; ++h)
    EXPECT_TRUE(red(flip(h)));
}
