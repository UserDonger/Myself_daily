#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>

/*
key_t ftok(const char *pathname, int proj_id);
功能：通过文件名和目标值共同创造一个键值并返回值
参数：
    pathname：任意一个文件名（文件名或者目录名）
    proj_id：目标值，范围一般是0~127
返回值：
    成功：键值
    失败：‐1
如果使用ftok函数获取键值，得到的键值是由ftok的第一个
参数对应文件的信息和第二个参数一起决定的
*/

int main(int argc, char *argv[])
{
    //使用ftok()函数获取键值
    //只要保证ftok的第一个参数对应的文件和第二个参数值相同，
    //则不管程序运行多少遍或者多少个进程或者键值，键值一定都是唯一的
    key_t mykey;
    if((mykey = ftok(".", 100)) == -1)
    {
        perror("fail to ftok");
        exit(1);
    }

    printf("key = %#x\n", mykey);

    return 0;

}