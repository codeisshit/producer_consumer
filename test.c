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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


static struct task_struct *kthread_1;
static task_struct *task;


static int producer(pointerForTaskthing, Buffer){
	printk(KERN_INFO "this is printed from producer function");
	for_each_process(taskPointer){
		printk(KERN_INFO "task: \n",task->pid);
		printk(KERN_INFO "val: \n",task->cred->uid.val);
	}
	return 0;
}


//struct task_struct *thread_run(int (*kthreadfn)(void *data), void *data, const char *namefmt);
static int thread_function(void *dontcare){
	printk(KERN_INFO "this is printed from kthread_func");
	return 0;
}

static int __init init_func(void){
	//producer runs finite long loop

	//consumer runs on infinite long loop
 	return 0;
}

static void __exit exit_func(void){
    printk(KERN_INFO "Exiting the module\n");
}

module_init(init_func);
module_exit(exit_func);


MODULE_LICENSE("GPL");