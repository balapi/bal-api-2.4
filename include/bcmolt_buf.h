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

#ifndef BCMOLT_BUF_H_
#define BCMOLT_BUF_H_

#include "bcmos_system.h"

/** Generic memory stream object */
typedef struct bcmolt_buf bcmolt_buf;

struct bcmolt_buf
{
    uint8_t *start;  /**< Pointer to the start of the buffer */
    uint8_t *curr;   /**< Pointer to the current position in the buffer */
    uint32_t len;    /**< Total Length of buffer */
    /* The following 2 fields enable foreign buffer encapsulation */
    void (*free)(void *bh);  /**< Foreign buffer release callback */
    void *bh;        /**< Foreign buffer handle */
};

/* Serialization buffer endianness */
#define BCMOLT_BUF_ENDIAN_FIXED BCMOS_ENDIAN_BIG

#if BCMOLT_BUF_ENDIAN_FIXED == BCMOS_ENDIAN_BIG
    #define BCMOLT_BUF_ENDIAN_BUF_TO_CPU(size, n) BCMOS_ENDIAN_BIG_TO_CPU_##size(n)
    #define BCMOLT_BUF_ENDIAN_CPU_TO_BUF(size, n) BCMOS_ENDIAN_CPU_TO_BIG_##size(n)
#else
    #define BCMOLT_BUF_ENDIAN_BUF_TO_CPU(size, n) BCMOS_ENDIAN_LITTLE_TO_CPU_##size(n)
    #define BCMOLT_BUF_ENDIAN_CPU_TO_BUF(size, n) BCMOS_ENDIAN_CPU_TO_LITTLE_##size(n)
#endif

/** Initalize a bcmolt_buf stream
 *
 * \param buf
 * \param size
 * \param start
 * \param endian Endianness of numbers in the resulting stream.
 *               This parameter is only for sanity check. Buffer endianness is
 *               set at compile time. Application MUST NOT rely on default buffer endianness
 *               being Big Endian.
 *               If Big Endian buffer is required, application must use
 *               access functions with "_be" designator (bcmolt_buf_read_u16_be(), etc.)
 */
void bcmolt_buf_init(bcmolt_buf *buf, uint32_t size, uint8_t *start, bcmos_endian endian);

/** Allocate data buffer and initialize bcmolt_buf stream
 *
 * \param buf
 * \param size
 * \param endian Endianness of numbers in the resulting stream.
 *               See explanation in bcmolt_buf_alloc()
 * \return BCM_ERR_OK or BCM_ERR_NOMEM
 */
bcmos_errno bcmolt_buf_alloc(bcmolt_buf *buf, uint32_t size, bcmos_endian endian);

/** Release data buffer pointed by bcmolt_buf stream
 * \param[in,out] buf
 */
void bcmolt_buf_free(bcmolt_buf *buf);

/** Read from the buffer
 *
 * \param buf    bcmolt_buf instance
 * \param to     Where to read to
 * \param len    Number of bytes to copy
 *
 * \return       BCMOS_TRUE if successfully copied
 */
bcmos_bool bcmolt_buf_read(bcmolt_buf *buf, void *to, size_t len);

/** Transfer bytes from one buf to another
 *
 * \param *from    Source buffer
 * \param *to      Destination buffer
 * \param bytes    Number of bytes to transfer
 * \return         BCMOS_TRUE if successfully transferred
 */
bcmos_bool bcmolt_buf_transfer_bytes(bcmolt_buf *from, bcmolt_buf *to, uint32_t bytes);

/** Write to the buffer
 *
 * \param buf    bcmolt_buf instance
 * \param from   Source, to copy from
 * \param len    Number of bytes to copy
 *
 * \return       BCMOS_TRUE if successfully copied
 */
bcmos_bool bcmolt_buf_write(bcmolt_buf *buf, const void *from, size_t len);

/** Move the current pointer to a given position in the buffer
 *
 * \param pos    Byte position in the buffer to move the current pointer to
 *
 * \param *buf   Input buffer
 * \return       BCMOS_FALSE if len takes us past the end of buffer
 */
bcmos_bool bcmolt_buf_set_pos(bcmolt_buf *buf, uint32_t pos);

/** Move the current pointer ahead by given number of bytes
 *
 * \param buf    bcmolt_buf instance
 * \param len    Number of bytes to skip
 *
 * \return       BCMOS_FALSE if len takes us past the end of buffer
 */
bcmos_bool bcmolt_buf_skip(bcmolt_buf *buf, uint32_t len);

/** Move the current pointer back by given number of bytes
 *
 * \param buf    bcmolt_buf instance
 * \param len    Number of bytes to go back
 *
 * \return       BCMOS_FALSE if len takes us past the start of buffer
 */
bcmos_bool bcmolt_buf_rewind(bcmolt_buf *buf, uint32_t len);

