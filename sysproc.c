#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
int
sys_fork(void)
{
return fork();
}
int
sys_exit(void)
{
exit();
return 0; // not reached
}
int
sys_wait(void)
{
return wait();
}
int
sys_kill(void)
{
int pid;
if(argint(0, &pid) < 0)
return -1;
return kill(pid);
}
int
sys_getpid(void)
{
return myproc()->pid;
}
int
sys_sbrk(void)
{
int addr;
int n;
if(argint(0, &n) < 0)
return -1;
addr = myproc()->sz;
if(growproc(n) < 0)
return -1;
return addr;
}
int
sys_sleep(void)
{
int n;
uint ticks0;
if(argint(0, &n) < 0)
return -1;
acquire(&tickslock);
ticks0 = ticks;
while(ticks - ticks0 < n)
{
if(myproc()->killed)
{
release(&tickslock);
return -1;
}
sleep(&ticks, &tickslock);
}
release(&tickslock);
return 0;
}
// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
uint xticks;
acquire(&tickslock);
xticks = ticks;
release(&tickslock);
return xticks;
}
// return the year of which Unix version 6 was released
int
sys_getyear(void)
{
return 1975;
}
// sum
int sys_sum(void) {
int num1, num2;
argptr(0, (void *)&num1, sizeof(num1));
argptr(1, (void *)&num2, sizeof(num2));
return num1+num2;
}
// difference
int sys_diff(void) {
int num1, num2;
argptr(0, (void *)&num1, sizeof(num1));
argptr(1, (void *)&num2, sizeof(num2));
return num1-num2;
}
// multiply
int sys_mul(void) {
int num1, num2;
argptr(0, (void *)&num1, sizeof(num1));
argptr(1, (void *)&num2, sizeof(num2));
return num1*num2;
}
// divide
int sys_div(void) {
int num1, num2;
argptr(0, (void *)&num1, sizeof(num1));
argptr(1, (void *)&num2, sizeof(num2));
return num1/num2;
}
// remainder
int sys_rem(void) {
int num1, num2;
argptr(0, (void *)&num1, sizeof(num1));
argptr(1, (void *)&num2, sizeof(num2));
return num1%num2;
}
// square
int sys_square(void) {
int num;
argptr(0, (void *)&num, sizeof(num));
return num*num;
}
// cube
int sys_cube(void) {
int num;
argptr(0, (void *)&num, sizeof(num));
return num*num*num;
}







