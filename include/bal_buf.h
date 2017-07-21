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
 * @file bal_buf.h
 *
 * @brief Common aliases for BAL
 *
 */
#ifndef BAL_BUF
#define BAL_BUF

#include "bcmolt_buf.h"

typedef bcmolt_buf bcmbal_buf;

#define bcmbal_buf_init(buf, size, start)  bcmolt_buf_init(buf, size, start, BCMOLT_BUF_ENDIAN_FIXED)
#define bcmbal_buf_alloc(buf, size)        bcmolt_buf_alloc(buf, size, BCMOLT_BUF_ENDIAN_FIXED)
#define bcmbal_buf_free                    bcmolt_buf_free
#define bcmbal_buf_skip                    bcmolt_buf_skip
#define bcmbal_buf_set_pos                 bcmolt_buf_set_pos
#define bcmbal_buf_get_used                bcmolt_buf_get_used
#define bcmbal_buf_get_remaining_size      bcmolt_buf_get_remaining_size
#define bcmbal_buf_write                   bcmolt_buf_write
#define bcmbal_buf_read                    bcmolt_buf_read
#define bcmbal_buf_rewind                  bcmolt_buf_rewind
#define bcmbal_buf_write_u8                bcmolt_buf_write_u8
#define bcmbal_buf_read_u8                 bcmolt_buf_read_u8
#define bcmbal_buf_write_u16               bcmolt_buf_write_u16
#define bcmbal_buf_read_u16                bcmolt_buf_read_u16
#define bcmbal_buf_write_s16               bcmolt_buf_write_s16
#define bcmbal_buf_read_s16                bcmolt_buf_read_s16
#define bcmbal_buf_write_u24               bcmolt_buf_write_u24
#define bcmbal_buf_read_u24                bcmolt_buf_read_u24
#define bcmbal_buf_write_u32               bcmolt_buf_write_u32
#define bcmbal_buf_read_u32                bcmolt_buf_read_u32
#define bcmbal_buf_write_s32               bcmolt_buf_write_s32
#define bcmbal_buf_read_s32                bcmolt_buf_read_s32
#define bcmbal_buf_write_u64               bcmolt_buf_write_u64
#define bcmbal_buf_read_u64                bcmolt_buf_read_u64
#define bcmbal_buf_write_bool              bcmolt_buf_write_bool
#define bcmbal_buf_read_bool               bcmolt_buf_read_bool
#define bcmbal_buf_write_mac_address       bcmolt_buf_write_mac_address
#define bcmbal_buf_read_mac_address        bcmolt_buf_read_mac_address
#define bcmbal_buf_write_ipv4_address      bcmolt_buf_write_ipv4_address
#define bcmbal_buf_read_ipv4_address       bcmolt_buf_read_ipv4_address
#define bcmbal_buf_write_ipv6_address      bcmolt_buf_write_ipv6_address
#define bcmbal_buf_read_ipv6_address       bcmolt_buf_read_ipv6_address
#define bcmbal_buf_write_vlan_tag          bcmolt_buf_write_vlan_tag
#define bcmbal_buf_read_vlan_tag           bcmolt_buf_read_vlan_tag

#endif /* BAL_BUF */
