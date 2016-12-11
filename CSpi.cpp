#include "CSpi.h"
using namespace std;


CSpi::CSpi(char CS,unsigned int speed)
{
	mSpeed = speed;
	mCS= CS;
	init();
}
	
CSpi::~CSpi()
{}

int CSpi::init()
{
	char file[20];
	if(sprintf(file, "/dev/spidev0.%c", mCS)<0)
	{
		perror("CS");
		return -1;
	}
	
	if((mFdSpi = open(file, O_RDWR)) <0)
	{
		perror("open");
		return -1;
	}
	
	if (ioctl(mFdSpi, SPI_IOC_WR_MAX_SPEED_HZ, & mSpeed) != 0) 
	{
         perror("ioctl");
         return -1;
    }
	return 1;
}

int CSpi::lire(char *buffer, int length)
{
	return read(mFdSpi, buffer, length);	
}
	
int CSpi::ecrire(char *buffer, int length)
{
	
	 return write(mFdSpi, buffer, length); 

}	