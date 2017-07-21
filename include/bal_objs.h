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
 * @file bal_objs.h
 * @brief The file provides an enumeration of all BAL objects
 *
 */
#ifndef BAL_OBJS_H
#define BAL_OBJS_H

#include "bal_common.h"
#include "bal_model_ids.h"
#include "bal_model_types.h"
#include <bal_version.h>

/** \ingroup api
 * @{
 */

static char *bal_obj_str[] =
{
    [bcmbal_obj_id_access_terminal] =     "access_terminal object",
    [bcmbal_obj_id_interface] =           "interface object",
    [bcmbal_obj_id_subscriber_terminal] = "subscriber_terminal object",
    [bcmbal_obj_id_flow] =                "flow object",
    [bcmbal_obj_id_packet] =              "packet object",
    [bcmbal_obj_id_group] =               "group object",
    [bcmbal_obj_id_tm_sched] =            "scheduler object",
    [bcmbal_obj_id_tm_queue] =            "queue object",
};

/* Ensure that the name array size matches the associated enum */
BAL_STATIC_ASSERT (BCMBAL_OBJ_ID__NUM_OF == (sizeof (bal_obj_str) / sizeof (char *)), bcmbal_obj_id);

static inline char *bcmbal_objtype_str(bcmbal_obj_id obj)
{
    return (BCMBAL_OBJ_ID__NUM_OF >= obj) ? bal_obj_str[obj] : "unknown";
}

#define BCMBAL_FLOW_PRIORITY_MAX      65535
#define BCMBAL_FLOW_PRIORITY_MIN      0
#define BAL_FLOW_DEFAULT_PRIORITY     10

/*
 * ------------------------------------------------------------------
 *
 * Internal BCMBAL macros used to manipulate the BAL object elements
 *
 * ------------------------------------------------------------------
 */

/* Initialize request. Internal macro
 * \ingroup api
 * \param[in]   _h      Message header
 * \param[in]   _obj    Object name (i.e. flow)
 * \param[in]   _grp    message type
 * \param[in]   _subgrp message subgroup
 */
#define _BCMBAL_REQ_INIT(_h, _obj, _grp, _subgrp) \
    (_h)->obj_init_val = BCMBAL_OBJ_INIT_VAL; \
    (_h)->om_version = BAL_API_VERSION; \
    (_h)->status = BCM_ERR_OK; \
    (_h)->presence_mask = 0; \
    (_h)->obj_type = bcmbal_obj_id_ ## _obj; \
    (_h)->group = _grp; \
    (_h)->subgroup = _subgrp;

/** Initialize set structure
 * \ingroup api
 * \param[in]   _s      Set structure
 * \param[in]   _obj    Object name (i.e. flow)
 * \param[in]   _key    Object key
 */
#define BCMBAL_CFG_INIT(_s, _obj, _key) \
    do { \
        bcmbal_ ## _obj ## _cfg *_x_ = _s; \
        memset(_x_, 0, sizeof(*_x_)); \
        _BCMBAL_REQ_INIT(&((_x_)->hdr.hdr), _obj, BCMBAL_MGT_GROUP_CFG, 0); \
        (_x_)->key = _key; \
    } while (0)

/** Initialize statistics structure
 * \ingroup api
 * \param[in]   _s      Statistics structure
 * \param[in]   _obj    Object name (i.e. flow)
 * \param[in]   _key    Object key
 */
#define BCMBAL_STAT_INIT(_s, _obj, _key) \
    do { \
        bcmbal_ ## _obj ## _stat *_x_ = _s; \
        memset(_x_, 0, sizeof(*_x_)); \
        _BCMBAL_REQ_INIT(&((_x_)->hdr.hdr), _obj, BCMBAL_MGT_GROUP_STAT, 0); \
        (_x_)->key = _key; \
    } while (0)

/** Initialize set structure
 * \ingroup api
 * \param[in]   _s      Set structure
 * \param[in]   _obj    Object name (i.e. flow)
 * \param[in]   _ind    indication name (i.e. oper_status_change)
 * \param[in]   _key    Object key
 */
