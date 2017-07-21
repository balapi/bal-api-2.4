/******************************************************************************
 *
 *  <:copyright-BRCM:2017:DUAL/GPL:standard
 *  
 *     Copyright (c) 2017 Broadcom
 *     All Rights Reserved
 *  
 *  Unless you and Broadcom execute a separate written software license
 *  agreement governing use of this software, this software is licensed
 *  to you under the terms of the GNU General Public License version 2
 *  (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
 *  with the following added to such license:
 *  
 *     As a special exception, the copyright holders of this software give
 *     you permission to link this software with independent modules, and
 *     to copy and distribute the resulting executable under terms of your
 *     choice, provided that you also meet, for each linked independent
 *     module, the terms and conditions of the license of that module.
 *     An independent module is a module which is not derived from this
 *     software.  The special exception does not apply to any modifications
 *     of the software.
 *  
 *  Not withstanding the above, under no circumstances may you combine
 *  this software in any way with any other Broadcom software provided
 *  under a license other than the GPL, without Broadcom's express prior
 *  written consent.
 *  
 *  :>
 *
 *****************************************************************************/
 
/**
 * @file bal_osmsg.h
 * @brief BAL Message data structure definitions
 *
 */
#ifndef BAL_OSMSG_H_
#define BAL_OSMSG_H_
/*
 * Message structures.
 * Going to be generated from object model and moved elsewhere
 */

/* BAL subsystem */
typedef enum
{
    BAL_SUBSYSTEM_CORE,
    BAL_SUBSYSTEM_MAC_UTIL,
    BAL_SUBSYSTEM_SWITCH_UTIL,
    BAL_SUBSYSTEM_PUBLIC_API,

    BAL_SUBSYSTEM__NUM_OF
} bal_subsystem;


__attribute__ ((unused)) static const char *subsystem_str[] =
{
    "BAL Core",
    "BAL Mac Util",
    "BAL Switch Util",
    "BAL Public API"
};

/** BAL OS message
 * \ingroup system_msg
 */
typedef enum
{
    BCMOS_MSG_ID__BEGIN,

    /* Messages used internally by OS abstraction. Do not touch */
    BCMOS_MSG_ID_INTERNAL_TIMER,            /**< Internal "timer message" type */
    BCMOS_MSG_ID_INTERNAL_EVENT,            /**< Internal "event message" type */
    BCMOS_MSG_ID_INTERNAL_IPC,

    /* Application messages */
    BCMOS_MSG_ID_IPC_PING,                  /*** Inter-process communication ping */

    /* Core/Switch util messages */
    BCMBAL_SWITCH_UTIL_MSG,

    /* Core/Mac util messages */
    BCMBAL_MAC_UTIL_MSG,

    /* Core<->Public API messages */
    BCMBAL_MGMT_MSG,

    /* Core->Public API indication messages (both auto and "normal") */
    BCMBAL_MGMT_API_IND_MSG,

    BCMOS_MSG_ID_EON_PROXY_RX,
    BCMOS_MSG_ID_EON_DESTROY_STATE,

    BCMOS_MSG_ID_EPON_OAM_PROXY_RX,
    BCMOS_MSG_ID_EPON_OAM_TIMEOUT,

	BCMOS_MSG_ID_OMCI_TRANSPORT_SEND,

    BCMOS_MSG_ID__END,
    BCMOS_MSG_ID__FORCE16 = 0x7fff
} bcmos_msg_id;


#endif /* BAL_OSMSG_H_ */
