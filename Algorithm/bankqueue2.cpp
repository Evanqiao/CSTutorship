#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Member {
    int arrTime;
    int priority;
    int conTime;
    int id;
};

void consructMember(Member &m, int arrTime, int priority, int conTime, int id) {
    m.arrTime = arrTime;
    m.priority = priority;
    m.conTime = conTime;
    m.id = id;
}

bool operator < (const Member &m1, const Member &m2) {

    if(m1.priority != m2.priority) {
        return m1.priority < m2.priority;
    } else if(m1.arrTime != m2.arrTime) {
        return  m1.arrTime > m2.arrTime;
    } else {
        return  m1.conTime > m2.conTime;
    }
}
template<typename T> void print_queue(T q) {
    Member m;
    while(!q.empty()) {
        m = q.top();
        cout << "(" << m.arrTime << ", " << m.priority << ", " << m.conTime << ", " << m.id << ")" << endl;
        q.pop();
    }
}

template<typename T> void print_vector(T& vec) {
    Member m;
    for(m : vec) {
        cout << "(" << m.arrTime << ", " << m.priority << ", " << m.conTime << ", " << m.id << ")" << endl;
    }
}

vector<int> bankQueue(priority_queue<Member> &pq_m, int currentTime) {

    vector<int> result;
    vector<Member> vec_m;

    while(!pq_m.empty()) {
        Member m = pq_m.top();
        while(m.arrTime > currentTime && pq_m.size() > 0) {
            vec_m.push_back(m);
            pq_m.pop();
            m = pq_m.top();
        }
        if(m.arrTime <= currentTime) {
            pq_m.pop();
            result.push_back(m.id);
            currentTime += m.conTime;
        } else {
            currentTime += 1;
        }
        for(int i = 0; i < vec_m.size(); i++) {
            pq_m.push(vec_m[i]);
        }
        vec_m.clear();
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
    Member member[n];
    int a, p, c;
    priority_queue<Member> pq_m;
    vector<int> result;
    int currentTime;

    for(int i = 0; i < n; i++) {
        cin >> a >> p >> c;
        consructMember(member[i], a, p, c, i + 1);
        pq_m.push(member[i]);
        currentTime = i == 0 ? a : currentTime;
    }

    result = bankQueue(pq_m, currentTime);

    for(int i : result)
        cout << i << " ";
    cout << endl;
}

