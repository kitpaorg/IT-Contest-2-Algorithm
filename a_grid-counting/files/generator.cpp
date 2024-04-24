#include "testlib.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 40);
    int m = rnd.next(1, 40);
    cout << n << '\n' << m << endl;
}