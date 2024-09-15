#include <iostream>
using namespace std;

int main() {
    bool isPrime[101]; // 创建一个布尔数组来标记每个数是否为质数
    for (int i = 0; i <= 100; i++) {
        isPrime[i] = true; // 初始假设所有数都是质数
    }
    isPrime[0] = isPrime[1] = false; // 0和1不是质数

// 筛除非质数
    for (int i = 2; i*i <= 100; i++) { // 只需检查到sqrt(100)即可
        if (isPrime[i]) {
            for (int j = i * i; j <= 100; j += i) {
                isPrime[j] = false; // 标记i的所有倍数为非质数
            }
        }
    }

// 打印质数
    for (int i = 2; i <= 100; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
