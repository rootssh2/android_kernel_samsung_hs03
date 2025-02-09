/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
*/

 /**********************************************
 * unified_power.h
 * This header file includes:
 * 1. Global configs for unified power driver
 * 2. Global macros
 * 3. Declarations of enums and main data structures
 * 4. Extern global variables
 * 5. Extern global APIs
 **********************************************/
#ifndef MTK_UNIFIED_POWER_MT6739_H
#define MTK_UNIFIED_POWER_MT6739_H

#ifdef __cplusplus
extern "C" {
#endif

#define UPOWER_ENABLE (1)
#define UPOWER_NUM_LARGER (1)

#ifdef CONFIG_MTK_TINYSYS_SSPM_SUPPORT
	#define UPOWER_ENABLE_TINYSYS_SSPM (0)
#else
	#define UPOWER_ENABLE_TINYSYS_SSPM (0)
#endif

/* #define EARLY_PORTING_EEM */		/* for ptp */

/* #define EARLY_PORTING_SPOWER	*/      /* for leakage driver */

/* #define UPOWER_UT */

/* #define UPOWER_PROFILE_API_TIME */

#define UPOWER_RCU_LOCK
#define UPOWER_LOG (0)
#define DISABLE_TP

/* #define UPOWER_L_PLUS */
/* #define UPOWER_L_PLUS_CORE 7 */

/* for unified power driver internal use */
#define UPOWER_OPP_NUM		16

#define UPOWER_DEGREE_0		85
#define UPOWER_DEGREE_1		75
#define UPOWER_DEGREE_2		65
#define UPOWER_DEGREE_3		55
#define UPOWER_DEGREE_4		45
#define UPOWER_DEGREE_5		25
#define NR_UPOWER_DEGREE	6

#define DEFAULT_LKG_IDX		0

#define UPOWER_FUNC_CODE_EFUSE_INDEX 120

#define NR_UPOWER_CSTATES	2	/* only use c0, c1 */

#define UPOWER_C1_VOLT		50000	/* 0.5v */
#define UPOWER_C1_IDX		1	/* idx of c1 in idle_states[][idx] */

#define NR_UPOWER_TBL_LIST	3	/* num of all tables */

/* upower banks */
enum upower_bank {
	UPOWER_BANK_LL,
	UPOWER_BANK_CLS_LL,
	NR_UPOWER_BANK,
};

#define UPOWER_BANK_CLS_BASE UPOWER_BANK_CLS_LL

/* for upower_get_power() to get the target power */
enum upower_dtype {
	UPOWER_DYN,
	UPOWER_LKG,
	UPOWER_CPU_STATES,

	NR_UPOWER_DTYPE,
};

extern unsigned int _mt_cpufreq_get_cpu_level(void);

#ifdef __cplusplus
}
#endif

#endif
