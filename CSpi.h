#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>

class CSpi
{
	private :
	
	int mFdSpi;
	unsigned int mSpeed;
	char mCS; 
	
	public :
	
	CSpi(char CS, unsigned int speed);
	~CSpi();	
	int init();
	int lire(char *buffer,int length);
	int ecrire(char *buffer, int length);

};