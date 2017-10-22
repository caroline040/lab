#include "head.h"

int main(void)
{
	key_t key = ftok(KEYPATH, PROJID);
	int msgid = msgget(key, IPC_CREAT | 0666);

	struct msgbuf msg1, msg2;

	while(1){
		bzero(&msg1, sizeof msg1);
		bzero(&msg2, sizeof msg2);

		fgets(msg1.text, MAXSIZE, stdin);
		msgsnd(msgid, &msg1, strlen(msg1.text), J2R);
	}
}
