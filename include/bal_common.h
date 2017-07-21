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
 * @file bal_common.h
 *
 * @brief Common include files and miscellaneous macros for the BAL source code.
 *
 */

#ifndef	BALCOMMON_H
#define	BALCOMMON_H

/*@{*/

/* --- system includes ---*/
#include <bcmos_system.h>

/* --- project includes ---*/

/**
 * @brief OUI Identifier
 *  
 */  
typedef uint8_t oui_val_t[3];

/*
 * A max/min function
 */
#define max(a,b) ((a > b) ? a : b)
#define min(a,b) ((a > b) ? b : a)

/**
 *  @brief Maximum value for a VLAN ID
 */
#define MAX_VLAN_ID 4094

/**
 *  @brief Minimum value for an 802.1ah I-SID
 *
 *  Notes from IEEE:
 *      0      - Reserved for use by future amendments to the standard.
 *      1      - Default value, unassigned ISID.
 *      2..FF  - Reserved for use by future amendments to the standard.
 */
#define MIN_8021AH_ISID 0x00000100

/**
 *  @brief Maximum value for an 802.1ah I-SID
 *
 *  Notes from IEEE:
 *      FFFFFF is reserved by IEEE
 */
#define MAX_8021AH_ISID 0x00FFFFFE

/**
 * @brief VLAN TPID definitions
 */
typedef enum vlan_tpid_type
{
    VLAN_TPID_TYPE_DEFAULT = 0x0000,     /**< Simple Bridge - i.e. VID 0, no tagging */
    VLAN_TPID_TYPE_8021Q   = 0x8100,     /**< C-VLAN */
    VLAN_TPID_TYPE_8021AD  = 0x88A8,     /**< S-VLAN */
    VLAN_TPID_TYPE_9100    = 0x9100,     /**< Legacy TPID */
    VLAN_TPID_TYPE_9200    = 0x9200,     /**< Legacy TPID */
    VLAN_TPID_TYPE_9300    = 0x9300,     /**< Legacy TPID */
    VLAN_TPID_TYPE_8021AH_ITAG = 0x88E7  /**< 802.1ah I-Tag TPID */
} vlan_tpid_type;

/**
 * @brief VLAN type definitions
 */
typedef enum vlan_mode_type
{
    VLAN_MODE_NONE,       /**< Neither Shared or L2VPN */
    VLAN_MODE_SHARED,     /**< IP-based shared vlan */
    VLAN_MODE_8021AD_EN,  /**< DPoE 802.1ad (or .1q) encapsulation mode */
    VLAN_MODE_8021AD_TP,  /**< DPoE 802.1ad (or .1q) transport mode */
    VLAN_MODE_8021AH_EN,  /**< DPoE 802.1ah encapsulation mode */
    VLAN_MODE_8021AH_TP,  /**< DPoE 802.1ah transport mode */
    VLAN_MODE_DAC         /**< DPoE DEMARC Auto Configuration */
} vlan_mode;

/**
 * @brief Macro to test if a VLAN is 802.1ad
 */
#define VLAN_IS_8021AD(_vlan_) (((_vlan_)->type == VLAN_MODE_8021AD_EN) || ((_vlan_)->type == VLAN_MODE_8021AD_TP))

/**
 * @brief Macro to test if a VLAN is 802.1ah
 */
#define VLAN_IS_8021AH(_vlan_) (((_vlan_)->type == VLAN_MODE_8021AH_EN) || ((_vlan_)->type == VLAN_MODE_8021AH_TP))

/**
 * @brief Macro to test if a VLAN is L2VPN (as opposed to 'None' or "Shared')
 */
#define VLAN_IS_L2VPN(_vlan_) (VLAN_IS_8021AD(_vlan_) || VLAN_IS_8021AH(_vlan_))

/**
 * @brief Macro to test if a VLAN is DPoE IP-HSD
 */
#define VLAN_IS_DPOE_IPHSD(_vlan_) (((_vlan_)->type == VlanType_None) && ((_vlan_)->dpoeIp.svid != 0) && ((_vlan_)->dpoeIp.cvid != 0))

/**
 * @brief Macro to test if a VLAN is Legacy IP-HSD
 */
#define VLAN_IS_LEGACY_IPHSD(_vlan_) (((_vlan_)->type == VlanType_None) && ((_vlan_)->dpoeIp.svid == 0))

