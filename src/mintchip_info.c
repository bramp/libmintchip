#include "mintchip.h"

/**
 * Turns a 8 byte char into a string
 */
static char _mintchip_id[17];
const char * mintchip_id_string(const struct mintchip_info *chip) {
	const char * id = chip->id;
	char * dest = _mintchip_id;

	for (int i = 0; i < 8; i++) {
		*dest = '0' + ((*id & 0xF0) >> 4);
		dest++;

		*dest = '0' + ((*id & 0x0F));
		dest++;

		id++;
	}
	*dest = '\0';
	return _mintchip_id;
}

static char _mintchip_version[4];
const char * mintchip_version_string(const struct mintchip_info *chip) {
	char version = chip->version;
	char * dest = _mintchip_version;
	dest[0] = ((version & 0xF0) >> 4) + '0';
	dest[1] = '.';
	dest[2] = ((version & 0xF0) >> 4) + '0';
	dest[3] = '\0';
	return dest;
}

const char * mintchip_currency_string(const struct mintchip_info *chip) {
	const char currency = chip->currency;
	switch (currency) {
		case 0: return "CHF";
		case 1: return "CAD";
		case 2: return "USD";
		case 3: return "EUR";
		case 4: return "GBP";
		case 5: return "JPY";
		case 6: return "AUD";
		case 7: return "INR";
		case 8: return "RUB";
	}

	return "UNKNOWN";
}
