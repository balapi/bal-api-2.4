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
#include <stdio.h>
#include <bal_api.h>

bcmos_errno bcmbal_init(int argc, char *argv[], bcmbal_exit_cb exit_cb)
{
    /*
     * Keep the caller happy
     */
    return BCM_ERR_OK;
}

bcmos_errno bcmbal_finish(void)
{
    return BCM_ERR_OK;
}


bcmos_errno bcmbal_cfg_set(bcmbal_access_term_id access_term_id, bcmbal_cfg *objinfo)
{
    return BCM_ERR_OK;
}

bcmos_errno bcmbal_cfg_get(bcmbal_access_term_id access_term_id, bcmbal_cfg *objinfo)
{
    return BCM_ERR_OK;
}

bcmos_errno bcmbal_pkt_send(bcmbal_access_term_id access_term_id,
                            bcmbal_dest dest,
                            const char *packet_to_send,
                            uint16_t packet_len)
{
    return BCM_ERR_OK;    
}

bcmos_errno bcmbal_cfg_clear(bcmbal_access_term_id access_term_id, bcmbal_cfg * objinfo)
{
    return BCM_ERR_OK;    
}

bcmos_errno bcmbal_stat_get(bcmbal_access_term_id access_term_id, bcmbal_stat *objinfo, bcmos_bool clear_on_read)
{
    return BCM_ERR_OK;    
}

bcmos_errno bcmbal_subscribe_ind(bcmbal_access_term_id access_term_id, bcmbal_cb_cfg *cb_cfg)
{
    return BCM_ERR_OK;    
}

bcmos_errno bcmbal_unsubscribe_ind(bcmbal_access_term_id access_term_id, bcmbal_cb_cfg *cb_cfg)
{
    return BCM_ERR_OK;    
}
