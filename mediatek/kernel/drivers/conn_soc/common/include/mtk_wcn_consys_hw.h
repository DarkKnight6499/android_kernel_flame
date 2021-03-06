/*! \file
    \brief  Declaration of library functions

    Any definitions in this file will be shared among GLUE Layer and internal Driver Stack.
*/



#ifndef _MTK_WCN_CONSYS_HW_H_
#define _MTK_WCN_CONSYS_HW_H_

#include "osal_typedef.h"
#include "osal.h"
#include <mach/mt_reg_base.h>
#include <mach/sync_write.h>
/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/

/*******************************************************************************
*                                 M A C R O S
********************************************************************************
*/

#define CONSYS_PMIC_CTRL_ENABLE 1
#define CONSYS_ENALBE_SET_JTAG 1
#define CONSYS_WMT_REG_SUSPEND_CB_ENABLE 0
#define CONSYS_USE_PLATFORM_WRITE 1

#define CONSYS_SET_BIT(REG, BITVAL) (*((volatile UINT32*)(REG)) |= ((UINT32)(BITVAL)))
#define CONSYS_CLR_BIT(REG, BITVAL)       ((*(volatile UINT32*)(REG)) &= ~((UINT32)(BITVAL)))
#define CONSYS_CLR_BIT_WITH_KEY(REG, BITVAL, KEY) {\
	UINT32 val = (*(volatile UINT32*)(REG)); \
	val &= ~((UINT32)(BITVAL)); \
	val |= ((UINT32)(KEY)); \
	(*(volatile UINT32*)(REG)) = val;\
}
#define CONSYS_REG_READ(addr) (*((volatile UINT32*)(addr)))
#if CONSYS_USE_PLATFORM_WRITE
#define CONSYS_REG_WRITE(addr,data)  mt65xx_reg_sync_writel(data,addr)
#else
#define CONSYS_REG_WRITE(addr,data)  (*((volatile UINT32*)(addr)) = (UINT32)(data))
#endif

/*connsys register offset define*/


#define TOPCKGEN_BASE INFRA_BASE


#if 1 
	/*top clock gating control register*/
	#define CONSYS_TOP_CLKCG_CLR_REG 		(TOPCKGEN_BASE + 0x00000084)
	#define CONSYS_TOP_CLKCG_SET_REG 		(TOPCKGEN_BASE + 0x00000054)
	#define CONSYS_TOP_CLKCG_BIT 			(0x1 << 26)

	/*SPM clock gating control register*/
	#define CONSYS_PWRON_CONFG_EN_REG 		(SPM_BASE + 0x00000000)
	#define CONSYS_PWRON_CONFG_EN_VALUE 	(0x0b160001)
	#define CONSYS_PWRON_CONFG_DIS_VALUE 	(0x0b160000)
#endif
#define CONSYS_CPU_SW_RST_REG 				(AP_RGU_BASE + 0x00000018)
#define CONSYS_TOP1_PWR_CTRL_REG 			(SPM_BASE + 0x00000280)
#define CONSYS_PWR_CONN_ACK_REG 			(SPM_BASE + 0x0000060c)
#define CONSYS_PWR_CONN_ACK_S_REG 			(SPM_BASE + 0x00000610)

#define CONSYS_WD_SYS_RST_REG 				(TOPCKGEN_BASE + 0x00000018)
#define CONSYS_CHIP_ID_REG 					(CONN_MCU_CONFIG_BASE + 0x00000008)
#define CONSYS_ROM_RAM_DELSEL_REG 			(CONN_MCU_CONFIG_BASE + 0x00000114)
#define CONSYS_MCU_CFG_ACR_REG 				(CONN_MCU_CONFIG_BASE + 0x00000110)
#define CONSYS_AFE_REG 						(CONN_TOP_CR_BASE + 0x00002000)
#define CONSYS_AFE_REG_DIG_RCK_01			(CONSYS_AFE_REG + 0x00000010)
#define CONSYS_AFE_REG_WBG_PLL_02			(CONSYS_AFE_REG + 0x00000028)
#define CONSYS_AFE_REG_WBG_WB_TX_01			(CONSYS_AFE_REG + 0x0000003c)
#define CONSYS_AFE_REG_DIG_RCK_01_VALUE 	(0x174b0160)
#define CONSYS_AFE_REG_WBG_PLL_02_VALUE		(0x844083fe)
#define CONSYS_AFE_REG_WBG_WB_TX_01_VALUE	(0x7fc39a20)

