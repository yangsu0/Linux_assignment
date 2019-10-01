/* Copyright 2017 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */
#ifdef CONFIG_DRM_AMD_DC_DSC_SUPPORT
#ifndef __DCN20_DSC_H__
#define __DCN20_DSC_H__

#include "dsc.h"
#include "dsc/dscc_types.h"
#include <drm/drm_dsc.h>

#define TO_DCN20_DSC(dsc)\
	container_of(dsc, struct dcn20_dsc, base)

#define DSC_REG_LIST_DCN20(id) \
	SRI(DSC_TOP_CONTROL, DSC_TOP, id),\
	SRI(DSC_DEBUG_CONTROL, DSC_TOP, id),\
	SRI(DSCC_CONFIG0, DSCC, id),\
	SRI(DSCC_CONFIG1, DSCC, id),\
	SRI(DSCC_STATUS, DSCC, id),\
	SRI(DSCC_INTERRUPT_CONTROL_STATUS, DSCC, id),\
	SRI(DSCC_PPS_CONFIG0, DSCC, id),\
	SRI(DSCC_PPS_CONFIG1, DSCC, id),\
	SRI(DSCC_PPS_CONFIG2, DSCC, id),\
	SRI(DSCC_PPS_CONFIG3, DSCC, id),\
	SRI(DSCC_PPS_CONFIG4, DSCC, id),\
	SRI(DSCC_PPS_CONFIG5, DSCC, id),\
	SRI(DSCC_PPS_CONFIG6, DSCC, id),\
	SRI(DSCC_PPS_CONFIG7, DSCC, id),\
	SRI(DSCC_PPS_CONFIG8, DSCC, id),\
	SRI(DSCC_PPS_CONFIG9, DSCC, id),\
	SRI(DSCC_PPS_CONFIG10, DSCC, id),\
	SRI(DSCC_PPS_CONFIG11, DSCC, id),\
	SRI(DSCC_PPS_CONFIG12, DSCC, id),\
	SRI(DSCC_PPS_CONFIG13, DSCC, id),\
	SRI(DSCC_PPS_CONFIG14, DSCC, id),\
	SRI(DSCC_PPS_CONFIG15, DSCC, id),\
	SRI(DSCC_PPS_CONFIG16, DSCC, id),\
	SRI(DSCC_PPS_CONFIG17, DSCC, id),\
	SRI(DSCC_PPS_CONFIG18, DSCC, id),\
	SRI(DSCC_PPS_CONFIG19, DSCC, id),\
	SRI(DSCC_PPS_CONFIG20, DSCC, id),\
	SRI(DSCC_PPS_CONFIG21, DSCC, id),\
	SRI(DSCC_PPS_CONFIG22, DSCC, id),\
	SRI(DSCC_MEM_POWER_CONTROL, DSCC, id),\
	SRI(DSCC_R_Y_SQUARED_ERROR_LOWER, DSCC, id),\
	SRI(DSCC_R_Y_SQUARED_ERROR_UPPER, DSCC, id),\
	SRI(DSCC_G_CB_SQUARED_ERROR_LOWER, DSCC, id),\
	SRI(DSCC_G_CB_SQUARED_ERROR_UPPER, DSCC, id),\
	SRI(DSCC_B_CR_SQUARED_ERROR_LOWER, DSCC, id),\
	SRI(DSCC_B_CR_SQUARED_ERROR_UPPER, DSCC, id),\
	SRI(DSCC_MAX_ABS_ERROR0, DSCC, id),\
	SRI(DSCC_MAX_ABS_ERROR1, DSCC, id),\
	SRI(DSCC_RATE_BUFFER0_MAX_FULLNESS_LEVEL, DSCC, id),\
	SRI(DSCC_RATE_BUFFER1_MAX_FULLNESS_LEVEL, DSCC, id),\
	SRI(DSCC_RATE_BUFFER2_MAX_FULLNESS_LEVEL, DSCC, id),\
	SRI(DSCC_RATE_BUFFER3_MAX_FULLNESS_LEVEL, DSCC, id),\
	SRI(DSCC_RATE_CONTROL_BUFFER0_MAX_FULLNESS_LEVEL, DSCC, id),\
	SRI(DSCC_RATE_CONTROL_BUFFER1_MAX_FULLNESS_LEVEL, DSCC, id),\
	SRI(DSCC_RATE_CONTROL_BUFFER2_MAX_FULLNESS_LEVEL, DSCC, id),\
	SRI(DSCC_RATE_CONTROL_BUFFER3_MAX_FULLNESS_LEVEL, DSCC, id),\
	SRI(DSCC_TEST_DEBUG_BUS_ROTATE, DSCC, id),\
	SRI(DSCCIF_CONFIG0, DSCCIF, id),\
	SRI(DSCCIF_CONFIG1, DSCCIF, id),\
	SRI(DSCRM_DSC_FORWARD_CONFIG, DSCRM, id)


