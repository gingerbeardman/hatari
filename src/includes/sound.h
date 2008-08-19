/*
  Hatari - sound.h

  This file is distributed under the GNU Public License, version 2 or at
  your option any later version. Read the file gpl.txt for details.
  
  Matthias Arndt 2008-08-15
    - cleanup to have definitions and declarations for both sound cores in one place
*/

#ifndef HATARI_SOUND_H
#define HATARI_SOUND_H

#undef OLD_SOUND  /* default is to use STSound core - define to revert to old Hatari sound renderer */

/* definitions common for all sound rendering engines */

#define MIXBUFFER_SIZE    8192          /* Size of circular buffer to store sample to (44Khz) */

extern Uint8	SoundRegs[ 14 ];			/* store YM regs 0 to 13 */
extern int	nGeneratedSamples;
extern bool	bEnvelopeFreqFlag;
extern Sint16	MixBuffer[MIXBUFFER_SIZE][2];

#ifdef OLD_SOUND
/* Original Hatari sound renderer active */

extern void Sound_Init(void);
extern void Sound_Reset(void);
extern void Sound_ResetBufferIndex(void);
extern void Sound_MemorySnapShot_Capture(bool bSave);
extern void Sound_Update(void);
extern void Sound_Update_VBL(void);
extern void Sound_WriteReg( int Reg , Uint8 Val );
extern bool Sound_BeginRecording(char *pszCaptureFileName);
extern void Sound_EndRecording(void);
extern bool Sound_AreWeRecording(void);

#else	/* OLD_SOUND */
/* STSound sound renderer active */
#include <SDL_types.h>


/* StSound's internal data types */
#define YM_INTEGER_ONLY

#ifdef YM_INTEGER_ONLY
typedef         Sint64			yms64;
#else
typedef         float			ymfloat;
#endif

typedef		Sint8			yms8;
typedef		Sint16			yms16;
typedef		Sint32			yms32;

typedef		Uint8			ymu8;
typedef		Uint16			ymu16;
typedef		Uint32			ymu32;

typedef		yms16			ymsample;	/* StSound emulator renders mono 16bits signed PCM samples */


extern bool	UseLowPassFilter;

extern void Sound_Init(void);
extern void Sound_Reset(void);
extern void Sound_ResetBufferIndex(void);
extern void Sound_MemorySnapShot_Capture(bool bSave);
extern void Sound_Update(void);
extern void Sound_Update_VBL(void);
extern void Sound_WriteReg( int reg , Uint8 data );
extern bool Sound_BeginRecording(char *pszCaptureFileName);
extern void Sound_EndRecording(void);
extern bool Sound_AreWeRecording(void);

#endif	/* OLD_SOUND */



#endif  /* HATARI_SOUND_H */