#define BCMBAL_IND_INIT(_s, _obj, _ind, _key)  \
    do { \
        bcmbal_ ## _obj ## _ ## _ind *_x_ = _s; \
        memset(_x_, 0, sizeof(*_x_)); \
        _BCMBAL_REQ_INIT(&((_x_)->hdr.hdr), _obj, BCMBAL_MGT_GROUP_AUTO, bcmbal_ ## _obj ## _auto_id_ ## _ind); \
        (_x_)->hdr.hdr.presence_mask = BCMBAL_PRESENCE_MASK_ALL; \
        (_x_)->key = _key; \
    } while (0)

/*
 * For use in indication functions
 */
#define BCMBAL_IND_SUBGROUP(_o, _s) (bcmbal_ ## _o ## _auto_id_ ## _s)


/** Set the memory buffer to use for variable-sized lists within a cfg get
 * \ingroup api
 * \param[in]   _s      Configuration structure
 * \param[in]   _obj    Object type
 * \param[in]   _buf    Pointer to a location in memory in which to store the lists
 * \param[in]   _len    Length of the buffer pointed to by _buf
 */
#define BCMBAL_CFG_LIST_BUF_SET(_s, _obj, _buf, _len) \
    do { \
        bcmbal_ ## _obj ## _cfg *_x_ = _s; \
        _x_->hdr.hdr.list_buf = _buf; \
        _x_->hdr.hdr.list_buf_size = _len; \
    } while (0)

/* Set the object progress state
 * \ingroup api
 * \param[in]   _s      Object structure
 * \param[in]   _p      New object in-progress state: BCMOS_TRUE, or BCMOS_FALSE
 */
#define BCMBAL_OBJ_IN_PROGRESS_SET(_s, _p) ((_s)->hdr.hdr.is_inprogress = _p )

/* Return the object progress state
 * \ingroup api
 * \param[in]   _s      Object structure
 */
#define BCMBAL_OBJ_IN_PROGRESS_GET(_s) ((_s)->hdr.hdr.is_inprogress)

/* Internal macro: Get a bitmask given a property ID enum */
#define BCMBAL_PROP_MASK_GET(_obj, _grp, _p) \
    (bcmbal_ ## _obj ## _grp ## _id_ ## _p == bcmbal_  ## _obj ## _grp ## _id_all_properties ? \
        ((1ULL << (uint64_t)bcmbal_  ## _obj ## _grp ## _id_ ## _p) - 1) : \
        (1ULL << (uint64_t)bcmbal_  ## _obj ## _grp ## _id_ ## _p))


/* Macro: Indicate that configuration property is present - USE WITH CAUTION */
#define BCMBAL_PROP_SET_PRESENT(_m, _obj, _grp, _p) \
    do { \
        (_m)->hdr.hdr.presence_mask |= BCMBAL_PROP_MASK_GET(_obj, _grp, _p); \
    } while (0)

/* Internal macro: Indicate that configuration property is not present */
#define BCMBAL_PROP_CLEAR_PRESENT(_m, _obj, _grp, _p)                   \
    do {                                                                \
        (_m)->hdr.hdr.presence_mask &= ~(BCMBAL_PROP_MASK_GET(_obj, _grp, _p));\
    } while (0)

/* Internal macro: check if property is present */
#define _BCMBAL_PROP_IS_PRESENT(_m, _obj, _grp, _p) \
    (((_m)->hdr.hdr.presence_mask & BCMBAL_PROP_MASK_GET(_obj, _grp, _p)) ? \
        BCMOS_TRUE : BCMOS_FALSE)

/** Set configuration property in message structure
 * \ingroup api
 * \param[in]   _m      Configuration structure
 * \param[in]   _obj    Object type
 * \param[in]   _p      Property name
 * \param[in]   _v      Property value
 */
#define BCMBAL_CFG_PROP_SET(_m, _obj, _p, _v) \
   do { \
       BCMBAL_PROP_SET_PRESENT(_m, _obj, _cfg, _p);\
       (_m)->data._p = (_v);\
   } while (0)

/** Indicate that configuration property should be read
 * \ingroup api
 * \param[in]   _m      Configuration structure
 * \param[in]   _obj    Object type
 * \param[in]   _p      Property name
 */
#define BCMBAL_CFG_PROP_GET(_m, _obj, _p) BCMBAL_PROP_SET_PRESENT(_m, _obj, _cfg, _p)

/** Indicate that all configuration properties should be read
 * \ingroup api
 * \param[in]   _m      Configuration structure
 * \param[in]   _obj    Object type
 */
#define BCMBAL_CFG_ALL_PROP_GET(_m, _obj) ((_m)->hdr.hdr.presence_mask = BCMBAL_PRESENCE_MASK_ALL)

/** clear object property in message structure
 * \ingroup api
 * \param[in]   _m      Object structure pointer
 * \param[in]   _obj    Object name (i.e. flow)
 * \param[in]   _p      Attribute name (i.e. admin_state)
 */
#define BCMBAL_CFG_PROP_CLEAR(_m, _obj, _p)         \
    do { \
        BCMBAL_PROP_CLEAR_PRESENT(_m, _obj, _cfg, _p);        \
        memset(&((_m)->data._p), 0, sizeof((_m)->data._p));    \
    } while (0)

/** Check if configuration property is set in message structure
 * \ingroup api
 * \param[in]   _m      Configuration structure
 * \param[in]   _obj    Object type
 * \param[in]   _p      Property name
 */
#define BCMBAL_CFG_PROP_IS_SET(_m, _obj, _p) _BCMBAL_PROP_IS_PRESENT(_m, _obj, _cfg, _p)

/** Indicate that statistic property should be read
 * \ingroup api
 * \param[in]   _m      Statistics structure
 * \param[in]   _obj    Object type
 * \param[in]   _p      Property name
 */
#define BCMBAL_STAT_PROP_GET(_m, _obj, _p) BCMBAL_PROP_SET_PRESENT(_m, _obj, _stat, _p)

/** Check if statistic property is set in message structure
 * \ingroup api
 * \param[in]   _m      Statistic structure
 * \param[in]   _obj    Object type
 * \param[in]   _p      Property name
 */
#define BCMBAL_STAT_PROP_IS_SET(_m, _obj, _p) _BCMBAL_PROP_IS_PRESENT(_m, _obj, _stat, _p)

/** Set statistic property in message structure
 * \ingroup api
 * \param[in]   _m      Statistic structure
 * \param[in]   _obj    Object type
 * \param[in]   _p      Property name
 * \param[in]   _v      Property value
 */
#define BCMBAL_STAT_PROP_SET(_m, _obj, _p, _v)\
	do { \
       BCMBAL_PROP_SET_PRESENT(_m, _obj, _stat, _p);\
       (_m)->data._p = (_v);\
   } while (0)

/***********************************************************************************
 **
 ** Macros for setting attribute values where an attribute supports a presence_mask
 **
 ***********************************************************************************
 **/

/* Internal macro: Get a bitmask given a attribute element property ID enum */
#define BCMBAL_ATTRIBUTE_PROP_MASK_GET(_attr, _p) bcmbal_ ## _attr ## _id_ ## _p

/* Internal macro: Indicate that configuration property is present */
#define _BCMBAL_ATTRIBUTE_PROP_SET_PRESENT(p_attr, _attr,_p)            \
    do {                                                                \
        (p_attr)->presence_mask |= BCMBAL_ATTRIBUTE_PROP_MASK_GET(_attr, _p); \
    } while (0)

/* Internal macro: Indicate that configuration property is not present */
#define _BCMBAL_ATTRIBUTE_PROP_CLEAR_PRESENT(p_attr, _attr,_p)            \
    do {                                                                \
        (p_attr)->presence_mask &= ~(BCMBAL_ATTRIBUTE_PROP_MASK_GET(_attr, _p)); \
    } while (0)

/** Set attribute element property in message structure
 * \param[in]   _p_attr Attribute structure pointer
 * \param[in]   _attr   Attribute name
 * \param[in]   _p      Element name (i.e. o_tpid)
 * \param[in]   _v      Element value
 */
#define BCMBAL_ATTRIBUTE_PROP_SET(_p_attr, _attr, _p, _v)    \
    do { \
        _BCMBAL_ATTRIBUTE_PROP_SET_PRESENT(_p_attr, _attr, _p);   \
        (_p_attr)->_p = (_v);                                    \
    } while (0)

/** Clear attribute element property in message structure
 * \param[in]   _p_attr Attribute structure pointer
 * \param[in]   _attr   Attribute name
 * \param[in]   _p      Element name (i.e. o_tpid)
 */
#define BCMBAL_ATTRIBUTE_PROP_CLEAR(_p_attr, _attr, _p)    \
    do { \
        _BCMBAL_ATTRIBUTE_PROP_CLEAR_PRESENT(_p_attr, _attr, _p);   \
        memset(&((_p_attr)->_p), 0, sizeof((_p_attr)->_p));   \
    } while (0)


/* Internal macro: check if an attribute element is present */
#define _BCMBAL_ATTRIBUTE_PROP_IS_PRESENT(_p_attr, _attr, _p)              \
    (((_p_attr)->presence_mask & BCMBAL_ATTRIBUTE_PROP_MASK_GET(_attr, _p)) ? \
         BCMOS_TRUE : BCMOS_FALSE)

/** Check if attribute element property is set in message structure
 * \param[in]   _p_attr Attribute structure pointer
 * \param[in]   _attr   Attribute name
 * \param[in]   _p      Element name (i.e. o_tpid)
 */
#define BCMBAL_ATTRIBUTE_PROP_IS_SET(_p_attr, _attr, _p)    _BCMBAL_ATTRIBUTE_PROP_IS_PRESENT(_p_attr, _attr, _p)


/*
 * ------------------------------------------------------------------
 *
 * Internal BCMBAL macros used to manipulate cmds_bitmask of action parameters
 *
 * ------------------------------------------------------------------
 */

/** Check if action cmd id is set in action structure
 * \param[in]   _m      Object structure pointer
 * \param[in]   _b      cmd Id bitmask
 */
#define BCMBAL_ACTION_CMD_ID_IS_SET(_m, _b) \
    (((_m)->cmds_bitmask & (_b)) ? \
        BCMOS_TRUE : BCMOS_FALSE)

/** Set action cmd id in action structure
 * \param[in]   _m      Object structure pointer
 * \param[in]   _b      cmd Id bitmask
 */
#define BCMBAL_ACTION_CMD_ID_SET(_m, _b) \
    do {                                                                \
        (_m)->cmds_bitmask |= (_b);\
    } while (0)


/** Clear action cmd id in action structure
 * \param[in]   _m      Object structure pointer
 * \param[in]   _b      cmd Id bitmask
 */
#define BCMBAL_ACTION_CMD_ID_CLEAR(_m, _b) \
    do {                                                                \
        (_m)->cmds_bitmask &= ~(_b);\
    } while (0)

/** Create a GET response, returning the requested parameters in _msg only
 *   if they are set in _curr
 *
 * \param[in]   _curr         A pointer to the object managed in the core
 * \param[in]   _msg          A pointer to the object message being returned
 * \param[in]   _objtype      The type of object
 */
#define GET_RSP_CREATE(_curr, _msg, _objtype)  {                        \
        bcmbal_presence_mask _foo_ = (((bcmbal_obj *)_msg)->presence_mask & _curr.hdr.hdr.presence_mask); \
        _curr.hdr.hdr.comm_hdr = ((bcmbal_obj *)_msg)->comm_hdr;        \
        *((bcmbal_ ## _objtype ## _cfg *)_msg) = _curr;                 \
        ((bcmbal_obj *)_msg)->presence_mask = _foo_;   }


static inline void bcmbal_access_terminal_object_overlay_w_src_priority(bcmbal_access_terminal_cfg *dstobj, 
                                                                        bcmbal_access_terminal_cfg *srcobj)
{
    BUG_ON(NULL == dstobj);
    BUG_ON(NULL == srcobj);

    bcmbal_presence_mask dest_presence_mask;

    /* First, copy the common object and keys in their entirety, except for preserving the presence_mask */
    dest_presence_mask = dstobj->hdr.hdr.presence_mask;
    dstobj->hdr = srcobj->hdr;
    dstobj->key = srcobj->key;
    dstobj->hdr.hdr.presence_mask = dest_presence_mask;

    /* Now copy only the fields that have been specified in the source object */
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, access_terminal, admin_state))
    {
        BCMBAL_CFG_PROP_SET(dstobj, access_terminal, admin_state, srcobj->data.admin_state);
    }
}

static inline void bcmbal_flow_object_overlay_w_src_priority(bcmbal_flow_cfg *dstobj, bcmbal_flow_cfg *srcobj)
{
    BUG_ON(NULL == dstobj);
    BUG_ON(NULL == srcobj);

    bcmbal_presence_mask dest_presence_mask;

    /* First, copy the common object and keys in their entirety, except for preserving the presence_mask */
    dest_presence_mask = dstobj->hdr.hdr.presence_mask;
    dstobj->hdr = srcobj->hdr;
    dstobj->key = srcobj->key;
    dstobj->hdr.hdr.presence_mask = dest_presence_mask;

    /* Now copy only the fields that have been specified in the source object */
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, admin_state))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, admin_state, srcobj->data.admin_state);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, access_int_id))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, access_int_id, srcobj->data.access_int_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, network_int_id))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, network_int_id, srcobj->data.network_int_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, sub_term_id))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, sub_term_id, srcobj->data.sub_term_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, svc_port_id))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, svc_port_id, srcobj->data.svc_port_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, resolve_mac))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, resolve_mac, srcobj->data.resolve_mac);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, queue))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, queue, srcobj->data.queue);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, action))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, action, srcobj->data.action);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, classifier))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, classifier, srcobj->data.classifier);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, group_id))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, group_id, srcobj->data.group_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, dba_tm_sched_id))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, dba_tm_sched_id, srcobj->data.dba_tm_sched_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, cookie))
    {
        BCMBAL_CFG_PROP_SET(dstobj, flow, cookie, srcobj->data.cookie);
    }
}

