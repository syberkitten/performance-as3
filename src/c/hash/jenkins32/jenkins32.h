#define JENKINS32( key ) \
	key = (key ^ 61) ^ (key >> 16); \
	key = key + (key << 3); \
	key = key ^ (key >> 4); \
	key = key * 0x27d4eb2d; \
	key = key ^ (key >> 15);
