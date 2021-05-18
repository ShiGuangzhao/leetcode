/*************************************************************************
    > File Name: 1603_设计停车系统.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月22日 星期一 13时02分56秒
 ************************************************************************/

#include <iostream>
using namespace std;

class ParkingSystem {
private:
    enum {
        BIG_CAR = 0,
        MEDIUM_CAR = 1,
        SMALL_CAR = 2
    } car;

    int left[3];
public:
    ParkingSystem(int big, int medium, int small) {
        left[BIG_CAR] = big;
        left[MEDIUM_CAR] = medium;
        left[SMALL_CAR] = small;
    }

    bool addCar(int carType) {
        if(left[carType - 1] > 0) {
            --left[carType - 1];
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