/** Get the current buffer pointer
 *
 * \param buf   bcmolt_buf instance
 *
 * \return      the current buffer pointer
 */
static inline uint8_t *bcmolt_buf_snap_get(const bcmolt_buf *buf)
{
    return buf->curr;
}

/** Move the current pointer to a snapped location
 *
 * \param buf   bcmolt_buf instance
 * \param snap  snapped location
 */
static inline void bcmolt_buf_snap_restore(bcmolt_buf *buf, uint8_t *snap)
{
    buf->curr = snap;
}

/** Get the length of unprocessed bytes in given stream
 *
 * \param buf    Input buffer
 *
 * \return       The number of remaining bytes in the buffer
 */
static inline uint32_t bcmolt_buf_get_remaining_size(const bcmolt_buf *buf)
{
    return (uint32_t)((buf->start + buf->len) - buf->curr);
}

/** Get amount of buf that has been read or written so far
 *
 * \param buf     Input buffer
 * \return        Amount of buffer used
 */
static inline uint32_t bcmolt_buf_get_used(const bcmolt_buf *buf)
{
    return (uint32_t)(buf->curr - buf->start);
}

/** Reads a uint8_t from a buffer
 *
 * \param buf Buffer to read from
 * \param val uint8_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_u8(bcmolt_buf *buf, uint8_t *val)
{
    return bcmolt_buf_read(buf, val, sizeof(*val));
}

/** Writes a uint8_t to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    uint8_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_u8(bcmolt_buf *buf, uint8_t val)
{
    return bcmolt_buf_write(buf, &val, sizeof(val));
}

/** Reads a boolean from a buffer
 *
 * \param *buf
 * \param *val
 */
bcmos_bool bcmolt_buf_read_bool(bcmolt_buf *buf, bcmos_bool *val);

