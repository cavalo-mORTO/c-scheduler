#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "scheduler.h"
#include "tsk_cfg.h"

uint8_t Tsk_GetNumTasks()
{
	return sizeof Tasks / sizeof *Tasks;
}

TaskType *Tsk_GetConfig()
{
	return Tasks;
}

void Tsk(void)
{
	printf("I'm Tsk\n");
}

void Tsk_10ms(void)
{
	printf("I'm Tsk_10ms\n");
}

void Tsk_100ms(void)
{
	printf("I'm 100ms\n");
}