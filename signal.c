//信号替换动作的修改
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    void sigcb(int signo)
    {
        printf("recv a signo:%d\n",signo);
        signal(signo,SIG_DFL);//将信号的处理方式还原成默认方式
    }
    //sighandler_t signal(int signum,sighandler_t handler);
    //signal(SIGINT,SIG_IGN);
    
    //int sigaction(int signum,const struct sigaction *act,struct sigaction *oldact);
    struct sigaction new_act,old_act;
    new_act.sa_flags=0;
    new_act.sa_handler=sigcb;
    //int sigemptyset(sigset_t *set);
    //清空set信号集合
    sigemptyset(&new_act.sa_mask);
    //sigaction使用new_act替换2号信号的处理动作，将原有动作保存到old_act中
    sigaction(SIGINT,&new_act,&old_act);

    while(1)
    {
        printf("hello~~~\n");
        sleep(5);
    }



    return 0;
}
