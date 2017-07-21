/*
<:copyright-BRCM:2017:DUAL/GPL:standard

   Broadcom Proprietary and Confidential.(c) 2017 Broadcom
   All Rights Reserved

Unless you and Broadcom execute a separate written software license
agreement governing use of this software, this software is licensed
to you under the terms of the GNU General Public License version 2
(the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
with the following added to such license:

   As a special exception, the copyright holders of this software give
   you permission to link this software with independent modules, and
   to copy and distribute the resulting executable under terms of your
   choice, provided that you also meet, for each linked independent
   module, the terms and conditions of the license of that module.
   An independent module is a module which is not derived from this
   software.  The special exception does not apply to any modifications
   of the software.

Not withstanding the above, under no circumstances may you combine
this software in any way with any other Broadcom software provided
under a license other than the GPL, without Broadcom's express prior
written consent.

:>
 */

#ifndef BCMOS_ERRNO_H_
#define BCMOS_ERRNO_H_

/** \defgroup system_errno Error Codes
 * @{
 */

/** Error codes */
typedef enum
{
    BCM_ERR_OK                                 =  0,   /**< OK */
    BCM_ERR_IN_PROGRESS                        = -1,   /**< Operation is in progress */
    BCM_ERR_PARM                               = -2,   /**< Error in parameters */
    BCM_ERR_NOMEM                              = -3,   /**< No memory */
    BCM_ERR_NORES                              = -4,   /**< No resources */
    BCM_ERR_INTERNAL                           = -5,   /**< Internal error */
    BCM_ERR_NOENT                              = -6,   /**< Entry doesn't exist */
    BCM_ERR_NODEV                              = -7,   /**< Device doesn't exist */
    BCM_ERR_ALREADY                            = -8,   /**< Entry already exists */
    BCM_ERR_RANGE                              = -9,   /**< Out of range */
    BCM_ERR_PERM                               = -10,  /**< No permission to perform an operation */
    BCM_ERR_NOT_SUPPORTED                      = -11,  /**< Operation is not supported */
    BCM_ERR_PARSE                              = -12,  /**< Parsing error */
    BCM_ERR_INVALID_OP                         = -13,  /**< Invalid operation */
    BCM_ERR_IO                                 = -14,  /**< I/O error */
    BCM_ERR_STATE                              = -15,  /**< Object is in bad state */
    BCM_ERR_DELETED                            = -16,  /**< Object is deleted */
    BCM_ERR_TOO_MANY                           = -17,  /**< Too many objects */
    BCM_ERR_NO_MORE                            = -18,  /**< No more entries */
    BCM_ERR_OVERFLOW                           = -19,  /**< Buffer overflow */
    BCM_ERR_COMM_FAIL                          = -20,  /**< Communication failure */
    BCM_ERR_NOT_CONNECTED                      = -21,  /**< No connection with the target system */
    BCM_ERR_SYSCALL_ERR                        = -22,  /**< System call returned error */
    BCM_ERR_MSG_ERROR                          = -23,  /**< Received message is insane */
    BCM_ERR_TOO_MANY_REQS                      = -24,  /**< Too many outstanding requests */
    BCM_ERR_TIMEOUT                            = -25,  /**< Operation timed out */
    BCM_ERR_TOO_MANY_FRAGS                     = -26,  /**< Too many fragments */
    BCM_ERR_NULL                               = -27,  /**< Got NULL pointer */
    BCM_ERR_READ_ONLY                          = -28,  /**< Attempt to set read-only parameter */
    BCM_ERR_ONU_ERR_RESP                       = -29,  /**< ONU returned an error response */
    BCM_ERR_MANDATORY_PARM_IS_MISSING          = -30,  /**< Mandatory parameter is missing */
    BCM_ERR_KEY_RANGE                          = -31,  /**< Key field was out of range */
    BCM_ERR_QUEUE_EMPTY                        = -32,  /**< Rx PCIe queue empty */
    BCM_ERR_QUEUE_FULL                         = -33,  /**< Tx PCIe queue full */
    BCM_ERR_TOO_LONG                           = -34,  /**< Processing is taking too long, but will finish eventually */
    BCM_ERR_INSUFFICIENT_LIST_MEM              = -35,  /**< Not enough memory was provided for variable-length lists */

    BCM_ERR_OUT_OF_SYNC                        = -36,  /**< Sequence number or operation step was out of sync. */
    BCM_ERR_CHECKSUM                           = -37,  /**< Checksum error */
    BCM_ERR_IMAGE_TYPE                         = -38,  /**< Unsupported file/image type */
    BCM_ERR_INCOMPLETE_TERMINATION             = -39,  /**< Incomplete premature termination */
    BCM_ERR_IB_SEND_IS_INHIBITED               = -40,  /**< In band; disconnected, send is inhibited*/
} bcmos_errno;

/** Map error code to error string
 * \param[in]   err     Error code
 * \returns Error string
 */
const char *bcmos_strerror(bcmos_errno err);

/** @} system_errno */

#endif /* BCMOS_ERRNO_H_ */
