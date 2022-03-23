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


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Scott Snyder");


//need to declare paramters at run time

static short int myshort = 1;

static int uid = 1000;
static int buff_size = 10;
static short int p = 1;
static short int c =2;

module_param(uid, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(buff_size, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(p,short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(c,short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

static int __init producer_consumer_init(void){

  printk(KERN_INFO "my id is: %hd\n", uid);
  printk(KERN_INFO "my buffer size is: %hd\n", buff_size);
  printk(KERN_INFO "prodNum: %hd\n", p);
  printk(KERN_INFO "consNum: %hd\n", c);

  return 0;
}

static void __exit producer_consumer_exit(void){
  printk(KERN_INFO "producer/consumer has been unloaded\n");
}


module_init(producer_consumer_init);
module_exit(producer_consumer_exit);
