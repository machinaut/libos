#define B_SIZE 4096
struct buf {
  int flags;
  uint dev;
  uint sector;
  struct buf *prev; // LRU cache list
  struct buf *next;
  struct buf *qnext; // disk queue
  uchar data[B_SIZE];
};
#define B_BUSY  0x1  // buffer is locked by some process
#define B_VALID 0x2  // buffer has been read from disk
#define B_DIRTY 0x4  // buffer needs to be written to disk
// Adding this counter, bits 5:3 of the flags field
// Count up from 0->7, as the buffer is filled or emptied to disk
// and allows the buffer to increase in size from 512 to 4096 (or larger)
#define B_DONE(i)			(((i) & 0x38) >> 3) // how many sectors are done
#define B_DONE_MAX		(B_SIZE / 512) // number of sectors total in a buffer
#define B_DONE_INC(i)	(((i)&~0x38)|(((i)&0x38)+0x8)) // increment
