#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Member {
    // 依次对应每个成员的到达时间、优先级、消耗时间、编号、是否已经服务过
    int arrTime;
    int priority;
    int conTime;
    int id;
    bool isVisited;
    // 构造函数
    Member(int arrT, int p, int conT, int i, bool f) :
            arrTime(arrT), priority(p), conTime(conT), id(i), isVisited(f) {}
};

// 定义自己的比较函数
struct mycmp {
    bool operator () (const Member* m1, const Member* m2) {
        if(m1->priority != m2->priority) {
            return m1->priority < m2->priority;
        } else if(m1->arrTime != m2->arrTime) {
            return  m1->arrTime > m2->arrTime;
        } else {
            return  m1->conTime > m2->conTime;
        }
    }
};

vector<int> bankQueue(priority_queue<Member*, vector<Member*>, mycmp> &pq_m, Member *pmem[], int n) {

    vector<int> result;
    if(n == 0)
        return result;
    int currentTime = pmem[0]->arrTime;
    int i = 0;
    while(i < n && pq_m.size() > 0) {
        Member *m = pq_m.top();
        if(m->isVisited) {
            pq_m.pop();
            continue;
        }
        if(m->arrTime <= currentTime) {
            m->isVisited = true;
            result.push_back(m->id);
            currentTime += m->conTime;
            pq_m.pop();
        } else {
            if(pmem[i]->isVisited == false) {
                result.push_back(pmem[i]->id);
                pmem[i]->isVisited = true;
                currentTime += pmem[i]->conTime;
            }
            i++;
        }
    }
    return result;
}

/*
5
0 1 10
2 1 10
5 3 10
7 2 5
11 3 5
*/
int main() {

    int n;
    cin >> n;
    Member *pmember[n];
    int a, p, c;
    // 定义优先队列
    priority_queue<Member*, vector<Member*>, mycmp> pq_m;
    vector<int> result;

    for(int i = 0; i < n; i++) {
        cin >> a >> p >> c;
        pmember[i] = new Member(a, p, c, i + 1, false);
        pq_m.push(pmember[i]);
    }
    result = bankQueue(pq_m, pmember, n);

    for(int i : result)
        cout << i << " ";
    cout << endl;
}