static inline void bcmbal_flow_object_overlay_w_dst_priority(bcmbal_flow_cfg *dstobj, bcmbal_flow_cfg *srcobj)
{
    BUG_ON(NULL == dstobj);
    BUG_ON(NULL == srcobj);

    bcmbal_presence_mask dest_presence_mask;

    /* First, copy the common object while preserving the presence_mask */
    dest_presence_mask = dstobj->hdr.hdr.presence_mask;
    dstobj->hdr = srcobj->hdr;
    dstobj->hdr.hdr.presence_mask = dest_presence_mask;

    /* Now copy only the fields that have been specified in the source and are not already set in the dst object */
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, admin_state))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, admin_state))
            BCMBAL_CFG_PROP_SET(dstobj, flow, admin_state, srcobj->data.admin_state);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, access_int_id))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, access_int_id))
            BCMBAL_CFG_PROP_SET(dstobj, flow, access_int_id, srcobj->data.access_int_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, network_int_id))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, network_int_id))
            BCMBAL_CFG_PROP_SET(dstobj, flow, network_int_id, srcobj->data.network_int_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, sub_term_id))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, sub_term_id))
            BCMBAL_CFG_PROP_SET(dstobj, flow, sub_term_id, srcobj->data.sub_term_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, svc_port_id))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, svc_port_id))
            BCMBAL_CFG_PROP_SET(dstobj, flow, svc_port_id, srcobj->data.svc_port_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, resolve_mac))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, resolve_mac))
            BCMBAL_CFG_PROP_SET(dstobj, flow, resolve_mac, srcobj->data.resolve_mac);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, queue))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, queue))
            BCMBAL_CFG_PROP_SET(dstobj, flow, queue, srcobj->data.queue);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, action))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, action))
            BCMBAL_CFG_PROP_SET(dstobj, flow, action, srcobj->data.action);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, classifier))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, classifier))
            BCMBAL_CFG_PROP_SET(dstobj, flow, classifier, srcobj->data.classifier);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, group_id))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, group_id))
            BCMBAL_CFG_PROP_SET(dstobj, flow, group_id, srcobj->data.group_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, dba_tm_sched_id))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, dba_tm_sched_id))
            BCMBAL_CFG_PROP_SET(dstobj, flow, dba_tm_sched_id, srcobj->data.dba_tm_sched_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, flow, cookie))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, flow, cookie))
            BCMBAL_CFG_PROP_SET(dstobj, flow, cookie, srcobj->data.cookie);
    }
}

