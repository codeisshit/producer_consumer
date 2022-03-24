#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/semaphore.h>
#include <linux/proc_fs.h>
#include <linux/ktime.h>
#include <linux/time.h>
#include <linux/timer.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/list.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Scott Snyder");

static short int myshort = 1;
static int uid = 1000;
static int buff_size = 10;
static short int p = 1;
static short int c =2;

static struct task_struct *prod_thread;
struct task_struct *task;
int count = 0; // this is for counting the processes that we iterate over


//list shittt
struct my_list{
  struct list_head list;
  struct task_struct nextNode;
};

struct my_list new_node;

// mutex_init> sema_init();

//module paramaters that we need to take in
module_param(uid, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(buff_size, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(p,short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(c,short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

//struct task_struct arr_tasks[buff_size];
//int size = sizeof arr_tasks/sizeof arr_tasks[0];


//function where we are adding to the array
int prod_func(void *dontcare ){
  for_each_process(task){

  } 
  return 0; 
}


//function where are are remomving from array and allso calc. time
/*
int cons_func(void *dontcare){
  do{
    wait(full);
    wait(mutex);

    //remove item from buffer

    signal(mutex);
    signal(empty);

    //consume item
  } while(1);

  return 0;
}
*/


static int __init producer_consumer_init(void){
  struct semaphore empty;
  struct semaphore full;
  //struct mutex mymtx;
  //sema_init(&empty,1);
  //sema_init(&full,0);
  //printk(KERN_INFO "SIZE OF ARRAY IS: %hd\n", size);
  printk(KERN_INFO "my id is: %hd\n", uid);
  printk(KERN_INFO "my buffer size is: %hd\n", buff_size);
  printk(KERN_INFO "prodNum: %hd\n", p);
  printk(KERN_INFO "consNum: %hd\n", c);

  //runs the proc thread
  prod_thread = kthread_run(prod_func, NULL, "producer thread");

  //this is used to check to make sure the thread is running
  if(prod_thread != NULL){ 
    printk(KERN_INFO "Producer thread is running now\n");
  } else {
    printk(KERN_INFO "Producer thread could not be created\n");
    return -1;
  }
  return 0;
}

static void __exit producer_consumer_exit(void){
  //need to make sure no threads are waiting for for semaphores
  //i can force the semaphores? if i expect multiple threads waiting on semafores signal it multiple times

  printk(KERN_INFO "producer/consumer has been unloaded\n");
}
//kthread_stop(prod_thread);

module_init(producer_consumer_init);
module_exit(producer_consumer_exit);