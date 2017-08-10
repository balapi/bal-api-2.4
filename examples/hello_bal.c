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
#include <string.h>
#include <bal_api.h>

static void sample_acc_term_indication_cb(bcmbal_obj *obj);


int main(int argc, char *argv[])
{
    bcmos_errno ret;
    bcmbal_status access_terminal_oper_status;
    bcmbal_access_terminal_cfg access_terminal_obj;
    bcmbal_interface_stat interface_stat_obj;
    bcmbal_cb_cfg cb_cfg = {};
    bcmbal_access_term_id access_term = DEFAULT_ATERM_ID; /* control the zeroeth (and only) access_terminal instance */
    bcmbal_dest destination = {};
    bcmbal_interface_key interface_key = {};

    const char user_pkt;           /* You need to craft a packet (including L2 header, excluding FSC) */
    uint32_t user_pkt_size;        /* and set the complete packet size (including L2 header, excluding FSC) */

    /* Init BAL */
    ret = bcmbal_init(argc, argv, NULL);

    printf("bcmbal_init function %s\n", (BCM_ERR_OK == ret) ? "successfully executed" : "FAILED!");

    if (BCM_ERR_OK != ret)
        return ret;

    /* Subscribe for access_terminal indications, and handle them
     * in the sample_indication_cb function
     */
    BCMBAL_IND_SUBSCRIBE_PREPARE(&cb_cfg,
                                 BCMBAL_OBJ_ID_ACCESS_TERMINAL,
                                 NULL,
                                 NULL,
                                 sample_acc_term_indication_cb);

    ret = bcmbal_subscribe_ind(access_term, &cb_cfg);

    printf("bcmbal_subscribe_ind function %s\n", (BCM_ERR_OK == ret) ? "successfully executed" : "FAILED!");

    /* A single access_terminal is supported at this time, so
     * the key value is not relevant
     */
    bcmbal_access_terminal_key access_terminal_key = {};

    /*
     * Initialize the access_terminal structure with the key
     */
    BCMBAL_CFG_INIT(&access_terminal_obj, access_terminal, access_terminal_key);
    BCMBAL_CFG_PROP_SET(&access_terminal_obj, access_terminal, admin_state, BCMBAL_STATE_UP);
    ret = bcmbal_cfg_set(access_term, BCMBAL_OBJ(&access_terminal_obj));

    printf("bcmbal_cfg_set function %s\n", (BCM_ERR_OK == ret) ? "successfully executed" : "FAILED!");

    /*
     * Initialize the access_terminal structure and indicate
     * that we want to fetch the oper status
     */
    BCMBAL_CFG_INIT(&access_terminal_obj, access_terminal, access_terminal_key);
    BCMBAL_CFG_PROP_GET(&access_terminal_obj, access_terminal, oper_status);

    /* Retrieve the specified information in the object instance */
    ret = bcmbal_cfg_get(access_term, BCMBAL_OBJ(&access_terminal_obj));

    printf("bcmbal_cfg_get function %s\n", (BCM_ERR_OK == ret) ? "successfully executed" : "FAILED!");

    /* Retrieve the NNI stats (rx_packets only) from the object instance */

    interface_key.intf_id = 1;  /* retrieve stats from interface NNI 1 */
    interface_key.intf_type = BCMBAL_INTF_TYPE_NNI;

    BCMBAL_STAT_INIT(&interface_stat_obj, interface, interface_key);
    BCMBAL_STAT_PROP_GET(&interface_stat_obj, interface, rx_packets);

    /* Retrieve the specified stats but do not clear them */
    ret = bcmbal_stat_get(access_term, BCMBAL_OBJ(&interface_stat_obj), BCMOS_FALSE);

    printf("bcmbal_stat_get function %s\n", (BCM_ERR_OK == ret) ? "successfully executed" : "FAILED!");

    /* Send the packet out to NNI interface 2 */
    destination.type =  BCMBAL_DEST_TYPE_NNI;
    destination.u.nni.intf_id = 2;

    ret = bcmbal_pkt_send(access_term, destination, &user_pkt, user_pkt_size);

    printf("bcmbal_pkt_send to NNI function %s\n", (BCM_ERR_OK == ret) ? "successfully executed" : "FAILED!");

    /* Send the packet out to UNI 1 on ONU 2 on PON 1 */
    destination.type =  BCMBAL_DEST_TYPE_SUB_TERM;
    destination.u.sub_term.sub_term_id = 2;
    destination.u.sub_term.intf_id = 1;
    destination.u.sub_term.sub_term_uni = 1;

    ret = bcmbal_pkt_send(access_term, destination, &user_pkt, user_pkt_size);

    printf("bcmbal_pkt_send to ONU function %s\n", (BCM_ERR_OK == ret) ? "successfully executed" : "FAILED!");

    /* Unsubscribe from indications */
    ret = bcmbal_unsubscribe_ind(access_term, &cb_cfg);

    printf("bcmbal_unsubscribe_ind function %s\n", (BCM_ERR_OK == ret) ? "successfully executed" : "FAILED!");

    /* Cleanup BAL */
    ret = bcmbal_finish();

    printf("bcmbal_finish function %s\n", (BCM_ERR_OK == ret) ? "successfully executed" : "FAILED!");

    return (BCM_ERR_OK == ret) ? 0 : -1;
}

static void sample_acc_term_indication_cb(bcmbal_obj *obj)
{
    /* TO-DO - add your access_terminal indication
     * handler code here
     */
    return;
}

