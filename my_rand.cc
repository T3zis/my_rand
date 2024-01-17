#include <iostream>
#include <ctime>

int your_seed(int seed)
{
  int a = 16807;
  unsigned int m = 0x7fffffff;


  seed = (seed * a) % m;


  return seed;
}


int generate_random_seed(void)
{
  static int seed = static_cast<int>(std::time(nullptr));
  int a = 16807;
  unsigned int m = 0x7fffffff;


  seed = (seed * a) % m;


  return seed;
}


int my_rand(int minus_or_plus)
{
  int new_seed = generate_random_seed();

  if (minus_or_plus <= 0)
    new_seed *= -1;


  new_seed %= minus_or_plus;


  return new_seed;
}


int smy_rand(int seed, int minus_or_plus)
{
  int new_seed = your_seed(seed);


  if (minus_or_plus <= 0)
    new_seed *= -1;


  new_seed %= minus_or_plus;


  return new_seed;
}



int rmy_rand(int min_value, int max_value)
{
  int new_seed = generate_random_seed();
  int range = max_value - min_value + 1;


  new_seed = (new_seed % range + range) % range + min_value;


  return new_seed;
}

