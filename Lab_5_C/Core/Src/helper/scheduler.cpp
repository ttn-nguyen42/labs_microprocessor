/*
 * scheduler.cpp
 *
 *  Created on: Nov 13, 2022
 *      Author: ttng
 */

#include "helper/scheduler.h"

Scheduler::Scheduler()
{
}

int Scheduler::AddTask(void (*callback)(), int delay, int period)
{
    int index = 0;

    /* Find a place for the task */
    while ((m_TaskQueue[index].pCallback != 0) && (index < m_QueueSize)) {
        index += 1;
    }

    if (index == m_QueueSize) {
        m_QueueSize += 1;
    }

    if (m_QueueSize == SCH_MAX_TASKS) {
        return -1;
    }

    Task* atIndex = &m_TaskQueue[index];

    /* Create the task */
    atIndex->pCallback = callback;
    atIndex->Delay = delay / TICK;
    atIndex->Period = period / TICK;
    atIndex->IsReady = false;

    return index;
}

void Scheduler::DeleteTask(int taskIndex)
{
    if (taskIndex >= m_QueueSize) {
        return;
    }

    if (taskIndex >= SCH_MAX_TASKS) {
        return;
    }

    Task* atIndex = &m_TaskQueue[taskIndex];

    if (atIndex->pCallback == nullptr) {
        return;
    }

    /* Reset the task */
    atIndex->pCallback = nullptr;
    atIndex->Delay = 0;
    atIndex->Period = 0;
    atIndex->IsReady = false;
}

void Scheduler::Init()
{
    /*
     * Clear the scheduler queue
     */
    for (int i = 0; i < m_QueueSize; i += 1) {
        this->DeleteTask(i);
    }
}

void Scheduler::Dispatch()
{
    /*
     * Executes the task
     */
    for (int i = 0; i < m_QueueSize; i += 1) {
        Task* atIndex = &m_TaskQueue[i];

        if (atIndex->IsReady) {
            /*
             * Execute the callback
             */
            (*(atIndex->pCallback))();
            atIndex->IsReady = false;
            if (atIndex->Period == 0) {
                /* Is a one-time job, remove from the queue */
                this->DeleteTask(i);
            }
        }
    }
}

void Scheduler::Update()
{
    /*
     * Solely updates the time
     * Called in the interupt
     */
    for (int i = 0; i < SCH_MAX_TASKS; i += 1) {
        Task* atIndex = &m_TaskQueue[i];
        /*
         * If there is a task
         */
        if (atIndex->pCallback) {

            /* If the task is ready to run */
            if (atIndex->Delay == 0) {

                /* Mark the task as ready to be executed */
                atIndex->IsReady = true;

                /* Check if its period is set, then schedule the task again */
                if (atIndex->Period > 0) {
                    atIndex->Delay = atIndex->Period;
                }
            } else {
                /* If the task is not ready, decrement the delay until it is ready */
                atIndex->Delay -= 1;
            }
        }
    }
}