/**
 * @brief Macro to test if a VLAN is DPoE IP-HSD with PON-NNI style tagging
 */
#define VLAN_IS_DPOE_IPHSD_PON_NNI(_vlan_) (VLAN_IS_DPOE_IPHSD(_vlan_) && ((_vlan_)->dot1ad[VLAN_TAG_OUTER].nniTpid != 0))

/**
 * @brief Macro to test if a VLAN is Shared
 */
#define VLAN_IS_SHARED(_vlan_) ((_vlan_)->type == VLAN_MODE_SHARED)

/**
 * @brief 802.1ad VLAN Tag index
 *
 * This enum is used in the VlanT structure to address the outer vs. the inner
 * 802.1ad tag.
 */
typedef enum vlan_tag_index
{
    VLAN_TAG_INDEX_OUTER = 0,  /**< Outer tag, typically the S-VLAN tag */
    VLAN_TAG_INDEX_INNER = 1,  /**< Inner tag, typically the C-VLAN tag */
    VLAN_TAG_INDEX_MAX   = 2
} vlan_tag_index;

/**
 * @brief VlanT structure
 */
typedef struct bcmbal_vlan
{
    vlan_mode    type;     /**< Type of VLAN */

    /** Intra-Chassis Tagging */
    struct
    {
        uint16_t tpid;          /**< ICT TPID */
        uint16_t vid;           /**< ICT VLAN ID */
    } ict;

    /** DPoE IP HSD Tagging */
    struct
    {
        uint16_t svid;          /**< S-TAG VID */
        uint16_t cvid;          /**< C-TAG VID */
    } dpoe_ip;

    /** 802.1ad (and 802.1q) tagging */
    struct
    {
        uint16_t nni_tpid;       /**< VLAN Tag TPID used on the NNI */
        uint16_t uni_tpid;       /**< VLAN Tag TPID used on the UNI */
        uint8_t  cos;           /**< CoS bits used in this VLAN Tag */
        uint16_t vid;           /**< VLAN ID */
    } dot_1ad[VLAN_TAG_INDEX_MAX];

    /** 802.1ah encapsulation info */
    struct
    {
        /** 802.1ah B-MACs */
        bcmos_mac_address bda;   /**< 802.1ah Destination B-MAC */
        bcmos_mac_address bsa;   /**< 802.1ah Source B-MAC */

        /** 802.1ah B-Tag */
        struct
        {
            uint16_t nni_tpid;   /**< B-Tag TPID used on the NNI */
            uint16_t uni_tpid;   /**< B-Tag TPID used on the UNI */
            uint16_t vid;       /**< B-Tag VLAN ID */
        } btag;

        /** 802.1ah I-Tag */
        struct
        {
            uint16_t nni_tpid;   /**< I-Tag TPID used on the NNI */
            uint16_t uni_tpid;   /**< I-Tag TPID used on the UNI */
            uint32_t isid;      /**< I-Tag Service ID */
        } itag;
    } dot_1ah;

    /** L2VPN specific VLAN configuration */
    uint32_t         vpn_idx; /**< Index of L2VPN that link is associated with. */
} bcmbal_vlan;

/**
 * @brief MAC Address key structure.
 *
 * This structure effectively adds a length field to the MacAddressT structure
 * which helps when handling GetNext requests that don't contain a full MAC
 * Address.
 */
typedef struct mac_address_key
{
    bcmos_mac_address mac_addr;  /**< The MAC address */
    uint16_t         len;        /**< The length of the MAC address in the field above */
} mac_address_key;

/**
 * @brief MAC Address length
 */
#define MAC_ADDRESS_LEN 6

/**
 * @brief Converts a MacAddressT structure into a MacAddressKeyT structure.
 */
#define MAC_ADDR_TO_KEY(A, K, L) {              \
        (K)->mac_addr = *(A);                    \
        (K)->len = (L);                         \
    }

/**
 *  @brief Compares the 802.1ad (or q) fields of two VlanT objects
 *
 *  This macro returns '1' if all fields match, and '0' otherwise.
 *
 *  Note, this macro looks at the nniTpid only. This macro is used to determine
 *  whether or not an OLT Domain already exists for a given VLAN (which prevents
 *  configuring duplicate/overlapping OLT domain selectors).
 *
 */