/*CONSYS_CPU_SW_RST_REG*/
#define CONSYS_CPU_SW_RST_BIT 				(0x1 << 12)
#define CONSYS_CPU_SW_RST_CTRL_KEY 			(0x88 << 24)

/*CONSYS_TOP1_PWR_CTRL_REG*/
#define CONSYS_SPM_PWR_RST_BIT 				(0x1 << 0)
#define CONSYS_SPM_PWR_ISO_S_BIT 			(0x1 << 1)
#define CONSYS_SPM_PWR_ON_BIT 				(0x1 << 2)
#define CONSYS_SPM_PWR_ON_S_BIT 			(0x1 << 3)
#define CONSYS_CLK_CTRL_BIT 				(0x1 << 4)
#define CONSYS_SRAM_CONN_PD_BIT 			(0x1 << 8)

/*CONSYS_PWR_CONN_ACK_REG*/
#define CONSYS_PWR_ON_ACK_BIT 				(0x1 << 1)


/*CONSYS_PWR_CONN_ACK_S_REG*/
#define CONSYS_PWR_CONN_ACK_S_BIT 			(0x1 << 1)

/*CONSYS_WD_SYS_RST_REG*/
#define CONSYS_WD_SYS_RST_CTRL_KEY 			(0x88 << 24)
#define CONSYS_WD_SYS_RST_BIT 				(0x1 << 9)

/*CONSYS_MCU_CFG_ACR_REG*/
#define CONSYS_MCU_CFG_ACR_MBIST_BIT 		(0x1 << 18)

/* EMI part mapping & ctrl*/
#define KBYTE								(1024*osal_sizeof(char))
#define CONSYS_EMI_AP_PHY_OFFSET			(0x80000)
#define CONSYS_EMI_AP_PHY_BASE				(0x80080000)
#define CONSYS_EMI_FW_PHY_BASE				(0xf0080000)
#define CONSYS_EMI_MEM_SIZE					(343*KBYTE)
#define CONSYS_EMI_PAGED_TRACE_OFFSET		(0x400)
#define CONSYS_EMI_PAGED_DUMP_OFFSET		(0x8400)
#define CONSYS_EMI_FULL_DUMP_OFFSET			(0x10400)

/*cpupcr*/
#define CONSYS_CPUPCR_REG					(CONN_MCU_CONFIG_BASE + 0x00000160)
/*emi mapping*/
#define CONSYS_EMI_MAPPING					(TOPCKGEN_BASE + 0x1310)


/*control app2cnn_osc_en*/
#define CONSYS_AP2CONN_OSC_EN_REG			(TOPCKGEN_BASE + 0x00001f00)
#define CONSYS_AP2CONN_OSC_EN_BIT			(0x1 << 10)
#define CONSYS_AP2CONN_WAKEUP_BIT			(0x1 << 9)

/*paged dump address start*/
#define CONSYS_PAGED_DUMP_START_ADDR		(0xf0088400)
#define CONSYS_PAGED_DUMP_SIZE				(32*KBYTE)

/*full dump address start*/
#define CONSYS_FULL_DUMP_START_ADDR			(0xf0090400)
#define CONSYS_FULL_DUMP_DLM_LEN			(0x1f000)
#define CONSYS_FULL_DUMP_SYSB2_START		(CONSYS_FULL_DUMP_START_ADDR + CONSYS_FULL_DUMP_DLM_LEN)
#define CONSYS_FULL_DUMP_SYSB2_LEN 			(0x6800)
#define CONSYS_FULL_DUMP_SYSB3_START		(CONSYS_FULL_DUMP_SYSB2_START + CONSYS_FULL_DUMP_SYSB2_LEN)
#define CONSYS_FULL_DUMP_SYSB3_LEN 			(0x16800)

