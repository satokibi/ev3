#include <kernel.h>
#include "common/module_common.h"
#include "target_config.h"
#include "platform_interface_layer.h"
#include "csl.h"
#include "chip_timer.h"
#include "syssvc/syslog.h"
#include "syssvc/banner.h"
#include "target_serial.h"
#include "target_serial_dbsio.h"
#include "syssvc/serial.h"
#include "syssvc/logtask.h"
#include "api.cfg.h"
#include "app.h"

ID _module_id_APP_INIT_TASK __attribute__((section (".module.text")));
static STK_T _module_ustack_APP_INIT_TASK[COUNT_STK_T(STACK_SIZE)];

ID _module_id_MAIN_TASK __attribute__((section (".module.text")));
static STK_T _module_ustack_MAIN_TASK[COUNT_STK_T(STACK_SIZE)];

ID _module_id_PRD_TSK_1 __attribute__((section (".module.text")));
static STK_T _module_ustack_PRD_TSK_1[COUNT_STK_T(STACK_SIZE)];

ID _module_id_PRD_TSK_2 __attribute__((section (".module.text")));
static STK_T _module_ustack_PRD_TSK_2[COUNT_STK_T(STACK_SIZE)];

static const T_CTSK _module_ctsk_tab[4] = {
	{ TA_ACT, 0, _app_init_task, TPRI_APP_INIT_TASK, ROUND_STK_T(STACK_SIZE), _module_ustack_APP_INIT_TASK, DEFAULT_SSTKSZ, NULL },
	{ TA_ACT, 0, main_task, PRIORITY_MAIN_TASK, ROUND_STK_T(STACK_SIZE), _module_ustack_MAIN_TASK, DEFAULT_SSTKSZ, NULL },
	{ TA_NULL, 0, periodic_task_1, PRIORITY_PRD_TSK_1, ROUND_STK_T(STACK_SIZE), _module_ustack_PRD_TSK_1, DEFAULT_SSTKSZ, NULL },
	{ TA_NULL, 0, periodic_task_2, PRIORITY_PRD_TSK_2, ROUND_STK_T(STACK_SIZE), _module_ustack_PRD_TSK_2, DEFAULT_SSTKSZ, NULL },
};

ID _module_id_DTQ_1 __attribute__((section (".module.text")));

static const T_CPDQ _module_cpdq_tab[1] = {
	{ TA_NULL, 256, 8, NULL },
};

const SIZE _module_cfg_entry_num = 5;

const MOD_CFG_ENTRY _module_cfg_tab[5] = {
	{ TSFN_CRE_TSK, &_module_ctsk_tab[0], &_module_id_APP_INIT_TASK },
	{ TSFN_CRE_TSK, &_module_ctsk_tab[1], &_module_id_MAIN_TASK },
	{ TSFN_CRE_TSK, &_module_ctsk_tab[2], &_module_id_PRD_TSK_1 },
	{ TSFN_CRE_TSK, &_module_ctsk_tab[3], &_module_id_PRD_TSK_2 },
	{ TSFN_CRE_PDQ, &_module_cpdq_tab[0], &_module_id_DTQ_1 },
};

const uint32_t _module_pil_version = PIL_VERSION;
