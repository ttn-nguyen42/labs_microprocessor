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
    if (m_QueueSize == (SCH_MAX_TASKS - 1)) {
        return SCH_MAX_TASKS;
    }

    bool flag = false;
    int index = 0;

    /*
     * Start from beginning
     * Find an index where the newly added task has a delay smaller than the one existing
     * Along the way, subtract its delay by task (will be) in front of it
     */
    while ((index < m_QueueSize) && (flag == false)) {
        if (delay > m_TaskQueue[index].Delay) {
            delay -= m_TaskQueue[index].Delay;
        } else {
            flag = true;
            m_TaskQueue[index].Delay -= delay;
        }
        index += 1;
    }

    /*
     * Shift the task array to the right
     */
    if (flag) {
        index -= 1;
        for (int b = m_QueueSize; b > index; b -= 1) {
            Task* fromBack = &m_TaskQueue[b];
            Task* infront = &m_TaskQueue[b - 1];
            fromBack->Delay = infront->Delay;
            fromBack->Id = infront->Id;
            fromBack->IsReady = fromBack->IsReady;
            fromBack->pCallback = fromBack->pCallback;
            fromBack->Period = fromBack->Period;
        }
    }
    Task* newTaskPlacement = &m_TaskQueue[index];
    newTaskPlacement->Delay = delay;
    newTaskPlacement->Id = index;
    newTaskPlacement->IsReady = false;
    newTaskPlacement->pCallback = callback;
    newTaskPlacement->Period = period;

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

    if (!m_TaskQueue[taskIndex].pCallback) {
        return;
    }

    /* Move task to the front */
    for (int i = 0; i < m_QueueSize - 1; i += 1) {
        Task* current = &m_TaskQueue[i];
        Task* next = &m_TaskQueue[i + 1];
        current->Delay = next->Delay;
        current->Id = next->Id;
        current->IsReady = next->IsReady;
        current->pCallback = current->pCallback;
        current->Period = current->Period;
    }
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
    Task* front = &m_TaskQueue[0];
    if (front->IsReady) {
        (*front->pCallback)();
        if (front->Period > 0) {
            AddTask(front->pCallback, front->Delay, front->Period);
        }
        DeleteTask(0);
    }
}

void Scheduler::Update()
{
    /*
     * Update time on the first task
     */
    Task* front = &m_TaskQueue[0];
    if (front->Delay == 0) {
        front->IsReady = true;
        return;
    }
    front->Delay -= 1;
}