static inline void bcmbal_sub_term_object_overlay_w_src_priority(bcmbal_subscriber_terminal_cfg *dstobj,
                                                                 bcmbal_subscriber_terminal_cfg *srcobj)
{
    BUG_ON(NULL == dstobj);
    BUG_ON(NULL == srcobj);

    bcmbal_presence_mask dest_presence_mask;

    /* First, copy the common object and keys in their entirety, except for preserving the presence_mask */
    dest_presence_mask = dstobj->hdr.hdr.presence_mask;
    dstobj->hdr = srcobj->hdr;
    dstobj->key = srcobj->key;
    dstobj->hdr.hdr.presence_mask = dest_presence_mask;

    /* Now copy only the fields that have been specified in the source object */
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, admin_state))
    {
        BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, admin_state, srcobj->data.admin_state);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, serial_number))
    {
        BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, serial_number, srcobj->data.serial_number);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, password))
    {
        BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, password, srcobj->data.password);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, registration_id))
    {
        BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, registration_id, srcobj->data.registration_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, sub_term_rate))
    {
        BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, sub_term_rate, srcobj->data.sub_term_rate);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, svc_port_id))
    {
        BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, svc_port_id, srcobj->data.svc_port_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, ds_tm))
    {
        BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, ds_tm, srcobj->data.ds_tm);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, us_tm))
    {
        BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, us_tm, srcobj->data.us_tm);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, mac_address))
    {
        BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, mac_address, srcobj->data.mac_address);
    }
	
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, sub_term_rate))
    {
        BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, sub_term_rate, srcobj->data.sub_term_rate);
    }
}