#define DSC_SF(reg_name, field_name, post_fix)\
	.field_name = reg_name ## __ ## field_name ## post_fix

//Used in resolving the corner case with duplicate field name
#define DSC2_SF(reg_name, field_name, post_fix)\
	.field_name = reg_name ## _ ## field_name ## post_fix

#define DSC_REG_LIST_SH_MASK_DCN20(mask_sh)\
	DSC_SF(DSC_TOP0_DSC_TOP_CONTROL, DSC_CLOCK_EN, mask_sh), \
	DSC_SF(DSC_TOP0_DSC_TOP_CONTROL, DSC_DISPCLK_R_GATE_DIS, mask_sh), \
	DSC_SF(DSC_TOP0_DSC_TOP_CONTROL, DSC_DSCCLK_R_GATE_DIS, mask_sh), \
	DSC_SF(DSC_TOP0_DSC_DEBUG_CONTROL, DSC_DBG_EN, mask_sh), \
	DSC_SF(DSC_TOP0_DSC_DEBUG_CONTROL, DSC_TEST_CLOCK_MUX_SEL, mask_sh), \
	DSC_SF(DSCC0_DSCC_CONFIG0, ICH_RESET_AT_END_OF_LINE, mask_sh), \
	DSC_SF(DSCC0_DSCC_CONFIG0, NUMBER_OF_SLICES_PER_LINE, mask_sh), \
	DSC_SF(DSCC0_DSCC_CONFIG0, ALTERNATE_ICH_ENCODING_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_CONFIG0, NUMBER_OF_SLICES_IN_VERTICAL_DIRECTION, mask_sh), \
	DSC_SF(DSCC0_DSCC_CONFIG1, DSCC_RATE_CONTROL_BUFFER_MODEL_SIZE, mask_sh), \
	DSC_SF(DSCC0_DSCC_CONFIG1, DSCC_DISABLE_ICH, mask_sh), \
	DSC_SF(DSCC0_DSCC_STATUS, DSCC_DOUBLE_BUFFER_REG_UPDATE_PENDING, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER0_OVERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER1_OVERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER2_OVERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER3_OVERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER0_UNDERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER1_UNDERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER2_UNDERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER3_UNDERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_CONTROL_BUFFER_MODEL0_OVERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_CONTROL_BUFFER_MODEL1_OVERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_CONTROL_BUFFER_MODEL2_OVERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_CONTROL_BUFFER_MODEL3_OVERFLOW_OCCURRED, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER0_OVERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER1_OVERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER2_OVERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER3_OVERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER0_UNDERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER1_UNDERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER2_UNDERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_BUFFER3_UNDERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_CONTROL_BUFFER_MODEL0_OVERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_CONTROL_BUFFER_MODEL1_OVERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_CONTROL_BUFFER_MODEL2_OVERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_INTERRUPT_CONTROL_STATUS, DSCC_RATE_CONTROL_BUFFER_MODEL3_OVERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG0, DSC_VERSION_MINOR, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG0, DSC_VERSION_MAJOR, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG0, PPS_IDENTIFIER, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG0, LINEBUF_DEPTH, mask_sh), \
	DSC2_SF(DSCC0, DSCC_PPS_CONFIG0__BITS_PER_COMPONENT, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG1, BITS_PER_PIXEL, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG1, VBR_ENABLE, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG1, SIMPLE_422, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG1, CONVERT_RGB, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG1, BLOCK_PRED_ENABLE, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG1, NATIVE_422, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG1, NATIVE_420, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG1, CHUNK_SIZE, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG2, PIC_WIDTH, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG2, PIC_HEIGHT, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG3, SLICE_WIDTH, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG3, SLICE_HEIGHT, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG4, INITIAL_XMIT_DELAY, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG4, INITIAL_DEC_DELAY, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG5, INITIAL_SCALE_VALUE, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG5, SCALE_INCREMENT_INTERVAL, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG6, SCALE_DECREMENT_INTERVAL, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG6, FIRST_LINE_BPG_OFFSET, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG6, SECOND_LINE_BPG_OFFSET, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG7, NFL_BPG_OFFSET, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG7, SLICE_BPG_OFFSET, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG8, NSL_BPG_OFFSET, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG8, SECOND_LINE_OFFSET_ADJ, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG9, INITIAL_OFFSET, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG9, FINAL_OFFSET, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG10, FLATNESS_MIN_QP, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG10, FLATNESS_MAX_QP, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG10, RC_MODEL_SIZE, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG11, RC_EDGE_FACTOR, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG11, RC_QUANT_INCR_LIMIT0, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG11, RC_QUANT_INCR_LIMIT1, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG11, RC_TGT_OFFSET_LO, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG11, RC_TGT_OFFSET_HI, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG12, RC_BUF_THRESH0, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG12, RC_BUF_THRESH1, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG12, RC_BUF_THRESH2, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG12, RC_BUF_THRESH3, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG13, RC_BUF_THRESH4, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG13, RC_BUF_THRESH5, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG13, RC_BUF_THRESH6, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG13, RC_BUF_THRESH7, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG14, RC_BUF_THRESH8, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG14, RC_BUF_THRESH9, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG14, RC_BUF_THRESH10, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG14, RC_BUF_THRESH11, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG15, RC_BUF_THRESH12, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG15, RC_BUF_THRESH13, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG15, RANGE_MIN_QP0, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG15, RANGE_MAX_QP0, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG15, RANGE_BPG_OFFSET0, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG16, RANGE_MIN_QP1, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG16, RANGE_MAX_QP1, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG16, RANGE_BPG_OFFSET1, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG16, RANGE_MIN_QP2, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG16, RANGE_MAX_QP2, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG16, RANGE_BPG_OFFSET2, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG17, RANGE_MIN_QP3, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG17, RANGE_MAX_QP3, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG17, RANGE_BPG_OFFSET3, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG17, RANGE_MIN_QP4, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG17, RANGE_MAX_QP4, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG17, RANGE_BPG_OFFSET4, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG18, RANGE_MIN_QP5, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG18, RANGE_MAX_QP5, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG18, RANGE_BPG_OFFSET5, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG18, RANGE_MIN_QP6, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG18, RANGE_MAX_QP6, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG18, RANGE_BPG_OFFSET6, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG19, RANGE_MIN_QP7, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG19, RANGE_MAX_QP7, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG19, RANGE_BPG_OFFSET7, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG19, RANGE_MIN_QP8, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG19, RANGE_MAX_QP8, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG19, RANGE_BPG_OFFSET8, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG20, RANGE_MIN_QP9, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG20, RANGE_MAX_QP9, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG20, RANGE_BPG_OFFSET9, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG20, RANGE_MIN_QP10, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG20, RANGE_MAX_QP10, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG20, RANGE_BPG_OFFSET10, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG21, RANGE_MIN_QP11, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG21, RANGE_MAX_QP11, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG21, RANGE_BPG_OFFSET11, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG21, RANGE_MIN_QP12, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG21, RANGE_MAX_QP12, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG21, RANGE_BPG_OFFSET12, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG22, RANGE_MIN_QP13, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG22, RANGE_MAX_QP13, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG22, RANGE_BPG_OFFSET13, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG22, RANGE_MIN_QP14, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG22, RANGE_MAX_QP14, mask_sh), \
	DSC_SF(DSCC0_DSCC_PPS_CONFIG22, RANGE_BPG_OFFSET14, mask_sh), \
	DSC_SF(DSCC0_DSCC_MEM_POWER_CONTROL, DSCC_DEFAULT_MEM_LOW_POWER_STATE, mask_sh), \
	DSC_SF(DSCC0_DSCC_MEM_POWER_CONTROL, DSCC_MEM_PWR_FORCE, mask_sh), \
	DSC_SF(DSCC0_DSCC_MEM_POWER_CONTROL, DSCC_MEM_PWR_DIS, mask_sh), \
	DSC_SF(DSCC0_DSCC_MEM_POWER_CONTROL, DSCC_MEM_PWR_STATE, mask_sh), \
	DSC_SF(DSCC0_DSCC_MEM_POWER_CONTROL, DSCC_NATIVE_422_MEM_PWR_FORCE, mask_sh), \
	DSC_SF(DSCC0_DSCC_MEM_POWER_CONTROL, DSCC_NATIVE_422_MEM_PWR_DIS, mask_sh), \
	DSC_SF(DSCC0_DSCC_MEM_POWER_CONTROL, DSCC_NATIVE_422_MEM_PWR_STATE, mask_sh), \
	DSC_SF(DSCC0_DSCC_R_Y_SQUARED_ERROR_LOWER, DSCC_R_Y_SQUARED_ERROR_LOWER, mask_sh), \
	DSC_SF(DSCC0_DSCC_R_Y_SQUARED_ERROR_UPPER, DSCC_R_Y_SQUARED_ERROR_UPPER, mask_sh), \
	DSC_SF(DSCC0_DSCC_G_CB_SQUARED_ERROR_LOWER, DSCC_G_CB_SQUARED_ERROR_LOWER, mask_sh), \
	DSC_SF(DSCC0_DSCC_G_CB_SQUARED_ERROR_UPPER, DSCC_G_CB_SQUARED_ERROR_UPPER, mask_sh), \
	DSC_SF(DSCC0_DSCC_B_CR_SQUARED_ERROR_LOWER, DSCC_B_CR_SQUARED_ERROR_LOWER, mask_sh), \
	DSC_SF(DSCC0_DSCC_B_CR_SQUARED_ERROR_UPPER, DSCC_B_CR_SQUARED_ERROR_UPPER, mask_sh), \
	DSC_SF(DSCC0_DSCC_MAX_ABS_ERROR0, DSCC_R_Y_MAX_ABS_ERROR, mask_sh), \
	DSC_SF(DSCC0_DSCC_MAX_ABS_ERROR0, DSCC_G_CB_MAX_ABS_ERROR, mask_sh), \
	DSC_SF(DSCC0_DSCC_MAX_ABS_ERROR1, DSCC_B_CR_MAX_ABS_ERROR, mask_sh), \
	DSC_SF(DSCC0_DSCC_RATE_BUFFER0_MAX_FULLNESS_LEVEL, DSCC_RATE_BUFFER0_MAX_FULLNESS_LEVEL, mask_sh), \
	DSC_SF(DSCC0_DSCC_RATE_BUFFER1_MAX_FULLNESS_LEVEL, DSCC_RATE_BUFFER1_MAX_FULLNESS_LEVEL, mask_sh), \
	DSC_SF(DSCC0_DSCC_RATE_BUFFER2_MAX_FULLNESS_LEVEL, DSCC_RATE_BUFFER2_MAX_FULLNESS_LEVEL, mask_sh), \
	DSC_SF(DSCC0_DSCC_RATE_BUFFER3_MAX_FULLNESS_LEVEL, DSCC_RATE_BUFFER3_MAX_FULLNESS_LEVEL, mask_sh), \
	DSC_SF(DSCC0_DSCC_RATE_CONTROL_BUFFER0_MAX_FULLNESS_LEVEL, DSCC_RATE_CONTROL_BUFFER0_MAX_FULLNESS_LEVEL, mask_sh), \
	DSC_SF(DSCC0_DSCC_RATE_CONTROL_BUFFER1_MAX_FULLNESS_LEVEL, DSCC_RATE_CONTROL_BUFFER1_MAX_FULLNESS_LEVEL, mask_sh), \
	DSC_SF(DSCC0_DSCC_RATE_CONTROL_BUFFER2_MAX_FULLNESS_LEVEL, DSCC_RATE_CONTROL_BUFFER2_MAX_FULLNESS_LEVEL, mask_sh), \
	DSC_SF(DSCC0_DSCC_RATE_CONTROL_BUFFER3_MAX_FULLNESS_LEVEL, DSCC_RATE_CONTROL_BUFFER3_MAX_FULLNESS_LEVEL, mask_sh), \
	DSC_SF(DSCC0_DSCC_TEST_DEBUG_BUS_ROTATE, DSCC_TEST_DEBUG_BUS0_ROTATE, mask_sh), \
	DSC_SF(DSCC0_DSCC_TEST_DEBUG_BUS_ROTATE, DSCC_TEST_DEBUG_BUS1_ROTATE, mask_sh), \
	DSC_SF(DSCC0_DSCC_TEST_DEBUG_BUS_ROTATE, DSCC_TEST_DEBUG_BUS2_ROTATE, mask_sh), \
	DSC_SF(DSCC0_DSCC_TEST_DEBUG_BUS_ROTATE, DSCC_TEST_DEBUG_BUS3_ROTATE, mask_sh), \
	DSC_SF(DSCCIF0_DSCCIF_CONFIG0, INPUT_INTERFACE_UNDERFLOW_RECOVERY_EN, mask_sh), \
	DSC_SF(DSCCIF0_DSCCIF_CONFIG0, INPUT_INTERFACE_UNDERFLOW_OCCURRED_INT_EN, mask_sh), \
	DSC_SF(DSCCIF0_DSCCIF_CONFIG0, INPUT_INTERFACE_UNDERFLOW_OCCURRED_STATUS, mask_sh), \
	DSC_SF(DSCCIF0_DSCCIF_CONFIG0, INPUT_PIXEL_FORMAT, mask_sh), \
	DSC2_SF(DSCCIF0, DSCCIF_CONFIG0__BITS_PER_COMPONENT, mask_sh), \
	DSC_SF(DSCCIF0_DSCCIF_CONFIG0, DOUBLE_BUFFER_REG_UPDATE_PENDING, mask_sh), \
	DSC_SF(DSCCIF0_DSCCIF_CONFIG1, PIC_WIDTH, mask_sh), \
	DSC_SF(DSCCIF0_DSCCIF_CONFIG1, PIC_HEIGHT, mask_sh), \
	DSC_SF(DSCRM0_DSCRM_DSC_FORWARD_CONFIG, DSCRM_DSC_FORWARD_EN, mask_sh), \
	DSC_SF(DSCRM0_DSCRM_DSC_FORWARD_CONFIG, DSCRM_DSC_OPP_PIPE_SOURCE, mask_sh)



