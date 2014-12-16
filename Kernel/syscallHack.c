
/*
* syscallHack.c
* Kernel module to redirect system calls.
* Victor Hugo Erminpour
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>  /* task_struct */
#include <asm-mips/unistd.h>  /* __NR_* (syscall #defines) */
#include <asm-mips/current.h>  /* current (task_struct) */
#include <linux/dcache.h>  /* dentry */
#include <linux/fs.h>  /* dentry */

#define MODULE_NAME "syscallHack"

static unsigned long **systemCallTable;

long (*original_open)(const char * filename, int flags, int mode);
ssize_t (* original_read)(unsigned int fd, const char * buf, size_t count);
//ssize_t (* original_write)(unsigned int fd, const char * buf, size_t count);

/*
ssize_t hackedWrite(unsigned int fd, const char * buf, size_t count)
{
  1) get the filename through the fd
  2) check to see if filename == /proc/meminfo
  3) get the current task_struct through "current->"
  4) show heap start and end values
  5) show where buf is pointing to
  6) if buff's address intersects the heap's address, let the user know
}
*/

size_t hackedRead(unsigned int fd, char * buf, size_t count)
{
  size_t retval;

  /* get dentry via the current task_struct's file descriptor */
  /* what can go wrong, right? */
  struct file *myFile = current->files->fd[fd];
  struct dentry *my_dentry = myFile->f_dentry;

  /* if open() called on "meminfo" */
  if (!strcmp(my_dentry->d_name.name, "meminfo"))
  {
    struct task_struct *task;

    printk(KERN_ALERT "read() called on '%s' by %s[%d]\n", my_dentry->d_name.name, current->comm, current->pid);
    printk(KERN_ALERT "\t%s[%d] UID: %i\n", current->comm, current->pid, current->uid);
    printk(KERN_ALERT "\t%s[%d] GID: %i\n", current->comm, current->pid, current->gid);
  //  printk(KERN_ALERT "\t%s[%d] read() Buffer Address: 0x%p\n", current->comm, current->pid, buf);
    printk(KERN_ALERT "\t%s[%d] call trace:\n", current->comm, current->pid);

    /* print call trace all the way to "init" */
    for (task = current; task != &init_task; task = task->p_pptr)
    { 
      printk(KERN_ALERT "%s->", task->comm);
    }
    printk(KERN_ALERT "\n");
  }

 /* return original read() */
 retval = (*original_read)(fd, buf, count);
return retval;
}

long hackedOpen(const char *filename, int flags, int mode)
{
  long retval;

  /* if open() called on "/proc/meminfo" */
  if (!strcmp(filename, "/proc/meminfo"))
  {
    struct task_struct *task;

    printk(KERN_ALERT "open() called on '%s' by %s[%d]\n", filename, current->comm, current->pid);
    printk(KERN_ALERT "\t%s[%d] UID: %i\n", current->comm, current->pid, current->uid);
    printk(KERN_ALERT "\t%s[%d] GID: %i\n", current->comm, current->pid, current->gid);
    printk(KERN_ALERT "\t%s[%d] call trace:\n", current->comm, current->pid);

    /* print call trace all the way to "init" */
    for (task = current; task != &init_task; task = task->p_pptr)
    { 
      printk(KERN_ALERT "%s->", task->comm);
    }
    printk(KERN_ALERT "\n");
  }

  /* return original open() */
  retval = (*original_open)(filename, flags, mode);
return retval;
}

static int syscallHack_init_module(void)
{
  printk(KERN_ALERT "%s: LOADED\n", MODULE_NAME); 

  /* Kids, don't try this at home! :-D */
  /* 0x802b446c == address of sys_call_table[] from System.map */
  systemCallTable=(void *)0x802b446c;

  printk(KERN_ALERT "%s: Redirecting open() systemcall...", MODULE_NAME); 
  original_open = (void *)systemCallTable[__NR_open];
  systemCallTable[__NR_open] = (unsigned long *)&hackedOpen;
  printk(KERN_ALERT "DONE\n"); 

  printk(KERN_ALERT "%s: Redirecting read() systemcall...", MODULE_NAME); 
  original_read = (void *)systemCallTable[__NR_read];
  systemCallTable[__NR_read] = (unsigned long *)&hackedRead;
  printk(KERN_ALERT "DONE\n"); 

return 0;
}

static void syscallHack_exit_module(void)
{
  printk(KERN_ALERT "%s: Replacing open() systemcall...", MODULE_NAME); 
  systemCallTable[__NR_open] = (unsigned long*)original_open;
  printk(KERN_ALERT "DONE\n"); 

  printk(KERN_ALERT "%s: Replacing read() systemcall...", MODULE_NAME); 
  systemCallTable[__NR_read] = (unsigned long*)original_read;
  printk(KERN_ALERT "DONE\n"); 

  printk(KERN_ALERT "%s: EXIT\n", MODULE_NAME); 
}

MODULE_LICENSE("GPL");
module_init(syscallHack_init_module);
module_exit(syscallHack_exit_module);

