#ifndef COMMON_HH
#define COMMON_HH

// Uncomment following line to allow finegrained optical flow in RGB jpegs
// Default is greyscale optical flow image
// R channel: Range [-128,127] @ steps of 1
// G channel: Remainder in [-1,1] @ steps of 1.0/128.0
// B channel: Always zero, required for JPEG
// #define TEST_FINEGRAINED true

// JPEG Quality
#define JPEG_QUALITY 85

// Begin a new chunk after this many images
#define MAX_FILES_PER_CHUNK 20000
#endif