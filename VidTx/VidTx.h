#pragma once

#include <iostream>
#include <algorithm>

#define NOMINMAX
#define SDL_MAIN_HANDLED

#include <SDL/SDL.h>
#include <SDL/SDL_net.h>

#include "UDPStream.h"
#include "FTDIStream.h"
#include "TCPStreamServer.h"
#include "Timer.h"

//LibAV headers (using C)
extern "C" {
#include <ffmpeg/libavcodec/avcodec.h>
#include <ffmpeg/libavformat/avformat.h>
#include <ffmpeg/libswscale/swscale.h>
#include <ffmpeg/libavutil/imgutils.h>
}


//Input codec and format
AVRational avr;
AVCodec *pInputCodec;
AVCodecContext *pInputCodecContext;
AVFormatContext *pInputFormatCtx;
struct SwsContext *sws_ctx;

//Output codec and format
AVCodec *outCodec;
AVCodecContext *pOutputCodecContext;

//Index of video stream in input file
unsigned int videoStream;

//Input and output frames
AVFrame *pFrame, *pOutFrame;

//Input and output video packets
AVPacket *inPkt, *outPkt;

uint8_t *pOutFrameBuffer;

//Output Streams
Stream *outStream;

struct avpkt {
	uint8_t sig[3] = { 0x01, 0x88, 0x28 };
	uint8_t part;
	uint8_t totalparts;
	uint64_t totalsize;
	uint8_t data[32700];
	uint64_t size;
} pack;