static inline void bcmbal_sub_term_object_overlay_w_dst_priority(bcmbal_subscriber_terminal_cfg *dstobj,
                                                                 bcmbal_subscriber_terminal_cfg *srcobj)
{
    BUG_ON(NULL == dstobj);
    BUG_ON(NULL == srcobj);

    bcmbal_presence_mask dest_presence_mask;

    /* First, copy the common object while preserving the presence_mask */
    dest_presence_mask = dstobj->hdr.hdr.presence_mask;
    dstobj->hdr = srcobj->hdr;
    dstobj->hdr.hdr.presence_mask = dest_presence_mask;

    /* Now copy only the fields that have been specified in the source object */
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, admin_state))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, subscriber_terminal, admin_state))
            BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, admin_state, srcobj->data.admin_state);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, serial_number))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, subscriber_terminal, serial_number))
            BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, serial_number, srcobj->data.serial_number);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, password))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, subscriber_terminal, password))
            BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, password, srcobj->data.password);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, registration_id))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, subscriber_terminal, registration_id))
            BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, registration_id, srcobj->data.registration_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, sub_term_rate))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, subscriber_terminal, sub_term_rate))
            BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, sub_term_rate, srcobj->data.sub_term_rate);
    }
	
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, svc_port_id))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, subscriber_terminal, svc_port_id))
            BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, svc_port_id, srcobj->data.svc_port_id);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, ds_tm))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, subscriber_terminal, ds_tm))
            BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, ds_tm, srcobj->data.ds_tm);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, us_tm))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, subscriber_terminal, us_tm))
            BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, us_tm, srcobj->data.us_tm);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, subscriber_terminal, mac_address))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, subscriber_terminal, mac_address))
            BCMBAL_CFG_PROP_SET(dstobj, subscriber_terminal, mac_address, srcobj->data.mac_address);
    }
}

