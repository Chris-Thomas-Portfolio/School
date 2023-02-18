#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=lab2.c fourierf.c fftmisc.c pic32_init_cache.S

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/lab2.o ${OBJECTDIR}/fourierf.o ${OBJECTDIR}/fftmisc.o ${OBJECTDIR}/pic32_init_cache.o
POSSIBLE_DEPFILES=${OBJECTDIR}/lab2.o.d ${OBJECTDIR}/fourierf.o.d ${OBJECTDIR}/fftmisc.o.d ${OBJECTDIR}/pic32_init_cache.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/lab2.o ${OBJECTDIR}/fourierf.o ${OBJECTDIR}/fftmisc.o ${OBJECTDIR}/pic32_init_cache.o

# Source Files
SOURCEFILES=lab2.c fourierf.c fftmisc.c pic32_init_cache.S



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048ECG144
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/pic32_init_cache.o: pic32_init_cache.S  .generated_files/flags/default/6030a15c0553a93c313d001d5cb9e4af3524a6a6 .generated_files/flags/default/c8f49664b0402dfc7fb4da4c6ec79c30a0012f45
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pic32_init_cache.o.d 
	@${RM} ${OBJECTDIR}/pic32_init_cache.o 
	@${RM} ${OBJECTDIR}/pic32_init_cache.o.ok ${OBJECTDIR}/pic32_init_cache.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pic32_init_cache.o.d"  -o ${OBJECTDIR}/pic32_init_cache.o pic32_init_cache.S  -DXPRJ_default=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/pic32_init_cache.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1 -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/pic32_init_cache.o.d" "${OBJECTDIR}/pic32_init_cache.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/pic32_init_cache.o: pic32_init_cache.S  .generated_files/flags/default/19c4098d5b7cb7a6fda718399f6151496d3e6aed .generated_files/flags/default/c8f49664b0402dfc7fb4da4c6ec79c30a0012f45
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pic32_init_cache.o.d 
	@${RM} ${OBJECTDIR}/pic32_init_cache.o 
	@${RM} ${OBJECTDIR}/pic32_init_cache.o.ok ${OBJECTDIR}/pic32_init_cache.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pic32_init_cache.o.d"  -o ${OBJECTDIR}/pic32_init_cache.o pic32_init_cache.S  -DXPRJ_default=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/pic32_init_cache.o.asm.d",--gdwarf-2 -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/pic32_init_cache.o.d" "${OBJECTDIR}/pic32_init_cache.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/lab2.o: lab2.c  .generated_files/flags/default/899727beaf464f0b262a249cb00773458673c157 .generated_files/flags/default/c8f49664b0402dfc7fb4da4c6ec79c30a0012f45
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lab2.o.d 
	@${RM} ${OBJECTDIR}/lab2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O1 -fno-common -MP -MMD -MF "${OBJECTDIR}/lab2.o.d" -o ${OBJECTDIR}/lab2.o lab2.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/fourierf.o: fourierf.c  .generated_files/flags/default/8ac4c09463243b8d55f097c33800d149377f2beb .generated_files/flags/default/c8f49664b0402dfc7fb4da4c6ec79c30a0012f45
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/fourierf.o.d 
	@${RM} ${OBJECTDIR}/fourierf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O1 -fno-common -MP -MMD -MF "${OBJECTDIR}/fourierf.o.d" -o ${OBJECTDIR}/fourierf.o fourierf.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/fftmisc.o: fftmisc.c  .generated_files/flags/default/38c0772fe96d319aaa33e6dbeec7d16c73e664 .generated_files/flags/default/c8f49664b0402dfc7fb4da4c6ec79c30a0012f45
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/fftmisc.o.d 
	@${RM} ${OBJECTDIR}/fftmisc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O1 -fno-common -MP -MMD -MF "${OBJECTDIR}/fftmisc.o.d" -o ${OBJECTDIR}/fftmisc.o fftmisc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/lab2.o: lab2.c  .generated_files/flags/default/c4ad7c9f17e0c672e47cc6dd674abd265d7b465c .generated_files/flags/default/c8f49664b0402dfc7fb4da4c6ec79c30a0012f45
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lab2.o.d 
	@${RM} ${OBJECTDIR}/lab2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O1 -fno-common -MP -MMD -MF "${OBJECTDIR}/lab2.o.d" -o ${OBJECTDIR}/lab2.o lab2.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/fourierf.o: fourierf.c  .generated_files/flags/default/c4f17cd411da1511758b21f19f31d07dc796c11d .generated_files/flags/default/c8f49664b0402dfc7fb4da4c6ec79c30a0012f45
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/fourierf.o.d 
	@${RM} ${OBJECTDIR}/fourierf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O1 -fno-common -MP -MMD -MF "${OBJECTDIR}/fourierf.o.d" -o ${OBJECTDIR}/fourierf.o fourierf.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/fftmisc.o: fftmisc.c  .generated_files/flags/default/39186f311d49563b22a3550e5e39a617d9e7c21a .generated_files/flags/default/c8f49664b0402dfc7fb4da4c6ec79c30a0012f45
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/fftmisc.o.d 
	@${RM} ${OBJECTDIR}/fftmisc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O1 -fno-common -MP -MMD -MF "${OBJECTDIR}/fftmisc.o.d" -o ${OBJECTDIR}/fftmisc.o fftmisc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_REAL_ICE=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x27F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,--defsym=_min_heap_size=512,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
