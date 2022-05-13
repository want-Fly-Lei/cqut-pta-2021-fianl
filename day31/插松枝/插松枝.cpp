#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, k;
queue<int> qu;
stack<int> sta, stm;
vector<vector<int>> ans;

//将sta里的数据插入到答案数组中
void insert() {
    vector<int> nums;
    while (sta.size() != 0) {
        nums.push_back(sta.top());
        sta.pop();
    }
    reverse(nums.begin(), nums.end());
    ans.push_back(nums);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    int i, j, t, temp, node;
    for (i = 0; i < n; i++) {
        scanf("%d",&t);
        qu.push(t);
    }

    while (!qu.empty() || !stm.empty()) {
        if (!stm.empty()) {
            temp = stm.top();
            if (sta.size() == 0 || temp <= sta.top()) {
                sta.push(temp);
                stm.pop();
                if (sta.size() == k) {
                    insert();
                }
            } else if (temp > sta.top() && qu.size() != 0) {
                node = qu.front();
                
                if (node <= sta.top()) {
                    sta.push(node);
                    qu.pop();
                    if (sta.size() == k) {
                        insert();
                    }
                } else if (node > sta.top()) {
                    if (stm.size() < m) {
                        stm.push(node);
                        qu.pop();
                    } else {
                        insert();
                    }
                }
            } else if (temp > sta.top() && qu.size() == 0) {
                insert();
            }
        } else if (stm.size() == 0 && qu.size() != 0) {
            temp = qu.front();
            if (sta.size() == 0 || temp <= sta.top()) {
                sta.push(temp);
                if (sta.size() == k) {
                    insert();
                }
                qu.pop();
            } else if (temp > sta.top()) {
                stm.push(temp);
                qu.pop();
            }
        }
    }

    if (sta.size() != 0) {
        insert();
    }
    
    for (i = 0; i < ans.size(); i++) {
        for (j = 0; j < ans[i].size(); j++) {
            if (j != ans[i].size() - 1) {
                cout << ans[i][j] << ' ';
            } else {
                cout << ans[i][j] << endl;
            }
        }
    }
    return 0;
}
