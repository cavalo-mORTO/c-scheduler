/* https://www.edn.com/7-steps-to-writing-a-simple-cooperative-scheduler/ */

#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "scheduler.h"
#include "tsk_cfg.h"

int main (void)
{
	static uint32_t tick = 0;						// System tick
	static TaskType *Task_ptr;						// Task pointer
	static uint8_t TaskIndex = 0;					// Task index
	const uint8_t NumTasks = Tsk_GetNumTasks(); 	// Number of tasks
	
	Task_ptr = Tsk_GetConfig();			// Get a pointer to the task configuration
	
	while(1)
	{
		tick = clock();
		
		/* Loop through all tasks. First, run all countinuous tasks. Then,
		if the number of ticks since the last time the tasks was run is
		greater than or equal to the task interval, execute the task.
		*/
		for(TaskIndex = 0; TaskIndex < NumTasks; TaskIndex++)
		{
			if ((tick - Task_ptr[TaskIndex].LastTick) >= Task_ptr[TaskIndex].Interval)
			{
				(*Task_ptr[TaskIndex].Func)();			/* Execute the Task */
				Task_ptr[TaskIndex].LastTick = tick; 	/* Save the last tick the task was ran at. */
			}
		}
	}
}