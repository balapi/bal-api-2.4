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
 
#ifndef _BAL_MSG_TYPE_H_
#define _BAL_MSG_TYPE_H_

/*
 *  * The BAL message subtype
 *   */
typedef enum
{
    BAL_MSG_TYPE_REQ,
    BAL_MSG_TYPE_RSP,
    BAL_MSG_TYPE_ACK,
    BAL_MSG_TYPE_IND,      /**< An INDication message generated as a part of a protocol exchange  */
    BAL_MSG_TYPE_AUTO_IND, /**< An asynchronous autonomous INDication message  */
} bcmbal_msg_type;

static __attribute__ ((unused)) char *bcmbal_msg_t_str[] = 
{
    "BAL_MSG_REQ",
    "BAL_MSG_RSP",
    "BAL_MSG_ACK",
    "BAL_MSG_IND",         /**< An INDication message generated as a part of a protocol exchange  */
    "BAL_MSG_AUTO_IND"     /**< An asynchronous autonomous INDication message  */
};


#endif
