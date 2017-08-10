#ifndef BAL_MODEL_TYPES
#define BAL_MODEL_TYPES

#include <bcmos_system.h>
#include "bal_obj.h"

/** \defgroup object_model_data_types BAL Object Model Data Types
 * @{
 */
typedef uint32_t bcmbal_access_id;                      /**< bcmbal_access_id: typed alias for a 32-bit unsigned integer. */
typedef uint16_t bcmbal_aggregation_port_id;            /**< bcmbal_aggregation_port_id: typed alias for a 16-bit unsigned integer. */
typedef uint64_t bcmbal_cookie;                         /**< bcmbal_cookie: typed alias for a 64-bit unsigned integer. */
typedef uint32_t bcmbal_intf_id;                        /**< bcmbal_intf_id: typed alias for a 32-bit unsigned integer. */
typedef uint32_t bcmbal_sub_id;                         /**< bcmbal_sub_id: typed alias for a 32-bit unsigned integer. */
#define BCMBAL_SUB_ID_UNKNOWN   ((bcmbal_sub_id) 65535UL)
typedef uint16_t bcmbal_service_port_id;                /**< bcmbal_service_port_id: typed alias for a 16-bit unsigned integer. */
typedef uint32_t bcmbal_time_quanta;                    /**< bcmbal_time_quanta: typed alias for a 32-bit unsigned integer. */
typedef uint32_t bcmbal_flow_id;                        /**< bcmbal_flow_id: typed alias for a 32-bit unsigned integer. */
typedef uint32_t bcmbal_group_id;                       /**< bcmbal_group_id: typed alias for a 32-bit unsigned integer. */
typedef uint32_t bcmbal_tm_sched_id;                    /**< bcmbal_tm_sched_id: typed alias for a 32-bit unsigned integer. */
#define BCMBAL_TM_SCHED_ID_UNKNOWN  ((bcmbal_tm_sched_id) 65535UL)
typedef uint16_t bcmbal_tm_queue_id;                    /**< bcmbal_tm_queue_id: typed alias for a 16-bit unsigned integer. */
#define BCMBAL_TM_QUEUE_ID_UNKNOWN  ((bcmbal_tm_queue_id) 65535U)
typedef uint8_t bcmbal_percent;                         /**< bcmbal_percent: typed alias for a 8-bit unsigned integer. */
typedef uint8_t bcmbal_tm_priority;                     /**< bcmbal_tm_priority: typed alias for a 8-bit unsigned integer. */
typedef uint16_t bcmbal_tm_sched_id_index;              /**< bcmbal_tm_sched_id_index: typed alias for a 16-bit unsigned integer. */
typedef uint8_t bcmbal_tm_weight;                       /**< bcmbal_tm_weight: typed alias for a 8-bit unsigned integer. */

/** action ID. 
 */
typedef enum bcmbal_action_id
{
    BCMBAL_ACTION_ID_NONE           = 0,
    BCMBAL_ACTION_ID_CMDS_BITMASK   = 0x0001,           /**< Commands bitmask. */
    BCMBAL_ACTION_ID_O_VID          = 0x0002,           /**< Outer vid. */
    BCMBAL_ACTION_ID_O_PBITS        = 0x0004,           /**< Outer pbits. */
    BCMBAL_ACTION_ID_O_TPID         = 0x0008,           /**< Outer tpid. */
    BCMBAL_ACTION_ID_I_VID          = 0x0010,           /**< Inner vid. */
    BCMBAL_ACTION_ID_I_PBITS        = 0x0020,           /**< Inner pbits. */
    BCMBAL_ACTION_ID_I_TPID         = 0x0040,           /**< Inner tpid. */
    BCMBAL_ACTION_ID_ALL            = 0x007F            /**< All fields */
} bcmbal_action_id;

/** action_cmd_id. 
 */
typedef enum bcmbal_action_cmd_id
{
    BCMBAL_ACTION_CMD_ID_NONE               = 0,
    BCMBAL_ACTION_CMD_ID_ADD_OUTER_TAG      = 0x0001,   /**< Add outer tag. */
    BCMBAL_ACTION_CMD_ID_REMOVE_OUTER_TAG   = 0x0002,   /**< Remove outer tag. */
    BCMBAL_ACTION_CMD_ID_XLATE_OUTER_TAG    = 0x0004,   /**< Translate outer tag. */
    BCMBAL_ACTION_CMD_ID_XLATE_TWO_TAGS     = 0x0008,   /**< Translate two tags. */
    BCMBAL_ACTION_CMD_ID_DISCARD_DS_BCAST   = 0x0010,   /**< Used to satisfy TR-156 Issue 3 R-111/TR-200 Issue 1 R-106 */
    BCMBAL_ACTION_CMD_ID_DISCARD_DS_UNKNOWN = 0x0020,   /**< Used to satisfy TR-156 Issue 3 R-109/TR-200 Issue 1 R-104 */
    BCMBAL_ACTION_CMD_ID_ADD_TWO_TAGS       = 0x0040,   /**< Add two tags. */
    BCMBAL_ACTION_CMD_ID_REMOVE_TWO_TAGS    = 0x0080,   /**< Remove two tags. */
    BCMBAL_ACTION_CMD_ID_REMARK_PBITS       = 0x0100,   /**< Set the outer tag pbits */
    BCMBAL_ACTION_CMD_ID_COPY_PBITS         = 0x0200,   /**< Copy the inner pbits to outer pbits */
    BCMBAL_ACTION_CMD_ID_REVERSE_COPY_PBITS = 0x0400,   /**< Copy the outer pbits to inner pbits */
    BCMBAL_ACTION_CMD_ID_DSCP_TO_PBITS      = 0x0800,   /**< Copy the L4 DSCP to outer pbits */
    BCMBAL_ACTION_CMD_ID_TRAP_TO_HOST       = 0x1000    /**< Not a valid action for a group object member */
} bcmbal_action_cmd_id;

/** alarm status. 
 */
