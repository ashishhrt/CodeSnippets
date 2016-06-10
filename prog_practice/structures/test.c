//TEST programs for structure
#include<stdio.h>
#include<string.h>

struct book{
		int num;
		char mess1[50];
		char mess2[50];
		struct book *p;
	};

int main(void){
	//char str[] = "Hey this is cool";
	struct book m[2] ={
		{1,"hehehe","terigaand"},
		{2,"ye to chuspa hai","aree bhai"}
	};
	m[0].p = &m[1];
	m[1].p = &m[0];
	int i = 0;
	//m.num = 1;
	//strcpy(m.mess1, "If all that you have is hammer");
	//strcpy(m.mess2, "Everything looks like a nail");
	//m.mess1 = "hello";
	//m.mess2 = "ki fayda";
	//ptr = &m;
	for(i = 0; i < 2; i++){
		printf("%d\t%s\t%s\n",m[i].p->num,m[i].p->mess1,m[i].p->mess2);
	}
	//printf("%c\n",5["Markvariable"]);
	//printf("%c\t%s\t%p\t%p\n",str[2],&str[2],str,&str);

	//printf("%d\t%s\t%s\n",(*ptr).num,(*ptr).mess1,(*ptr).mess2);
	//printf("%d\t%s\t%s\n",m.num,m.mess1,m.mess2);

	return 0;
}