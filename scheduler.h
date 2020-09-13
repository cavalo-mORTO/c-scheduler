/*
TaskType is used to define the parameters required in order to
configure a task and execute it.
*/

typedef struct
{
	uint16_t Interval;			/* Defines how often a task will run */
	uint32_t LastTick;			/* Stores the last tick task was run */
	void (*Func) (void);		/* Function pointer to the task */
} TaskType;