#define DSC_FIELD_LIST_DCN20(type)\
	type DSC_CLOCK_EN; \
	type DSC_DISPCLK_R_GATE_DIS; \
	type DSC_DSCCLK_R_GATE_DIS; \
	type DSC_DBG_EN; \
	type DSC_TEST_CLOCK_MUX_SEL; \
	type ICH_RESET_AT_END_OF_LINE; \
	type NUMBER_OF_SLICES_PER_LINE; \
	type ALTERNATE_ICH_ENCODING_EN; \
	type NUMBER_OF_SLICES_IN_VERTICAL_DIRECTION; \
	type DSCC_RATE_CONTROL_BUFFER_MODEL_SIZE; \
	type DSCC_DISABLE_ICH; \
	type DSCC_DOUBLE_BUFFER_REG_UPDATE_PENDING; \
	type DSCC_RATE_BUFFER0_OVERFLOW_OCCURRED; \
	type DSCC_RATE_BUFFER1_OVERFLOW_OCCURRED; \
	type DSCC_RATE_BUFFER2_OVERFLOW_OCCURRED; \
	type DSCC_RATE_BUFFER3_OVERFLOW_OCCURRED; \
	type DSCC_RATE_BUFFER0_UNDERFLOW_OCCURRED; \
	type DSCC_RATE_BUFFER1_UNDERFLOW_OCCURRED; \
	type DSCC_RATE_BUFFER2_UNDERFLOW_OCCURRED; \
	type DSCC_RATE_BUFFER3_UNDERFLOW_OCCURRED; \
	type DSCC_RATE_CONTROL_BUFFER_MODEL0_OVERFLOW_OCCURRED; \
	type DSCC_RATE_CONTROL_BUFFER_MODEL1_OVERFLOW_OCCURRED; \
	type DSCC_RATE_CONTROL_BUFFER_MODEL2_OVERFLOW_OCCURRED; \
	type DSCC_RATE_CONTROL_BUFFER_MODEL3_OVERFLOW_OCCURRED; \
	type DSCC_RATE_BUFFER0_OVERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_BUFFER1_OVERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_BUFFER2_OVERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_BUFFER3_OVERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_BUFFER0_UNDERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_BUFFER1_UNDERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_BUFFER2_UNDERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_BUFFER3_UNDERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_CONTROL_BUFFER_MODEL0_OVERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_CONTROL_BUFFER_MODEL1_OVERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_CONTROL_BUFFER_MODEL2_OVERFLOW_OCCURRED_INT_EN; \
	type DSCC_RATE_CONTROL_BUFFER_MODEL3_OVERFLOW_OCCURRED_INT_EN; \
	type DSC_VERSION_MINOR; \
	type DSC_VERSION_MAJOR; \
	type PPS_IDENTIFIER; \
	type LINEBUF_DEPTH; \
	type DSCC_PPS_CONFIG0__BITS_PER_COMPONENT; \
	type BITS_PER_PIXEL; \
	type VBR_ENABLE; \
	type SIMPLE_422; \
	type CONVERT_RGB; \
	type BLOCK_PRED_ENABLE; \
	type NATIVE_422; \
	type NATIVE_420; \
	type CHUNK_SIZE; \
	type PIC_WIDTH; \
	type PIC_HEIGHT; \
	type SLICE_WIDTH; \
	type SLICE_HEIGHT; \
	type INITIAL_XMIT_DELAY; \
	type INITIAL_DEC_DELAY; \
	type INITIAL_SCALE_VALUE; \
	type SCALE_INCREMENT_INTERVAL; \
	type SCALE_DECREMENT_INTERVAL; \
	type FIRST_LINE_BPG_OFFSET; \
	type SECOND_LINE_BPG_OFFSET; \
	type NFL_BPG_OFFSET; \
	type SLICE_BPG_OFFSET; \
	type NSL_BPG_OFFSET; \
	type SECOND_LINE_OFFSET_ADJ; \
	type INITIAL_OFFSET; \
	type FINAL_OFFSET; \
	type FLATNESS_MIN_QP; \
	type FLATNESS_MAX_QP; \
	type RC_MODEL_SIZE; \
	type RC_EDGE_FACTOR; \
	type RC_QUANT_INCR_LIMIT0; \
	type RC_QUANT_INCR_LIMIT1; \
	type RC_TGT_OFFSET_LO; \
	type RC_TGT_OFFSET_HI; \
	type RC_BUF_THRESH0; \
	type RC_BUF_THRESH1; \
	type RC_BUF_THRESH2; \
	type RC_BUF_THRESH3; \
	type RC_BUF_THRESH4; \
	type RC_BUF_THRESH5; \
	type RC_BUF_THRESH6; \
	type RC_BUF_THRESH7; \
	type RC_BUF_THRESH8; \
	type RC_BUF_THRESH9; \
	type RC_BUF_THRESH10; \
	type RC_BUF_THRESH11; \
	type RC_BUF_THRESH12; \
	type RC_BUF_THRESH13; \
	type RANGE_MIN_QP0; \
	type RANGE_MAX_QP0; \
	type RANGE_BPG_OFFSET0; \
	type RANGE_MIN_QP1; \
	type RANGE_MAX_QP1; \
	type RANGE_BPG_OFFSET1; \
	type RANGE_MIN_QP2; \
	type RANGE_MAX_QP2; \
	type RANGE_BPG_OFFSET2; \
	type RANGE_MIN_QP3; \
	type RANGE_MAX_QP3; \
	type RANGE_BPG_OFFSET3; \
	type RANGE_MIN_QP4; \
	type RANGE_MAX_QP4; \
	type RANGE_BPG_OFFSET4; \
	type RANGE_MIN_QP5; \
	type RANGE_MAX_QP5; \
	type RANGE_BPG_OFFSET5; \
	type RANGE_MIN_QP6; \
	type RANGE_MAX_QP6; \
	type RANGE_BPG_OFFSET6; \
	type RANGE_MIN_QP7; \
	type RANGE_MAX_QP7; \
	type RANGE_BPG_OFFSET7; \
	type RANGE_MIN_QP8; \
	type RANGE_MAX_QP8; \
	type RANGE_BPG_OFFSET8; \
	type RANGE_MIN_QP9; \
	type RANGE_MAX_QP9; \
	type RANGE_BPG_OFFSET9; \
	type RANGE_MIN_QP10; \
	type RANGE_MAX_QP10; \
	type RANGE_BPG_OFFSET10; \
	type RANGE_MIN_QP11; \
	type RANGE_MAX_QP11; \
	type RANGE_BPG_OFFSET11; \
	type RANGE_MIN_QP12; \
	type RANGE_MAX_QP12; \
	type RANGE_BPG_OFFSET12; \
	type RANGE_MIN_QP13; \
	type RANGE_MAX_QP13; \
	type RANGE_BPG_OFFSET13; \
	type RANGE_MIN_QP14; \
	type RANGE_MAX_QP14; \
	type RANGE_BPG_OFFSET14; \
	type DSCC_DEFAULT_MEM_LOW_POWER_STATE; \
	type DSCC_MEM_PWR_FORCE; \
	type DSCC_MEM_PWR_DIS; \
	type DSCC_MEM_PWR_STATE; \
	type DSCC_NATIVE_422_MEM_PWR_FORCE; \
	type DSCC_NATIVE_422_MEM_PWR_DIS; \
	type DSCC_NATIVE_422_MEM_PWR_STATE; \
	type DSCC_R_Y_SQUARED_ERROR_LOWER; \
	type DSCC_R_Y_SQUARED_ERROR_UPPER; \
	type DSCC_G_CB_SQUARED_ERROR_LOWER; \
	type DSCC_G_CB_SQUARED_ERROR_UPPER; \
	type DSCC_B_CR_SQUARED_ERROR_LOWER; \
	type DSCC_B_CR_SQUARED_ERROR_UPPER; \
	type DSCC_R_Y_MAX_ABS_ERROR; \
	type DSCC_G_CB_MAX_ABS_ERROR; \
	type DSCC_B_CR_MAX_ABS_ERROR; \
	type DSCC_RATE_BUFFER0_MAX_FULLNESS_LEVEL; \
	type DSCC_RATE_BUFFER1_MAX_FULLNESS_LEVEL; \
	type DSCC_RATE_BUFFER2_MAX_FULLNESS_LEVEL; \
	type DSCC_RATE_BUFFER3_MAX_FULLNESS_LEVEL; \
	type DSCC_RATE_CONTROL_BUFFER0_MAX_FULLNESS_LEVEL; \
	type DSCC_RATE_CONTROL_BUFFER1_MAX_FULLNESS_LEVEL; \
	type DSCC_RATE_CONTROL_BUFFER2_MAX_FULLNESS_LEVEL; \
	type DSCC_RATE_CONTROL_BUFFER3_MAX_FULLNESS_LEVEL; \
	type DSCC_UPDATE_PENDING_STATUS; \
	type DSCC_UPDATE_TAKEN_STATUS; \
	type DSCC_UPDATE_TAKEN_ACK; \
	type DSCC_TEST_DEBUG_BUS0_ROTATE; \
	type DSCC_TEST_DEBUG_BUS1_ROTATE; \
	type DSCC_TEST_DEBUG_BUS2_ROTATE; \
	type DSCC_TEST_DEBUG_BUS3_ROTATE; \
	type DSCC_RATE_BUFFER0_FULLNESS_LEVEL; \
	type DSCC_RATE_BUFFER1_FULLNESS_LEVEL; \
	type DSCC_RATE_BUFFER2_FULLNESS_LEVEL; \
	type DSCC_RATE_BUFFER3_FULLNESS_LEVEL; \
	type DSCC_RATE_CONTROL_BUFFER0_FULLNESS_LEVEL; \
	type DSCC_RATE_CONTROL_BUFFER1_FULLNESS_LEVEL; \
	type DSCC_RATE_CONTROL_BUFFER2_FULLNESS_LEVEL; \
	type DSCC_RATE_CONTROL_BUFFER3_FULLNESS_LEVEL; \
	type DSCC_RATE_BUFFER0_INITIAL_XMIT_DELAY_REACHED; \
	type DSCC_RATE_BUFFER1_INITIAL_XMIT_DELAY_REACHED; \
	type DSCC_RATE_BUFFER2_INITIAL_XMIT_DELAY_REACHED; \
	type DSCC_RATE_BUFFER3_INITIAL_XMIT_DELAY_REACHED; \
	type INPUT_INTERFACE_UNDERFLOW_RECOVERY_EN; \
	type INPUT_INTERFACE_UNDERFLOW_OCCURRED_INT_EN; \
	type INPUT_INTERFACE_UNDERFLOW_OCCURRED_STATUS; \
	type INPUT_PIXEL_FORMAT; \
	type DSCCIF_CONFIG0__BITS_PER_COMPONENT; \
	type DOUBLE_BUFFER_REG_UPDATE_PENDING; \
	type DSCCIF_UPDATE_PENDING_STATUS; \
	type DSCCIF_UPDATE_TAKEN_STATUS; \
	type DSCCIF_UPDATE_TAKEN_ACK; \
	type DSCRM_DSC_FORWARD_EN; \
	type DSCRM_DSC_OPP_PIPE_SOURCE


