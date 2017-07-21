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
 * @file bal_api.h
 * @brief Function declarations and all inclusions required for the BAL Public API
 *
 * @defgroup api BAL Public API
 */
#ifndef BCMBAL_API_H
#define BCMBAL_API_H

#include <bcmos_system.h>
#include <bal_osmsg.h>
#include <bal_objs.h>

/*@{*/

/** BAL Indication callback handler function prototype */
typedef void (*f_bcmbal_ind_handler)(bcmbal_obj *obj);


/** BAL Indication callback registration parameters */
typedef struct bcmbal_cb_cfg
{
    bcmbal_obj_id           obj_type; 	        /**< Object type */
    bcmbal_object_key_info  *p_object_key_info; /**< Pointer to object key info (NULL=don't care) */
    uint16_t                *p_subgroup;        /**< Pointer to subgroup (NULL=don't care) */    
    f_bcmbal_ind_handler    ind_cb_hdlr;        /**< Indication callback function. NULL=unregister */
    bcmos_module_id         module;             /**< Target module id.
                                                  If it is BCMOS_MODULE_ID_NONE (0), the callback will be called
                                                  in BAL's context. Otherwise, it will be called in application
                                                  module's context */
    uint32_t                access_term_id;     /**< Access terminal Id for which this Ind subscription applies */
} bcmbal_cb_cfg;

/*
 *------------------------------------------------------------------------------------------
 *
 * @brief The BAL Public API
 *
 *------------------------------------------------------------------------------------------
 */

/**
 * @brief BAL Public API Set (or modify) command.
 *
 * Set (or modify) the specified object instance (with implicit creation
 * of dynamic objects) associated with the specified access-terminal device.
 *
 * @param access_term_id  access terminal Id
 * @param objinfo A pointer to a BAL object
 *
 * @returns bcmos_errno
 *
 **/
bcmos_errno bcmbal_cfg_set(bcmbal_access_term_id access_term_id, bcmbal_cfg *objinfo);

/**
 * @brief BAL Public API Get command.
 *
 * Get the specified object instance
 *
 * @param access_term_id  access terminal Id
 * @param objinfo A pointer to a BAL object
 *
 * @returns bcmos_errno
 *
 */
bcmos_errno bcmbal_cfg_get(bcmbal_access_term_id access_term_id, bcmbal_cfg *objinfo);

/**
 * @brief BAL Public API Packet Send function.
 *
 * Send a packet to the specified destination
 *
 * @param access_term_id  access terminal Id
 *
 * @param dest    The destination of the user packet
 *
 * @param packet_to_send A pointer to the user packet to send to the specified destination
 *
 * @param packet_len The length of the  user packet (must be <=1600 bytes)
 *
 * @returns bcmos_errno
 *
 */
bcmos_errno bcmbal_pkt_send(bcmbal_access_term_id access_term_id, 
                            bcmbal_dest dest,
                            const char *packet_to_send,
                            uint16_t packet_len);

/**
 * @brief BAL Public API Clear command.
 *
 * Set all attributes to default (or remove the object instance for
 * dynamic objects) for the specified object instance
 *
 * @param access_term_id  access terminal Id
 * @param objinfo A pointer to a BAL object
 *
 * @returns bcmos_errno
 *
 */
bcmos_errno bcmbal_cfg_clear(bcmbal_access_term_id access_term_id, bcmbal_cfg * objinfo);

/**
 * @brief BAL Public API Get Stats command.
 *
 * Get (and clear) the stats associated with specified object instance
 *
 * @param access_term_id  access terminal Id
 * @param objinfo A pointer to a BAL object
 * @param clear_on_read  clear the counter after the rad operation
 *
 * @returns bcmos_errno
 *
 */
bcmos_errno bcmbal_stat_get(bcmbal_access_term_id access_term_id, bcmbal_stat *objinfo, bcmos_bool clear_on_read);

/**
 * @brief BAL Public API indication subscription.
 *
 * Subscription function for the specified indications
 *
 * @param access_term_id  Access terminal Id
 * @param cb_cfg  A pointer to the callback configuration parameters for the
 *                object indications being subscribed to.
 *
 * @returns bcmos_errno
 *
 */
bcmos_errno bcmbal_subscribe_ind(bcmbal_access_term_id access_term_id, bcmbal_cb_cfg *cb_cfg);

/**
 * @brief BAL Public API indication un-subscription.
 *
 * Un-subscription function for the specified (or all) indications
 *
 * @param access_term_id  Access terminal Id
 * @param cb_cfg  A pointer to the callback configuration parameters for the
 *                object indications being un-subscribed from.
 *
 * @returns bcmos_errno
 *
 */
bcmos_errno bcmbal_unsubscribe_ind(bcmbal_access_term_id access_term_id, bcmbal_cb_cfg *cb_cfg);

/*
 * For use in BAL API subscription calls to prepare a cb_cfg structure
 *
 * NOTE: cb_cfg.module must be set outside this function!
 *
 */

#define BCMBAL_IND_SUBSCRIBE_PREPARE(a,b,c,d,e) { (a)->obj_type = b;    \
        (a)->p_subgroup = c;                                            \
        (a)->p_object_key_info = d;                                     \
        (a)->ind_cb_hdlr = e; \
    }


/*
 * For use in BAL API calls, as in:
 * 
 * bcmbal_interface_cfg bal_interface_obj;
 *
 * bcmbal_cfg_set(BCMBAL_OBJ(bal_interface_obj));
 *
 */

#define BCMBAL_OBJ(a) (&((a)->hdr))

/*
 * For use in BAL calls, as in:
 * 
 *    access_terminal_oper_status = BCMBAL_OBJ_ATTR(&access_terminal_obj, oper_status);
 *      
 *      or
 *
 *  BCMBAL_ATTRIBUTE_PROP_SET(&(BCMBAL_OBJ_ATTR(&tm_queue_obj, rate)), tm_shaping, pbr, my_ratelimit.pbr);
 *
 *
 */
#define BCMBAL_OBJ_ATTR(a,b) ((a)->data.b)


#define BCMBAL_OBJ_KEY_INFO(_o, _k) { .key = _k, .key_size = sizeof(bcmbal_ ## _o ## _key) }

#define DEFAULT_ATERM_ID (0)

/*@}*/

#endif /* BCMBAL_API_H */
