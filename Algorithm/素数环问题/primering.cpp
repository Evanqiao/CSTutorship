//
//  primeRing.cpp
//  tree
//
//  Created by Ge, Xiao on 02/03/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include "math.h"

using namespace std;

int isPrime(int n) {    // 判断质数
    if (n==1 || n==2 || (n>2 && n%2==0)){
        return 0;
    }
    for (int i=3;i<=sqrt(n);i+=2){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}


// 回溯法遍历
void search(int data[],int n,int i) {
    
    cout<<"Seaching: "<<data[1]; // 日志
    for (int j=2;j<=i;j++){
        cout<<" "<<data[j];
    }
    cout<<endl;
    
    if (i==n){    // 递归边界，n个数都确定了位置
        if (isPrime(data[n]+data[1])) {
            for (int j=1;j<=n;j++){  // 最后判断首尾和是不是素数，是的话就找到一个解
                cout<<data[j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    int tmp=data[i];
    for (int j=i;j<=n;j++){  // 枚举尚未确定的数字
        if (isPrime(data[j]+data[i-1])){ // 剪枝
            data[i]=data[j];    // 交换i,j位的数字
            data[j]=tmp;
            search(data,n,i+1);   // 递归搜索下一个数
            data[j]=data[i];    // 恢复第j位的数字
        }
    }
    data[i]=tmp;    // 恢复第i位的数字
}


int main(){
    int n;
    cin>>n;
    if (n%2==1) {   // 预判，也是一种优化
        cout<<"奇数是不可能的!"<<endl;
        return 0;
    }
    int data[n+1];
    for (int j=1;j<=n;j++) {    // 初始化排列
        data[j]=j;
    }
    search(data,n,2);   // 为什么从2开始？因为循环对称性，第1位固定为1}
    return 0;
}
