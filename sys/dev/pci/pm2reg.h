/*	$NetBSD: pm2reg.h,v 1.9 2014/12/14 13:58:41 macallan Exp $	*/

/*
 * Copyright (c) 2009 Michael Lorenz
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * register definitions for Permedia 2 graphics controllers
 */
 

#ifndef PM2_REG_H
#define PM2_REG_H

#define PM2_RESET	0x00000000	/* any write initiates a chip reset */
#define		PM2_RESET_BUSY	0x80000000	/* reset in progress */

#define PM2_INPUT_FIFO_SPACE	0x00000018
#define PM2_OUTPUT_FIFO_WORDS	0x00000020

#define PM2_VCLKCTL		0x00000040
#define		VCC_CLOCK_A		0x00000000
#define		VCC_CLOCK_B		0x00000001
#define		VCC_CLOCK_C		0x00000002
/* PCI clocks to wait between RAMDAC accesses */ 
#define		VCC_RAMDAC_WAIT_MASK	0x000003fc

#define PM2_APERTURE1_CONTROL	0x00000050
#define PM2_APERTURE2_CONTROL	0x00000058
#define		PM2_AP_BYTESWAP		0x00000001
#define		PM2_AP_HALFWORDSWAP	0x00000002
#define		PM2_AP_PACKED16_EN	0x00000008
#define		PM2_AP_PACKED16_READ_B	0x00000010 /* Buffer A otherwise */
#define		PM2_AP_PACKED16_WRITE_B	0x00000020 /* A otherwise */
#define		PM2_AP_PACKED16_WRT_DBL	0x00000040
#define		PM2_AP_PACKED16_R31	0x00000080 /* read buffer selected by
						    * visibility bit in memory 
						    */
#define		PM2_AP_SVGA		0x00000100
#define		PM2_AP_ROM		0x00000200

#define PM2_BYPASS_MASK		0x00001100
#define PM2_FB_WRITE_MASK	0x00001140

#define PM2_OUTPUT_FIFO		0x00002000

#define PM2_SCREEN_BASE		0x00003000 /* in 64bit units */
#define PM2_SCREEN_STRIDE	0x00003008 /* in 64bit units */
#define PM2_HTOTAL		0x00003010
#define PM2_HGATE_END		0x00003018
#define PM2_HBLANK_END		0x00003020
#define PM2_HSYNC_START		0x00003028
#define PM2_HSYNC_END		0x00003030
#define PM2_VTOTAL		0x00003038
#define PM2_VBLANK_END		0x00003040
#define PM2_VSYNC_START		0x00003048
#define PM2_VSYNC_END		0x00003050
#define PM2_VIDEO_CONTROL	0x00003058
#define 	PM2_VC_VIDEO_ENABLE	0x00000001
#define 	PM2_VC_BLANK_ACR_LOW	0x00000002
#define 	PM2_VC_LINE_DOUBLE	0x00000004
#define 	PM2_VC_HSYNC_FORCE_H	0x00000000
#define 	PM2_VC_HSYNC_ACT_HIGH	0x00000008
#define 	PM2_VC_HSYNC_FORCE_L	0x00000010
#define 	PM2_VC_HSYNC_ACT_LOW	0x00000018
#define 	PM2_VC_VSYNC_FORCE_H	0x00000000
#define 	PM2_VC_VSYNC_ACT_HIGH	0x00000020
#define 	PM2_VC_VSYNC_FORCE_L	0x00000040
#define 	PM2_VC_VSYNC_ACT_LOW	0x00000060
#define 	PM2_VC_BP_BASE_PENDING	0x00000080
#define 	PM2_VC_RE_BASE_PENDING	0x00000100
#define 	PM2_VC_SWAP_SYNC_BLANK	0x00000000
#define 	PM2_VC_SWAP_FREERUNNING	0x00000200
#define 	PM2_VC_SWAP_LIMIT_FR	0x00000400
#define 	PM2_VC_STEREO_ENABLE	0x00000800
#define 	PM2_VC_RIGHT_EYE_ACT_L	0x00001000
#define 	PM2_VC_DISP_RIGHT_FRAME	0x00002000	/* RO, left otherwise */
#define 	PM2_VC_BP_RIGHT_PENDING	0x00004000
#define 	PM2_VC_RE_RIGHT_PENDING	0x00008000
#define 	PM2_VC_RAMDAC_64BIT	0x00010000	/* 32bit otherwise */

