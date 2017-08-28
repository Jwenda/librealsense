/* License: Apache 2.0. See LICENSE file in root directory.
   Copyright(c) 2017 Intel Corporation. All Rights Reserved. */

/** \file rs.h
* \brief
* Exposes librealsense functionality for C compilers
*/

#ifndef LIBREALSENSE_RS2_H
#define LIBREALSENSE_RS2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "h/rs_types.h"
#include "h/rs_context.h"
#include "h/rs_device.h"
#include "h/rs_frame.h"
#include "h/rs_option.h"
#include "h/rs_processing.h"
#include "h/rs_record_playback.h"
#include "h/rs_sensor.h"

#define RS2_API_MAJOR_VERSION    2
#define RS2_API_MINOR_VERSION    7
#define RS2_API_PATCH_VERSION    6
#define RS2_API_BUILD_VERSION    0

#define STRINGIFY(arg) #arg
#define VAR_ARG_STRING(arg) STRINGIFY(arg)

/* Versioning rules            : For each release at least one of [MJR/MNR/PTCH] triple is promoted                                             */
/*                             : Versions that differ by RS2_API_PATCH_VERSION only are interface-compatible, i.e. no user-code changes required */
/*                             : Versions that differ by MAJOR/MINOR VERSION component can introduce API changes                                */
/* Version in encoded integer format (1,9,x) -> 01090x. note that each component is limited into [0-99] range by design                         */
#define RS2_API_VERSION  (((RS2_API_MAJOR_VERSION) * 10000) + ((RS2_API_MINOR_VERSION) * 100) + (RS2_API_PATCH_VERSION))
/* Return version in "X.Y.Z" format */
#define RS2_API_VERSION_STR (VAR_ARG_STRING(RS2_API_MAJOR_VERSION.RS2_API_MINOR_VERSION.RS2_API_PATCH_VERSION))

/**
* get the size of rs2_raw_data_buffer
* \param[in] buffer  pointer to rs2_raw_data_buffer returned by rs2_send_and_receive_raw_data
* \param[out] error  if non-null, receives any error that occurs during this call, otherwise, errors are ignored
* \return size of rs2_raw_data_buffer
*/
int rs2_get_raw_data_size(const rs2_raw_data_buffer* buffer, rs2_error** error);

/**
* Delete rs2_raw_data_buffer
* \param[in] buffer        rs2_raw_data_buffer returned by rs2_send_and_receive_raw_data
*/
void rs2_delete_raw_data(const rs2_raw_data_buffer* buffer);

/**
* Retrieve char array from rs2_raw_data_buffer
* \param[in] buffer   rs2_raw_data_buffer returned by rs2_send_and_receive_raw_data
* \param[out] error   if non-null, receives any error that occurs during this call, otherwise, errors are ignored
* \return raw data
*/
const unsigned char* rs2_get_raw_data(const rs2_raw_data_buffer* buffer, rs2_error** error);

/**
 * Retrieve the API version from the source code. Evaluate that the value is conformant to the established policies
 * \param[out] error  if non-null, receives any error that occurs during this call, otherwise, errors are ignored
 * \return            the version API encoded into integer value "1.9.3" -> 10903
 */
int rs2_get_api_version(rs2_error** error);

void rs2_log_to_console(rs2_log_severity min_severity, rs2_error ** error);

void rs2_log_to_file(rs2_log_severity min_severity, const char * file_path, rs2_error ** error);

float rs2_depth_frame_get_distance(const rs2_frame* frame_ref, int x, int y, rs2_error** error);

#ifdef __cplusplus
}
#endif
#endif
