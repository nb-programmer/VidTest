#pragma once

#include <stdint.h>

/* Input video */
const char* fileName = "C:\\Users\\naray\\Downloads\\Bad Apple PV.mp4";
//const char* fileName = "\\\\GAMING\\Anime\\Akkun to Kanojo\\Akkun to Kanojo 1.mp4";

//Video Metadata
#define OUTWIDTH		640
#define OUTHEIGHT		480
#define OUTCODEC		AV_CODEC_ID_MPEG4
#define OUTPXFMT		AV_PIX_FMT_YUV420P

#define FTDI_BAUD		2000000

//UDP TX Port/IP
const char *UDP_IP = "192.168.1.22";
const uint16_t UDP_PORT = 2000;

//Comment to transcode at unlimited speed
//#define THROTTLE

//Switch high or low bitrate
//#define HBRate


#define MODE_TCP		0
#define MODE_UDP		1
#define MODE_FTDI		2

//Transmission Media
#define TXMODE			MODE_FTDI