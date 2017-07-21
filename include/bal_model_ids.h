#ifndef BAL_MODEL_IDS_H_
#define BAL_MODEL_IDS_H_

/** \ingroup object_model_data_types
 * \defgroup object_model_enums BAL Object Model Enumerations
 */

/** \addtogroup object_model_enums
 * @{
 */
#include <bcmos_system.h>

/** Identifiers for all properties contained in the access_terminal_cfg group. 
 */
typedef enum bcmbal_access_terminal_cfg_id
{
    BCMBAL_ACCESS_TERMINAL_CFG_ID_ADMIN_STATE   = 0,                    /**< Administrative state. */
    BCMBAL_ACCESS_TERMINAL_CFG_ID_OPER_STATUS   = 1,                    /**< Operational status. */
    BCMBAL_ACCESS_TERMINAL_CFG_ID_IWF_MODE      = 2,                    /**< Interworking function mode. */
    BCMBAL_ACCESS_TERMINAL_CFG_ID_TOPOLOGY      = 3,                    /**< Topology. */
    BCMBAL_ACCESS_TERMINAL_CFG_ID_SW_VERSION    = 4,                    /**< Software version. */
    BCMBAL_ACCESS_TERMINAL_CFG_ID__NUM_OF                               /**< Number of enum entries, not an entry itself. */
} bcmbal_access_terminal_cfg_id;

/** Identifiers for all properties contained in the access_terminal_ind group. 
 */
typedef enum bcmbal_access_terminal_ind_id
{
    BCMBAL_ACCESS_TERMINAL_IND_ID_ADMIN_STATE   = 0,                    /**< Administrative state. */
    BCMBAL_ACCESS_TERMINAL_IND_ID_OPER_STATUS   = 1,                    /**< Operational status. */
    BCMBAL_ACCESS_TERMINAL_IND_ID_IWF_MODE      = 2,                    /**< Interworking function mode. */
    BCMBAL_ACCESS_TERMINAL_IND_ID_TOPOLOGY      = 3,                    /**< Topology. */
    BCMBAL_ACCESS_TERMINAL_IND_ID_SW_VERSION    = 4,                    /**< Software version. */
    BCMBAL_ACCESS_TERMINAL_IND_ID__NUM_OF                               /**< Number of enum entries, not an entry itself. */
} bcmbal_access_terminal_ind_id;

/** Identifiers for all properties contained in the access_terminal_key group. 
 */
typedef enum bcmbal_access_terminal_key_id
{
    BCMBAL_ACCESS_TERMINAL_KEY_ID_ACCESS_TERM_ID= 0,                    /**< access_term_id. */
    BCMBAL_ACCESS_TERMINAL_KEY_ID__NUM_OF                               /**< Number of enum entries, not an entry itself. */
} bcmbal_access_terminal_key_id;

/** Identifiers for all properties contained in the 
 * access_terminal_oper_status_change group. 
 */
typedef enum bcmbal_access_terminal_oper_status_change_id
{
    BCMBAL_ACCESS_TERMINAL_OPER_STATUS_CHANGE_ID_NEW_OPER_STATUS= 0,    /**< current oper status. */
    BCMBAL_ACCESS_TERMINAL_OPER_STATUS_CHANGE_ID_OLD_OPER_STATUS= 1,    /**< old oper status. */
    BCMBAL_ACCESS_TERMINAL_OPER_STATUS_CHANGE_ID_ADMIN_STATE    = 2,    /**< current admin state. */
    BCMBAL_ACCESS_TERMINAL_OPER_STATUS_CHANGE_ID__NUM_OF                /**< Number of enum entries, not an entry itself. */
} bcmbal_access_terminal_oper_status_change_id;

/** Identifiers for all properties contained in the flow_cfg group. 
 */