#define PM2_DISPLAY_DATA	0x00003068
#define		PM2_DD_SDA_IN		0x00000001
#define		PM2_DD_SCL_IN		0x00000002
#define		PM2_DD_SDA_OUT		0x00000004
#define		PM2_DD_SCL_OUT		0x00000008
#define		PM2_DD_LATCHED_DATA	0x00000010
#define		PM2_DD_DATA_VALID	0x00000020	/* clear by 1 */
#define		PM2_DD_START		0x00000040	/* START detected */
#define		PM2_DD_STOP		0x00000080	/* STOP detected */
#define		PM2_DD_INSERT_WAITS	0x00000100
#define		PM2_DD_USE_MONID	0x00000200	/* DDC2 otherwise */
#define		PM2_DD_MONID_IN_MASK	0x00001c00
#define		PM2_DD_MONID_OUT_MASK	0x0000e000

/* RAMDAC */
#define PM2_DAC_PAL_WRITE_IDX	0x00004000
#define PM2_DAC_DATA		0x00004008
#define PM2_DAC_MASK		0x00004010
#define PM2_DAC_PAL_READ_IDX	0x00004018
/* these are different on PM2V: */
#define PM2_DAC_CURSOR_PAL	0x00004020
#define PM2_DAC_CURSOR_DATA	0x00004028
/* here we go: */
#define PM2V_DAC_INDEX_LOW	0x00004020
#define PM2V_DAC_INDEX_HIGH	0x00004028
#define PM2V_DAC_INDEX_DATA	0x00004030
#define PM2V_DAC_INDEX_CONTROL	0x00004038

#define PM2_DAC_INDEX_DATA	0x00004050
#define PM2_DAC_CURSOR_RAM	0x00004058
#define PM2_DAC_CURSOR_X_LOW	0x00004060
#define PM2_DAC_CURSOR_X_HIGH	0x00004068
#define PM2_DAC_CURSOR_Y_LOW	0x00004070
#define PM2_DAC_CURSOR_Y_HIGH	0x00004078

/* RAMDAC registers ( through INDEX_DATA */
#define	PM2_DAC_COLOR_MODE	0x18
#define		CM_PALETTE	0x00
#define		CM_RGB332	0x01
#define		CM_RGB232OFFSET	0x02
#define		CM_RGBA2321	0x03
#define		CM_RGBA5551	0x04
#define		CM_RGBA4444	0x05
#define		CM_RGB565	0x06
#define		CM_RGBA8888	0x08
#define		CM_RGB888	0x09
#define		CM_GUI_ENABLE	0x10
#define		CM_RGB		0x20	/* BGR otherwise */
#define		CM_TRUECOLOR	0x80	/* use palette for gamma correction */

#define PM2_DAC_MISC_CONTROL	0x1e
#define		MC_POWERDOWN	0x01
#define		MC_PALETTE_8BIT	0x02	/* 6bit otherwise */
#define		MC_HSYNC_INV	0x04
#define		MC_VSYNC_INV	0x08
#define		MC_SYNCONGREEN	0x10
#define PM2_DAC_PIXELCLKA_M	0x20
#define PM2_DAC_PIXELCLKA_N	0x21
#define PM2_DAC_PIXELCLKA_P	0x22
#define 	PCLK_ENABLE	0x08
#define PM2_DAC_PIXELCLKB_M	0x23
#define PM2_DAC_PIXELCLKB_N	0x24
#define PM2_DAC_PIXELCLKB_P	0x25
#define PM2_DAC_PIXELCLKC_M	0x26
#define PM2_DAC_PIXELCLKC_N	0x27
#define PM2_DAC_PIXELCLKC_P	0x28
#define PM2_DAC_PIXELCLK_STATUS	0x29
#define		PCLK_LOCKED	0x10
#define PM2_DAC_MEMCLK_M	0x30
#define PM2_DAC_MEMCLK_N	0x31
#define PM2_DAC_MEMCLK_P	0x32
#define PM2_DAC_MEMCLK_STATUS	0x33

