/*
 * timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_HELPER_TIMER_H_
#define INC_HELPER_TIMER_H_

#define ONE_SECOND 1000
#define TICK 10

class Timer {
private:
    bool m_Signal = false;
    int m_Duration = 0;
    int m_Remaining = 0;

public:
    Timer();

    /*
     * Reset/Start the timer
     */
    void Start();
    void Reset();

    /*
     * Set the duration
     */
    void Set(int duration);

    /*
     * Used in loops or callbacks to enable timer
     */
    void Breath();

    /*
     * Flag check
     */
    bool HasSignal();
};

#endif /* INC_HELPER_TIMER_H_ */