static inline void bcmbal_tm_sched_object_overlay_w_src_priority(bcmbal_tm_sched_cfg *dstobj, bcmbal_tm_sched_cfg *srcobj)
{
    BUG_ON(NULL == dstobj);
    BUG_ON(NULL == srcobj);

    bcmbal_presence_mask dest_presence_mask;

    /* First, copy the common object and keys in their entirety, except for preserving the presence_mask */
    dest_presence_mask = dstobj->hdr.hdr.presence_mask;
    dstobj->hdr = srcobj->hdr;
    dstobj->key = srcobj->key;
    dstobj->hdr.hdr.presence_mask = dest_presence_mask;

    /* Now copy only the fields that have been specified in the source object */
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, owner))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_sched, owner, srcobj->data.owner);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, sched_type))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_sched, sched_type, srcobj->data.sched_type);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, sched_parent))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_sched, sched_parent, srcobj->data.sched_parent);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, sched_child_type))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_sched, sched_child_type, srcobj->data.sched_child_type);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, rate))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_sched, rate, srcobj->data.rate);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, ext_itu_dba))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_sched, ext_itu_dba, srcobj->data.ext_itu_dba);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, ext_epon_dba))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_sched, ext_epon_dba, srcobj->data.ext_epon_dba);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, creation_mode))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_sched, creation_mode, srcobj->data.creation_mode);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, num_priorities))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_sched, num_priorities, srcobj->data.num_priorities);
    }

}



static inline void bcmbal_tm_sched_object_overlay_w_dst_priority(bcmbal_tm_sched_cfg *dstobj, bcmbal_tm_sched_cfg *srcobj)
{
    BUG_ON(NULL == dstobj);
    BUG_ON(NULL == srcobj);

    bcmbal_presence_mask dest_presence_mask;

    /* First, copy the common object while preserving the presence_mask */
    dest_presence_mask = dstobj->hdr.hdr.presence_mask;
    dstobj->hdr = srcobj->hdr;
    dstobj->hdr.hdr.presence_mask = dest_presence_mask;

    /* Now copy only the fields that have been specified in the source and are not already set in the dst object */
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, owner))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, tm_sched, owner))
            BCMBAL_CFG_PROP_SET(dstobj, tm_sched, owner, srcobj->data.owner);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, sched_type))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, tm_sched, sched_type))
            BCMBAL_CFG_PROP_SET(dstobj, tm_sched, sched_type, srcobj->data.sched_type);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, sched_parent))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, tm_sched, sched_parent))
            BCMBAL_CFG_PROP_SET(dstobj, tm_sched, sched_parent, srcobj->data.sched_parent);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, sched_child_type))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, tm_sched, sched_child_type))
            BCMBAL_CFG_PROP_SET(dstobj, tm_sched, sched_child_type, srcobj->data.sched_child_type);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, rate))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, tm_sched, rate))
            BCMBAL_CFG_PROP_SET(dstobj, tm_sched, rate, srcobj->data.rate);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, ext_itu_dba))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, tm_sched, ext_itu_dba))
            BCMBAL_CFG_PROP_SET(dstobj, tm_sched, ext_itu_dba, srcobj->data.ext_itu_dba);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, ext_epon_dba))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, tm_sched, ext_epon_dba))
            BCMBAL_CFG_PROP_SET(dstobj, tm_sched, ext_epon_dba, srcobj->data.ext_epon_dba);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_sched, creation_mode))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, tm_sched, creation_mode))
            BCMBAL_CFG_PROP_SET(dstobj, tm_sched, creation_mode, srcobj->data.creation_mode);
    }					

}


static inline void bcmbal_tm_queue_object_overlay(bcmbal_tm_queue_cfg *dstobj, bcmbal_tm_queue_cfg *srcobj)
{
    BUG_ON(NULL == dstobj);
    BUG_ON(NULL == srcobj);

    bcmbal_presence_mask dest_presence_mask;

    /* First, copy the common object and keys in their entirety, except for preserving the presence_mask */
    dest_presence_mask = dstobj->hdr.hdr.presence_mask;
    dstobj->hdr = srcobj->hdr;
    dstobj->key = srcobj->key;
    dstobj->hdr.hdr.presence_mask = dest_presence_mask;

    /* Now copy only the fields that have been specified in the source object */

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_queue, priority))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_queue, priority, srcobj->data.priority);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_queue, weight))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_queue, weight, srcobj->data.weight);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_queue, rate))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_queue, rate, srcobj->data.rate);
    }

    if(BCMBAL_CFG_PROP_IS_SET(srcobj, tm_queue, bac))
    {
        BCMBAL_CFG_PROP_SET(dstobj, tm_queue, bac, srcobj->data.bac);
    }
}

