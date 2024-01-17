#include <iostream>
#include <ctime>

int generate_random_seed(void)
{
  static int seed = static_cast<int>(std::time(nullptr));
  int a = 16807;
  unsigned int m = 0x7fffffff;


  seed = (seed * a) % m;


  return seed;
}

int my_rand(int min_or_plus)
{
  int new_seed = generate_random_seed();

  if (min_or_plus <= 0)
    new_seed *= -1;


  new_seed %= min_or_plus;


  return new_seed;
}

