#include "mintchip.h"

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void hex_print(const unsigned char *data, size_t len) {
	size_t i = 0;
	for (i = 0; i < len; i++) {
		printf("%02X ", *data++);
		if (i % 16 == 15)
			printf("\n");
	}
	printf("\n");
}

void get_info( struct mintchip * chip ) {

	struct mintchip_info info;

	mintchip_begin(chip);

	mintchip_get_info(chip, &info);

	printf( "  MintChip\n");
	printf( "   version : %s\n", mintchip_version_string(&info) );
	printf( "        id : %s\n", mintchip_id_string(&info) );
	printf( "   balance : %0.2f %s\n", (info.balance / 100.0), mintchip_currency_string(&info) );
	printf( "credit log : %d / %d\n", info.creditLogCount, info.creditLogCountRemaining );
	printf( " debit log : %d / %d\n", info.debitLogCount,  info.debitLogCountRemaining );
	printf( "max credit : %0.2f %s\n", (info.maxCreditAllowed / 100.0), mintchip_currency_string(&info) );
	printf( " max debit : %0.2f %s\n", (info.maxDebitAllowed  / 100.0), mintchip_currency_string(&info) );


	mintchip_end(&chip);

}

int main(int argc, const char *argv[]) {
	int ret;

	struct mintchip * chip;
	ret = mintchip_open_path(&chip, "/tmp/fakechip");
	if (ret) {
		printf("Failed to open mintchip\n");
		return -1;
	}

	get_info();


/*
//	fd = open("/media/disk/SMART_IO.CRD", O_RDWR, S_IWOTH | S_IXOTH);
	fd = open("/media/disk/SMART_IO.CRD", O_SYNC | O_DIRECT | O_RDWR);
	if (fd == -1) {
		printf("open failed\n");
		return -1;
	}

	memset(data, 0, 512);
	memcpy(&data[0], header_request, 16);
	memcpy(&data[16], r, 16);

	hex_print(data, 64);

	send_request(fd, data);
	wait_for_response(fd, data);

	hex_print(data, 64);

	close(fd);
*/

	return 0;
}

