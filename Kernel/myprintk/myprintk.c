
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init myprintk_init(void)
{
    /* 
     * System.map or /proc/kallsyms provides addresses
     * Need to be root to see addresses
     * normal users see zeros.
     * # cat /proc/kallsyms | grep "T printk"
     * ffffffff8153fb99 T printk
     */
    int (*myprintk)(const char *fmt, ...) = (int (*)() ) 0xffffffff8153fb99;

    printk(KERN_INFO "&printk (%p)\n", &printk);
    myprintk(KERN_INFO "&myprintk (%p)\n", &myprintk);
    myprintk(KERN_INFO "&*myprintk (%p)\n", &*myprintk);
    return 0;
}

static void __exit myprintk_exit(void)
{
}

module_init(myprintk_init);
module_exit(myprintk_exit);

