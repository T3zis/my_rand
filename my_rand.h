#ifndef MYRANDOM_HEADER
#define MYRANDOM_HEADER

#include <cstdint>
#include <iostream>
#include <ctime>

typedef uint32_t my_rand_t;

#undef M
#define M 0x7fffffff
#undef A
#define A 16807
#undef OP
#define OP(x) ((x * A) % M)

class my_random
{
private:
  my_rand_t seed = 0;
  
  my_rand_t generate_random_seed(void)
  {
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0)
      return -1;
    return ((my_rand_t)(ts.tv_sec * 1000000000ULL + ts.tv_nsec));
  }

  my_rand_t seedrand(void)
  {
    my_rand_t seed;
    seed = generate_random_seed();
    return (this->seed = OP(seed));
  }
  
  my_rand_t seedproc(my_rand_t seed)
  {
    return (this->seed = OP(seed));
  }

public:
  my_rand_t my_rand(void)
  {
/* delete recursion: #define NOREC */    
 #ifdef NOREC
    static my_rand_t tmp = 0;
#endif      
    my_rand_t res = 0;
    
    res = (seed * 1103515245 + 12345) & M;
#ifdef NOREC      
    if (res == tmp)
      return (my_rand());
    tmp = res;
#endif
    return res;
  }
  
  void my_srand(my_rand_t seed, bool random)
  {
    if (random)
      seedrand();
    else
      seedproc(seed);
  }
  
  my_rand_t rmy_rand(my_rand_t max, my_rand_t min)
  {
    if (min >= max)
      return -1;
    
    if (seed == 0)
      seedrand();
    
    return min + my_rand() % (max - min + 1);
  }
  
  my_rand_t rzmy_rand(int max)
  {
    return (rmy_rand(max, 0));
  }
};

#endif
