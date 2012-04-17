/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (genshell.h)
 *  
 *  It has been AutoGen-ed  April  7, 2012 at 12:39:38 PM by AutoGen 5.16pre15
 *  From the definitions    genshell.def
 *  and the template file   options
 *
 * Generated from AutoOpts 36:4:11 templates.
 *
 *  AutoOpts is a copyrighted work.  This header file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the genshellopt author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The genshellopt program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 1999-2012 Bruce Korb, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the
 *  GNU General Public License, version 3 or later
 *      <http://gnu.org/licenses/gpl.html>
 *
 *  genshellopt is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  genshellopt is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
 *  This file contains the programmatic interface to the Automated
 *  Options generated for the genshellopt program.
 *  These macros are documented in the AutoGen info file in the
 *  "AutoOpts" chapter.  Please refer to that doc for usage help.
 */
#ifndef AUTOOPTS_GENSHELL_H_GUARD
#define AUTOOPTS_GENSHELL_H_GUARD 1
#include <autoopts/options.h>

/*
 *  Ensure that the library used for compiling this generated header is at
 *  least as new as the version current when the header template was released
 *  (not counting patch version increments).  Also ensure that the oldest
 *  tolerable version is at least as old as what was current when the header
 *  template was released.
 */
#define AO_TEMPLATE_VERSION 147460
#if (AO_TEMPLATE_VERSION < OPTIONS_MINIMUM_VERSION) \
 || (AO_TEMPLATE_VERSION > OPTIONS_STRUCT_VERSION)
# error option template version mismatches autoopts/options.h header
  Choke Me.
#endif

/*
 *  Enumeration of each option:
 */
typedef enum {
    INDEX_GENSHELL_OPT_SCRIPT      =  0,
    INDEX_GENSHELL_OPT_SHELL       =  1,
    INDEX_GENSHELL_OPT_VERSION     =  2,
    INDEX_GENSHELL_OPT_HELP        =  3,
    INDEX_GENSHELL_OPT_MORE_HELP   =  4
} teGenshell_OptIndex;

#define GENSHELL_OPTION_CT    5
#define GENSHELLOPT_VERSION       "1"
#define GENSHELLOPT_FULL_VERSION  "genshellopt 1"

/*
 *  Interface defines for all options.  Replace "n" with the UPPER_CASED
 *  option name (as in the teGenshell_OptIndex enumeration above).
 *  e.g. HAVE_GENSHELL_OPT(SCRIPT)
 */
#define GENSHELL_DESC(n) (genshelloptOptions.pOptDesc[INDEX_GENSHELL_OPT_## n])
#define     HAVE_GENSHELL_OPT(n) (! UNUSED_OPT(& GENSHELL_DESC(n)))
#define      GENSHELL_OPT_ARG(n) (GENSHELL_DESC(n).optArg.argString)
#define    STATE_GENSHELL_OPT(n) (GENSHELL_DESC(n).fOptState & OPTST_SET_MASK)
#define    COUNT_GENSHELL_OPT(n) (GENSHELL_DESC(n).optOccCt)
#define    ISSEL_GENSHELL_OPT(n) (SELECTED_OPT(&GENSHELL_DESC(n)))
#define ISUNUSED_GENSHELL_OPT(n) (UNUSED_OPT(& GENSHELL_DESC(n)))
#define  ENABLED_GENSHELL_OPT(n) (! DISABLED_OPT(& GENSHELL_DESC(n)))
#define  STACKCT_GENSHELL_OPT(n) (((tArgList*)(GENSHELL_DESC(n).optCookie))->useCt)
#define STACKLST_GENSHELL_OPT(n) (((tArgList*)(GENSHELL_DESC(n).optCookie))->apzArgs)
#define    CLEAR_GENSHELL_OPT(n) STMTS( \
                GENSHELL_DESC(n).fOptState &= OPTST_PERSISTENT_MASK;   \
                if ((GENSHELL_DESC(n).fOptState & OPTST_INITENABLED) == 0) \
                    GENSHELL_DESC(n).fOptState |= OPTST_DISABLED; \
                GENSHELL_DESC(n).optCookie = NULL )

/* * * * * *
 *
 *  Enumeration of genshellopt exit codes
 */
typedef enum {
    GENSHELLOPT_EXIT_SUCCESS = 0,
    GENSHELLOPT_EXIT_FAILURE = 1,
    GENSHELLOPT_EXIT_LIBOPTS_FAILURE = 70
} genshellopt_exit_code_t;
/* * * * * *
 *
 *  Interface defines for specific options.
 */
#define VALUE_GENSHELL_OPT_SCRIPT 'o'
#define VALUE_GENSHELL_OPT_SHELL 's'
#define VALUE_GENSHELL_OPT_HELP '?'
#define VALUE_GENSHELL_OPT_MORE_HELP '!'
#define VALUE_GENSHELL_OPT_VERSION 'v'
/*
 *  Interface defines not associated with particular options
 */
#define ERRSKIP_GENSHELL_OPTERR  STMTS(genshelloptOptions.fOptSet &= ~OPTPROC_ERRSTOP)
#define ERRSTOP_GENSHELL_OPTERR  STMTS(genshelloptOptions.fOptSet |= OPTPROC_ERRSTOP)
#define RESTART_GENSHELL_OPT(n)  STMTS( \
                genshelloptOptions.curOptIdx = (n); \
                genshelloptOptions.pzCurOpt  = NULL )
#define START_GENSHELL_OPT       RESTART_GENSHELL_OPT(1)
#define GENSHELL_USAGE(c)        (*genshelloptOptions.pUsageProc)(&genshelloptOptions, c)
/* extracted from opthead.tlib near line 484 */

#ifdef  __cplusplus
extern "C" {
#endif


/* * * * * *
 *
 *  Declare the genshellopt option descriptor.
 */
extern tOptions genshelloptOptions;

#if defined(ENABLE_NLS)
# ifndef _
#   include <stdio.h>
static inline char* aoGetsText(char const* pz) {
    if (pz == NULL) return NULL;
    return (char*)gettext(pz);
}
#   define _(s)  aoGetsText(s)
# endif /* _() */

# define OPT_NO_XLAT_CFG_NAMES  STMTS(genshelloptOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT_CFG;)
# define OPT_NO_XLAT_OPT_NAMES  STMTS(genshelloptOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG;)

# define OPT_XLAT_CFG_NAMES     STMTS(genshelloptOptions.fOptSet &= \
                                  ~(OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG);)
# define OPT_XLAT_OPT_NAMES     STMTS(genshelloptOptions.fOptSet &= \
                                  ~OPTPROC_NXLAT_OPT;)

#else   /* ENABLE_NLS */
# define OPT_NO_XLAT_CFG_NAMES
# define OPT_NO_XLAT_OPT_NAMES

# define OPT_XLAT_CFG_NAMES
# define OPT_XLAT_OPT_NAMES

# ifndef _
#   define _(_s)  _s
# endif
#endif  /* ENABLE_NLS */

#ifdef  __cplusplus
}
#endif
#endif /* AUTOOPTS_GENSHELL_H_GUARD */
/* genshell.h ends here */