typedef enum bcmbal_flow_cfg_id
{
    BCMBAL_FLOW_CFG_ID_ADMIN_STATE                              = 0,    /**< Administrative state. */
    BCMBAL_FLOW_CFG_ID_OPER_STATUS                              = 1,    /**< Operational status. */
    BCMBAL_FLOW_CFG_ID_ACCESS_INT_ID                            = 2,    /**< Access Interface ID. */
    BCMBAL_FLOW_CFG_ID_NETWORK_INT_ID                           = 3,    /**< Network Interface ID. */
    BCMBAL_FLOW_CFG_ID_SUB_TERM_ID                              = 4,    /**< Subscriber Terminal ID. */
    BCMBAL_FLOW_CFG_ID_SUB_TERM_UNI_IDX                         = 5,    /**< Subscriber Terminal uni port index. */
    BCMBAL_FLOW_CFG_ID_SVC_PORT_ID                              = 6,    /**< Service Port ID. */
    BCMBAL_FLOW_CFG_ID_RESOLVE_MAC                              = 7,    /**< Resolve mac. */
    BCMBAL_FLOW_CFG_ID_CLASSIFIER                               = 8,    /**< Classifier. */
    BCMBAL_FLOW_CFG_ID_ACTION                                   = 9,    /**< Action. */
    BCMBAL_FLOW_CFG_ID_COOKIE                                   = 10,   /**< Cookie. */
    BCMBAL_FLOW_CFG_ID_PRIORITY                                 = 11,   /**< Priority. */
    BCMBAL_FLOW_CFG_ID_GROUP_ID                                 = 12,   /**< Group ID. */
    BCMBAL_FLOW_CFG_ID_QUEUE                                    = 13,   /**< Egress queue. */
    BCMBAL_FLOW_CFG_ID_DBA_TM_SCHED_ID                          = 14,   /**< tm_sched for us dba. */
    BCMBAL_FLOW_CFG_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_flow_cfg_id;

/** Identifiers for all properties contained in the flow_ind group. 
 */
typedef enum bcmbal_flow_ind_id
{
    BCMBAL_FLOW_IND_ID_ADMIN_STATE                              = 0,    /**< Administrative state. */
    BCMBAL_FLOW_IND_ID_OPER_STATUS                              = 1,    /**< Operational status. */
    BCMBAL_FLOW_IND_ID_ACCESS_INT_ID                            = 2,    /**< Access Interface ID. */
    BCMBAL_FLOW_IND_ID_NETWORK_INT_ID                           = 3,    /**< Network Interface ID. */
    BCMBAL_FLOW_IND_ID_SUB_TERM_ID                              = 4,    /**< Subscriber Terminal ID. */
    BCMBAL_FLOW_IND_ID_SUB_TERM_UNI_IDX                         = 5,    /**< Subscriber Terminal uni port index. */
    BCMBAL_FLOW_IND_ID_SVC_PORT_ID                              = 6,    /**< Service Port ID. */
    BCMBAL_FLOW_IND_ID_RESOLVE_MAC                              = 7,    /**< Resolve mac. */
    BCMBAL_FLOW_IND_ID_CLASSIFIER                               = 8,    /**< Classifier. */
    BCMBAL_FLOW_IND_ID_ACTION                                   = 9,    /**< Action. */
    BCMBAL_FLOW_IND_ID_COOKIE                                   = 10,   /**< Cookie. */
    BCMBAL_FLOW_IND_ID_PRIORITY                                 = 11,   /**< Priority. */
    BCMBAL_FLOW_IND_ID_GROUP_ID                                 = 12,   /**< Group ID. */
    BCMBAL_FLOW_IND_ID_QUEUE                                    = 13,   /**< Egress queue. */
    BCMBAL_FLOW_IND_ID_DBA_TM_SCHED_ID                          = 14,   /**< tm_sched for us dba. */
    BCMBAL_FLOW_IND_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_flow_ind_id;

/** Identifiers for all properties contained in the flow_key group. 
 */
typedef enum bcmbal_flow_key_id
{
    BCMBAL_FLOW_KEY_ID_FLOW_ID                                  = 0,    /**< Flow ID. */
    BCMBAL_FLOW_KEY_ID_FLOW_TYPE                                = 1,    /**< Flow type. */
    BCMBAL_FLOW_KEY_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_flow_key_id;

/** Identifiers for all properties contained in the flow_oper_status_change 
 * group. 
 */
typedef enum bcmbal_flow_oper_status_change_id
{
    BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_NEW_OPER_STATUS           = 0,    /**< current oper status. */
    BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_OLD_OPER_STATUS           = 1,    /**< old oper status. */
    BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_ADMIN_STATE               = 2,    /**< current admin state. */
    BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_SVC_PORT_ID               = 3,    /**< Service port ID. */
    BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_DBA_TM_SCHED_ID           = 4,    /**< tm_sched for us dba. */
    BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_COOKIE                    = 5,    /**< Cookie. */
    BCMBAL_FLOW_OPER_STATUS_CHANGE_ID__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_flow_oper_status_change_id;

/** Identifiers for all properties contained in the flow_stat group. 
 */
typedef enum bcmbal_flow_stat_id
{
    BCMBAL_FLOW_STAT_ID_RX_PACKETS                              = 0,    /**< Received packets. */
    BCMBAL_FLOW_STAT_ID_RX_BYTES                                = 1,    /**< Received bytes. */
    BCMBAL_FLOW_STAT_ID_TX_PACKETS                              = 2,    /**< Transmitted packets. */
    BCMBAL_FLOW_STAT_ID_TX_BYTES                                = 3,    /**< Transmitted bytes. */
    BCMBAL_FLOW_STAT_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_flow_stat_id;

/** Identifiers for all properties contained in the group_cfg group. 
 */
typedef enum bcmbal_group_cfg_id
{
    BCMBAL_GROUP_CFG_ID_MEMBERS_CMD                             = 0,    /**< Membership operation commands. */
    BCMBAL_GROUP_CFG_ID_MEMBERS                                 = 1,    /**< Member. */
    BCMBAL_GROUP_CFG_ID_COOKIE                                  = 2,    /**< Application cookie. */
    BCMBAL_GROUP_CFG_ID_FLOWS                                   = 3,    /**< List of flows associated with the group . */
    BCMBAL_GROUP_CFG_ID_OWNER                                   = 4,    /**< Owner of the group. */
    BCMBAL_GROUP_CFG_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_group_cfg_id;

/** Identifiers for all properties contained in the group_ind group. 
 */
typedef enum bcmbal_group_ind_id
{
    BCMBAL_GROUP_IND_ID_MEMBERS_CMD                             = 0,    /**< Membership operation commands. */
    BCMBAL_GROUP_IND_ID_MEMBERS                                 = 1,    /**< Member. */
    BCMBAL_GROUP_IND_ID_COOKIE                                  = 2,    /**< Application cookie. */
    BCMBAL_GROUP_IND_ID_FLOWS                                   = 3,    /**< List of flows associated with the group . */
    BCMBAL_GROUP_IND_ID_OWNER                                   = 4,    /**< Owner of the group. */
    BCMBAL_GROUP_IND_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_group_ind_id;

/** Identifiers for all properties contained in the group_key group. 
 */
typedef enum bcmbal_group_key_id
{
    BCMBAL_GROUP_KEY_ID_GROUP_ID                                = 0,    /**< Group ID. */
    BCMBAL_GROUP_KEY_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_group_key_id;

/** Identifiers for all properties contained in the interface_cfg group. 
 */
typedef enum bcmbal_interface_cfg_id
{
    BCMBAL_INTERFACE_CFG_ID_ADMIN_STATE                         = 0,    /**< Administrative state. */
    BCMBAL_INTERFACE_CFG_ID_OPER_STATUS                         = 1,    /**< Operational status. */
    BCMBAL_INTERFACE_CFG_ID_MIN_DATA_AGG_PORT_ID                = 2,    /**< Minimum aggregate port ID. */
    BCMBAL_INTERFACE_CFG_ID_MIN_DATA_SVC_PORT_ID                = 3,    /**< Minimum service port ID. */
    BCMBAL_INTERFACE_CFG_ID_TRANSCEIVER_TYPE                    = 4,    /**< Transceiver type. */
    BCMBAL_INTERFACE_CFG_ID_DS_MISS_MODE                        = 5,    /**< Downstream unknown packet action. */
    BCMBAL_INTERFACE_CFG_ID_MTU                                 = 6,    /**< MTU. */
    BCMBAL_INTERFACE_CFG_ID_FLOW_CONTROL                        = 7,    /**< Flow control. */
    BCMBAL_INTERFACE_CFG_ID_DS_TM                               = 8,    /**< Downstream scheduler and shaper. */
    BCMBAL_INTERFACE_CFG_ID_US_TM                               = 9,    /**< Upstream scheduler and shaper. */
    BCMBAL_INTERFACE_CFG_ID_SUB_TERM_ID_LIST                    = 10,   /**< Sub-term id list. */
    BCMBAL_INTERFACE_CFG_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_interface_cfg_id;

/** Identifiers for all properties contained in the interface_ind group. 
 */
typedef enum bcmbal_interface_ind_id
{
    BCMBAL_INTERFACE_IND_ID_ADMIN_STATE                         = 0,    /**< Administrative state. */
    BCMBAL_INTERFACE_IND_ID_OPER_STATUS                         = 1,    /**< Operational status. */
    BCMBAL_INTERFACE_IND_ID_MIN_DATA_AGG_PORT_ID                = 2,    /**< Minimum aggregate port ID. */
    BCMBAL_INTERFACE_IND_ID_MIN_DATA_SVC_PORT_ID                = 3,    /**< Minimum service port ID. */
    BCMBAL_INTERFACE_IND_ID_TRANSCEIVER_TYPE                    = 4,    /**< Transceiver type. */
    BCMBAL_INTERFACE_IND_ID_DS_MISS_MODE                        = 5,    /**< Downstream unknown packet action. */
    BCMBAL_INTERFACE_IND_ID_MTU                                 = 6,    /**< MTU. */
    BCMBAL_INTERFACE_IND_ID_FLOW_CONTROL                        = 7,    /**< Flow control. */
    BCMBAL_INTERFACE_IND_ID_DS_TM                               = 8,    /**< Downstream scheduler and shaper. */
    BCMBAL_INTERFACE_IND_ID_US_TM                               = 9,    /**< Upstream scheduler and shaper. */
    BCMBAL_INTERFACE_IND_ID_SUB_TERM_ID_LIST                    = 10,   /**< Sub-term id list. */
    BCMBAL_INTERFACE_IND_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_interface_ind_id;

/** Identifiers for all properties contained in the interface_key group. 
 */
typedef enum bcmbal_interface_key_id
{
    BCMBAL_INTERFACE_KEY_ID_INTF_ID                             = 0,    /**< intf_id. */
    BCMBAL_INTERFACE_KEY_ID_INTF_TYPE                           = 1,    /**< intf_type. */
    BCMBAL_INTERFACE_KEY_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_interface_key_id;

/** Identifiers for all properties contained in the interface_los group. 
 */
typedef enum bcmbal_interface_los_id
{
    BCMBAL_INTERFACE_LOS_ID_STATUS                              = 0,    /**< status. */
    BCMBAL_INTERFACE_LOS_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_interface_los_id;

/** Identifiers for all properties contained in the interface_oper_status_change 
 * group. 
 */
typedef enum bcmbal_interface_oper_status_change_id
{
    BCMBAL_INTERFACE_OPER_STATUS_CHANGE_ID_NEW_OPER_STATUS      = 0,    /**< current oper status. */
    BCMBAL_INTERFACE_OPER_STATUS_CHANGE_ID_OLD_OPER_STATUS      = 1,    /**< old oper status. */
    BCMBAL_INTERFACE_OPER_STATUS_CHANGE_ID_ADMIN_STATE          = 2,    /**< current admin state. */
    BCMBAL_INTERFACE_OPER_STATUS_CHANGE_ID__NUM_OF                      /**< Number of enum entries, not an entry itself. */
} bcmbal_interface_oper_status_change_id;

/** Identifiers for all properties contained in the interface_stat group. 
 */
typedef enum bcmbal_interface_stat_id
{
    BCMBAL_INTERFACE_STAT_ID_RX_BYTES                           = 0,    /**< Received bytes. */
    BCMBAL_INTERFACE_STAT_ID_RX_PACKETS                         = 1,    /**< Recieved packets. */
    BCMBAL_INTERFACE_STAT_ID_RX_UCAST_PACKETS                   = 2,    /**< Received unicast packets. */
    BCMBAL_INTERFACE_STAT_ID_RX_MCAST_PACKETS                   = 3,    /**< Received multicast packets. */
    BCMBAL_INTERFACE_STAT_ID_RX_BCAST_PACKETS                   = 4,    /**< Received broadcast packets. */
    BCMBAL_INTERFACE_STAT_ID_RX_ERROR_PACKETS                   = 5,    /**< Received error packets. */
    BCMBAL_INTERFACE_STAT_ID_RX_UNKNOWN_PROTOS                  = 6,    /**< Received unknown-proto packets. */
    BCMBAL_INTERFACE_STAT_ID_TX_BYTES                           = 7,    /**< Transmitted bytes. */
    BCMBAL_INTERFACE_STAT_ID_TX_PACKETS                         = 8,    /**< Transmitted packets. */
    BCMBAL_INTERFACE_STAT_ID_TX_UCAST_PACKETS                   = 9,    /**< Transmitted unicast packets. */
    BCMBAL_INTERFACE_STAT_ID_TX_MCAST_PACKETS                   = 10,   /**< Transmitted multicast packets. */
    BCMBAL_INTERFACE_STAT_ID_TX_BCAST_PACKETS                   = 11,   /**< Transmitted broadcast packets. */
    BCMBAL_INTERFACE_STAT_ID_TX_ERROR_PACKETS                   = 12,   /**< Transmitted error packets. */
    BCMBAL_INTERFACE_STAT_ID_RX_CRC_ERRORS                      = 13,   /**< Received packets with CRC error. */
    BCMBAL_INTERFACE_STAT_ID_BIP_ERRORS                         = 14,   /**< Received bip errors (bip8 for gpon, bip32 for xgpon). */
    BCMBAL_INTERFACE_STAT_ID__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_interface_stat_id;

/** Identifiers for all properties contained in the packet_bearer_channel_rx 
 * group. 
 */
typedef enum bcmbal_packet_bearer_channel_rx_id
{
    BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_FLOW_ID                  = 0,    /**< Flow Id. */
    BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_FLOW_TYPE                = 1,    /**< Flow Type. */
    BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_INTF_ID                  = 2,    /**< Interface ID. */
    BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_INTF_TYPE                = 3,    /**< Interface Type. */
    BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_SVC_PORT                 = 4,    /**< Service Port. */
    BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_FLOW_COOKIE              = 5,    /**< Flow Cookie. */
    BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_PKT                      = 6,    /**< Packet Data. */
    BCMBAL_PACKET_BEARER_CHANNEL_RX_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_packet_bearer_channel_rx_id;

/** Identifiers for all properties contained in the packet_cfg group. 
 */
typedef enum bcmbal_packet_cfg_id
{
    BCMBAL_PACKET_CFG_ID_FLOW_ID                                = 0,    /**< Flow Id. */
    BCMBAL_PACKET_CFG_ID_FLOW_TYPE                              = 1,    /**< Flow Type. */
    BCMBAL_PACKET_CFG_ID_INTF_ID                                = 2,    /**< Interface ID. */
    BCMBAL_PACKET_CFG_ID_INTF_TYPE                              = 3,    /**< Interface Type. */
    BCMBAL_PACKET_CFG_ID_SVC_PORT                               = 4,    /**< Service Port. */
    BCMBAL_PACKET_CFG_ID_FLOW_COOKIE                            = 5,    /**< Flow Cookie. */
    BCMBAL_PACKET_CFG_ID_PKT                                    = 6,    /**< Packet Data. */
    BCMBAL_PACKET_CFG_ID__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_packet_cfg_id;

/** Identifiers for all properties contained in the packet_ieee_oam_channel_rx 
 * group. 
 */
typedef enum bcmbal_packet_ieee_oam_channel_rx_id
{
    BCMBAL_PACKET_IEEE_OAM_CHANNEL_RX_ID_PKT                    = 0,    /**< Packet Data. */
    BCMBAL_PACKET_IEEE_OAM_CHANNEL_RX_ID__NUM_OF                        /**< Number of enum entries, not an entry itself. */
} bcmbal_packet_ieee_oam_channel_rx_id;

/** Identifiers for all properties contained in the packet_itu_omci_channel_rx 
 * group. 
 */
typedef enum bcmbal_packet_itu_omci_channel_rx_id
{
    BCMBAL_PACKET_ITU_OMCI_CHANNEL_RX_ID_PKT                    = 0,    /**< Packet Data. */
    BCMBAL_PACKET_ITU_OMCI_CHANNEL_RX_ID__NUM_OF                        /**< Number of enum entries, not an entry itself. */
} bcmbal_packet_itu_omci_channel_rx_id;

/** Identifiers for all properties contained in the packet_key group. 
 */
typedef enum bcmbal_packet_key_id
{
    BCMBAL_PACKET_KEY_ID_RESERVED                               = 0,    /**< Reserved key field. */
    BCMBAL_PACKET_KEY_ID_PACKET_SEND_DEST                       = 1,    /**< Packet destination. */
    BCMBAL_PACKET_KEY_ID__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_packet_key_id;

/** Identifiers for all properties contained in the subscriber_terminal_cfg 
 * group. 
 */
typedef enum bcmbal_subscriber_terminal_cfg_id
{
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_ADMIN_STATE               = 0,    /**< Administrative state. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_OPER_STATUS               = 1,    /**< Operational status. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_SERIAL_NUMBER             = 2,    /**< Serial number. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_PASSWORD                  = 3,    /**< Password. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_REGISTRATION_ID           = 4,    /**< Registration id. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_SVC_PORT_ID               = 5,    /**< Service port ID. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_MAC_ADDRESS               = 6,    /**< MAC address. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_DS_TM                     = 7,    /**< Downstream scheduler and shaper. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_US_TM                     = 8,    /**< Upstream scheduler and shaper. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_SVC_PORT_ID_LIST          = 9,    /**< svc_port_id list. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_AGG_PORT_ID_LIST          = 10,   /**< agg_port_id list. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_SUB_TERM_RATE             = 11,   /**< sub_term_rate. */
    BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_subscriber_terminal_cfg_id;

/** Identifiers for all properties contained in the subscriber_terminal_dgi 
 * group. 
 */
typedef enum bcmbal_subscriber_terminal_dgi_id
{
    BCMBAL_SUBSCRIBER_TERMINAL_DGI_ID_DGI_STATUS                = 0,    /**< dgi_status. */
    BCMBAL_SUBSCRIBER_TERMINAL_DGI_ID__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_subscriber_terminal_dgi_id;

/** Identifiers for all properties contained in the subscriber_terminal_ind 
 * group. 
 */
typedef enum bcmbal_subscriber_terminal_ind_id
{
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_ADMIN_STATE               = 0,    /**< Administrative state. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_OPER_STATUS               = 1,    /**< Operational status. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_SERIAL_NUMBER             = 2,    /**< Serial number. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_PASSWORD                  = 3,    /**< Password. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_REGISTRATION_ID           = 4,    /**< Registration id. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_SVC_PORT_ID               = 5,    /**< Service port ID. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_MAC_ADDRESS               = 6,    /**< MAC address. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_DS_TM                     = 7,    /**< Downstream scheduler and shaper. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_US_TM                     = 8,    /**< Upstream scheduler and shaper. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_SVC_PORT_ID_LIST          = 9,    /**< svc_port_id list. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_AGG_PORT_ID_LIST          = 10,   /**< agg_port_id list. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_SUB_TERM_RATE             = 11,   /**< sub_term_rate. */
    BCMBAL_SUBSCRIBER_TERMINAL_IND_ID__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_subscriber_terminal_ind_id;

/** Identifiers for all properties contained in the subscriber_terminal_key 
 * group. 
 */
typedef enum bcmbal_subscriber_terminal_key_id
{
    BCMBAL_SUBSCRIBER_TERMINAL_KEY_ID_SUB_TERM_ID               = 0,    /**< sub_term_id. */
    BCMBAL_SUBSCRIBER_TERMINAL_KEY_ID_INTF_ID                   = 1,    /**< intf_id. */
    BCMBAL_SUBSCRIBER_TERMINAL_KEY_ID__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_subscriber_terminal_key_id;

/** Identifiers for all properties contained in the 
 * subscriber_terminal_oper_status_change group. 
 */
typedef enum bcmbal_subscriber_terminal_oper_status_change_id
{
    BCMBAL_SUBSCRIBER_TERMINAL_OPER_STATUS_CHANGE_ID_NEW_OPER_STATUS= 0,    /**< current oper status. */
    BCMBAL_SUBSCRIBER_TERMINAL_OPER_STATUS_CHANGE_ID_OLD_OPER_STATUS= 1,    /**< old oper status. */
    BCMBAL_SUBSCRIBER_TERMINAL_OPER_STATUS_CHANGE_ID_ADMIN_STATE    = 2,    /**< current admin state. */
    BCMBAL_SUBSCRIBER_TERMINAL_OPER_STATUS_CHANGE_ID__NUM_OF                /**< Number of enum entries, not an entry itself. */
} bcmbal_subscriber_terminal_oper_status_change_id;

/** Identifiers for all properties contained in the subscriber_terminal_stat 
 * group. 
 */
typedef enum bcmbal_subscriber_terminal_stat_id
{
    BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID_RX_PACKETS                   = 0,    /**< Received  packets. */
    BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID_RX_BYTES                     = 1,    /**< Received bytes. */
    BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID_TX_PACKETS                   = 2,    /**< Transmitted packets. */
    BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID_TX_BYTES                     = 3,    /**< Transmitted bytes. */
    BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_subscriber_terminal_stat_id;

/** Identifiers for all properties contained in the 
 * subscriber_terminal_sub_term_alarm group. 
 */
typedef enum bcmbal_subscriber_terminal_sub_term_alarm_id
{
    BCMBAL_SUBSCRIBER_TERMINAL_SUB_TERM_ALARM_ID_ALARM              = 0,    /**< Alarm. */
    BCMBAL_SUBSCRIBER_TERMINAL_SUB_TERM_ALARM_ID__NUM_OF                    /**< Number of enum entries, not an entry itself. */
} bcmbal_subscriber_terminal_sub_term_alarm_id;

/** Identifiers for all properties contained in the 
 * subscriber_terminal_sub_term_disc group. 
 */
typedef enum bcmbal_subscriber_terminal_sub_term_disc_id
{
    BCMBAL_SUBSCRIBER_TERMINAL_SUB_TERM_DISC_ID_SERIAL_NUMBER       = 0,    /**< Serial number. */
    BCMBAL_SUBSCRIBER_TERMINAL_SUB_TERM_DISC_ID__NUM_OF                     /**< Number of enum entries, not an entry itself. */
} bcmbal_subscriber_terminal_sub_term_disc_id;

/** Identifiers for all properties contained in the tm_queue_cfg group. 
 */
typedef enum bcmbal_tm_queue_cfg_id
{
    BCMBAL_TM_QUEUE_CFG_ID_PRIORITY                                 = 0,    /**< priority. */
    BCMBAL_TM_QUEUE_CFG_ID_WEIGHT                                   = 1,    /**< weight. */
    BCMBAL_TM_QUEUE_CFG_ID_RATE                                     = 2,    /**< rate. */
    BCMBAL_TM_QUEUE_CFG_ID_BAC                                      = 3,    /**< bac. */
    BCMBAL_TM_QUEUE_CFG_ID_CREATION_MODE                            = 4,    /**< creation_mode. */
    BCMBAL_TM_QUEUE_CFG_ID_REF_COUNT                                = 5,    /**< ref_count. */
    BCMBAL_TM_QUEUE_CFG_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_queue_cfg_id;

/** Identifiers for all properties contained in the tm_queue_ind group. 
 */
typedef enum bcmbal_tm_queue_ind_id
{
    BCMBAL_TM_QUEUE_IND_ID_PRIORITY                                 = 0,    /**< priority. */
    BCMBAL_TM_QUEUE_IND_ID_WEIGHT                                   = 1,    /**< weight. */
    BCMBAL_TM_QUEUE_IND_ID_RATE                                     = 2,    /**< rate. */
    BCMBAL_TM_QUEUE_IND_ID_BAC                                      = 3,    /**< bac. */
    BCMBAL_TM_QUEUE_IND_ID_CREATE_MODE                              = 4,    /**< create_mode. */
    BCMBAL_TM_QUEUE_IND_ID_REF_COUNT                                = 5,    /**< ref_count. */
    BCMBAL_TM_QUEUE_IND_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_queue_ind_id;

/** Identifiers for all properties contained in the tm_queue_key group. 
 */
typedef enum bcmbal_tm_queue_key_id
{
    BCMBAL_TM_QUEUE_KEY_ID_SCHED_ID                                 = 0,    /**< sched_id. */
    BCMBAL_TM_QUEUE_KEY_ID_SCHED_DIR                                = 1,    /**< sched dir. */
    BCMBAL_TM_QUEUE_KEY_ID_ID                                       = 2,    /**< id. */
    BCMBAL_TM_QUEUE_KEY_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_queue_key_id;

/** Identifiers for all properties contained in the tm_queue_stat group. 
 */
typedef enum bcmbal_tm_queue_stat_id
{
    BCMBAL_TM_QUEUE_STAT_ID_PACKETS_OK                              = 0,    /**< packets_ok. */
    BCMBAL_TM_QUEUE_STAT_ID_BYTES_OK                                = 1,    /**< bytes_ok. */
    BCMBAL_TM_QUEUE_STAT_ID_PACKETS_DISCARDED                       = 2,    /**< packets_discarded. */
    BCMBAL_TM_QUEUE_STAT_ID_BYTES_DISCARDED                         = 3,    /**< bytes_discarded. */
    BCMBAL_TM_QUEUE_STAT_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_queue_stat_id;

/** Identifiers for all properties contained in the tm_sched_cfg group. 
 */
typedef enum bcmbal_tm_sched_cfg_id
{
    BCMBAL_TM_SCHED_CFG_ID_OWNER                                    = 0,    /**< owner. */
    BCMBAL_TM_SCHED_CFG_ID_SCHED_TYPE                               = 1,    /**< type. */
    BCMBAL_TM_SCHED_CFG_ID_SCHED_PARENT                             = 2,    /**< parent. */
    BCMBAL_TM_SCHED_CFG_ID_SCHED_CHILD_TYPE                         = 3,    /**< child_type. */
    BCMBAL_TM_SCHED_CFG_ID_NUM_PRIORITIES                           = 4,    /**< num_priorities. */
    BCMBAL_TM_SCHED_CFG_ID_RATE                                     = 5,    /**< rate. */
    BCMBAL_TM_SCHED_CFG_ID_EXT_ITU_DBA                              = 6,    /**< extended itu dba. */
    BCMBAL_TM_SCHED_CFG_ID_EXT_EPON_DBA                             = 7,    /**< extended epon dba. */
    BCMBAL_TM_SCHED_CFG_ID_CREATION_MODE                            = 8,    /**< creation_mode. */
    BCMBAL_TM_SCHED_CFG_ID_QUEUES                                   = 9,    /**< queues. */
    BCMBAL_TM_SCHED_CFG_ID_SUB_SCHEDS                               = 10,   /**< sub_scheds. */
    BCMBAL_TM_SCHED_CFG_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_sched_cfg_id;

/** Identifiers for all properties contained in the tm_sched_ind group. 
 */
typedef enum bcmbal_tm_sched_ind_id
{
    BCMBAL_TM_SCHED_IND_ID_OWNER                                    = 0,    /**< owner. */
    BCMBAL_TM_SCHED_IND_ID_SCHED_TYPE                               = 1,    /**< type. */
    BCMBAL_TM_SCHED_IND_ID_SCHED_PARENT                             = 2,    /**< parent. */
    BCMBAL_TM_SCHED_IND_ID_SCHED_CHILD_TYPE                         = 3,    /**< child_type. */
    BCMBAL_TM_SCHED_IND_ID_NUM_PRIORITIES                           = 4,    /**< num_priorities. */
    BCMBAL_TM_SCHED_IND_ID_RATE                                     = 5,    /**< rate. */
    BCMBAL_TM_SCHED_IND_ID_EXT_ITU_DBA                              = 6,    /**< extended itu dba. */
    BCMBAL_TM_SCHED_IND_ID_EXT_EPON_DBA                             = 7,    /**< extended epon dba. */
    BCMBAL_TM_SCHED_IND_ID_CREATION_MODE                            = 8,    /**< creation_mode. */
    BCMBAL_TM_SCHED_IND_ID_QUEUES                                   = 9,    /**< queues. */
    BCMBAL_TM_SCHED_IND_ID_SUB_SCHEDS                               = 10,   /**< sub_scheds. */
    BCMBAL_TM_SCHED_IND_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_sched_ind_id;

/** Identifiers for all properties contained in the tm_sched_key group. 
 */
typedef enum bcmbal_tm_sched_key_id
{
    BCMBAL_TM_SCHED_KEY_ID_DIR                                      = 0,    /**< dir. */
    BCMBAL_TM_SCHED_KEY_ID_ID                                       = 1,    /**< id. */
    BCMBAL_TM_SCHED_KEY_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_sched_key_id;

/** All object tags for all objects in the system. 
 */
typedef enum bcmbal_obj_tag
{
    BCMBAL_OBJ_TAG__NUM_OF          /**< Number of enum entries, not an entry itself. */
} bcmbal_obj_tag;

/** Identifiers for all objects in the system. 
 */
typedef enum bcmbal_obj_id
{
    BCMBAL_OBJ_ID__BEGIN,
    BCMBAL_OBJ_ID_ACCESS_TERMINAL                                   = 0,    /**< BAL Access Terminal */
    BCMBAL_OBJ_ID_FLOW                                              = 1,    /**< BAL Flow */
    BCMBAL_OBJ_ID_GROUP                                             = 2,    /**< BAL Group */
    BCMBAL_OBJ_ID_INTERFACE                                         = 3,    /**< BAL Interface */
    BCMBAL_OBJ_ID_PACKET                                            = 4,    /**< packet */
    BCMBAL_OBJ_ID_SUBSCRIBER_TERMINAL                               = 5,    /**< BAL Subscriber Terminal */
    BCMBAL_OBJ_ID_TM_QUEUE                                          = 6,    /**< tm_queue */
    BCMBAL_OBJ_ID_TM_SCHED                                          = 7,    /**< tm_sched */
    BCMBAL_OBJ_ID__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_obj_id;

/** Identifiers for all possible groups under all objects in the system. 
 */
typedef enum bcmbal_obj_group_id
{
    BCMBAL_OBJ_GROUP_ID__BEGIN,
    BCMBAL_OBJ_GROUP_ID_ACCESS_TERMINAL_KEY                         = 0,    /**< BAL Access Terminal - key */
    BCMBAL_OBJ_GROUP_ID_ACCESS_TERMINAL_CFG                         = 1,    /**< BAL Access Terminal - cfg */
    BCMBAL_OBJ_GROUP_ID_ACCESS_TERMINAL_IND                         = 2,    /**< BAL Access Terminal - Access Terminal Indication */
    BCMBAL_OBJ_GROUP_ID_ACCESS_TERMINAL_OPER_STATUS_CHANGE          = 3,    /**< BAL Access Terminal - Change of operational status */
    BCMBAL_OBJ_GROUP_ID_FLOW_KEY                                    = 4,    /**< BAL Flow - key */
    BCMBAL_OBJ_GROUP_ID_FLOW_CFG                                    = 5,    /**< BAL Flow - cfg */
    BCMBAL_OBJ_GROUP_ID_FLOW_STAT                                   = 6,    /**< BAL Flow - stat */
    BCMBAL_OBJ_GROUP_ID_FLOW_IND                                    = 7,    /**< BAL Flow - Flow Indication */
    BCMBAL_OBJ_GROUP_ID_FLOW_OPER_STATUS_CHANGE                     = 8,    /**< BAL Flow - Change of operational status */
    BCMBAL_OBJ_GROUP_ID_GROUP_KEY                                   = 9,    /**< BAL Group - key */
    BCMBAL_OBJ_GROUP_ID_GROUP_CFG                                   = 10,   /**< BAL Group - cfg */
    BCMBAL_OBJ_GROUP_ID_GROUP_IND                                   = 11,   /**< BAL Group - Group indication */
    BCMBAL_OBJ_GROUP_ID_INTERFACE_KEY                               = 12,   /**< BAL Interface - key */
    BCMBAL_OBJ_GROUP_ID_INTERFACE_CFG                               = 13,   /**< BAL Interface - cfg */
    BCMBAL_OBJ_GROUP_ID_INTERFACE_STAT                              = 14,   /**< BAL Interface - stat */
    BCMBAL_OBJ_GROUP_ID_INTERFACE_IND                               = 15,   /**< BAL Interface - Interface Indication */
    BCMBAL_OBJ_GROUP_ID_INTERFACE_LOS                               = 16,   /**< BAL Interface - LOS */
    BCMBAL_OBJ_GROUP_ID_INTERFACE_OPER_STATUS_CHANGE                = 17,   /**< BAL Interface - Change of operational status */
    BCMBAL_OBJ_GROUP_ID_PACKET_KEY                                  = 18,   /**< packet - key */
    BCMBAL_OBJ_GROUP_ID_PACKET_CFG                                  = 19,   /**< packet - cfg */
    BCMBAL_OBJ_GROUP_ID_PACKET_BEARER_CHANNEL_RX                    = 20,   /**< packet - Bearer channel rx packet indication */
    BCMBAL_OBJ_GROUP_ID_PACKET_IEEE_OAM_CHANNEL_RX                  = 21,   /**< packet - IEEE OAM channel rx packet indication */
    BCMBAL_OBJ_GROUP_ID_PACKET_ITU_OMCI_CHANNEL_RX                  = 22,   /**< packet - ITU OMCI channel rx packet indication */
    BCMBAL_OBJ_GROUP_ID_SUBSCRIBER_TERMINAL_KEY                     = 23,   /**< BAL Subscriber Terminal - key */
    BCMBAL_OBJ_GROUP_ID_SUBSCRIBER_TERMINAL_CFG                     = 24,   /**< BAL Subscriber Terminal - cfg */
    BCMBAL_OBJ_GROUP_ID_SUBSCRIBER_TERMINAL_STAT                    = 25,   /**< BAL Subscriber Terminal - stat */
    BCMBAL_OBJ_GROUP_ID_SUBSCRIBER_TERMINAL_DGI                     = 26,   /**< BAL Subscriber Terminal - Receive Dying-Gasp of subscriber terminal */
    BCMBAL_OBJ_GROUP_ID_SUBSCRIBER_TERMINAL_IND                     = 27,   /**< BAL Subscriber Terminal - Subscriber Terminal Indication */
    BCMBAL_OBJ_GROUP_ID_SUBSCRIBER_TERMINAL_OPER_STATUS_CHANGE      = 28,   /**< BAL Subscriber Terminal - Change of operational status */
    BCMBAL_OBJ_GROUP_ID_SUBSCRIBER_TERMINAL_SUB_TERM_ALARM          = 29,   /**< BAL Subscriber Terminal - Subscriber Terminal Alarm Indication */
    BCMBAL_OBJ_GROUP_ID_SUBSCRIBER_TERMINAL_SUB_TERM_DISC           = 30,   /**< BAL Subscriber Terminal - Subscriber Terminal Discovery Indication */
    BCMBAL_OBJ_GROUP_ID_TM_QUEUE_KEY                                = 31,   /**< tm_queue - key */
    BCMBAL_OBJ_GROUP_ID_TM_QUEUE_CFG                                = 32,   /**< tm_queue - cfg */
    BCMBAL_OBJ_GROUP_ID_TM_QUEUE_STAT                               = 33,   /**< tm_queue - stat */
    BCMBAL_OBJ_GROUP_ID_TM_QUEUE_IND                                = 34,   /**< tm_queue - tm queue indication */
    BCMBAL_OBJ_GROUP_ID_TM_SCHED_KEY                                = 35,   /**< tm_sched - key */
    BCMBAL_OBJ_GROUP_ID_TM_SCHED_CFG                                = 36,   /**< tm_sched - cfg */
    BCMBAL_OBJ_GROUP_ID_TM_SCHED_IND                                = 37,   /**< tm_sched - Tm Sched Indication */
    BCMBAL_OBJ_GROUP_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_obj_group_id;

/** List of all access_terminal groups of type auto. 
 */
typedef enum bcmbal_access_terminal_auto_id
{
    BCMBAL_ACCESS_TERMINAL_AUTO_ID__BEGIN,
    BCMBAL_ACCESS_TERMINAL_AUTO_ID_IND                              = 0,    /**< Access Terminal Indication. */
    BCMBAL_ACCESS_TERMINAL_AUTO_ID_OPER_STATUS_CHANGE,                      /**< Change of operational status. */
    BCMBAL_ACCESS_TERMINAL_AUTO_ID__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_access_terminal_auto_id;

/** List of all flow groups of type auto. 
 */
typedef enum bcmbal_flow_auto_id
{
    BCMBAL_FLOW_AUTO_ID__BEGIN,
    BCMBAL_FLOW_AUTO_ID_IND                                         = 0,    /**< Flow Indication. */
    BCMBAL_FLOW_AUTO_ID_OPER_STATUS_CHANGE, /**< Change of operational status. */
    BCMBAL_FLOW_AUTO_ID__NUM_OF             /**< Number of enum entries, not an entry itself. */
} bcmbal_flow_auto_id;

/** List of all group groups of type auto. 
 */
typedef enum bcmbal_group_auto_id
{
    BCMBAL_GROUP_AUTO_ID__BEGIN,
    BCMBAL_GROUP_AUTO_ID_IND                                        = 0,    /**< Group indication. */
    BCMBAL_GROUP_AUTO_ID__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_group_auto_id;

/** List of all interface groups of type auto. 
 */
typedef enum bcmbal_interface_auto_id
{
    BCMBAL_INTERFACE_AUTO_ID__BEGIN,
    BCMBAL_INTERFACE_AUTO_ID_IND                                    = 0,    /**< Interface Indication. */
    BCMBAL_INTERFACE_AUTO_ID_LOS,                   /**< LOS. */
    BCMBAL_INTERFACE_AUTO_ID_OPER_STATUS_CHANGE,    /**< Change of operational status. */
    BCMBAL_INTERFACE_AUTO_ID__NUM_OF                /**< Number of enum entries, not an entry itself. */
} bcmbal_interface_auto_id;

/** List of all packet groups of type auto. 
 */
typedef enum bcmbal_packet_auto_id
{
    BCMBAL_PACKET_AUTO_ID__BEGIN,
    BCMBAL_PACKET_AUTO_ID_BEARER_CHANNEL_RX                         = 0,    /**< Bearer channel rx packet indication. */
    BCMBAL_PACKET_AUTO_ID_IEEE_OAM_CHANNEL_RX,  /**< IEEE OAM channel rx packet indication. */
    BCMBAL_PACKET_AUTO_ID_ITU_OMCI_CHANNEL_RX,  /**< ITU OMCI channel rx packet indication. */
    BCMBAL_PACKET_AUTO_ID__NUM_OF               /**< Number of enum entries, not an entry itself. */
} bcmbal_packet_auto_id;

/** List of all subscriber_terminal groups of type auto. 
 */
typedef enum bcmbal_subscriber_terminal_auto_id
{
    BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID__BEGIN,
    BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID_DGI                          = 0,    /**< Receive Dying-Gasp of subscriber terminal. */
    BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID_IND,                 /**< Subscriber Terminal Indication. */
    BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID_OPER_STATUS_CHANGE,  /**< Change of operational status. */
    BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID_SUB_TERM_ALARM,      /**< Subscriber Terminal Alarm Indication. */
    BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID_SUB_TERM_DISC,       /**< Subscriber Terminal Discovery Indication. */
    BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID__NUM_OF              /**< Number of enum entries, not an entry itself. */
} bcmbal_subscriber_terminal_auto_id;

/** List of all tm_queue groups of type auto. 
 */
typedef enum bcmbal_tm_queue_auto_id
{
    BCMBAL_TM_QUEUE_AUTO_ID__BEGIN,
    BCMBAL_TM_QUEUE_AUTO_ID_IND                                     = 0,    /**< tm queue indication. */
    BCMBAL_TM_QUEUE_AUTO_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_queue_auto_id;

/** List of all tm_sched groups of type auto. 
 */
typedef enum bcmbal_tm_sched_auto_id
{
    BCMBAL_TM_SCHED_AUTO_ID__BEGIN,
    BCMBAL_TM_SCHED_AUTO_ID_IND                                     = 0,    /**< Tm Sched Indication. */
    BCMBAL_TM_SCHED_AUTO_ID__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_sched_auto_id;

#define bcmbal_access_terminal_key_id_all_properties                    BCMBAL_ACCESS_TERMINAL_KEY_ID__NUM_OF
#define bcmbal_access_terminal_cfg_id_all_properties                    BCMBAL_ACCESS_TERMINAL_CFG_ID__NUM_OF
#define bcmbal_access_terminal_ind_id_all_properties                    BCMBAL_ACCESS_TERMINAL_IND_ID__NUM_OF
#define bcmbal_access_terminal_oper_status_change_id_all_properties     BCMBAL_ACCESS_TERMINAL_OPER_STATUS_CHANGE_ID__NUM_OF
#define bcmbal_flow_cfg_id_all_properties                               BCMBAL_FLOW_CFG_ID__NUM_OF
#define bcmbal_flow_key_id_all_properties                               BCMBAL_FLOW_KEY_ID__NUM_OF
#define bcmbal_flow_stat_id_all_properties                              BCMBAL_FLOW_STAT_ID__NUM_OF
#define bcmbal_flow_ind_id_all_properties                               BCMBAL_FLOW_IND_ID__NUM_OF
#define bcmbal_flow_oper_status_change_id_all_properties                BCMBAL_FLOW_OPER_STATUS_CHANGE_ID__NUM_OF
#define bcmbal_group_cfg_id_all_properties                              BCMBAL_GROUP_CFG_ID__NUM_OF
#define bcmbal_group_key_id_all_properties                              BCMBAL_GROUP_KEY_ID__NUM_OF
#define bcmbal_group_ind_id_all_properties                              BCMBAL_GROUP_IND_ID__NUM_OF
#define bcmbal_interface_key_id_all_properties                          BCMBAL_INTERFACE_KEY_ID__NUM_OF
#define bcmbal_interface_cfg_id_all_properties                          BCMBAL_INTERFACE_CFG_ID__NUM_OF
#define bcmbal_interface_stat_id_all_properties                         BCMBAL_INTERFACE_STAT_ID__NUM_OF
#define bcmbal_interface_ind_id_all_properties                          BCMBAL_INTERFACE_IND_ID__NUM_OF
#define bcmbal_interface_oper_status_change_id_all_properties           BCMBAL_INTERFACE_OPER_STATUS_CHANGE_ID__NUM_OF
#define bcmbal_interface_los_id_all_properties                          BCMBAL_INTERFACE_LOS_ID__NUM_OF
#define bcmbal_packet_cfg_id_all_properties                             BCMBAL_PACKET_CFG_ID__NUM_OF
#define bcmbal_packet_key_id_all_properties                             BCMBAL_PACKET_KEY_ID__NUM_OF
#define bcmbal_packet_bearer_channel_rx_id_all_properties               BCMBAL_PACKET_BEARER_CHANNEL_RX_ID__NUM_OF
#define bcmbal_packet_itu_omci_channel_rx_id_all_properties             BCMBAL_PACKET_ITU_OMCI_CHANNEL_RX_ID__NUM_OF
#define bcmbal_packet_ieee_oam_channel_rx_id_all_properties             BCMBAL_PACKET_IEEE_OAM_CHANNEL_RX_ID__NUM_OF
#define bcmbal_subscriber_terminal_key_id_all_properties                BCMBAL_SUBSCRIBER_TERMINAL_KEY_ID__NUM_OF
#define bcmbal_subscriber_terminal_cfg_id_all_properties                BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID__NUM_OF
#define bcmbal_subscriber_terminal_stat_id_all_properties               BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID__NUM_OF
#define bcmbal_subscriber_terminal_ind_id_all_properties                BCMBAL_SUBSCRIBER_TERMINAL_IND_ID__NUM_OF
#define bcmbal_subscriber_terminal_sub_term_disc_id_all_properties      BCMBAL_SUBSCRIBER_TERMINAL_SUB_TERM_DISC_ID__NUM_OF
#define bcmbal_subscriber_terminal_sub_term_alarm_id_all_properties     BCMBAL_SUBSCRIBER_TERMINAL_SUB_TERM_ALARM_ID__NUM_OF
#define bcmbal_subscriber_terminal_oper_status_change_id_all_properties BCMBAL_SUBSCRIBER_TERMINAL_OPER_STATUS_CHANGE_ID__NUM_OF
#define bcmbal_subscriber_terminal_dgi_id_all_properties                BCMBAL_SUBSCRIBER_TERMINAL_DGI_ID__NUM_OF
#define bcmbal_tm_queue_key_id_all_properties                           BCMBAL_TM_QUEUE_KEY_ID__NUM_OF
#define bcmbal_tm_queue_cfg_id_all_properties                           BCMBAL_TM_QUEUE_CFG_ID__NUM_OF
#define bcmbal_tm_queue_stat_id_all_properties                          BCMBAL_TM_QUEUE_STAT_ID__NUM_OF
#define bcmbal_tm_queue_ind_id_all_properties                           BCMBAL_TM_QUEUE_IND_ID__NUM_OF
#define bcmbal_tm_sched_key_id_all_properties                           BCMBAL_TM_SCHED_KEY_ID__NUM_OF
#define bcmbal_tm_sched_cfg_id_all_properties                           BCMBAL_TM_SCHED_CFG_ID__NUM_OF
#define bcmbal_tm_sched_ind_id_all_properties                           BCMBAL_TM_SCHED_IND_ID__NUM_OF

/* The following are required for the API Init/Set/etc macros */
#define bcmbal_obj_id__begin                                                BCMBAL_OBJ_ID__BEGIN
#define bcmbal_obj_id_access_terminal                                       BCMBAL_OBJ_ID_ACCESS_TERMINAL
#define bcmbal_obj_id_flow                                                  BCMBAL_OBJ_ID_FLOW
#define bcmbal_obj_id_group                                                 BCMBAL_OBJ_ID_GROUP
#define bcmbal_obj_id_interface                                             BCMBAL_OBJ_ID_INTERFACE
#define bcmbal_obj_id_packet                                                BCMBAL_OBJ_ID_PACKET
#define bcmbal_obj_id_subscriber_terminal                                   BCMBAL_OBJ_ID_SUBSCRIBER_TERMINAL
#define bcmbal_obj_id_tm_queue                                              BCMBAL_OBJ_ID_TM_QUEUE
#define bcmbal_obj_id_tm_sched                                              BCMBAL_OBJ_ID_TM_SCHED
#define bcmbal_obj_id__num_of                                               BCMBAL_OBJ_ID__NUM_OF
#define bcmbal_access_terminal_auto_id__begin                               BCMBAL_ACCESS_TERMINAL_AUTO_ID__BEGIN
#define bcmbal_access_terminal_auto_id_ind                                  BCMBAL_ACCESS_TERMINAL_AUTO_ID_IND
#define bcmbal_access_terminal_auto_id_oper_status_change                   BCMBAL_ACCESS_TERMINAL_AUTO_ID_OPER_STATUS_CHANGE
#define bcmbal_access_terminal_auto_id__num_of                              BCMBAL_ACCESS_TERMINAL_AUTO_ID__NUM_OF
#define bcmbal_flow_auto_id__begin                                          BCMBAL_FLOW_AUTO_ID__BEGIN
#define bcmbal_flow_auto_id_ind                                             BCMBAL_FLOW_AUTO_ID_IND
#define bcmbal_flow_auto_id_oper_status_change                              BCMBAL_FLOW_AUTO_ID_OPER_STATUS_CHANGE
#define bcmbal_flow_auto_id__num_of                                         BCMBAL_FLOW_AUTO_ID__NUM_OF
#define bcmbal_group_auto_id__begin                                         BCMBAL_GROUP_AUTO_ID__BEGIN
#define bcmbal_group_auto_id_ind                                            BCMBAL_GROUP_AUTO_ID_IND
#define bcmbal_group_auto_id__num_of                                        BCMBAL_GROUP_AUTO_ID__NUM_OF
#define bcmbal_interface_auto_id__begin                                     BCMBAL_INTERFACE_AUTO_ID__BEGIN
#define bcmbal_interface_auto_id_ind                                        BCMBAL_INTERFACE_AUTO_ID_IND
#define bcmbal_interface_auto_id_los                                        BCMBAL_INTERFACE_AUTO_ID_LOS
#define bcmbal_interface_auto_id_oper_status_change                         BCMBAL_INTERFACE_AUTO_ID_OPER_STATUS_CHANGE
#define bcmbal_interface_auto_id__num_of                                    BCMBAL_INTERFACE_AUTO_ID__NUM_OF
#define bcmbal_packet_auto_id__begin                                        BCMBAL_PACKET_AUTO_ID__BEGIN
#define bcmbal_packet_auto_id_bearer_channel_rx                             BCMBAL_PACKET_AUTO_ID_BEARER_CHANNEL_RX
#define bcmbal_packet_auto_id_ieee_oam_channel_rx                           BCMBAL_PACKET_AUTO_ID_IEEE_OAM_CHANNEL_RX
#define bcmbal_packet_auto_id_itu_omci_channel_rx                           BCMBAL_PACKET_AUTO_ID_ITU_OMCI_CHANNEL_RX
#define bcmbal_packet_auto_id__num_of                                       BCMBAL_PACKET_AUTO_ID__NUM_OF
#define bcmbal_subscriber_terminal_auto_id__begin                           BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID__BEGIN
#define bcmbal_subscriber_terminal_auto_id_dgi                              BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID_DGI
#define bcmbal_subscriber_terminal_auto_id_ind                              BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID_IND
#define bcmbal_subscriber_terminal_auto_id_oper_status_change               BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID_OPER_STATUS_CHANGE
#define bcmbal_subscriber_terminal_auto_id_sub_term_alarm                   BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID_SUB_TERM_ALARM
#define bcmbal_subscriber_terminal_auto_id_sub_term_disc                    BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID_SUB_TERM_DISC
#define bcmbal_subscriber_terminal_auto_id__num_of                          BCMBAL_SUBSCRIBER_TERMINAL_AUTO_ID__NUM_OF
#define bcmbal_tm_queue_auto_id__begin                                      BCMBAL_TM_QUEUE_AUTO_ID__BEGIN
#define bcmbal_tm_queue_auto_id_ind                                         BCMBAL_TM_QUEUE_AUTO_ID_IND
#define bcmbal_tm_queue_auto_id__num_of                                     BCMBAL_TM_QUEUE_AUTO_ID__NUM_OF
#define bcmbal_tm_sched_auto_id__begin                                      BCMBAL_TM_SCHED_AUTO_ID__BEGIN
#define bcmbal_tm_sched_auto_id_ind                                         BCMBAL_TM_SCHED_AUTO_ID_IND
#define bcmbal_tm_sched_auto_id__num_of                                     BCMBAL_TM_SCHED_AUTO_ID__NUM_OF
#define bcmbal_access_terminal_key_id_access_term_id                        BCMBAL_ACCESS_TERMINAL_KEY_ID_ACCESS_TERM_ID
#define bcmbal_access_terminal_key_id__num_of                               BCMBAL_ACCESS_TERMINAL_KEY_ID__NUM_OF
#define bcmbal_access_terminal_cfg_id_admin_state                           BCMBAL_ACCESS_TERMINAL_CFG_ID_ADMIN_STATE
#define bcmbal_access_terminal_cfg_id_oper_status                           BCMBAL_ACCESS_TERMINAL_CFG_ID_OPER_STATUS
#define bcmbal_access_terminal_cfg_id_iwf_mode                              BCMBAL_ACCESS_TERMINAL_CFG_ID_IWF_MODE
#define bcmbal_access_terminal_cfg_id_topology                              BCMBAL_ACCESS_TERMINAL_CFG_ID_TOPOLOGY
#define bcmbal_access_terminal_cfg_id_sw_version                            BCMBAL_ACCESS_TERMINAL_CFG_ID_SW_VERSION
#define bcmbal_access_terminal_cfg_id__num_of                               BCMBAL_ACCESS_TERMINAL_CFG_ID__NUM_OF
#define bcmbal_access_terminal_ind_id_admin_state                           BCMBAL_ACCESS_TERMINAL_IND_ID_ADMIN_STATE
#define bcmbal_access_terminal_ind_id_oper_status                           BCMBAL_ACCESS_TERMINAL_IND_ID_OPER_STATUS
#define bcmbal_access_terminal_ind_id_iwf_mode                              BCMBAL_ACCESS_TERMINAL_IND_ID_IWF_MODE
#define bcmbal_access_terminal_ind_id_topology                              BCMBAL_ACCESS_TERMINAL_IND_ID_TOPOLOGY
#define bcmbal_access_terminal_ind_id_sw_version                            BCMBAL_ACCESS_TERMINAL_IND_ID_SW_VERSION
#define bcmbal_access_terminal_ind_id__num_of                               BCMBAL_ACCESS_TERMINAL_IND_ID__NUM_OF
#define bcmbal_access_terminal_oper_status_change_id_new_oper_status        BCMBAL_ACCESS_TERMINAL_OPER_STATUS_CHANGE_ID_NEW_OPER_STATUS
#define bcmbal_access_terminal_oper_status_change_id_old_oper_status        BCMBAL_ACCESS_TERMINAL_OPER_STATUS_CHANGE_ID_OLD_OPER_STATUS
#define bcmbal_access_terminal_oper_status_change_id_admin_state            BCMBAL_ACCESS_TERMINAL_OPER_STATUS_CHANGE_ID_ADMIN_STATE
#define bcmbal_access_terminal_oper_status_change_id__num_of                BCMBAL_ACCESS_TERMINAL_OPER_STATUS_CHANGE_ID__NUM_OF
#define bcmbal_flow_key_id_flow_id                                          BCMBAL_FLOW_KEY_ID_FLOW_ID
#define bcmbal_flow_key_id_flow_type                                        BCMBAL_FLOW_KEY_ID_FLOW_TYPE
#define bcmbal_flow_key_id__num_of                                          BCMBAL_FLOW_KEY_ID__NUM_OF
#define bcmbal_flow_cfg_id_admin_state                                      BCMBAL_FLOW_CFG_ID_ADMIN_STATE
#define bcmbal_flow_cfg_id_oper_status                                      BCMBAL_FLOW_CFG_ID_OPER_STATUS
#define bcmbal_flow_cfg_id_access_int_id                                    BCMBAL_FLOW_CFG_ID_ACCESS_INT_ID
#define bcmbal_flow_cfg_id_network_int_id                                   BCMBAL_FLOW_CFG_ID_NETWORK_INT_ID
#define bcmbal_flow_cfg_id_sub_term_id                                      BCMBAL_FLOW_CFG_ID_SUB_TERM_ID
#define bcmbal_flow_cfg_id_sub_term_uni_idx                                 BCMBAL_FLOW_CFG_ID_SUB_TERM_UNI_IDX
#define bcmbal_flow_cfg_id_svc_port_id                                      BCMBAL_FLOW_CFG_ID_SVC_PORT_ID
#define bcmbal_flow_cfg_id_resolve_mac                                      BCMBAL_FLOW_CFG_ID_RESOLVE_MAC
#define bcmbal_flow_cfg_id_classifier                                       BCMBAL_FLOW_CFG_ID_CLASSIFIER
#define bcmbal_flow_cfg_id_action                                           BCMBAL_FLOW_CFG_ID_ACTION
#define bcmbal_flow_cfg_id_cookie                                           BCMBAL_FLOW_CFG_ID_COOKIE
#define bcmbal_flow_cfg_id_priority                                         BCMBAL_FLOW_CFG_ID_PRIORITY
#define bcmbal_flow_cfg_id_group_id                                         BCMBAL_FLOW_CFG_ID_GROUP_ID
#define bcmbal_flow_cfg_id_queue                                            BCMBAL_FLOW_CFG_ID_QUEUE
#define bcmbal_flow_cfg_id_dba_tm_sched_id                                  BCMBAL_FLOW_CFG_ID_DBA_TM_SCHED_ID
#define bcmbal_flow_cfg_id__num_of                                          BCMBAL_FLOW_CFG_ID__NUM_OF
#define bcmbal_flow_stat_id_rx_packets                                      BCMBAL_FLOW_STAT_ID_RX_PACKETS
#define bcmbal_flow_stat_id_rx_bytes                                        BCMBAL_FLOW_STAT_ID_RX_BYTES
#define bcmbal_flow_stat_id_tx_packets                                      BCMBAL_FLOW_STAT_ID_TX_PACKETS
#define bcmbal_flow_stat_id_tx_bytes                                        BCMBAL_FLOW_STAT_ID_TX_BYTES
#define bcmbal_flow_stat_id__num_of                                         BCMBAL_FLOW_STAT_ID__NUM_OF
#define bcmbal_flow_ind_id_admin_state                                      BCMBAL_FLOW_IND_ID_ADMIN_STATE
#define bcmbal_flow_ind_id_oper_status                                      BCMBAL_FLOW_IND_ID_OPER_STATUS
#define bcmbal_flow_ind_id_access_int_id                                    BCMBAL_FLOW_IND_ID_ACCESS_INT_ID
#define bcmbal_flow_ind_id_network_int_id                                   BCMBAL_FLOW_IND_ID_NETWORK_INT_ID
#define bcmbal_flow_ind_id_sub_term_id                                      BCMBAL_FLOW_IND_ID_SUB_TERM_ID
#define bcmbal_flow_ind_id_sub_term_uni_idx                                 BCMBAL_FLOW_IND_ID_SUB_TERM_UNI_IDX
#define bcmbal_flow_ind_id_svc_port_id                                      BCMBAL_FLOW_IND_ID_SVC_PORT_ID
#define bcmbal_flow_ind_id_resolve_mac                                      BCMBAL_FLOW_IND_ID_RESOLVE_MAC
#define bcmbal_flow_ind_id_classifier                                       BCMBAL_FLOW_IND_ID_CLASSIFIER
#define bcmbal_flow_ind_id_action                                           BCMBAL_FLOW_IND_ID_ACTION
#define bcmbal_flow_ind_id_cookie                                           BCMBAL_FLOW_IND_ID_COOKIE
#define bcmbal_flow_ind_id_priority                                         BCMBAL_FLOW_IND_ID_PRIORITY
#define bcmbal_flow_ind_id_group_id                                         BCMBAL_FLOW_IND_ID_GROUP_ID
#define bcmbal_flow_ind_id_queue                                            BCMBAL_FLOW_IND_ID_QUEUE
#define bcmbal_flow_ind_id_dba_tm_sched_id                                  BCMBAL_FLOW_IND_ID_DBA_TM_SCHED_ID
#define bcmbal_flow_ind_id__num_of                                          BCMBAL_FLOW_IND_ID__NUM_OF
#define bcmbal_flow_oper_status_change_id_new_oper_status                   BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_NEW_OPER_STATUS
#define bcmbal_flow_oper_status_change_id_old_oper_status                   BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_OLD_OPER_STATUS
#define bcmbal_flow_oper_status_change_id_admin_state                       BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_ADMIN_STATE
#define bcmbal_flow_oper_status_change_id_svc_port_id                       BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_SVC_PORT_ID
#define bcmbal_flow_oper_status_change_id_dba_tm_sched_id                   BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_DBA_TM_SCHED_ID
#define bcmbal_flow_oper_status_change_id_cookie                            BCMBAL_FLOW_OPER_STATUS_CHANGE_ID_COOKIE
#define bcmbal_flow_oper_status_change_id__num_of                           BCMBAL_FLOW_OPER_STATUS_CHANGE_ID__NUM_OF
#define bcmbal_group_key_id_group_id                                        BCMBAL_GROUP_KEY_ID_GROUP_ID
#define bcmbal_group_key_id__num_of                                         BCMBAL_GROUP_KEY_ID__NUM_OF
#define bcmbal_group_cfg_id_members_cmd                                     BCMBAL_GROUP_CFG_ID_MEMBERS_CMD
#define bcmbal_group_cfg_id_members                                         BCMBAL_GROUP_CFG_ID_MEMBERS
#define bcmbal_group_cfg_id_cookie                                          BCMBAL_GROUP_CFG_ID_COOKIE
#define bcmbal_group_cfg_id_flows                                           BCMBAL_GROUP_CFG_ID_FLOWS
#define bcmbal_group_cfg_id_owner                                           BCMBAL_GROUP_CFG_ID_OWNER
#define bcmbal_group_cfg_id__num_of                                         BCMBAL_GROUP_CFG_ID__NUM_OF
#define bcmbal_group_ind_id_members_cmd                                     BCMBAL_GROUP_IND_ID_MEMBERS_CMD
#define bcmbal_group_ind_id_members                                         BCMBAL_GROUP_IND_ID_MEMBERS
#define bcmbal_group_ind_id_cookie                                          BCMBAL_GROUP_IND_ID_COOKIE
#define bcmbal_group_ind_id_flows                                           BCMBAL_GROUP_IND_ID_FLOWS
#define bcmbal_group_ind_id_owner                                           BCMBAL_GROUP_IND_ID_OWNER
#define bcmbal_group_ind_id__num_of                                         BCMBAL_GROUP_IND_ID__NUM_OF
#define bcmbal_interface_key_id_intf_id                                     BCMBAL_INTERFACE_KEY_ID_INTF_ID
#define bcmbal_interface_key_id_intf_type                                   BCMBAL_INTERFACE_KEY_ID_INTF_TYPE
#define bcmbal_interface_key_id__num_of                                     BCMBAL_INTERFACE_KEY_ID__NUM_OF
#define bcmbal_interface_cfg_id_admin_state                                 BCMBAL_INTERFACE_CFG_ID_ADMIN_STATE
#define bcmbal_interface_cfg_id_oper_status                                 BCMBAL_INTERFACE_CFG_ID_OPER_STATUS
#define bcmbal_interface_cfg_id_min_data_agg_port_id                        BCMBAL_INTERFACE_CFG_ID_MIN_DATA_AGG_PORT_ID
#define bcmbal_interface_cfg_id_min_data_svc_port_id                        BCMBAL_INTERFACE_CFG_ID_MIN_DATA_SVC_PORT_ID
#define bcmbal_interface_cfg_id_transceiver_type                            BCMBAL_INTERFACE_CFG_ID_TRANSCEIVER_TYPE
#define bcmbal_interface_cfg_id_ds_miss_mode                                BCMBAL_INTERFACE_CFG_ID_DS_MISS_MODE
#define bcmbal_interface_cfg_id_mtu                                         BCMBAL_INTERFACE_CFG_ID_MTU
#define bcmbal_interface_cfg_id_flow_control                                BCMBAL_INTERFACE_CFG_ID_FLOW_CONTROL
#define bcmbal_interface_cfg_id_ds_tm                                       BCMBAL_INTERFACE_CFG_ID_DS_TM
#define bcmbal_interface_cfg_id_us_tm                                       BCMBAL_INTERFACE_CFG_ID_US_TM
#define bcmbal_interface_cfg_id_sub_term_id_list                            BCMBAL_INTERFACE_CFG_ID_SUB_TERM_ID_LIST
#define bcmbal_interface_cfg_id__num_of                                     BCMBAL_INTERFACE_CFG_ID__NUM_OF
#define bcmbal_interface_stat_id_rx_bytes                                   BCMBAL_INTERFACE_STAT_ID_RX_BYTES
#define bcmbal_interface_stat_id_rx_packets                                 BCMBAL_INTERFACE_STAT_ID_RX_PACKETS
#define bcmbal_interface_stat_id_rx_ucast_packets                           BCMBAL_INTERFACE_STAT_ID_RX_UCAST_PACKETS
#define bcmbal_interface_stat_id_rx_mcast_packets                           BCMBAL_INTERFACE_STAT_ID_RX_MCAST_PACKETS
#define bcmbal_interface_stat_id_rx_bcast_packets                           BCMBAL_INTERFACE_STAT_ID_RX_BCAST_PACKETS
#define bcmbal_interface_stat_id_rx_error_packets                           BCMBAL_INTERFACE_STAT_ID_RX_ERROR_PACKETS
#define bcmbal_interface_stat_id_rx_unknown_protos                          BCMBAL_INTERFACE_STAT_ID_RX_UNKNOWN_PROTOS
#define bcmbal_interface_stat_id_tx_bytes                                   BCMBAL_INTERFACE_STAT_ID_TX_BYTES
#define bcmbal_interface_stat_id_tx_packets                                 BCMBAL_INTERFACE_STAT_ID_TX_PACKETS
#define bcmbal_interface_stat_id_tx_ucast_packets                           BCMBAL_INTERFACE_STAT_ID_TX_UCAST_PACKETS
#define bcmbal_interface_stat_id_tx_mcast_packets                           BCMBAL_INTERFACE_STAT_ID_TX_MCAST_PACKETS
#define bcmbal_interface_stat_id_tx_bcast_packets                           BCMBAL_INTERFACE_STAT_ID_TX_BCAST_PACKETS
#define bcmbal_interface_stat_id_tx_error_packets                           BCMBAL_INTERFACE_STAT_ID_TX_ERROR_PACKETS
#define bcmbal_interface_stat_id_rx_crc_errors                              BCMBAL_INTERFACE_STAT_ID_RX_CRC_ERRORS
#define bcmbal_interface_stat_id_bip_errors                                 BCMBAL_INTERFACE_STAT_ID_BIP_ERRORS
#define bcmbal_interface_stat_id__num_of                                    BCMBAL_INTERFACE_STAT_ID__NUM_OF
#define bcmbal_interface_ind_id_admin_state                                 BCMBAL_INTERFACE_IND_ID_ADMIN_STATE
#define bcmbal_interface_ind_id_oper_status                                 BCMBAL_INTERFACE_IND_ID_OPER_STATUS
#define bcmbal_interface_ind_id_min_data_agg_port_id                        BCMBAL_INTERFACE_IND_ID_MIN_DATA_AGG_PORT_ID
#define bcmbal_interface_ind_id_min_data_svc_port_id                        BCMBAL_INTERFACE_IND_ID_MIN_DATA_SVC_PORT_ID
#define bcmbal_interface_ind_id_transceiver_type                            BCMBAL_INTERFACE_IND_ID_TRANSCEIVER_TYPE
#define bcmbal_interface_ind_id_ds_miss_mode                                BCMBAL_INTERFACE_IND_ID_DS_MISS_MODE
#define bcmbal_interface_ind_id_mtu                                         BCMBAL_INTERFACE_IND_ID_MTU
#define bcmbal_interface_ind_id_flow_control                                BCMBAL_INTERFACE_IND_ID_FLOW_CONTROL
#define bcmbal_interface_ind_id_ds_tm                                       BCMBAL_INTERFACE_IND_ID_DS_TM
#define bcmbal_interface_ind_id_us_tm                                       BCMBAL_INTERFACE_IND_ID_US_TM
#define bcmbal_interface_ind_id_sub_term_id_list                            BCMBAL_INTERFACE_IND_ID_SUB_TERM_ID_LIST
#define bcmbal_interface_ind_id__num_of                                     BCMBAL_INTERFACE_IND_ID__NUM_OF
#define bcmbal_interface_los_id_status                                      BCMBAL_INTERFACE_LOS_ID_STATUS
#define bcmbal_interface_los_id__num_of                                     BCMBAL_INTERFACE_LOS_ID__NUM_OF
#define bcmbal_interface_oper_status_change_id_new_oper_status              BCMBAL_INTERFACE_OPER_STATUS_CHANGE_ID_NEW_OPER_STATUS
#define bcmbal_interface_oper_status_change_id_old_oper_status              BCMBAL_INTERFACE_OPER_STATUS_CHANGE_ID_OLD_OPER_STATUS
#define bcmbal_interface_oper_status_change_id_admin_state                  BCMBAL_INTERFACE_OPER_STATUS_CHANGE_ID_ADMIN_STATE
#define bcmbal_interface_oper_status_change_id__num_of                      BCMBAL_INTERFACE_OPER_STATUS_CHANGE_ID__NUM_OF
#define bcmbal_packet_key_id_reserved                                       BCMBAL_PACKET_KEY_ID_RESERVED
#define bcmbal_packet_key_id_packet_send_dest                               BCMBAL_PACKET_KEY_ID_PACKET_SEND_DEST
#define bcmbal_packet_key_id__num_of                                        BCMBAL_PACKET_KEY_ID__NUM_OF
#define bcmbal_packet_cfg_id_flow_id                                        BCMBAL_PACKET_CFG_ID_FLOW_ID
#define bcmbal_packet_cfg_id_flow_type                                      BCMBAL_PACKET_CFG_ID_FLOW_TYPE
#define bcmbal_packet_cfg_id_intf_id                                        BCMBAL_PACKET_CFG_ID_INTF_ID
#define bcmbal_packet_cfg_id_intf_type                                      BCMBAL_PACKET_CFG_ID_INTF_TYPE
#define bcmbal_packet_cfg_id_svc_port                                       BCMBAL_PACKET_CFG_ID_SVC_PORT
#define bcmbal_packet_cfg_id_flow_cookie                                    BCMBAL_PACKET_CFG_ID_FLOW_COOKIE
#define bcmbal_packet_cfg_id_pkt                                            BCMBAL_PACKET_CFG_ID_PKT
#define bcmbal_packet_cfg_id__num_of                                        BCMBAL_PACKET_CFG_ID__NUM_OF
#define bcmbal_packet_bearer_channel_rx_id_flow_id                          BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_FLOW_ID
#define bcmbal_packet_bearer_channel_rx_id_flow_type                        BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_FLOW_TYPE
#define bcmbal_packet_bearer_channel_rx_id_intf_id                          BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_INTF_ID
#define bcmbal_packet_bearer_channel_rx_id_intf_type                        BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_INTF_TYPE
#define bcmbal_packet_bearer_channel_rx_id_svc_port                         BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_SVC_PORT
#define bcmbal_packet_bearer_channel_rx_id_flow_cookie                      BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_FLOW_COOKIE
#define bcmbal_packet_bearer_channel_rx_id_pkt                              BCMBAL_PACKET_BEARER_CHANNEL_RX_ID_PKT
#define bcmbal_packet_bearer_channel_rx_id__num_of                          BCMBAL_PACKET_BEARER_CHANNEL_RX_ID__NUM_OF
#define bcmbal_packet_ieee_oam_channel_rx_id_pkt                            BCMBAL_PACKET_IEEE_OAM_CHANNEL_RX_ID_PKT
#define bcmbal_packet_ieee_oam_channel_rx_id__num_of                        BCMBAL_PACKET_IEEE_OAM_CHANNEL_RX_ID__NUM_OF
#define bcmbal_packet_itu_omci_channel_rx_id_pkt                            BCMBAL_PACKET_ITU_OMCI_CHANNEL_RX_ID_PKT
#define bcmbal_packet_itu_omci_channel_rx_id__num_of                        BCMBAL_PACKET_ITU_OMCI_CHANNEL_RX_ID__NUM_OF
#define bcmbal_subscriber_terminal_key_id_sub_term_id                       BCMBAL_SUBSCRIBER_TERMINAL_KEY_ID_SUB_TERM_ID
#define bcmbal_subscriber_terminal_key_id_intf_id                           BCMBAL_SUBSCRIBER_TERMINAL_KEY_ID_INTF_ID
#define bcmbal_subscriber_terminal_key_id__num_of                           BCMBAL_SUBSCRIBER_TERMINAL_KEY_ID__NUM_OF
#define bcmbal_subscriber_terminal_cfg_id_admin_state                       BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_ADMIN_STATE
#define bcmbal_subscriber_terminal_cfg_id_oper_status                       BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_OPER_STATUS
#define bcmbal_subscriber_terminal_cfg_id_serial_number                     BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_SERIAL_NUMBER
#define bcmbal_subscriber_terminal_cfg_id_password                          BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_PASSWORD
#define bcmbal_subscriber_terminal_cfg_id_registration_id                   BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_REGISTRATION_ID
#define bcmbal_subscriber_terminal_cfg_id_svc_port_id                       BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_SVC_PORT_ID
#define bcmbal_subscriber_terminal_cfg_id_mac_address                       BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_MAC_ADDRESS
#define bcmbal_subscriber_terminal_cfg_id_ds_tm                             BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_DS_TM
#define bcmbal_subscriber_terminal_cfg_id_us_tm                             BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_US_TM
#define bcmbal_subscriber_terminal_cfg_id_svc_port_id_list                  BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_SVC_PORT_ID_LIST
#define bcmbal_subscriber_terminal_cfg_id_agg_port_id_list                  BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_AGG_PORT_ID_LIST
#define bcmbal_subscriber_terminal_cfg_id_sub_term_rate                     BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID_SUB_TERM_RATE
#define bcmbal_subscriber_terminal_cfg_id__num_of                           BCMBAL_SUBSCRIBER_TERMINAL_CFG_ID__NUM_OF
#define bcmbal_subscriber_terminal_stat_id_rx_packets                       BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID_RX_PACKETS
#define bcmbal_subscriber_terminal_stat_id_rx_bytes                         BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID_RX_BYTES
#define bcmbal_subscriber_terminal_stat_id_tx_packets                       BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID_TX_PACKETS
#define bcmbal_subscriber_terminal_stat_id_tx_bytes                         BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID_TX_BYTES
#define bcmbal_subscriber_terminal_stat_id__num_of                          BCMBAL_SUBSCRIBER_TERMINAL_STAT_ID__NUM_OF
#define bcmbal_subscriber_terminal_dgi_id_dgi_status                        BCMBAL_SUBSCRIBER_TERMINAL_DGI_ID_DGI_STATUS
#define bcmbal_subscriber_terminal_dgi_id__num_of                           BCMBAL_SUBSCRIBER_TERMINAL_DGI_ID__NUM_OF
#define bcmbal_subscriber_terminal_ind_id_admin_state                       BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_ADMIN_STATE
#define bcmbal_subscriber_terminal_ind_id_oper_status                       BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_OPER_STATUS
#define bcmbal_subscriber_terminal_ind_id_serial_number                     BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_SERIAL_NUMBER
#define bcmbal_subscriber_terminal_ind_id_password                          BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_PASSWORD
#define bcmbal_subscriber_terminal_ind_id_registration_id                   BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_REGISTRATION_ID
#define bcmbal_subscriber_terminal_ind_id_svc_port_id                       BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_SVC_PORT_ID
#define bcmbal_subscriber_terminal_ind_id_mac_address                       BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_MAC_ADDRESS
#define bcmbal_subscriber_terminal_ind_id_ds_tm                             BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_DS_TM
#define bcmbal_subscriber_terminal_ind_id_us_tm                             BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_US_TM
#define bcmbal_subscriber_terminal_ind_id_svc_port_id_list                  BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_SVC_PORT_ID_LIST
#define bcmbal_subscriber_terminal_ind_id_agg_port_id_list                  BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_AGG_PORT_ID_LIST
#define bcmbal_subscriber_terminal_ind_id_sub_term_rate                     BCMBAL_SUBSCRIBER_TERMINAL_IND_ID_SUB_TERM_RATE
#define bcmbal_subscriber_terminal_ind_id__num_of                           BCMBAL_SUBSCRIBER_TERMINAL_IND_ID__NUM_OF
#define bcmbal_subscriber_terminal_oper_status_change_id_new_oper_status    BCMBAL_SUBSCRIBER_TERMINAL_OPER_STATUS_CHANGE_ID_NEW_OPER_STATUS
#define bcmbal_subscriber_terminal_oper_status_change_id_old_oper_status    BCMBAL_SUBSCRIBER_TERMINAL_OPER_STATUS_CHANGE_ID_OLD_OPER_STATUS
#define bcmbal_subscriber_terminal_oper_status_change_id_admin_state        BCMBAL_SUBSCRIBER_TERMINAL_OPER_STATUS_CHANGE_ID_ADMIN_STATE
#define bcmbal_subscriber_terminal_oper_status_change_id__num_of            BCMBAL_SUBSCRIBER_TERMINAL_OPER_STATUS_CHANGE_ID__NUM_OF
#define bcmbal_subscriber_terminal_sub_term_alarm_id_alarm                  BCMBAL_SUBSCRIBER_TERMINAL_SUB_TERM_ALARM_ID_ALARM
#define bcmbal_subscriber_terminal_sub_term_alarm_id__num_of                BCMBAL_SUBSCRIBER_TERMINAL_SUB_TERM_ALARM_ID__NUM_OF
#define bcmbal_subscriber_terminal_sub_term_disc_id_serial_number           BCMBAL_SUBSCRIBER_TERMINAL_SUB_TERM_DISC_ID_SERIAL_NUMBER
#define bcmbal_subscriber_terminal_sub_term_disc_id__num_of                 BCMBAL_SUBSCRIBER_TERMINAL_SUB_TERM_DISC_ID__NUM_OF
#define bcmbal_tm_queue_key_id_sched_id                                     BCMBAL_TM_QUEUE_KEY_ID_SCHED_ID
#define bcmbal_tm_queue_key_id_sched_dir                                    BCMBAL_TM_QUEUE_KEY_ID_SCHED_DIR
#define bcmbal_tm_queue_key_id_id                                           BCMBAL_TM_QUEUE_KEY_ID_ID
#define bcmbal_tm_queue_key_id__num_of                                      BCMBAL_TM_QUEUE_KEY_ID__NUM_OF
#define bcmbal_tm_queue_cfg_id_priority                                     BCMBAL_TM_QUEUE_CFG_ID_PRIORITY
#define bcmbal_tm_queue_cfg_id_weight                                       BCMBAL_TM_QUEUE_CFG_ID_WEIGHT
#define bcmbal_tm_queue_cfg_id_rate                                         BCMBAL_TM_QUEUE_CFG_ID_RATE
#define bcmbal_tm_queue_cfg_id_bac                                          BCMBAL_TM_QUEUE_CFG_ID_BAC
#define bcmbal_tm_queue_cfg_id_creation_mode                                BCMBAL_TM_QUEUE_CFG_ID_CREATION_MODE
#define bcmbal_tm_queue_cfg_id_ref_count                                    BCMBAL_TM_QUEUE_CFG_ID_REF_COUNT
#define bcmbal_tm_queue_cfg_id__num_of                                      BCMBAL_TM_QUEUE_CFG_ID__NUM_OF
#define bcmbal_tm_queue_stat_id_packets_ok                                  BCMBAL_TM_QUEUE_STAT_ID_PACKETS_OK
#define bcmbal_tm_queue_stat_id_bytes_ok                                    BCMBAL_TM_QUEUE_STAT_ID_BYTES_OK
#define bcmbal_tm_queue_stat_id_packets_discarded                           BCMBAL_TM_QUEUE_STAT_ID_PACKETS_DISCARDED
#define bcmbal_tm_queue_stat_id_bytes_discarded                             BCMBAL_TM_QUEUE_STAT_ID_BYTES_DISCARDED
#define bcmbal_tm_queue_stat_id__num_of                                     BCMBAL_TM_QUEUE_STAT_ID__NUM_OF
#define bcmbal_tm_queue_ind_id_priority                                     BCMBAL_TM_QUEUE_IND_ID_PRIORITY
#define bcmbal_tm_queue_ind_id_weight                                       BCMBAL_TM_QUEUE_IND_ID_WEIGHT
#define bcmbal_tm_queue_ind_id_rate                                         BCMBAL_TM_QUEUE_IND_ID_RATE
#define bcmbal_tm_queue_ind_id_bac                                          BCMBAL_TM_QUEUE_IND_ID_BAC
#define bcmbal_tm_queue_ind_id_create_mode                                  BCMBAL_TM_QUEUE_IND_ID_CREATE_MODE
#define bcmbal_tm_queue_ind_id_ref_count                                    BCMBAL_TM_QUEUE_IND_ID_REF_COUNT
#define bcmbal_tm_queue_ind_id__num_of                                      BCMBAL_TM_QUEUE_IND_ID__NUM_OF
#define bcmbal_tm_sched_key_id_dir                                          BCMBAL_TM_SCHED_KEY_ID_DIR
#define bcmbal_tm_sched_key_id_id                                           BCMBAL_TM_SCHED_KEY_ID_ID
#define bcmbal_tm_sched_key_id__num_of                                      BCMBAL_TM_SCHED_KEY_ID__NUM_OF
#define bcmbal_tm_sched_cfg_id_owner                                        BCMBAL_TM_SCHED_CFG_ID_OWNER
#define bcmbal_tm_sched_cfg_id_sched_type                                   BCMBAL_TM_SCHED_CFG_ID_SCHED_TYPE
#define bcmbal_tm_sched_cfg_id_sched_parent                                 BCMBAL_TM_SCHED_CFG_ID_SCHED_PARENT
#define bcmbal_tm_sched_cfg_id_sched_child_type                             BCMBAL_TM_SCHED_CFG_ID_SCHED_CHILD_TYPE
#define bcmbal_tm_sched_cfg_id_num_priorities                               BCMBAL_TM_SCHED_CFG_ID_NUM_PRIORITIES
#define bcmbal_tm_sched_cfg_id_rate                                         BCMBAL_TM_SCHED_CFG_ID_RATE
#define bcmbal_tm_sched_cfg_id_ext_itu_dba                                  BCMBAL_TM_SCHED_CFG_ID_EXT_ITU_DBA
#define bcmbal_tm_sched_cfg_id_ext_epon_dba                                 BCMBAL_TM_SCHED_CFG_ID_EXT_EPON_DBA
#define bcmbal_tm_sched_cfg_id_creation_mode                                BCMBAL_TM_SCHED_CFG_ID_CREATION_MODE
#define bcmbal_tm_sched_cfg_id_queues                                       BCMBAL_TM_SCHED_CFG_ID_QUEUES
#define bcmbal_tm_sched_cfg_id_sub_scheds                                   BCMBAL_TM_SCHED_CFG_ID_SUB_SCHEDS
#define bcmbal_tm_sched_cfg_id__num_of                                      BCMBAL_TM_SCHED_CFG_ID__NUM_OF
#define bcmbal_tm_sched_ind_id_owner                                        BCMBAL_TM_SCHED_IND_ID_OWNER
#define bcmbal_tm_sched_ind_id_sched_type                                   BCMBAL_TM_SCHED_IND_ID_SCHED_TYPE
#define bcmbal_tm_sched_ind_id_sched_parent                                 BCMBAL_TM_SCHED_IND_ID_SCHED_PARENT
#define bcmbal_tm_sched_ind_id_sched_child_type                             BCMBAL_TM_SCHED_IND_ID_SCHED_CHILD_TYPE
#define bcmbal_tm_sched_ind_id_num_priorities                               BCMBAL_TM_SCHED_IND_ID_NUM_PRIORITIES
#define bcmbal_tm_sched_ind_id_rate                                         BCMBAL_TM_SCHED_IND_ID_RATE
#define bcmbal_tm_sched_ind_id_ext_itu_dba                                  BCMBAL_TM_SCHED_IND_ID_EXT_ITU_DBA
#define bcmbal_tm_sched_ind_id_ext_epon_dba                                 BCMBAL_TM_SCHED_IND_ID_EXT_EPON_DBA
#define bcmbal_tm_sched_ind_id_creation_mode                                BCMBAL_TM_SCHED_IND_ID_CREATION_MODE
#define bcmbal_tm_sched_ind_id_queues                                       BCMBAL_TM_SCHED_IND_ID_QUEUES
#define bcmbal_tm_sched_ind_id_sub_scheds                                   BCMBAL_TM_SCHED_IND_ID_SUB_SCHEDS
#define bcmbal_tm_sched_ind_id__num_of                                      BCMBAL_TM_SCHED_IND_ID__NUM_OF

/** Checks whether the given object type has the given tag. 
 *
 * \return true if the given object has the given tag, false otherwise 
 */
bcmos_bool bcmbal_obj_has_tag(bcmbal_obj_id obj, bcmbal_obj_tag tag);

#define BCMBAL_OBJ_ID_ANY   ((bcmbal_obj_id) UINT16_MAX)

/** @} */
#endif /* BAL_MODEL_IDS_H_ */