/*force fw assert pattern*/
#define EXP_APMEM_HOST_OUTBAND_ASSERT_MAGIC_W1   (0x19b30bb1)

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/



/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/



/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/
typedef enum _ENUM_EMI_BASE_INDEX_{
	EMI_CTRL_STATE_BASE_INDEX = 0,
	EMI_PAGED_TRACE_BASE_INDEX = 1,
	EMI_PAGED_DUMP_BASE_INDEX = 2,
	EMI_FULL_DUMP_BASE_INDEX = 3,
	EMI_BASE_INDEX_MAX
}ENUM_EMI_BASE_INDEX,*P_ENUM_EMI_BASE_INDEX;

typedef enum _ENUM_EMI_CTRL_STATE_OFFSET_{
	EXP_APMEM_CTRL_STATE = 0x0,
	EXP_APMEM_CTRL_HOST_SYNC_STATE = 0x4,
	EXP_APMEM_CTRL_HOST_SYNC_NUM = 0x8,
	EXP_APMEM_CTRL_CHIP_SYNC_STATE = 0xc,
	EXP_APMEM_CTRL_CHIP_SYNC_NUM = 0x10,
	EXP_APMEM_CTRL_CHIP_SYNC_ADDR = 0x14,
	EXP_APMEM_CTRL_CHIP_SYNC_LEN = 0x18,
	EXP_APMEM_CTRL_CHIP_PRINT_BUFF_START = 0x1c,
	EXP_APMEM_CTRL_CHIP_PRINT_BUFF_LEN = 0x20,
	EXP_APMEM_CTRL_CHIP_PRINT_BUFF_IDX = 0x24,
	EXP_APMEM_CTRL_CHIP_INT_STATUS = 0x28,
	EXP_APMEM_CTRL_CHIP_PAGED_DUMP_END = 0x2c,
	EXP_APMEM_CTRL_HOST_OUTBAND_ASSERT_W1 = 0x30, 
	EXP_APMEM_CTRL_MAX
}ENUM_EMI_CTRL_STATE_OFFSET, *P_ENUM_EMI_CTRL_STATE_OFFSET;

/*******************************************************************************
*                            P U B L I C   D A T A
********************************************************************************
*/



/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/





/*******************************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/



/*******************************************************************************
*                              F U N C T I O N S
********************************************************************************
*/
extern INT32 mtk_wcn_consys_hw_init(VOID);
extern INT32 mtk_wcn_consys_hw_deinit(VOID);
extern INT32 mtk_wcn_consys_hw_pwr_off (VOID);
extern INT32 mtk_wcn_consys_hw_pwr_on (UINT32 co_clock_en);
extern INT32 mtk_wcn_consys_hw_rst (UINT32 co_clock_en);
extern INT32 mtk_wcn_consys_hw_chipid(VOID);
extern INT32 mtk_wcn_consys_hw_bt_paldo_ctrl(UINT32 enable);
extern INT32 mtk_wcn_consys_hw_wifi_paldo_ctrl(UINT32 enable);
extern INT32 mtk_wcn_consys_hw_vcn28_ctrl(UINT32 enable);
extern INT32 mtk_wcn_consys_hw_state_show(VOID);
extern UINT8 *mtk_wcn_consys_emi_base_addr_get(ENUM_EMI_BASE_INDEX emi_addr_index);
extern UINT8 *mtk_wcn_consys_emi_ctrl_state_addr_get(ENUM_EMI_CTRL_STATE_OFFSET ctrl_state_offset);
#if CONSYS_ENALBE_SET_JTAG
extern UINT32 mtk_wcn_consys_jtag_flag_ctrl(UINT32 en);
#endif
#if CONSYS_WMT_REG_SUSPEND_CB_ENABLE
extern UINT32 mtk_wcn_consys_hw_osc_en_ctrl(UINT32 en);
#endif
#endif /* _MTK_WCN_CMB_HW_H_ */