typedef enum bcmbal_alarm_status
{
    BCMBAL_ALARM_STATUS_OFF                 = 0,        /**< alarm status is off */
    BCMBAL_ALARM_STATUS_ON                  = 1,        /**< alarm status is on */
    BCMBAL_ALARM_STATUS_NO__CHANGE          = 2,        /**< alarm status should not be changed */
    BCMBAL_ALARM_STATUS__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_alarm_status;

/** classifier ID. 
 */
typedef enum bcmbal_classifier_id
{
    BCMBAL_CLASSIFIER_ID_NONE               = 0,
    BCMBAL_CLASSIFIER_ID_O_TPID             = 0x0001,   /**< Outer TPID of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_O_VID              = 0x0002,   /**< Outer VID of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_I_TPID             = 0x0004,   /**< Inner TPID of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_I_VID              = 0x0008,   /**< Inner VID of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_O_PBITS            = 0x0010,   /**< Outer PBITS of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_I_PBITS            = 0x0020,   /**< Inner PBITS of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_ETHER_TYPE         = 0x0040,   /**< Ethertype of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_DST_MAC            = 0x0080,   /**< Destination MAC address of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_SRC_MAC            = 0x0100,   /**< Source MAC address of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_IP_PROTO           = 0x0200,   /**< IP protocol of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_DST_IP             = 0x0400,   /**< Destination IP address of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_SRC_IP             = 0x0800,   /**< Source IP address of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_SRC_PORT           = 0x1000,   /**< Source port of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_DST_PORT           = 0x2000,   /**< Destination port of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_PKT_TAG_TYPE       = 0x4000,   /**< The tag type of the ingress packets */
    BCMBAL_CLASSIFIER_ID_ALL                = 0x7FFF    /**< All fields */
} bcmbal_classifier_id;

/** Packet tag type. 
 */
typedef enum bcmbal_pkt_tag_type
{
    BCMBAL_PKT_TAG_TYPE_NONE                = 0,
    BCMBAL_PKT_TAG_TYPE_UNTAGGED            = 0x0001,   /**< Untagged. */
    BCMBAL_PKT_TAG_TYPE_SINGLE_TAG          = 0x0002,   /**< Single tag. */
    BCMBAL_PKT_TAG_TYPE_DOUBLE_TAG          = 0x0004    /**< Double tag. */
} bcmbal_pkt_tag_type;

/** Generic enable/disable enumeration 
 */
typedef enum bcmbal_control
{
    BCMBAL_CONTROL_DISABLE                  = 0,        /**< disable. */
    BCMBAL_CONTROL_ENABLE                   = 1,        /**< enable. */
    BCMBAL_CONTROL__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_control;

/** Destination type. 
 */
typedef enum bcmbal_dest_type
{
    BCMBAL_DEST_TYPE_NNI                    = 1,                    /**< for packets being sent to the NNI */
    BCMBAL_DEST_TYPE_SUB_TERM               = 2,                    /**< for packets being sent to a subscriber terminal */
    BCMBAL_DEST_TYPE_SVC_PORT               = 3,                    /**< for packet being sent to the pon service port */
    BCMBAL_DEST_TYPE_ITU_OMCI_CHANNEL       = 4,                    /**< for itu omci channel packets */
    BCMBAL_DEST_TYPE_IEEE_OAM_CHANNEL       = 5                     /**< for ieee oam channel packets */
} bcmbal_dest_type;

/** Downstrean action for unknown packets. 
 */
typedef enum bcmbal_ds_miss_mode
{
    BCMBAL_DS_MISS_MODE_DISCARD             = 0,                    /**< Discard. */
    BCMBAL_DS_MISS_MODE_BROADCAST           = 1,                    /**< Broadcast. */
    BCMBAL_DS_MISS_MODE_VID                 = 2,                    /**< Vid. */
    BCMBAL_DS_MISS_MODE__NUM_OF                                     /**< Number of enum entries, not an entry itself. */
} bcmbal_ds_miss_mode;

/** extended epon dba ID. 
 */
typedef enum bcmbal_extended_epon_dba_id
{
    BCMBAL_EXTENDED_EPON_DBA_ID_NONE                    = 0,
    BCMBAL_EXTENDED_EPON_DBA_ID_POLLING_INTERVAL_US     = 0x0001,   /**< The amount of time between when this LLID last reported upstream data and when it will next be polled (approximate: rounded down to the nearest 65.536 us). */
    BCMBAL_EXTENDED_EPON_DBA_ID_GRANT_THRESHOLD_TQ      = 0x0002,   /**< Used to determine the maximum grant size that will be issued to this LLID (in TQ; rounded up to the nearest 128TQ; 1TQ = 16ns = 2Bytes@1G or 20Bytes@10G). */
    BCMBAL_EXTENDED_EPON_DBA_ID_CIR_PRIORITY            = 0x0004,   /**< The priority of the CIR scheduling element. */
    BCMBAL_EXTENDED_EPON_DBA_ID_CIR_WEIGHT_TQ           = 0x0008,   /**< The weight of the CIR scheduler (in TQ rounded up to nearest 128). Must be greater than or equal to Grant Threshold. */
    BCMBAL_EXTENDED_EPON_DBA_ID_PIR_PRIORITY            = 0x0010,   /**< The priority of the PIR scheduling element. */
    BCMBAL_EXTENDED_EPON_DBA_ID_PIR_WEIGHT_TQ           = 0x0020,   /**< The weight of the PIR scheduler (in TQ rounded up to nearest 128). Must be greater than or equal to Grant Threshold. */
    BCMBAL_EXTENDED_EPON_DBA_ID_TDM_GRANT_SIZE_TQ       = 0x0040,   /**< Size of TDM grants (in TQ). */
    BCMBAL_EXTENDED_EPON_DBA_ID_TDM_GRANT_INTERVAL_US   = 0x0080,   /**< Interval between TDM grants (in us). */
    BCMBAL_EXTENDED_EPON_DBA_ID_ALL                     = 0x00FF    /**< All fields */
} bcmbal_extended_epon_dba_id;

/** Polling Interval. 
 */
typedef enum bcmbal_polling_interval
{
    BCMBAL_POLLING_INTERVAL_POLLING_DISABLED            = 0,        /**< No polling gates will be sent to this LLID. */
    BCMBAL_POLLING_INTERVAL_US_500                      = 500,      /**< 500 us. */
    BCMBAL_POLLING_INTERVAL_MS_1                        = 1000,     /**< 1 ms. */
    BCMBAL_POLLING_INTERVAL_MS_2                        = 2000,     /**< 2 ms. */
    BCMBAL_POLLING_INTERVAL_MS_4                        = 4000,     /**< 4 ms. */
    BCMBAL_POLLING_INTERVAL_MS_8                        = 8000,     /**< 8 ms. */
    BCMBAL_POLLING_INTERVAL_MS_16                       = 16000     /**< 16 ms. */
} bcmbal_polling_interval;

/** extended itu dba ID. 
 */
typedef enum bcmbal_extended_itu_dba_id
{
    BCMBAL_EXTENDED_ITU_DBA_ID_NONE                     = 0,
    BCMBAL_EXTENDED_ITU_DBA_ID_EXTRA_BW_ELIG            = 0x0001,   /**< Extra BW eligibility type */
    BCMBAL_EXTENDED_ITU_DBA_ID_NRT_CBR                  = 0x0002,   /**< NRT CBR */
    BCMBAL_EXTENDED_ITU_DBA_ID_RT_CBR                   = 0x0004,   /**< RT_CBR */
    BCMBAL_EXTENDED_ITU_DBA_ID_RT_PROFILE               = 0x0008,   /**< RT Profile */
    BCMBAL_EXTENDED_ITU_DBA_ID_NRT_PROFILE              = 0x0010,   /**< NRT Profile */
    BCMBAL_EXTENDED_ITU_DBA_ID_ALL                      = 0x001F    /**< All fields */
} bcmbal_extended_itu_dba_id;

/** Extra BW Eligibility Type 
 */
typedef enum bcmbal_extra_bw_eligibility_type
{
    BCMBAL_EXTRA_BW_ELIGIBILITY_TYPE_NONE               = 0,        /**< None */
    BCMBAL_EXTRA_BW_ELIGIBILITY_TYPE_NOT_ASSURED        = 1,        /**< Not assured */
    BCMBAL_EXTRA_BW_ELIGIBILITY_TYPE_BEST_EFFORT        = 2,        /**< Best effort */
    BCMBAL_EXTRA_BW_ELIGIBILITY_TYPE__NUM_OF                        /**< Number of enum entries, not an entry itself. */
} bcmbal_extra_bw_eligibility_type;

/** Flow Type. 
 */
typedef enum bcmbal_flow_type
{
    BCMBAL_FLOW_TYPE_UPSTREAM                           = 1,        /**< Upstream flow */
    BCMBAL_FLOW_TYPE_DOWNSTREAM                         = 2,        /**< Downstream Flow */
    BCMBAL_FLOW_TYPE_BROADCAST                          = 3,        /**< Broadcast Flow */
    BCMBAL_FLOW_TYPE_MULTICAST                          = 4         /**< Multicast Flow */
} bcmbal_flow_type;

/** Member operation type. 
 */
typedef enum bcmbal_group_member_cmd
{
    BCMBAL_GROUP_MEMBER_CMD_ADD_MEMBERS                 = 1,        /**< Add new members. */
    BCMBAL_GROUP_MEMBER_CMD_REM_MEMBERS                 = 2,        /**< Remove existing members. */
    BCMBAL_GROUP_MEMBER_CMD_SET_MEMBERS                 = 3         /**< Replace members with new set. */
} bcmbal_group_member_cmd;

/** owner of the group 
 */
typedef enum bcmbal_group_owner
{
    BCMBAL_GROUP_OWNER_NONE                             = 0,        /**< no owner */
    BCMBAL_GROUP_OWNER_MULTICAST                        = 1,        /**< used as multicast group */
    BCMBAL_GROUP_OWNER_UNICAST                          = 2,        /**< used as unicast group */
    BCMBAL_GROUP_OWNER__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_group_owner;

/** Interface type. 
 */
typedef enum bcmbal_intf_type
{
    BCMBAL_INTF_TYPE_NNI                                = 0,    /**< NNI Interface. */
    BCMBAL_INTF_TYPE_PON                                = 1,    /**< PON Interface. */
    BCMBAL_INTF_TYPE_EPON_1G_PATH                       = 2,    /**< EPON 1G Path. */
    BCMBAL_INTF_TYPE_EPON_10G_PATH                      = 3,    /**< EPON 10G Path. */
    BCMBAL_INTF_TYPE__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_intf_type;

/** Interworking Function Mode. 
 */
typedef enum bcmbal_iwf_mode
{
    BCMBAL_IWF_MODE_DIRECT_MAPPING                      = 0,    /**< Direct mapping. */
    BCMBAL_IWF_MODE_PER_FLOW                            = 1,    /**< Per flow . */
    BCMBAL_IWF_MODE__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_iwf_mode;

/** The PON family 
 */
typedef enum bcmbal_pon_family
{
    BCMBAL_PON_FAMILY_GPON                              = 0,    /**< GPON family. */
    BCMBAL_PON_FAMILY_EPON                              = 1,    /**< EPON family. */
    BCMBAL_PON_FAMILY_INVALID                           = 2,    /**< INVALID . */
    BCMBAL_PON_FAMILY__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_pon_family;

/** The PON sub-family 
 */
typedef enum bcmbal_pon_sub_family
{
    BCMBAL_PON_SUB_FAMILY_GPON                          = 0,    /**< GPON. */
    BCMBAL_PON_SUB_FAMILY_XGPON                         = 1,    /**< XGPON. */
    BCMBAL_PON_SUB_FAMILY_EPON                          = 2,    /**< EPON. */
    BCMBAL_PON_SUB_FAMILY_INVALID                       = 3,    /**< INVALID. */
    BCMBAL_PON_SUB_FAMILY__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_pon_sub_family;

/** SLA ID. 
 */
typedef enum bcmbal_sla_id
{
    BCMBAL_SLA_ID_NONE                                  = 0,
    BCMBAL_SLA_ID_MIN_RATE                              = 0x0001,   /**< The minimal rate for this flow, in kilobits per second (optional) */
    BCMBAL_SLA_ID_MAX_RATE                              = 0x0002,   /**< The maximum rate for this flow, in kilobits per second (optional) */
    BCMBAL_SLA_ID_ALL                                   = 0x0003    /**< All fields */
} bcmbal_sla_id;

/** Admin state values for access terminal object 
 */
typedef enum bcmbal_state
{
    BCMBAL_STATE_UP                                     = 1,        /**< Admin state up */
    BCMBAL_STATE_DOWN                                   = 2,        /**< Admin state down */
    BCMBAL_STATE_TESTING                                = 3         /**< Admin state testing */
} bcmbal_state;

/** Oper status values 
 */
typedef enum bcmbal_status
{
    BCMBAL_STATUS_UP                                    = 1,        /**< Oper status up */
    BCMBAL_STATUS_DOWN                                  = 2,        /**< Oper status down */
    BCMBAL_STATUS_TESTING                               = 3,        /**< Oper status testing */
    BCMBAL_STATUS_NOT_PRESENT                           = 4,        /**< Oper status not present */
    BCMBAL_STATUS_LOWER_LAYER_DOWN                      = 5,        /**< Oper status lower layer down */
    BCMBAL_STATUS_UNKNOWN                               = 6         /**< Oper status unknown */
} bcmbal_status;

/** sub_term_rate. 
 */
typedef enum bcmbal_sub_term_rate
{
    BCMBAL_SUB_TERM_RATE_NONE                           = 0,        /**< none. */
    BCMBAL_SUB_TERM_RATE_RATE_10_G                      = 1,        /**< rate_10_g. */
    BCMBAL_SUB_TERM_RATE_RATE_2_5_G                     = 2,        /**< rate_2_5_g. */
    BCMBAL_SUB_TERM_RATE__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_sub_term_rate;

/** The type of release version 
 */
typedef enum bcmbal_version_type
{
    BCMBAL_VERSION_TYPE_UNKNOWN                         = 0,    /**< illegal */
    BCMBAL_VERSION_TYPE_RELEASE                         = 1,    /**< released version */
    BCMBAL_VERSION_TYPE_DEVELOPMENT                     = 2,    /**< debug version */
    BCMBAL_VERSION_TYPE__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_version_type;

/** Buffer Admission Control Type 
 */
typedef enum bcmbal_tm_bac_type
{
    BCMBAL_TM_BAC_TYPE_TAILDROP                         = 0,    /**< Taildrop  */
    BCMBAL_TM_BAC_TYPE_WTAILDROP                        = 1,    /**< Weighted taildrop */
    BCMBAL_TM_BAC_TYPE_RED                              = 2,    /**< Random Early Discard */
    BCMBAL_TM_BAC_TYPE_WRED                             = 3,    /**< Weighted Random Early Discard */
    BCMBAL_TM_BAC_TYPE__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_bac_type;

/** TM Creation Mode 
 */
typedef enum bcmbal_tm_creation_mode
{
    BCMBAL_TM_CREATION_MODE_MANUAL                      = 0,    /**< tm object created manually */
    BCMBAL_TM_CREATION_MODE_AUTO                        = 1,    /**< tm object created automatically */
    BCMBAL_TM_CREATION_MODE__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_creation_mode;

/** Scheduling Level for the Children TM  
 */
typedef enum bcmbal_tm_sched_child_type
{
    BCMBAL_TM_SCHED_CHILD_TYPE_QUEUE                    = 0,    /**< Queue-level scheduler */
    BCMBAL_TM_SCHED_CHILD_TYPE_SCHED                    = 1,    /**< Scheduler-level scheduler */
    BCMBAL_TM_SCHED_CHILD_TYPE__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_sched_child_type;

/** Traffic Direction 
 */
typedef enum bcmbal_tm_sched_dir
{
    BCMBAL_TM_SCHED_DIR_US                              = 1,    /**< Upstream */
    BCMBAL_TM_SCHED_DIR_DS                              = 2     /**< Downstream */
} bcmbal_tm_sched_dir;

/** TM Scheduler Owner Type 
 */
typedef enum bcmbal_tm_sched_owner_type
{
    BCMBAL_TM_SCHED_OWNER_TYPE_UNDEFINED                = 0,    /**< Undefined */
    BCMBAL_TM_SCHED_OWNER_TYPE_INTERFACE                = 1,    /**< Interface */
    BCMBAL_TM_SCHED_OWNER_TYPE_SUB_TERM                 = 2,    /**< Subscriber terminal */
    BCMBAL_TM_SCHED_OWNER_TYPE_AGG_PORT                 = 3,    /**< TM scheduler is owned by aggregation port */
    BCMBAL_TM_SCHED_OWNER_TYPE_UNI                      = 4,    /**< TM scheduler is owned by UNI port */
    BCMBAL_TM_SCHED_OWNER_TYPE_VIRTUAL                  = 5,    /**< Other unspecified owner */
    BCMBAL_TM_SCHED_OWNER_TYPE__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_sched_owner_type;

/** tm_sched_owner agg_port ID. 
 */
typedef enum bcmbal_tm_sched_owner_agg_port_id
{
    BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_NONE              = 0,
    BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_INTF_ID           = 0x0001,   /**< PON interface id */
    BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_SUB_TERM_ID       = 0x0002,   /**< Subscriber terminal id */
    BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_AGG_PORT_ID       = 0x0004,   /**< Aggregation port id */
    BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_ALL               = 0x0007    /**< All fields */
} bcmbal_tm_sched_owner_agg_port_id;

/** tm_sched_parent ID. 
 */
typedef enum bcmbal_tm_sched_parent_id
{
    BCMBAL_TM_SCHED_PARENT_ID_NONE                      = 0,
    BCMBAL_TM_SCHED_PARENT_ID_SCHED_ID                  = 0x0001,   /**< Parent scheduler id */
    BCMBAL_TM_SCHED_PARENT_ID_PRIORITY                  = 0x0002,   /**< Priority */
    BCMBAL_TM_SCHED_PARENT_ID_WEIGHT                    = 0x0004,   /**< Weight */
    BCMBAL_TM_SCHED_PARENT_ID_ALL                       = 0x0007    /**< All fields */
} bcmbal_tm_sched_parent_id;

/** Scheduler Type 
 */
typedef enum bcmbal_tm_sched_type
{
    BCMBAL_TM_SCHED_TYPE_NONE                           = 0,        /**< NO scheduling */
    BCMBAL_TM_SCHED_TYPE_WFQ                            = 1,        /**< Weighted Fair Queue */
    BCMBAL_TM_SCHED_TYPE_SP                             = 2,        /**< Strict Priority */
    BCMBAL_TM_SCHED_TYPE_SP_WFQ                         = 3,        /**< Hybrid SP + WFQ */
    BCMBAL_TM_SCHED_TYPE__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_sched_type;

/** tm_shaping ID. 
 */
typedef enum bcmbal_tm_shaping_id
{
    BCMBAL_TM_SHAPING_ID_NONE                           = 0,
    BCMBAL_TM_SHAPING_ID_CIR                            = 0x0001,   /**< Committed Information Rate (kbps) */
    BCMBAL_TM_SHAPING_ID_PIR                            = 0x0002,   /**< Peak Information Rate (kbps) */
    BCMBAL_TM_SHAPING_ID_BURST                          = 0x0004,   /**< Max Burst Bytes at Peak Bit Rate */
    BCMBAL_TM_SHAPING_ID_ALL                            = 0x0007    /**< All fields */
} bcmbal_tm_shaping_id;

/** Transceiver types 
 */
typedef enum bcmbal_trx_type
{
    BCMBAL_TRX_TYPE_GPON_SPS_43_48                      = 0,        /**< gpon_sps_43_48. */
    BCMBAL_TRX_TYPE_GPON_SPS_SOG_4321                   = 1,        /**< gpon_sps_sog_4321. */
    BCMBAL_TRX_TYPE_GPON_LTE_3680_M                     = 2,        /**< gpon_lte_3680_m. */
    BCMBAL_TRX_TYPE_GPON_SOURCE_PHOTONICS               = 3,        /**< gpon_source_photonics. */
    BCMBAL_TRX_TYPE_GPON_LTE_3680_P                     = 4,        /**< gpon_lte_3680_p. */
    BCMBAL_TRX_TYPE_XGPON_LTH_7222_PC                   = 5,        /**< xgpon_lth_7222_pc. */
    BCMBAL_TRX_TYPE_XGPON_LTH_7226_PC                   = 6,        /**< xgpon_lth_7226_pc. */
    BCMBAL_TRX_TYPE_XGPON_LTH_5302_PC                   = 7,        /**< xgpon_lth_5302_pc. */
    BCMBAL_TRX_TYPE_XGPON_LTH_7226_A_PC_PLUS            = 8,        /**< xgpon_lth_7226_a_pc_plus. */
    BCMBAL_TRX_TYPE__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_trx_type;

#define bcmbal_action_id_none                               BCMBAL_ACTION_ID_NONE
#define bcmbal_action_id_cmds_bitmask                       BCMBAL_ACTION_ID_CMDS_BITMASK
#define bcmbal_action_id_o_vid                              BCMBAL_ACTION_ID_O_VID
#define bcmbal_action_id_o_pbits                            BCMBAL_ACTION_ID_O_PBITS
#define bcmbal_action_id_o_tpid                             BCMBAL_ACTION_ID_O_TPID
#define bcmbal_action_id_i_vid                              BCMBAL_ACTION_ID_I_VID
#define bcmbal_action_id_i_pbits                            BCMBAL_ACTION_ID_I_PBITS
#define bcmbal_action_id_i_tpid                             BCMBAL_ACTION_ID_I_TPID
#define bcmbal_action_id_all                                BCMBAL_ACTION_ID_ALL
#define bcmbal_classifier_id_none                           BCMBAL_CLASSIFIER_ID_NONE
#define bcmbal_classifier_id_o_tpid                         BCMBAL_CLASSIFIER_ID_O_TPID
#define bcmbal_classifier_id_o_vid                          BCMBAL_CLASSIFIER_ID_O_VID
#define bcmbal_classifier_id_i_tpid                         BCMBAL_CLASSIFIER_ID_I_TPID
#define bcmbal_classifier_id_i_vid                          BCMBAL_CLASSIFIER_ID_I_VID
#define bcmbal_classifier_id_o_pbits                        BCMBAL_CLASSIFIER_ID_O_PBITS
#define bcmbal_classifier_id_i_pbits                        BCMBAL_CLASSIFIER_ID_I_PBITS
#define bcmbal_classifier_id_ether_type                     BCMBAL_CLASSIFIER_ID_ETHER_TYPE
#define bcmbal_classifier_id_dst_mac                        BCMBAL_CLASSIFIER_ID_DST_MAC
#define bcmbal_classifier_id_src_mac                        BCMBAL_CLASSIFIER_ID_SRC_MAC
#define bcmbal_classifier_id_ip_proto                       BCMBAL_CLASSIFIER_ID_IP_PROTO
#define bcmbal_classifier_id_dst_ip                         BCMBAL_CLASSIFIER_ID_DST_IP
#define bcmbal_classifier_id_src_ip                         BCMBAL_CLASSIFIER_ID_SRC_IP
#define bcmbal_classifier_id_src_port                       BCMBAL_CLASSIFIER_ID_SRC_PORT
#define bcmbal_classifier_id_dst_port                       BCMBAL_CLASSIFIER_ID_DST_PORT
#define bcmbal_classifier_id_pkt_tag_type                   BCMBAL_CLASSIFIER_ID_PKT_TAG_TYPE
#define bcmbal_classifier_id_all                            BCMBAL_CLASSIFIER_ID_ALL
#define bcmbal_extended_epon_dba_id_none                    BCMBAL_EXTENDED_EPON_DBA_ID_NONE
#define bcmbal_extended_epon_dba_id_polling_interval_us     BCMBAL_EXTENDED_EPON_DBA_ID_POLLING_INTERVAL_US
#define bcmbal_extended_epon_dba_id_grant_threshold_tq      BCMBAL_EXTENDED_EPON_DBA_ID_GRANT_THRESHOLD_TQ
#define bcmbal_extended_epon_dba_id_cir_priority            BCMBAL_EXTENDED_EPON_DBA_ID_CIR_PRIORITY
#define bcmbal_extended_epon_dba_id_cir_weight_tq           BCMBAL_EXTENDED_EPON_DBA_ID_CIR_WEIGHT_TQ
#define bcmbal_extended_epon_dba_id_pir_priority            BCMBAL_EXTENDED_EPON_DBA_ID_PIR_PRIORITY
#define bcmbal_extended_epon_dba_id_pir_weight_tq           BCMBAL_EXTENDED_EPON_DBA_ID_PIR_WEIGHT_TQ
#define bcmbal_extended_epon_dba_id_tdm_grant_size_tq       BCMBAL_EXTENDED_EPON_DBA_ID_TDM_GRANT_SIZE_TQ
#define bcmbal_extended_epon_dba_id_tdm_grant_interval_us   BCMBAL_EXTENDED_EPON_DBA_ID_TDM_GRANT_INTERVAL_US
#define bcmbal_extended_epon_dba_id_all                     BCMBAL_EXTENDED_EPON_DBA_ID_ALL
#define bcmbal_extended_itu_dba_id_none                     BCMBAL_EXTENDED_ITU_DBA_ID_NONE
#define bcmbal_extended_itu_dba_id_extra_bw_elig            BCMBAL_EXTENDED_ITU_DBA_ID_EXTRA_BW_ELIG
#define bcmbal_extended_itu_dba_id_nrt_cbr                  BCMBAL_EXTENDED_ITU_DBA_ID_NRT_CBR
#define bcmbal_extended_itu_dba_id_rt_cbr                   BCMBAL_EXTENDED_ITU_DBA_ID_RT_CBR
#define bcmbal_extended_itu_dba_id_rt_profile               BCMBAL_EXTENDED_ITU_DBA_ID_RT_PROFILE
#define bcmbal_extended_itu_dba_id_nrt_profile              BCMBAL_EXTENDED_ITU_DBA_ID_NRT_PROFILE
#define bcmbal_extended_itu_dba_id_all                      BCMBAL_EXTENDED_ITU_DBA_ID_ALL
#define bcmbal_sla_id_none                                  BCMBAL_SLA_ID_NONE
#define bcmbal_sla_id_min_rate                              BCMBAL_SLA_ID_MIN_RATE
#define bcmbal_sla_id_max_rate                              BCMBAL_SLA_ID_MAX_RATE
#define bcmbal_sla_id_all                                   BCMBAL_SLA_ID_ALL
#define bcmbal_tm_sched_owner_agg_port_id_none              BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_NONE
#define bcmbal_tm_sched_owner_agg_port_id_intf_id           BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_INTF_ID
#define bcmbal_tm_sched_owner_agg_port_id_sub_term_id       BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_SUB_TERM_ID
#define bcmbal_tm_sched_owner_agg_port_id_agg_port_id       BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_AGG_PORT_ID
#define bcmbal_tm_sched_owner_agg_port_id_all               BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_ALL
#define bcmbal_tm_sched_parent_id_none                      BCMBAL_TM_SCHED_PARENT_ID_NONE
#define bcmbal_tm_sched_parent_id_sched_id                  BCMBAL_TM_SCHED_PARENT_ID_SCHED_ID
#define bcmbal_tm_sched_parent_id_priority                  BCMBAL_TM_SCHED_PARENT_ID_PRIORITY
#define bcmbal_tm_sched_parent_id_weight                    BCMBAL_TM_SCHED_PARENT_ID_WEIGHT
#define bcmbal_tm_sched_parent_id_all                       BCMBAL_TM_SCHED_PARENT_ID_ALL
#define bcmbal_tm_shaping_id_none                           BCMBAL_TM_SHAPING_ID_NONE
#define bcmbal_tm_shaping_id_cir                            BCMBAL_TM_SHAPING_ID_CIR
#define bcmbal_tm_shaping_id_pir                            BCMBAL_TM_SHAPING_ID_PIR
#define bcmbal_tm_shaping_id_burst                          BCMBAL_TM_SHAPING_ID_BURST
#define bcmbal_tm_shaping_id_all                            BCMBAL_TM_SHAPING_ID_ALL

/** action. 
 */
typedef struct bcmbal_action
{
    bcmbal_action_id presence_mask;     /**< Presence Mask. */
    bcmbal_action_cmd_id cmds_bitmask;  /**< Commands bitmask. */
    uint16_t o_vid;                     /**< Outer vid. */
    uint8_t o_pbits;                    /**< Outer pbits. */
    uint16_t o_tpid;                    /**< Outer tpid. */
    uint16_t i_vid;                     /**< Inner vid. */
    uint8_t i_pbits;                    /**< Inner pbits. */
    uint16_t i_tpid;                    /**< Inner tpid. */
} bcmbal_action;

/** Variable-length list of aggregation_port_id. 
 */
typedef struct bcmbal_aggregation_port_id_list_u8
{
    uint8_t len;                        /**< List length. */
    bcmbal_aggregation_port_id *val;    /**< List contents. */
} bcmbal_aggregation_port_id_list_u8;

/** ber monitor parameters. 
 */
typedef struct bcmbal_ber_monitor_params
{
    uint8_t sf_threshold;   /**< Signal fail alarm is raised when BER raises to 10^-x, where x is this number. */
    uint8_t sd_threshold;   /**< Signal degrade alarm is raised when BER raises to 10^-x, where x is this number. */
} bcmbal_ber_monitor_params;

/** classifier. 
 */
typedef struct bcmbal_classifier
{
    bcmbal_classifier_id presence_mask; /**< Presence Mask. */
    uint16_t o_tpid;                    /**< Outer TPID of the packet to be classified */
    uint16_t o_vid;                     /**< Outer VID of the packet to be classified */
    uint16_t i_tpid;                    /**< Inner TPID of the packet to be classified */
    uint16_t i_vid;                     /**< Inner VID of the packet to be classified */
    uint8_t o_pbits;                    /**< Outer PBITS of the packet to be classified */
    uint8_t i_pbits;                    /**< Inner PBITS of the packet to be classified */
    uint16_t ether_type;                /**< Ethertype of the packet to be classified */
    bcmos_mac_address dst_mac;          /**< Destination MAC address of the packet to be classified */
    bcmos_mac_address src_mac;          /**< Source MAC address of the packet to be classified */
    uint8_t ip_proto;                   /**< IP protocol of the packet to be classified */
    bcmos_ipv4_address dst_ip;          /**< Destination IP address of the packet to be classified */
    bcmos_ipv4_address src_ip;          /**< Source IP address of the packet to be classified */
    uint16_t src_port;                  /**< Source port of the packet to be classified */
    uint16_t dst_port;                  /**< Destination port of the packet to be classified */
    bcmbal_pkt_tag_type pkt_tag_type;   /**< The tag type of the ingress packets */
} bcmbal_classifier;

/** Packet destination. 
 */
typedef struct bcmbal_dest
{
    bcmbal_dest_type type;              /**< packet destination. */
    union
    {
        struct
        {
            bcmbal_intf_id intf_id;     /**< Interface ID. */
        } nni;

        struct
        {
            bcmbal_sub_id sub_term_id;  /**< Subscriber terminal ID. */
            uint16_t sub_term_uni;      /**< Subscriber terminal UNI. */
            bcmbal_intf_id intf_id;     /**< Interface ID. */
        } sub_term;

        struct
        {
            bcmbal_service_port_id svc_port_id; /**< Service Port ID. */
            bcmbal_intf_id intf_id;             /**< Interface ID. */
        } svc_port;

        struct
        {
            bcmbal_sub_id sub_term_id;          /**< Subscriber terminal ID. */
            bcmbal_intf_id intf_id;             /**< Interface ID. */
        } itu_omci_channel;

        struct
        {
            bcmos_mac_address mac_address;      /**< MAC address for this link. */
            bcmbal_intf_id intf_id;             /**< Interface ID. */
        } ieee_oam_channel;
    } u;
} bcmbal_dest;

/** extended epon dba. 
 */
typedef struct bcmbal_extended_epon_dba
{
    bcmbal_extended_epon_dba_id presence_mask;      /**< Presence Mask. */
    bcmbal_polling_interval polling_interval_us;    /**< The amount of time between when this LLID last reported upstream data and when it will next be polled (approximate: rounded down to the nearest 65.536 us). */
    bcmbal_time_quanta grant_threshold_tq;          /**< Used to determine the maximum grant size that will be issued to this LLID (in TQ; rounded up to the nearest 128TQ; 1TQ = 16ns = 2Bytes@1G or 20Bytes@10G). */
    uint8_t cir_priority;                   /**< The priority of the CIR scheduling element. */
    bcmbal_time_quanta cir_weight_tq;       /**< The weight of the CIR scheduler (in TQ rounded up to nearest 128). Must be greater than or equal to Grant Threshold. */
    uint8_t pir_priority;                   /**< The priority of the PIR scheduling element. */
    bcmbal_time_quanta pir_weight_tq;       /**< The weight of the PIR scheduler (in TQ rounded up to nearest 128). Must be greater than or equal to Grant Threshold. */
    bcmbal_time_quanta tdm_grant_size_tq;   /**< Size of TDM grants (in TQ). */
    uint32_t tdm_grant_interval_us;         /**< Interval between TDM grants (in us). */
} bcmbal_extended_epon_dba;

/** Extended itu dba parameters 
 */
typedef struct bcmbal_extended_itu_dba
{
    bcmbal_extended_itu_dba_id presence_mask;   /**< Presence Mask. */
    bcmbal_extra_bw_eligibility_type extra_bw_elig; /**< Extra BW eligibility type */
    uint8_t nrt_cbr;        /**< NRT CBR */
    uint8_t rt_cbr;         /**< RT_CBR */
    uint8_t rt_profile;     /**< RT Profile */
    uint8_t nrt_profile;    /**< NRT Profile */
} bcmbal_extended_itu_dba;

/** Variable-length list of flow_id. 
 */
typedef struct bcmbal_flow_id_list_u32
{
    uint32_t len;           /**< List length. */
    bcmbal_flow_id *val;    /**< List contents. */
} bcmbal_flow_id_list_u32;

/** Queue Reference 
 */
typedef struct bcmbal_tm_queue_ref
{
    bcmbal_tm_sched_id sched_id;    /**< Scheduler (tm_sched) ID */
    bcmbal_tm_queue_id queue_id;    /**< Queue ID */
} bcmbal_tm_queue_ref;

/** Group Member Info. 
 */
typedef struct bcmbal_group_member_info
{
    bcmbal_intf_id intf_id;             /**< Access interface id for this member */
    bcmbal_service_port_id svc_port_id; /**< GPON/XGPON - The multicast "GEM" for this member. EPON - The multicast link identifier. */
    bcmbal_action action;               /**< VLAN actions */
    bcmbal_tm_queue_ref queue;          /**< Egress queue */
} bcmbal_group_member_info;

/** Variable-length list of group_member_info. 
 */
typedef struct bcmbal_group_member_info_list_u16
{
    uint16_t len;                   /**< List length. */
    bcmbal_group_member_info *val;  /**< List contents. */
} bcmbal_group_member_info_list_u16;

/** Password. 
 */
typedef struct bcmbal_password
{
    uint8_t arr[10];    /**< Array. */
} bcmbal_password;

/** pon_distance. 
 */
typedef struct bcmbal_pon_distance
{
    uint32_t max_log_distance;  /**< Max logical distance of a subscriber termainal on the interface */
    uint32_t max_diff_reach;    /**< Max distance between the closest and farthest subscriber terminal */
} bcmbal_pon_distance;

/** Registration id. 
 */
typedef struct bcmbal_registration_id
{
    uint8_t arr[36];    /**< ONU registration ID */
} bcmbal_registration_id;

/** Serial number. 
 */
typedef struct bcmbal_serial_number
{
    uint8_t vendor_id[4];       /**< vendor id. */
    uint8_t vendor_specific[4]; /**< vendor specific. */
} bcmbal_serial_number;

/** Variable-length list of service_port_id. 
 */
typedef struct bcmbal_service_port_id_list_u8
{
    uint8_t len;                    /**< List length. */
    bcmbal_service_port_id *val;    /**< List contents. */
} bcmbal_service_port_id_list_u8;

/** SLA. 
 */
typedef struct bcmbal_sla
{
    bcmbal_sla_id presence_mask;    /**< Presence Mask. */
    uint32_t min_rate;              /**< The minimal rate for this flow, in kilobits per second (optional) */
    uint32_t max_rate;              /**< The maximum rate for this flow, in kilobits per second (optional) */
} bcmbal_sla;

/** Variable-length list of sub_id. 
 */
typedef struct bcmbal_sub_id_list_u16
{
    uint16_t len;       /**< List length. */
    bcmbal_sub_id *val; /**< List contents. */
} bcmbal_sub_id_list_u16;

/** Subscriber Terminal Alarms. 
 */
typedef struct bcmbal_subscriber_terminal_alarms
{
    bcmbal_alarm_status los;            /**< LOS. */
    bcmbal_alarm_status lob;            /**< LOB. */
    bcmbal_alarm_status lopc_miss;      /**< LOPC miss. */
    bcmbal_alarm_status lopc_mic_error; /**< LOPC mic error. */
} bcmbal_subscriber_terminal_alarms;

/** Software version information 
 */
typedef struct bcmbal_sw_version
{
    bcmbal_version_type version_type;   /**< Release or debug version */
    uint8_t major_rev;                  /**< Major rev */
    uint8_t minor_rev;                  /**< Minor rev */
    uint8_t patch_rev;                  /**< Patch number */
    uint16_t om_version;                /**< BAL API Object Model version */
    uint32_t dev_point;                 /**< Development point - only valid for development versions, 0 otherwise */
} bcmbal_sw_version;

/** Random Early Discard Configuration 
 */
typedef struct bcmbal_tm_red
{
    bcmbal_percent min_threshold;   /**< Min threshold in percent of max queue size */
    bcmbal_percent max_threshold;   /**< Max threshold in percent of max queue size */
    bcmbal_percent max_probability; /**< Discard probability for occupancy between min_threshold and max_threshold */
} bcmbal_tm_red;

/** Queue Buffer Admission Control 
 */
typedef struct bcmbal_tm_bac
{
    bcmbal_tm_bac_type type;        /**< Buffer Admission Control Type */
    union
    {
        struct
        {
            uint32_t max_size;      /**< max number of packets in the queue */
        } taildrop;

        struct
        {
            bcmbal_tm_red red;      /**< Random Early Discard configuration */
        } red;

        struct
        {
            bcmbal_tm_red green;    /**< Green Random Early Discard Configuration */
            bcmbal_tm_red yellow;   /**< Yellow Random Early Discard Configuration */
            bcmbal_tm_red red;      /**< Red Random Early Discard Configuration */
        } wred;
    } u;
} bcmbal_tm_bac;

/** Variable-length list of tm_queue_id. 
 */
typedef struct bcmbal_tm_queue_id_list_u8
{
    uint8_t len;                /**< List length. */
    bcmbal_tm_queue_id *val;    /**< List contents. */
} bcmbal_tm_queue_id_list_u8;

/** Variable-length list of tm_sched_id. 
 */
typedef struct bcmbal_tm_sched_id_list_u8
{
    uint8_t len;                /**< List length. */
    bcmbal_tm_sched_id *val;    /**< List contents. */
} bcmbal_tm_sched_id_list_u8;

/** TM Scheduler Owner 
 */
typedef struct bcmbal_tm_sched_owner
{
    bcmbal_tm_sched_owner_type type;    /**< Owner type */
    union
    {
        struct
        {
            bcmbal_intf_type intf_type; /**< Interface Type */
            bcmbal_intf_id intf_id;     /**< Interface ID */
        } interface;

        struct
        {
            bcmbal_intf_id intf_id;     /**< PON interface id */
            bcmbal_sub_id sub_term_id;  /**< Subscriber terminal ID */
        } sub_term;

        struct
        {
            bcmbal_tm_sched_owner_agg_port_id presence_mask;    /**< Presence Mask. */
            bcmbal_intf_id intf_id;                 /**< PON interface id */
            bcmbal_sub_id sub_term_id;              /**< Subscriber terminal id */
            bcmbal_aggregation_port_id agg_port_id; /**< Aggregation port id */
        } agg_port;

        struct
        {
            bcmbal_intf_id intf_id;                 /**< PON interface id */
            bcmbal_sub_id sub_term_id;              /**< Subscriber terminal id */
            uint8_t idx;    /**< Index at subscriber terminal */
        } uni;

        struct
        {
            uint32_t idx;   /**< Owner index */
        } virtual;
    } u;
} bcmbal_tm_sched_owner;

/** Scheduling Parent Connect Point 
 */
typedef struct bcmbal_tm_sched_parent
{
    bcmbal_tm_sched_parent_id presence_mask;    /**< Presence Mask. */
    bcmbal_tm_sched_id sched_id;                /**< Parent scheduler id */
    bcmbal_tm_priority priority;                /**< Priority */
    bcmbal_tm_weight weight;                    /**< Weight */
} bcmbal_tm_sched_parent;

/** Shaping Parameters 
 */
typedef struct bcmbal_tm_shaping
{
    bcmbal_tm_shaping_id presence_mask; /**< Presence Mask. */
    uint32_t cir;                       /**< Committed Information Rate (kbps) */
    uint32_t pir;                       /**< Peak Information Rate (kbps) */
    uint32_t burst;                     /**< Max Burst Bytes at Peak Bit Rate */
} bcmbal_tm_shaping;

/** BAL topology. 
 */
typedef struct bcmbal_topology
{
    uint32_t num_of_nni_ports;              /**< The number of nni ports for the access_terminal */
    uint32_t num_of_pon_ports;              /**< The number of pon ports for the access_terminal */
    uint32_t num_of_mac_devs;               /**< The number of mac devices associated with this access_terminal */
    uint32_t num_of_pons_per_mac_dev;       /**< The number of pon ports per mac device in this access_terminal */
    bcmbal_pon_family pon_family;           /**< The PON family for the access_terminal */
    bcmbal_pon_sub_family pon_sub_family;   /**< The PON sub-family for the access_terminal */
} bcmbal_topology;

/** Variable-length list of U8. 
 */
typedef struct bcmbal_u8_list_u32_max_2048
{
    uint32_t len;   /**< List length. */
    uint8_t *val;   /**< List contents. */
} bcmbal_u8_list_u32_max_2048;

/** Structure definition for the "key" group of the "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_key
{
    bcmbal_access_id access_term_id;    /**< Reserved (set to 0) */
} bcmbal_access_terminal_key;

/** Structure definition for the "cfg" group of the "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_cfg_data
{
    bcmbal_state admin_state;       /**< Administrative state */
    bcmbal_status oper_status;      /**< Operational status */
    bcmbal_iwf_mode iwf_mode;       /**< The interworking mode */
    bcmbal_topology topology;       /**< Topology. */
    bcmbal_sw_version sw_version;   /**< Software version information */
} bcmbal_access_terminal_cfg_data;

/** Transport message definition for "cfg" group of "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_cfg
{
    bcmbal_cfg hdr;                 /**< Transport header. */
    bcmbal_access_terminal_key key; /**< Object key. */
    bcmbal_access_terminal_cfg_data data;   /**< All properties that must be set by the user. */
} bcmbal_access_terminal_cfg;

/** Structure definition for the "ind" group of the "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_ind_data
{
    bcmbal_state admin_state;       /**< Current administrative state */
    bcmbal_status oper_status;      /**< Current operational status */
    bcmbal_iwf_mode iwf_mode;       /**< The interworking mode */
    bcmbal_topology topology;       /**< Topology. */
    bcmbal_sw_version sw_version;   /**< Software version information */
} bcmbal_access_terminal_ind_data;

/** Transport message definition for "ind" group of "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_ind
{
    bcmbal_auto hdr;                        /**< Transport header. */
    bcmbal_access_terminal_key key;         /**< Object key. */
    bcmbal_access_terminal_ind_data data;   /**< All properties that must be set by the user. */
} bcmbal_access_terminal_ind;

/** Structure definition for the "oper_status_change" group of the 
 * "access_terminal" object. 
 *
 * An indication of a change of operational status 
 */
typedef struct bcmbal_access_terminal_oper_status_change_data
{
    bcmbal_status new_oper_status;  /**< The current oper status */
    bcmbal_status old_oper_status;  /**< The previous oper status before this indication was reported */
    bcmbal_state admin_state;       /**< The current admin status */
} bcmbal_access_terminal_oper_status_change_data;

/** Transport message definition for "oper_status_change" group of 
 * "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_oper_status_change
{
    bcmbal_auto hdr;                /**< Transport header. */
    bcmbal_access_terminal_key key; /**< Object key. */
    bcmbal_access_terminal_oper_status_change_data data;    /**< All properties that must be set by the user. */
} bcmbal_access_terminal_oper_status_change;

/** Structure definition for the "key" group of the "flow" object. 
 */
typedef struct bcmbal_flow_key
{
    bcmbal_flow_id flow_id;     /**< The ID of the flow object instance being referenced */
    bcmbal_flow_type flow_type; /**< The type of the flow, Upstream, Downstream, Broadcast or Multicast */
} bcmbal_flow_key;

/** Structure definition for the "cfg" group of the "flow" object. 
 */
typedef struct bcmbal_flow_cfg_data
{
    bcmbal_state admin_state;           /**< Administrative state */
    bcmbal_status oper_status;          /**< Operational status */
    bcmbal_intf_id access_int_id;       /**< The ID of the subscriber side interface; i.e. PON */
    bcmbal_intf_id network_int_id;      /**< The ID of the network side interface; i.e. NNI */
    bcmbal_sub_id sub_term_id;          /**< The ID of the subsccriber terminal device */
    uint8_t sub_term_uni_idx;           /**< The index of the subsccriber terminal uni port the flow is related to */
    bcmbal_service_port_id svc_port_id; /**< The ID of the service port (for GPON/XGPON - GEM ID; for EPON - abstract link identifier) */
    bcmos_bool resolve_mac;             /**< A flag indicating if the MAC address table should be used in DS service port resolution */
    bcmbal_classifier classifier;       /**< The classifier for this flow */
    bcmbal_action action;               /**< The action associated with the flow */
    bcmbal_cookie cookie;               /**< Application cookie */
    uint16_t priority;                  /**< Priority for this flow in case of multiple match. */
    bcmbal_group_id group_id;           /**< RW - The multicast group associated with this flow, valid for type MULTICAST only */
    bcmbal_tm_queue_ref queue;          /**< Egress queue */
    bcmbal_tm_sched_id dba_tm_sched_id; /**< A reference to an us tm_sched used for us dba for this flow */
} bcmbal_flow_cfg_data;

/** Transport message definition for "cfg" group of "flow" object. 
 */
typedef struct bcmbal_flow_cfg
{
    bcmbal_cfg hdr;             /**< Transport header. */
    bcmbal_flow_key key;        /**< Object key. */
    bcmbal_flow_cfg_data data;  /**< All properties that must be set by the user. */
} bcmbal_flow_cfg;

/** Structure definition for the "stat" group of the "flow" object. 
 */
typedef struct bcmbal_flow_stat_data
{
    uint64_t rx_packets;    /**< Received packets. */
    uint64_t rx_bytes;      /**< Received bytes. */
    uint64_t tx_packets;    /**< Transmitted packets. */
    uint64_t tx_bytes;      /**< Transmitted bytes. */
} bcmbal_flow_stat_data;

/** Transport message definition for "stat" group of "flow" object. 
 */
typedef struct bcmbal_flow_stat
{
    bcmbal_stat hdr;            /**< Transport header. */
    bcmbal_flow_key key;        /**< Object key. */
    bcmbal_flow_stat_data data; /**< All properties that must be set by the user. */
} bcmbal_flow_stat;

/** Structure definition for the "ind" group of the "flow" object. 
 */
typedef struct bcmbal_flow_ind_data
{
    bcmbal_state admin_state;           /**< Administrative state */
    bcmbal_status oper_status;          /**< Operational status */
    bcmbal_intf_id access_int_id;       /**< The ID of the subscriber side interface; i.e. PON */
    bcmbal_intf_id network_int_id;      /**< The ID of the network side interface; i.e. NNI */
    bcmbal_sub_id sub_term_id;          /**< The ID of the subsccriber terminal device */
    uint8_t sub_term_uni_idx;           /**< The index of the subsccriber terminal uni port the flow is related to */
    bcmbal_service_port_id svc_port_id; /**< The ID of the service port (for GPON/XGPON - GEM ID; for EPON - abstract link identifier) */
    bcmos_bool resolve_mac;             /**< A flag indicating if the MAC address table should be used in DS service port resolution */
    bcmbal_classifier classifier;       /**< The classifier for this flow */
    bcmbal_action action;               /**< The action associated with the flow */
    bcmbal_cookie cookie;               /**< Application cookie */
    uint16_t priority;                  /**< Priority for this flow in case of multiple match. */
    bcmbal_group_id group_id;           /**< RW - The multicast group associated with this flow, valid for type MULTICAST only */
    bcmbal_tm_queue_ref queue;          /**< Egress queue */
    bcmbal_tm_sched_id dba_tm_sched_id; /**< A reference to an us tm_sched used for us dba for this flow */
} bcmbal_flow_ind_data;

/** Transport message definition for "ind" group of "flow" object. 
 */
typedef struct bcmbal_flow_ind
{
    bcmbal_auto hdr;            /**< Transport header. */
    bcmbal_flow_key key;        /**< Object key. */
    bcmbal_flow_ind_data data;  /**< All properties that must be set by the user. */
} bcmbal_flow_ind;

/** Structure definition for the "oper_status_change" group of the "flow" 
 * object. 
 *
 * An indication of a change of operational status 
 */
typedef struct bcmbal_flow_oper_status_change_data
{
    bcmbal_status new_oper_status;      /**< The current oper status */
    bcmbal_status old_oper_status;      /**< The previous oper status before this indication was reported */
    bcmbal_state admin_state;           /**< The current admin status */
    uint16_t svc_port_id;               /**< The ID of the service port (for GPON/XGPON - GEM ID) */
    bcmbal_tm_sched_id dba_tm_sched_id; /**< A reference to an us tm_sched used for us dba for this flow */
    bcmbal_cookie cookie;               /**< Opaque application cookie associated with the flow (not interpreted by Maple) */
} bcmbal_flow_oper_status_change_data;

/** Transport message definition for "oper_status_change" group of "flow" 
 * object. 
 */
typedef struct bcmbal_flow_oper_status_change
{
    bcmbal_auto hdr;        /**< Transport header. */
    bcmbal_flow_key key;    /**< Object key. */
    bcmbal_flow_oper_status_change_data data;   /**< All properties that must be set by the user. */
} bcmbal_flow_oper_status_change;

/** Structure definition for the "key" group of the "group" object. 
 */
typedef struct bcmbal_group_key
{
    bcmbal_group_id group_id;   /**< The ID of the group object instance being referenced */
} bcmbal_group_key;

/** Structure definition for the "cfg" group of the "group" object. 
 */
typedef struct bcmbal_group_cfg_data
{
    bcmbal_group_member_cmd members_cmd;        /**< Membership operation commands. */
    bcmbal_group_member_info_list_u16 members;  /**< The list of members associated with this group */
    bcmbal_cookie cookie;                       /**< Application cookie */
    bcmbal_flow_id_list_u32 flows;              /**< List of flows associated with this group */
    bcmbal_group_owner owner;                   /**< Owner of the group. */
} bcmbal_group_cfg_data;

/** Transport message definition for "cfg" group of "group" object. 
 */
typedef struct bcmbal_group_cfg
{
    bcmbal_cfg hdr;             /**< Transport header. */
    bcmbal_group_key key;       /**< Object key. */
    bcmbal_group_cfg_data data; /**< All properties that must be set by the user. */
} bcmbal_group_cfg;

/** Structure definition for the "ind" group of the "group" object. 
 */
typedef struct bcmbal_group_ind_data
{
    bcmbal_group_member_cmd members_cmd;        /**< Membership operation commands. */
    bcmbal_group_member_info_list_u16 members;  /**< The list of members associated with this group */
    bcmbal_cookie cookie;                       /**< Application cookie */
    bcmbal_flow_id_list_u32 flows;              /**< List of flows associated with this group */
    bcmbal_group_owner owner;                   /**< Owner of the group. */
} bcmbal_group_ind_data;

/** Transport message definition for "ind" group of "group" object. 
 */
typedef struct bcmbal_group_ind
{
    bcmbal_auto hdr;            /**< Transport header. */
    bcmbal_group_key key;       /**< Object key. */
    bcmbal_group_ind_data data; /**< All properties that must be set by the user. */
} bcmbal_group_ind;

/** Structure definition for the "key" group of the "interface" object. 
 */
typedef struct bcmbal_interface_key
{
    bcmbal_intf_id intf_id;     /**< intf_id. */
    bcmbal_intf_type intf_type; /**< intf_type. */
} bcmbal_interface_key;

/** Structure definition for the "cfg" group of the "interface" object. 
 */
typedef struct bcmbal_interface_cfg_data
{
    bcmbal_state admin_state;   /**< Administrative state */
    bcmbal_status oper_status;  /**< Operational status */
    bcmbal_aggregation_port_id min_data_agg_port_id;    /**< The minimum agg_port_id that is allowed in the system */
    bcmbal_service_port_id min_data_svc_port_id;        /**< The minimum svc_port_id that is allowed in the system */
    bcmbal_trx_type transceiver_type;                   /**< The transceiver type used on an interface. N/A for EPON. */
    bcmbal_ds_miss_mode ds_miss_mode;                   /**< Defines the action to take for unknown downstream packets */
    uint16_t mtu;                   /**< The MTU for an interface */
    bcmbal_control flow_control;    /**< Flow control enable or disable */
    bcmbal_tm_sched_id ds_tm;       /**< Downstream scheduler and shaper */
    bcmbal_tm_sched_id us_tm;       /**< Upstream scheduler and shaper */
    bcmbal_sub_id_list_u16 sub_term_id_list;    /**< A list of subscriber terminal ids configured on this interface */
    bcmbal_pon_distance pon_distance;           /**< pon inetrface distance parameters */
    bcmbal_ber_monitor_params ber_monitor;      /**< BER monitor process configuration */
    uint32_t us_bandwidth_limit;                /**< us_bandwidth_limit. */
    bcmbal_control ds_fec;                      /**< enable/disable  ds fec (gpon only) */
} bcmbal_interface_cfg_data;

/** Transport message definition for "cfg" group of "interface" object. 
 */
typedef struct bcmbal_interface_cfg
{
    bcmbal_cfg hdr;                 /**< Transport header. */
    bcmbal_interface_key key;       /**< Object key. */
    bcmbal_interface_cfg_data data; /**< All properties that must be set by the user. */
} bcmbal_interface_cfg;

/** Structure definition for the "stat" group of the "interface" object. 
 */
typedef struct bcmbal_interface_stat_data
{
    uint64_t rx_bytes;          /**< RFC 2233 */
    uint64_t rx_packets;        /**< RFC 1213 ucast + none-ucast */
    uint64_t rx_ucast_packets;  /**< RFC 2233 */
    uint64_t rx_mcast_packets;  /**< RFC 2233 */
    uint64_t rx_bcast_packets;  /**< RFC 2233 */
    uint64_t rx_error_packets;  /**< RFC 1213 */
    uint64_t rx_unknown_protos; /**< RFC 1213 */
    uint64_t tx_bytes;          /**< RFC 2233 */
    uint64_t tx_packets;        /**< RFC 1213 ucast + none-ucast */
    uint64_t tx_ucast_packets;  /**< RFC 2233 */
    uint64_t tx_mcast_packets;  /**< RFC 2233 */
    uint64_t tx_bcast_packets;  /**< RFC 2233 */
    uint64_t tx_error_packets;  /**< RFC 1213 */
    uint64_t rx_crc_errors;     /**< Received packets with CRC error. */
    uint64_t bip_errors;        /**< Received bip errors (bip8 for gpon, bip32 for xgpon). */
} bcmbal_interface_stat_data;

/** Transport message definition for "stat" group of "interface" object. 
 */
typedef struct bcmbal_interface_stat
{
    bcmbal_stat hdr;                    /**< Transport header. */
    bcmbal_interface_key key;           /**< Object key. */
    bcmbal_interface_stat_data data;    /**< All properties that must be set by the user. */
} bcmbal_interface_stat;

/** Structure definition for the "ind" group of the "interface" object. 
 */
typedef struct bcmbal_interface_ind_data
{
    bcmbal_state admin_state;   /**< Administrative state */
    bcmbal_status oper_status;  /**< Operational status */
    bcmbal_aggregation_port_id min_data_agg_port_id;    /**< The minimum agg_port_id that is allowed in the system */
    bcmbal_service_port_id min_data_svc_port_id;        /**< The minimum svc_port_id that is allowed in the system */
    bcmbal_trx_type transceiver_type;                   /**< The transceiver type used on an interface */
    bcmbal_ds_miss_mode ds_miss_mode;                   /**< Defines the action to take for unknown downstream packets */
    uint16_t mtu;                   /**< The MTU for an interface */
    bcmbal_control flow_control;    /**< Flow control enable or disable */
    bcmbal_tm_sched_id ds_tm;       /**< Downstream scheduler and shaper */
    bcmbal_tm_sched_id us_tm;       /**< Upstream scheduler and shaper */
    bcmbal_sub_id_list_u16 sub_term_id_list;    /**< A list of subscriber terminal ids configured on this interface */
    bcmbal_pon_distance pon_distance;           /**< pon_distance. */
    bcmbal_ber_monitor_params ber_monitor;      /**< ber_monitor. */
    uint32_t us_bandwidth_limit;                /**< us_bandwidth_limit. */
    bcmbal_control ds_fec;                      /**< enable/disable  ds fec (gpon only) */
} bcmbal_interface_ind_data;

/** Transport message definition for "ind" group of "interface" object. 
 */
typedef struct bcmbal_interface_ind
{
    bcmbal_auto hdr;                /**< Transport header. */
    bcmbal_interface_key key;       /**< Object key. */
    bcmbal_interface_ind_data data; /**< All properties that must be set by the user. */
} bcmbal_interface_ind;

/** Structure definition for the "los" group of the "interface" object. 
 *
 * An indication of a change olt los alarm 
 */
typedef struct bcmbal_interface_los_data
{
    bcmbal_alarm_status status; /**< The current admin status */
} bcmbal_interface_los_data;

/** Transport message definition for "los" group of "interface" object. 
 */
typedef struct bcmbal_interface_los
{
    bcmbal_auto hdr;                /**< Transport header. */
    bcmbal_interface_key key;       /**< Object key. */
    bcmbal_interface_los_data data; /**< All properties that must be set by the user. */
} bcmbal_interface_los;

/** Structure definition for the "oper_status_change" group of the "interface" 
 * object. 
 *
 * An indication of a change of operational status 
 */
typedef struct bcmbal_interface_oper_status_change_data
{
    bcmbal_status new_oper_status;  /**< The current oper status */
    bcmbal_status old_oper_status;  /**< The previous oper status before this indication was reported */
    bcmbal_state admin_state;       /**< The current admin status */
} bcmbal_interface_oper_status_change_data;

/** Transport message definition for "oper_status_change" group of "interface" 
 * object. 
 */
typedef struct bcmbal_interface_oper_status_change
{
    bcmbal_auto hdr;            /**< Transport header. */
    bcmbal_interface_key key;   /**< Object key. */
    bcmbal_interface_oper_status_change_data data;  /**< All properties that must be set by the user. */
} bcmbal_interface_oper_status_change;

/** Structure definition for the "key" group of the "packet" object. 
 */
typedef struct bcmbal_packet_key
{
    uint32_t reserved;              /**< Reserved key field. */
    bcmbal_dest packet_send_dest;   /**< Packet destination. */
} bcmbal_packet_key;

/** Structure definition for the "cfg" group of the "packet" object. 
 */
typedef struct bcmbal_packet_cfg_data
{
    bcmbal_flow_id flow_id;             /**< N/A for sending a packet */
    bcmbal_flow_type flow_type;         /**< Flow Type. */
    bcmbal_intf_id intf_id;             /**< Interface ID. */
    bcmbal_intf_type intf_type;         /**< Interface Type. */
    bcmbal_service_port_id svc_port;    /**< N/A for sending a packet */
    bcmbal_cookie flow_cookie;          /**< N/A for sending a packet */
    bcmbal_u8_list_u32_max_2048 pkt;    /**< Packet Data. */
} bcmbal_packet_cfg_data;

/** Transport message definition for "cfg" group of "packet" object. 
 */
typedef struct bcmbal_packet_cfg
{
    bcmbal_cfg hdr;                 /**< Transport header. */
    bcmbal_packet_key key;          /**< Object key. */
    bcmbal_packet_cfg_data data;    /**< All properties that must be set by the user. */
} bcmbal_packet_cfg;

/** Structure definition for the "bearer_channel_rx" group of the "packet" 
 * object. 
 */
typedef struct bcmbal_packet_bearer_channel_rx_data
{
    bcmbal_flow_id flow_id;             /**< N/A for sending a packet */
    bcmbal_flow_type flow_type;         /**< Flow Type. */
    bcmbal_intf_id intf_id;             /**< Interface ID. */
    bcmbal_intf_type intf_type;         /**< Interface Type. */
    bcmbal_service_port_id svc_port;    /**< N/A for sending a packet */
    bcmbal_cookie flow_cookie;          /**< N/A for sending a packet */
    bcmbal_u8_list_u32_max_2048 pkt;    /**< Packet Data. */
} bcmbal_packet_bearer_channel_rx_data;

/** Transport message definition for "bearer_channel_rx" group of "packet" 
 * object. 
 */
typedef struct bcmbal_packet_bearer_channel_rx
{
    bcmbal_auto hdr;        /**< Transport header. */
    bcmbal_packet_key key;  /**< Object key. */
    bcmbal_packet_bearer_channel_rx_data data;  /**< All properties that must be set by the user. */
} bcmbal_packet_bearer_channel_rx;

/** Structure definition for the "ieee_oam_channel_rx" group of the "packet" 
 * object. 
 *
 * Rx indication on the IEEE OAM channel 
 */
typedef struct bcmbal_packet_ieee_oam_channel_rx_data
{
    bcmbal_u8_list_u32_max_2048 pkt;    /**< Packet Data. */
} bcmbal_packet_ieee_oam_channel_rx_data;

/** Transport message definition for "ieee_oam_channel_rx" group of "packet" 
 * object. 
 */
typedef struct bcmbal_packet_ieee_oam_channel_rx
{
    bcmbal_auto hdr;        /**< Transport header. */
    bcmbal_packet_key key;  /**< Object key. */
    bcmbal_packet_ieee_oam_channel_rx_data data;    /**< All properties that must be set by the user. */
} bcmbal_packet_ieee_oam_channel_rx;

/** Structure definition for the "itu_omci_channel_rx" group of the "packet" 
 * object. 
 *
 * Rx indication on the ITU OMCI channel 
 */
typedef struct bcmbal_packet_itu_omci_channel_rx_data
{
    bcmbal_u8_list_u32_max_2048 pkt;    /**< Packet Data. */
} bcmbal_packet_itu_omci_channel_rx_data;

/** Transport message definition for "itu_omci_channel_rx" group of "packet" 
 * object. 
 */
typedef struct bcmbal_packet_itu_omci_channel_rx
{
    bcmbal_auto hdr;        /**< Transport header. */
    bcmbal_packet_key key;  /**< Object key. */
    bcmbal_packet_itu_omci_channel_rx_data data;    /**< All properties that must be set by the user. */
} bcmbal_packet_itu_omci_channel_rx;

/** Structure definition for the "key" group of the "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_key
{
    bcmbal_sub_id sub_term_id;  /**< sub_term_id. */
    bcmbal_intf_id intf_id;     /**< intf_id. */
} bcmbal_subscriber_terminal_key;

/** Structure definition for the "cfg" group of the "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_cfg_data
{
    bcmbal_state admin_state;               /**< Administrative state */
    bcmbal_status oper_status;              /**< Operational status */
    bcmbal_serial_number serial_number;     /**< The serial number of an  ITU PON (GPON/XG-PON1/XGS-PON/NG-PON2) subscriber terminal */
    bcmbal_password password;               /**< The password of a GPON subscriber terminal */
    bcmbal_registration_id registration_id; /**< ONU registration ID of an  ITU PON (XG-PON1/XGS-PON/NG-PON2) subscriber terminal */
    bcmbal_service_port_id svc_port_id;     /**< The management service port ID (for PON, the ONU ID) */
    bcmos_mac_address mac_address;          /**< The Ethernet MAC address of an EPON subscriber terminal */
    bcmbal_tm_sched_id ds_tm;               /**< Downstream scheduler and shaper */
    bcmbal_tm_sched_id us_tm;               /**< Upstream scheduler and shaper */
    bcmbal_service_port_id_list_u8 svc_port_id_list;        /**< A list of bearer traffic svc_port_ids associated with this subscriber terminal */
    bcmbal_aggregation_port_id_list_u8 agg_port_id_list;    /**< A list of aggr_port_ids associated with this subscriber terminal */
    bcmbal_sub_term_rate sub_term_rate;                     /**< sub_term_rate. */
    bcmbal_control us_fec;  /**< enable/disable us fec */
} bcmbal_subscriber_terminal_cfg_data;

/** Transport message definition for "cfg" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_cfg
{
    bcmbal_cfg hdr;                     /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_cfg_data data;   /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_cfg;

/** Structure definition for the "stat" group of the "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_stat_data
{
    uint64_t rx_packets;    /**< Received packets on specified object */
    uint64_t rx_bytes;      /**< Received bytes on specified object */
    uint64_t tx_packets;    /**< Transmitted packets on specified object */
    uint64_t tx_bytes;      /**< Transmittted bytes on specified object */
} bcmbal_subscriber_terminal_stat_data;

/** Transport message definition for "stat" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_stat
{
    bcmbal_stat hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_stat_data data;  /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_stat;

/** Structure definition for the "dgi" group of the "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_dgi_data
{
    bcmbal_alarm_status dgi_status; /**< dgi_status. */
} bcmbal_subscriber_terminal_dgi_data;

/** Transport message definition for "dgi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_dgi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_dgi_data data;   /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_dgi;

/** Structure definition for the "dowi" group of the "subscriber_terminal" 
 * object. 
 *
 * drift of window 
 */
typedef struct bcmbal_subscriber_terminal_dowi_data
{
    bcmbal_alarm_status dowi_status;    /**< dowi alarm status */
    uint32_t drift_value;               /**< Calculated amount of drift (positive + negative as a signed value). */
    uint32_t new_eqd;                   /**< New EQD after drift is corrected (only valid if status is 'on').  */
} bcmbal_subscriber_terminal_dowi_data;

/** Transport message definition for "dowi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_dowi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_dowi_data data;  /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_dowi;

/** Structure definition for the "ind" group of the "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_ind_data
{
    bcmbal_state admin_state;               /**< Administrative state */
    bcmbal_status oper_status;              /**< Operational status */
    bcmbal_serial_number serial_number;     /**< The serial number of an  ITU PON (GPON/XG-PON1/XGS-PON/NG-PON2) subscriber terminal */
    bcmbal_password password;               /**< The password of a GPON subscriber terminal */
    bcmbal_registration_id registration_id; /**< ONU registration ID of an  ITU PON (XG-PON1/XGS-PON/NG-PON2) subscriber terminal */
    bcmbal_service_port_id svc_port_id;     /**< The management service port ID (for PON, the ONU ID) */
    bcmos_mac_address mac_address;          /**< The Ethernet MAC address of an EPON subscriber terminal */
    bcmbal_tm_sched_id ds_tm;               /**< Downstream scheduler and shaper */
    bcmbal_tm_sched_id us_tm;               /**< Upstream scheduler and shaper */
    bcmbal_service_port_id_list_u8 svc_port_id_list;        /**< A list of bearer traffic svc_port_ids associated with this subscriber terminal */
    bcmbal_aggregation_port_id_list_u8 agg_port_id_list;    /**< A list of aggr_port_ids associated with this subscriber terminal */
    bcmbal_sub_term_rate sub_term_rate;                     /**< sub_term_rate. */
    bcmbal_control us_efc;  /**< us_fec. */
} bcmbal_subscriber_terminal_ind_data;

/** Transport message definition for "ind" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_ind
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_ind_data data;   /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_ind;

/** Structure definition for the "looci" group of the "subscriber_terminal" 
 * object. 
 *
 * loss of omci channel 
 */
typedef struct bcmbal_subscriber_terminal_looci_data
{
    bcmbal_alarm_status looci_status;   /**< status of loocs alarm */
} bcmbal_subscriber_terminal_looci_data;

/** Transport message definition for "looci" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_looci
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_looci_data data; /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_looci;

/** Structure definition for the "oper_status_change" group of the 
 * "subscriber_terminal" object. 
 *
 * An indication of a change of operational status 
 */
typedef struct bcmbal_subscriber_terminal_oper_status_change_data
{
    bcmbal_status new_oper_status;  /**< The current oper status */
    bcmbal_status old_oper_status;  /**< The previous oper status before this indication was reported */
    bcmbal_state admin_state;       /**< The current admin status */
} bcmbal_subscriber_terminal_oper_status_change_data;

/** Transport message definition for "oper_status_change" group of 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_oper_status_change
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_oper_status_change_data data;    /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_oper_status_change;

/** Structure definition for the "sdi" group of the "subscriber_terminal" 
 * object. 
 *
 * signal degraded 
 */
typedef struct bcmbal_subscriber_terminal_sdi_data
{
    bcmbal_alarm_status sdi_status; /**< sdi alarm status */
    uint32_t ber;                   /**<  Inverse bit error rate (e.g. if this number is 1000, the BER is 1/1000). */
} bcmbal_subscriber_terminal_sdi_data;

/** Transport message definition for "sdi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_sdi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sdi_data data;   /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sdi;

/** Structure definition for the "sfi" group of the "subscriber_terminal" 
 * object. 
 *
 * signal fail 
 */
typedef struct bcmbal_subscriber_terminal_sfi_data
{
    bcmbal_alarm_status sfi_status; /**< sfi alarm status */
    uint32_t ber;                   /**<  Inverse bit error rate (e.g. if this number is 1000, the BER is 1/1000). */
} bcmbal_subscriber_terminal_sfi_data;

/** Transport message definition for "sfi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_sfi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sfi_data data;   /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sfi;

/** Structure definition for the "sub_term_alarm" group of the 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_sub_term_alarm_data
{
    bcmbal_subscriber_terminal_alarms alarm;    /**< The serial number of an  ITU PON (GPON/XG-PON1/XGS-PON/NG-PON2) subscriber terminal */
} bcmbal_subscriber_terminal_sub_term_alarm_data;

/** Transport message definition for "sub_term_alarm" group of 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_sub_term_alarm
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sub_term_alarm_data data;    /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sub_term_alarm;

/** Structure definition for the "sub_term_disc" group of the 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_sub_term_disc_data
{
    bcmbal_serial_number serial_number; /**< The serial number of an  ITU PON (GPON/XG-PON1/XGS-PON/NG-PON2) subscriber terminal */
} bcmbal_subscriber_terminal_sub_term_disc_data;

/** Transport message definition for "sub_term_disc" group of 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_sub_term_disc
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sub_term_disc_data data; /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sub_term_disc;

/** Structure definition for the "sufi" group of the "subscriber_terminal" 
 * object. 
 *
 * start up failure 
 */
typedef struct bcmbal_subscriber_terminal_sufi_data
{
    bcmbal_alarm_status sufi_status;    /**< sufi alarm status */
} bcmbal_subscriber_terminal_sufi_data;

/** Transport message definition for "sufi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_sufi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sufi_data data;  /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sufi;

/** Structure definition for the "tiwi" group of the "subscriber_terminal" 
 * object. 
 *
 * transmission interference 
 */
typedef struct bcmbal_subscriber_terminal_tiwi_data
{
    bcmbal_alarm_status tiwi_status;    /**< tiwi alarm status */
    uint32_t drift_value;               /**<  Calculated amount of drift (positive + negative as a signed value). */
} bcmbal_subscriber_terminal_tiwi_data;

/** Transport message definition for "tiwi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_tiwi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_tiwi_data data;  /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_tiwi;

/** Structure definition for the "key" group of the "tm_queue" object. 
 */
typedef struct bcmbal_tm_queue_key
{
    bcmbal_tm_sched_id sched_id;    /**< Scheduler that owns the queue */
    bcmbal_tm_sched_dir sched_dir;  /**< sched dir. */
    bcmbal_tm_queue_id id;          /**< Queue id */
} bcmbal_tm_queue_key;

/** Structure definition for the "cfg" group of the "tm_queue" object. 
 */
typedef struct bcmbal_tm_queue_cfg_data
{
    bcmbal_tm_priority priority;            /**< Scheduling priority */
    bcmbal_tm_weight weight;                /**< Scheduling weight */
    bcmbal_tm_shaping rate;                 /**< Rate shaping parameters */
    bcmbal_tm_bac bac;                      /**< Buffer admission control */
    bcmbal_tm_creation_mode creation_mode;  /**< Creation mode */
    uint8_t ref_count;                      /**< reference count (flows) */
} bcmbal_tm_queue_cfg_data;

/** Transport message definition for "cfg" group of "tm_queue" object. 
 */
typedef struct bcmbal_tm_queue_cfg
{
    bcmbal_cfg hdr;                 /**< Transport header. */
    bcmbal_tm_queue_key key;        /**< Object key. */
    bcmbal_tm_queue_cfg_data data;  /**< All properties that must be set by the user. */
} bcmbal_tm_queue_cfg;

/** Structure definition for the "stat" group of the "tm_queue" object. 
 */
typedef struct bcmbal_tm_queue_stat_data
{
    uint64_t packets_ok;        /**< Packets transmitted succewssfully */
    uint64_t bytes_ok;          /**< Bytes transmitted successfully */
    uint64_t packets_discarded; /**< Packets discarded */
    uint64_t bytes_discarded;   /**< Bytes discarded */
} bcmbal_tm_queue_stat_data;

/** Transport message definition for "stat" group of "tm_queue" object. 
 */
typedef struct bcmbal_tm_queue_stat
{
    bcmbal_stat hdr;                /**< Transport header. */
    bcmbal_tm_queue_key key;        /**< Object key. */
    bcmbal_tm_queue_stat_data data; /**< All properties that must be set by the user. */
} bcmbal_tm_queue_stat;

/** Structure definition for the "ind" group of the "tm_queue" object. 
 *
 * tm queue indication 
 */
typedef struct bcmbal_tm_queue_ind_data
{
    bcmbal_tm_priority priority;    /**< priority. */
    bcmbal_tm_weight weight;        /**< weight. */
    bcmbal_tm_shaping rate;         /**< rate. */
    bcmbal_tm_bac bac;              /**< bac. */
    bcmbal_tm_creation_mode create_mode;    /**< create_mode. */
    uint8_t ref_count;                      /**< ref_count. */
} bcmbal_tm_queue_ind_data;

/** Transport message definition for "ind" group of "tm_queue" object. 
 */
typedef struct bcmbal_tm_queue_ind
{
    bcmbal_auto hdr;                /**< Transport header. */
    bcmbal_tm_queue_key key;        /**< Object key. */
    bcmbal_tm_queue_ind_data data;  /**< All properties that must be set by the user. */
} bcmbal_tm_queue_ind;

/** Structure definition for the "key" group of the "tm_sched" object. 
 */
typedef struct bcmbal_tm_sched_key
{
    bcmbal_tm_sched_dir dir;    /**< Traffic direction */
    bcmbal_tm_sched_id id;      /**< ID */
} bcmbal_tm_sched_key;

/** Structure definition for the "cfg" group of the "tm_sched" object. 
 */
typedef struct bcmbal_tm_sched_cfg_data
{
    bcmbal_tm_sched_owner owner;            /**< The owner of the tm_sched object instance */
    bcmbal_tm_sched_type sched_type;        /**< Scheduler type */
    bcmbal_tm_sched_parent sched_parent;    /**< Scheduling parameters for parent scheduler */
    bcmbal_tm_sched_child_type sched_child_type;    /**< Scheduling type of all child tm objects */
    uint8_t num_priorities;                 /**< Max number of strict priority scheduling elements */
    bcmbal_tm_shaping rate;                 /**< Rate shaping parameters */
    bcmbal_extended_itu_dba ext_itu_dba;    /**< Extended itu dba parameters for an agg_port owned tm_sched */
    bcmbal_extended_epon_dba ext_epon_dba;  /**< epon dba parameters for an agg_port owned tm_sched */
    bcmbal_tm_creation_mode creation_mode;  /**< Creation mode */
    bcmbal_tm_queue_id_list_u8 queues;      /**< Subsidiary queues */
    bcmbal_tm_sched_id_list_u8 sub_scheds;  /**< Subsidiary schedulers */
} bcmbal_tm_sched_cfg_data;

/** Transport message definition for "cfg" group of "tm_sched" object. 
 */
typedef struct bcmbal_tm_sched_cfg
{
    bcmbal_cfg hdr;                 /**< Transport header. */
    bcmbal_tm_sched_key key;        /**< Object key. */
    bcmbal_tm_sched_cfg_data data;  /**< All properties that must be set by the user. */
} bcmbal_tm_sched_cfg;

/** Structure definition for the "ind" group of the "tm_sched" object. 
 *
 * Tm Sched Indication 
 */
typedef struct bcmbal_tm_sched_ind_data
{
    bcmbal_tm_sched_owner owner;        /**< The owner of the tm_sched object instance */
    bcmbal_tm_sched_type sched_type;    /**< Scheduler type */
    bcmbal_tm_sched_parent sched_parent;            /**< Scheduling parameters for parent scheduler */
    bcmbal_tm_sched_child_type sched_child_type;    /**< Scheduling type of all child tm objects */
    uint8_t num_priorities;                 /**< Max number of strict priority scheduling elements */
    bcmbal_tm_shaping rate;                 /**< Rate shaping parameters */
    bcmbal_extended_itu_dba ext_itu_dba;    /**< Extended itu dba parameters for an agg_port owned tm_sched */
    bcmbal_extended_epon_dba ext_epon_dba;  /**< epon dba parameters for an agg_port owned tm_sched */
    bcmbal_tm_creation_mode creation_mode;  /**< Creation mode */
    bcmbal_tm_queue_id_list_u8 queues;      /**< Subsidiary queues */
    bcmbal_tm_sched_id_list_u8 sub_scheds;  /**< Subsidiary schedulers */
} bcmbal_tm_sched_ind_data;

/** Transport message definition for "ind" group of "tm_sched" object. 
 */
typedef struct bcmbal_tm_sched_ind
{
    bcmbal_auto hdr;                /**< Transport header. */
    bcmbal_tm_sched_key key;        /**< Object key. */
    bcmbal_tm_sched_ind_data data;  /**< All properties that must be set by the user. */
} bcmbal_tm_sched_ind;

typedef bcmbal_access_id bcmbal_access_term_id;

/** @} */
#endif /* BAL_MODEL_TYPES */