static inline bcmos_errno bal_obj_key_str_get(bcmbal_obj *obj, char *p_obj_key_str)
{
    BUG_ON(NULL == p_obj_key_str);

    bcmos_errno ret = BCM_ERR_OK;

    switch (obj->obj_type)
    {

        case (BCMBAL_OBJ_ID_ACCESS_TERMINAL):
        {
            sprintf(p_obj_key_str, "unit:%d", 
                    ((bcmbal_access_terminal_cfg *)obj)->key.access_term_id);
            break;
        }
        
        case (BCMBAL_OBJ_ID_INTERFACE):
        {
            sprintf(p_obj_key_str, "intf_id:%d, type:%s",
                    ((bcmbal_interface_cfg *)obj)->key.intf_id,
                    ((bcmbal_interface_cfg *)obj)->key.intf_type == BCMBAL_INTF_TYPE_NNI ? "NNI" :
                    ((bcmbal_interface_cfg *)obj)->key.intf_type == BCMBAL_INTF_TYPE_PON ? "PON" :
                    "???"
                    );
            break;
        }

        case (BCMBAL_OBJ_ID_SUBSCRIBER_TERMINAL):
        {
            sprintf(p_obj_key_str, "sub_term_id:%d, intf_id:%d",
                    ((bcmbal_subscriber_terminal_cfg *)obj)->key.sub_term_id,
                    ((bcmbal_subscriber_terminal_cfg *)obj)->key.intf_id);
            break;
        }
            
        case (BCMBAL_OBJ_ID_FLOW):
        {
            sprintf(p_obj_key_str, "flow_id:%d, type:%s",
                    ((bcmbal_flow_cfg *)obj)->key.flow_id,
                    ((bcmbal_flow_cfg *)obj)->key.flow_type == BCMBAL_FLOW_TYPE_UPSTREAM ? "upstream" :
                    ((bcmbal_flow_cfg *)obj)->key.flow_type == BCMBAL_FLOW_TYPE_DOWNSTREAM ? "downstream" :
                    ((bcmbal_flow_cfg *)obj)->key.flow_type == BCMBAL_FLOW_TYPE_BROADCAST ? "broadcast" :
                    ((bcmbal_flow_cfg *)obj)->key.flow_type == BCMBAL_FLOW_TYPE_MULTICAST ? "multicast" :
                    "???"
                    );
            break;
        }

        case (BCMBAL_OBJ_ID_GROUP):
        {
            sprintf(p_obj_key_str, "group_id:%d",
                    ((bcmbal_group_cfg *)obj)->key.group_id);
            break;
        }

        case (BCMBAL_OBJ_ID_TM_SCHED):
        {
            sprintf(p_obj_key_str, "dir:%s, id:%d",
                    ((bcmbal_tm_sched_cfg *)obj)->key.dir == BCMBAL_TM_SCHED_DIR_US ? "upstream" :
                    ((bcmbal_tm_sched_cfg *)obj)->key.dir == BCMBAL_TM_SCHED_DIR_DS ? "downstream" :
                    "???",
                    ((bcmbal_tm_sched_cfg *)obj)->key.id
                    );
            break;
        } 

        case (BCMBAL_OBJ_ID_TM_QUEUE):
        {
            sprintf(p_obj_key_str, "sched_id:%d, sched_dir:%s, id:%d",                   
                    ((bcmbal_tm_queue_cfg *)obj)->key.sched_id,
                    ((bcmbal_tm_queue_cfg *)obj)->key.sched_dir == BCMBAL_TM_SCHED_DIR_US ? "upstream" :
                    ((bcmbal_tm_queue_cfg *)obj)->key.sched_dir == BCMBAL_TM_SCHED_DIR_DS ? "downstream" :
                    "???",
                    ((bcmbal_tm_queue_cfg *)obj)->key.id
                    );
            break;
        } 
                    
        case (BCMBAL_OBJ_ID_PACKET):
        {
            sprintf(p_obj_key_str, " ");
            break;
        }

        default:
            sprintf(p_obj_key_str, " ");
            ret = BCM_ERR_PARM;
            break;
    }

    return ret;
}