/** Writes a bcmos_bool to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    uint8_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_bool(bcmolt_buf *buf, bcmos_bool val)
{
    return bcmolt_buf_write_u8(buf, val ? 1 : 0);
}

/** Reads a int8_t from a buffer
 *
 * \param buf Buffer to read from
 * \param val int8_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_s8(bcmolt_buf *buf, int8_t *val)
{
    return bcmolt_buf_read_u8(buf, (uint8_t *)val);
}

/** Writes a int8_t to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    int8_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_s8(bcmolt_buf *buf, int8_t val)
{
    return bcmolt_buf_write_u8(buf, (uint8_t)val);
}

/** Reads a uint16_t from a buffer
 *
 * \param buf Buffer to read from
 * \param val uint16_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_u16(bcmolt_buf *buf, uint16_t *val)
{
    bcmos_bool res = bcmolt_buf_read(buf, val, sizeof(*val));
    *val = BCMOLT_BUF_ENDIAN_BUF_TO_CPU(U16, *val);
    return res;
}

/** Reads a uint16_t from a Big Endian buffer
 *
 * \param buf Buffer to read from
 * \param val uint16_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_u16_be(bcmolt_buf *buf, uint16_t *val)
{
    bcmos_bool res = bcmolt_buf_read(buf, val, sizeof(*val));
    *val = BCMOS_ENDIAN_BIG_TO_CPU_U16(*val);
    return res;
}

/** Writes a uint16_t to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    uint16_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_u16(bcmolt_buf *buf, uint16_t val)
{
    val = BCMOLT_BUF_ENDIAN_CPU_TO_BUF(U16, val);
    return bcmolt_buf_write(buf, &val, sizeof(val));
}

/** Writes a uint16_t to a Big Endian buffer
 *
 * \param buf    Buffer to write to
 * \param val    uint16_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_u16_be(bcmolt_buf *buf, uint16_t val)
{
    val = BCMOS_ENDIAN_CPU_TO_BIG_U16(val);
    return bcmolt_buf_write(buf, &val, sizeof(val));
}

/** Reads a int16_t from a buffer
 *
 * \param buf Buffer to read from
 * \param val int16_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_s16(bcmolt_buf *buf, int16_t *val)
{
    return bcmolt_buf_read_u16(buf, (uint16_t *)val);
}

/** Reads a int16_t from a Big Endian buffer
 *
 * \param buf Buffer to read from
 * \param val int16_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_s16_be(bcmolt_buf *buf, int16_t *val)
{
    return bcmolt_buf_read_u16_be(buf, (uint16_t *)val);
}

/** Writes int16_t to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    int16_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_s16(bcmolt_buf *buf, int16_t val)
{
    return bcmolt_buf_write_u16(buf, (uint16_t)val);
}

/** Writes int16_t to a Big Endian buffer
 *
 * \param buf    Buffer to write to
 * \param val    int16_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_s16_be(bcmolt_buf *buf, int16_t val)
{
    return bcmolt_buf_write_u16_be(buf, (uint16_t)val);
}

/** Reads a bcmos_u24 from a buffer
 *
 * \param buf Buffer to read from
 * \param val bcmos_u24 to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_u24(bcmolt_buf *buf, uint24_t *val)
{
    return bcmolt_buf_read_u8(buf, &(val->low_hi.hi)) &&
           bcmolt_buf_read_u8(buf, &(val->low_hi.mid)) &&
           bcmolt_buf_read_u8(buf, &(val->low_hi.low));
}

/** Writes a bcmos_u24 to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    bcmos_u24 to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_u24(bcmolt_buf *buf, uint24_t val)
{
    return bcmolt_buf_write_u8(buf, val.low_hi.hi) &&
           bcmolt_buf_write_u8(buf, val.low_hi.mid) &&
           bcmolt_buf_write_u8(buf, val.low_hi.low);
}

/** Reads a uint32_t from a buffer
 *
 * \param buf Buffer to read from
 * \param val uint32_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_u32(bcmolt_buf *buf, uint32_t *val)
{
    bcmos_bool res = bcmolt_buf_read(buf, val, sizeof(*val));
    *val = BCMOLT_BUF_ENDIAN_BUF_TO_CPU(U32, *val);
    return res;
}

/** Reads a uint32_t from a Big Endian buffer
 *
 * \param buf Buffer to read from
 * \param val uint32_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_u32_be(bcmolt_buf *buf, uint32_t *val)
{
    bcmos_bool res = bcmolt_buf_read(buf, val, sizeof(*val));
    *val = BCMOS_ENDIAN_BIG_TO_CPU_U32(*val);
    return res;
}

/** Writes a uint32_t to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    uint32_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_u32(bcmolt_buf *buf, uint32_t val)
{
    val = BCMOLT_BUF_ENDIAN_CPU_TO_BUF(U32, val);
    return bcmolt_buf_write(buf, &val, sizeof(val));
}

/** Writes a uint32_t to a Big Endian buffer
 *
 * \param buf    Buffer to write to
 * \param val    uint32_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_u32_be(bcmolt_buf *buf, uint32_t val)
{
    val = BCMOS_ENDIAN_CPU_TO_BIG_U32(val);
    return bcmolt_buf_write(buf, &val, sizeof(val));
}

/** Reads a int32_t from a buffer
 *
 * \param buf Buffer to read from
 * \param val int32_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_s32(bcmolt_buf *buf, int32_t *val)
{
    return bcmolt_buf_read_u32(buf, (uint32_t *)val);
}

/** Reads a int32_t from a big endian buffer
 *
 * \param buf Buffer to read from
 * \param val int32_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_s32_be(bcmolt_buf *buf, int32_t *val)
{
    return bcmolt_buf_read_u32_be(buf, (uint32_t *)val);
}

/** Writes a int32_t to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    int32_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_s32(bcmolt_buf *buf, int32_t val)
{
    return bcmolt_buf_write_u32(buf, (uint32_t)val);
}

/** Writes a int32_t to a Big Endian buffer
 *
 * \param buf    Buffer to write to
 * \param val    int32_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_s32_be(bcmolt_buf *buf, int32_t val)
{
    return bcmolt_buf_write_u32_be(buf, (uint32_t)val);
}

/** Reads a uint64_t from a buffer
 *
 * \param buf Buffer to read from
 * \param val uint64_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_u64(bcmolt_buf *buf, uint64_t *val)
{
    bcmos_bool res = bcmolt_buf_read(buf, val, sizeof(*val));
    *val = BCMOLT_BUF_ENDIAN_BUF_TO_CPU(U64, *val);
    return res;
}

/** Reads a uint64_t from a Big Endian buffer
 *
 * \param buf Buffer to read from
 * \param val uint64_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_u64_be(bcmolt_buf *buf, uint64_t *val)
{
    bcmos_bool res = bcmolt_buf_read(buf, val, sizeof(*val));
    *val = BCMOS_ENDIAN_BIG_TO_CPU_U64(*val);
    return res;
}

/** Writes a uint64_t to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    uint64_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_u64(bcmolt_buf *buf, uint64_t val)
{
    val = BCMOLT_BUF_ENDIAN_CPU_TO_BUF(U64, val);
    return bcmolt_buf_write(buf, &val, sizeof(val));
}

/** Writes a uint64_t to a Big Endian buffer
 *
 * \param buf    Buffer to write to
 * \param val    uint64_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_u64_be(bcmolt_buf *buf, uint64_t val)
{
    val = BCMOS_ENDIAN_CPU_TO_BIG_U64(val);
    return bcmolt_buf_write(buf, &val, sizeof(val));
}

/** Reads a int64_t from a buffer
 *
 * \param buf Buffer to read from
 * \param val int64_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_s64(bcmolt_buf *buf, int64_t *val)
{
    return bcmolt_buf_read_u64(buf, (uint64_t *)val);
}

/** Reads a int64_t from a Big Endian buffer
 *
 * \param buf Buffer to read from
 * \param val int64_t to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_s64_be(bcmolt_buf *buf, int64_t *val)
{
    return bcmolt_buf_read_u64_be(buf, (uint64_t *)val);
}

/** Writes a int64_t to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    int64_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_s64(bcmolt_buf *buf, int64_t val)
{
    return bcmolt_buf_write_u64(buf, (uint64_t)val);
}

/** Writes a int64_t to a Big Endian buffer
 *
 * \param buf    Buffer to write to
 * \param val    int64_t to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_s64_be(bcmolt_buf *buf, int64_t val)
{
    return bcmolt_buf_write_u64_be(buf, (uint64_t)val);
}

/** Reads a float from a buffer
 *
 * \param buf Buffer to read from
 * \param val float to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_float(bcmolt_buf *buf, float *val)
{
    return bcmolt_buf_read_u32(buf, (uint32_t *)val);
}

/** Writes a float to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    float to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_float(bcmolt_buf *buf, float val)
{
    uint32_t *num = (uint32_t *)&val;
    return bcmolt_buf_write_u32(buf, *num);
}

/** Reads a double from a buffer
 *
 * \param buf Buffer to read from
 * \param val double to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_double(bcmolt_buf *buf, double *val)
{
    return bcmolt_buf_read_u64(buf, (uint64_t *)val);
}

/** Writes a double to a buffer
 *
 * \param buf    Buffer to write to
 * \param val    double to write
 *
 * \return       BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_double(bcmolt_buf *buf, double val)
{
    uint64_t *num = (uint64_t *)&val;
    return bcmolt_buf_write_u64(buf, *num);
}

/** Reads a bcmos_vlan_tag from a buffer
 *
 * \param buf Buffer to read from
 * \param val bcmos_vlan_tag to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_vlan_tag(bcmolt_buf *buf, bcmos_vlan_tag *val)
{
    return bcmolt_buf_read_u16(buf, (uint16_t *)val);
}

/** Writes a bcmos_vlan_tag to a buffer
 *
 * \param buf Buffer to write to
 * \param val bcmos_vlan_tag to write
 *
 * \return BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_vlan_tag(bcmolt_buf *buf, bcmos_vlan_tag val)
{
    return bcmolt_buf_write_u16(buf, (uint16_t)val);
}

/** Reads a bcmos_mac_address from a buffer
 *
 * \param buf Buffer to read from
 * \param val bcmos_mac_address to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_mac_address(bcmolt_buf *buf, bcmos_mac_address *val)
{
    return bcmolt_buf_read(buf, val, sizeof(bcmos_mac_address));
}

/** Writes a bcmos_mac_address to a buffer
 *
 * \param buf Buffer to write to
 * \param val bcmos_mac_address to write
 *
 * \return BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_mac_address(bcmolt_buf *buf, bcmos_mac_address val)
{
    return bcmolt_buf_write(buf, &val, sizeof(bcmos_mac_address));
}

/** Reads a bcmos_ipv4_address from a buffer
 *
 * \param buf Buffer to read from
 * \param val bcmos_ipv4_address to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_ipv4_address(bcmolt_buf *buf, bcmos_ipv4_address *val)
{
    return bcmolt_buf_read(buf, val->u8, sizeof(bcmos_ipv4_address));
}

/** Writes a bcmos_ipv4_address to a buffer
 *
 * \param buf Buffer to write to
 * \param val bcmos_ipv4_address to write
 *
 * \return BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_ipv4_address(bcmolt_buf *buf, bcmos_ipv4_address val)
{
    return bcmolt_buf_write(buf, val.u8, sizeof(bcmos_ipv4_address));
}

/** Reads a bcmos_ipv6_address from a buffer
 *
 * \param buf Buffer to read from
 * \param val bcmos_ipv6_address to read
 *
 * \return BCMOS_TRUE if read successful
 */
static inline bcmos_bool bcmolt_buf_read_ipv6_address(bcmolt_buf *buf, bcmos_ipv6_address *val)
{
    return bcmolt_buf_read(buf, *val, sizeof(bcmos_ipv6_address));
}

/** Writes a bcmos_ipv6_address to a buffer
 *
 * \param buf Buffer to write to
 * \param val bcmos_ipv6_address to write
 *
 * \return BCMOS_TRUE if write successful
 */
static inline bcmos_bool bcmolt_buf_write_ipv6_address(bcmolt_buf *buf, bcmos_ipv6_address val)
{
    return bcmolt_buf_write(buf, val, sizeof(bcmos_ipv6_address));
}

#endif /* BCMOLT_BUF_H_ */