/* PM2V RAMDAC */
#define PM2V_DAC_MISC_CONTROL		0x000
#define		PM2V_DAC_8BIT		0x01	/* 6bit otherwise */
#define		PM2V_DAC_BYPASS_CLUT	0x08	/* ??? guess from xorg */
#define		PM2V_DAC_8_24_OVERLAY	0x10	/* ??? guess from xorg */
#define PM2V_DAC_SYNC_CONTROL		0x001
#define		PM2V_DAC_HSYNC_INV	0x01
#define		PM2V_DAC_VSYNC_INV	0x08
#define PM2V_DAC_CONTROL		0x002
#define PM2V_DAC_PIXEL_SIZE		0x003
#define		PM2V_PS_8BIT		0x00
#define		PM2V_PS_16BIT		0x01
#define		PM2V_PS_32BIT		0x02
#define		PM2V_PS_24BIT		0x04
#define PM2V_DAC_COLOR_FORMAT		0x004
#define		PM2V_DAC_PALETTE	0x2e
#define		PM2V_DAC_RGB555		0x61
#define		PM2V_DAC_RGB565		0x70
#define		PM2V_DAC_RGB888		0x60
#define		PM2V_DAC_RGBA8888	0x20

#define PM2V_DAC_CHECK_CONTROL		0x018
#define PM2V_DAC_CLOCK_CONTROL		0x200
#define PM2V_DAC_CLOCK_A_M		0x201
#define PM2V_DAC_CLOCK_A_N		0x202
#define PM2V_DAC_CLOCK_A_P		0x203
#define PM2V_DAC_CLOCK_B_M		0x204
#define PM2V_DAC_CLOCK_B_N		0x205
#define PM2V_DAC_CLOCK_B_P		0x206
#define PM2V_DAC_MCLK_CONTROL		0x20D
#define PM2V_DAC_MCLK_M			0x20E
#define PM2V_DAC_MCLK_N			0x20F
#define PM2V_DAC_MCLK_P			0x210

/* drawing engine */
#define PM2_RE_STARTXDOM	0x00008000
#define	PM2_RE_DXDOM		0x00008008
#define PM2_RE_STARTXSUB	0x00008010
#define PM2_RE_STARTY		0x00008020
#define PM2_RE_DY		0x00008028
#define PM2_RE_COUNT		0x00008030
#define PM2_RE_BITMASK		0x00008068 /* for colour expansion */
#define PM2_RE_COLOUR		0x000087f0
#define PM2_RE_CONFIG		0x00008d90
#define		PM2RECFG_READ_SRC	0x00000001
#define		PM2RECFG_READ_DST	0x00000002
#define		PM2RECFG_PACKED		0x00000004
#define		PM2RECFG_WRITE_EN	0x00000008
#define		PM2RECFG_DDA_EN		0x00000010
#define		PM2RECFG_ROP_EN		0x00000020
#define		PM2RECFG_ROP_MASK	0x000003c0
#define		PM2RECFG_ROP_SHIFT	6

#define PM2_RE_CONST_COLOUR	0x000087e8
#define PM2_RE_BUFFER_OFFSET	0x00008a90 /* distance between src and dst */
#define PM2_RE_SOURCE_BASE	0x00008d80 /* write after windowbase */
#define PM2_RE_SOURCE_DELTA	0x00008d88 /* offset in coordinates */
#define PM2_RE_SOURCE_OFFSET	0x00008a88 /* same in pixels */
#define PM2_RE_WINDOW_BASE	0x00008ab0
#define PM2_RE_WINDOW_ORIGIN	0x000081c8
#define PM2_RE_WRITE_MODE	0x00008ab8
#define		PM2WM_WRITE_EN		0x00000001
#define		PM2WM_TO_HOST		0x00000008
#define PM2_RE_PIXEL_SIZE	0x00008ad0
#define		PM2PS_8BIT		0x00000000
#define		PM2PS_16BIT		0x00000001
#define		PM2PS_32BIT		0x00000002
#define		PM2PS_24BIT		0x00000004

#define PM2_RE_MODE		0x000080a0
#define		PM2RM_MASK_MIRROR	0x00000001 /* mask is right-to-left */
#define		PM2RM_MASK_INVERT	0x00000002
#define		PM2RM_MASK_OPAQUE	0x00000040 /* BG in TEXEL0 */
#define		PM2RM_MASK_SWAP		0x00000180
#define		PM2RM_MASK_PAD		0x00000200 /* new line new mask */
#define		PM2RM_MASK_OFFSET	0x00007c00
#define		PM2RM_HOST_SWAP		0x00018000
#define		PM2RM_LIMITS_EN		0x00040000
#define		PM2RM_MASK_REL_X	0x00080000

