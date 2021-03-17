#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct my_msg{
    long int msg_type;
    int number;
};

 

int palin(int n){
    int arr[10],i=0;
    while(n>0){
        arr[i++]=n%10;
        n=n/10;
    }
    n=i;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[n-1-i])
            return 0;
    }
    return 1;
}
int main(){
    int running=1;
    int msgid;
    struct my_msg data;
    long int msg_rcv;
    msgid=msgget((key_t)1234,0666|IPC_CREAT);
    if(msgid==-1){
        printf("msgget failed\n");
        return 0;
    }
    while(running){
        if(msgrcv(msgid,(void*)&data,sizeof(int),msg_rcv,0)==-1){
            printf("msgrcv failed %m\n");
            return 0;
        }
        if(data.number==-1)
            return 0;
        if (palin(data.number))
            printf("%d is Palindrome\n",data.number);
        else
            printf("%d is not a Palindrome\n",data.number);
    }
    return 0;
}