static inline void bcmbal_interface_object_overlay_w_dst_priority(bcmbal_interface_cfg *dstobj, bcmbal_interface_cfg *srcobj)
{
    BUG_ON(NULL == dstobj);
    BUG_ON(NULL == srcobj);
    
    bcmbal_presence_mask dest_presence_mask;
    
    /* First, copy the common object while preserving the presence_mask */
    dest_presence_mask = dstobj->hdr.hdr.presence_mask;
    dstobj->hdr = srcobj->hdr;
    dstobj->hdr.hdr.presence_mask = dest_presence_mask;
    
    /* Now copy only the fields that have been specified in the source and are not already set in the dst object */
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, admin_state))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, interface, admin_state))
            BCMBAL_CFG_PROP_SET(dstobj, interface, admin_state, srcobj->data.admin_state);
    }
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, min_data_agg_port_id))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, interface, min_data_agg_port_id))
            BCMBAL_CFG_PROP_SET(dstobj, interface, min_data_agg_port_id, srcobj->data.min_data_agg_port_id);
    }   
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, min_data_svc_port_id))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, interface, min_data_svc_port_id))
            BCMBAL_CFG_PROP_SET(dstobj, interface, min_data_svc_port_id, srcobj->data.min_data_svc_port_id);
    }    
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, transceiver_type))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, interface, transceiver_type))
            BCMBAL_CFG_PROP_SET(dstobj, interface, transceiver_type, srcobj->data.transceiver_type);
    }    
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, ds_miss_mode))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, interface, ds_miss_mode))
            BCMBAL_CFG_PROP_SET(dstobj, interface, ds_miss_mode, srcobj->data.ds_miss_mode);
    }  
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, mtu))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, interface, mtu))
            BCMBAL_CFG_PROP_SET(dstobj, interface, mtu, srcobj->data.mtu);
    }		
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, flow_control))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, interface, flow_control))
            BCMBAL_CFG_PROP_SET(dstobj, interface, flow_control, srcobj->data.flow_control);
    }
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, ds_tm))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, interface, ds_tm))
            BCMBAL_CFG_PROP_SET(dstobj, interface, ds_tm, srcobj->data.ds_tm);
    }
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, us_tm))
    {
        if(!BCMBAL_CFG_PROP_IS_SET(dstobj, interface, us_tm))
            BCMBAL_CFG_PROP_SET(dstobj, interface, us_tm, srcobj->data.us_tm);
    }
}


static inline void bcmbal_interface_object_overlay_w_src_priority(bcmbal_interface_cfg *dstobj,
                                                                  bcmbal_interface_cfg *srcobj)
{
    BUG_ON(NULL == dstobj);
    BUG_ON(NULL == srcobj);
    
    bcmbal_presence_mask dest_presence_mask;
    
    /* First, copy the common object and keys in their entirety, except for preserving the presence_mask */
    dest_presence_mask = dstobj->hdr.hdr.presence_mask;
    dstobj->hdr = srcobj->hdr;
    dstobj->key = srcobj->key;
    dstobj->hdr.hdr.presence_mask = dest_presence_mask;
    
    /* Now copy only the fields that have been specified in the source object */
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, admin_state))
    {
        BCMBAL_CFG_PROP_SET(dstobj, interface, admin_state, srcobj->data.admin_state);
    }
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, min_data_agg_port_id))
    {
        BCMBAL_CFG_PROP_SET(dstobj, interface, min_data_agg_port_id, srcobj->data.min_data_agg_port_id);
    }
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, min_data_svc_port_id))
    {
        BCMBAL_CFG_PROP_SET(dstobj, interface, min_data_svc_port_id, srcobj->data.min_data_svc_port_id);
    }    
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, transceiver_type))
    {
        BCMBAL_CFG_PROP_SET(dstobj, interface, transceiver_type, srcobj->data.transceiver_type);
    }
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, ds_miss_mode))
    {
        BCMBAL_CFG_PROP_SET(dstobj, interface, ds_miss_mode, srcobj->data.ds_miss_mode);
    }
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, mtu))
    {
        BCMBAL_CFG_PROP_SET(dstobj, interface, mtu, srcobj->data.mtu);
    }
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, flow_control))
    {
        BCMBAL_CFG_PROP_SET(dstobj, interface, flow_control, srcobj->data.flow_control);
    }    
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, ds_tm))
    {
        BCMBAL_CFG_PROP_SET(dstobj, interface, ds_tm, srcobj->data.ds_tm);
    }
    if(BCMBAL_CFG_PROP_IS_SET(srcobj, interface, us_tm))
    {
        BCMBAL_CFG_PROP_SET(dstobj, interface, us_tm, srcobj->data.us_tm);
    }

}

typedef union bcmbal_object_key
{
    bcmbal_access_terminal_key        acc_term_key;
    bcmbal_interface_key              intf_key;
    bcmbal_subscriber_terminal_key    sub_term_key;
    bcmbal_flow_key                   flow_key;
    bcmbal_group_key                  group_key;
    bcmbal_tm_sched_key               tm_sched_key;
    bcmbal_tm_queue_key               tm_queue_key;
}bcmbal_object_key;

typedef struct bcmbal_object_key_info
{
    bcmbal_object_key key;
    uint16_t          key_size;
}bcmbal_object_key_info;

/*@}*/

#endif /* BAL_OBJS_H */
