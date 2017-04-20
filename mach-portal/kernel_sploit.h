#ifndef _KERNEL_SPLOIT_H
#define _KERNEL_SPLOIT_H

#include <mach/mach.h>

mach_port_t get_task_port(mach_port_t host_priv, uint32_t* kernel_base, uint32_t* realhost);

#endif
