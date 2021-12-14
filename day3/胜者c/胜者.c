#include<stdio.h>
int main(){
	int num,sg,gs;
	int sc,gc;
	int i;
	while(scanf("%d",&num) != EOF) {
		sc = gc = 0;
		for(i = 0; i < num; i++) {
			scanf("%d %d",&sg,&gs);
			if(sg > gs) {
				sc++;
			} else if(sg < gs) {
				gc++;
			}
		}
		if(sc > gc) {
			printf("Sg\n");
		} else if(sc < gc) {
			printf("Gs\n");
		} else {
			printf("CONTINUE\n");
		}
	}
}