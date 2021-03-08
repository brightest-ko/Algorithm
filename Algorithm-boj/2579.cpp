#include <iostream>
using namespace std;
int n;

int main(int argc, const char * argv[]) {
//    cout << "Helloworld!";
    int step[301] = {0};
    int sum_steps[301] = {0};
    cin >> n;
    for(int i=1 ; i <= n ; i++ ){
        cin >> step[i];
    }
    sum_steps[1] = step[1];
    for(int i=2 ; i <= n ; i++ ){
        sum_steps[i] = max(step[i-1]+sum_steps[i-3],sum_steps[i-2]) + step[i];
    }
    cout << sum_steps[n];
    return 0;
}
