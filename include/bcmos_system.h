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
 * @file bcmos_system.h
 * @brief The file provides a FAKE stub for bcmos_system.h
 *
 */
#ifndef BCMOS_SYSTEM_H
#define BCMOS_SYSTEM_H

/** BCM68620 module (FAKE)
 * \ingroup system_module
 */
typedef enum
{
    BCMOS_MODULE_ID_NONE,                       /**< no module */
}bcmos_module_id;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;

typedef _Bool bcmos_bool;

#define BCMOS_ETH_ALEN   6

/** MAC address */
typedef struct
{
    uint8_t u8[BCMOS_ETH_ALEN];
} bcmos_mac_address;

/** IPv4 address. It is stored in network byte order. */
typedef union
{
    uint32_t u32;
    uint8_t u8[4];
} bcmos_ipv4_address;

/** IPv6 address */
typedef uint8_t bcmos_ipv6_address[16];

#define BCMOS_TRUE 1
#define BCMOS_FALSE 0

typedef enum
{
    BCMOS_ENDIAN_BIG_E          = 0,
    BCMOS_ENDIAN_LITTLE_E       = 1,
} bcmos_endian;

#define __PACKED_ATTR_START__
#define __PACKED_ATTR_END__ __attribute__ ((packed))

/** 24-bit unsigned integer */
typedef union
{
    uint8_t u8[3];
    struct __PACKED_ATTR_START__
    {
        uint8_t low;
        uint8_t mid;
        uint8_t hi;
    } __PACKED_ATTR_END__ low_hi;
} uint24_t;

/** VLAN tag (CoS/CFI/VID) */
typedef uint16_t bcmos_vlan_tag;

/** FAKE Message header for compilation */
typedef struct bcmos_msg
{
    int foo;
}bcmos_msg;

/** FAKE semaphore for complilation */
typedef struct bcmos_sem
{
    int sem;
}bcmos_sem;

typedef void (* bcmbal_exit_cb)(void);

#endif /* BCMOS_SYSTEM_H */
