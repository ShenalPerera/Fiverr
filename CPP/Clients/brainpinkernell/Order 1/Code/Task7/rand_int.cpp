#include <random>

using namespace std;

int rand_int(int desired_min, int desired_max){

    random_device rand_dev;

    mt19937 mt(rand_dev());

    uniform_int_distribution<int> dist(desired_min,desired_max);

    return dist(mt);
}