#define PM2_RE_RECT_START	0x000080d0
#define PM2_RE_RECT_SIZE	0x000080d8
#define PM2_RE_RENDER		0x00008038 /* write starts command */
#define		PM2RE_STIPPLE		0x00000001
#define		PM2RE_FASTFILL		0x00000008
#define		PM2RE_LINE		0x00000000
#define		PM2RE_TRAPEZOID		0x00000040
#define		PM2RE_POINT		0x00000080
#define		PM2RE_RECTANGLE		0x000000c0
#define		PM2RE_SYNC_ON_MASK	0x00000800 /* wait for write to bitmask
						      register */
#define		PM2RE_SYNC_ON_HOST	0x00001000 /* wait for host data */
#define		PM2RE_TEXTURE_EN	0x00002000
#define		PM2RE_INC_X		0x00200000 /* drawing direction */
#define		PM2RE_INC_Y		0x00400000
#define	PM2_RE_TEXEL0		0x00008600 /* background colour */
#define PM2_RE_STATUS		0x00000068
#define		PM2ST_BUSY	0x80000000
#define PM2_RE_SYNC		0x00008c40
#define PM2_RE_FILTER_MODE	0x00008c00
#define		PM2FLT_PASS_SYNC	0x00000400
#define PM2_RE_DDA_MODE		0x000087e0
#define		PM2DDA_ENABLE		0x00000001
#define		PM2DDA_GOURAUD		0x00000002 /* flat otherwise */
#define PM2_RE_BLOCK_COLOUR	0x00008ac8
#define PM2_RE_STIPPLE_MODE	0x000081a0
#define 	PM2ST_ENABLE		0x00000001
#define 	PM2ST_XOFFSET_MASK	0x00000380
#define 	PM2ST_YOFFSET_MASK	0x00007000
#define 	PM2ST_INVERT		0x00020000
#define 	PM2ST_MIRROR_X		0x00040000
#define 	PM2ST_MIRROR_Y		0x00080000
#define 	PM2ST_OPAQUE		0x00100000
#define PM2_HW_WRITEMASK	0x00008ac0
#define PM2_SW_WRITEMASK	0x00008820
#define PM2_FB_READMODE		0x00008a80
#define		PM2FB_PP0_MASK	0x00000007
#define		PM2FB_PP1_MASK	0x00000038
#define		PM2FB_PP2_MASK	0x000001c0
#define		PM2FB_READ_SRC	0x00000200
#define		PM2FB_READ_DST	0x00000400
#define		PM2FB_FBCOLOR	0x00008000 /* for uploads */
#define		PM2FB_ORIGIN_BL	0x00010000 /* window origin, TL otherwise */
#define		PM2FB_PATCH_EN	0x00020000
#define		PM2FB_PACKED	0x00040000
#define		PM2FB_OFFSET_M	0x00380000
#define		PM2FB_PM_PATCH	0x00000000
#define		PM2FB_PM_SUB	0x02000000
#define		PM2FB_PM_SUBP	0x04000000

#define PM2_RE_SCISSOR_MODE	0x00008180
#define		PM2SC_USER_EN		0x00000001 /* from scissor reg */
#define		PM2SC_SCREEN_EN		0x00000002 /* screensize reg */
#define PM2_RE_SCREENSIZE	0x00008198
#define PM2_RE_SCISSOR_MINYX	0x00008188
#define PM2_RE_SCISSOR_MAXYX	0x00008190
#define PM2_RE_TEXMAP_FORMAT	0x00008588
#define PM2_RE_DITHER_MODE	0x00008818
#define PM2_RE_ALPHA_MODE	0x00008810
#define PM2_RE_TEX_COLOUR_MODE	0x00008680
#define PM2_RE_TEX_READ_MODE	0x00008670
#define PM2_RE_TEX_LUT_MODE	0x00008678
#define PM2_RE_TEX_ADDRESS_MODE	0x00008380
#define PM2_RE_YUV_MODE		0x00008f00
#define PM2_RE_DEPTH_MODE	0x000089a0
#define PM2_RE_DEPTH		0x000089a8
#define PM2_RE_STENCIL_MODE	0x00008988
#define PM2_RE_ROP_MODE		0x00008828
#define PM2_RE_PACKEDDATA_LIMIT	0x00008150
#define PM2_RE_DATA		0x00008aa0	/* pixel data */
#define PM2_RE_SOURCEDATA	0x00008aa8	/* raw data */


#endif /* PM2_REG_H */
