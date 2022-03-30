#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;

int main() {
    short city,route, i, j, k, len, city1, city2;
    scanf("%d %d",&city,&route);
    ++city;
    vector<short> arr[city];
    char tempArr[city];
    for(i = 0; i < route; i++) {
        scanf("%hd %hd",&city1,&city2);
        arr[city1].push_back(city2);
        arr[city2].push_back(city1);
    }

    short plans,planson;
    bool flag;
    scanf("%hd",&plans);
    for(i = 0; i < plans; i++) {
        scanf("%hd",&planson);
        flag = true;
        memset(tempArr,0,city);

        for(j = 0;j < planson; j++) {
            scanf("%d",&city1);
            if(city1 <= 0 || city1 >= city) {
                continue;
            }
            tempArr[city1] = 1;
        }

        for(j = 1; j < city; j++) {
            len = arr[j].size();
            for(k = 0; k < len; k++) {
                if(tempArr[j] == 0 && tempArr[arr[j][k]] == 0) {
                    flag = false;
                    break;
                }
            }
            if(!flag) {
                break;
            }
        }

        if(flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}