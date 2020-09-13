//Constants
#define SYS_TICK_INTERVAL   1000UL
#define INTERVAL_0MS        0
#define INTERVAL_10MS       (10000UL / SYS_TICK_INTERVAL)
#define INTERVAL_50MS       (50000UL / SYS_TICK_INTERVAL)
#define INTERVAL_100MS      (100000UL / SYS_TICK_INTERVAL)

uint8_t Tsk_GetNumTasks();
TaskType *Tsk_GetConfig();

void Tsk(void);
void Tsk_10ms(void);
void Tsk_100ms(void);

/*
Task configuration table. Holds the task interval, last time executed, and
the function to be executed. A continuous task is defined as a task with
an interval of 0. Last time executed is set to 0.
*/

static TaskType Tasks[] =
{
	{INTERVAL_0MS	, 0, Tsk		},
	{INTERVAL_10MS	, 0, Tsk_10ms	},
	{INTERVAL_100MS	, 0, Tsk_100ms	},
};