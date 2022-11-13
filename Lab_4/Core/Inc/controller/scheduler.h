/*
 * scheduler.h
 *
 *  Created on: Nov 13, 2022
 *      Author: ttng
 */

#ifndef INC_CONTROLLER_SCHEDULER_H_
#define INC_CONTROLLER_SCHEDULER_H_

class Scheduler {
private:
    /*
     * Rebuild scheduler queue
     *
     * @note Invoked when scheduler is full
     */
    void _UpdateTask();

public:
    Scheduler()
    {
    }

    /*
     * Add new task to the scheduler queue
     *
     * @param int delay     Delay in ticks before task is first executed
     *                      If set to 0, the task is executed immediately
     *
     * @param int period    Interval in ticks between repeated executions of the task
     *                      If set to 0, the task is executed only once
     *
     * @return int index    The task index
     */
    int AddTask(void (*callback)(), int delay, int period);

    /*
     * Removes a task from the scheduler queue
     *
     * @param int taskIndex Index of the task inside the queue
     *                      Given after invoking AddTask()
     */
    int DeleteTask(int taskIndex);

    /*
     * Initialize the scheduler
     *
     * @note Calls in the main()
     */
    void Init();

    /*
     * Invoke execution of tasks
     *
     * @note Calls in the PeriodElapsedCallback()
     */
    void Dispatch();
}

#endif /* INC_CONTROLLER_SCHEDULER_H_ */
