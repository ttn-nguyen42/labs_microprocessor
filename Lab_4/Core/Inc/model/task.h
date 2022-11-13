/*
 * task.h
 *
 *  Created on: Nov 13, 2022
 *      Author: Nguyen Tran
 */

typedef struct {
    /*
     * The actual work of the task
     */
    void (*pCallback)() = nullptr;

    /*
     * Delay in ticks until the function will be run
     */
    int Delay = 0;

    /*
     * Interval between subsequent runs
     */
    int Period = 0;

    /*
     * To mark if the task is ready to run
     */
    bool IsReady = false;

    /*
     * Task ID
     */
    int Id;
} Task;