struct dcn20_dsc_registers {
	uint32_t DSC_TOP_CONTROL;
	uint32_t DSC_DEBUG_CONTROL;
	uint32_t DSCC_CONFIG0;
	uint32_t DSCC_CONFIG1;
	uint32_t DSCC_STATUS;
	uint32_t DSCC_INTERRUPT_CONTROL_STATUS;
	uint32_t DSCC_PPS_CONFIG0;
	uint32_t DSCC_PPS_CONFIG1;
	uint32_t DSCC_PPS_CONFIG2;
	uint32_t DSCC_PPS_CONFIG3;
	uint32_t DSCC_PPS_CONFIG4;
	uint32_t DSCC_PPS_CONFIG5;
	uint32_t DSCC_PPS_CONFIG6;
	uint32_t DSCC_PPS_CONFIG7;
	uint32_t DSCC_PPS_CONFIG8;
	uint32_t DSCC_PPS_CONFIG9;
	uint32_t DSCC_PPS_CONFIG10;
	uint32_t DSCC_PPS_CONFIG11;
	uint32_t DSCC_PPS_CONFIG12;
	uint32_t DSCC_PPS_CONFIG13;
	uint32_t DSCC_PPS_CONFIG14;
	uint32_t DSCC_PPS_CONFIG15;
	uint32_t DSCC_PPS_CONFIG16;
	uint32_t DSCC_PPS_CONFIG17;
	uint32_t DSCC_PPS_CONFIG18;
	uint32_t DSCC_PPS_CONFIG19;
	uint32_t DSCC_PPS_CONFIG20;
	uint32_t DSCC_PPS_CONFIG21;
	uint32_t DSCC_PPS_CONFIG22;
	uint32_t DSCC_MEM_POWER_CONTROL;
	uint32_t DSCC_R_Y_SQUARED_ERROR_LOWER;
	uint32_t DSCC_R_Y_SQUARED_ERROR_UPPER;
	uint32_t DSCC_G_CB_SQUARED_ERROR_LOWER;
	uint32_t DSCC_G_CB_SQUARED_ERROR_UPPER;
	uint32_t DSCC_B_CR_SQUARED_ERROR_LOWER;
	uint32_t DSCC_B_CR_SQUARED_ERROR_UPPER;
	uint32_t DSCC_MAX_ABS_ERROR0;
	uint32_t DSCC_MAX_ABS_ERROR1;
	uint32_t DSCC_RATE_BUFFER0_MAX_FULLNESS_LEVEL;
	uint32_t DSCC_RATE_BUFFER1_MAX_FULLNESS_LEVEL;
	uint32_t DSCC_RATE_BUFFER2_MAX_FULLNESS_LEVEL;
	uint32_t DSCC_RATE_BUFFER3_MAX_FULLNESS_LEVEL;
	uint32_t DSCC_RATE_CONTROL_BUFFER0_MAX_FULLNESS_LEVEL;
	uint32_t DSCC_RATE_CONTROL_BUFFER1_MAX_FULLNESS_LEVEL;
	uint32_t DSCC_RATE_CONTROL_BUFFER2_MAX_FULLNESS_LEVEL;
	uint32_t DSCC_RATE_CONTROL_BUFFER3_MAX_FULLNESS_LEVEL;
	uint32_t DSCC_TEST_DEBUG_BUS_ROTATE;
	uint32_t DSCCIF_CONFIG0;
	uint32_t DSCCIF_CONFIG1;
	uint32_t DSCRM_DSC_FORWARD_CONFIG;
};


