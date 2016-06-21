#ifndef __INC_CHANNEL_TYPE_H
#define __INC_CHANNEL_TYPE_H


#define	HAL_PRIME_CHNL_OFFSET_DONT_CARE	0
#define	HAL_PRIME_CHNL_OFFSET_BELOW		1
#define	HAL_PRIME_CHNL_OFFSET_ABOVE		2


typedef enum _DATA_SC{
	DATA_SC_DONOT_CARE = 0,
	DATA_SC_20_ABOVE_OF_80MHZ = 1,
	DATA_SC_20_BELOW_OF_80MHZ = 2,
	DATA_SC_20_TOP_OF_80MHZ = 3,
	DATA_SC_20_BOTTOM_OF_80MHZ = 4,
	DATA_SC_20_RECV1 = 5,
	DATA_SC_20_RECV2 = 6,
	DATA_SC_20_RECV3 = 7,
	DATA_SC_20_RECV4 = 8,
	DATA_SC_40_ABOVE_OF_80MHZ = 9,
	DATA_SC_40_BELOW_OF_80MHZ = 10,
}DATA_SC, *PDATA_SC_E;

// Represent Channel Width
typedef enum _CHANNEL_WIDTH{
	CHANNEL_WIDTH_20 = 0,
	CHANNEL_WIDTH_40 = 1,
	CHANNEL_WIDTH_80 = 2,
	CHANNEL_WIDTH_160 = 3,
	CHANNEL_WIDTH_80_80 = 4,
	CHANNEL_WIDTH_MAX = 5,
}CHANNEL_WIDTH, *PCHANNEL_WIDTH;

// Represent Extention Channel Offset
typedef enum _EXTCHNL_OFFSET{
	EXTCHNL_OFFSET_NO_EXT = 0,
	EXTCHNL_OFFSET_UPPER = 1,
	EXTCHNL_OFFSET_NO_DEF = 2,
	EXTCHNL_OFFSET_LOWER = 3,
}EXTCHNL_OFFSET, *PEXTCHNL_OFFSET;


// Represent Extention Channel Offset
typedef enum _EXTCHNL_OFFSET_JAR{
	//EXTCHNL_OFFSET_NO_EXT = 0,
	EXTCHNL_OFFSET_ABOVE = 1,
	//EXTCHNL_OFFSET_NO_DEF = 2,
	EXTCHNL_OFFSET_BELOW = 3,
}EXTCHNL_OFFSET_JAR, *PEXTCHNL_OFFSET_JAR;

typedef enum _CHNLOP{
	CHNLOP_NONE = 0, // No Action now
	CHNLOP_SCAN = 1, // Scan in progress
	CHNLOP_SWBW = 2, // Bandwidth switching in progress
	CHNLOP_SWCHNL = 3, // Software Channel switching in progress
} CHNLOP, *PCHNLOP;

typedef struct _RT_CHANNEL_INFO {
	DECLARE_RT_OBJECT(_RT_CHANNEL_INFO);

	CHANNEL_WIDTH	RegBWSetting;
	BOOLEAN			bSwBwInProgress;
	CHNLOP			ChnlOp; 

	u1Byte			PrimaryChannelNumber;
	CHANNEL_WIDTH	CurrentChannelBandWidth;
	u1Byte			CurrentChannelCenterFrequency;

	EXTCHNL_OFFSET	Ext20MHzChnlOffsetOf40MHz;
	EXTCHNL_OFFSET	Ext40MHzChnlOffsetOf80MHz;

	RT_TIMER		SwBwTimer;
} RT_CHANNEL_INFO, *PRT_CHANNEL_INFO;

typedef struct _CHANNEL_COMMON_CONTEXT {
	u1Byte			PrimaryChannelNumber;
	CHANNEL_WIDTH	CurrentChannelBandWidth;
	u1Byte			CurrentChannelCenterFrequency;

	EXTCHNL_OFFSET	Ext20MHzChnlOffsetOf40MHz;
	EXTCHNL_OFFSET	Ext40MHzChnlOffsetOf80MHz;
} CHANNEL_COMMON_CONTEXT, *PCHANNEL_COMMON_CONTEXT;


#endif