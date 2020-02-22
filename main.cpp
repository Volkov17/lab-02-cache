#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

#include "cache.h"




int main() {
    // L1 = 0.25mb = 32768b   32768 /4 /2 = 4096
    // L2 = 2mb = 262144b
    // L3 = 3mb = 3145728b    (3145728 /4 ) *3/2 = 1179648


    Cache cache ;
    cache.run();


    return 0;
}
