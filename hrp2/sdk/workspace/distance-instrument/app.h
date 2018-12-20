/**
 * Common header files
 */
#include "ev3api.h"
#include "target_test.h"

/**
 * Task priorities (smaller number has higher priority)
 */
#define PRIORITY_PRD_TSK_1 (TMIN_APP_TPRI + 1)
// #define PRIORITY_PRD_TSK_2 TMIN_APP_TPRI
#define PRIORITY_PRD_TSK_2 (TMIN_APP_TPRI + 1)
#define PRIORITY_MAIN_TASK TMIN_APP_TPRI

/**
 * Task periods in ms
 */
#define PERIOD_PRD_TSK_1  (100)
//#define PERIOD_PRD_TSK_2  (500)
#define PERIOD_PRD_TSK_2  (100)

/**
 * Default task stack size in bytes
 */
#ifndef STACK_SIZE
#define	STACK_SIZE 4096
#endif

/**
 * Prototypes for configuration
 */
#ifndef TOPPERS_MACRO_ONLY

extern void	main_task(intptr_t);
extern void periodic_task_1(intptr_t);
extern void periodic_task_2(intptr_t);

extern void task_activator(intptr_t tskid);

#endif /* TOPPERS_MACRO_ONLY */

