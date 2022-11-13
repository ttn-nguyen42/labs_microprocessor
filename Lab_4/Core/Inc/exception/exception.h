/*
 * exception.h
 *
 *  Created on: Nov 13, 2022
 *      Author: ttng
 */
// #include <exception>

// /*
//  * Scheduler queue is full
//  * @related     Mostly due to tasks being added too rapidly
//  */
// class SchedulerFullException : public std::exception {
// public:
//     char* what()
//     {
//         return "Scheduler queue is full";
//     }
// };

// /*
//  * Scheduler timer is missing
//  * @related     Due to the timer being passed in as nullptr when creating scheduler
//  */
// class SchedulerTimerMissingException : public std::exception {
// public:
//     char* what()
//     {
//         return "Scheduler timer is missing";
//     }
// };

// /*
//  * Failed task deletion
//  * @related     Mostly due to provided index is greater than maximum amount of task
//  */
// class SchedulerDeleteInvalidIndex : public std::exception {
// public:
//     char* what()
//     {
//         return "Scheduler deletion provided invalid index";
//     }
// };