#define VLANS_MATCH_AD(_vlan1_, _vlan2_) (((_vlan1_)->dot1ad[VLAN_TAG_OUTER].vid     == (_vlan2_)->dot1ad[VLAN_TAG_OUTER].vid) && \
                                          ((_vlan1_)->dot1ad[VLAN_TAG_OUTER].nniTpid == (_vlan2_)->dot1ad[VLAN_TAG_OUTER].nniTpid) && \
                                          ((_vlan1_)->dot1ad[VLAN_TAG_INNER].vid     == (_vlan2_)->dot1ad[VLAN_TAG_INNER].vid) && \
                                          ((_vlan1_)->dot1ad[VLAN_TAG_INNER].nniTpid == (_vlan2_)->dot1ad[VLAN_TAG_INNER].nniTpid))

/**
 *  @brief Compares the 802.1ah (mac-in-mac) fields of two VlanT objects
 *
 *  This macro returns '1' if all fields match, and '0' otherwise.
 *
 *  Note, this macro looks at the nniTpid's only. This macro is used to
 *  determine whether or not an OLT Domain already exists for a given VLAN
 *  (which prevents configuring duplicate/overlapping OLT domain selectors).
 *
 */
#define VLANS_MATCH_AH(_vlan1_, _vlan2_) (((_vlan1_)->dot1ah.btag.nniTpid == (_vlan2_)->dot1ah.btag.nniTpid) && \
                                          ((_vlan1_)->dot1ah.btag.vid == (_vlan2_)->dot1ah.btag.vid) && \
                                          ((_vlan1_)->dot1ah.itag.nniTpid == (_vlan2_)->dot1ah.itag.nniTpid) && \
                                          ((_vlan1_)->dot1ah.itag.isid == (_vlan2_)->dot1ah.itag.isid))

/**
 *  @brief Compares the ICT fields of two VlanT objects
 *
 *  This macro returns '1' if all fields match, and '0' otherwise.
 *
 *  Note, this macro looks at the ICT fields only. This macro is
 *  used to determine whether or not an OLT Domain already
 *  exists for a given VLAN (which prevents configuring
 *  duplicate/overlapping OLT domain selectors).
 *
 */
#define VLANS_MATCH_ICT(_vlan1_, _vlan2_) (((_vlan1_)->ict.tpid == (_vlan2_)->ict.tpid) && \
                                           ((_vlan1_)->ict.vid == (_vlan2_)->ict.vid))
/**
 *  @brief Compares the 802.1ad (or q) and 802.1ah (mac-in-mac)
 *         fields of two VlanT objects
 *
 *  This macro returns '1' if all fields match, and '0' otherwise.
 *
 */
#define VLANS_MATCH(_vlan1_, _vlan2_) (VLANS_MATCH_AD(_vlan1_, _vlan2_) && VLANS_MATCH_AH(_vlan1_, _vlan2_))

/**
 *  @brief Macros for setting/clearing bits inside of an integer
 */
#define SET_BIT(x,n)    ((x) |= (1L << (n)))
#define CLR_BIT(x,n)    ((x) &= (~(1L << (n))))
#define BIT_IS_SET(x,n) (((x) >> (n)) & 1)



/**
 *  Static compile time assert used to ensure that enums and associated
 *  character arrays are equal.
 *
 *  Use the BAL_STATIC_ASSERT function in your code to check array sizes
 */
#define _BAL_STATIC_ASSERT_HELPER(expr, msg) (sizeof (struct {unsigned int STATIC_ASSERT__##msg: (expr) ? 1 : -1;} ))

#define BAL_STATIC_ASSERT(expr, msg) extern int (*assert_function__##msg(void)) [_BAL_STATIC_ASSERT_HELPER(expr, msg) ]


/** @brief log print colors */
#define BAL_LOG_COLOR_RED(a) "\033[31m"a"\033[0m"
#define BAL_LOG_COLOR_GREEN(a) "\033[32m"a"\033[0m"
#define BAL_LOG_COLOR_YELLOW(a) "\033[33m"a"\033[0m"
#define BAL_LOG_COLOR_BLUE(a) "\033[34m"a"\033[0m"
#define BAL_LOG_COLOR_BOLD(a) "\033[1m"a"\033[0m"

/*@}*/

#endif /* #ifndef BALCOMMON_H */
