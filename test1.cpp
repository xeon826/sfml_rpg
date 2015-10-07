#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
int main() {
    srand(time(NULL));
    while(1) {
        int s = (500+rand())%500;
        cout << s << endl;
    } 
    return 0;
}
