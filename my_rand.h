#ifndef MY_RANDOM
#define MY_RANDOM


#include <iostream>
#include <ctime>


class my_random
{
private:
  int your_seed(int user_seed)
  {
    int a = 16807;
    unsigned int m = 0x7fffffff;


    user_seed = (user_seed * a) % m;


    return user_seed;
  }


  int generate_random_seed()
  {
    static int seed = static_cast<int>(std::time(nullptr));
    int a = 16807;
    unsigned int m = 0x7fffffff;


    seed = (seed * a) % m;


    return seed;
  }

public:
  int my_rand(int minus_or_plus)
  {
    int new_seed = generate_random_seed();


    if (minus_or_plus <= 0)
      new_seed *= -1;


    new_seed %= minus_or_plus;
    return new_seed;
  }


  int smy_rand(int user_seed, int minus_or_plus)
  {
    int new_seed = your_seed(user_seed);


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
};



#endif
