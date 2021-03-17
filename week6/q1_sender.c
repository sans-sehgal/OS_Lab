#include<stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

 

struct my_msg{
    long int msg_type;
    int number;
};
int main(){
    int run=1;
    struct my_msg data;
    int msgid;
    msgid=msgget((key_t)1234,0666|IPC_CREAT);
    if(msgid==-1){
        printf("Msgget failed %m\n");
        return 0;
    }
    while(run){
        int n;
        printf("Enter the number to be checked,To quit enter -1:\n");
        scanf("%d",&n);
        data.msg_type=1;
        data.number=n;
        if(msgsnd(msgid,(void*)&data,sizeof(int),0)==-1){
            printf("Message failed\n");
            return 0;
        }
        if(n==-1)
            run=0;
    }
    return 0;
}