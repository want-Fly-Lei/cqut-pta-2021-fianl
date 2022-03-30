#include<stdio.h>
#include<stdbool.h>
#define SIZE 10001

int main() {
    int city,route, i, j, k, city1, city2;
    scanf("%d %d",&city,&route);
    ++city;
    //why have two test not pass, because, can not find arr to memroy
    char arr[SIZE][SIZE], tempArr[SIZE][SIZE];
    for(i = 1; i < city; i++) {
        for( j = i; j < city; j++) {
            arr[i][j] = arr[j][i] = tempArr[i][j] = tempArr[j][i] = 0;
        }
    }
    for(i = 0; i < route; i++) {
        scanf("%d %d",&city1,&city2);
        arr[city1][city2] = arr[city2][city1] = 1;
    }

    int plans,planson;
    bool flag;
    scanf("%d",&plans);
    for(i = 0; i < plans; i++) {
        scanf("%d",&planson);
        flag = true;
        
        for(j = 1; j < city; j++) {
            for(k = j + 1; k < city; k++) {
                if(arr[j][k] == 1) {
                    tempArr[j][k] = tempArr[k][j] = 1;
                }
            }
        }

        for(j = 0;j < planson; j++) {
            scanf("%d",&city1);
            if(city1 <= 0 || city1 >= city) {
                continue;
            }
            for(k = 1; k < city; k++) {
                if(tempArr[city1][k] == 1) {
                    tempArr[city1][k] = tempArr[k][city1] = 0;
                }
            }
        }

        for(j = 1; j < city; j++) {
            for(k = j + 1; k < city; k++) {
                if(tempArr[j][k] == 1) {
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