struct dcn20_dsc_shift {
	DSC_FIELD_LIST_DCN20(uint8_t);
};

struct dcn20_dsc_mask {
	DSC_FIELD_LIST_DCN20(uint32_t);
};

/* DSCCIF_CONFIG.INPUT_PIXEL_FORMAT values */
enum dsc_pixel_format {
	DSC_PIXFMT_RGB,
	DSC_PIXFMT_YCBCR444,
	DSC_PIXFMT_SIMPLE_YCBCR422,
	DSC_PIXFMT_NATIVE_YCBCR422,
	DSC_PIXFMT_NATIVE_YCBCR420,
	DSC_PIXFMT_UNKNOWN
};

struct dsc_reg_values {
	/* PPS registers */
	struct drm_dsc_config pps;

	/* Additional registers */
	uint32_t dsc_clock_enable;
	uint32_t dsc_clock_gating_disable;
	uint32_t underflow_recovery_en;
	uint32_t underflow_occurred_int_en;
	uint32_t underflow_occurred_status;
	enum dsc_pixel_format pixel_format;
	uint32_t ich_reset_at_eol;
	uint32_t alternate_ich_encoding_en;
	uint32_t num_slices_h;
	uint32_t num_slices_v;
	uint32_t rc_buffer_model_size;
	uint32_t disable_ich;
	uint32_t bpp_x32;
	uint32_t dsc_dbg_en;
	uint32_t rc_buffer_model_overflow_int_en[4];
};

struct dcn20_dsc {
	struct display_stream_compressor base;
	const struct dcn20_dsc_registers *dsc_regs;
	const struct dcn20_dsc_shift *dsc_shift;
	const struct dcn20_dsc_mask *dsc_mask;

	struct dsc_reg_values reg_vals;

	int max_image_width;
};


void dsc2_construct(struct dcn20_dsc *dsc,
		struct dc_context *ctx,
		int inst,
		const struct dcn20_dsc_registers *dsc_regs,
		const struct dcn20_dsc_shift *dsc_shift,
		const struct dcn20_dsc_mask *dsc_mask);

#endif

#endif
