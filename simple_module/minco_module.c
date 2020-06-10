#include <linux/fs.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

/* 디바이스 파일의 주 번호와 부 번호 */
#define MOD_MAJOR 141
#define MOD_NAME "minco"

static int minco_open(struct inode *inod, struct file *fil)
{
    printk(KERN_INFO "open\n");
    return 0;
}

static int minco_release(struct inode *inod, struct file *fil)
{
    printk(KERN_INFO "release\n");
    return 0;
}

static struct file_operations minco_fops={
    .open = minco_open,
    .release = minco_release,
};

static int minco_init(void)
{
    if(register_chrdev(MOD_MAJOR,MOD_NAME,&minco_fops)<0)
		printk("INIT FAIL\n");
    
    printk(KERN_INFO "minco_init\n");
    return 0;
}

static void minco_exit(void)
{
    unregister_chrdev(MOD_MAJOR, MOD_NAME);
    printk(KERN_INFO "minco_exit\n");
    return;
}

module_init(minco_init);
module_exit(minco_exit);
