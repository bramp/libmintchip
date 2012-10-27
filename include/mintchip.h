#include <stdint.h>

struct mintchip {
	int fd;
	uint8_t seq;
	uint16_t session_id;
};

struct mintchip_info {
	char id[8];                  // 0-8
	char currency;               // 8
	int balance;                 // 9-12
	int creditLogCount;          // 12-14
	int debitLogCount;           // 14-16
	int creditLogCountRemaining; // 16-18
	int debitLogCountRemaining;  // 12-20
	int maxCreditAllowed;        // 20-23
	int maxDebitAllowed;         // 23-26
	char version;                // 26
};

//
//
int mintchip_open(struct mintchip *chip);
int mintchip_open_path(struct mintchip *chip, const char *path);

//
// Mintchip_info
const char * mintchip_id_string(const struct mintchip_info *info);
const char * mintchip_version_string(const struct mintchip_info *info);
const char * mintchip_currency_string(const struct mintchip_info *info);

//
// Commands
int mintchip_begin   (struct mintchip *chip);
int mintchip_end     (struct mintchip *chip);

int mintchip_get_info(struct mintchip *chip, struct mintchip_info *info);

const char * mintchip_get_err(struct mintchip *chip);
int mintchip_get_errno(struct mintchip *chip);
